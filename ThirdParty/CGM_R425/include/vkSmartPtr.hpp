VK_INLINE vkSmartPtrObject::vkSmartPtrObject(vkCtx iCtxHandle)
: ParentClass(iCtxHandle)
{
	vkSmartPtrManager& spMan = vkSmartPtrManager::Instance();
	m_Link			= spMan.GetFreeLink();
	m_Link->ptr		= this;
	m_Link->count	= 0;
}

VK_INLINE vkSmartPtrObject::vkSmartPtrObject(const vkSmartPtrObject& iSrc):vkObject(iSrc)
{
	vkSmartPtrManager& spMan = vkSmartPtrManager::Instance();
	m_Link			= spMan.GetFreeLink();
	m_Link->ptr		= this;
	m_Link->count	= 0;
}

VK_INLINE bool
vkSmartPtrObject::IsBeingDestroyed() const
{
	return (m_ObjectFlags & fIsBeingDestroyed) != 0;
}

VK_INLINE bool 
vkSmartPtrObject::IsUncorrupted() const
{
	if (m_Link) {
		return (m_Link->ptr == this);
	}
	return false;
}


VK_INLINE bool 
vkSmartPtrObject::IsReferenced() const
{
	// Explicit call to this implementation
	// to speed up the call.
	return vkSmartPtrObject::GetReferenceCount() != 0;
}

////////////////////////////////////////////////////////////////////////////////

VK_INLINE vkSmartPtrObject::Link*		
vkSmartPtrManager::GetFreeLink()
{
	vkMutex::Lock mutexLock(m_Mutex);
	return m_Links.New();
}

VK_INLINE void		
vkSmartPtrManager::ReleaseLink(vkSmartPtrObject::Link* iLink)
{
	VKASSERTEX((iLink->count <= 0) && (iLink->ptr == 0), "The Smart Link is not in a proper form for deletion");
	vkMutex::Lock mutexLock(m_Mutex);
	m_Links.Delete(iLink);
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
VK_INLINE vkSmartPtr<T>::vkSmartPtr()
{
	m_Ref = &vkSmartPtrObject::s_NullLink;
}

template <class T>
VK_INLINE vkSmartPtr<T>::vkSmartPtr(const T* iP) 
{
	_Set((const vkSmartPtrObject*)iP);
}

template <class T>
VK_INLINE vkSmartPtr<T>::vkSmartPtr(const vkSmartPtr& iCopy) 
{
//	if (iCopy.m_Ref->ptr != 0) {
	if (iCopy.m_Ref != &vkSmartPtrObject::s_NullLink) {
		m_Ref = iCopy.m_Ref;
		_AddRef();
	} else { // we just copy something hollow -> prefer the null link
		m_Ref = &vkSmartPtrObject::s_NullLink;
	}
}

template <class T>
VK_INLINE vkSmartPtr<T>::~vkSmartPtr() 
{
	_Release();
}

template <class T>	
VK_INLINE void 
vkSmartPtr<T>::SwapObjects(vkSmartPtr<T>& iOther) 
{
	_SwapObjects(iOther);
}

////////////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE vkSmartPtr<T>& 
vkSmartPtr<T>::operator=(const T* iP) 
{
	if (!iP || (iP != Ptr())) { // release if sets to null and the pointer was already null
		_Release();
		_Set(iP);
	}
	return *this;
}

template <class T>
VK_INLINE vkSmartPtr<T>& 
vkSmartPtr<T>::operator=(const vkSmartPtr<T>& iCopy) 
{
	// we do not have to test for equality since
	// we have 2 ptrs, the refCount is >= 2 so we 
	// can afford Release then AddRef
	_Release();

//	if (iCopy.m_Ref->ptr != 0) {
	if (iCopy.m_Ref != &vkSmartPtrObject::s_NullLink) {
		m_Ref = iCopy.m_Ref;
		_AddRef();
	} else { // we just copy something hollow -> prefer the null link
		m_Ref = &vkSmartPtrObject::s_NullLink;
	}

	return *this;
}


////////////////////////////////////////////////////////////////////////////////

VK_INLINE
void 
vkSmartPtrBase::_AddRef()
{
	VKASSERT(m_Ref != &VKernel::vkSmartPtrObject::s_NullLink);
	vkAtomicIncrement32(m_Ref->count);

#ifdef VK_SUPPORT_DEBUGSYMBOL
	_TraceAddRef();
#endif
}

VK_INLINE
void 
vkSmartPtrBase::_Release()
{
#ifdef VK_SUPPORT_DEBUGSYMBOL		
	_TraceRelease();
#endif

	if (m_Ref->count == vkSmartPtrObject::kNullLinkRefCount) // we do not decrement the NullRef Ptr
		return;

	if (!vkAtomicDecrement32(m_Ref->count)) { // one reference down !
		_DeleteObject();
	}
}

VK_INLINE
void
vkSmartPtrBase::_Set(const vkSmartPtrObject* iP)
{
	if (iP) {
		// add a reference 
		m_Ref = iP->m_Link;
		_AddRef();
	} else {
		m_Ref = &vkSmartPtrObject::s_NullLink;
	}
}
	
VK_INLINE bool 
vkSmartPtrBase::HasSameLink(const vkSmartPtrBase& iOther) 
{
	return (m_Ref == iOther.m_Ref);
}

//////////////////////////////////////////////////////////////////////////
// template specializations
//////////////////////////////////////////////////////////////////////////

template <class T>
void vkSwap(vkSmartPtr<T>& iOp1, vkSmartPtr<T>& iOp2) 
{
	iOp1.Swap(iOp2);
}

template <typename T>
struct vkHashFunction<vkSmartPtr<T> >
{
	uint32 operator()(const vkSmartPtr<T>& iP) const 
	{
		return VK_HASH_32(VK_POINTER_TO_PTRDIFF(iP._GetLink())) >> 3; 
	}
};

template <> struct vkIsPod<vkSmartPtrObject::Link> {enum {result = 1};};


