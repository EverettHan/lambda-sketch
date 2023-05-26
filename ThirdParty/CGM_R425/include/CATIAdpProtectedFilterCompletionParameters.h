//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/12/07
//===================================================================
// CATIAdpProtectedFilterCompletionParameters.cpp
// Header definition of class CATIAdpProtectedFilterCompletionParameters
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/12/07 Creation: Code generated by the 3DS wizard
//===================================================================
/**
* @level Protected
* @usage U3  
*/

#ifndef CATIAdpProtectedFilterCompletionParameters_H
#define CATIAdpProtectedFilterCompletionParameters_H

// small checks
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
@error
#endif

// implementation limited to some components
#define AuthorizedModule 999
#define CATPLMIntegrationAccess        AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATImmCaptureCmd               AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header limited to some components. Ask JBB.
    @error
#endif
#undef CATPLMIntegrationAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATImmCaptureCmd


#include "CATPLMIntegrationAccess.h"
#include "CATIPLMQueryFilter.h"


extern ExportedByCATPLMIntegrationAccess  IID IID_CATIAdpProtectedFilterCompletionParameters ;


class ExportedByCATPLMIntegrationAccess CATIAdpProtectedFilterCompletionParameters: public CATBaseUnknown
{
CATDeclareInterface;

public:

   /*
   * Set the query filter
   * <b>Role :</b> Allows to set any kind filter to @href CATAdpProtectedOpener
   */
   virtual HRESULT SetFilter(CATIPLMQueryFilter *iFilter) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIAdpProtectedFilterCompletionParameters, CATBaseUnknown );

#endif
