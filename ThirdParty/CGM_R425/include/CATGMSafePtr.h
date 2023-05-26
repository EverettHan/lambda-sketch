/* -*-C++-*- */
#ifndef CATGMSafePtr_H
#define CATGMSafePtr_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================

//=============================================================================
//
// RESPONSABLE  : Q. FREGER (QF2)
//
// DESCRIPTION  : Template class  for smart pointer on AddRef/Release() object.
//                Multi OS - AIX Compliant
//                            
//=============================================================================

#include "CATMathematics.h"
#include <cstddef>
#include <utility>
#include <memory>
#include "CATGMMakeSafePtr.h"


#if __cplusplus >= 201103L


/** 
 * template safe pointer class 
 * Usage: 
 *  {
 *    myClass * ptr = [...];
 *    CATGMSafePtr<myClass> safePtr = ptr; // call AddRef
 *    CATGMSafePtr<myClass> safePtr(ptr);  // call AddRef
 *    CATGMSafePtr<myClass> safeptr_2 = safePtr; // call AddRef
 *    safePtr = nullptr; // call Release  
 * 
 *  } // end of block, call Release.
 */

template <class T>
class CATGMSafePtr final 
{

public :

  CATGMSafePtr() = delete;

  void * operator new    (size_t) = delete;
  void * operator new[]  (size_t) = delete;


  /* Constuctors 1 */
  // constexpr CATGMSafePtr( std::nullptr_t ) noexcept;

  /* Constuctors 2 */
  CATGMSafePtr(T * ipPointer) noexcept; 
  /*Copy constructor */
  CATGMSafePtr(const CATGMSafePtr & iHandler) noexcept;
  /* Move constructor */
  CATGMSafePtr(CATGMSafePtr && iHandler) noexcept ;

  // Destructor 
  virtual ~CATGMSafePtr() ;


  /**  Operators = **/
  CATGMSafePtr & operator = (const CATGMSafePtr &iHandler) noexcept;
  CATGMSafePtr & operator = ( std::nullptr_t ) noexcept;
  /* forbidden operator */
  CATGMSafePtr & operator = (T * iPtr) = delete; // evite le code alambiqué 
  
 /** To set to null the manage object - call Release() 
  *  equivalent to: CATGMSafePtr<T> obj = nullptr;
  */
  void Reset() noexcept;

  /** Accessors **/
  explicit operator bool () const noexcept;

  T & operator*()  const noexcept;
  T * operator->() const noexcept;

  operator T * ()  const noexcept;


protected :
  // Owning private methods  
  void TakeOwnership(T * const iptr) noexcept;

  template<class U>  friend CATGMSafePtr<U> CATGM::MakeSafePtr();
  template<class U, class... Args> friend CATGMSafePtr<U> CATGM::MakeSafePtr(Args&&... args);


private :
  // Compilation pour linux
  void operator delete   (void* ptr) noexcept {};
  void operator delete [](void* ptr) noexcept {};

private:

  T * _ptrObj;

};




#include "CATGMSafePtr.hxx"


// for AIX 
#else


class /*ExportedByCATMathematics*/ CGMBaseCSealed
{
private:

  CGMBaseCSealed() {} ;
  virtual ~CGMBaseCSealed() {} ;

public:
  
  template<class T> friend class CATGMSafePtr;
};


template <class T>
class CATGMSafePtr : public CGMBaseCSealed
{
public :

  CATGMSafePtr(T * ipPointer) : _ptrObj(ipPointer)  { 
    if (_ptrObj) _ptrObj->AddRef(); 
  }
  
  CATGMSafePtr(const CATGMSafePtr & iHandler)  : _ptrObj(iHandler._ptrObj) {
    if (_ptrObj)
      _ptrObj->AddRef();
  }  

  CATGMSafePtr & operator = (const CATGMSafePtr &iHandler) {
    if (iHandler._ptrObj != _ptrObj) 
    {
      if (_ptrObj)
        _ptrObj -> Release();

      _ptrObj = iHandler._ptrObj;
      if (_ptrObj)
        _ptrObj -> AddRef();
    }
    return *this;
  }

  virtual ~CATGMSafePtr() {
    if (_ptrObj) 
      _ptrObj->Release();
    _ptrObj = 0;
  }


  void Reset() {
    if (_ptrObj)
      _ptrObj -> Release();
    _ptrObj = 0; 
  }

  operator bool () const  {
    if (_ptrObj)
      return true;
    return false;
  }

  T & operator*() const  {
    return *_ptrObj; }
  
  T * operator->() const  {
    return _ptrObj; }

  operator T * () const  {
    return _ptrObj; }


private :
  CATGMSafePtr();

  void * operator new    (size_t);
  void * operator new[]  (size_t);

  CATGMSafePtr & operator = (T * iPtr);

  // void operator delete   (void*) ;
  // void operator delete [](void*) ;

private:

  T * _ptrObj;
  
};

#endif // ifdef C++ 11


#endif // ifndef CATGMSafePtr_H

