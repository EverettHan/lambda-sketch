/**
* @level Private
* @usage U3
*/
// COPYRIGHT DASSAULT SYSTEMES 2005

// ExportedByAD0XXBAS module header

#undef ExportedByAD0XXBAS

//-----------------------------------------------------
//  Check that only infrastructure modules can link on the exported symbols
//----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error 

#endif


#define AuthorizedModuleForDocStampAccess 666

  // Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForDocStampAccess
#pragma message("[Warning] Module declared as authorized by another header.")
#endif  


  // List of authorized infrastructure modules 

#define AC0XXLNK						AuthorizedModuleForDocStampAccess
#define AD0XXBAS						AuthorizedModuleForDocStampAccess
#define AC0SPBAS	  					AuthorizedModuleForDocStampAccess
#define AC0SPTRANSAC                    AuthorizedModuleForDocStampAccess
#define AD0UNDO                         AuthorizedModuleForDocStampAccess
#define OmbTstDirty                     AuthorizedModuleForDocStampAccess
#define AC0ITEMS                        AuthorizedModuleForDocStampAccess
#define AC0CATPL                        AuthorizedModuleForDocStampAccess
#define CATOmbSwitchEngine              AuthorizedModuleForDocStampAccess
#define CATOmbPersistency               AuthorizedModuleForDocStampAccess
#define CATFileEnv                      AuthorizedModuleForDocStampAccess
#define CATOmbSelectiveLoading          AuthorizedModuleForDocStampAccess
#define CATPLMBatchLinkCATToCATDocs     AuthorizedModuleForDocStampAccess
#define CATPLMBatchLinkCATNoCATDocs     AuthorizedModuleForDocStampAccess
#define OmbTstDocDirtyUndoRedo          AuthorizedModuleForDocStampAccess
#define CATPLMDocument                  AuthorizedModuleForDocStampAccess
#define CATOmcBase                      AuthorizedModuleForDocStampAccess
#define CATOmbNonCATIADocument          AuthorizedModuleForDocStampAccess
#define CATOmdUndoRedoTestEngine        AuthorizedModuleForDocStampAccess
#define CATOmbDebugWorkshop				      AuthorizedModuleForDocStampAccess
#define PLMStreamDescriptor_TestSynchroStamp	AuthorizedModuleForDocStampAccess
#define CATOmbTestLib_PLM               AuthorizedModuleForDocStampAccess
#define CATOxiRefreshVisuStreams        AuthorizedModuleForDocStampAccess

#if _MK_MODNAME_ == AuthorizedModuleForDocStampAccess

#else

#error Forbidden Access To CATOmbDocUpdateStampServices from a non-infrastructure module
  // Fatal error on solaris
  @error 

#endif

#undef AC0XXLNK
#undef AD0XXBAS
#undef AC0SPBAS
#undef AC0SPTRANSAC
#undef AD0UNDO
#undef OmbTstDirty
#undef AC0ITEMS
#undef AC0CATPL
#undef CATOmbSwitchEngine
#undef CATOmbPersistency
#undef CATFileEnv
#undef CATOmbSelectiveLoading
#undef CATPLMBatchLinkCATToCATDocs
#undef CATPLMBatchLinkCATNoCATDocs
#undef OmbTstDocDirtyUndoRedo
#undef CATPLMDocument
#undef CATOmcBase
#undef CATOmbNonCATIADocument
#undef CATOmbDebugWorkshop
#undef PLMStreamDescriptor_TestSynchroStamp
#undef CATOmdUndoRedoTestEngine
#undef CATOmbTestLib_PLM
#undef CATOxiRefreshVisuStreams

  // Check we did not forget to remove all definition
#if _MK_MODNAME_ == AuthorizedModuleForDocStampAccess
#pragma message("[Warning] Module declared has not been undeclared correctly.")
#endif  

  // ExportedByAD0XXBAS def

#if defined __AD0XXBAS
#define ExportedByAD0XXBAS DSYExport
#else
#define ExportedByAD0XXBAS DSYImport
#endif
#include "DSYExport.h"
