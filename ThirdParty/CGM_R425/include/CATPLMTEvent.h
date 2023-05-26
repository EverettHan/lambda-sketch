// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATPLMTEvent.h
// Define the CATPLMTEvent interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMTEvent_H
#define CATPLMTEvent_H

#include "CATPLMServicesItf.h"
#include "CATPLMTLogEntry.h"
#include "CATBooleanDef.h"
#include "CATPLMID.h"
#include "CATUnicodeString.h"
#include "CATPLMType.h"

class CATPLMHistoryRecordLight;

class ExportedByCATPLMServicesItf CATPLMTEvent: public CATPLMTLogEntry
{
  CATDeclareClass;

public:
  enum CATPLMTEventType {Create, Update, Delete, ChangeStatus, Lock, UnLock, ChangeAuthorityControl, TransferOwnership, NewVersion, Clone, ModifyUnderCorrection, NewMinorVersion};

  /**
  * Creates a new CATPLMTEvent object.
  * @param iType
  *   Types of the user fact. Can be:
  *     -CATPLMTEventType::Create
  *     -CATPLMTEventType::Update
  *     -CATPLMTEventType::Delete
  * @param iPLMID
  *   PLMID of the object the event is associated with.
  * @param iIsRoot
  *   Is the event a root event or not.
  * @return CATBaseUnknown#Release
  *    Created CATPLMTEvent.
  */	
  static CATPLMTEvent *Factory(CATPLMTEventType iType, CATPLMID &iPLMID, boolean iIsRoot=FALSE);

  /**
  * @nodoc
  */	
  static CATPLMTEvent *Factory(CATPLMHistoryRecordLight *iRecordLight);

  /**
  * Add specific event information: PLMID of the object used as reference for the operation.
  * Only applies to a CATPLMTEventType::Create event.
  * @param iPLMID
  *   PLMID of the object.
  * @return
  *    S_OK  : Information correctly added.
  *    E_FAIL: Otherwise.
  */	
  HRESULT AddDerivedFrom(CATPLMID &iValue);

  /**
  * Set associated Action ID.
  * @param iPLMID
  *   PLMID of the Action to set.
  * @return
  *    S_OK  : Information correctly added.
  *    E_FAIL: Otherwise.
  */	
  HRESULT SetActionID(CATPLMID &iValue);

  /**
  * Get the type of the event.
  * @return
  *    Returned type.
  */	
  CATPLMTEventType GetType();

  /**
  * Get object PLMID the event is associated with.
  * @return
  *    Returned PLMID.
  */
  CATPLMID &GetPLMID();

  /**
  * Is the event root or not.
  * @return
  *    Root status.
  */
  boolean IsRoot();

  /**
  * Convert the event unique ID into a string.
  * @return
  *    ID as a string. x'uuid (32 characters)'
  *    current stream is used for PLMQL...
  */
  CATUnicodeString GetID();

  /**
  * Convert the event unique ID into a string.
  * @return
  *    ID as a string. uuid (32 characters)
  *    current stream is used for XMQL...
  */
  CATUnicodeString GetID2();

  HRESULT AddCompOwner(const CATPLMID& iParentPlmid);

  HRESULT AddCompInstOf(const CATPLMID& iChildPlmid);

private:
  CATPLMTEvent(CATPLMTEventType iType, CATPLMID &iPLMID, boolean iIsRoot, CATUnicodeString *iId=NULL);
  ~CATPLMTEvent();

  CATPLMTEventType eventType;
  boolean          root;
  CATUnicodeString id;
  CATPLMID         _plmid;
  CATPLMType::PLMMetaType _metaType;
};
#endif
