
// DO NOT USE WITHOUT THE AGREEMENT OF THE SYSTEM TEAM

#ifndef CATXHCompatMacros_H
#define CATXHCompatMacros_H

#include "CATErrorMacrosEx.h"   // CATXH_CXX_UNWINDING_ON_CATTHROW


#if (CATXH_CXX_UNWINDING_ON_CATTHROW != 0)
/**
 * !!! DO NOT USE WITHOUT THE AGREEMENT OF THE SYSTEM TEAM !!!
 * Macros to help optimize performance on platforms with Unwinding enabled (CATXH_CXX_UNWINDING_ON_CATTHROW != 0), 
 * for code which still has to support Releases/Platforms with Unwinding still disabled (CATXH_CXX_UNWINDING_ON_CATTHROW == 0)
 * => Transitional need
 *
 * CATXH_ENSURE_RELEASE / CATXH_ENSURE_DELETE / CATXH_ENSURE_DELETE_ARRAY / CATXH_ENSURE_DELETE_CUSTOM:
 *   Respectively ensure Release / delete / delete[] / "CustomDelete" of the pointer "var_ptr" at the end of the C++ scope, 
 *   in case of: normal control flow, exception (CATThrow, C++ exception)
 *   If the pointer gets "freed" manually before the end of the scope, it MUST be reset to NULL in order to avoid double freeing.
 *   If the pointer is (already) NULL when the control flow reaches the end of scope, CATXH_ENSURE_XXX macros have no effect.
 * 
 * CATXH_REGAIN_OWNERSHIP:
 *   Regain control over the lifecycle of the object pointed by "var_ptr", previously managed by one of the CATXH_ENSURE_XXX macros
 *   => Mandatory to be able to safely return "var_ptr" to the caller.
 * 
 * Remarks: 
 * - why not to use std::auto_ptr/std::unique_ptr?
 *   One reason is that these objects do not support being marked "volatile", which might still be required on some platforms during the transitional phase
 *   Using them also requires deeper rewrite of the code, which is not necessarily desired on levels under maintenance, with Unwinding still disabled (CATXH_CXX_UNWINDING_ON_CATTHROW == 0)
 */

#if !defined(_AIX_SOURCE) || defined(__ibmxl__)
#define CATXH_TYPE_OF(var)  decltype(var)
#else
#define CATXH_TYPE_OF(var)  __typeof__(var)
#endif

#define CATXH_ENSURE_RELEASE(var_ptr) \
    detail::CATXHSmartPointer<CATXH_TYPE_OF(var_ptr), detail::ReleasePtr> var_ptr##_cleaner(var_ptr)

#define CATXH_ENSURE_DELETE(var_ptr) \
    detail::CATXHSmartPointer<CATXH_TYPE_OF(var_ptr), detail::DeletePtr> var_ptr##_cleaner(var_ptr)

#define CATXH_ENSURE_DELETE_ARRAY(var_ptr) \
    detail::CATXHSmartPointer<CATXH_TYPE_OF(var_ptr), detail::DeleteArray> var_ptr##_cleaner(var_ptr)

#define CATXH_ENSURE_DELETE_CUSTOM(var_ptr, deleter) \
    detail::CATXHSmartPointerCustomDeleter<CATXH_TYPE_OF(var_ptr), CATXH_TYPE_OF(deleter)> var_ptr##_cleaner(var_ptr, deleter)

#define CATXH_REGAIN_OWNERSHIP(var_ptr)    var_ptr##_cleaner.release()
    
#endif  // CATXH_CXX_UNWINDING_ON_CATTHROW



namespace detail
{
    template<typename T>
    inline void ReleasePtr(T *ptr) {
        ptr->Release();
    }
    
    template<typename T>
    inline void DeletePtr(T *ptr) {
        delete ptr;
    }
    
    template<typename T>
    inline void DeleteArray(T *ptr) {
        delete[] ptr;
    }
    
    template<typename TPtr>
    struct CATXHSmartPointerBase
    {
        CATXHSmartPointerBase(TPtr &ptr) : m_pptr(CATXH_AddressOf(ptr)) {
        }    
        TPtr release() {
            if(!m_pptr) return NULL;
            TPtr ptr = *m_pptr;
            m_pptr = NULL;
            return ptr;
        }
    protected:
        // Members
        TPtr * m_pptr;
    };
    
    template<typename TPtr, void(*DelFunc)(TPtr)>
    struct CATXHSmartPointer : public CATXHSmartPointerBase<TPtr>
    {
        CATXHSmartPointer(TPtr &ptr) : CATXHSmartPointerBase<TPtr>(ptr) {
        }
        ~CATXHSmartPointer() {
            if(!this->m_pptr) return;
            if(*this->m_pptr) {
                DelFunc(*this->m_pptr);
                *this->m_pptr = NULL;
            }
        }
    };  // CATXHSmartPointer
    
    template<typename TPtr, typename PDeleter>
    struct CATXHSmartPointerCustomDeleter : public CATXHSmartPointerBase<TPtr>
    {        
        CATXHSmartPointerCustomDeleter(TPtr &ptr, PDeleter ipDeleter)
            : CATXHSmartPointerBase<TPtr>(ptr), m_pdel(ipDeleter) {
        }
        ~CATXHSmartPointerCustomDeleter() {
            if(!this->m_pptr) return;
            if(*this->m_pptr) {
                (*m_pdel)(*this->m_pptr);
                *this->m_pptr = NULL;
            }
        }
    private:
        PDeleter m_pdel;
    };  // CATXHSmartPointerCustomDeleter
    
    
}   // namespace detail


#endif  // CATXHCompatMacros_H
