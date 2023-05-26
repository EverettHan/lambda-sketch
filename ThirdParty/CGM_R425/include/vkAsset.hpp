/**
@file

@COPYRIGHT

This file implements inlined vkAsset class methods.

@author Thomas Bucher
*/

// Inlined Implementations

VK_INLINE bool
vkAsset::IsBeingLoaded() const
{
	return (m_Flags & fIsBeingLoaded) != 0;
}

VK_INLINE bool
vkAsset::IsBeingDestroyed() const
{
	return (m_Flags & fIsBeingDestroyed) != 0;
}

VK_INLINE bool
vkAsset::IsBeingReloaded() const
{
	return (m_Flags & fIsBeingReloaded) != 0;
}

VK_INLINE bool
vkAsset::IsLoaded() const
{
	return (m_Flags & fIsLoaded) != 0;
}

VK_INLINE bool
vkAsset::IsProcessed() const
{
	return (m_Flags & fIsProcessed) != 0;
}

VK_INLINE bool
vkAsset::IsDirty() const
{
	return (m_Flags & fIsDirty) != 0;
}

VK_INLINE uint32
vkAsset::GetResourceCount() const
{
	return m_Resources.Size();
}

VK_INLINE vkResource*
vkAsset::GetResource(uint32 iIndex) const
{
	return m_Resources[iIndex];
}

VK_INLINE const vkArray<vkResourcePtr>&
vkAsset::GetResources() const
{
	return m_Resources;
}


template <class TResourceType>
void
vkAsset::GetResourcesByType(vkArray<vkSmartPtr<TResourceType> >& oResources, bool iGetOnlyRelevantResources) const
{
	vkCtx ctx = GetCtx();
	GetResourcesByType(TResourceType::s_Type[ctx], (vkArray<vkResourcePtr>&) oResources, iGetOnlyRelevantResources);
}

template <class T>
T*
vkAsset::GetResource(const vkString& iResourceID, vkResourceCategory iCategory) const
{
	return (T*) GetResource(iResourceID, iCategory, T::s_Type[GetCtx()]);
}


template <class T>
T*
vkAsset::GetResource() const
{
	T* ret	= 0;
	const uint32 resCount = m_Resources.Size();
	for (uint32 i = 0; i < resCount; ++i) {
		vkResource* resource = GetResource(i);
		if (ret = T::DynamicCast(resource)) {
			return ret;
		}
	}
	return (T*)0;
}

VK_INLINE vkEventsChannel&
vkAsset::GetEventsChannel()
{
	return m_EventsChannel;
}

VK_INLINE bool
vkAsset::IsSystem() const
{
	return (m_Flags & fIsSystem) == fIsSystem;
}

VK_INLINE bool
vkAsset::IsImplicit()
{
	return false;
}

VK_INLINE bool
vkAsset::IsUnresolved() const
{
	return (m_Flags & fIsUnresolved) != 0;
}

VK_INLINE bool
vkAsset::CanRegisterTypes() const
{
	return (m_Flags & fCanRegisterTypes) != 0;
}

VK_INLINE void 
vkAsset::_SetCanHaveCyclicDeps(bool iValue)
{
	m_Flags = vkChangeMask(iValue,m_Flags,fCanHaveCyclicDeps);
}
VK_INLINE bool 
vkAsset::_CanHaveCyclicDeps()
{
	return (m_Flags & fCanHaveCyclicDeps) != 0;
}



