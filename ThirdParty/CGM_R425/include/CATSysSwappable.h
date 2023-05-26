#ifndef CATSysSwappable_H
#define CATSysSwappable_H
// COPYRIGHT DASSAULT SYSTEMES 2002
//=======================================================================================
// THIS CLASS SHOULD NOT BE USED AS OF TODAY
// Usage forbidden 
// PLEASE ASK SGT BEFORE TRYING TO USE IT
//=======================================================================================

#include <stdlib.h>
#include <stdio.h>
#include "IUnknown.h"
#include "CATSysAllocator.h"
#define CATSysSwapHeaderSize 8

#define CATSysSwpManualSwpForbidden     0x00000001
#define CATSysSwpAutomaticSwpForbidden  0x00000002

#define CATSysSwpHdlStsSwappedOut 0x00000001
#define CATSysSwpHdlStsDead       0x00000002 

#define CATSysSwpFilStsInitialized 0x00000001
//#define _DEBUG_SWAPPABLES

typedef size_t CATSysSwpAddress_t;

enum CATSysSwapConditions { CATSysSwpCondAutomatic=0, CATSysSwpCondManual=1, CATSysSwpCondImperious=2 };
 
struct CATSysSwapPage;
#if defined(_AIX_SOURCE) && (__xlC__ >= 0x0500)
class CATSysSwappable;
#endif
class CATSysSwappableHdl ;
class CATSysSwappable ;
class ExportedByCATSysAllocator CATSysSwapFile 
{
  friend class CATSysSwappable;
  public:
  CATSysSwapFile();
  ~CATSysSwapFile();
  HRESULT Initialize(int iRules,size_t iSizeInMemory, size_t iMinSize, size_t iFileSize);
  inline size_t ZoneSize(size_t iSize);
  // global services
  HRESULT TuneSwapOut(unsigned int iMinNumberOfSwappedOutPage);

  HRESULT SwapOutOldestObjects( size_t iNeededSize);
  HRESULT SwapOut(); // global swapout
  HRESULT SwapIn(); // global swapin
  HRESULT FreeAll();

  // instance high level services
  HRESULT AllocateObject(size_t iObjectSize, CATSysSwappable **oObject);
  HRESULT DeallocateObject(CATSysSwappable *iObject);
  HRESULT SwapOutObject( CATSysSwappableHdl *);
  HRESULT RecallObject( CATSysSwappableHdl *);

  // tools services
  private:
  HRESULT EffectiveSwapOut( CATSysSwappable *,CATSysSwappableHdl *oH,unsigned int *oGain=NULL);
  void * FindAvailableZoneInPool(size_t);
  void *PageInPreSwapSpace(int iIndex);
  HRESULT FreeIndex(int iIndex);
  HRESULT SwapInPage(int iIndex,size_t lDecal,CATSysSwappable **oWantedObject,char *iEndDest, int iTailSize);

  HRESULT DirectCopyToFile(int iStartPage, int iHoleLen,void *iAddr , size_t iSize);
  inline void *RealAddress( CATSysSwappable *iObj);

  // debug services - unimplement in official release
  size_t DumpObjectsToSwap(FILE *oFic ,const char *iTag, int iTraceAndCount);


  // DATA
  private:
  void *m_MemoryWindow; // fenetre memoire (pool)
  unsigned char *m_PageIndex;    // index des pages
  FILE *m_File;         // Fichier de swap
  int   m_Status;       // status 
  size_t m_MemorySize;  // taille de la fenetre memoire
  size_t m_MemoryOccupied; // occupation
  size_t m_FileSize;    // taille max du fichier de swap
  size_t m_CurrentSize;// taille courante
  int    m_SizeOfPageIndex;  // nb de page de swap (de taille SWAP_PAGE_SIZE)
  int  m_FirstFreePage; // premiere page vide
  int m_FirstFreeSpace; // debut de l'espace  vierge
  CATSysSwapPage *m_CurrentSwapPage;
  CATSysSwappable *m_FirstToSwap;
  CATSysSwappable *m_LastToSwap;
  unsigned int m_MinSwapOuts;

};

inline size_t CATSysSwapFile::ZoneSize(size_t iSize)
{
  return ((iSize+7) / 8 *8) +  CATSysSwapHeaderSize ;
}

inline void * CATSysSwapFile::RealAddress( CATSysSwappable *iObj)
{
  const char *ptr=(char *)iObj;
  if (iObj) ptr-= 2 *sizeof(void*);
  return (void *)ptr ;
}

class ExportedByCATSysAllocator CATSysSwappableHdl 
{
   friend class CATSysSwappable;
   friend class CATSysSwappable_hdl ;
   friend class CATSysSwapFile ;
   private :
   CATSysSwappable *m_Object ;
   CATSysSwapFile *m_SwapPool;// a reflechir
   unsigned int m_Ref;
   void *m_Debug;

   CATSysSwappable *RecallObject( );

   protected:
   CATSysSwappableHdl( CATSysSwappable *iSwap=NULL , CATSysSwapFile *iPool=NULL);
   virtual HRESULT RemoveObject();
   
   public:
   virtual CATSysSwappableHdl* operator =(CATSysSwappable *iSwpObj);
//   virtual int IsSwappable() { return 0; };
   inline int IsHandle() { return -1; };
#ifdef _DEBUG_SWAPPABLES
   virtual int IsSwapped() ;
#else
   virtual int IsSwapped() { 
	   return ((CATSysSwpAddress_t)m_Object & CATSysSwpHdlStsSwappedOut);
   };
#endif
   virtual int IsNull() { return m_Object==NULL; };
   virtual int IsDead() { return 0; };
   
#ifdef _DEBUG_SWAPPABLES
   virtual HRESULT CallDeathOnObject();
#else
   virtual HRESULT CallDeathOnObject()
   { 
	    if ( IsSwapped() ) GetObject();
		if (IsSwapped() || IsNull() || IsDead()) 
			 return E_FAIL; 
		 /*m_Object->LogicalDeath();*/;  return S_OK;
   };
#endif
   virtual ULONG GetRefCount() { return m_Ref; };
/*
#ifndef CNEXT_CLIENT
*/
   virtual ULONG __stdcall AddRefToObj(void *iKey) {return ++m_Ref; };
#ifdef _DEBUG_SWAPPABLES
   virtual ULONG __stdcall ReleaseObj( void *iKey) ;
#else
   virtual ULONG __stdcall ReleaseObj( void *iKey) { int lRef=m_Ref; if (m_Ref > 0 ) { m_Ref--; lRef=m_Ref; if (m_Ref==0) { CallDeathOnObject(); RemoveObject(); } } return lRef; };
#endif
/*
#else
  virtual ULONG __stdcall AddRefToObj(void *iKey) {return ++m_Ref; };
  virtual ULONG __stdcall ReleaseObj( void *iKey) { if (m_Ref > 0 ) { m_Ref--; if (m_Ref==0){CallDeathOnObject(); RemoveObject(); } } return m_Ref;};
#endif
*/

   protected:
   CATSysSwappable *GetObject(){ if ( (CATSysSwpAddress_t)m_Object & CATSysSwpHdlStsSwappedOut) m_SwapPool->RecallObject(this);  return m_Object ; };
   CATSysSwappableHdl *SetObject(CATSysSwappable *iSwpObj){  *this=iSwpObj;return this; };
};
class  ExportedByCATSysAllocator CATSysSwappable_hdl
{
  public:
  CATSysSwappable_hdl(){};
  CATSysSwappable_hdl(CATSysSwappable *iOb);
  CATSysSwappable_hdl(CATSysSwappableHdl *iOb){ m_PermanentHandle=iOb;};
  ~CATSysSwappable_hdl(){if ( m_PermanentHandle ) m_PermanentHandle->ReleaseObj(this);m_PermanentHandle=NULL;};
   virtual int IsNull() { return m_PermanentHandle==NULL; };
  protected:
  
  CATSysSwappableHdl *SetObject(CATSysSwappable *iObj) ;
  CATSysSwappableHdl *SetObjectRef(CATSysSwappableHdl *iHdl) { 
   if( iHdl&& iHdl != m_PermanentHandle )  iHdl->AddRefToObj(this);
   if  (m_PermanentHandle && m_PermanentHandle != iHdl ) m_PermanentHandle->ReleaseObj(this); 
   m_PermanentHandle= iHdl;  return m_PermanentHandle ;
  };
  void SetObject(CATSysSwappable_hdl &iObj){SetObjectRef(iObj.m_PermanentHandle); } ;
  CATSysSwappable *GetObject() { if  (m_PermanentHandle )  return m_PermanentHandle->GetObject(); else  return NULL ;};
  CATSysSwappableHdl *m_PermanentHandle;
};
#define CATSysSwpPreDeclareHandler(a) class a##_hdl;
#define CATSysSwpDeclareHandler(a)                                \
class a ;                                                            \
class a##_hdl :public CATSysSwappable_hdl                             \
{                                                                    \
  friend class a;\
  public:        \
  a##_hdl( CATSysSwappable *i1=NULL, CATSysSwapFile *i2=NULL)  : CATSysSwappable_hdl(i1){}; \
  a##_hdl * operator =(a *iSwpObj) { SetObject( (CATSysSwappable*)iSwpObj); return this; }; \
  a##_hdl * operator =(a##_hdl &iSwp_h) { SetObject( iSwp_h); return this; }; \
  a *operator ->(){ CATSysSwappable *p=  GetObject()  ;if(p)p->IsUsed(); return (a*)p;}; \
};

#define CATSysSwappableObject(a)  \
  public:                          \
  static a##_hdl *Create ( CATSysSwapFile *iFile,a##_hdl *iHandle=NULL,int iRules=0 );  \
  private :                    \
  a(CATSysSwapFile *iF,int iRules=0);             \
  a##_hdl *GetNewHandle();                        \


#define CATSysSwpImplementClass(a) \
  a##_hdl *a::Create( CATSysSwapFile *iFile,a##_hdl *iHandle,int iRules ) {if (iFile ){  a *pt= new ( iFile ) a(iFile,iRules);if ( iHandle){ *iHandle = pt; return iHandle;} else {if (pt) return  pt->GetNewHandle(); }  } return NULL;}; \
  a##_hdl *a::GetNewHandle() { return new a##_hdl(this,GetSwapFile());};\

//--------------------------------------------------------------------
//
class  ExportedByCATSysAllocator CATSysSwappable : public CATSysSwappable_hdl
{
   friend class CATSysSwapFile ;
   friend class CATSysSwappableHdl ;
  protected:
  CATSysSwappable(CATSysSwapFile *iFile, int iRules=0);
  protected:
  virtual ~CATSysSwappable( );
  public :
  //---------------------------------------
  // un-overloadable services
  CATSysSwappableHdl  *GetHandle(int iSwappableHandle=0);
  CATSysSwappableHdl  *ReplaceHandle(CATSysSwappableHdl *);
  void operator delete(void *iAddr);
#if defined( _SUNOS_SOURCE ) || defined ( _WINDOWS_SOURCE)
  void operator delete(void *iAddr,void *iAllocType, 
                      void *iRefAddr,int iReservedSize) ;
#endif
  void *operator new(size_t iSize,void *iAllocType=NULL,
                      void *iAddr=NULL,int iReservedSize=0) ;
  HRESULT SwapOut(CATSysSwapConditions iCondition = CATSysSwpCondManual);
  HRESULT SwapIn();
  HRESULT AddHandle( CATSysSwappableHdl *);
  HRESULT RemoveHandle( CATSysSwappableHdl *);
  HRESULT UpdateHandles(CATSysSwpAddress_t);
  HRESULT IsUsed( );
  CATSysSwappableHdl *GetPermanentHandle() { if ( m_PermanentHandle==NULL ){m_PermanentHandle=new CATSysSwappableHdl(this) ; } return m_PermanentHandle;};
  CATSysSwapFile * GetSwapFile(){ return m_SwapPool;}; 
  //---------------------------------------
  // overloadable services
  CATSysSwappable *operator ->() {return this;};
  // appele avant un swappout (peut refuser le swap-out)
  virtual int IsSwapAuthorized(CATSysSwapConditions iCondition = CATSysSwpCondManual) { return -1; };
  // appele lors d'un swap-out
  virtual HRESULT SwappedOut( ){ return S_OK; };
  // appele lors d'un swap-in
  virtual HRESULT SwappedIn() { return S_OK; };
//  virtual int IsSwappable() { return -1; };
//  inline int IsHandle() { return 0; };
  virtual ULONG GetRefCount() { if (m_PermanentHandle) return m_PermanentHandle->GetRefCount(); else return 0; };
  private:
  size_t GetSize();
  // pour l'instant on bourrine
  CATSysSwappable *m_Object ;
  CATSysSwapFile  *m_SwapPool;
  CATSysSwappable *m_NextToSwap ;
  CATSysSwappable *m_PrevToSwap ;
};

/**
 * Swappable handle
class CATSysSwappable : public CATSysSwpSwappableHdl
{
  CATSysSwappable operator ->() { return CATSysSwappableHdl::operator->() ;};
  virtual int IsHandle() { return -1 };
  size_t GetSize() { return (CATSysSwappable*)m_Object->GetSize(); };
};
 */
#endif
