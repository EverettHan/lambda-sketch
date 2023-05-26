#if defined(VK_MULTIPLE_CONTEXTS)

/************************************************************************/
/* Multiple context implementation                                      */
/************************************************************************/
template <class T, class TInit>
VK_INLINE vkCtxObject<T, TInit>::vkCtxObject(vkCtxObjectBase*& iCtxObjectList)
{
	_Register(iCtxObjectList);
}

template <class T, class TInit>
inline uint32
vkCtxObject<T, TInit>::GetObjectSize() const
{
	return sizeof(T);
}

template <class T, class TInit>
inline uint8*
vkCtxObject<T, TInit>::Construct(uint8* iDst, uint32 iCount)
{
	T* object = (T*) iDst;
	for (uint32 i=0; i < iCount; ++i)
	{
		TInit::Construct(object++);
	}

	return (uint8*) object;
}

template <class T, class TInit>
inline void
vkCtxObject<T, TInit>::Destruct(uint32 iCount)
{
	VKASSERT(m_IndexedData != 0);
	T* obj = (T*) m_IndexedData;
	for (uint32 i=0; i < iCount; ++i)
	{
		TInit::Destruct(obj++);
	}

	m_IndexedData = 0;
}

template <class T, class TInit>
inline void
vkCtxObject<T, TInit>::DestructOnlyForContext(vkCtx iCtx)
{
	VKASSERT(m_IndexedData != 0);
//	VKASSERT(iCtx < vkContext::GetContextCount());
	T* obj = &((T*) m_IndexedData)[iCtx];
	TInit::Destruct(obj);
}

template <class T, class TInit>
VK_INLINE const T&
vkCtxObject<T, TInit>::operator[](vkCtx iCtxHandle) const
{
	VKASSERT(iCtxHandle >= 0);
//	VKASSERT(iCtxHandle < (int32)vkContext::GetContextCount());
	VKASSERT(m_IndexedData != 0);
	return ((T*) m_IndexedData)[iCtxHandle];
}

template <class T, class TInit>
VK_INLINE T&
vkCtxObject<T, TInit>::operator[](vkCtx iCtxHandle) 
{
	VKASSERT(iCtxHandle >= 0);
//	VKASSERT(iCtxHandle < (int32)vkContext::GetContextCount());
	VKASSERT(m_IndexedData != 0);
	return ((T*) m_IndexedData)[iCtxHandle];
}

#else

/************************************************************************/
/* Single context implementation                                      */
/************************************************************************/
template <class T, class TInit>
VK_INLINE vkCtxObject<T, TInit>::vkCtxObject()
{
	// Perform post init
	TInit::PostConstruct(m_Instance);
}

template <class T, class TInit>
VK_INLINE bool
vkCtxObject<T, TInit>::IsInitialized() const
{
	return true;
}

template <class T, class TInit>
VK_INLINE const T&
vkCtxObject<T, TInit>::operator[](vkCtx iCtxHandle) const
{
	VKASSERT(iCtxHandle == kMainCtx);
	return m_Instance;
}

template <class T, class TInit>
VK_INLINE T&
vkCtxObject<T, TInit>::operator[] (vkCtx iCtxHandle)
{
	VKASSERT(iCtxHandle == kMainCtx);
	return m_Instance;
}

#endif



