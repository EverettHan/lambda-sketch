
VK_INLINE 
vkRefPtrObject::vkRefPtrObject(vkCtx iCtx, bool iIsValid)
: ParentClass(iCtx),m_Refcount(0)
{
	if (!iIsValid)
		m_Refcount = (uint32)fIsInvalid;
}

VK_INLINE
vkRefPtrObject::vkRefPtrObject(const vkRefPtrObject &iSrc):vkObject(iSrc)
{
	// copy const must NOT copy XRefs/pinfo!!
	m_Refcount = 0;
}

VK_INLINE vkRefPtrObject&
vkRefPtrObject::operator=(const vkRefPtrObject &) 
{
	// operator= must NOT copy XRefs/pinfo!!	
	return *this;
}

////////////////////////////////////////////////////////////////////////////////

VK_INLINE void	
vkRefPtrObject::AddRef() const
{
	vkAtomicIncrement32((int32&)m_Refcount);
	//++m_Refcount;
}


VK_INLINE void
vkRefPtrObject::Release() const
{
	int32 result = vkAtomicDecrement32((int32&)m_Refcount);
	if ((result&fFlagsMask) == 0 )
	{ // time to destroy the object
		((vkRefPtrObject*)this)->Destroy();

		if((m_Refcount & fIsInvalid) == 0)
		{
			return;
		}
		if(m_Refcount & fDeleteCountMask)
		{
			_WaitForDeletion();
		}
		delete this;
	}
} 


//////////////////////////////////////////////////////////////////////////

VK_INLINE bool
vkRefPtrObject::IsValid() const 
{
	return (m_Refcount & fIsInvalid) == 0;	
}



VK_INLINE bool
vkRefPtrObject::IsReferenced() const
{
	// Explicit call to this implementation
	// to speed up the call.
	return vkRefPtrObject::GetReferenceCount() >= 1;
}

////////////////////////////////////////////////////////////////////////////////

VK_INLINE vkRefPtrObject::~vkRefPtrObject()
{	
	VKASSERT(m_Refcount == fIsInvalid);	
}

VK_INLINE void
vkRefPtrObject::SetReferenceCount(uint32 iReferenceCount)
{
	vkAtomicCompareExchange32((int32&)m_Refcount,(m_Refcount&0xFF000000)|iReferenceCount,m_Refcount);
}



