/* -*-C++-*- */
#ifndef DSYGMSharedPtr_H
#define DSYGMSharedPtr_H

#include <memory>
#include "DSYSysAtomic.h"
// #include "CATMathInline.h"

#if __cplusplus >= 201103L // if C++11
// #if _QF2CodeActif

template<class _Ty>
using DSYGMSharedPtr = std::shared_ptr<_Ty>;

#else  // Mostly AIX with legacy compiler

// ---------------------------------------------------------------------------
// DS - Equivalent of std::shared_ptr
// ---------------------------------------------------------------------------
template<class _Ty>
class DSYGMSharedPtr 
{
  template<class U>
  friend class DSYGMSharedPtr;

public:
  // default
  // DSYGMSharedPtr (unsigned int = 0);  

  // regular
  DSYGMSharedPtr(_Ty * iPtr = 0 );

  // with deleter
  DSYGMSharedPtr (_Ty * iPtr, void (*iDeleter)(_Ty *) ) ;

  // copy constructors
  DSYGMSharedPtr( const DSYGMSharedPtr & iOther );

  template <class _U>
  DSYGMSharedPtr( const DSYGMSharedPtr<_U> & iOther );

  // destructor 
  ~DSYGMSharedPtr();

  /* Swap & reset */
  void  reset() ;
  // Exchanges the stored pointer values and the ownerships of *this and iOther. 
  // Reference counts, if any, are not adjusted. 
  void  swap( DSYGMSharedPtr & iOther );

  _Ty     * get() const;
  CATLONG32 use_count() const;
  
  
  /* Accessors  */
  operator bool () const;
 
  _Ty & operator *() const; 
  _Ty * operator->() const;

  // Operator =
  template <class _U>
  DSYGMSharedPtr & operator = (const DSYGMSharedPtr<_U> &iOther); 
	


protected :

  void _destroyer();


  static void default_deleter ( _Ty * p) {
    if (p)
      delete p;
  }  

  class CATGMSmartCounter {
    public:
      CATGMSmartCounter(CATLONG32 i) : _count(i) {}
      ~CATGMSmartCounter () {    
        _count = 0; 
      }

      CATLONG32 _count;
  };


private :

  // internal Data
// ------------------------- 
  // pointer 
  _Ty               * _ptr;
  // counter
  CATGMSmartCounter * _ref;
  // deleter
  void (*_fdel)(_Ty *);

};

// -------------------------------------------------------------------------------------
// Operator == 
// -------------------------------------------------------------------------------------
template <class _Ty1, class _Ty2>
bool operator==(const DSYGMSharedPtr<_Ty1> & iLeft, const DSYGMSharedPtr<_Ty2> & iRight)  
{
  return iLeft.get() == iRight.get();
}

// -------------------------------------------------------------------------------------
// Operator != 
// -------------------------------------------------------------------------------------
template <class _Ty1, class _Ty2>
bool operator!=(const DSYGMSharedPtr<_Ty1> & iLeft, const DSYGMSharedPtr<_Ty2> & iRight)  
{
  return iLeft.get() != iRight.get();
}


// =========================================================================================

// default constructor 
//template<class _Ty>
//DSYGMSharedPtr<_Ty>::DSYGMSharedPtr(unsigned int) :
//_ref(0),
//_ptr(0),
//_fdel(0)
//{
//} 
  
// regular
template<class _Ty>
DSYGMSharedPtr<_Ty>::DSYGMSharedPtr(_Ty * iPtr ) :
_ref( iPtr ? new CATGMSmartCounter(1) : 0),
_ptr(iPtr),
_fdel(iPtr ? &default_deleter : 0)
{
}  

// with deleter
template<class _Ty>
DSYGMSharedPtr<_Ty>::DSYGMSharedPtr (_Ty * iPtr, void (*iDeleter)(_Ty *) ) :
_ref(new CATGMSmartCounter(1)),
_ptr(iPtr),
_fdel(iDeleter)
{
}

// copy constructor
template<class _Ty>
DSYGMSharedPtr<_Ty>::DSYGMSharedPtr( const DSYGMSharedPtr & iOther ) :
_ptr(iOther.get()),
_ref (iOther._ref),
_fdel(iOther._fdel)
{
  if (_ref)
    DSYSysInterlockedIncrement(& _ref->_count);
}

// copy constructor
template<class _Ty>
template<class _U> 
DSYGMSharedPtr<_Ty>::DSYGMSharedPtr( const DSYGMSharedPtr<_U> & iOther ) :
_ptr(iOther.get()),
_ref (reinterpret_cast<DSYGMSharedPtr<_Ty>::CATGMSmartCounter *>(iOther._ref)),
_fdel(reinterpret_cast<void(*)(_Ty *)> (iOther._fdel))
{
  if (_ref)
    DSYSysInterlockedIncrement(& _ref->_count);
}

// destructor 
template<class _Ty>
DSYGMSharedPtr<_Ty>::~DSYGMSharedPtr() 
{
  this->reset();
}

template<class _Ty>
_Ty * DSYGMSharedPtr<_Ty>::get() const {
  return _ptr;
}

template<class _Ty>
CATLONG32 DSYGMSharedPtr<_Ty>::use_count() const
{
  if (_ref)
    return _ref->_count;
  return 0;
}

template<class _Ty>
void DSYGMSharedPtr<_Ty>::reset() 
{
  if (_ref)
  {
    DSYSysInterlockedDecrement(& _ref->_count);
    if (_ref->_count == 0)
    {
      this->_destroyer();

      delete _ref;        
    }
  }
  _ptr  = NULL;
  _ref  = NULL;
  _fdel = NULL;
}

template<class _Ty>
void DSYGMSharedPtr<_Ty>::swap( DSYGMSharedPtr & iOther )
{
  if (&iOther != this)
  {
    // 1. exchange ptr
    _Ty * tmpPtr = _ptr;
    _ptr = iOther._ptr;
    iOther._ptr = tmpPtr;

    // 2. exchange counter
    CATGMSmartCounter * tmpRef = _ref;
    _ref = iOther._ref;
    iOther._ref = tmpRef;

    // 3. exchange deleter
    void (*tmpDel)(_Ty *) = _fdel;
    _fdel = iOther._fdel;
    iOther._fdel = tmpDel;
  }
}

template<class _Ty>
DSYGMSharedPtr<_Ty>::operator bool () const {
  if (_ptr)
    return true;

  return false;
}

template<class _Ty>
_Ty & DSYGMSharedPtr<_Ty>::operator*() const  {
  return *_ptr;
}
  
template<class _Ty>
_Ty * DSYGMSharedPtr<_Ty>::operator->() const {
  return _ptr;
}

template<class _Ty>
template<class _U>
DSYGMSharedPtr<_Ty> & DSYGMSharedPtr<_Ty>::operator = (const DSYGMSharedPtr<_U> & iOther)  
{
  if (_ptr != iOther._ptr) 
  {
    this->reset();

    _ptr  = iOther._ptr;
    _ref  = reinterpret_cast<DSYGMSharedPtr<_Ty>::CATGMSmartCounter *> (iOther._ref);   
    _fdel = reinterpret_cast<void (*)(_Ty *) > (iOther._fdel);

    if (_ref)
      DSYSysInterlockedIncrement(& _ref->_count);
  }

  return *this;
}


// Private Methods
template<class _Ty>
void DSYGMSharedPtr<_Ty>::_destroyer() {
  
  if (_fdel)
    _fdel (_ptr);

  //else if (_ptr)
  //  delete _ptr;

  _ptr = NULL;
}

#endif

#endif
