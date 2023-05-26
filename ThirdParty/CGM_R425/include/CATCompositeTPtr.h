#ifndef CATCompositeTPtr_h_
#define CATCompositeTPtr_h_

#include "SGComposites.h"

// SpecialAPI (ProtectedInterfaces)
#include "CATSysMacroPtr.h"

// SGInfra (ProtectedInterfaces)
#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
template<typename T>
class CATCompositeTPtr;

template<typename T>
class CATCompositeTWeakPtr;

class CATOnStackBorrowBasePtr;

template<typename T>
class CATOnStackBorrowPtr;

/**
* Smart pointer to hold a CATSGComposite with automatic AddRef/Release.
* (not derived from CATCompositeBasePtr because vtable would double the size of the class which is used everywhere)
*/
template<typename T>
class CATCompositeTPtr
{
public:
    typedef T type;

    CATCompositeTPtr();
    CATCompositeTPtr(T* iPtr);
    CATCompositeTPtr(const CATCompositeTPtr<T>& iOther);
    CATCompositeTPtr(const CATCompositeTWeakPtr<T>& iOther);
    CATCompositeTPtr(const CATOnStackBorrowBasePtr& iOther);
    template<typename U>
    CATCompositeTPtr(const CATCompositeTPtr<U>& iOther);
    template<typename U>
    CATCompositeTPtr(const CATCompositeTWeakPtr<U>& iOther);
    ~CATCompositeTPtr();

    void Free();

    void* PtrAsVoid() const;
    T* Ptr() const;
    const T* ConstPtr() const;

    bool IsValid() const;
    const bool IsTraitSupported(const GUID& iTraitGUID) const;

    T* operator->();
    const T* operator->() const;

    bool operator==(const CATCompositeTPtr<T>& iOther) const;
    bool operator!=(const CATCompositeTPtr<T>& iOther) const;
    bool operator==(const T* iT) const;
    bool operator!=(const T* iT) const;

    CATCompositeTPtr<T>& operator=(T* iPtr);
    CATCompositeTPtr<T>& operator=(const CATCompositeTPtr<T>& iOther);
    CATCompositeTPtr<T>& operator=(const CATCompositeTWeakPtr<T>& iOther);
    CATCompositeTPtr<T>& operator=(const CATOnStackBorrowBasePtr& iOther);

    template<typename U>
    CATCompositeTPtr<T>& operator=(const CATCompositeTPtr<U>& iOther);
    template<typename U>
    CATCompositeTPtr<T>& operator=(const CATCompositeTWeakPtr<U>& iOther);

    static CATCompositeTPtr<T> NaTValue();

private:
    static void* operator new(std::size_t) = delete;
    static void* operator new[](std::size_t) = delete;

private:
    T* _ptr;
};

/**
* Smart pointer to hold a CATSGComposite WITHOUT AddRef.
* (not derived from CATCompositeBasePtr because vtable would double the size of the class which is used everywhere)
*/
template<typename T>
class CATCompositeTWeakPtr
{
public:
    typedef T type;

    CATCompositeTWeakPtr();
    CATCompositeTWeakPtr(T* iPtr);
    CATCompositeTWeakPtr(const CATCompositeTPtr<T>& iOther);
    CATCompositeTWeakPtr(const CATCompositeTWeakPtr<T>& iOther);
    CATCompositeTWeakPtr(const CATOnStackBorrowBasePtr& iOther);
    template<typename U>
    CATCompositeTWeakPtr(const CATCompositeTPtr<U>& iOther);
    template<typename U>
    CATCompositeTWeakPtr(const CATCompositeTWeakPtr<U>& iOther);
    ~CATCompositeTWeakPtr();

    void* PtrAsVoid() const;
    T* Ptr() const;
    const T* ConstPtr() const;

    bool IsValid() const;
    const bool IsTraitSupported(const GUID& iTraitGUID) const;

    T* operator->();
    const T* operator->() const;

    bool operator==(const CATCompositeTWeakPtr<T>& iOther) const;
    bool operator!=(const CATCompositeTWeakPtr<T>& iOther) const;
    bool operator==(const T* iT) const;
    bool operator!=(const T* iT) const;

    CATCompositeTWeakPtr<T>& operator=(T* iPtr);
    CATCompositeTWeakPtr<T>& operator=(const CATCompositeTPtr<T>& iOther);
    CATCompositeTWeakPtr<T>& operator=(const CATCompositeTWeakPtr<T>& iOther);
    CATCompositeTWeakPtr<T>& operator=(const CATOnStackBorrowBasePtr& iOther);

    template<typename U>
    CATCompositeTWeakPtr<T>& operator=(const CATCompositeTPtr<U>& iOther);
    template<typename U>
    CATCompositeTWeakPtr<T>& operator=(const CATCompositeTWeakPtr<U>& iOther);

    static CATCompositeTWeakPtr<T> NaTValue();

private:
    static void* operator new(std::size_t) = delete;
    static void* operator new[](std::size_t) = delete;

private:
    T* _ptr;
};

/**
* Smart pointer to hold a CATSGComposite WITHOUT AddRef.
* (heavier than CATCompositeTPtr and CATCompositeTWeakPtr because it has a vtable)
*/
class ExportedBySGComposites CATOnStackBorrowBasePtr
{
public:
    CATOnStackBorrowBasePtr();
    CATOnStackBorrowBasePtr(void* iPtr);
    CATOnStackBorrowBasePtr(const CATOnStackBorrowBasePtr& iOther);
    template<typename U>
    CATOnStackBorrowBasePtr(const CATCompositeTPtr<U>& iOther);
    template<typename U>
    CATOnStackBorrowBasePtr(const CATCompositeTWeakPtr<U>& iOther);
    virtual ~CATOnStackBorrowBasePtr();

    virtual void* PtrAsVoid() const;

    virtual bool IsValid() const;
    virtual const bool IsTraitSupported(const GUID& /*iTraitGUID*/) const;

    virtual bool operator==(const CATOnStackBorrowBasePtr& iOther) const;
    virtual bool operator!=(const CATOnStackBorrowBasePtr& iOther) const;
    virtual bool operator==(const void* iT) const;
    virtual bool operator!=(const void* iT) const;

    CATOnStackBorrowBasePtr& operator=(void* iPtr);
    CATOnStackBorrowBasePtr& operator=(const CATOnStackBorrowBasePtr& iOther);

    template<typename U>
    CATOnStackBorrowBasePtr& operator=(const CATCompositeTPtr<U>& iOther);
    template<typename U>
    CATOnStackBorrowBasePtr& operator=(const CATCompositeTWeakPtr<U>& iOther);

    static CATOnStackBorrowBasePtr NaTValue();

private:
    static void* operator new(std::size_t) = delete;
    static void* operator new[](std::size_t) = delete;

protected:
    void* _ptr;
};

/**
* Smart pointer to hold a CATSGComposite WITHOUT AddRef.
* (heavier than CATCompositeTPtr and CATCompositeTWeakPtr because it has a vtable)
*/
template<typename T>
class ExportedBySGComposites CATOnStackBorrowPtr : public CATOnStackBorrowBasePtr
{
public:
    typedef T type;

    CATOnStackBorrowPtr();
    CATOnStackBorrowPtr(void* iPtr);
    CATOnStackBorrowPtr(const CATCompositeTPtr<T>& iOther);
    CATOnStackBorrowPtr(const CATCompositeTWeakPtr<T>& iOther);
    CATOnStackBorrowPtr(const CATOnStackBorrowBasePtr& iOther);

    virtual T* Ptr() const;
    virtual const T* ConstPtr() const;

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const;

    virtual T* operator->();
    virtual const T* operator->() const;

private:
    static void* operator new(std::size_t) = delete;
    static void* operator new[](std::size_t) = delete;
};


#include "CATSGComposite.h"

template<typename T, typename U>
T* StaticCast(CATCompositeTPtr<U>& iBasePtr)
{
    return static_cast<T*>(iBasePtr.PtrAsVoid());
}

template<typename T, typename U>
const T* StaticConstCast(const CATCompositeTPtr<U>& iBasePtr)
{
    return static_cast<const T*>(iBasePtr.PtrAsVoid());
}

template<typename T, typename U>
bool SafeConvertPtr(const CATCompositeTPtr<T>& iOriginPtr, CATCompositeTPtr<U>& ioDestPtr)
{
    if (iOriginPtr.IsValid()
        && ((CATTraitInfo<U>::GetTraitTag() >= 0 && iOriginPtr->IsTraitSupported(CATTraitInfo<U>::GetTraitTag()))
        || (iOriginPtr->IsTraitSupported(CATTraitInfo<U>::GetTraitGUID()))))
    {
        ioDestPtr = iOriginPtr;
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T, typename U>
T* StaticCast(CATCompositeTWeakPtr<U>& iBasePtr)
{
    return static_cast<T*>(iBasePtr.PtrAsVoid());
}

template<typename T, typename U>
const T* StaticConstCast(const CATCompositeTWeakPtr<U>& iBasePtr)
{
    return static_cast<const T*>(iBasePtr.PtrAsVoid());
}

template<typename T, typename U>
bool SafeConvertPtr(const CATCompositeTWeakPtr<T>& iOriginPtr, CATCompositeTWeakPtr<U>& ioDestPtr)
{
    if (iOriginPtr.IsValid()
        && ((CATTraitInfo<U>::GetTraitTag() >= 0 && iOriginPtr->IsTraitSupported(CATTraitInfo<U>::GetTraitTag()))
            || (iOriginPtr->IsTraitSupported(CATTraitInfo<U>::GetTraitGUID()))))
    {
        ioDestPtr = iOriginPtr;
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
T* StaticCast(CATOnStackBorrowBasePtr& iBasePtr)
{
    return static_cast<T*>(iBasePtr.PtrAsVoid());
}

template<typename T>
const T* StaticConstCast(const CATOnStackBorrowBasePtr& iBasePtr)
{
    return static_cast<const T*>(iBasePtr.PtrAsVoid());
}

template<typename T, typename U>
bool SafeConvertPtr(const CATOnStackBorrowPtr<T>& iOriginPtr, CATOnStackBorrowPtr<U>& ioDestPtr)
{
    if (iOriginPtr.IsValid()
        && ((CATTraitInfo<U>::GetTraitTag() >= 0 && iOriginPtr->IsTraitSupported(CATTraitInfo<U>::GetTraitTag()))
            || (iOriginPtr->IsTraitSupported(CATTraitInfo<U>::GetTraitGUID()))))
    {
        ioDestPtr = iOriginPtr;
        return true;
    }
    else
    {
        return false;
    }
}


// CATCompositeTPtr inline methods definition

template<typename T>
CATCompositeTPtr<T>::CATCompositeTPtr() : _ptr(nullptr) {}
template<typename T>
CATCompositeTPtr<T>::CATCompositeTPtr(T* iPtr) : _ptr(iPtr) { if (_ptr) _ptr->AddRef(); }
template<typename T>
CATCompositeTPtr<T>::CATCompositeTPtr(const CATCompositeTPtr<T>& iOther) : CATCompositeTPtr(iOther.Ptr()) {}
template<typename T>
CATCompositeTPtr<T>::CATCompositeTPtr(const CATCompositeTWeakPtr<T>& iOther) : CATCompositeTPtr(iOther.Ptr()) {}
template<typename T>
CATCompositeTPtr<T>::CATCompositeTPtr(const CATOnStackBorrowBasePtr& iOther) : CATCompositeTPtr(static_cast<T*>(iOther.PtrAsVoid())) {}
template<typename T> template<typename U>
CATCompositeTPtr<T>::CATCompositeTPtr(const CATCompositeTPtr<U>& iOther) : CATCompositeTPtr(static_cast<T*>(iOther.PtrAsVoid())) {}
template<typename T> template<typename U>
CATCompositeTPtr<T>::CATCompositeTPtr(const CATCompositeTWeakPtr<U>& iOther) : CATCompositeTPtr(static_cast<T*>(iOther.PtrAsVoid())) {}
template<typename T>
CATCompositeTPtr<T>::~CATCompositeTPtr() { Free(); }
template<typename T>
void CATCompositeTPtr<T>::Free() { CATSysReleasePtr(_ptr); }
template<typename T>
void* CATCompositeTPtr<T>::PtrAsVoid() const { return _ptr; }
template<typename T>
T* CATCompositeTPtr<T>::Ptr() const { return _ptr; }
template<typename T>
const T* CATCompositeTPtr<T>::ConstPtr() const { return _ptr; }
template<typename T>
bool CATCompositeTPtr<T>::IsValid() const { return (_ptr != nullptr); }
template<typename T>
const bool CATCompositeTPtr<T>::IsTraitSupported(const GUID& iTraitGUID) const { return (_ptr ? _ptr->IsTraitSupported(iTraitGUID) : false); }
template<typename T>
T* CATCompositeTPtr<T>::operator->() { return _ptr; }
template<typename T>
const T* CATCompositeTPtr<T>::operator->() const { return _ptr; }
template<typename T>
bool CATCompositeTPtr<T>::operator==(const CATCompositeTPtr<T>& iOther) const { return (_ptr == iOther._ptr); }
template<typename T>
bool CATCompositeTPtr<T>::operator!=(const CATCompositeTPtr<T>& iOther) const { return (_ptr != iOther._ptr); }
template<typename T>
bool CATCompositeTPtr<T>::operator==(const T* iT) const { return (_ptr == iT); }
template<typename T>
bool CATCompositeTPtr<T>::operator!=(const T* iT) const { return (_ptr != iT); }
template<typename T>
CATCompositeTPtr<T>& CATCompositeTPtr<T>::operator=(T* iPtr)
{
    Free();
    _ptr = iPtr;
    if (_ptr)
        _ptr->AddRef();
    return *this;
}
template<typename T>
CATCompositeTPtr<T>& CATCompositeTPtr<T>::operator=(const CATCompositeTPtr<T>& iOther) { return operator=(iOther.Ptr()); }
template<typename T>
CATCompositeTPtr<T>& CATCompositeTPtr<T>::operator=(const CATCompositeTWeakPtr<T>& iOther) { return operator=(iOther.Ptr()); }
template<typename T>
CATCompositeTPtr<T>& CATCompositeTPtr<T>::operator=(const CATOnStackBorrowBasePtr& iOther) { return operator=(static_cast<T*>(iOther.PtrAsVoid())); }
template<typename T> template<typename U>
CATCompositeTPtr<T>& CATCompositeTPtr<T>::operator=(const CATCompositeTPtr<U>& iOther) { return operator=(static_cast<T*>(iOther.PtrAsVoid())); }
template<typename T> template<typename U>
CATCompositeTPtr<T>& CATCompositeTPtr<T>::operator=(const CATCompositeTWeakPtr<U>& iOther) { return operator=(static_cast<T*>(iOther.PtrAsVoid())); }
template<typename T>
CATCompositeTPtr<T> CATCompositeTPtr<T>::NaTValue() { return CATCompositeTPtr<T>(); }


// CATCompositeTWeakPtr inline methods definition

template<typename T>
CATCompositeTWeakPtr<T>::CATCompositeTWeakPtr() : _ptr(nullptr) {}
template<typename T>
CATCompositeTWeakPtr<T>::CATCompositeTWeakPtr(T* iPtr) : _ptr(iPtr) {}
template<typename T>
CATCompositeTWeakPtr<T>::CATCompositeTWeakPtr(const CATCompositeTPtr<T>& iOther) : CATCompositeTWeakPtr(iOther.Ptr()) {}
template<typename T>
CATCompositeTWeakPtr<T>::CATCompositeTWeakPtr(const CATCompositeTWeakPtr<T>& iOther) : CATCompositeTWeakPtr(iOther.Ptr()) {}
template<typename T>
CATCompositeTWeakPtr<T>::CATCompositeTWeakPtr(const CATOnStackBorrowBasePtr& iOther) : CATCompositeTWeakPtr(static_cast<T*>(iOther.PtrAsVoid())) {}
template<typename T> template<typename U>
CATCompositeTWeakPtr<T>::CATCompositeTWeakPtr(const CATCompositeTPtr<U>& iOther) : CATCompositeTWeakPtr(static_cast<T*>(iOther.PtrAsVoid())) {}
template<typename T> template<typename U>
CATCompositeTWeakPtr<T>::CATCompositeTWeakPtr(const CATCompositeTWeakPtr<U>& iOther) : CATCompositeTWeakPtr(static_cast<T*>(iOther.PtrAsVoid())) {}
template<typename T>
CATCompositeTWeakPtr<T>::~CATCompositeTWeakPtr() { _ptr = nullptr; }
template<typename T>
void* CATCompositeTWeakPtr<T>::PtrAsVoid() const { return _ptr; }
template<typename T>
T* CATCompositeTWeakPtr<T>::Ptr() const { return _ptr; }
template<typename T>
const T* CATCompositeTWeakPtr<T>::ConstPtr() const { return _ptr; }
template<typename T>
bool CATCompositeTWeakPtr<T>::IsValid() const { return (_ptr != nullptr); }
template<typename T>
const bool CATCompositeTWeakPtr<T>::IsTraitSupported(const GUID& iTraitGUID) const { return (_ptr ? _ptr->IsTraitSupported(iTraitGUID) : false); }
template<typename T>
T* CATCompositeTWeakPtr<T>::operator->() { return _ptr; }
template<typename T>
const T* CATCompositeTWeakPtr<T>::operator->() const { return _ptr; }
template<typename T>
bool CATCompositeTWeakPtr<T>::operator==(const CATCompositeTWeakPtr<T>& iOther) const { return (_ptr == iOther._ptr); }
template<typename T>
bool CATCompositeTWeakPtr<T>::operator!=(const CATCompositeTWeakPtr<T>& iOther) const { return (_ptr != iOther._ptr); }
template<typename T>
bool CATCompositeTWeakPtr<T>::operator==(const T* iT) const { return (_ptr == iT); }
template<typename T>
bool CATCompositeTWeakPtr<T>::operator!=(const T* iT) const { return (_ptr != iT); }
template<typename T>
CATCompositeTWeakPtr<T>& CATCompositeTWeakPtr<T>::operator=(T* iPtr) { _ptr = iPtr; return *this; }
template<typename T>
CATCompositeTWeakPtr<T>& CATCompositeTWeakPtr<T>::operator=(const CATCompositeTPtr<T>& iOther) { return operator=(iOther.Ptr()); }
template<typename T>
CATCompositeTWeakPtr<T>& CATCompositeTWeakPtr<T>::operator=(const CATCompositeTWeakPtr<T>& iOther) { return operator=(iOther.Ptr()); }
template<typename T>
CATCompositeTWeakPtr<T>& CATCompositeTWeakPtr<T>::operator=(const CATOnStackBorrowBasePtr& iOther) { return operator=(static_cast<T*>(iOther.PtrAsVoid())); }
template<typename T> template<typename U>
CATCompositeTWeakPtr<T>& CATCompositeTWeakPtr<T>::operator=(const CATCompositeTPtr<U>& iOther) { return operator=(static_cast<T*>(iOther.PtrAsVoid())); }
template<typename T> template<typename U>
CATCompositeTWeakPtr<T>& CATCompositeTWeakPtr<T>::operator=(const CATCompositeTWeakPtr<U>& iOther) { return operator=(static_cast<T*>(iOther.PtrAsVoid())); }
template<typename T>
CATCompositeTWeakPtr<T> CATCompositeTWeakPtr<T>::NaTValue() { return CATCompositeTWeakPtr<T>(); }

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompositeTPtr_h_
