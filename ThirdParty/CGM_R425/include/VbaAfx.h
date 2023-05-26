#ifndef VbaAfx_h
#define VbaAfx_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATVBAInfra.h"
#include "CATVBAInclude.h"
#include "CATVBACodeMacro.h"

/**
 * Component declarations necessary for an MFC-APC application
 */
 
//---------------------------------------------------------------------------
// MFC Integration Start

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxtempl.h>		// MFC templates
#include <afxole.h>			// MFC OLE 2 support
#include <afxdocob.h>
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxcmn.h>			// MFC support for Windows Common Controls

// MFC Integration End
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// ATL Integration Start

/** @c++ansi fbq 2004-08-02.20:05:17 [Useless with VC++7.1] **/
#if !defined(_DS_VBAIntegrationIsOutProcess) && !defined (_ATL_APARTMENT_THREADED) // -JBX 3.2012 VBA7 Migration 
// Define threading model for the ATL module.
#define _ATL_APARTMENT_THREADED
#endif

// Load ATL declarations
#include "Atlbase.h"

// Create a custom ATL CComModule to work with MFC
#pragma warning( push )
#pragma warning( disable : 4275 )
class ExportedByCATVBAInfra CATAtlMfcModule: public CComModule /*CAtlMfcModule*/ {
	public:
		LONG Lock() noexcept;
		LONG Unlock() noexcept;
};
#pragma warning( pop )


// Declare the ATL global _Module variable. Must come before Atlcom.h
// inclusion.
extern ExportedByCATVBAInfra CATAtlMfcModule _Module;

#include "Atlcom.h"

// ATL Integration End
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// APC Integration Start

// Required to use the MFC-APC ApcDual classes 
// #pragma push_macro("ASSERT")
// #include "CATAssert.h"
// #undef ASSERT
// #define ASSERT  CATAssert
// #include "ApcDual.h"
// #pragma pop_macro("ASSERT")

// Specifies the options to pass to #import "mso9d.dll"
// made in the apc.h VBA header file. FULL can be used
// when Visual C++ version is >= 5.0
//#define APC_IMPORT_FULL
#define APC_IMPORT_MIDL

// The CAT_DEFINE_VBA_GUIDS can be used to generate the
// definition of common VBA and APC UUIDS.
#ifdef CAT_DEFINE_VBA_GUIDS
#include "initguid.h"
#endif

// ++IK8 20:11:17 Bypass for build errors due to the definition of a macro named "Ctrl" in the Dialog header:
//   Dialog/PublicInterfaces/CATDlgKeySym.h 
// Indeed, "Ctrl" is the name of a parameter in the VBA SDK header <msotl.h> (included by APC Integration headers below)
// Should the Dialog macro be needed, ask for another one with a stronger name...
#pragma push_macro("Ctrl")  // Backup macro named "Ctrl" (if applicable)
#undef Ctrl
// ++IK8 20:11:17 
#pragma warning( push )
#pragma warning( default : 4355 )   // cf. official CATWarningPromote.h that promotes this warning to an error

// Load APC declarations
#include "ApcMfc.h"

#pragma warning( pop )

// ++IK8 20:11:17 Restore macro named "Ctrl" (if applicable)
#pragma pop_macro("Ctrl")
// ++IK8 20:11:17

// Access declarations of the APC component
using namespace MSAPC;
using namespace VBIDE;


//---------------------------------------------------------------------------
// DS Header files

#include "DSYStringHelperATL.h" // DSY::CUSFrom, DSY::ATLCStringFrom

#define APC_USE_STL // For ApcImpl.cpp

// APC Integration End
//---------------------------------------------------------------------------

#endif



