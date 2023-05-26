// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATPLMTUserFact.h
// Define the CATPLMTUserFact interface
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
#ifndef CATPLMTUserFact_H
#define CATPLMTUserFact_H

#include "CATPLMServicesItf.h"
#include "CATPLMTLogEntry.h"
#include "CATOmxVector.h"
#include "CATPLMTEvent.h"
#include "CATListOfCATUnicodeString.h"

class CATUnicodeString;
class CATPLMHistoryRecordLight;

class ExportedByCATPLMServicesItf CATPLMTUserFact : public CATPLMTLogEntry
{
  CATDeclareClass;
public:
  enum CATPLMTUserFactType { Split, SplitER, Replace, ReplaceER, Delete, Modify, ModifyApplicability, MoveMatrix, LogicalClone };
  /*NB: MoveMatrix is not sent as is to server but as a Modify user fact with specific UserData*/

  /**
  * Creates a new CATPLMTUserFact object.
  * @param iType
  *   Types of the user fact. Can be:
  *     -CATPLMTUserFact::Split
  *     -CATPLMTUserFact::SplitER
  *     -CATPLMTUserFact::Replace
  *     -CATPLMTUserFact::ReplaceER
  *     -CATPLMTUserFact::Delete
  *     -CATPLMTUserFact::Modify
  *     -CATPLMTUserFact::ModifyApplicability
  *     -CATPLMTUserFact::MoveMatrix
  * @return CATBaseUnknown#Release
  *    Created CATPLMTUserFact.
  */
  static CATPLMTUserFact *Factory(CATPLMTUserFactType iType);

  /**
  * @nodoc
  */
  static CATPLMTUserFact *Factory(CATPLMHistoryRecordLight *iRecordLight);

  /**
  * Get the type of the user fact.
  * @return
  *    Returned type.
  */
  CATPLMTUserFactType GetType();

  /**
  * Log an event inside the user fact.
  * @param iEvent
  *   Event to log.
  * @return
  *    S_OK  : Event correctly added.
  *    E_FAIL: Otherwise.
  */
  HRESULT AddEvent(CATPLMTEvent *iEvent);

  /**
  * Get the number of events inside the user fact.
  * @return
  *    Number of events.
  */
  int GetNbEvents();

  /**
  * Get an allready added event.
  * @param iIndice
  *   Indice of the desired event.
  *   From 0 to GetNbEvents()-1
  * @param oEvent [CATBaseUnknown#Release]
  *   The returned event.
  * @return
  *    S_OK  : Event correctly returned.
  *    E_FAIL: Otherwise.
  */
  HRESULT GetEvent(int iIndice, CATPLMTEvent *&oEvent);

  /**
  * Add specific log entry information: Relevant Date for the operation.
  * @param iValue
  *   Date value. Use the same formating than time_t.
  * @return
  *    S_OK  : Information correctly added.
  *    E_FAIL: Otherwise.
  */
  HRESULT AddDate(CATLONG64 iValue);

  /**
  * Add specific log entry information: Relevant Date for the operation.
  * @param iValue
  *   Date value.
  * @return
  *    S_OK  : Information correctly added.
  *    E_FAIL: Otherwise.
  */
  HRESULT AddDate(CATTime &iValue);

  /**
  * Add MOVEMATRIXATTRIBUTE information in User Data
  * TODO: should be a specific user fact. Waiting for server code.
  * @return
  *    S_OK  : Information correctly added.
  *    E_FAIL: Otherwise.
  */
  HRESULT AddMoveMatrixAttribute();

  /**
  * Add specific log entry information: configured delete flag.
  *
  * @return
  *    S_OK  : Information correctly added.
  *    E_FAIL: Otherwise.
  */
  HRESULT SetConfiguredDelete();

  /**
  * Add operation information.
  *
  * @return
  *    S_OK  : Information correctly added.
  *    E_FAIL: Otherwise.
  */
  HRESULT AddOperation(const CATUnicodeString & iOperation);

private:
  CATPLMTUserFact(CATPLMTUserFactType iType);
  ~CATPLMTUserFact();

  static HRESULT Parse(CATUnicodeString &, CATListOfCATUnicodeString &, CATListOfCATUnicodeString &);

  CATPLMTUserFactType userFactType;
  CATOmxVector<CATPLMTEvent> events;
};
#endif
