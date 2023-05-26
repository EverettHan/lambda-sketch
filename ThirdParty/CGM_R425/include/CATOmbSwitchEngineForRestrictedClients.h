// COPYRIGHT DASSAULT SYSTEMES 2005

// ExportedByCATOmbSwitchEngine module header

/**
* @level Private
* @usage U3
*/


#undef ExportedByCATOmbSwitchEngine

//-----------------------------------------------------
//  Check that only infrastructure modules can link on the exported symbols
//----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error

#endif


#define AuthorizedModule 999


// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModule  
#error Module declared as authorized by another header
// Fatal error on solaris
@error
#endif  


// List of authorized infrastructure modules

#define CATOmbSwitchEngine                            AuthorizedModule
#define CATOmbDebugWorkshop                           AuthorizedModule
#define CATAssUpdCoreActors                           AuthorizedModule
#define CATAssUpdEngine                               AuthorizedModule
#define CATDbdImportModeler                           AuthorizedModule
#define CATOmbSelectiveLoading                        AuthorizedModule
#define CATOmbTransientServices                       AuthorizedModule
#define CATSbmTDM                                     AuthorizedModule
#define CATPLMUpdateServices                          AuthorizedModule
#define CATPLMIntegration                             AuthorizedModule
#define CATFmtToolsServices                             AuthorizedModule

#define SelectiveLoadingTST_OmbRepRefMultiSD_PLMx	    AuthorizedModule
#define SelectiveLoadingTST_RepRefTSTImpl             AuthorizedModule
#define PLMStreamDescriptor_TestSynchroStamp          AuthorizedModule
#define MfImportPLMTest                               AuthorizedModule //ODT MechMod
#define CATOxiCollaborativeAccess                     AuthorizedModule
#define CATOmbTestLib_PLM                             AuthorizedModule
#define CATOxiMigrateXPDMToV6                         AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To CATOmbSwitchEngine Services from a non-infrastructure module
// Fatal error on solaris
@error

#endif

#undef CATOmbSwitchEngine
#undef CATOmbDebugWorkshop
#undef CATAssUpdCoreActors 
#undef CATAssUpdEngine
#undef CATSbmTDM
#undef CATDbdImportModeler
#undef CATOmbSelectiveLoading
#undef CATOmbTransientServices
#undef CATPLMUpdateServices
#undef CATPLMIntegration 
#undef CATFmtToolsServices 

#undef SelectiveLoadingTST_RepRefTSTImpl
#undef MfImportPLMTest //ODT MechMod
#undef SelectiveLoadingTST_OmbRepRefMultiSD_PLMx
#undef PLMStreamDescriptor_TestSynchroStamp
#undef CATOxiCollaborativeAccess
#undef CATOmbTestLib_PLM
#undef CATOxiMigrateXPDMToV6

#if _MK_MODNAME_ == AuthorizedModule  
#error Module has not been undeclared correctly. Check this header. 
// Fatal error on solaris
@error
#endif  


// ExportedByCATOmbSelectiveLoading def

#if defined __CATOmbSwitchEngine
#define ExportedByCATOmbSwitchEngine DSYExport
#else
#define ExportedByCATOmbSwitchEngine DSYImport
#endif
#include "DSYExport.h"

#include "CATErrorDef.h"
