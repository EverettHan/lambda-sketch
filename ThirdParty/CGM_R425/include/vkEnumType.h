/**
@file

This file defines all the
class related to enumeration types (enum , flags ).

@COPYRIGHT

@author Romain Sididris
*/
#if !defined(__vkEnumType_h)
#define __vkEnumType_h

#include "vkKernelTypes.h"
#include "vkIntegerType.h"

namespace VKernel
{

class vkString;

class vkEnumType;
typedef vkSmartPtr<vkEnumType> vkEnumTypePtr;

class vkFlagType;
typedef vkSmartPtr<vkFlagType> vkFlagTypePtr;

/**
Summary: vkEnumType class. 
Description: defines an enumeration type.
An enumeration uses the exact same storage than an int32
and the same functions at the exception
of the serialization functions
See Also: vkFlagType
*/
class VKKERNEL_API vkEnumType : public vkTemplateIntegerType<int32>
{
	friend void* EnumTypeNewFct(vkCtx iHandle);

public:
	VK_DECLARE_RTTI_EX(vkEnumType, vkIntegerType, NOCREATE, TYPE, NOCOMP);

	vkEnumType(vkCtx iCtxHandle, const vkString& iName):vkTemplateIntegerType<int32>(iCtxHandle, iName) {}
	virtual void _PrepareDeletion_2_RemoveReferences();
	virtual void _UncompleteType();
	struct EnumEntry {
		int32			value;
		vkString		name;
		EnumEntry() {}
		EnumEntry(int32 iVal,const vkString& iStr):value(iVal),name(iStr) {}
	};

	// array of enums values
	VKernel::vkArray<EnumEntry>	values;


	
	virtual const vkType* GetStorageType() const ;
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual const vkType* _Clone(bool iCopy) const;
	virtual void ComputeTypeDeclaration(vkString& oString) const;

	uint32	GetValueCount(void) const;

	using vkType::GetName;
	bool	GetName(int32 iValue, vkString& oValue) const;
	bool	GetValue(const vkString& iName, int32& oValue) const;
	void	GetValidName(vkString& ioName) const;

	virtual uint32	  GetMemoryOccupation(bool iSelfSize = true, bool iDependencies = false) const;


	void UpdateEnumInfos();

};

/**
Summary: vkFlagType class. 
A Flag is very close to an enumeration type. The only difference is again
in the represenation:
enums are supposed to looks like this
enum {
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thursday  =4,
	etc..
}
where a single value can be chose
while flag types are expected to look :
flag {
	alignHLeft	 = 0x01,
	alignHRight	 = 0x02,
	alignVTop	 = 0x04,
	alignVBottom = 0x08,
	bold		 = 0x10,
	italic		 = 0x20,
}
so a value of type flag can be a combination of the above values.

See Also: vkEnumType
*/
class VKKERNEL_API vkFlagType : public vkEnumType
{
public:
	VK_DECLARE_RTTI_EX(vkFlagType, vkEnumType, NOCREATE, TYPE, NOCOMP);

	vkFlagType(vkCtx iCtxHandle, const vkString& iName):vkEnumType(iCtxHandle, iName) {}
	virtual const vkType* GetStorageType() const ;
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual const vkType* _Clone(bool iCopy) const;
	virtual void ComputeTypeDeclaration(vkString& oString) const;
};

} // namespace VKernel

#endif // __vkEnumType_h



