//====================================================================
// Copyright Dassault Systemes Provence 2018-2020, All Rights Reserved 
//====================================================================
// QUELQUES MACROS pour supprimer les copy-constructor, les operateur = et les move
// HISTORIQUE :
// 31/01/2020 : RNO : Duplication depuis CATMaterialRemovalSimulation
// 21/09/2018 : RNO : Creation (inspiree de Abseil.io)
//==================================================================== 


#define  DISALLOW_COPYCTOR_ASSIGN_AND_MOVE(MyType)\
MyType & operator = (const MyType &) = delete;\
MyType & operator = (MyType &&) = delete;\
MyType(const MyType &) = delete;\
MyType(MyType &&) = delete;




//NOTE THREAD SAFE MEANS ALOOW SIMULTANEOUS ADDREF BUT NOT SIMULTANEOUS ADDREF AND RELEASE
#include <cstdint>
#include <atomic>


//GetRefCount : Return the Ref Counter of the object
// WARNING IT's NOT THREAD SAFE TO USE THIS METHOD 
// if 2 thread use the same object and one do AddRef or Release GetRefCount can return an unexpected value
// BUT it's OK to use it on two different object at the time
//inline int GetRefCount() const {return _RefCount;}

//Herb Sutter Tricks (fetch_add & fetch_sub std::memory_order::memory_order_relaxed)
//Andrei Alexandrescu Tricks ( 0 as Init and last decrementation skipped)
#define DECLAREPolyComparBaseDEVIRTUALISED(TYPE)\
public:\
  INLINE void AddRef()\
  {\
     _RefCount.fetch_add(1,std::memory_order_relaxed);/*++_RefCount;*/\
  }\
  INLINE void Release()\
  {\
	/*if(_RefCount.load(std::memory_order::memory_order_relaxed)==1) {	delete this; return;}*/\
	int prevValue=_RefCount.fetch_sub(1,std::memory_order_relaxed);\
	if (prevValue==0)\
		delete this;\
  }\
  INLINE static void Replace(TYPE *& to, TYPE * from)\
  {\
    if(to!=from)\
    {\
      if(from) from->AddRef();\
      if(to) to->Release();\
      to=from;\
    }\
  }\
  inline int GetRefCount() const {return _RefCount;}\
                                                                                        \
  inline static void ReleaseObject(TYPE* ipObject) { if(ipObject) ipObject->Release(); }      \
                                                                                        \
private:\
  volatile std::atomic<std::int32_t> _RefCount;


//Andrei Alexandrescu Tricks (use 0)
#define INITPolyComparBaseDEVIRTUALISED _RefCount(0) 
