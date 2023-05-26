#ifndef CATPLMItgDecoration_H
#define CATPLMItgDecoration_H
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATLISTV_CATPLMID.h"
#include "CATSysErrorDef.h"

// List of authorized infrastructure modules 
#define AuthorizedModule     999
#define CATPLMIntegrationAccess        AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATPLMWorkspaceImplCompEngine  AuthorizedModule
#define CATPLMWorkspaceImpl            AuthorizedModule


#if _MK_MODNAME_ == AuthorizedModule
#else
  #error Forbidden Access To CATPLMItgDecoration Services from a non-authorized module
  // Fatal error on solaris
  @error 
#endif

class ExportedByCATPLMIntegrationAccess CATPLMItgDecoration
{
public :
  static HRESULT RetrieveRelevantConnectionsAndPorts(const CATPLMIDs & iObjectsInStructure, CATPLMIDs & oObjectsInStructureWithRelevantCnxAndPorts);
} ;
#endif
