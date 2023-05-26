/**
@file

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkFunctionPtrImplRaw_h)
#define __vkFunctionPtrImplRaw_h

#if !defined(__vkFunctionPtrImpl_h)
  #include "vkFunctionPtrImpl.h"
#endif
#if !defined(__vkKernelLib_h)
  #include "vkKernelLib.h"
#endif
#if !defined(__vkHeapObject_h)
  #include "vkHeapObject.h"
#endif

namespace VKernel
{

#if defined(VK_PROC_PPU) || defined(VK_PROC_XENON)
  #define RETURN_VALUE_REG_SIZE  8
  #define RETURN_VALUE_REG_TYPE  vkFunctionPtr::e64BitValue
#elif defined(VK_PROC_WII)
  #define RETURN_VALUE_REG_SIZE  8
  #define RETURN_VALUE_REG_TYPE  vkFunctionPtr::e2x32BitValue
#else
  #define RETURN_VALUE_REG_SIZE  4
  #define RETURN_VALUE_REG_TYPE  vkFunctionPtr::e32BitValue
#endif


#if !defined(VK_SUPPORT_AUTOGENERATED_CODE)

  #define ARGDESC_BITS_PER_KIND      2
  #define ARGDESC_64_MINUS_BITS_PER_KIND  62

  #if !defined(VK_SUPPORT_AUTOGENERATED_CODE)
  
  enum eRegType{
    eRegInt   = 0,
    eRegFloat = 1,
    eRegVector= 2
  };

  enum eLoadOp{
    eLoad1  = 0,
    eLoad2  = 1,
    eLoad4  = 2,
    eLoad8  = 3    
  };

  enum eSkipSize{
    eSkip4    = 0,
    eSkip8    = 1,
    eSkip16    = 3    
  };

  enum eShift{
    eNoShift  = 0,
    eShift1    = 1,
    eShift2    = 2,
    eShift3    = 3    
  };


  #define FILLPARAMDESC(a,rt,lo,sks,rs)  a.SkipSize = sks;a.LoadOp = lo; a.RegType = rt;a.RightShift=rs;

  // Can't use enum type directly because on Visual 
  struct ParamDesc{
    uint8  RightShift  : 2; // Shift Amount values (0,1,2,3)
    uint8  RegType    : 2; // Vector, GPR, FPR
    uint8  LoadOp    : 2; // Load Byte, short,  int/float, int64/double
    uint8  SkipSize  : 2; // in 32Bits values (1,2,4)    
  };
  
  struct ArgDesc {
    union{
      uint8 u8[16];
      uint32 u32[4];
      uint64 u64[2];
    };

    ArgDesc(){
      u64[0] = u64[1] = 0;
    }

    ArgDesc(const ArgDesc& iArgDesc){
      u64[0] = iArgDesc.u64[0];
      u64[1] = iArgDesc.u64[1];
    }

    bool operator == (const ArgDesc& iComp) const {
      return (u64[0] == iComp.u64[0]) && (u64[1] == iComp.u64[1]); 
    }
  } ;

  #endif

#endif

  
  /**
  Storage of a function pointer
  A function pointer can be a C/C++ pointer 
  or a CodeRunner pointer
  TODO : Let's make things clear,  C/C++ pointer are not always void*.
  This leads to many hacks. TO FIX.
  */
  struct VKKERNEL_API vkFunctionPtrImplRaw : public vkHeapObject
  {
    public:
    
    vkFunctionPtrImplRaw(const vkFunctionPtrImplRaw& iFct);
    vkFunctionPtrImplRaw(void** ipFuncPtr, size_t iFuncPtrSizeOf);
    
#if defined(VK_PROC_AMD64)
    ~vkFunctionPtrImplRaw() 
      {if(fctPtr.paramsDesc)vkDeallocate(fctPtr.paramsDesc);}
#endif
    
    bool operator == (const vkFunctionPtrImplRaw& iSign) const;

    typedef int32  (vkFunctionPtrImplRaw::*ICallFct)  (void* iObject, void* iParameters,int32 iParamSizeInBytes) const ;
    typedef int16  (vkFunctionPtrImplRaw::*I16CallFct)(void* iObject, void* iParameters,int32 iParamSizeInBytes) const;
    typedef int8   (vkFunctionPtrImplRaw::*I8CallFct) (void* iObject, void* iParameters,int32 iParamSizeInBytes) const;
    typedef int64  (vkFunctionPtrImplRaw::*I64CallFct)(void* iObject, void* iParameters,int32 iParamSizeInBytes) const;
    typedef float  (vkFunctionPtrImplRaw::*FCallFct)  (void* iObject, void* iParameters,int32 iParamSizeInBytes) const;
    typedef void   (vkFunctionPtrImplRaw::*VCallFct)  (void* iObject, void* iParameters,int32 iParamSizeInBytes) const;
    typedef double (vkFunctionPtrImplRaw::*DCallFct)  (void* iObject, void* iParameters,int32 iParamSizeInBytes) const;

    void  SetPointer(void* iPtr);
    void  SetFct(void* iFct);

    void*  GetRawPointer() const;    

#if defined(VK_COMPILER_MSVC)// || (defined(VK_COMPILER_GCC) && defined(VK_TARGET_IPHONE) && !(defined(VK_IPHONE_SIMULATOR)))
    // Simple pointer to code
    void* fctPtr;
    #if defined(VK_PROC_X64)
    ICallFct ParamPusherFct;
    #endif

#elif defined(VK_COMPILER_GCC)//|| (defined(VK_IPHONE_SIMULATOR))
    struct PTMF
    {
      void* codeOrVTableOffset;
      int32 thisOffset;
    };
    
    // valid on MacOS X with GCC
    // To check on other gcc implementations
    struct VKKERNEL_API FctPtr
    {
      // Constructors
      FctPtr(void* iPtr=0);
      FctPtr(const FctPtr& iOther);
      
      // new API to use for creation
      void CreateFromSimpleFunction(void* iFunctionPtr);
      void CreateFromMethod(const PTMF* iFunctionPtr);
#if defined(VK_TARGET_ANDROID)
      void ComputeVirtualCodePointer(void* iInstance);
#endif
      bool operator==(const FctPtr& iOther) const;
      
      // Allows cast to any Ptr Type per use in opCodeCompiler and other files      
      template<typename T> VK_INLINE operator T*() const
      {
        return (T*) this;
      }

      // To remove (fields now public to facilitate access in assembler)
      VK_INLINE void* GetRawPointer() const
      {
#if defined(VK_TARGET_ANDROID)
        if (realVTableOffset) return realVTableOffset;
#endif
        return codeOrVTableOffset;
      }
      
    public:    
      // codeOrVTableOffset is even => direct pointer to code
      // codeOrVTableOffset is odd : codeOrVTableOffset-1 is the offset in the vtable
      void*  codeOrVTableOffset;
          
      // iOS : "virtual" is not checked on codeOrVTableOffset, we use thisOffset
      // thisOffset = 2 * (real offset) + 1 if the function is virtual
      // Cf : ARM CPP ABI Section 3.2.1
#if defined(VK_TARGET_IPHONE)
      int32 thisOffset;
#endif      
      
      // parameters description for handling passing of arguments
      // with non trivial copy constructor or destructor
#if defined(VK_PROC_X86)  || defined(VK_TARGET_IPHONE) 
      int32*  paramsDesc;
#elif defined(VK_PROC_AMD64) || defined(VK_TARGET_ANDROID)
      uint32* paramsDesc;
#endif

#if defined(VK_TARGET_ANDROID)
      void* realVTableOffset;
#endif  
    };
    FctPtr fctPtr;
#else
  #error "fctPtr not defined"
#endif

    union
    {
      I8CallFct  callerI8;
      I16CallFct  callerI16;
      ICallFct  callerI;
      I64CallFct  callerI64;
      FCallFct  callerF;
      DCallFct  callerD;
      VCallFct  callerV;
    };
    union
		{
			I8CallFct	callerI8Mov;
			I16CallFct	callerI16Mov;
			ICallFct	 callerIMov;
			I64CallFct callerI64Mov;
			FCallFct	callerFMov;
			DCallFct	callerDMov;
		};
    
    int8   CallI8(void* iObject,void* iParameters,int32 iParamSizeInBytes) const;
    int16  CallI16(void* iObject,void* iParameters,int32 iParamSizeInBytes) const;
    int32  CallI32(void* iObject,void* iParameters,int32 iParamSizeInBytes) const;
    int64  CallI64(void* iObject,void* iParameters,int32 iParamSizeInBytes) const;
    float  CallF(void* iObject,void* iParameters,int32 iParamSizeInBytes) const;
    double CallD(void* iObject,void* iParameters,int32 iParamSizeInBytes) const;
    void   CallV(void* iObject,void* iParameters,int32 iParamSizeInBytes) const;    

#ifdef VK_USE_REGISTER_FOR_CALL
  #ifdef VK_SUPPORT_AUTOGENERATED_CODE
    void* paramPusher;
  #else
    ArgDesc m_ArgDesc;
  #endif
#endif

  };
        
/**
Inlined implementations
*/

VK_INLINE bool
vkFunctionPtrImplRaw::operator==(const vkFunctionPtrImplRaw& iSign) const
{
  return (fctPtr == iSign.fctPtr);
}

VK_INLINE int8
vkFunctionPtrImplRaw::CallI8(void* iObject,void* iParameters,int32 iParamSizeInBytes) const
{
  VKASSERT(this->callerI != 0);
  return (this->*callerI8)(iObject,iParameters,iParamSizeInBytes);
}

VK_INLINE int16
vkFunctionPtrImplRaw::CallI16(void* iObject,void* iParameters,int32 iParamSizeInBytes) const
{
  VKASSERT(this->callerI != 0);
  return (this->*callerI16)(iObject,iParameters,iParamSizeInBytes);
}

VK_INLINE int32
vkFunctionPtrImplRaw::CallI32(void* iObject,void* iParameters,int32 iParamSizeInBytes) const
{
  VKASSERT(this->callerI != 0);
  return (this->*callerI)(iObject,iParameters,iParamSizeInBytes);
}

VK_INLINE int64
vkFunctionPtrImplRaw::CallI64(void* iObject,void* iParameters,int32 iParamSizeInBytes) const
{
  VKASSERT(this->callerI != 0);
  return (this->*callerI64)(iObject,iParameters,iParamSizeInBytes);
}
  
VK_INLINE float
vkFunctionPtrImplRaw::CallF(void* iObject,void* iParameters,int32 iParamSizeInBytes) const
{
  VKASSERT(this->callerI != 0);
  return (this->*callerF)(iObject,iParameters,iParamSizeInBytes);
}
  
VK_INLINE void
vkFunctionPtrImplRaw::CallV(void* iObject,void* iParameters,int32 iParamSizeInBytes) const
{
  VKASSERT(this->callerI != 0);
  return (this->*callerV)(iObject,iParameters,iParamSizeInBytes);
}

VK_INLINE double
vkFunctionPtrImplRaw::CallD(void* iObject,void* iParameters,int32 iParamSizeInBytes) const
{
  VKASSERT(this->callerI != 0);
  return (this->*callerD)(iObject,iParameters,iParamSizeInBytes);
}
  
// #ifdef VK_64BIT
  // #define CallPtr CallI64
// #else
  // #define CallPtr CallI
// #endif

/************************************************************************/
/* GetRawPointer Imp                                                    */
/************************************************************************/
#if defined(VK_COMPILER_MSVC)// || (defined(VK_TARGET_IPHONE))
  VK_INLINE void*
  vkFunctionPtrImplRaw::GetRawPointer() const
  {
    return fctPtr;
  }

#elif defined(VK_COMPILER_GCC)

  // TODO ps3: Check if a simple pointer to code can work
  VK_INLINE void*
  vkFunctionPtrImplRaw::GetRawPointer() const
  {
    return fctPtr.GetRawPointer();
  }
#else
  #error "GetRawPointer is not implemented"
#endif

}

#endif // __vkFunctionPtr_h

