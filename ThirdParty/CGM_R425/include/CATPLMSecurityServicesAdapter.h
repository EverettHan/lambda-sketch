// (C) Copyright Dassault Systemes - 2015
// -----------------------------------------------------------------------
// Interface declaration: CATPLMSecurityServicesAdapter
// -----------------------------------------------------------------------
// Creation: 2015-02-10
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _CATIPLMSecurityServices_H_
#define _CATIPLMSecurityServices_H_

#include "CATIPLMSecurityServices.h"
#include "CATTime.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#include "CATPLMImplAdapterClass.h"// ExportedBy

/** @nodoc */
class ExportedByCATPLMImplAdapterClass CATPLMSecurityServicesAdapter : public CATIPLMSecurityServices
{
public:
    CATPLMSecurityServicesAdapter();
    virtual ~CATPLMSecurityServicesAdapter();
    virtual HRESULT CreateLoginTicket(unsigned int iNumberOfUse, CATUnicodeString *iSecurityContext, CATTime *iStart, CATTime *iExpiration, CATListOfCATUnicodeString *iRestrictions, const char *iKey, CATUnicodeString &oTicket);
    
private:
    CATPLMSecurityServicesAdapter (CATPLMSecurityServicesAdapter &);
    CATPLMSecurityServicesAdapter& operator=(CATPLMSecurityServicesAdapter&);    
};

#endif
