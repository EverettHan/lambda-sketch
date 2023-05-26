#include "vkKernelLib.h"
#include "vkKernelDefines.h"
#include "vkTypeManager.h"

namespace VKernel
{

////////////////////////////////////////////////////////////////////////////////
//
// vkTypeManager
//
////////////////////////////////////////////////////////////////////////////////


VK_INLINE const vkType*
vkTypeManager::GetNullType() const
{
	return m_NullType;
}

VK_INLINE const vkType*
vkTypeManager::GetErrorType() const
{
	return m_ErrorType;
}

VK_INLINE const vkType*
vkTypeManager::GetCtxType() const
{
	return m_CtxType;
}

VK_INLINE const vkType*
vkTypeManager::GetAttributeType() const
{
	return m_AttributeType;
}

VK_INLINE const vkType*
vkTypeManager::GetAttributesSetType() const
{
	return m_AttributesSetType;
}

VK_INLINE const vkType*
vkTypeManager::GetUnknownType()
{
	return m_UnknownType;
}

VK_INLINE void
vkTypeManager::DeclareCastFunction(const vkString& iSrcTypeName,const vkString& iDstTypeName,vkCopyFunction iCastFct)
{
	DeclareCastFunction(GetType(iSrcTypeName),GetType(iDstTypeName),iCastFct);
}

VK_INLINE void
vkTypeManager::DeclareInstanceResourceCategory(const vkCtxObject<vkResourceCategory>& iResourceCategory)
{
	DeclareInstanceResourceCategory(iResourceCategory[GetCtx()]);
}


////////////////////////////////////////////////////////////////////////////////
//
// vkTypeManager::TypePair
//
////////////////////////////////////////////////////////////////////////////////

VK_INLINE vkTypeManager::TypePair::TypePair(const vkType* iFirst, const vkType* iSecond)
:	first(iFirst), second(iSecond)
{
}

VK_INLINE bool
vkTypeManager::TypePair::operator==(const TypePair& iOp) const
{
	return ((first == iOp.first) && (second == iOp.second));
}

VK_INLINE vkTypeManager::TypePair::operator uint32() const
{
	return (uint32)((ptrdiff)first ^ (ptrdiff)second);
}

////////////////////////////////////////////////////////////////////////////////
//
// vkTypeManager::TypePair
//
////////////////////////////////////////////////////////////////////////////////

VK_INLINE vkTypeManager::TypeAndString::TypeAndString(vkType* iFirst, const vkString& iSecond)
:	first(iFirst), second(iSecond)
{
}

VK_INLINE vkTypeManager::TypeAndString::TypeAndString(const TypeAndString& iSrc):first(iSrc.first), second(iSrc.second)
{
}

VK_INLINE vkTypeManager::TypeAndString&
vkTypeManager::TypeAndString::operator=(const TypeAndString& iSrc)
{
	first = iSrc.first;
	second =iSrc.second;
	return *this;
}

// Comparison operator
VK_INLINE bool
vkTypeManager::TypeAndString::operator==(const TypeAndString& iOp) const
{
	return ((first == iOp.first) && (second == iOp.second));
}

// Hashing function
VK_INLINE vkTypeManager::TypeAndString::operator uint32() const
{
	return (uint32)((ptrdiff)first ^ second.Hash());
}

////////////////////////////////////////////////////////////////////////////////
//
// vkTypeManager::TypePair
//
////////////////////////////////////////////////////////////////////////////////


VK_INLINE void*
vkTypeManager::_GetArgumentDefaultValueBuffer(int16 iIndex)
{
	return m_ArgumentDefaultValues[iIndex];
}

VK_INLINE void
vkTypeManager::_TypeBecomesIncomplete(vkType* iType)
{
	if (iType->_BecomesIncomplete()) {
		m_IncompleteTypes.PushBack(iType);
	}
}

} // namespace VKernel
