#pragma once

#include "VisREKernel.h"
#include "vAtomic.h"
#include "vAssert.h"
#include <cstdint>
//#define V_DEBUG_SMART_PTR

namespace VKL
{
  class ExportedByVisREKernel vSmartPtrObject
  {
    template <class T> friend class vSmartPtr;
    template <class T> friend class vWeakPtr;

  public:
    struct Link
    {
      Link() : ptr(NULL), count(0), weakCount(0) {}
      Link(int iRefCount) : ptr(0), count(iRefCount), weakCount(iRefCount > 1) {}
      Link(int iRefCount, int iWeakRefCount) : ptr(0), count(iRefCount), weakCount(iWeakRefCount) {}

      vSmartPtrObject* ptr;
      vAtomic<int> count;
      vAtomic<int> weakCount;
    };

    vSmartPtrObject();
    vSmartPtrObject(const vSmartPtrObject& iSrc);

    virtual ~vSmartPtrObject();

    virtual int GetReferenceCount() const;
    virtual int GetWeakReferenceCount() const;
    bool IsReferenced() const;

    // Override assignment so that Link is not copied
    inline vSmartPtrObject& operator = (const vSmartPtrObject& iOther) { return *this; }
    /**
    Destroy the object pointed by the smart	pointers.
    The object is really destroyed now, not waiting for the reference count to reach 0.
    Other smart pointer previously pointing on the destroyed object will now point to a Null object,
    and when they will all release their reference, the space used by the old pointer will be released.
    */
    virtual void Destroy();

  protected:

    enum { kNullLinkRefCount = -1 };
    enum { kNullWeakLinkRefCount = -1 };

    /**
    Virtual to override if some book keeping destruction code is needed.
    This function is called just before the deletion of the object.
    Don't forget to call the ParentClass::_Destroy() function.
    */
    virtual	void _Destroy();

    mutable Link* m_Link;

    vAtomicFlag m_IsBeingDestroyed;
    // the static Null Block
    static Link s_NullLink;
  };

  // template <> struct vIsPod<vSmartPtrObject::Link> { enum { result = 1 }; };


  class ExportedByVisREKernel vSmartPtrManager
  {
  public:
    template <class T> friend class vSmartPtr;
    friend class vSmartPtrObject;

    // Blocks Management
    vSmartPtrObject::Link* GetFreeLink();
    void ReleaseLink(vSmartPtrObject::Link* iLink);
  };

  /**
  Templated SmartPtr class.

  This smart pointer class handles manually destroyed objects, by
  delocalizing the refCount into a small structure, called the link.
  Hence, you can destroy an object, or replace it, either if it is still referenced
  by many objects.

  You have to derive from the vSmartPtrObject to be referenced by a vSmartPtr.

  @see vSmartPtrObject

  @code
  vSmartPtr<Shape> myShape = ///;
  myShape->Draw();
  myShape->Destroy();
  // myShape->Draw; // will crash
  myShape = 0; // to release the link, if we had the last reference on it.
  @endcode
  */
  template <class T>
  class vSmartPtr
  {
    template <class U> friend class vSmartPtr;
    template <class U> friend class vWeakPtr;

  public:
    inline vSmartPtr();
    inline vSmartPtr(const vSmartPtrObject* iP);
    inline vSmartPtr(const vSmartPtr& iCopy);
    inline vSmartPtr(vSmartPtr&& iMove);

    ~vSmartPtr();

    inline const vSmartPtrObject::Link* _GetLink() const { return m_Ref; }

    // Tracking functions
#ifdef V_DEBUG_SMART_PTR
    void StartDebugThisRefCount();
    void StopDebugThisRefCount();
#endif

    inline vSmartPtr& operator   =(const vSmartPtrObject* iP);
    inline vSmartPtr<T>& operator=(const vSmartPtr<T>& iCopy);
    inline vSmartPtr<T>& operator=(vSmartPtr<T>&& iMove);

    template <class U>
    inline vSmartPtr<T>& operator=(const vSmartPtr<U>& iCopy)
    {
      if (m_Ref->ptr == iCopy.m_Ref->ptr) return *this;
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
    inline operator vSmartPtr<U>()
    {
      return vSmartPtr<U>(Ptr());
    }

    inline T* operator->() const { return (T*)(m_Ref->ptr); }
    inline T& operator*() const { return *(T*)(m_Ref->ptr); }

    inline operator T*() const { return (T*)(m_Ref->ptr); }
    inline T* Ptr() const { return (T*)(m_Ref->ptr); }

  protected:

    inline void _Set(const vSmartPtrObject* iP);
    inline void _AddRef();
    inline void _Release();
    inline void _DeleteObject();

#ifdef V_DEBUG_SMART_PTR
    inline void _TraceAddRef();
    inline void _TraceRelease();
#endif

    vSmartPtrObject::Link* m_Ref;
  };

  template <class T, class U>
  inline vSmartPtr<T>& Cast(const vSmartPtr<U>& S) { return *(vSmartPtr<T>*)(&S); }

  // vSmartPtrObject
  inline vSmartPtrObject::vSmartPtrObject()
  {
    vSmartPtrManager spMan;
    m_Link = spMan.GetFreeLink();
    m_Link->ptr = this;
    m_Link->count = 0;
  }

  inline vSmartPtrObject::vSmartPtrObject(const vSmartPtrObject& iSrc)
  {
    vSmartPtrManager spMan;
    m_Link = spMan.GetFreeLink();
    m_Link->ptr = this;
    m_Link->count = 0;
  }

  inline bool vSmartPtrObject::IsReferenced() const
  {
    return vSmartPtrObject::GetReferenceCount() != 0;
  }

  // vSmartPtr
  template <class T>
  inline vSmartPtr<T>::vSmartPtr()
  {
    m_Ref = &vSmartPtrObject::s_NullLink;
  }

  template <class T>
  inline vSmartPtr<T>::vSmartPtr(const vSmartPtrObject* iP)
  {
    _Set(iP);
  }

  template <class T>
  inline vSmartPtr<T>::vSmartPtr(const vSmartPtr& iCopy)
  {
    if (iCopy.m_Ref != &vSmartPtrObject::s_NullLink)
    {
      m_Ref = iCopy.m_Ref;
      _AddRef();
    }
    else
    {
      m_Ref = &vSmartPtrObject::s_NullLink;
    }
  }
  
  template <class T>
  inline vSmartPtr<T>::vSmartPtr(vSmartPtr&& iMove) : m_Ref(iMove.m_Ref)
  {
    iMove.m_Ref = &vSmartPtrObject::s_NullLink;
  }
  
  template <class T>
  inline vSmartPtr<T>::~vSmartPtr()
  {
    _Release();
  }

  template <class T>
  inline vSmartPtr<T>& vSmartPtr<T>::operator=(const vSmartPtrObject* iP)
  {
    if (m_Ref->ptr == iP) return *this;

    _Release();
    _Set(iP);

    return *this;
  }

  template <class T>
  inline vSmartPtr<T>& vSmartPtr<T>::operator=(const vSmartPtr<T>& iCopy)
  {
    if (m_Ref->ptr == iCopy.m_Ref->ptr) return *this;
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
  inline vSmartPtr<T>& vSmartPtr<T>::operator=(vSmartPtr<T>&& iMove)
  {
    if (m_Ref->ptr == iMove.m_Ref->ptr) return *this;
    _Release();
    m_Ref = iMove.m_Ref;
    iMove.m_Ref = &vSmartPtrObject::s_NullLink;
    return *this;
  }
  
  template <class T>
  inline void vSmartPtr<T>::_AddRef()
  {
    V_ASSERT(m_Ref != &vSmartPtrObject::s_NullLink);
    if (!m_Ref->count++)
      m_Ref->weakCount++;

#ifdef V_DEBUG_SMART_PTR
    _TraceAddRef();
#endif
  }

  template <class T>
  inline void vSmartPtr<T>::_Release()
  {
#ifdef V_DEBUG_SMART_PTR		
    _TraceRelease();
#endif

    if (m_Ref->count.Load() == vSmartPtrObject::kNullLinkRefCount)
      return;

    if (!--m_Ref->count)
    {
      _DeleteObject();
    }
  }

  template <class T>
  inline void vSmartPtr<T>::_Set(const vSmartPtrObject* iP)
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

  template <class T>
  void vSmartPtr<T>::_DeleteObject()
  {
    // No more reference on the pointee : delete it
    vSmartPtrObject* const object = m_Ref->ptr;

    if (object && !object->m_IsBeingDestroyed.TestAndSet())
    {
      object->_Destroy();
      V_ASSERT(m_Ref->ptr == 0); // Should have been reset by the dtor called in object->Destroy

                                 // and we release the block

      if (!(--m_Ref->weakCount))
      {
        vSmartPtrManager spMan;
        spMan.ReleaseLink(m_Ref);
      }
    }
  }

#ifdef V_DEBUG_SMART_PTR
  template <class T>
  void vSmartPtr<T>::_TraceAddRef()
  {
    // 	if(vSmartPtrManager::s_Instance && m_Ref==vSmartPtrManager::s_Instance->m_DebugRefAddress)
    // 	{
    // 		char buffer[128];
    // 		vkSprintf(buffer, sizeof(buffer), "ADDREF------------------ %d\n", m_Ref->count);
    // 		vkDebugTools::OutputString(buffer);
    // 		vkString stack;
    // 		vkDebugTools::ComputeCallStack(stack, 10);
    // 		vkDebugTools::OutputString(stack);
    // 		vkDebugTools::OutputString("\n------------------------\n");
    // 
    // 		V_ASSERT(!vSmartPtrManager::s_Instance->m_DebugCallStacks.IsHere(this));
    // 		vSmartPtrManager::s_Instance->m_DebugCallStacks.Insert(this, stack);
    // 	}
  }

  template <class T>
  void vSmartPtr<T>::_TraceRelease()
  {
    // 	if (vSmartPtrManager::s_Instance && m_Ref==vSmartPtrManager::s_Instance->m_DebugRefAddress) {
    // 		char buffer[128];
    // 		vkSprintf(buffer, sizeof(buffer), "RELEASE----------------- %d\n", m_Ref->count-1);
    // 		vkDebugTools::OutputString(buffer);
    // 		vkString stack;
    // 		vkDebugTools::ComputeCallStack(stack, 10);
    // 		vkDebugTools::OutputString(stack);
    // 		vkDebugTools::OutputString("\n------------------------\n");
    // 
    // 		//V_ASSERT(vSmartPtrManager::s_Instance->m_DebugCallStacks.IsHere(this));
    // 		vSmartPtrManager::s_Instance->m_DebugCallStacks.Remove(this);
    // 	}
  }

  template <class T>
  void vSmartPtr<T>::StartDebugThisRefCount()
  {
    // 	vSmartPtrManager::Instance().m_DebugRefAddress = m_Ref;
    // 	vSmartPtrManager::Instance().m_DebugCallStacks.Empty();
    // 
    // 	char buffer[128];
    // 	vkSprintf(buffer, sizeof(buffer), "Start RefCount Debug---- %d\n", m_Ref->count);
    // 	vkDebugTools::OutputString(buffer);
  }

  template <class T>
  void vSmartPtr<T>::StopDebugThisRefCount()
  {
    // 	vSmartPtrManager::Instance().m_DebugRefAddress = 0;
    // 	vSmartPtrManager::Instance().m_DebugCallStacks.Empty();
  }

#endif // V_DEBUG_SMART_PTR
}
