#ifndef CSITemplateExport_H
#define CSITemplateExport_H

// On LINUX
// Since R422 GCC supports C++ standard
// Header file:   extern template class MyTemplateClass<MyType>;
// Cpp file:      template class MyTemplateClass<MyType>;

// Note: Before R422, it was mandatory to set visibility attribute because of the mkmk default
// -fvisibility=hidden flag, else the symbol was not exported leading to link failure.
// Since 422 GCC now automatically exports template instantiation declared with extern.
// Using the visibility attribute is now redundant and raises a warning.

// ON MAC/ANDROID
// Visibility attribute is still mandatory as of now (422), else the link will fail
// Header file:   extern template class __attribute__((visibility("default"))) MyTemplateClass<MyType>;
// Cpp file:      template class MyTemplateClass<MyType>;

// On WINDOWS
// We need to specify the export flag for the definition (cpp file)
// Header file:   extern template class MyTemplateClass<MyType>;
// Cpp file:      template class __declspec(dllexport) MyTemplateClass<MyType>;

// On iOS
// Link is static so export is irrelevant

// Using CSITemplateExport just write:
// Header file: extern template TemplateDeclExport class MyTemplateClass<MyType>;
// Cpp file: template class TemplateDefExport MyTemplateClass<MyType>;

#define TemplateDeclExport

#if (defined(_DARWIN_SOURCE) || defined(_ANDROID_SOURCE))
#undef TemplateDeclExport
#define TemplateDeclExport __attribute__((visibility("default")))
#endif

#define TemplateDefExport

#ifdef _WINDOWS_SOURCE
#undef TemplateDefExport
#define TemplateDefExport DSYExport
#endif /*_WINDOWS_SOURCE*/

#include "DSYExport.h"

#endif
