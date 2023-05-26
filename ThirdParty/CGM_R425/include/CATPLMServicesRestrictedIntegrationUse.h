// COPYRIGHT DASSAULT SYSTEMES 2010
/** @required */ 

#undef ExportedByCATPLMServicesItf

#if defined (private) || defined(friend) || defined (protected)
	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                999
#define CATPLMImplAdapterBase           AuthorizedModule
#define CATPLMServicesItf               AuthorizedModule
#define CATPLMIntegration               AuthorizedModule
#define CATPLMCollabMgt                 AuthorizedModule
#define CATPLMFXn                       AuthorizedModule
#define CATPLMLPr                       AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to internal apis from non-infrastructure module
        @error 
#endif
#undef CATPLMImplAdapterBase
#undef CATPLMServicesItf
#undef CATPLMIntegration
#undef CATPLMCollabMgt
#undef CATPLMLPr
#undef CATPLMFXn
// ----------------------------------------------------------------------------------------------------------------------

#undef AuthorizedModule           

#if defined (__CATPLMServicesItf)
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"
