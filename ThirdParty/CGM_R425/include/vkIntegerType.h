/**
@file

This file defines all the
class related to simple integer types (int , bool , char).

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkIntegerType_h)
#define __vkIntegerType_h

// Kernel Includes

	#include "vkStringLoadArgs.h"

#if !defined(__vkStringLock_h)
	#include "vkStringLock.h"
#endif
#if !defined(__vkConcreteType_h)
	#include "vkConcreteType.h"
#endif


// TODO remove this
#include <cstdio>

namespace VKernel
{

#if defined(VK_COMPILER_MSVC)
	#pragma warning (push)
	#pragma warning (disable:4127)
#endif

struct VKKERNEL_API vkIntegerType : public vkBaseType 
{
	VK_DECLARE_RTTI(vkIntegerType, vkBaseType);
	vkIntegerType(vkCtx iCtxHandle, const vkString& iName):vkBaseType(iCtxHandle, iName) 
	{ 
		flags = fComplete|fPlaindOldData;
	}
	~vkIntegerType();

	uint32 Hash(const void* iOpBuffer1) const;
	
	
	virtual bool IsSigned() = 0;
};

#if defined(VK_COMPILER_MSVC)
#pragma warning(disable:4146)
#endif

/**
Summary: Type definition for a generic integer class
*/
template <class T>
struct VKKERNEL_API vkTemplateIntegerType : public vkIntegerType
{
	vkTemplateIntegerType(vkCtx iCtxHandle, const vkString& iName)
	:vkIntegerType(iCtxHandle, iName) {}

	virtual int32 GetSize() const
	{
		return sizeof(T);
	}

	virtual void Construct(void* iParamBuffer) const
	{
		*(T*)iParamBuffer = 0;
	}

	virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* /*iSrcType*/ = 0) const
	{
		*(T*)iParamBuffer = *(T*)iSrcBuffer;
	}

	virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* /*iSrcType*/ = 0) const
	{
		*(T*)iParamBuffer = *(T*)iSrcBuffer;
	}

	virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const 
	{
		return *(T*)iOpBuffer1 == *(T*)iOpBuffer2;
	}

	virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const 
	{
		if (*(T*)iOpBuffer1 == *(T*)iOpBuffer2)
			return 0;
		if (*(T*)iOpBuffer1 < *(T*)iOpBuffer2)
			return -1;
		return 1;
	}

	virtual bool IsSigned()
	{
		return vkNumericLimits<T>::IsSigned;
	}

	virtual error LoadFromString(vkStringLoadArgs& iArgs) const
	{
		vkString string;
		if (iArgs.HasFlags(vkStringLoadArgs::fInternal)) {
			string.CreateSubString(iArgs.stringStart, iArgs.stringEnd);
		}
		else {
			string = *iArgs.stringStart.GetString();
		}

		if (vkNumericLimits<T>::IsSigned) {
			T a = 0;
			if (VK_FAILED(string.To(a)))
			{
				/*vkString msg;
				msg.Format("Could convert %s in integer", lock.CStr());
				VK_THROW_ERROR_EX(errSyntaxError, msg);
				*/
				return errSyntaxError;
			}
			*(T*)iArgs.buffer = (T)a;			
		} else {
			T a = 0;
			if (VK_FAILED(string.To(a)))
			{
				/*vkString msg;
				msg.Format("Could convert %s in integer", lock.CStr());
				VK_THROW_ERROR_EX(errSyntaxError, msg);
				*/
				return errSyntaxError;
			}
			*(T*)iArgs.buffer = (T)a;
		}

		return errOk;
	}

	virtual error SaveToString(const vkStringSaveArgs& iArgs) const
	{
		iArgs.output->From(*(T*)iArgs.buffer);
		return errOk;
	}

	
	virtual const vkType* _Clone(bool iCopy) const 
	{
		if (iCopy)
			return new vkTemplateIntegerType<T>(*this);
		else
			return new vkTemplateIntegerType<T>(GetCtx(), VK_NS);
	}

	virtual bool Op(EOperation iOperation, const void* iRBuf, const void* iP1Buf, const void* iP2Buf, float iAlpha = 0) const {
		switch (iOperation) {
			case eAdd			: *(T*)iRBuf = *(T*)iP1Buf + *(T*)iP2Buf; break;
			case eSubtract		: *(T*)iRBuf = *(T*)iP1Buf - *(T*)iP2Buf; break;
			case eMultiply		: *(T*)iRBuf = *(T*)iP1Buf * *(T*)iP2Buf; break;
			case eDivide		: 
				{
					T& value = *(T*)iP2Buf;
					if(value != 0)
					{
						*(T*)iRBuf = *(T*)iP1Buf / value;
					}	
					break;
				}
			case eAddSat		: 
				{
					T old = *(T*)iP1Buf;
					*(T*)iRBuf = old + *(T*)iP2Buf;
					if (*(T*)iRBuf < old)
						*(T*)iRBuf = vkNumericLimits<T>::Max();
				} break;
			case eSubSat		: 
				{
					T old = *(T*)iP1Buf;
					*(T*)iRBuf = old - *(T*)iP2Buf;
					if (*(T*)iRBuf > old)
						*(T*)iRBuf = vkNumericLimits<T>::Min();
				} break;
				break;


			case eBinaryNot		: *(T*)iRBuf = *(T*)iP1Buf & *(T*)iP2Buf; break;
			case eBinaryAnd		: *(T*)iRBuf = *(T*)iP1Buf & *(T*)iP2Buf; break;
			case eBinaryOr		: *(T*)iRBuf = *(T*)iP1Buf | *(T*)iP2Buf; break;
			case eBinaryXor		: *(T*)iRBuf = *(T*)iP1Buf ^ *(T*)iP2Buf; break;
			
			case eMinus			: *(T*)iRBuf = -*(T*)iP1Buf; break;
			case eInverse		: 
				{
					T& value = *(T*)iP1Buf;
					if(value != 0)
					{
						*(T*)iRBuf = (T)(1 / value); 
					}
					break;
				}

			case eLerp			: *(T*)iRBuf = *(T*)iP1Buf + (T)( iAlpha * (*(T*)iP2Buf - *(T*)iP1Buf) ); break;
			case ePerSecond		: *(T*)iRBuf = T(*(T*)iP1Buf * iAlpha);			break;

			case eLower			: *(bool*)iRBuf = *(T*)iP1Buf < *(T*)iP2Buf;	break;
			case eLowerEqual	: *(bool*)iRBuf = *(T*)iP1Buf <= *(T*)iP2Buf;	break;
			case eEqual			: *(bool*)iRBuf = *(T*)iP1Buf == *(T*)iP2Buf;	break;
			case eLogicalAnd	: *(bool*)iRBuf = *(T*)iP1Buf && *(T*)iP2Buf;	break;
			case eLogicalOr		: *(bool*)iRBuf = *(T*)iP1Buf || *(T*)iP2Buf;	break;
			case eLogicalNot	: *(bool*)iRBuf = !*(T*)iP1Buf; break;

			default: return false;
		}
		return true;
	}

};

struct vkBool32Type : public vkTemplateIntegerType<int32>
{
	VK_DECLARE_RTTI(vkBool32Type, vkIntegerType);
	vkBool32Type(vkCtx iCtxHandle):vkTemplateIntegerType<int32>(iCtxHandle, VK_AS("bool32")) {}

	virtual int32 GetSize() const;

	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;

	virtual const vkType* _Clone(bool iCopy) const;
};

struct VKKERNEL_API vkBoolType : public vkTemplateIntegerType<int8>
{
	VK_DECLARE_RTTI(vkBoolType, vkIntegerType);
	vkBoolType(vkCtx iCtxHandle):vkTemplateIntegerType<int8>(iCtxHandle, VK_AS("bool")) {}

	virtual int32 GetSize() const;

	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;

	virtual const vkType* _Clone(bool iCopy) const;
};

struct VKKERNEL_API vkChar8Type : public vkTemplateIntegerType<uint8>
{
	VK_DECLARE_RTTI(vkChar8Type, vkIntegerType);
	vkChar8Type(vkCtx iCtxHandle):vkTemplateIntegerType<uint8>(iCtxHandle, VK_AS("char8")) {}

	virtual int32 GetSize() const;

	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual const vkType* _Clone(bool iCopy) const;
};

struct VKKERNEL_API vkChar16Type : public vkTemplateIntegerType<uint16>
{
	VK_DECLARE_RTTI(vkChar16Type, vkIntegerType);
	vkChar16Type(vkCtx iCtxHandle):vkTemplateIntegerType<uint16>(iCtxHandle, VK_AS("char16")) {}

	virtual int32 GetSize() const;

	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual const vkType* _Clone(bool iCopy) const;
};

struct vkChar32Type : public vkTemplateIntegerType<uint32>
{
	VK_DECLARE_RTTI(vkChar32Type, vkIntegerType);
	vkChar32Type(vkCtx iCtxHandle):vkTemplateIntegerType<uint32>(iCtxHandle, VK_AS("char32")) {}

	virtual int32 GetSize() const;

	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual const vkType* _Clone(bool iCopy) const;
};


#if defined(VK_COMPILER_MSVC)
	#pragma warning (pop)
#endif


} // NameSpace VKernel

#endif // __vkIntegerType_h



