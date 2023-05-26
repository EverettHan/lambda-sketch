/**
@file

@COPYRIGHT

This file implements a reference counted pointer class.

@author Aymeric Bard
*/

//////////////////////////////////////////////////////////////////////////
// vkRefPtr implementation
//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE vkRefPtr<T>::vkRefPtr():m_Pointee(0)	
{}

/**
Constructor.
*/
template <class T>
VK_INLINE vkRefPtr<T>::vkRefPtr(T* iPointer):m_Pointee(iPointer)
{
	if (iPointer)
		iPointer->AddRef();
}

template <class T>
VK_INLINE vkRefPtr<T>::vkRefPtr(const vkRefPtr<T>& iSrc):m_Pointee(iSrc.m_Pointee) 
{
	if (m_Pointee)
		m_Pointee->AddRef();
}

//////////////////////////////////////////////////////////////////////////
template <class T>
VK_INLINE vkRefPtr<T>& 
vkRefPtr<T>::operator=(const vkRefPtr<T>& iSrc) 
{
	if(this == &iSrc) return *this;
	return operator=(iSrc.m_Pointee);
}

template <class T>
VK_INLINE vkRefPtr<T>& 
vkRefPtr<T>::operator=(T* iPointer) 
{
	if (iPointer)
		iPointer->AddRef();
		
	if (m_Pointee)
		m_Pointee->Release();

	m_Pointee = iPointer;
	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE vkRefPtr<T>::~vkRefPtr() 
{
	if (m_Pointee)
		m_Pointee->Release();
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE void	
vkRefPtr<T>::Swap(vkRefPtr<T>& iCopy) 
{
	vkSwap(m_Pointee, iCopy.m_Pointee);
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE T* 
vkRefPtr<T>::operator->() const 
{
	return m_Pointee;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE T& 
vkRefPtr<T>::operator*() const 
{
	return *m_Pointee;
}

//////////////////////////////////////////////////////////////////////////

/*template <class T>
T** 
vkRefPtr<T>::operator&() const 
{
	return &m_Pointee;
}*/

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE vkRefPtr<T>::operator T*() const 
{
	return m_Pointee;
}

template <class T>
VK_INLINE T* 
vkRefPtr<T>::Ptr() const
{
	return m_Pointee;
}

template <class T>
VK_INLINE void 
vkRefPtr<T>::Discard()
{
	m_Pointee = 0;
}

template <class T>
VK_INLINE bool 
vkRefPtr<T>::Validate()
{
	if (!m_Pointee) {
		return false;
	}

	if (!m_Pointee->IsValid()) {
		m_Pointee = 0;
		return false;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////
// template specializations
//////////////////////////////////////////////////////////////////////////

template <class T>
void vkSwap(vkRefPtr<T>& iOp1, vkRefPtr<T>& iOp2) 
{
	iOp1.Swap(iOp2);
}

template <typename T>
struct vkHashFunction<vkRefPtr<T> >
{
	uint32 operator()(const vkRefPtr<T>& iP) const 
	{
		return VK_HASH_32(VK_POINTER_TO_PTRDIFF(iP.Ptr())) / sizeof(T); 
	}
};


