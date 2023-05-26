// COPYRIGHT DASSAULT SYSTEMES 2006

// ExportedByCATPLMIntegration module header

/** @required */ 

#undef ExportedByCATPLMIntegration

  //-----------------------------------------------------
  //  Check that only authorized modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif


#define AuthorizedModule 999

// List of authorized infrastructure modules 

#define CATPLMIntegration							    AuthorizedModule

// For preparation of migration on expand engine. Should disappear once migration is done.
#define CATImmVPMOpenEngine               AuthorizedModule

// For call on Initialization of links table on the workspace, needing an IntegRecordRead. New protocol needed for this service (SemanticRelationAccess). Should disappear afterwards.
#define TransitionEngine                  AuthorizedModule

// For call on GetIntegrationRecordRead by VPMNav (Bolino migration). Should disappear afterwards.
#define CATImmVPMModel                    AuthorizedModule // Suppress as sson as possible. Replaced by CATImmVPMFrame.
#define CATImmVPMFrame                    AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Access To CATPLMIntegration service from a non-authorized module is prohibited
        // Fatal error on solaris
        @error 

#endif

#undef CATPLMIntegration           
#undef CATImmVPMOpenEngine           
#undef TransitionEngine           
#undef CATImmVPMModel           
#undef CATImmVPMFrame
#undef AuthorizedModule           


// ExportedByCATPLMIntegration def
#if defined __CATPLMIntegration
#define ExportedByCATPLMIntegration DSYExport
#else
#define ExportedByCATPLMIntegration DSYImport
#endif
#include "DSYExport.h"
