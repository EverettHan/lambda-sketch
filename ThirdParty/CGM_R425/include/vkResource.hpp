/**
@file

This file implements vkResource's inlined methods.

@COPYRIGHT

@author Thomas Bucher
*/

//////////////////////////////////////////////////////////////////////////
// vkResource
//////////////////////////////////////////////////////////////////////////

#if !defined(__vkResource_hpp)
#define __vkResource_hpp

#if !defined(__vkKernelLib_h)
#include "vkKernelLib.h"
#endif

#if !defined(__vkResource_h)
#include "vkResource.h"
#endif

namespace VKernel
{
VK_INLINE bool
vkResource::IsRegistered() const
{
	// fWasRegistered = fIsRegistered | fIsObsolete
	return (m_RscFlags & fWasRegistered) == fIsRegistered;
}

VK_INLINE bool
vkResource::WasRegistered() const
{
	// fWasRegistered = fIsRegistered | fIsObsolete
	return (m_RscFlags & fWasRegistered) == fWasRegistered;
}

VK_INLINE const vkString&
vkResource::GetPrefixID()
{
	return s_PrefixIDString;
}

VK_INLINE vkResourceCategory
vkResource::GetResourceCategory() const
{
	return m_ResourceCategory;
}


VK_INLINE bool
vkResource::IsReady() const
{
	return (m_RscFlags & vkResource::fIsReady) != 0;
}


VK_INLINE bool
vkResource::IsResultOfAConfiguration() const
{
	return (m_RscFlags & fIsResultOfConfig) == fIsResultOfConfig;
}

VK_INLINE bool
vkResource::IsInCache() const
{
	return (m_RscFlags & vkResource::fIsInCache) != 0;
}

VK_INLINE bool
vkResource::IsObsolete() const
{
	return (m_RscFlags & fIsObsolete) != 0;
}

VK_INLINE bool
vkResource::IsUnresolved() const
{
	return (m_RscFlags & fIsUnresolved) != 0;
}

VK_INLINE bool
vkResource::IsConfigured() const
{
	return (m_RscFlags & fIsConfigured) != 0;
}

} //namespace VKernel

#endif //__vkResource_hpp
