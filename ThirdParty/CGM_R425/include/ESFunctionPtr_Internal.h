/**
@file

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__ESFunctionPtr_Internal_h)
#define __ESFunctionPtr_Internal_h

namespace VKernel
{
  class vkCallBuffer;
  class vkCallBufferAccessor;
  class vkFunctionPtr;
  struct vkFunctionPtrImplRaw;
}

namespace ES
{        

  // =========================================================================
	// Class describing an iterator on the inputs of a ES::FunctionPtr :
  // first the object on which to apply the function if its a class data member
  // then the arguments of the function
	// ==========================================================================
  class ESKERNEL_API FunctionInputs
  {
    public:
    
    FunctionInputs(const VKernel::vkCallBuffer & iBuffer);  
    ~FunctionInputs();  
    
    // Untyped access to next element
    void* get(size_t iDataIndex, size_t iDataSize);
    
    // Typed access to next element defined by value
    template<typename T>
    typename std::enable_if<!std::is_reference<T>::value,T>::type get(size_t iDataIndex)
    {return *((T*) get(iDataIndex, sizeof(T)));}
  
    // Typed access to next element defined by reference
    template<typename T>
    typename std::enable_if<std::is_reference<T>::value,T>::type get(size_t iDataIndex) 
    {return **((typename std::remove_reference<T>::type**)get(iDataIndex,sizeof(typename std::remove_reference<T>::type*)));}
  
    VKernel::vkCallBufferAccessor * m_Iter  = nullptr;  
  };   
  
  /*
  #define _MACRO_NEXT_ARG_(iType, oArg, iIter) \
    size_t sizeElt##oArg  = (std::is_reference<iType>::value) ? sizeof(void*) : sizeof(iType);\
    void * dataFromBuffer##oArg =  iIter.Next(sizeElt##oArg); \
    void * ptrOnArg##oArg       = (std::is_reference<iType>::value) ? *( (void**) dataFromBuffer##oArg ) : dataFromBuffer##oArg ; \
    iType oArg = *((typename std::add_pointer<iType>::type)  ptrOnArg##oArg) ;  
  */
    
	// ===============================================
  // Template alias type ReturnedType
  // mapping from exact returned types to normalized
  // return types 
  // ===============================================
      
  //  pointwise mapping   
  template<size_t BITS>
  struct BitsToTypesMap;
    
  template<>
  struct BitsToTypesMap<1> 
  { typedef std::int8_t TYPE;  };
  
  template<>
  struct BitsToTypesMap<2>
  { typedef std::int16_t TYPE; };
  
  template<>
  struct BitsToTypesMap<4>
  { typedef std::int32_t TYPE; };  
  
  template<>
  struct BitsToTypesMap<8>
  { typedef std::int64_t TYPE; };
  
  //  type2type mapping  
  template <typename RT, typename Enable=void> 
  struct TypesToRetTypesMap; 
  
  template<>
  struct TypesToRetTypesMap<double> 
  { typedef double TYPE; };
  
  template<>
  struct TypesToRetTypesMap<float> 
  { typedef float TYPE; };
  
  // Partial specialisation, not a separate template.
  template <typename RT> 
  struct TypesToRetTypesMap<RT, typename std::enable_if<!std::is_pointer<RT>::value&&!std::is_reference<RT>::value&&!std::is_void<RT>::value>::type> 
  { typedef typename BitsToTypesMap<sizeof(RT)>::TYPE TYPE; };
  
  template <typename RT> 
  struct TypesToRetTypesMap<RT, typename std::enable_if<std::is_pointer<RT>::value>::type> 
  { typedef void* TYPE; };
  
  template <typename RT> 
  struct TypesToRetTypesMap<RT, typename std::enable_if<std::is_reference<RT>::value>::type> 
  { typedef void* TYPE; };
  
  template <typename RT> 
  struct TypesToRetTypesMap<RT, typename std::enable_if<std::is_void<RT>::value>::type> 
  { using TYPE = void; };
  
  // cute wrapping 
  template<typename RT>   
  using ReturnedType = typename TypesToRetTypesMap<RT>::TYPE;   
 
  // ===============================================
  // Template function that normalizes a return type   
  // ===============================================      
  template <typename RT,typename Enable=void>
  struct Normalize;
  
  template <typename RT>
  struct Normalize<RT,typename std::enable_if<std::is_reference<RT>::value>::type>
  { static void * norm(RT iRet) {return (void*)&iRet;}};
  
  template <typename RT>
  struct Normalize<RT,typename std::enable_if<std::is_pointer<RT>::value>::type>
  { static void * norm(RT iRet) {return (void*)iRet;}};
  
  template <typename RT>
  struct Normalize<RT,typename std::enable_if<!std::is_pointer<RT>::value&&!std::is_reference<RT>::value&&!std::is_void<RT>::value>::type>
  {
    static ReturnedType<RT> norm(RT iRet)
    {
      ReturnedType<RT> rc;
      memcpy(&rc,&iRet,sizeof(RT));
      return rc;
    }    
  };
  
  // // The following specialisation is correct but it's useless as the following code doesnt compile. 
  // // (Maybe the type std::void_t in c++17 will help to solve that).
  // // void Meth() {}
  // // Normalize<void>::norm(Meth) 
  // template <typename RT>
  // struct Normalize<RT,typename std::enable_if<std::is_void<RT>::value>::type>
  // {
    // static void norm(RT) {return;}    
  // };
  
  // =======================================================
  // Template alias type FinalStdFunctionType
  // Mapping from exact returned types to std::function type 
  // =======================================================  
  template<typename T>
  using FinalStdFunctionType = typename std::function<ReturnedType<T>(FunctionInputs&&)>;

  // Macro for 
  #define _GET_ARG_IND_(iNum) params.get<ARG##iNum>(iIndex+iNum)   
  
  // ============================================================
  // Utility class that provide utility static template functions
  //
  // esAdaptFunc_ and esAdaptFunc_R have the following specs  :
  // IN : a general std::function, which means its input parameters types, 
  // and also its return type with some limitations, can be anything
  // OUT : a normalized std::function with the following signature 
  // (FunctionInputs&& params) -> ReturnedType<RT> with RT the initial
  // return type
  // ============================================================
  class ESKERNEL_API FunctionPtrUtil
  {
    public :       

    // FROM
    // user function (parameters are typed) 
    // TO 
    // function with untyped param
    // ------------------------------------    

    // 4 args and more : RT rc = Meth(ARG0,ARG1,AG2,ARG3,...)     
    template <typename RT, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename... Args>
    static FinalStdFunctionType<RT>  esAdaptFunc_R( std::function<RT(ARG0,ARG1,ARG2,ARG3,Args...)> &&std_user_func) 
    {            
      return [std_user_func{move(std_user_func)}](FunctionInputs&& params) -> ReturnedType<RT> 
        {
          const std::function<RT(ARG0,ARG1,ARG2,ARG3,Args...)> & std_user_func_local =  std_user_func;
          return Normalize<RT>::norm(esCallFuncAndRet(std_user_func_local, std::move(params),0));
        };
    }
   
    // 4 args and more : void Meth(ARG0,ARG1,ARG2,ARG3,...)
    template <typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename... Args>
    static FinalStdFunctionType<void>  esAdaptFunc_( std::function<void(ARG0,ARG1,ARG2,ARG3,Args...)> &&std_user_func)
    {      
      return  [std_user_func{move(std_user_func)}](FunctionInputs&& params) -> void {            
          const std::function<void(ARG0,ARG1,ARG2,ARG3,Args...)> & std_user_func_local =  std_user_func;
          esCallFunc(std_user_func_local, std::move(params), 0);
        };
    }
    
    private:
    
    //
    // esCallFuncAndRet and esCallFunc goal is to convert from untyped data
    // , coming from JS via a FunctionInputs, into the real expected types 
    // of the initial function and to execute this function
    //
    
  
    // std functions with return
    // ---------------------------
   
    // 0 arg
    template <typename RT>
    static RT esCallFuncAndRet(const std::function<RT()> &lambda_prec, FunctionInputs&& params, size_t iIndex)
    { return lambda_prec(); }

    // 1 args
    template <typename RT, typename ARG0>
    static RT esCallFuncAndRet(const std::function<RT(ARG0)> &lambda_prec, FunctionInputs&& params, size_t iIndex)
    { return lambda_prec(_GET_ARG_IND_(0)); }
    
    // 2 args
    template <typename RT, typename ARG0, typename ARG1>
    static RT esCallFuncAndRet(const std::function<RT(ARG0,ARG1)> &lambda_prec, FunctionInputs&& params, size_t iIndex)
    { return lambda_prec(_GET_ARG_IND_(0),_GET_ARG_IND_(1)); }

    // 3 args and more
    template <typename RT, typename ARG0, typename ARG1, typename ARG2, typename... Args>
    static RT esCallFuncAndRet(const std::function<RT(ARG0,ARG1,ARG2, Args...)> &lambda_prec, FunctionInputs&& params, size_t iIndex)
    {
      std::function<RT(Args... args)> lambda_next =
        ([&](Args... args) -> RT {           
          return lambda_prec(_GET_ARG_IND_(0),_GET_ARG_IND_(1),_GET_ARG_IND_(2), args...);         
          }
        );
      return esCallFuncAndRet(lambda_next, std::move(params),iIndex+3);
    }
    
    // std function without return
    // ---------------------------
    
    // O arg
    static void esCallFunc (const std::function<void()> &lambda_prec, FunctionInputs&& params, size_t iIndex);     

    // 1 arg
    template <typename ARG0>
    static void esCallFunc (const std::function<void(ARG0)> &lambda_prec, FunctionInputs&& params, size_t iIndex)
    { lambda_prec(_GET_ARG_IND_(0)); }
    
    // 2 args
    template <typename ARG0,typename ARG1>
    static void esCallFunc (const std::function<void(ARG0,ARG1)> &lambda_prec, FunctionInputs&& params, size_t iIndex)
    { lambda_prec(_GET_ARG_IND_(0),_GET_ARG_IND_(1)); }
    
    // 3 args and more
    template <typename ARG0, typename ARG1, typename ARG2, typename... Args>
    static void esCallFunc (const std::function<void(ARG0, ARG1, ARG2, Args...)> &lambda_prec, FunctionInputs&& params, size_t iIndex)
    {
      std::function<void(Args... args)> lambda_next =
        ([&](Args... args) -> void 
          { lambda_prec(_GET_ARG_IND_(0),_GET_ARG_IND_(1),_GET_ARG_IND_(2), args...); }
        );
      esCallFunc (lambda_next, std::move(params),iIndex+3);
    }
  };
  
} // ES

#endif // __ESFunctionPtr_Internal_h
