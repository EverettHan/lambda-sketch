#ifndef _CATxPDMLogEntry_H
#define _CATxPDMLogEntry_H

/**
 * @level Private
 * @usage U1
 */


#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATPLMID.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATxPDMTodoStatus.h"


 /**
 * This class represents a (read-only) save log entry
 * It returns the PLMID and xPDMTodoStatus of the object corresponding to the entry.
 */
class CATxPDMLogEntry
{
public:

  /**
  * GetPLMID
  *   Returns the PLMID of the log entry
  *
  * @return
  *   The CATPLMID of the log entry
  */
  inline CATPLMID GetPLMID() const { return _PLMID; }

  /**
  * GetStatus
  *   returns the status of the log entry
  *
  * @return
  *   the status of the log entry
  */
  inline CATxPDMTodoStatus GetStatus() const { return _LogStatus; }

  /**
  * GetAdpIdentificator
  *
  * @param opPLMIdentificator [out, CATBaseUnknown#Release]
  *   A pointer to the Adp Identificator corresponding to this log entry
  *
  * @return
  *  S_OK if the related plm type could be retrieved.
  *  E_FAIL otherwise
  */
  inline HRESULT GetAdpIdentificator(CATIAdpPLMIdentificator *& opPLMIdentificator) const { return CATPLMID::GetAdpIdentificatorFromPLMID(_PLMID, opPLMIdentificator); }


  // Constructor, reserved to the internal object managing the save log
  inline CATxPDMLogEntry(const CATPLMID & iPLMID, CATxPDMTodoStatus iLogStatus) :_PLMID(iPLMID), _LogStatus(iLogStatus) {}


private:
  const CATPLMID _PLMID;
  const CATxPDMTodoStatus _LogStatus;
};

#endif
