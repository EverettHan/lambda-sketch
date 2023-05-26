#ifndef _CATIPLMSearchServices_h_
#define _CATIPLMSearchServices_h_

// Includes
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATIPLMSearchRequest.h"

extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMSearchServices;

/**
 * This class does stuff
**/

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMSearchServices : public CATBaseUnknown
{
    CATDeclareInterface;

public:

	virtual HRESULT CreateSearchRequest(CATIPLMSearchRequest_var &oSR) = 0;
};

CATDeclareHandler(CATIPLMSearchServices, CATBaseUnknown);

/**
*  Create a CATIPLMSearchServices object. If called several times, this method returns the same object.
*/
extern HRESULT ExportedByGUIDCATPLMIndexInterfaces GetSearchServices(CATIPLMSearchServices_var &oSearchServices);

#endif
