// COPYRIGHT DASSAULT SYSTEMES 2005

// ExportedByCATOmbConverter module header

/** @required */ 
#include "CATIAV5Level.h"

#undef ExportedByCATOmbConverter

  //-----------------------------------------------------
  //  Check that only infrastructure modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif


#define AuthorizedModuleForCATOmbConverter 888

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForCATOmbConverter  
  #error Module declared as authorized by another header  
  // Fatal error on solaris
    @error 
#endif  

// List of authorized infrastructure modules 
#define CATOmbConverter       							    AuthorizedModuleForCATOmbConverter
#define TransitionEngine                        AuthorizedModuleForCATOmbConverter
#define ConverterTST_StreamFeaAsXML             AuthorizedModuleForCATOmbConverter
#define SelectiveLoadingTST_RepRefTSTImpl       AuthorizedModuleForCATOmbConverter
#define CATOmbSelectiveLoading                  AuthorizedModuleForCATOmbConverter
#define XCADOMBConverter                        AuthorizedModuleForCATOmbConverter
#define TestXCADOMBConverter                    AuthorizedModuleForCATOmbConverter
#define XPGClientBatchUI                        AuthorizedModuleForCATOmbConverter
#define CAT3DXMLEngine                          AuthorizedModuleForCATOmbConverter
#define XPDMXMLExchangeProduct                  AuthorizedModuleForCATOmbConverter
#define CATOmbTestLib                           AuthorizedModuleForCATOmbConverter
#define CATOmbTestLib_PLM                       AuthorizedModuleForCATOmbConverter
#define XCADFormatConversionServices            AuthorizedModuleForCATOmbConverter
#define CATMultiCADRepCalculator                AuthorizedModuleForCATOmbConverter
#define CATOxiCollaborativeAccess               AuthorizedModuleForCATOmbConverter
#define CATPLMREDownwardCompatibility           AuthorizedModuleForCATOmbConverter
#define CATOmbPersistency                       AuthorizedModuleForCATOmbConverter
#define CATRepPccModel                          AuthorizedModuleForCATOmbConverter
#define CATOmbIPCS                              AuthorizedModuleForCATOmbConverter
#define CATOmbImportExportImplementations       AuthorizedModuleForCATOmbConverter
#define CATOmbImportExport                      AuthorizedModuleForCATOmbConverter

#if _MK_MODNAME_ == AuthorizedModuleForCATOmbConverter

#else

	    #error Forbidden Access To CATOmbXConverter Services from a non-infrastructure module
        // Fatal error on solaris
        @error 

#endif

#undef CATOmbConverter
#undef TransitionEngine
#undef ConverterTST_StreamFeaAsXML
#undef SelectiveLoadingTST_RepRefTSTImpl
#undef CATOmbSelectiveLoading
#undef XCADOMBConverter
#undef TestXCADOMBConverter
#undef XPGClientBatchUI            
#undef CAT3DXMLEngine 
#undef XPDMXMLExchangeProduct            
#undef CATOmbTestLib  
#undef CATOmbTestLib_PLM
#undef XCADFormatConversionServices  
#undef CATMultiCADRepCalculator  
#undef CATOxiCollaborativeAccess
#undef CATPLMREDownwardCompatibility
#undef CATOmbPersistency
#undef CATRepPccModel
#undef CATOmbIPCS
#undef CATOmbImportExportImplementations
#undef CATOmbImportExport

#if _MK_MODNAME_ == AuthorizedModuleForCATOmbConverter
  #error Declared Module has not been undeclared correctly
  // Fatal error on solaris
  @error 
#endif  

#undef AuthorizedModuleForCATOmbConverter


#if defined __CATOmbConverter
#define ExportedByCATOmbConverter DSYExport
#else
#define ExportedByCATOmbConverter DSYImport
#endif
#include "DSYExport.h"


#include "CATErrorDef.h"
