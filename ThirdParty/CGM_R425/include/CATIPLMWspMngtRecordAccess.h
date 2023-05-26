#ifndef CATIPLMWspMngtRecordAccess_H
#define CATIPLMWspMngtRecordAccess_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#include "CATBaseUnknown.h"

#include "CATPLMServicesItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMWspMngtRecordAccess;
#else
extern "C" const IID IID_CATIPLMWspMngtRecordAccess ;
#endif

#include "CATBooleanDef.h"
class CATPLMID;

/**
 * Interface to retreive workspace operation information on returned Records.
 * 
 */
class ExportedByCATPLMServicesItf CATIPLMWspMngtRecordAccess : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * List of operations.
   */
  enum WspOperation 
  {
  /** 
   * Synchronize Attach.
   */
    Sync_Attach = 1
  /** 
   * Synchronize Update.
   */
  , Sync_Update 
  /** 
   * Synchronize Detach.
   */
  , Sync_Detach
  /** 
   * Synchronize Impact.
   */
  , Sync_Impact
  /** 
   * Delivery Create.
   */
  , Deliver_Create
  /** 
   * Delivery Update.
   */
  , Deliver_Update
  /** 
   * Delivery Delete.
   */
  , Deliver_Delete
  /** 
   * Unknown operation.
   */
  , Unknown_Operation
  };

  /**
   * Returns the workspace operation dealt by the record.
   * 
   * E_FAIL : the operation stored in the record is not a workspace operation (Unknown_operation).
   */
  virtual HRESULT GetWspOperation (CATIPLMWspMngtRecordAccess::WspOperation &oOperation) = 0;

  /**
   * Returns the workspace identifier dealt by the record.
   * @param oWspPLMID [out]
   *    The PLMID of the workspace object
   * @param oIsImpactedByOperation [out]
   *    Indicates that the workspace element could have been impacted by the operation,
   *    So, the attribute modification should be applied to this PLMID.
   * 
   * E_FAIL : The PLMID cannot be retreived.
   */
  virtual HRESULT GetWspPLMId (CATPLMID &oWspPLMID, CATBoolean &oIsImpactedByOperation) = 0;

  /**
   * Returns the workspace identifier dealt by the record.
   * @param oRefPLMID [out]
   *    The PLMID of the reference object
   * @param oIsImpactedByOperation [out]
   *    Indicates that the reference element could have been impacted by the operation,
   *    So, the attribute modification should be applied to this PLMID.
   * 
   * E_FAIL : The PLMID cannot be retreived.
   */
  virtual HRESULT GetRefPLMId (CATPLMID &oRefPLMID, CATBoolean &oIsImpactedByOperation) = 0;
};

#endif
