//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMCompHistoryServices
//
//===================================================================
//
// we provide an adapter for this interface:
// CATPLMHistoryHandlerAdapter.h
// Indeed, this interface is implemented by each client
//
//===================================================================
//
// Jan 2009 Creation EPB
// 
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMHistoryHandler_H
#define CATIPLMHistoryHandler_H

#include "CATPLMServicesItf.h"// ExportedByCATPLMServicesItf

#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMHistoryHandler;
#else
extern "C" const IID IID_CATIPLMHistoryHandler ;
#endif


class CATPLMHistoryRecord;
class CATPLMHistoryRecordLight;

class ExportedByCATPLMServicesItf CATIPLMHistoryHandler : public CATBaseUnknown
{
    CATDeclareInterface;
public:

    /** 
    * Treatment of history records.
    *
    * <br><b>Role</b>: Treatment of history records.
    *
    * @param iRecord [in]
    *   the light record that has been filled (information retrieved using the xml file that contains history records).
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise...
    *   <code>E_FAIL</code> if handler means to stop the parsing. The corresponding Query method will return E_FAIL also.
    *
    */
    virtual HRESULT TreatHistoryRecord ( CATPLMHistoryRecordLight *iRecord ) = 0;

};

#endif
