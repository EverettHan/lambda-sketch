/**
@file

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkFunctionPtrImpl_h)
#define __vkFunctionPtrImpl_h

#if !defined(__vkKernelLib_h)
  #include "vkKernelLib.h"
#endif
#if !defined(__vkHeapObject_h)
  #include "vkHeapObject.h"
#endif

#if !defined(__vkCallBuffer_h)
  #include "vkCallBuffer.h"
#endif

#if !defined(__vkFunctionPtr_h)
  #include "vkFunctionPtr.h"
#endif

#include <functional>
#include <stdexcept>

namespace VKernel
{
  struct vkFunctionPtrImplRaw;

  typedef void (*vkDestructor)(void* instance);

  // Root class for implementations of vkFunctionPtr
  class VKKERNEL_API vkFunctionPtrImpl
  {

  public:
    virtual ~vkFunctionPtrImpl() {}
    vkFunctionPtrImpl()          {}

    virtual vkFunctionPtrImpl * copy() = 0;

    vkFunctionPtrImpl& operator=(const vkFunctionPtrImpl& iToCopy) = delete;
    vkFunctionPtrImpl(const vkFunctionPtrImpl & iToCopy) = delete;

    virtual operator bool() const noexcept = 0;

    virtual void Call(const vkCallBuffer & iParams,std::int8_t& oRet)  const { VKASSERT(0);}
    virtual void Call(const vkCallBuffer & iParams,std::int16_t& oRet) const { VKASSERT(0);}
    virtual void Call(const vkCallBuffer & iParams,std::int32_t& oRet) const { VKASSERT(0);}
    virtual void Call(const vkCallBuffer & iParams,std::int64_t& oRet) const { VKASSERT(0);}
    virtual void Call(const vkCallBuffer & iParams,float& oRet)        const { VKASSERT(0);}
    virtual void Call(const vkCallBuffer & iParams,double& oRet)       const { VKASSERT(0);}
    virtual void Call(const vkCallBuffer & iParams,void*& oRet)        const { VKASSERT(0);}
    virtual void Call(const vkCallBuffer & iParams)                    const { VKASSERT(0);}

    virtual vkFunctionPtrImplRaw* GetFunctionRawImpl() const
      { return nullptr;}
  };

  // Final implementations of vkFunctionPtr returning a value
  template <typename RT>
  class VKKERNEL_API vkFunctionPtrImpl_Spec : public vkFunctionPtrImpl
  {
    typedef std::function<RT(const VKernel::vkCallBuffer&)>  vkFunctionPtrType_;

  private:
    vkFunctionPtrType_ _mFunc = nullptr;
  public:

    vkFunctionPtrImpl_Spec(const vkFunctionPtrType_ && iFunc): _mFunc(std::move(iFunc))
      {}
    virtual ~vkFunctionPtrImpl_Spec()
      {_mFunc=nullptr;}
    virtual vkFunctionPtrImpl * copy() override
      { return new vkFunctionPtrImpl_Spec<RT>(std::move(vkFunctionPtrType_(_mFunc))); }
    virtual operator bool() const noexcept override
      {return (bool) _mFunc ;}
    void Call(const vkCallBuffer & iParams, RT& oRet) const override
      { oRet = _mFunc(iParams);}
  };

  // Final implementations of vkFunctionPtr returning no value
  template <>
  class VKKERNEL_API vkFunctionPtrImpl_Spec<void> : public vkFunctionPtrImpl
  {
    typedef std::function<void(const VKernel::vkCallBuffer&)>  vkFunctionPtrType_;

  private:
    vkFunctionPtrType_ _mFunc = nullptr;
  public:

    vkFunctionPtrImpl_Spec(const vkFunctionPtrType_ && iFunc): _mFunc(std::move(iFunc))
      {}
    virtual ~vkFunctionPtrImpl_Spec()
      {_mFunc=nullptr;}
    virtual vkFunctionPtrImpl * copy() override
      { return new vkFunctionPtrImpl_Spec<void>(std::move(vkFunctionPtrType_(_mFunc))); }
    virtual operator bool() const noexcept override
      {return (bool) _mFunc ;}
    void Call(const vkCallBuffer & iParams) const override
      { _mFunc(iParams);}
  };

  // This class derivating from vkFunctionPtrImpl is necessary because vkFunctionPtrImplRaw
  // must be a non virtual class (i.e. without a vtable) in order the assembler code works fine
  // -> vkFunctionPtrImplRaw cannot derivate from vkFunctionPtrImpl
  class VKKERNEL_API vkFunctionPtrLegacy : public vkFunctionPtrImpl
  {
    public:
    vkFunctionPtrLegacy(void** ipFuncPtr, size_t iFuncPtrSizeOf);
    vkFunctionPtrLegacy(const vkFunctionPtrLegacy & iToCopy);
    virtual ~vkFunctionPtrLegacy();
    vkFunctionPtrLegacy * copy() override;
    operator bool() const noexcept override;

    vkFunctionPtrImplRaw * GetFunctionRawImpl() const override
    { return _impl;}

    virtual void Call(const vkCallBuffer & iParams,std::int8_t& oRet)  const override;          
    virtual void Call(const vkCallBuffer & iParams,std::int16_t& oRet) const override;          
    virtual void Call(const vkCallBuffer & iParams,std::int32_t& oRet) const override;          
    virtual void Call(const vkCallBuffer & iParams,std::int64_t& oRet) const override;          
    virtual void Call(const vkCallBuffer & iParams,float& oRet)        const override;          
    virtual void Call(const vkCallBuffer & iParams,double& oRet)       const override;          
    virtual void Call(const vkCallBuffer & iParams,void*& oRet)        const override;          
    virtual void Call(const vkCallBuffer & iParams)                    const override; 
    
    vkFunctionPtrImplRaw * _impl = nullptr; // should not have virtual function table in order assembler works fine
  };
}

#endif // __vkFunctionPtrImpl_h
