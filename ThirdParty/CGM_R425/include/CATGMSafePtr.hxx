// C++ 
// QF2

#if __cplusplus >= 201103L
// CATGMSafePtr.hxx


//namespace CATGM
//{
//  template< class T>
//  CATGMSafePtr<T> MakeSafePtr() {
//    // T * ptr = new T();
//    // return CATGMSafePtr(*ptr);
//
//    CATGMSafePtr<T> safePtr = nullptr;
//    safePtr.TakeOwnership(new T());
//    return safePtr; // move
//  }
//
//  template< class U, class... Args >
//  CATGMSafePtr<U> MakeSafePtr(Args&&... args) {
//    /*U * ptr = new U(std::forward<Args>(args)...);
//    return CATGMSafePtr(*ptr);*/
//    
//    CATGMSafePtr<U> safePtr = nullptr;
//    U * ptr = new U(std::forward<Args>(args)...);
//    safePtr.TakeOwnership(ptr);
//    
//    return safePtr; // move
//  }
//}

// Constructor with null
//template <class T>
//constexpr CATGMSafePtr<T>::CATGMSafePtr( std::nullptr_t ) noexcept : 
//_ptrObj(nullptr) 
//{
//
//}

// Constructor with Pointer
template <class T>
CATGMSafePtr<T>::CATGMSafePtr(T * ipPointer) noexcept : 
_ptrObj(ipPointer)
{ 
  if (_ptrObj) 
    _ptrObj->AddRef(); 
}

// Copy - Constructor 
template <class T>
CATGMSafePtr<T>::CATGMSafePtr(const CATGMSafePtr & iHandler) noexcept : 
_ptrObj(iHandler._ptrObj) 
{
  if (_ptrObj)
    _ptrObj->AddRef();
}  


// Move  - Constructor 
template <class T>
CATGMSafePtr<T>::CATGMSafePtr(CATGMSafePtr && iHandler) noexcept : _ptrObj(nullptr) 
{
  if (&iHandler != this)
  {
    _ptrObj = iHandler._ptrObj;
    iHandler._ptrObj = nullptr;
  }
}

// Constructor (for make methods) - Removed
//template <class T>
//CATGMSafePtr<T>::CATGMSafePtr(T & iRef) noexcept : 
//_ptrObj(&iRef) 
//{
//  // No addref / nothing
//}



// Destuctor 
template <class T>
CATGMSafePtr<T>::~CATGMSafePtr() 
{
  if (_ptrObj) 
    _ptrObj->Release();
  _ptrObj = nullptr;
}

template <class T>
CATGMSafePtr<T> & CATGMSafePtr<T>::operator = (const CATGMSafePtr &iHandler) noexcept
{
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

template <class T>
CATGMSafePtr<T> & CATGMSafePtr<T>::operator = ( std::nullptr_t ) noexcept
{
  if (_ptrObj)
    _ptrObj -> Release();
  _ptrObj = nullptr;

  return *this;
}


template <class T>
void CATGMSafePtr<T>::Reset() noexcept 
{
  if (_ptrObj)
    _ptrObj -> Release();
  _ptrObj = nullptr; 
}

template <class T>
CATGMSafePtr<T>::operator bool () const noexcept 
{
  if (_ptrObj)
    return true;
  return false;
}

template <class T>
T & CATGMSafePtr<T>::operator*() const noexcept {
  return *_ptrObj; 
}

template <class T>
T * CATGMSafePtr<T>::operator->() const noexcept {
  return _ptrObj; 
}

template <class T>
CATGMSafePtr<T>::operator T * () const noexcept {
  return _ptrObj; 
}

// Private for MakeSafe methods
template <class T>
void CATGMSafePtr<T>::TakeOwnership(T * const iptr) noexcept {
  
  if (_ptrObj)
    _ptrObj -> Release();

  _ptrObj = iptr;
}

#endif
