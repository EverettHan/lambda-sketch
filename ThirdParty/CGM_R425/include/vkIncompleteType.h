/**
@file

This file defines all the
class are derived from vkType and implemented qualified types
(pointers , arrays, etc..).

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkIncompleteType_h)
#define __vkIncompleteType_h

#if !defined(__vkClassType_h)
	#include "vkClassType.h"
#endif

namespace VKernel
{

// forward declaration
struct vkNamespace;

class vkIncompleteType;
typedef vkSmartPtr<vkIncompleteType> vkIncompleteTypePtr;

/**
Summary: vkIncompleteType class. 

An uncomplete type is a type that has been declared before 
before being defined (forward declaration) 

If a struct declares a member of an unknown typename, an uncomplete 
type is created with the typename and will be replaced when the real type
is declared

See Also: vkType
*/
class VKKERNEL_API vkIncompleteType : public vkClassType
{
public:
	VK_DECLARE_RTTI(vkIncompleteType, vkClassType);
	vkIncompleteType(vkCtx iCtxHandle, const vkString& iName);

	virtual bool _CheckIfComplete() { return false; }
	virtual bool _CompleteType()  { return false; }

	virtual void Construct(void* /*iParamBuffer*/) const { 	VKASSERT(0); }
	virtual void Destruct(void* /*iParamBuffer*/)  const { 	VKASSERT(0); }
	virtual void CopyConstruct(void* /*iParamBuffer*/,const void* /*iSrcBuffer*/, const vkType* /*iSrcType*/ = 0) const { 	VKASSERT(0); }
	virtual void Copy(void* /*iParamBuffer*/, const void* /*iSrcBuffer*/, const vkType* /*iSrcType*/ = 0) const { 	VKASSERT(0); }
	virtual int32 Compare(const void* /*iOpBuffer1*/, const void* /*iOpBuffer2*/) const  { 	VKASSERT(0); return 0;}
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	
	virtual const vkType* _Clone(bool iCopy) const;
};

} // NameSpace VKernel

#endif  // __vkIncompleteType_h



