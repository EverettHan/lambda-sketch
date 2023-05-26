#ifndef __CATSysMacro
#define __CATSysMacro   42500

// COPYRIGHT DASSAULT SYSTEMES 2001

/**
* Macros used to delete or release objects 
*/

#include "JS0CORBA.h"
#include "CATSysMacroPtr.h"
#include <type_traits>

class CATBaseUnknown;
class CATMetaClass;

// ++IK8 20:04:21 New compile-time checks in order to ensure safe use of the macro CAT_DYNAMIC_CAST
#if !defined(CATMetaClassStaticCheck_Disable)

#if defined(CATDynamicCastStaticAssert_Enable) || defined(REMOVE_USELESS_INCLUDE) 
/** @nodoc compile-time error if "cond" evaluates to false */
#define CATDynamicCastCheck(cond, msg)  static_assert (cond, msg)
#else
/** @nodoc */
#define CAT_SYS_DYNAMIC_CAST_CAT(x,y) CAT_SYS_DYNAMIC_CAST_CAT1(x,y)
/** @nodoc */
#define CAT_SYS_DYNAMIC_CAST_CAT1(x,y) x##y
/** @nodoc compile-time warning if "cond" evaluates to false */
#define CATDynamicCastCheck(cond, msg) \
    struct CAT_SYS_DYNAMIC_CAST_CAT(static_warning,__LINE__) { \
        /* Define a function named "_", with 2 overloads, one of which is marked deprecated with our custom message */\
        [[maybe_unused]] constexpr void _(std::integral_constant<bool,true> const& ) {} \
        [[maybe_unused]] [[deprecated(msg)]] constexpr void _(std::integral_constant<bool,false> const& ) {} \
        /* Constructor */\
        [[maybe_unused]] constexpr CAT_SYS_DYNAMIC_CAST_CAT(static_warning,__LINE__)() { _( std::integral_constant<bool, (cond)>() ); } \
    }
#endif


/**
* Dynamic cast macro 
* CAT_DYNAMIC_CAST requires that the target class is declared with either the macro 'CATDeclareClass' or the macro 'CATDeclareInterface'
* Otherwise, it may allow invalid casts. In such dangerous cases, the following compilation warning is issued:
*       "CAT_DYNAMIC_CAST is not supported for type 'X'"...
* If you have this warning in your code, you have three options:
*   1) If applicable, change the target class of the CAT_DYNAMIC_CAST to the closest parent class that is declared with one of the macros CATDeclareClass/CATDeclareInterface
*      This should be possible if that class already declares all the members you need (virtual methods...)
*   2) Otherwise, ask the responsible of the class 'X' to consider adding these macros: (CATDeclareClass + CATImplementClass) or (CATDeclareInterface + CATImplementInterface)
*      Important: this operation may also require to update existing 'CATImplementClass/CATImplementInterface' macros in classes deriving from 'X' (to declare 'X' as their parent)
*   3) NOT RECOMMENDED, but as a last resort, you may suppress the warning by simply replacing the macro 'CAT_DYNAMIC_CAST' with 'CAT_DYNAMIC_CAST_LEGACY_DANGEROUS'
*      In this case, your code remains unprotected against potential invalid casts, which can lead to a crash of the application.
*/

#define CAT_DYNAMIC_CAST(iCATClass, iCATObject) \
    ( []() { \
        CATDynamicCastCheck(iCATClass::template SYS_OM_META_CLASS_CHECK<iCATClass>(), \
            "CAT_DYNAMIC_CAST is not supported for type '" #iCATClass "' (cf. comments in CATSysMacro.h)");\
    }(), dsy::internal::CATSysDynamicCast_t<iCATClass>(iCATObject, #iCATClass) )

#else   // CATMetaClassStaticCheck_Disable
/**
* Dynamic cast macro without compile-time validity check
*/
#define CAT_DYNAMIC_CAST(iCATClass, iCATObject) CAT_DYNAMIC_CAST_LEGACY_DANGEROUS(iCATClass, iCATObject)
#endif  // CATMetaClassStaticCheck_Disable

/**
* Legacy dynamic cast macro (no compile-time validity check)
* DO NOT USE instead of 'CAT_DYNAMIC_CAST' for new code!
* NOTE: using a "static_cast" instead of a C cast is important to disallow 
*       "iCATClass" arguments which have a "MetaObject" method, but are not derived from CATBaseUnknown
*/
#define CAT_DYNAMIC_CAST_LEGACY_DANGEROUS(iCATClass, iCATObject)    \
    static_cast<iCATClass*>(CATSysDynamicCast(iCATClass::MetaObject(), iCATObject)) // The signature taking a class name argument is used to perform runtime checks 
                                                                                    // that users of the 'CAT_DYNAMIC_CAST_LEGACY_DANGEROUS' macro explicitly choose to disable
// ++IK8 20:04:21



/**
* @deprecated Use C++ static_cast instead
* Macro used to make a static cast on a pointer
*/
#ifndef CNEXT_CLIENT
#define CAT_STATIC_CAST(iCATClass,iCATObject) (iCATClass*)CATSysStaticCast(iCATClass::MetaObject(), iCATObject)
#else
// Default branch - DO NOT USE!!! Use C++ static_cast instead
#define CAT_STATIC_CAST(iCATClass, iCATObject) (iCATClass*)iCATObject
#endif



ExportedByJS0CORBA CATBaseUnknown const* CATSysDynamicCast( CATMetaClass const* iClass, CATBaseUnknown const* iObject );
inline CATBaseUnknown * CATSysDynamicCast( CATMetaClass const* iClass, CATBaseUnknown * iObject ) { // For compatibility with code calling 'CATSysDynamicCast' directly 
    return const_cast<CATBaseUnknown *>(CATSysDynamicCast(iClass, const_cast<CATBaseUnknown const*>(iObject)));
}
/** @nodoc DO NOT call directly - to be used by CAT_DYNAMIC_CAST macro */
ExportedByJS0CORBA CATBaseUnknown const* CATSysDynamicCast( CATMetaClass const* iClass, CATBaseUnknown const* iObject, char const*iClassName );



/**
* CATOMDynamicCast.
* This function is an alternative to the C++ 'dynamic_cast', which is not supported by default in our code base.
* It allows to safely convert pointers to CATBaseUnknown-derived classes down along the inheritance hierarchy (downcast).
* The target class is required to be declared with either the macro 'CATDeclareClass' or the macro 'CATDeclareInterface'.
*/
template<typename _Ty>
inline _Ty CATOMDynamicCast( CATBaseUnknown const* iObject ) {
    static_assert(std::is_pointer<_Ty>::value, "CATOMDynamicCast only supports pointer types.");
    using _TyClass = typename std::remove_cv<typename std::remove_pointer<_Ty>::type>::type;
    static_assert(std::is_base_of<CATBaseUnknown, _TyClass>::value && !std::is_same<CATBaseUnknown, _TyClass>::value, "CATOMDynamicCast only supports CATBaseUnknown-derived types.");
    static_assert(_TyClass::template SYS_OM_META_CLASS_CHECK<_TyClass>(), "CATOMDynamicCast is not supported (cf. comments in CATSysMacro.h)");
    return static_cast<_Ty>(CATSysDynamicCast(_TyClass::MetaObject(), iObject));
}
template<typename _Ty>
inline _Ty CATOMDynamicCast( CATBaseUnknown * iObject ) {
    static_assert(std::is_pointer<_Ty>::value, "CATOMDynamicCast only supports pointer types.");
    using _TyClass = typename std::remove_cv<typename std::remove_pointer<_Ty>::type>::type;
    static_assert(std::is_base_of<CATBaseUnknown, _TyClass>::value && !std::is_same<CATBaseUnknown, _TyClass>::value, "CATOMDynamicCast only supports CATBaseUnknown-derived types.");
    static_assert(_TyClass::template SYS_OM_META_CLASS_CHECK<_TyClass>(), "CATOMDynamicCast is not supported (cf. comments in CATSysMacro.h)");
    return static_cast<_Ty>(const_cast<CATBaseUnknown *>(CATSysDynamicCast(_TyClass::MetaObject(), iObject)));
}


namespace dsy
{
  namespace internal  // Internal use only
  {
    
    /** 
     * @nodoc CATSysDynamicCast_t. 
     * DO NOT call directly! Internal functions, used to implement the macro CAT_DYNAMIC_CAST.
     * NOTE: using a "static_cast" instead of a C cast is important to disallow 
     *       "_Ty" types which have a "MetaObject" method, but are not derived from CATBaseUnknown
     */
    template<typename _Ty>
    inline _Ty const* CATSysDynamicCast_t( CATBaseUnknown const* iObject, char const* iClassName ) {
        return static_cast<_Ty const *>(CATSysDynamicCast(_Ty::MetaObject(), iObject, iClassName));
    }
    template<typename _Ty>
    inline _Ty * CATSysDynamicCast_t( CATBaseUnknown * iObject, char const* iClassName ) {
        return static_cast<_Ty *>(const_cast<CATBaseUnknown *>(CATSysDynamicCast(_Ty::MetaObject(), iObject, iClassName)));
    }
    
  }   // namespace internal
}   // namespace dsy

ExportedByJS0CORBA CATBaseUnknown* CATSysStaticCast( CATMetaClass const* iClass, CATBaseUnknown* iObject );



#endif  // __CATSysMacro
