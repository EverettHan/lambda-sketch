// COPYRIGHT DASSAULT SYSTEMES 2006

// ExportedByCATPLMIntegrationInterfaces module header

/** @required */ 

#undef ExportedByCATPLMIntegrationInterfaces

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

#define CATPLMIntegrationInterfaces							    AuthorizedModule
#define CATPLMIntegration							              AuthorizedModule
#define CATPLMPrdFactory          							    AuthorizedModule
#define CATPrdModelProperties      							    AuthorizedModule
#define CAT3DPhysicalRepProperties	                AuthorizedModule
#define CATPLMClientCoreModel     	                AuthorizedModule
#define CATPLMIntegrationAccess                     AuthorizedModule
#define DELPMXProcessStructure                      AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Access To CATPLMIntegrationInterfaces services from a non-authorized module is prohibited
        // Fatal error on solaris
        @error 

#endif

#undef CATPLMIntegrationInterfaces           
#undef CATPLMIntegration           
#undef CATPLMPrdFactory           
#undef CATPrdModelProperties
#undef CAT3DPhysicalRepProperties           
#undef CATPLMClientCoreModel           
#undef CATPLMIntegrationAccess           
#undef DELPMXProcessStructure           
#undef AuthorizedModule           


// ExportedByCATPLMIntegrationInterfaces def
#if defined __CATPLMIntegrationInterfaces
#define ExportedByCATPLMIntegrationInterfaces DSYExport
#else
#define ExportedByCATPLMIntegrationInterfaces DSYImport
#endif
#include "DSYExport.h"
