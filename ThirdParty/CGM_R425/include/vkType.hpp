
#if !defined(vkType_hpp)
#define vkType_hpp

VK_INLINE uint32
vkType::GetFlags() const {
	return flags;
}

VK_INLINE void	
vkType::AddFlags(uint32 iFlags) {
	flags |= iFlags;
}

VK_INLINE void
vkType::RemoveFlags(uint32 iFlags) {
	flags &= ~iFlags;
}

VK_INLINE const vkString&
vkType::GetName() const {
	return m_ResourceID;
}

VK_INLINE bool	
vkType::IsPod() const {
	return (flags & fPlaindOldData) ? true : false;
}

VK_INLINE bool
vkType::IsComplete() const {
	return (flags & fComplete) != 0;
}

VK_INLINE bool
vkType::ContainVirtuals() const {
	return (flags & fContainVirtuals) ? true : false;
}

VK_INLINE bool 
vkType::IsConst() const {
	return (qualifier & fConst) ? true : false;
}

VK_INLINE bool	
vkType::IsRef() const {
	return ((qualifier & fOptionsMask) >= fReference) && ((qualifier & fOptionsMask) <= fSmartPtr);
}

VK_INLINE bool
vkType::IsPointerOnly() const {
	return ((qualifier & fOptionsMask) == fPointer);
}

VK_INLINE bool
vkType::IsReferenceOnly() const {
	return ((qualifier & fOptionsMask) == fReference);
}

VK_INLINE bool
vkType::IsRefPtrOnly() const {
	return ((qualifier & fOptionsMask) == fRefPtr);
}

VK_INLINE bool
vkType::IsSmartPtrOnly() const {
	return ((qualifier & fOptionsMask) == fSmartPtr);
}


VK_INLINE vkType::FQualifier
vkType::GetQualifier() const {
	return (FQualifier)qualifier;
}

VK_INLINE bool
vkType::IsAbstract() const {
	return (flags & fIsAbstract) != 0;
}

VK_INLINE bool  
vkType::IsModifiable() const {
	return (flags & fIsModifiable) != 0;
}

VK_INLINE bool
vkType::IsArrayTemplate() const {
	return (GetTemplateKind() == eArray);
}

VK_INLINE bool
vkType::IsHashTemplate() const {
	return (GetTemplateKind() == eHash);
}

VK_INLINE bool  
vkType::IsSame(const vkType* iType) const {
	return IsSameContent(iType);
}

VK_INLINE bool	
vkType::IsFromScriptLanguage() const {
	return (flags & fSLType) != 0;
}

VK_INLINE bool	
vkType::IsNamespace() const {
	return (flags & fIsNamespace) != 0;
}

VK_INLINE bool	
vkType::IsAtomicSerialization() const {
	return (flags & fAtomicSerialization) != 0;
}


VK_INLINE vkType*
vkType::GetWeakPointerType(const vkString& iUsageName) const {
	return GetQualifiedType(fPointer,iUsageName);
}

VK_INLINE vkType*
vkType::GetReferenceType(const vkString& iUsageName) const {
	return GetQualifiedType(fReference,iUsageName);
}

VK_INLINE vkType*
vkType::GetRefPtrType(const vkString& iUsageName) const {
	return GetQualifiedType(fRefPtr,iUsageName);
}

VK_INLINE vkType*
vkType::GetConstRefType(const vkString& iUsageName) const {
	return GetQualifiedType(FQualifier(fConst|fReference),iUsageName);
}

VK_INLINE vkType*
vkType::GetDynArrayType(const vkString& iUsageName) const {
	return GetQualifiedType(fvkArray,iUsageName);
}

VK_INLINE vkType*
vkType::GetStaticArrayType(const uint32 iDimension,const vkString& iUsageName) const {
	return GetQualifiedType(fStaticArray,iUsageName, iDimension);
}

VK_INLINE vkType*
vkType::GetAutoPtrType(const vkString& iUsageName) const {
	return GetQualifiedType(fAutoPtr,iUsageName);
}

VK_INLINE vkType*
vkType::GetConstType(const vkString& iUsageName) const {
	return GetQualifiedType(fConst,iUsageName);
}

VK_INLINE bool 
vkType::_BecomesIncomplete() {
	flags &= ~vkType::fComplete;
	if (!(flags  & vkType::fToBeCompleted)) {
		flags  |= vkType::fToBeCompleted;
		return true;
	}
	return false;
}

/**
Returns true if this is kind of the other type.
*/
VK_INLINE bool 
vkType::IsDerivedFrom(const vkCtxTypePtr& iOtherType) const
{
	return IsDerivedFrom(iOtherType[GetCtx()]);
}

VK_INLINE uint32 
vkType::GetAccessFlags() const
{
	return accessFlags;
}

VK_INLINE void 
vkType::SetAccessFlags(uint32 iFlags)
{
	accessFlags = iFlags;
}

#endif



