//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/01/18
//===================================================================
// CATAdpProtectedCompletionParametersFilterFactory.cpp
// Header definition of class CATAdpProtectedCompletionParametersFilterFactory
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/01/18 Creation: Code generated by the 3DS wizard
//===================================================================
/**
* @level Protected
* @usage U1  
*/

#ifndef CATAdpProtectedCompletionParametersFilterFactory_H
#define CATAdpProtectedCompletionParametersFilterFactory_H

#include "CATPLMIntegrationAccess.h"
#include "CATAdpProtectedCompletionParametersFactory.h"
#include "CATIAdpProtectedCompletionParameters.h"
class CATIPLMQueryFilter;

// small checks
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
@error
#endif

// implementation limited to some components
#define AuthorizedModule 999
#define CATFLModelerAccess             AuthorizedModule
#define TSTRFLModeler                  AuthorizedModule
#define CATImmVPMCfgFilter             AuthorizedModule
#define CATPLMIntegrationAccess        AuthorizedModule
#define CATPLMItgXOpener               AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATPLMItgTests                 AuthorizedModule
#define ENOITDBatchUtl                 AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header limited to some components. Ask JBB.
    @error
#endif
#undef CATPLMIntegrationAccess
#undef CATPLMItgXOpener
#undef CATPLMItgTestIntegrationAccess
#undef CATImmVPMCfgFilter 
#undef CATFLModelerAccess
#undef TSTRFLModeler
#undef CATPLMItgTests
#undef ENOITDBatchUtl

//-----------------------------------------------------------------------

class ExportedByCATPLMIntegrationAccess CATAdpProtectedCompletionParametersFilterFactory
{
public:
// Standard constructors and destructors
// -------------------------------------
CATAdpProtectedCompletionParametersFilterFactory ();
virtual ~CATAdpProtectedCompletionParametersFilterFactory ();

/*
* Get completion parameters for a @href CATAdpProtectedOpener with filter
* <br><b>Role:</b>Will give an handler of a @href CATIAdpProtectedCompletionParameters prebuilt. You can then manually set the parameters.
* using the interface @href CATIAdpProtectedCompletionParameters.
* @params iFilter 
*          the filter to apply
* @params iAdditionalFactory 
*          another completion mode. See @href CATAdpProtectedCompletionParametersFactory
*          by default, Authoring.
*/
static CATIAdpProtectedCompletionParameters_var Filter(         CATIPLMQueryFilter *iFilter,
                                                          const CATIAdpProtectedCompletionParameters_var iAdditionalFactory 
                                                                      = CATAdpProtectedCompletionParametersFactory::Authoring());

private:
// Copy constructor and equal operator
// -----------------------------------
CATAdpProtectedCompletionParametersFilterFactory (CATAdpProtectedCompletionParametersFilterFactory &);
CATAdpProtectedCompletionParametersFilterFactory& operator=(CATAdpProtectedCompletionParametersFilterFactory&);

};

//-----------------------------------------------------------------------

#endif