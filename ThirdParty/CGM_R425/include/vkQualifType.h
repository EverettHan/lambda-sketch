/**
@file

This file defines all the
class are derived from vkType and implemented qualified types
(pointers , arrays, etc..).

@COPYRIGHT

@author Romain Sididris
*/
#ifndef __vkQualifType_h
#define __vkQualifType_h

#if !defined(__vkType_h)
	#include "vkType.h"
#endif 

namespace VKernel
{

// forward declaration
struct vkNamespace;

class vkQualifType;
typedef vkSmartPtr<vkQualifType> vkQualifTypePtr;

/**
Summary: vkQualifiedType class. 
Remarks:  A qualified type is the base class 
for a special kind of types : types that add a "qualification" to another type.
For example an uint32* is type which is a qualified (pointer) version of the uint32 type.


See Also: vkType
*/
class VKKERNEL_API vkQualifType : public vkType
{
public:
	VK_DECLARE_RTTI(vkQualifType, vkType);

	vkQualifType(vkCtx iCtxHandle);
	vkQualifType(vkCtx iCtxHandle, const vkString& iName, FQualifier iQualifier);

	vkTypePtr	baseType;		// The type being qualified
	
	using ParentClass::GetResourceCategory;
	using ParentClass::GetResourceID;
	
	virtual bool IsDerivedFrom(const vkType* /*iType*/) const {
		return false;
	}
	virtual vkType* GetUnQualifiedType() const  {
		return baseType;
	}
	virtual vkClassType*  GetOwnerNamespace() const {
		return baseType->GetOwnerNamespace();
	}
	virtual vkString  GetCompleteName() const;

	virtual int32 GetSize() const {
		return baseType->GetSize();	
	}

	virtual uint32 GetAlignementSize() const 
	{
		if (qualifier & vkType::fConst) {
			return GetDeConstType()->GetAlignementSize(); 
		}
		return ParentClass::GetAlignementSize();
	}

	virtual void _Destroy();

	virtual const vkType* GetStorageType() const {
		return baseType;
	}

	virtual bool _CheckIfComplete() { return true; }
	virtual bool _CompleteType()  { return true; }


	// For default qualified type (const ,static...) the save functions
	// are the same than the base type...

	virtual void Construct(void* iParamBuffer) const { 	baseType->Construct(iParamBuffer); }
	virtual void Destruct(void* iParamBuffer)  const {	baseType->Destruct(iParamBuffer); }
	virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const { 	baseType->CopyConstruct(iParamBuffer,iSrcBuffer,iSrcType);	}
	virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const { 	baseType->Copy(iParamBuffer,iSrcBuffer,iSrcType); 	}
	virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const { 	return baseType->Equals(iOpBuffer1,iOpBuffer2);	}
	virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const { 	return baseType->Compare(iOpBuffer1,iOpBuffer2);	}
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	
	virtual const vkType* GetInstanceType(const void* iInstance) const;
	virtual vkResourceCategory GetResourceCategory(const void* iInstance) const;
	virtual vkString GetInstanceID(const void* iInstance) const;
	virtual bool GetResourceLocation(const void* iInstance, vkAssetPtr& oResourceAsset, vkString& oResourceID) const;

	virtual const vkType* _Clone(bool iCopy) const;
	virtual void ComputeTypeDeclaration(vkString& oString) const;

	virtual uint32 Hash(const void* iParamBuffer) const;

};

} // NameSpace VKernel

#endif  // __vkQualifType_h



