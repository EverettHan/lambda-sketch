/**
@file

@COPYRIGHT

@author Gerald Guyomard
*/
#if !defined(__vkWeakPointerType_h)
#define __vkWeakPointerType_h

#include "vkPointerType.h"

namespace VKernel
{
	class vkWeakPointerType;
	typedef vkSmartPtr<vkWeakPointerType> vkWeakPointerTypePtr;

	/**
	Summary: vkPointerType class. 
	Description: Represents a weak pointer or reference type (Type* , or Type&).
	See Also: vkQualifiedType
	*/
	class VKKERNEL_API vkWeakPointerType : public vkPointerType
	{
	public :
		VK_DECLARE_RTTI(vkWeakPointerType, vkPointerType);

		vkWeakPointerType(vkCtx iCtxHandle, const vkString& iName);

		virtual vkString  GetCompleteName() const;
		virtual void Construct(void* iParamBuffer) const;
		virtual void Destruct(void* iParamBuffer) const;
		virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;
		virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;

		virtual void* GetUnqualifiedInstance(const void* iInstance) const;
		virtual const vkType*	GetInstanceType(const void* iInstance) const;

		virtual vkCopyFunction _GetCastFromFunction(const vkType* iDstType) const;
		virtual vkCopyFunction _GetCastToFunction(const vkType* iSrcType) const;
		
		virtual uint32 Hash(const void* iParamBuffer) const;

	protected :

		virtual const vkType* _Clone(bool iCopy) const;
	};

	class VKKERNEL_API vkRefType : public vkWeakPointerType
	{
	public :
		VK_DECLARE_RTTI(vkRefType, vkWeakPointerType);

		// For Derived classes
		vkRefType(vkCtx iCtxHandle, const vkString& iName);
		virtual vkString  GetCompleteName() const;

	protected:
		virtual const vkType* _Clone(bool iCopy) const;
	};


} // NameSpace VKernel

#endif  // __vkWeakPointerType_h



