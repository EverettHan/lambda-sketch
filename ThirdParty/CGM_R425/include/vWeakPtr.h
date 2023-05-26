#pragma once

#include "VisREKernel.h"
#include "vSmartPtr.h"

//#define V_DEBUG_SMART_PTR

namespace VKL
{
  /**
  Templated WeakPtr class.

  This smart pointer class handles weak reference to vSmartPtr objects.

  @see vSmartPtrObject

  @code
  @endcode
  */
  template <class T>
  class vWeakPtr
  {
    template <class U> friend class vWeakPtr;
    typedef vSmartPtr<T> vSmartPtrType;

  public:
    vWeakPtr();
    vWeakPtr(const vSmartPtrObject* iP);
    vWeakPtr(const vWeakPtr& iP);
    vWeakPtr(vWeakPtr&& iP);
    vWeakPtr(const vSmartPtrType& iCopy);

    ~vWeakPtr();

    inline const vSmartPtrObject::Link* _GetLink() const { return m_Ref; }

    vWeakPtr& operator    =(const vSmartPtrObject* iP);
    vWeakPtr<T>& operator =(const vWeakPtr<T>& iCopy);
    vWeakPtr<T>& operator =(vWeakPtr<T>&& iCopy);
    vWeakPtr<T>& operator =(const vSmartPtr<T>& iCopy);

    template <class U>
    vWeakPtr<T>& operator =(const vWeakPtr<U>& iCopy)
    {
      if (iCopy.m_Ref->ptr == m_Ref->ptr)
        return *this;
      _Release();

      if (iCopy.m_Ref->ptr != 0)
      {
        m_Ref = iCopy.m_Ref;
        _AddRef();
      }
      else
      {
        m_Ref = &vSmartPtrObject::s_NullLink;
      }

      return *this;
    }

    template <class U>
    operator vWeakPtr<U>()
    {
      return vWeakPtr<U>(Ptr());
    }

    // Function names are same as std::weak_ptr so that we migrate easily
    inline vSmartPtrType lock() const { return vSmartPtrType(Ptr()); }
    inline bool expired() const { return (Ptr() == nullptr) != 0; }
  protected:

    inline T* Ptr() const { return (T*)(m_Ref->ptr); }
    void _AddRef();
    void _Release();
    void _Set(const vSmartPtrObject* iP);

    vSmartPtrObject::Link* m_Ref;
  };

  template <class T, class U>
  inline vWeakPtr<T>& Cast(const vWeakPtr<U>& S) { return *(vWeakPtr<T>*)(&S); }

  // vWeakPtr
  template <class T>
  inline vWeakPtr<T>::vWeakPtr()
  {
    m_Ref = &vSmartPtrObject::s_NullLink;
  }

  // vWeakPtr
  template <class T>
  inline vWeakPtr<T>::vWeakPtr(const vSmartPtrObject* iP)
  {
    _Set(iP);
  }

  template <class T>
  inline vWeakPtr<T>::vWeakPtr(const vWeakPtr& iCpy)
  {
    m_Ref = iCpy.m_Ref;
    _AddRef();
  }

  template <class T>
  inline vWeakPtr<T>::vWeakPtr(const vSmartPtrType& iCpy)
  {
    m_Ref = iCpy.m_Ref;
    _AddRef();
  }
  
  template <class T>
  inline vWeakPtr<T>::vWeakPtr(vWeakPtr&& iMove)
  {
    m_Ref = iMove.m_Ref;
    iMove.m_Ref = &vSmartPtrObject::s_NullLink;
  }

  template <class T>
  inline vWeakPtr<T>::~vWeakPtr()
  {
    _Release();
  }

  template <class T>
  inline vWeakPtr<T>& vWeakPtr<T>::operator=(const vSmartPtrObject* iP)
  {
    if (iP != Ptr())
    {
      _Release();
      _Set(iP);
    }

    return *this;
  }

  template <class T>
  inline vWeakPtr<T>& vWeakPtr<T>::operator=(const vWeakPtr<T>& iCopy)
  {
    if (iCopy.m_Ref->ptr == m_Ref->ptr)
      return *this;
    _Release();

    if (iCopy.m_Ref != &vSmartPtrObject::s_NullLink)
    {
      m_Ref = iCopy.m_Ref;
      _AddRef();
    }
    else
    {
      m_Ref = &vSmartPtrObject::s_NullLink;
    }

    return *this;
  }


  template <class T>
  inline vWeakPtr<T>& vWeakPtr<T>::operator=(const vSmartPtr<T>& iCopy)
  {
    if (iCopy.m_Ref->ptr == m_Ref->ptr)
      return *this;
    _Release();

    if (iCopy._GetLink() != &vSmartPtrObject::s_NullLink)
    {
      _Set(iCopy.Ptr());
    }
    else
    {
      m_Ref = &vSmartPtrObject::s_NullLink;
    }

    return *this;
  }

  template <class T>
  inline vWeakPtr<T>& vWeakPtr<T>::operator=(vWeakPtr<T>&& iMove)
  {
    if (iMove.m_Ref->ptr == m_Ref->ptr)
      return *this;
    _Release();
    m_Ref = iMove.m_Ref;
    iMove.m_Ref = &vSmartPtrObject::s_NullLink;
    return *this;
  }

  template <class T>
  inline void vWeakPtr<T>::_AddRef()
  {
    V_ASSERT(m_Ref != &vSmartPtrObject::s_NullLink);
    m_Ref->weakCount++;
  }

  template <class T>
  inline void vWeakPtr<T>::_Release()
  {
    if(m_Ref->weakCount.Load() != vSmartPtrObject::kNullWeakLinkRefCount)
    {
      if (!(--m_Ref->weakCount))
      {
        vSmartPtrManager m;
        m.ReleaseLink(m_Ref);
      }
    }
  }

  template <class T>
  inline void vWeakPtr<T>::_Set(const vSmartPtrObject* iP)
  {
    if (iP)
    {
      m_Ref = iP->m_Link;
      _AddRef();
    }
    else
    {
      m_Ref = &vSmartPtrObject::s_NullLink;
    }
  }

}

