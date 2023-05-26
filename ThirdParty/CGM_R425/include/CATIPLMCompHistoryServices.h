//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMCompHistoryServices
//
//===================================================================
//
// this interface is implemented by CATPLMAdapter
//
// in terms of OM architecture, we have:
//  component                               interface
// CATPLMAdapter    implements interface CATIPLMCompHistoryServices
//
// this interface is implemented by CATPLMAdapter
// no adapter on this interface...
//
//===================================================================
//
// 1 TRANSACTION <=> 1 SAVE <=> 1 ACTION <=> n history (object , operation...)
//
// on 1 action, we can modify more than 1 object (of course), so:
//                    n
// ACTION              OBJECT
//
// one object can be modified by n ACTION (n transaction <=> n save)
//       n
// ACTION              OBJECT
//
// one action can contain n history recod
//                    n
// ACTION              HISTORY
//
// Action
//   |___History 1 (Object A , Create)
//   |___History 2 (Object B , Modify)
//
//===================================================================
// mapping between the model and our c++ object
// History <=> CATPLMHistoryRecord <=> metadata History.metadata (it is not a real plm object)
// Action <=> metadata PLMChgBase.metadata (real plm object)
//===================================================================
//
// code that is executed on our layer
// first,
// QueryHistory,QueryAction(    const CATLISTV(CATPLMID) & iActionList        ,
//                              const CATIPLMHistoryHandler * iHandler  );
// is executed
// then,
// on CATIPLMHistoryHandler
// TreatHistoryRecord( CATPLMHistoryRecord & iRecord )
// is executed
// and then
// CATPLMHistoryRecord
//
// CATPLMHistoryRecord gives access to the object whose description is in HISTORY.metadata
// the description of the ACTION object is in PLMChgBase.metadata
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

#ifndef CATIPLMCompHistoryServices_H
#define CATIPLMCompHistoryServices_H

#include "CATPLMServicesItf.h"//ExportedBy

#include "CATBaseUnknown.h"
#include "CATCollec.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompHistoryServices;
#else
extern "C" const IID IID_CATIPLMCompHistoryServices ;
#endif


class CATListPtrCATPLMTLogEntry;
class CATPLMID;
class CATLISTV(CATPLMID);
class CATIPLMHistoryHandler;
class CATTime;

class ExportedByCATPLMServicesItf CATIPLMCompHistoryServices: public CATBaseUnknown
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
                                                    const CATIPLMHistoryHandler * iHandler        ,
													int iOrderByDate = 0) = 0;

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
                                                    int iLightOuput = 0                             ,
													int iOrderByDate = 0) = 0;
 
	/** 
    */
    virtual HRESULT QueryLogRelatedToObjects(const CATLISTV(CATPLMID) &iComponents, CATListPtrCATPLMTLogEntry &oLog, CATTime *iAfter=NULL, int iLightOuput=0) = 0;


	/** 
    */
  virtual  HRESULT CheckHistoryFromAction ( const CATPLMID & iAction, 
                                   CATBoolean & oEntryExists ) = 0;
};

#endif

