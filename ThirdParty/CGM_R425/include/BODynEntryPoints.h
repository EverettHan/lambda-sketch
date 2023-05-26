/* -*-c++-*- */
// @quickReview PTO 20220310 R424AssessedForLinux CTF_ENTRYPOINT
#ifndef BODynEntryPoints_h_
#define BODynEntryPoints_h_
   

#ifndef NULL
#define NULL 0
#endif

#include "CATGetEntryPoint.h"
#include "CATCGMOutput.h"


// Les Librairies (Old & New Modeler sauf pour le sweep)

#if defined (_AIX)
#define CATIALibraryName   "libCATTopDynamicOpe.a"
#define CNEXTLibraryName   "libCATTopologicalOperators.a"
#endif
#if defined (_IRIX_SOURCE) 
#define CATIALibraryName   "libCATTopDynamicOpe.so"
#define CNEXTLibraryName   "libCATTopologicalOperators.so"
#endif
#if defined (_WINDOWS_SOURCE) 
#define CATIALibraryName   "CATTopDynamicOpe.dll"
#define CNEXTLibraryName   "CATTopologicalOperators.dll"
#endif
#if defined(_SUNOS_SOURCE)
#define CATIALibraryName   "libCATTopDynamicOpe.so"
#define CNEXTLibraryName   "libCATTopologicalOperators.so"
#endif
#if defined(_HPUX_SOURCE)
#define CATIALibraryName   "libCATTopDynamicOpe.sl"
#define CNEXTLibraryName   "libCATTopologicalOperators.sl"
#endif
#if defined (_LINUX_SOURCE) 
#define CATIALibraryName   "libCATTopDynamicOpe.so"
#define CNEXTLibraryName   "libCATTopologicalOperators.so"
#endif
#if defined (_DARWIN_SOURCE) 
#define CATIALibraryName   "libCATTopDynamicOpe.dylib"
#define CNEXTLibraryName   "libCATTopologicalOperators.dylib"
#endif
#if defined(_ANDROID_SOURCE)
#define CATIALibraryName   "libCATTopDynamicOpe.so"
#define CNEXTLibraryName   "libCATTopologicalOperators.so"
#endif

#ifndef _STATIC_SOURCE
#ifndef CATIALibraryName
#error Dynamic loading: Unsupported OS
#endif
#endif
 
// Macro d'Erreurs
#include "TopologicalOperatorsInternalError.h"
#include "TopologicalOperatorsErrors.h"

#define ERRORDynLoading(libraryname,entrypointname)                  \
cgmerr    << "** GeoOperator Dynamic Binding ERROR : "                 \
<< cgmendl << "** cannot find symbol " << entrypointname                \
        << " of library " << libraryname << cgmendl;                    \
TopologicalOperatorsInternalError * Error =                          \
new TopologicalOperatorsInternalError (GBIntEInvalidTopoMethodCall); \
CATThrow (Error)


#define ERRORDynUnknownBinding                                            \
cgmerr<< "** GeoOperator Dynamic Binding ERROR : unknown binding "<<cgmendl;   \
TopologicalOperatorsInternalError * Error =                               \
new TopologicalOperatorsInternalError (GBIntEInvalidTopoMethodCall);      \
CATThrow (Error)



   
// Macro pour les DynCreate ...     
#define MacForDynCreateWithLibs(NameFuncChosen,NameFuncType,NamePtrContainer,NameEntryPointV4,NameLibV4,NameEntryPointV5,NameLibV5)  \
  static NameFuncType  FuncOnImplCATIA = NULL;                                        \
  static NameFuncType  FuncOnImplV5 = NULL;                                           \
  CATImplementationMode mod = BODynFindMode(NamePtrContainer);                        \
  if (mod == CATIAMODE) {                                                             \
    if (FuncOnImplCATIA)      FuncChosen = FuncOnImplCATIA;                           \
      else {                                                                          \
      LibraryHandler libhdl = CATGetEntryPoint (NameLibV4,NameEntryPointV4);          \
      if (!libhdl.EntryPoint) {                                                       \
        ERRORDynLoading(NameLibV4,NameEntryPointV4);                                  \
        return NULL; }                                                                \
      FuncOnImplCATIA = (NameFuncType) libhdl.EntryPoint;                             \
      FuncChosen = FuncOnImplCATIA;  }   }                                            \
  else if (mod == CNEXTMODE)   {                                                      \
    if (FuncOnImplV5)      FuncChosen = FuncOnImplV5;                                 \
      else {                                                                          \
      LibraryHandler libhdl = CATGetEntryPoint (NameLibV5,NameEntryPointV5);          \
      if (!libhdl.EntryPoint) {                                                       \
        ERRORDynLoading(NameLibV5,NameEntryPointV5);                                  \
        return NULL; }                                                                \
      FuncOnImplV5    = (NameFuncType) libhdl.EntryPoint;                             \
      FuncChosen = FuncOnImplV5;  } }                                                 \
  if (!FuncChosen)    {  ERRORDynUnknownBinding;    return NULL; }     


#define MacForDynCreate(NameFuncChosen,NameFuncType,NamePtrContainer,NameEntryPointV4,NameEntryPointV5)  \
MacForDynCreateWithLibs(NameFuncChosen,NameFuncType,NamePtrContainer,NameEntryPointV4,CATIALibraryName,NameEntryPointV5,CNEXTLibraryName)  

#endif
