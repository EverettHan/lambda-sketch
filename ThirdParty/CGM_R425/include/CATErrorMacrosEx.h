
#ifndef CATErrorMacrosEx_H
#define CATErrorMacrosEx_H 42500

#include "CATErrorMacros.h" // Public header
// Header for specifics not to expose in the CAA SDK


/** @nodoc Manages the lifecycle of the exception object automatically (compared to CATCatch) */
#define CATCatchByRef(errclass,errobj)  } catch (CATException<errclass> const & _spErr_##errobj) {\
                                            errclass & errobj = *static_cast<errclass *>(CATXHContextCxx::CatchBlockProlog(/*&_xhctx_*/nullptr,0,_spErr_##errobj));\
                                            CATXH_VAR_SUPPRESS_WARN(_ctxtCatch_, CATError *const _ctxtCatch_ = CATXH_AddressOf(errobj););\
                                            using CATErrorMacrosTrue::__CATCatchBlockType__;


/**
 * CATXH_ENSURE_DESTRUCTION.
 * Allows to register an automatic object to make sure it gets destroyed in any case (especially in case of exception)
 * Only useful for automatic objects that manage resources (memory, locks...), or whose destructors have side effects.
 * For e.g., it would be useless for std::atomic<int>.
 * Recommended to fix a memory leaks related to a small set of automatic objects, when the function hasn't got any CATCatch/CATRethrow already.
 * 
 * Sample:
 * 
 *  void Function(CATBaseUnknown *iParam)
 *  {
 *      CATISpecObject_var spObject = iParam;
 *      CATXH_ENSURE_DESTRUCTION(spObject);
 *      // To avoid memory leaks (MLK) related to an automatic object in case of exception, 
 *      // the CATXH_ENSURE_DESTRUCTION macro can be used as shown above right after its initialization
 *      // Please note that other techniques can be used for the same purpose.
 * 
 *      if (...) {
 *          spObject->Update();    // May throw, in which case CATXH_ENSURE_DESTRUCTION ensures automatic destruction of the object
 *      }
 * 
 *      DoAdditionalStuff(spObject);
 *      
 *      // If no exception was raised, "spObject" is destroyed normally at the end of the scope
 *  }
 */



#include "JS0ERROR.h"   // ExportedByJS0ERROR
#include <cstddef>      // std::nullptr_t
#if defined(_CATXH_FindAllNested_Supported)
#include <functional>   // std::function
#endif

#if (0 != CATXH_CXX_SUPPORT)   // Requires C++ Exception Handling to be enabled! (compiler)
# include <exception>    // std::exception_ptr, std::current_exception, std::rethrow_exception
# if defined(_CATXH_FindAllNested_Supported)
#  include "DSYSysCxxExceptionHelpers.h"  // DSY::Find_all_nested
# endif
# define _CATXH_EXCEPTION_PTR_CXX_Supported
#endif


namespace detail
{
#if defined(_CATXH_FindAllNested_Supported)
    ExportedByJS0ERROR bool __CATErrorChainEnumerate(CATError *err, std::function<bool(CATError &, int)> iFunc, const char *iCATErrorTypeName);
#endif


#if defined(_CATXH_EXCEPTION_PTR_CXX_Supported)
    /** @nodoc */
    class _CATXH_EXCEPTION_PTR_CXX
    {
    public: 
        _CATXH_EXCEPTION_PTR_CXX() = delete;
        _CATXH_EXCEPTION_PTR_CXX(const _CATXH_EXCEPTION_PTR_CXX & iOther) = delete;
        _CATXH_EXCEPTION_PTR_CXX & operator= ( const _CATXH_EXCEPTION_PTR_CXX & iOther ) = delete;
        
        _CATXH_EXCEPTION_PTR_CXX(std::nullptr_t) : m_ptr(nullptr) {}
        
        _CATXH_EXCEPTION_PTR_CXX(const std::exception_ptr & iPtr) : m_ptr(iPtr) {
        }
        ~_CATXH_EXCEPTION_PTR_CXX() {
            m_ptr = nullptr;
        };// = default;
        _CATXH_EXCEPTION_PTR_CXX(_CATXH_EXCEPTION_PTR_CXX && iOther) noexcept = default;
        _CATXH_EXCEPTION_PTR_CXX & operator= ( _CATXH_EXCEPTION_PTR_CXX && iOther ) = default;
        operator bool () const { return static_cast<bool>(m_ptr); }
        
        // If not defined inline, VS2017 does not generate proper code... (leak of exception object)
        [[noreturn]] static void Rethrow(const _CATXH_EXCEPTION_PTR_CXX & eptr)
        {
            // By contract, eptr must not be null! Otherwise, undefined behavior! (cf. noreturn attribute)
            // CATRethrow: for compatibility, make sure virtual function overrides Throw/OnBeforeThrow are called
            // => Disable if possible, because PCS impact!
        // #define _CATXH_EXCEPTION_PTR_CXX_COMPAT
        #if defined(_CATXH_EXCEPTION_PTR_CXX_COMPAT)
            CATTry {    // WARNING: definition of these macros depend on the define NATIVE_EXCEPTION
        #endif
                std::rethrow_exception(eptr.m_ptr);
        #if defined(_CATXH_EXCEPTION_PTR_CXX_COMPAT)
            } CATCatchOthers {
                CATRethrow;
            } CATEndTry
        #endif
        }
        
        static _CATXH_EXCEPTION_PTR_CXX make_exception_ptr(CATError *e) noexcept;
        
#if defined(_CATXH_FindAllNested_Supported)
        template<typename T, typename Callable>
        static auto FindAllNested(const _CATXH_EXCEPTION_PTR_CXX & eptr, Callable&& iFunc) noexcept
            -> typename std::enable_if<std::is_base_of<CATError,T>::value, bool>::type  // T must be a CATError-derived type
        {
            if(!eptr)
                return false;
            
            // Implementation suitable in case CATError::Throw calls std::throw_with_nested
            static bool bThrowWithNested = false;   // For tests in the debugger
            if(bThrowWithNested)
            {
                auto eptr_1 = eptr.m_ptr;
                return DSY::Find_all_nested<CATException<T>>([&iFunc](CATException<T> & iErr, int level) -> bool {
                        return iFunc(*static_cast<T *>(iErr.get_CATError()), level);
                    }, 
                    [eptr_1]() { std::rethrow_exception(eptr_1); }
                );
            }
            
            // Implementation based on error chaining (valid in both longjmp and NATIVE_EXCEPTION modes)
            CATTry { std::rethrow_exception(eptr.m_ptr); }
            CATCatchByRef(CATError, err) {
                return __CATErrorChainEnumerate(CATXH_AddressOf(err), [&iFunc](CATError & iErr, int level) -> bool {
                    return iFunc(static_cast<T &>(iErr), level);
                }, T::ClassName());
            } CATEndTry
            return false;
        }   // FindAllNested
#endif   // _CATXH_FindAllNested_Supported
        
    private:
        std::exception_ptr m_ptr;
    };

    inline _CATXH_EXCEPTION_PTR_CXX _CATXH_EXCEPTION_PTR_CXX::make_exception_ptr(CATError *e) noexcept
    {
        try {
            // "raise" allows to support polymorphism by generating an exception of the exact object's type
            if(e) e->raise(); // Don't use "CATThrow" to avoid OnBeforeThrow callback and other useless stuff...
        } catch(...) {
            return std::current_exception();
        }
        // To make this more efficient, would require a virtual method defined by CATDeclareError:
        // virtual CATXH_EXCEPTION_PTR make_exception_ptr() const { return std::make_exception_ptr(thisClass::ThrowSmartPtr(this)); }
        return nullptr;
    }
#endif  // _CATXH_EXCEPTION_PTR_CXX_Supported
    
}   // namespace detail






/**
 * WARNING: CATXH_CURRENT_EXCEPTION is NOT supported in CATCatch blocks for lifecycle reasons!
 * Sample:
 * 
 *  CATXH_EXCEPTION_PTR eptr = nullptr;
 *  {
 *      // Local variables (automatic objects...)
 *      CATTry {
 *          funcThatMayThrow();
 *      } CATCatchOthers {
 *          // Capture the exception object
 *          eptr = CATXH_CURRENT_EXCEPTION();
 *      } CATEndTry
 *      // End of the scope: automatic destruction of local variables
 *  }
 *  if(eptr)
 *      CATXH_RETHROW_EXCEPTION(eptr);  // Rethrow exception if any
 */
#if defined(_CATXH_EXCEPTION_PTR_CXX_Supported)

using CATXH_EXCEPTION_PTR = detail::_CATXH_EXCEPTION_PTR_CXX;
// C++ lambda is required to be able to access the "_xhFlags_" variable which is expected to be defined in CATCatchXXX blocks
//   => replaced by using directive to avoid additional local variable declarations
#define CATXH_CURRENT_EXCEPTION         []() -> CATXH_EXCEPTION_PTR {                   \
                                            /*static_assert(!(_xhFlags_ & 0x01), "CATXH_CURRENT_EXCEPTION is supported only in CATCatchByRef/CATCatchOthers!");*/\
                                            static_assert(__CATCatchBlockType__, "CATXH_CURRENT_EXCEPTION is supported only in CATCatchByRef/CATCatchOthers!");\
                                            return std::current_exception();            \
                                        }

inline void CATXH_RETHROW_EXCEPTION [[noreturn]] (const CATXH_EXCEPTION_PTR & eptr)
{
    CATXH_EXCEPTION_PTR::Rethrow(eptr);
}

inline CATXH_EXCEPTION_PTR CATXH_MAKE_EXCEPTION_PTR(CATError *e) noexcept
{
    return CATXH_EXCEPTION_PTR::make_exception_ptr(e);
}
// inline CATXH_EXCEPTION_PTR CATXH_MAKE_EXCEPTION_PTR(const std::current_exception & eptr) noexcept

#endif  // _CATXH_EXCEPTION_PTR_CXX_Supported



#endif  // CATErrorMacrosEx_H
