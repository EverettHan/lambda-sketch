// COPYRIGHT DASSAULT SYSTEMES 2003

// ExportedByCATOmbTechnologicalRepForInfraOnly module header

/**
* @level Protected
* @usage U3
*/

#undef ExportedByCATOmbTechnologicalRepForInfraOnly

  //-----------------------------------------------------
  //  Check that only infrastructure modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif


#define AuthorizedModule     999

// List of authorized infrastructure modules 
#define CATOmbTechnologicalRep                AuthorizedModule
#define AC0CATPL                AuthorizedModule
#define AC0SPDOC                AuthorizedModule
#define CATOmcCluster				AuthorizedModule
#define CATOmcBase				AuthorizedModule
#define CATOmbSelectiveLoading				AuthorizedModule
#define CATOmbImportExport  AuthorizedModule
#define CATOmbTestLib_PLM  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Forbidden Access To CATOmbTechnologicalRep Services from a non-infrastructure module
        // Fatal error on solaris
        @error 

#endif

#undef CATOmbTechnologicalRep
#undef AC0CATPL                
#undef AC0SPDOC 
#undef CATOmcCluster
#undef CATOmcBase
#undef CATOmbSelectiveLoading
#undef CATOmbImportExport
#undef CATOmbTestLib_PLM

// ExportedByCATOmbClusterForInfraOnly def

#if defined __CATOmbTechnologicalRep
#define ExportedByCATOmbTechnologicalRepForInfraOnly DSYExport
#else
#define ExportedByCATOmbTechnologicalRepForInfraOnly DSYImport
#endif
#include "DSYExport.h"

