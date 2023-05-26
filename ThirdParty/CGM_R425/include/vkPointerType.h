/**
@file

@COPYRIGHT

@author Romain Sididris
*/
#if !defined(__vkPointerType_h)
#define __vkPointerType_h

#include "vkQualifType.h"

namespace VKernel
{
class vkXMLReader;

class vkPointerType;
typedef vkSmartPtr<vkPointerType> vkPointerTypePtr;

/**
Summary: vkPointerType class. 
Description: Represents a pointer or reference type (Type* , or Type&).
See Also: vkQualifiedType
*/
class VKKERNEL_API vkPointerType : public vkQualifType
{
public :
	VK_DECLARE_RTTI(vkPointerType, vkQualifType);

	vkPointerType(vkCtx iCtxHandle, const vkString& iName, FQualifier iQualifier);

	virtual const vkType* GetDeRefType() const;

	virtual int32 GetSize() const;

	// Abstract these methods to force them to be implemented
	virtual vkString  GetCompleteName() const = 0;
	virtual void Construct(void* iParamBuffer) const = 0;
	virtual void Destruct(void* iParamBuffer) const = 0;
	virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const = 0;
	virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const = 0;
	virtual void* GetUnqualifiedInstance(const void* iInstance) const = 0;
	virtual const vkType*	GetInstanceType(const void* iInstance) const = 0;

	virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const;
	virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const;

	// Field API
	virtual uint32 GetFieldCount(void* iParamBuffer = 0) const;
	virtual const vkType* GetFieldType(uint32 iFieldIndex,void* iParamBuffer = 0) const;
	virtual void GetFieldName(uint32 iFieldIndex,void* iParamBuffer,vkString& oName) const;
	virtual bool GetFieldDescription(uint32 iFieldIndex,void* iParamBuffer ,vkString& oDescription) const;
	virtual bool IsResourceAdapterOwningObject(const void* /*iObject*/) const
	{
		return false;
	}

	virtual uint32	  GetMemoryOccupation(bool iSelfSize = true, bool iDependencies = false) const;
	
	virtual uint32 Hash(const void* iParamBuffer) const;

protected :

	virtual const vkType* _Clone(bool iCopy) const = 0;
	
	void				_GetPointedObject(const void* iBuffer, void*& oObject, const vkType*& oObjectType) const;
};

} // NameSpace VKernel

#endif  // __vkPointerType_h



