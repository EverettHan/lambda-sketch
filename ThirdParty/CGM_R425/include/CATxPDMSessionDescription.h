#ifndef _CATxPDMSessionDescription_H
#define _CATxPDMSessionDescription_H

/**
 * @level Private
 * @usage U1
 */

#include "IUnknown.h"
#include "CATxPDMTodoStatus.h"
#include "CATLISTV_CATComponentId.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATUnicodeString.h"
#include "CATxPDMTodoStatus.h"
#include "CATOmxArray.h"

class CATILockBytes2;
class CATxPDMLogEntryIterator;
class CATOmXStream;
class CATOxEntity;
class CATPLMID;
class CATxPDMLogEntry;

/**
* Class to manage the marshalling and unmarshalling of save logs, as well as to give access
* to the entries in the save log.
*/
class ExportedByCATPLMIdentification CATxPDMSessionDescription
{
public:
  /**
  * Constructor.
  */
  CATxPDMSessionDescription();

  /**
  * Destructor.
  */
  ~CATxPDMSessionDescription();

  /**
  * Check if PDM Log is activated
  *
  * @return
  *   TRUE  : PDM is activated
  *   FALSE : PDM is not activated
  */
  static CATBoolean IsPDMLogActivated();

  /**
  * Initialize the description with the logged component ids
  *
  * @param iListCIDs
  *   List of logged components
  *
  * @return
  *   S_OK if operation succeeded
  *   E_FAIL otherwise
  */
  HRESULT Init(const CATComponentIds & iListCIDs);

  /**
  * Initialize the description
  *
  * @return
  *   S_OK if operation succeeded
  *   E_FAIL otherwise
  */
  HRESULT Init();

  /**
  * Append PLMID to log
  *
  * @param iPLMID
  *   The PLMID of a REFERENCE to log in the save log file
  *
  * @param iTodoStatus
  *    The status of the reference
  *
  * @return
  *   S_OK if the entry was correctly added
  *   S_FALSE if xPDMLog is NOT activated
  *   E_FAIL otherwise
  */
  HRESULT Append(const CATPLMID & iPLMID, CATxPDMTodoStatus iTodoStatus);

  /**
  * Marshall the log.
  *
  * @param oStream : the stream where to write the log
  *
  * @return
  *   S_OK if operation succeeded
  *   E_FAIL otherwise
  */
  HRESULT Marshall(CATOmXStream & oStream);

  /**
  * Unmarshall the log.
  *
  * @param iStream : the log stream to unmarshall
  * @param oDescription : the log description object
  */
  static HRESULT Unmarshall(CATOmXStream & iStream, CATxPDMSessionDescription & oDescription);

  /**
  * Gets on iterator on log entries.
  *
  * @return
  *  an iterator on log entries.
  */
  CATxPDMLogEntryIterator * GetIterator() const;

  /**
  * Returns the user id.
  */
  inline CATUnicodeString & GetUserId() { return _User; }

  /**
  * Returns the computer id.
  */
  inline CATUnicodeString & GetMachineId() { return _Machine; }

private:

  CATOmxArray<CATxPDMLogEntry*, naive_manager> _CATxPDMLogEntryList;

  CATUnicodeString _User;
  CATUnicodeString _Machine;

  CATBoolean _InitDone;

  static const unsigned char _Version;
};

#endif
