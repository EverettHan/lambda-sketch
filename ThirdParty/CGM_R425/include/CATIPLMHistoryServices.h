//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMCompHistoryServices
//
//===================================================================
//
// this interface will be implemented by each provider
// So, we provide an adapter for this interface:
// CATPLMHistoryServicesAdapter.h (CATPLMImplAdapter ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterBase.dll)
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

#ifndef CATIPLMHistoryServices_H
#define CATIPLMHistoryServices_H

#include "CATPLMServicesItf.h"//ExportedBy

#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMHistoryServices;
#else
extern "C" const IID IID_CATIPLMHistoryServices ;
#endif

class CATPLMID;
class CATLISTV(CATPLMID);
class CATIPLMHistoryHandler;
class CATTime;

class ExportedByCATPLMServicesItf CATIPLMHistoryServices: public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /** 
    * we have a list of ACTION ids, we retrieve HISTORY records related to those ACTION ids
    *
    * <br><b>Role</b>:
    * we have a list of ACTION ids, we retrieve HISTORY records related to those ACTION ids
    *
    * @param iActionList [in]
    *   list of ACTION ids
    * @param iHandler [in]
    *   handler that will contain all HISTORY records related to ACTION ids
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise...
    *   <code>E_INVALIDARG</code>if size of iActionList is empty
    *
    */
    virtual HRESULT QueryHistoriesRelatedToActions( const CATLISTV(CATPLMID) & iActionList        ,
                                                    const CATIPLMHistoryHandler * iHandler,
													int iOderByData = 0) = 0;

    /** 
    * we have a list of OBJECT ids, we retrieve HISTORY records related to those OBJECT ids
    *
    * <br><b>Role</b>:
    * we have a list of OBJECT ids, we retrieve HISTORY records related to those OBJECT ids
    *
    * @param iObject [in]
    *   the list of object that have been modified
    * @param iHandler [in]
    *   handler that will contain all HISTORY records related to OBJECT ids
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise...
    *   <code>E_INVALIDARG</code>if size of iObject is empty
    *
    */
    virtual HRESULT QueryHistoriesRelatedToObjects( const CATLISTV(CATPLMID) & iObject              ,
                                                    const CATIPLMHistoryHandler * iHandler          ,
                                                    int iFilterOnAction = 1                         ,
                                                    CATTime *iAfter = NULL,
                                                    int iLightOuput = 0,
													int iOderByData = 0) = 0;

    virtual HRESULT CheckHistoryFromAction ( const CATPLMID & iAction, 
                                   CATBoolean & oEntryExists ) = 0;
};

#endif
