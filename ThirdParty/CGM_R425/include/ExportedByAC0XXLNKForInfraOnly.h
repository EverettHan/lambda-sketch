// COPYRIGHT DASSAULT SYSTEMES 2003
/**
* @level Protected
* @usage U3
*/
// ExportedByAC0XXLNKForInfraOnly module header

#undef ExportedByAC0XXLNKForInfraOnly

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

#define AC0XXLNK                   AuthorizedModule
#define AD0XXBAS                   AuthorizedModule
#define AC0SPBAS                   AuthorizedModule
#define AC0SPCHECK                 AuthorizedModule
#define AC0SPEXT                   AuthorizedModule
#define AC0SPDOC                   AuthorizedModule
#define AC0CATNAV                  AuthorizedModule
#define AC0CATPL                   AuthorizedModule
#define CP0CLIP                    AuthorizedModule
#define CP0SPEC                    AuthorizedModule
#define CATOmbLinks                AuthorizedModule
#define CATOsmProxy                AuthorizedModule
#define CATClnSpecs                AuthorizedModule
#define CATVBTCatalogBuilder       AuthorizedModule
#define CATOmbTechnologicalRep     AuthorizedModule
#define CATIAEnable                AuthorizedModule
#define CATOmbCluster              AuthorizedModule
#define CATOmcBase                 AuthorizedModule
#define CATOsm_OmcV4               AuthorizedModule
#define CATOmbTstMigrationServices AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Forbidden Access To AC0XXLNK Services from a non-infrastructure module
        // Fatal error on solaris
        @error 

#endif

#undef AC0XXLNK                
#undef AD0XXBAS                
#undef AC0SPBAS                
#undef AC0SPCHECK              
#undef AC0SPEXT                
#undef AC0SPDOC                
#undef AC0CATNAV               
#undef AC0CATPL                
#undef CP0CLIP                 
#undef CP0SPEC                 
#undef CATOmbLinks             
#undef CATOsmProxy             
#undef CATClnSpecs             
#undef CATVBTCatalogBuilder    
#undef CATOmbTechnologicalRep  					
#undef CATIAEnable   
#undef CATOmbCluster           
#undef CATOmcBase
#undef CATOsm_OmcV4
#undef CATOmbTstMigrationServices

// ExportedByAC0XXLNKForInfraOnly def

#define ExportedByAC0XXLNKForInfraOnly DSYExport

#include "DSYExport.h"

