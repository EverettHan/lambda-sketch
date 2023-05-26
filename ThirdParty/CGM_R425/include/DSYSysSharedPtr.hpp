/**
*   @author: ik8
*/
#ifndef DSYSysSharedPtr_H
#define DSYSysSharedPtr_H

/****************************************************************************/
/* Defines                                                                  */
/****************************************************************************/
#define DSY_SYS_SHARED_PTR_ASSERT

#define NULL_ptr    nullptr

/****************************************************************************/
/* Includes                                                                 */
/****************************************************************************/
#ifdef DSY_SYS_SHARED_PTR_ASSERT
    #include "CATAssert.h"
#else
    #ifndef __CATBBMagic
        #include "CATErrors.h"
        #include "CATBaseError.h"
    #endif
#endif

/****************************************************************************/
/* Macros                                                                   */
/****************************************************************************/
// DO NOT USE
#ifdef DSY_SYS_SHARED_PTR_ASSERT
#define _DSY_SYS_SHARED_PTR_ASSERT_IMPL(iPtr)                               \
        CATAssert(iPtr);
#else
    #ifndef __CATBBMagic
        #define _DSY_SYS_SHARED_PTR_ASSERT_IMPL(iPtr)                       \
        if (!iPtr)                                                          \
        {                                                                   \
            CATError *err_null = new CATBaseError(OleNullHandler);          \
            CATThrow(err_null);                                             \
        }
    #else
        #define _DSY_SYS_SHARED_PTR_ASSERT_IMPL(iPtr)   ((void *)iPtr);
    #endif
#endif

/****************************************************************************/
/* Declarations                                                             */
/****************************************************************************/

/**
 *  DSYSysSharedPtr provides a convenient way to manage the lifecycle of 
 *  objects which types are reference counted. It provides a limited garbage-
 *  collection facility, possibly sharing that management with other objects.
 *  Objects of DSYSysSharedPtr type have the ability of taking ownership of a 
 *  pointer and share that ownership with any other DSYSysSharedPtr instance 
 *  that manages the same underlying pointer. DSYSysSharedPtr objects release 
 *  ownership on the object they co-own as soon as they themselves are 
 *  destroyed or if Reset is called. Once all DSYSysSharedPtr objects that 
 *  share ownership over a pointer have released this ownership, the managed 
 *  object is deleted only if its reference counter is null (by calling 
 *  ::delete).
 *  That allows the developer to keep control over an object's lifecycle by
 *  manually performing AddRef and Release operations.
 */

/**
*  The _DSYSysSharedPtrBase class conforms the CRTP idiom.
*  Its purpose is to factorize some code to ease maintenability of different 
*  smart pointer implementations. It is not meant to be instanciated.
*  Specific smart pointer implementations have to derive from this class as  
*  well as follow the following contract:
*
*  Access must be granted to the following member functions:
*   - const T *_getObject() const
*   - void _setObject(const T *iObj)
*   - void _incRefCnt() 
*   - void _reset()
*   - void _assign(const DSYSysSharedPtr &iRSptr)
*  Moreover, the following declaration has to be made public:
*   - using _DSYSysSharedPtrBase::operator=;
*/
template <class T, class Derived>
class _DSYSysSharedPtrBase
{
    // FRIENDSHIP DECLARATIONS
    template <class Base, class Deriv, class U>
        friend bool operator== (U *, const _DSYSysSharedPtrBase<Base,Deriv> &);
    template <class Base, class Deriv, class U>
        friend bool operator!= (U *, const _DSYSysSharedPtrBase<Base,Deriv> &);
    template <class Base, class Deriv>
        friend bool operator== (decltype(nullptr), const _DSYSysSharedPtrBase<Base,Deriv> &);
    template <class Base, class Deriv>
        friend bool operator!= (decltype(nullptr), const _DSYSysSharedPtrBase<Base,Deriv> &);

public:
    
    // operator T * might cause the compiler to perform invalid implicit conversions.
    // cf. JFL note in file "CATOmxSR.h" (l.138).
    operator T *() = delete;
    operator const T *() const = delete;
    
    /**
    * Get increments the reference counter of the managed object by one and 
    * then returns a pointer to it.
    *
    * @retval pointer to the managed object if the shared pointer is valid.
    * @retval nullptr otherwise.
    */
    T *Get() const;
    
    /**
    * Reset releases the managed object. A call to this function has the same
    * side effects as if the shared pointer's destructor was called before its 
    * value changed.
    */
    void Reset();
    
    /**
    * Dereference operators.
    * If the shared pointer is invalid, an error occurs:
    * if DSY_SYS_SHARED_PTR_ASSERT has been set at compile time, an assertion 
    * failure occurs at runtime ; otherwise, an exception of type CATBaseError 
    * with the code OleNullHandler is thrown.
    *
    * @retval reference to the managed object.
    */
    T *operator->();
    const T *operator->() const;

    T &operator*();
    const T &operator*() const;

    /**
    * Assignement operators.
    *
    * @retval reference to the shared pointer.
    */
    _DSYSysSharedPtrBase &operator=(const _DSYSysSharedPtrBase &iRSptr);
    
    template <class U,class D>
    _DSYSysSharedPtrBase &operator=(const _DSYSysSharedPtrBase<U,D> &iRSptr);

    /**
    * Not operator.
    * Allows to check if the shared pointer is valid, i.e. if it manages a 
    * valid pointer.
    *
    * @retval non-null value if the shared pointer is invalid.
    * @retval 0 otherwise.
    */
    bool operator!() const;

    /**
    * Comparison operators.
    * Allows to check if two shared pointers are managing the same pointer or
    * if a shared pointer manages a given pointer.
    *
    * @retval non-null value if both pointers are equivalent.
    * @retval 0 otherwise.
    */
    template <class U,class D>
    bool operator== (const _DSYSysSharedPtrBase<U,D> &iRSptr) const;

    template <class U,class D>
    bool operator!= (const _DSYSysSharedPtrBase<U,D> &iRSptr) const;
    
    // below operators are taking a non-const parameter to remove 
    // ambiguity with built-in operators
    template <class U>
    bool operator== (U *iPtr) const;
    
    // non-const to disambiguate with built-in operators
    template <class U>
    bool operator!= (U *iPtr) const;
    
    bool operator== (decltype(nullptr)) const {
        return  _isEqual(nullptr);
    }
    
    bool operator!= (decltype(nullptr)) const {
        return !_isEqual(nullptr);
    }

protected:
    bool _isEqual(const T *iPtr) const;

    template<class U>
    bool _isEqual(const U *iPtr) const;
    
    bool _isValid() const;
};

template <class T>
class DSYSysSharedPtr :
 public _DSYSysSharedPtrBase<T,DSYSysSharedPtr<T> >
{
    // FRIENDSHIP DECLARATIONS
    template<class Base, class Derived>
        friend class _DSYSysSharedPtrBase;
    
    // allow other template instances to access 
    // current instance's private member _obj
    template <class U>
        friend class DSYSysSharedPtr;
    
    // MEMBERS
    T      *_obj;

    // ACCESSORS
    const T *_getObject() const;
    void _setObject(const T *iObj);
    
    // FUNCTION MEMBERS
    void _incRefCnt();
    T &_safeRef() const;
    /*inline*/ void _assign(const DSYSysSharedPtr &iRSptr);
    void _reset();
    
public:
    using _DSYSysSharedPtrBase<T,DSYSysSharedPtr<T> >::operator=;
    
    DSYSysSharedPtr();
    
    DSYSysSharedPtr(T *ipObj);

    DSYSysSharedPtr(const DSYSysSharedPtr &iRSptr);

    ~DSYSysSharedPtr();
    
    template<class U>
    DSYSysSharedPtr(const DSYSysSharedPtr<U> &iRSptr);
};

/****************************************************************************/
/* INLINES                                                                  */
/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
/// _DSYSysSharedPtrBase
template<class T, class Derived>
inline T *_DSYSysSharedPtrBase<T,Derived>::Get() const
{
    Derived &deriv = const_cast<Derived &>(static_cast<const Derived &>(*this));
    deriv._incRefCnt();
    return const_cast<T *>(static_cast<const T *>(deriv._getObject()));
}

template<class T, class Derived>
inline void _DSYSysSharedPtrBase<T,Derived>::Reset()
{
    Derived &deriv = const_cast<Derived &>(static_cast<const Derived &>(*this));
    deriv._reset();
}

template<class T, class Derived>
inline T *_DSYSysSharedPtrBase<T,Derived>::operator->()
{
    const Derived &deriv = static_cast<const Derived &>(*this);
    return static_cast<T *>(&deriv._safeRef());
}

template<class T, class Derived>
inline const T *_DSYSysSharedPtrBase<T,Derived>::operator->() const
{
    const Derived &deriv = static_cast<const Derived &>(*this);
    return static_cast<const T *>(&deriv._safeRef());
}

template<class T, class Derived>
inline T &_DSYSysSharedPtrBase<T,Derived>::operator*()
{
    Derived &deriv = const_cast<Derived &>(static_cast<const Derived &>(*this));
    return static_cast<T &>(deriv._safeRef());
}

template<class T, class Derived>
inline const T &_DSYSysSharedPtrBase<T,Derived>::operator*() const
{
    Derived &deriv = const_cast<Derived &>(static_cast<const Derived &>(*this));
    return static_cast<const T &>(deriv._safeRef());
}

template<class T, class Derived>
inline _DSYSysSharedPtrBase<T,Derived> &_DSYSysSharedPtrBase<T,Derived>::operator=(const _DSYSysSharedPtrBase<T,Derived> &iRSptr)
{
    Derived &deriv  = static_cast<Derived &>(*this);
    Derived &iDeriv = const_cast<Derived &>(static_cast<const Derived &>(iRSptr));
    deriv._assign(iDeriv);
    return *this;
}

template<class T, class Derived>
template<class U, class D>
inline _DSYSysSharedPtrBase<T,Derived> &_DSYSysSharedPtrBase<T,Derived>::operator=(const _DSYSysSharedPtrBase<U,D> &iRSptr)
{
    Derived &deriv  = static_cast<Derived &>(*this);
    D       &iDeriv = const_cast<D &>(static_cast<const D &>(iRSptr));
    deriv._assign(iDeriv);
    return *this;
}

template<class T, class Derived>
inline bool _DSYSysSharedPtrBase<T,Derived>::operator!() const
{
    return !_isValid();
}

template<class T, class Derived>
template <class U, class D>
inline bool _DSYSysSharedPtrBase<T,Derived>::operator== (const _DSYSysSharedPtrBase<U,D> &iRSptr) const
{
    const D &deriv = static_cast<const D &>(iRSptr);
    return _isEqual(deriv._getObject());
}

template<class T, class Derived>
template <class U, class D>
inline bool _DSYSysSharedPtrBase<T,Derived>::operator!= (const _DSYSysSharedPtrBase<U,D> &iRSptr) const
{
    
    const D &deriv = static_cast<const D &>(iRSptr);
    return !_isEqual(deriv._getObject());
}

template<class T, class Derived>
template <class U>
inline bool _DSYSysSharedPtrBase<T,Derived>::operator== (U *iPtr) const
{
    return _isEqual(iPtr);
}

template<class T, class Derived>
template <class U>
inline bool _DSYSysSharedPtrBase<T,Derived>::operator!= (U *iPtr) const
{
    return !_isEqual(iPtr);
}

template<class T, class Derived>
inline bool _DSYSysSharedPtrBase<T,Derived>::_isEqual(const T *iPtr) const
{
    const Derived &deriv = static_cast<const Derived &>(*this);
    if(deriv._getObject() == iPtr)
        return true;
    else
        return false;
}

template<class T, class Derived>
template <class U>
inline bool _DSYSysSharedPtrBase<T,Derived>::_isEqual(const U *iPtr) const
{
    const Derived &deriv = static_cast<const Derived &>(*this);
    if(deriv._getObject() == iPtr)
        return true;
    else
        return false;
}

template<class T, class Derived>
inline bool _DSYSysSharedPtrBase<T,Derived>::_isValid() const
{
    return !_isEqual((T *)nullptr);
}

//////////////////////////////////////////////////////////////////////////////
/// DSYSysSharedPtr
template<class T>
inline DSYSysSharedPtr<T>::DSYSysSharedPtr() : _obj(nullptr)
{
    _incRefCnt();
}

template<class T>
inline DSYSysSharedPtr<T>::DSYSysSharedPtr(T *ipObj) 
    : _obj(ipObj)
{
    _incRefCnt();
}

template<class T>
inline DSYSysSharedPtr<T>::DSYSysSharedPtr(const DSYSysSharedPtr &iRSptr) 
    : _obj(iRSptr._obj)
{
    _incRefCnt();
}

template<class T>
inline DSYSysSharedPtr<T>::~DSYSysSharedPtr()
{
    _reset();
}

template<class T>
template<class U>
inline DSYSysSharedPtr<T>::DSYSysSharedPtr(const DSYSysSharedPtr<U> &iRSptr) 
    : _obj(const_cast<U *>(iRSptr._obj))
{
    _incRefCnt();
}

template<class T>
inline const T *DSYSysSharedPtr<T>::_getObject() const 
{
    return _obj; 
}

template<class T>
inline void DSYSysSharedPtr<T>::_setObject(const T *iObj) 
{
    _obj = const_cast<T *>(iObj);
}

template<class T>
inline void DSYSysSharedPtr<T>::_incRefCnt()
{
    if(_obj)
        _obj->AddRef(); 
}

template<class T>
inline T &DSYSysSharedPtr<T>::_safeRef() const
{
    _DSY_SYS_SHARED_PTR_ASSERT_IMPL(_obj)
    return const_cast<T &>(*_obj);
}

template<class T>
/*inline*/ void DSYSysSharedPtr<T>::_assign(const DSYSysSharedPtr &iRSptr)
{   
    if(iRSptr._obj != _obj)
    {
        if(_obj)
            _obj->Release();
        _setObject(iRSptr._obj);
        _incRefCnt();
    }
}

template<class T>
inline void DSYSysSharedPtr<T>::_reset()
{
    if(_obj)
        _obj->Release();
    _setObject(nullptr);
}

//////////////////////////////////////////////////////////////////////////////
/// Global scope operators

// Comparison operators

template <class T,class Deriv, class U>
inline bool operator== (U *iPtr, const _DSYSysSharedPtrBase<T,Deriv> &iRSptr)
{
    return iRSptr._isEqual(iPtr);
}

template <class T, class Deriv>
inline bool operator== (decltype(nullptr), const _DSYSysSharedPtrBase<T,Deriv> &iRSptr)
{
    return iRSptr._isEqual(nullptr);
}

template <class T, class Deriv, class U>
inline bool operator!= (U *iPtr, const _DSYSysSharedPtrBase<T,Deriv> &iRSptr)
{
    return !iRSptr._isEqual(iPtr);
}

template <class T, class Deriv>
inline bool operator!= (decltype(nullptr), const _DSYSysSharedPtrBase<T,Deriv> &iRSptr)
{
    return !iRSptr._isEqual(nullptr);
}

#endif  // DSYSysSharedPtr_H
