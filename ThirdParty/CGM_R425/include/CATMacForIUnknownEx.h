#ifndef __CATMacForIUnknownEx
#define __CATMacForIUnknownEx

#include "CATMacForIUnknown.h"

/**
 * @nodoc
 * Functionally equivalent to the macro 'CATDeclareClass' defined in CATMacForIUnknown.h, 
 * but with the ability to finely manage export rules. 
 * This is useful for library classes that are not being globally exported.
 * The class must derive from CATBaseUnknown (cf. 'override' specifier).
 * Use this macro in the class header file in conjunction with @href CATImplementClass
 * in the class source (.cpp) file.
 * End it with a semicolon.
 * ExportedByV: manage export for virtual member functions.
 *      When the compiler can infer the exact type of an object, it can devirtualize virtual functions calls
 *      In such cases, exporting the virtual member functions is likely to be required
 * ExportedBy:  export macro for the non-virtual member functions.
 */
#define CATDeclareClass_CustomExport(ExportedBy, ExportedByV)       \
                                                                    \
private:                                                            \
   CATMetaClassStaticCheck                                          \
public:                                                             \
   ExportedByV /*virtual*/ CATMetaClass *  __stdcall GetMetaObject() const override;        \
   ExportedByV /*virtual*/ const char *              IsA() const override;                  \
   ExportedByV /*virtual*/ int                       IsAKindOf(const char *) const override;\
   ExportedBy static CATMetaClass *   __stdcall MetaObject();       \
   ExportedBy static const CLSID &    __stdcall ClassId();          \
   ExportedBy static const char *     __stdcall ClassName();        \
   ExportedBy static CATBaseUnknown *CreateItself()

#endif  // __CATMacForIUnknownEx
