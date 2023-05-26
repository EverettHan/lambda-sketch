//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMHistoryServicesAdapter.h
// Define the CATPLMHistoryServicesAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMHistoryServices
//
//===================================================================
//
// Feb 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMHistoryServicesAdapter_H
#define CATPLMHistoryServicesAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMHistoryServices.h" // CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

class ExportedByCATPLMImplAdapterClass CATPLMHistoryServicesAdapter : public CATIPLMHistoryServices
{
public:
    CATPLMHistoryServicesAdapter();
    virtual ~CATPLMHistoryServicesAdapter();

    virtual HRESULT QueryHistoriesRelatedToActions( const CATLISTV(CATPLMID) & iActionList        ,
                                                    const CATIPLMHistoryHandler * iHandler,
													int iOrderByDate=0);

    virtual HRESULT QueryHistoriesRelatedToObjects( const CATLISTV(CATPLMID) & iObject             ,
                                                    const CATIPLMHistoryHandler * iHandler          ,
                                                    int iFilterOnAction = 1                         ,
                                                    CATTime *iAfter = NULL,
                                                    int iLightOuput = 0,
													int iOrderByDate=0);

    HRESULT CheckHistoryFromAction ( const CATPLMID & iAction, CATBoolean & oEntryExists );

private:
    CATPLMHistoryServicesAdapter (CATPLMHistoryServicesAdapter &);
    CATPLMHistoryServicesAdapter& operator=(CATPLMHistoryServicesAdapter&);

};

#endif

