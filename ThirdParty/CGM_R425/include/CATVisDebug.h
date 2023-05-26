/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Abstract
// --------
// Declaration of macros for trace purposes
// Declaration of static functions returning variable names
//
//==============================================================================
// Usage
// -----
// dbgCATVisNewProp   : traces for new graphic properties
// dbgCATVisMaterial  : traces for materials
// dbgCATVisTexture   : traces for texture mapping
// dbgCATGviBuild     : traces for BuildRep of geometric and topologic objects
// dbgCATGviDecode    : traces for DecodeGraphic of geometric and topologic objects
// dbgCATGviModify    : traces for ModifyRep of geometric and topologic objects
//
//==============================================================================
// History
// -------
//     - Oct 22, 1999: Created.
//==============================================================================
#ifndef CATVisDebug_H
#define CATVisDebug_H

#include "CATTrace.h"
#include "SGInfra.h"

// trace for new visu properties
// -----------------------------
#ifndef DbgCATVisNewProp
ExportedBySGInfra extern CATTrace * dbgCATVisNewProp;
#else
ExportedBySGInfra CATTrace * dbgCATVisNewProp = new CATTrace("CATVisNewProp",
                                                                      "New Graphic properties");
#endif

// trace for materials
// -------------------
#ifndef DbgCATVisMaterial
ExportedBySGInfra extern CATTrace * dbgCATVisMaterial;
#else
ExportedBySGInfra CATTrace * dbgCATVisMaterial = new CATTrace("CATVisMaterial",
                                                                       "Material management");
#endif

// trace for texture mapping
// -------------------------
#ifndef DbgCATVisTexture
ExportedBySGInfra extern CATTrace * dbgCATVisTexture;
#else
ExportedBySGInfra CATTrace * dbgCATVisTexture = new CATTrace("CATVisTexture",
                                                                      "Texture management");
#endif

// trace for building geometric and topologic object reps
// ------------------------------------------------------
#ifndef DbgCATVisGeomVisu
ExportedBySGInfra extern CATTrace * dbgCATVisGeomVisu;
#else
ExportedBySGInfra CATTrace * dbgCATVisGeomVisu = new CATTrace("CATVisGeomVisu",
                                                                       "Do not use");
#endif
#ifndef DbgCATGviBuildRep
ExportedBySGInfra extern CATTrace * dbgCATGviBuildRep;
#else
ExportedBySGInfra CATTrace * dbgCATGviBuildRep = new CATTrace("CATGviBuild",
                                                                       "Building reps of topological and geometrical objects");
#endif

// trace for decoding geometric and topologic object reps
// ------------------------------------------------------
#ifndef DbgCATGviDecodeRep
ExportedBySGInfra extern CATTrace * dbgCATGviDecodeRep;
#else
ExportedBySGInfra CATTrace * dbgCATGviDecodeRep = new CATTrace("CATGviDecode",
                                                                       "Decoding reps of topological and geometrical objects");
#endif

// trace for modifing geometric and topologic object reps
// ------------------------------------------------------
#ifndef DbgCATGviModifyRep
ExportedBySGInfra extern CATTrace * dbgCATGviModifyRep;
#else
ExportedBySGInfra CATTrace * dbgCATGviModifyRep = new CATTrace("CATGviModify",
                                                                       "Modifying reps of topological and geometrical objects");
#endif





// macro returns TRUE if "trace" is set and active
// -----------------------------------------------
#define DBG_ACTIVE(trace) \
  trace && trace->IsActive()

// prints if "trace" is set and active
// -----------------------------------
#define DBG_PRINT(trace) \
  if (trace && trace->IsActive()) trace->TraPrint

// macro used at entry point of method (color on UNIX)
// ---------------------------------------------------
#ifdef _WINDOWS_SOURCE
#define DBG_ENTER(trace,class,method) \
if (trace && trace->IsActive()) \
  trace->TraPrint(2,#class"::"#method"\n")
#else
#define DBG_ENTER(trace,class,method) \
if (trace && trace->IsActive()) \
  trace->TraPrint(2,#class"::\033[31m"#method"\033[0m\n")
#endif

// macros for color prints
// -----------------------
#ifdef _WINDOWS_SOURCE
#define CRESET   ""
#define CBLACK   ""
#define CRED     ""
#define CGREEN   ""
#define CYELLOW  ""
#define CBLUE    ""
#define CMAGENTA ""
#define CCYAN    ""
#define CWHITE   ""
#else
#define CRESET   "\033[0m"
#define CBLACK   "\033[30m"
#define CRED     "\033[31m"
#define CGREEN   "\033[32m"
#define CYELLOW  "\033[33m"
#define CBLUE    "\033[34m"
#define CMAGENTA "\033[35m"
#define CCYAN    "\033[36m"
#define CWHITE   "\033[37m"
#endif

// color names
// -----------
ExportedBySGInfra extern const char * CATVisColorName    (const unsigned int iColor);
ExportedBySGInfra extern const char * CATVisLineTypeName (const unsigned int iLineType);
ExportedBySGInfra extern const char * CATVisRepTypeName  (const unsigned int iRepType);
ExportedBySGInfra extern const char * CATVisSymbolName   (const unsigned int iSymbol);

#define CATVisDumpPathElement(trace, iPath)                                     \
        if ( iPath.IsAKindOf(CATPathElement::ClassName()) )                     \
        {                                                                       \
          int sizeOfThePath = ((CATPathElement)iPath).GetSize();                \
          trace->TraPrint(2, "PathElement (%x) : ", &iPath);                    \
          for (int iii=0; iii<sizeOfThePath; iii++ )                            \
            trace->TraPrint(2, "/%s", (iPath)[iii]->IsA() );                    \
          trace->TraPrint(2, "\n");                                             \
        }                                                                       \
        else                                                                    \
        {                                                                       \
          trace->TraPrint("ATTENTION cet element N'EST PAS un PathElement.\n"); \
        }

#endif // CATVisDebug_H
