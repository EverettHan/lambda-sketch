/**
@file

@COPYRIGHT

Description: 

@author Aymeric Bard
Creation date: 14/2/2005
*/

#if !defined(__vkArgument_h)
#define __vkArgument_h

#if !defined(__vkKernelDefines_h)
	#include "vkKernelDefines.h"
#endif 

#if !defined(__vkType_h)
	#include "vkType.h"
#endif 

namespace VKernel
{

/**
Summary: vkArgument class. 
Remarks: defines an argument as used in a function.
*/
struct VKKERNEL_API vkArgument
{
	enum {
		eInputArgument				= 1<<0,
		eOutputArgument				= 1<<1,
		e8BitPod					= 1<<2,	// Argument is a 8 bit integer than need endianess check on some platform
		e16BitPod					= 1<<3,	// Argument is a 16 bit integer than need endianess check on some platform
		eCopyPassedByVal			= 1<<4,
		eDestructorCalledByCaller	= 1<<5,
		e32BitPod					= 1<<6,	// Argument is a 32 bit integer than need endianess check on some platform
		e64BitPod					= 1<<7,	// Argument is a 64 bit integer than need endianess check on some platform
		eIsPod						= e8BitPod | e16BitPod | e32BitPod | e64BitPod,
	};
	vkArgument():flags(0),defaultValueIndex(0) {}
	VK_INLINE vkArgument(const vkArgument& iArg):type(iArg.type),flags(iArg.flags),defaultValueIndex(iArg.defaultValueIndex){
		name = iArg.name;	
	}

	vkArgument(const vkType* iType):type(iType),flags(0),defaultValueIndex(0) {}

	// Comparison operator
	int operator == (const vkArgument& iOp) const 
	{
		return (type == iOp.type);
	}
	inline bool IsRef() const {
		return type->IsRef();
	}
	inline bool IsPtr() const {
		return type->IsPointerOnly();
	}

	inline uint32 GetSize() const {
		return type->GetSize();
	}
	void* GetDefaultValueBuffer() const;

	vkTypePtr		type;		// type of this member
	uint16			flags;
	uint16			defaultValueIndex;
	vkString	name;

}; // vkArgument
 
typedef VKernel::vkArray<vkArgument> ArgumentsArray;

}; // VKernel

#endif // __vkSignature_h
