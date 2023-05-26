/**
@file

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkFunctionPtr_h)
#define __vkFunctionPtr_h

#if !defined(__vkKernelLib_h)
  #include "vkKernelLib.h"
#endif

#if !defined(__vkCallBuffer_h)
  #include "vkCallBuffer.h"
#endif

#include <iostream>
#include <functional>
#include <stdexcept>
  
namespace VKernel
{     
  class  vkFunctionPtrImpl;
  struct vkFunctionPtrImplRaw;
  
  typedef std::function<std::int8_t(const VKernel::vkCallBuffer&)>  vkFunctionPtrType_I8;
  typedef std::function<std::int16_t(const VKernel::vkCallBuffer&)> vkFunctionPtrType_I16;
  typedef std::function<std::int32_t(const VKernel::vkCallBuffer&)> vkFunctionPtrType_I32;
  typedef std::function<std::int64_t(const VKernel::vkCallBuffer&)> vkFunctionPtrType_I64;
  typedef std::function<double(const VKernel::vkCallBuffer&)>       vkFunctionPtrType_D;
  typedef std::function<float(const VKernel::vkCallBuffer&)>        vkFunctionPtrType_F;
  typedef std::function<void(const VKernel::vkCallBuffer&)>         vkFunctionPtrType_V;
  typedef std::function<void*(const VKernel::vkCallBuffer&)>        vkFunctionPtrType_PTR;
     
  /**
  Storage of a function pointer
  A function pointer can be a C/C++ pointer 
  or a CodeRunner pointer
  */
  class VKKERNEL_API vkFunctionPtr 
  {   
  
  public:
    
    enum ECallType
    {
      eCDECL,
      eSTD,
      eVSL,
      eSchematic
    };
    
    enum EReturnType
    {
      eFloat = 0,
      eVoid,
      e32BitValue,
      e16BitValue,
      e8BitValue,
      eStructValue,
      eDouble,
      e64BitValue,
      e2x32BitValue,
      eMaxReturnType
    };
    
    vkFunctionPtr() {};    
    vkFunctionPtr& operator=(const vkFunctionPtr& iToCopy);    
    vkFunctionPtr(const vkFunctionPtr & iToCopy); 
    virtual ~vkFunctionPtr();   
    
    // Ctors for template code (new)
    explicit vkFunctionPtr(const vkFunctionPtrType_I8 && iFunc);
    explicit vkFunctionPtr(const vkFunctionPtrType_I16 && iFunc);
    explicit vkFunctionPtr(const vkFunctionPtrType_I32 && iFunc);
    explicit vkFunctionPtr(const vkFunctionPtrType_I64 && iFunc);
    explicit vkFunctionPtr(const vkFunctionPtrType_D && iFunc);
    explicit vkFunctionPtr(const vkFunctionPtrType_F && iFunc);
    explicit vkFunctionPtr(const vkFunctionPtrType_V && iFunc);
    explicit vkFunctionPtr(const vkFunctionPtrType_PTR && iFunc);

    // Ctors for assembler code (legacy) 
		template<typename T> 
    vkFunctionPtr(T iFct)
		{ 
			if (iFct)
			{
				T tmp = iFct;
				LegacyInitialize( (void**) &tmp, sizeof(iFct) ); 
			}			
		}    
    void LegacyInitialize(void** ipFunctionPtr, size_t iFuncPtrSize);
    
    operator bool() const noexcept;
    
    std::int8_t  Call_I8(const vkCallBuffer & iParams)  const;
    std::int16_t Call_I16(const vkCallBuffer & iParams) const;
    std::int32_t Call_I32(const vkCallBuffer & iParams) const;
    std::int64_t Call_I64(const vkCallBuffer & iParams) const;
    float        Call_F(const vkCallBuffer & iParams)   const;
    double       Call_D(const vkCallBuffer & iParams)   const;
    void         Call_V(const vkCallBuffer & iParams)  const;
    void*        Call_PTR(const vkCallBuffer & iParams) const;
    
    vkFunctionPtrImplRaw* GetFunctionRawImpl() const;    

  private:
    vkFunctionPtrImpl * _mLetter = nullptr;
  };
}      

#endif // __vkFunctionPtr_h
