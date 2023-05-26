/**
@file

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkConcreteType_h)
#define __vkConcreteType_h

#if !defined(__vkType_h)
	#include "vkType.h"
#endif 
#if !defined(__vkAsset_h)
	#include "vkAsset.h"
#endif 

namespace VKernel
{

class vkModifiableTypeData;

/**
Summary: vkType class. 
Remarks: This class defines a basic type, registered to the vkTypeManager.

See Also: vkClass
*/
class VKKERNEL_API vkConcreteType : public vkType
{
	VK_DECLARE_RTTI(vkConcreteType, vkType);
public:

	// Ctors
	vkConcreteType(vkCtx iCtxHandle);
	vkConcreteType(const vkConcreteType& iSrc);
	vkConcreteType(vkCtx iCtxHandle, const vkString& iName);

	virtual ~vkConcreteType();


	uint32					size;					// size taken to store a data of this type
	vkTypePtr				ownerNamespace;
	
	union {
		void*				defaultValueBuffer;		// default value if needed
		vkString*			defaultValueString;
	};
	uint32					crc;
	vkModifiableTypeData*	modifiableTypeData;
	
	virtual bool IsNotReady() const {
		return (flags & vkType::fNotReady) != 0;
	}

	virtual bool _CheckIfComplete() { return true; }
	virtual bool _CompleteType();

	virtual vkClassType*  GetOwnerNamespace() const;

	virtual int32 GetSize() const;
	virtual void Construct(void* iParamBuffer) const;
	virtual void Destruct(void* iParamBuffer) const;
	virtual void ResetToDefault(void* iParamBuffer) const;

	virtual void SetOwnerNamespace(vkClassType* iOwnerNamespace);

	bool  HasDefaultValueString() const
	{
		return (flags & fHasDefaultValueString) != 0;
	}

	bool  NeedDefaultValueBuffer() const
	{
		return (flags & fNeedDefaultValueBuffer) != 0;
	}

	bool  HasDefaultValueBuffer() const
	{
		return defaultValueBuffer && !HasDefaultValueString();
	}

	bool  HasDefaultValue() const
	{
		return defaultValueBuffer != 0;
	}

	void* GetDefaultValueBuffer() const
	{
		if (HasDefaultValueBuffer())
			return defaultValueBuffer;
		return 0;
	}

	void	_CreateDefaultValueBuffer(const void* iSrcBuffer = 0);
	void	_StoreDefaultValueBuffer(const void* iBuffer);
	void	_DeleteDefaultValueBuffer(bool iBufferIsShared = false);

	virtual void		SwitchToModifiableType();
	virtual vkModifiableTypeData* GetModifiableData() const {
		return modifiableTypeData;
	}	

	virtual void	_PrepareDeletion_1_DeleteAllocatedBuffers();
	virtual void	_PrepareDeletion_2_RemoveReferences();
	virtual void	_UncompleteType();
	
	virtual uint32	GetMemoryOccupation(bool iSelfSize = true, bool iDependencies = false) const;
};

typedef vkSmartPtr<vkConcreteType> vkConcreteTypePtr;

/**
Summary: This class is only here to have a common RTTI between float and integers 

*/
struct VKKERNEL_API vkBaseType : public vkConcreteType
{
	VK_DECLARE_RTTI(vkBaseType, vkConcreteType);

	vkBaseType(vkCtx iCtxHandle);
	vkBaseType(vkCtx iCtxHandle, const vkString& iName);
	
	virtual uint32 Hash(const void* iParamBuffer) const;
};


struct VKKERNEL_API vkUnknownType : public vkType
{
	VK_DECLARE_RTTI(vkUnknownType, vkType);
	vkUnknownType(vkCtx iCtxHandle, const vkString& iName);
	// name of the type

	virtual int32 GetSize() const;

	virtual void Construct(void* iParamBuffer) const;
	virtual void Destruct(void* iParamBuffer) const;
	virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const;
	virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const;
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual vkClassType*  GetOwnerNamespace() const;
	virtual bool _CheckIfComplete() { return true; }
	virtual bool _CompleteType()  { flags |= vkType::fComplete; return true; }
	virtual const vkType* _Clone(bool iCopy) const;
};


struct VKKERNEL_API vkVoidType : public vkUnknownType
{
	VK_DECLARE_RTTI(vkVoidType, vkUnknownType);
	vkVoidType(vkCtx iCtxHandle);
	virtual const vkType* _Clone(bool iCopy) const;
};


} // NameSpace VKernel

#endif // __vkConcreteType_h



