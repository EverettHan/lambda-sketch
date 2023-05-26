
#ifndef CATMacForIUnknownChecked_H
#define CATMacForIUnknownChecked_H  42500

#include "CATMacForIUnknown.h"  // CATImplementClass, CATImplementInterface...

#if 0//(__CATMacForIUnknown > 42500)  
// Official macros now include the additional buildtime checks
#else   // "Overload" official macros to add compile-time checks

/** 
 * @nodoc
 * Implement checks for the "CATImplementClass" macro
 */
#undef ToCreateMetaObject   // Use this internal sub-macro as a hook
#define ToCreateMetaObject(Class,Typeofclass,Basemeta,Impmeta)        \
    /* Note that (BaseMeta = CATNull) is allowed, even if it is not advised */ \
    static_assert((dsy::internal::is_accessible_base_of<Basemeta, Class>() || std::is_same<Basemeta, CATNull>::value), \
    "[CATImplementClass] 3rd argument \"" #Basemeta "\" is not a valid \"BaseMeta\" because it is not a parent C++ class of \"" #Class "\"");\
    /* Note that (BaseMeta = CATNull) is allowed, even if it is not advised */ \
    static_assert((dsy::internal::is_accessible_base_of<CATBaseUnknown, Basemeta>() || std::is_same<Basemeta, CATNull>::value), \
        "[CATImplementClass] 3rd argument \"" #Basemeta "\" is not a valid \"BaseMeta\" because it does not derive from CATBaseUnknown");\
    /* Don't enforce that (yet?): static_assert((dsy::internal::is_accessible_base_of<CATBaseUnknown, Class>()),"[CATImplementClass] 1st argument \"" #Class "\" is not valid because it is not deriving from CATBaseUnknown");*/ \
    meta_object = dsy::internal::fct_RetrieveMetaObject(#Class,Typeofclass,        \
                     Basemeta::MetaObject(),#Impmeta,CATLicenseOptionId,sizeof(Class))


/** 
 * @nodoc
 * Implement checks for the "CATImplementInterface" macro
 */
#undef CATBeginImplementInterface
#define CATBeginImplementInterface(Class, Basemeta, Alias)  \
                                                            \
CATMacMetaObjectMethodProlog(Class)                         \
                                                            \
    /* Check that "CNext inheritance" is related to "C++ inheritance" for proper RTTI support */ \
    static_assert((dsy::internal::is_accessible_base_of<Basemeta, Class>() || std::is_same<Basemeta, CATNull>::value), "[CATImplementInterface] 2nd argument \"" #Basemeta "\" is not a valid \"BaseMeta\" because it is not a parent C++ class of \"" #Class "\"");                                           \
    meta_object = new CATMetaClass(&IID_##Class,#Alias,     \
                     Basemeta::MetaObject(),nullptr,        \
                     TypeOfClass::Interfaces)

#endif  // __CATMacForIUnknown


#if (__CATMacForIUnknown <= 42500)
namespace dsy
{
    namespace internal  // Internal use only
    {
        template <typename _TyBase, typename _Tz>
        using is_accessible_base_of
            = std::integral_constant<bool, std::is_base_of<_TyBase, _Tz>::value 
            && std::is_convertible<_Tz*, _TyBase*>::value>;
    }
}
#endif

#endif  // CATMacForIUnknownChecked_H
