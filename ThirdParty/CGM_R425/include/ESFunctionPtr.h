/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESFunctionPtr_h
#define __ESFunctionPtr_h

//ES
#include "ESKernelLib.h"

#include <vector>
#include <iostream>
#include <functional>
#include <stdexcept>
#include <string>
#include <math.h>

#include "ESFunctionPtr_Internal.h"

namespace ES {   

  /**
	Class describing a ES FunctionPtr
	*/
	class ESKERNEL_API FunctionPtr {

	public:
    
    virtual ~FunctionPtr();
    FunctionPtr();
		FunctionPtr(const FunctionPtr& iToCopy);    
    FunctionPtr& operator=(const FunctionPtr& iToCopy);
    
    FunctionPtr& operator=(const VKernel::vkFunctionPtr& iToCopy) ;
    FunctionPtr(const VKernel::vkFunctionPtr & ivkPtr) ; 
  
    // CTOR for RT rc = sMeth(...)     
    // static functions 
    // return value
    //----------------------------
    
    // 4 args and more : RT rc = sMeth(ARG0,AG1,ARG2,ARG3,...)
    template <typename RT, typename ARG0, typename ARG1, typename ARG2,  typename ARG3, typename... Args>
    FunctionPtr(RT(*user_func)(ARG0,ARG1,ARG2,ARG3,Args...),bool)     
     : FunctionPtr(std::move(FunctionPtrUtil::esAdaptFunc_R(std::move(std::function<RT(ARG0,ARG1,ARG2,ARG3,Args...)> (user_func)))))
      {}
  
    // 3 args : RT rc = sMeth(ARG0,ARG1,ARG2) 
    template <typename RT, typename ARG0, typename ARG1, typename ARG2>
    FunctionPtr(RT(*user_func)(ARG0,ARG1,ARG2),bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm(user_func(params.get<ARG0>(0),params.get<ARG1>(1),params.get<ARG2>(2)));};
        _Initialize(std::move(std_func));
      }
    
    // 2 args : RT rc = sMeth(ARG0,ARG1) 
    template <typename RT, typename ARG0, typename ARG1>
    FunctionPtr(RT(*user_func)(ARG0,ARG1),bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm(user_func(params.get<ARG0>(0),params.get<ARG1>(1)));};
        _Initialize(std::move(std_func));
      }
      
    // 1 args : RT rc = sMeth(ARG0) 
    template <typename RT, typename ARG0>
    FunctionPtr(RT(*user_func)(ARG0),bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm(user_func(params.get<ARG0>(0)));};
        _Initialize(std::move(std_func));
      }
    
    // 0 args : RT rc = sMeth() 
    template <typename RT>
    FunctionPtr(RT(*user_func)(),bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& iterOnArgs) -> ReturnedType<RT> 
          { return Normalize<RT>::norm(user_func());};
        _Initialize(std::move(std_func));
      }
      
    // CTOR for void sMeth(...)
    // static functions 
    // No return value
    //-------------------------
    
    // 4 args and more : void sMeth(ARG0,AG1,ARG2,ARG3,...)
    template <typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename... Args>
    FunctionPtr(void(*user_func)(ARG0,ARG1,ARG2,ARG3,Args...),bool)     
     : FunctionPtr(std::move(FunctionPtrUtil::esAdaptFunc_(std::move(std::function<void(ARG0,ARG1,ARG2,ARG3,Args...)> (user_func)))))
      {}
  
    // 3 args : void sMeth(ARG0,ARG1,ARG2) 
    template <typename ARG0, typename ARG1, typename ARG2>
    FunctionPtr(void(*user_func)(ARG0,ARG1,ARG2),bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void 
          { user_func(params.get<ARG0>(0),params.get<ARG1>(1),params.get<ARG2>(2));};
        _Initialize(std::move(std_func));
      }
    
    // 2 args : void sMeth(ARG0,ARG1) 
    template <typename ARG0, typename ARG1>
    FunctionPtr(void(*user_func)(ARG0,ARG1),bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void 
          { user_func(params.get<ARG0>(0),params.get<ARG1>(1));};
        _Initialize(std::move(std_func));
      }
      
    // 1 args : void sMeth(ARG0) 
    template <typename ARG0>
    FunctionPtr(void(*user_func)(ARG0),bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void
          {user_func(params.get<ARG0>(0));};
        _Initialize(std::move(std_func));
      }
    
    // 0 args : sMeth() 
    FunctionPtr(void(*user_func)(),bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&&) -> void
          {return user_func();};
        _Initialize(std::move(std_func));
      }
	
    // CTOR for RT rc = CM::Meth(...)
    // non-static member functions
    // return value
    // non-const version
    //----------------------------    
    
    // 3 args and more : RT rc = CM::Meth(ARG0,AG1,ARG2,...)
    template <typename RT, typename CM, typename ARG0, typename ARG1, typename ARG2, typename... Args>
    FunctionPtr(RT(CM::*user_func)(ARG0,ARG1,ARG2,Args...),bool) 
      :FunctionPtr(std::move(FunctionPtrUtil::esAdaptFunc_R(std::move(std::function<RT(CM*,ARG0,ARG1,ARG2,Args...)> (user_func)))))
      {}
    
    // 2 args : RT rc = CM::Meth(ARG0,ARG1) 
    template <typename RT, typename CM, typename ARG0, typename ARG1>
    FunctionPtr(RT(CM::*user_func)(ARG0,ARG1),bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm((params.get<CM*>(0)->*user_func)(params.get<ARG0>(1),params.get<ARG1>(2)));};
        _Initialize(std::move(std_func));
      }
      
    // 1 args : RT rc = CM::Meth(ARG0) 
    template <typename RT, typename CM, typename ARG0>
    FunctionPtr(RT(CM::*user_func)(ARG0),bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm((params.get<CM*>(0)->*user_func)(params.get<ARG0>(1)));};
        _Initialize(std::move(std_func));
      }
    
    // 0 args : RT rc = CM::Meth() 
    template <typename RT, typename CM>
    FunctionPtr(RT(CM::*user_func)(),bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm((params.get<CM*>(0)->*user_func)());};
        _Initialize(std::move(std_func));
      }
            
    // CTOR for RT rc = CM::Meth(...) const
    // non-static member functions
    // return value
    // const version
    //-------------------------------------
    
    // 3 args and more : RT rc = CM::Meth(ARG0,AG1,ARG2,...) const
    template <typename RT, typename CM, typename ARG0, typename ARG1, typename ARG2, typename... Args>
    FunctionPtr(RT(CM::*user_func)(ARG0,ARG1,ARG2,Args...) const,bool) 
      :FunctionPtr(std::move(FunctionPtrUtil::esAdaptFunc_R(std::move(std::function<RT(const CM*,ARG0,ARG1,ARG2,Args...)> (user_func)))))
      {}
    
    // 2 args : RT rc = CM::Meth(ARG0,ARG1) const
    template <typename RT, typename CM, typename ARG0, typename ARG1>
    FunctionPtr(RT(CM::*user_func)(ARG0,ARG1) const,bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm((params.get<const CM*>(0)->*user_func)(params.get<ARG0>(1),params.get<ARG1>(2)));};
        _Initialize(std::move(std_func));
      }
      
    // 1 args : RT rc = CM::Meth(ARG0) const
    template <typename RT, typename CM, typename ARG0>
    FunctionPtr(RT(CM::*user_func)(ARG0) const,bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm((params.get<const CM*>(0)->*user_func)(params.get<ARG0>(1)));};
        _Initialize(std::move(std_func));
      }
    
    // 0 args : RT rc = CM::Meth() const
    template <typename RT, typename CM>
    FunctionPtr(RT(CM::*user_func)() const,bool)     
      {
        std::function<ReturnedType<RT>(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> ReturnedType<RT> 
          { return Normalize<RT>::norm((params.get<const CM*>(0)->*user_func)());};
        _Initialize(std::move(std_func));
      }

    // CTOR for void CM::Meth(...)
    // non-static member functions 
    // No return value
    //--------------------------------------------------------------------------
    
    // 3 args and more : void CM::Meth(ARG0,AG1,ARG2,...) 
    template <typename CM, typename ARG0, typename ARG1, typename ARG2, typename... Args>
    FunctionPtr(void(CM::*user_func)(ARG0,ARG1,ARG2,Args...),bool) 
      :FunctionPtr(std::move(FunctionPtrUtil::esAdaptFunc_(std::move(std::function<void(CM*,ARG0,ARG1,ARG2,Args...)> (user_func)))))
      {}
    
    // 2 args : void CM::Meth(ARG0,ARG1) 
    template <typename CM, typename ARG0, typename ARG1>
    FunctionPtr(void(CM::*user_func)(ARG0,ARG1),bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void
          { return (params.get<CM*>(0)->*user_func)(params.get<ARG0>(1),params.get<ARG1>(2));};
        _Initialize(std::move(std_func));
      }
      
    // 1 args : void CM::Meth(ARG0)
    template <typename CM, typename ARG0>
    FunctionPtr(void(CM::*user_func)(ARG0),bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void
          { return (params.get<CM*>(0)->*user_func)(params.get<ARG0>(1));};
        _Initialize(std::move(std_func));
      }
    
    // 0 args : void CM::Meth() 
    template <typename CM>
    FunctionPtr(void(CM::*user_func)() ,bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void 
          { return (params.get<CM*>(0)->*user_func)();};
        _Initialize(std::move(std_func));
      }
    
    // CTOR for void CM::Meth(...)
    // non-static member functions 
    // No return value
    // const version
    //--------------------------------------------------------------------------
      
    // 3 args and more : void CM::Meth(ARG0,AG1,ARG2,...) 
    template <typename CM, typename ARG0, typename ARG1, typename ARG2, typename... Args>
    FunctionPtr(void(CM::*user_func)(ARG0,ARG1,ARG2,Args...) const,bool) 
      :FunctionPtr(std::move(FunctionPtrUtil::esAdaptFunc_(std::move(std::function<void(const CM*,ARG0,ARG1,ARG2,Args...)> (user_func)))))
      {}
    
    // 2 args : void CM::Meth(ARG0,ARG1) 
    template <typename CM, typename ARG0, typename ARG1>
    FunctionPtr(void(CM::*user_func)(ARG0,ARG1) const,bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void
          { return (params.get<const CM*>(0)->*user_func)(params.get<ARG0>(1),params.get<ARG1>(2));};
        _Initialize(std::move(std_func));
      }
      
    // 1 args : void CM::Meth(ARG0)
    template <typename CM, typename ARG0>
    FunctionPtr(void(CM::*user_func)(ARG0) const,bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void
          { return (params.get<const CM*>(0)->*user_func)(params.get<ARG0>(1));};
        _Initialize(std::move(std_func));
      }
    
    // 0 args : void CM::Meth() 
    template <typename CM>
    FunctionPtr(void(CM::*user_func)() const,bool)     
      {
        std::function<void(FunctionInputs&&)> std_func = [=] (FunctionInputs&& params) -> void 
          { return (params.get<const CM*>(0)->*user_func)();};
        _Initialize(std::move(std_func));
      }
    
    // CTORs corresponding to legacy code
    //-----------------------------------

#if defined(__aarch64__)
    template<typename T> 
    FunctionPtr(T iFct) : FunctionPtr(iFct, true)
      {			
      }
#else
    template<typename T> 
    FunctionPtr(T iFct)
      { 
        if (iFct)
        {
          T tmp = iFct;
          _Initialize( (void**) &tmp, sizeof(iFct) ); 
        }			
      }
#endif
      
    // Some specific CTORs that that may help to reduce dll size 
    // In opposite to templated CTORs that generate lots of code in callers dlls, these ones do not.
    // But as the parameters and the return object are untyped, they are more difficult to use and need
    // to get how to create typed data from untypes ones, like it's done in ESFunctionPtr_Internal's functions.
    explicit FunctionPtr(std::function<std::int8_t(FunctionInputs&&)>  && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    explicit FunctionPtr(std::function<std::int16_t(FunctionInputs&&)> && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    explicit FunctionPtr(std::function<std::int32_t(FunctionInputs&&)> && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    explicit FunctionPtr(std::function<std::int64_t(FunctionInputs&&)> && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    explicit FunctionPtr(std::function<double      (FunctionInputs&&)>   && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    explicit FunctionPtr(std::function<float       (FunctionInputs&&)>   && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    explicit FunctionPtr(std::function<void        (FunctionInputs&&)>   && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    explicit FunctionPtr(std::function<void*       (FunctionInputs&&)> && iStdFunction)
    { _Initialize(std::move(iStdFunction));}
    
    // Check if this contains a function or if it is empty
		explicit operator bool() const noexcept;		
    
    // start of internal use methods 
    // =============================
    // Get the real assembler implementation if it exists
    VKernel::vkFunctionPtrImplRaw* GetFunctionRawImpl() const;
    // Get the real implementation
		VKernel::vkFunctionPtr* GetVkFunctionPtr() const ;    
    // Helper to execute the function of 'this' with a specific signature corresponding to ES binded destructors : void(void*)
    void  CallV_Ptr(void* iPtr) const;
    // end of internal use methods 
    // ===========================

  private:		
		
    void _Initialize(void** ipFunctionPtr, size_t iFuncPtrSize);
    
    void _Initialize(std::function<std::int8_t (FunctionInputs&&)> && iStdFunction);
    void _Initialize(std::function<std::int16_t(FunctionInputs&&)> && iStdFunction);
    void _Initialize(std::function<std::int32_t(FunctionInputs&&)> && iStdFunction);
    void _Initialize(std::function<std::int64_t(FunctionInputs&&)> && iStdFunction);
    void _Initialize(std::function<double      (FunctionInputs&&)> && iStdFunction);
    void _Initialize(std::function<float       (FunctionInputs&&)> && iStdFunction);
    void _Initialize(std::function<void        (FunctionInputs&&)> && iStdFunction);
    void _Initialize(std::function<void*       (FunctionInputs&&)> && iStdFunction);
    
    bool operator == (const FunctionPtr& iToTest) const = delete;
        
		VKernel::vkFunctionPtr * m_FunctionPtr=nullptr;
    
		friend class Signature;
		friend class Namespace;
		friend class Class;
    friend class V8Binding;
	};   
}

#endif //__ESFunctionPtr_h


