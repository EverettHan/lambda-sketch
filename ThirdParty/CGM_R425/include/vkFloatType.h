/**
@file

This file defines all the
class related to float types (float, double ).

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkFloatType_h)
#define __vkFloatType_h

#if !defined(__vkConcreteType_h)
	#include "vkConcreteType.h"
#endif


namespace VKernel 
{

/// @cond

struct VKKERNEL_API vkFloatType : public vkBaseType
{
	VK_DECLARE_RTTI(vkFloatType, vkBaseType);
	vkFloatType(vkCtx iCtxHandle);

	virtual int32 GetSize() const;

	virtual void Construct(void* iParamBuffer) const;
	virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const;
	virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const;
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual const vkType* _Clone(bool iCopy) const;
	virtual bool Op(EOperation iOperation, const void* iResultBuffer, const void* iParam1Buffer, const void* iParam2Buffer, float iAlpha = 0) const;
	virtual uint32 Hash(const void* iOpBuffer1) const;
};


struct VKKERNEL_API vkDoubleType : public vkBaseType
{
	VK_DECLARE_RTTI(vkDoubleType, vkBaseType);
	vkDoubleType(vkCtx iCtxHandle);

	virtual int32 GetSize() const;

	virtual void Construct(void* iParamBuffer) const;
	virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const;
	virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const;
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual const vkType* _Clone(bool iCopy) const;
	virtual bool Op(EOperation iOperation, const void* iResultBuffer, const void* iParam1Buffer, const void* iParam2Buffer, float iAlpha = 0) const;
	virtual uint32 Hash(const void* iOpBuffer1) const;

};

/// @endcond

} // NameSpace VKernel

#endif // __vkFloatType_h



