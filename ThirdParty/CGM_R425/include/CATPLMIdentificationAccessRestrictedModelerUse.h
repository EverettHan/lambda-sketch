#undef ExportedByCATPLMIdentificationAccessRestrictedModelerUse 
/**
 * @level Private
 * @usage U3
 */

#if defined (private) || defined(friend) || defined (protected)
	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif


#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMIdentificationAccess            AuthorizedModule
#define CATPLMIdentification_PLM              AuthorizedModule // Test
#define DELPLMPPRContBase                     AuthorizedModule // Use of CATAdpTypeBuilder
#define CATPLMClientCoreTypeInfos             AuthorizedModule // Use of GetPreferedInstanciationType
#define CATPLMClientCoreServices              AuthorizedModule // Use of GetPreferedInstanciationType
#define CATPrsFbdImport                       AuthorizedModule // Use of GetPreferedInstanciationType
#define CATFLModelerServices                  AuthorizedModule // Use of GetPreferedInstanciationType
#define PLMChangeBaseModelerUtilities         AuthorizedModule // Use of GetPreferedInstanciationType
#define PLMModelerRep                         AuthorizedModule // Use of GetPreferedInstanciationType
#define PLMModelerServices                    AuthorizedModule // Use of GetPreferedInstanciationType
#define CATPrdPccModelInit                    AuthorizedModule // Use of GetPreferedInstanciationType
#define PrdTestStructureEdition               AuthorizedModule // Use of GetPreferedInstanciationType
#define CATPLMIntegrationAccess               AuthorizedModule // Use of GetPreferedInstanciationType
#define DELPLMFunctionModelImpl               AuthorizedModule // Use of GetPreferedInstanciationType

#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden Access To CATPLMIdentificationAccessRestrictedModelerUse Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef AuthorizedModule
#undef CATPLMIdentificationAccess
#undef CATPLMIdentification_PLM
#undef DELPLMPPRContBase
#undef CATPLMClientCoreServices
#undef CATPLMClientCoreTypeInfos
#undef CATPrsFbdImport
#undef CATFLModelerServices
#undef PLMChangeBaseModelerUtilities
#undef PLMModelerRep
#undef PLMModelerServices
#undef CATPrdPccModelInit
#undef PrdTestStructureEdition
#undef CATPLMIntegrationAccess
#undef DELPLMFunctionModelImpl

#if defined(__CATPLMIdentificationAccess)
#define ExportedByCATPLMIdentificationAccessRestrictedModelerUse DSYExport
#else
#define ExportedByCATPLMIdentificationAccessRestrictedModelerUse DSYImport
#endif
#include "DSYExport.h"


