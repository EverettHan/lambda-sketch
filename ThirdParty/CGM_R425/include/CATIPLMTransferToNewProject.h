#ifndef _CATIPLMTransferToNewProject_H_
#define _CATIPLMTransferToNewProject_H_ 1

// System
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATUuid.h"
// ObjectModelerCollection
#include "CATOmxDeprecated.h"
#include "CATOmxIter.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxOHMap.h"
#include "CATOmxOMap.h"
#include "CATOmxPortability.h"
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATPLMTypeH.h"
// CATPLMIdentification
#include "ExportedByCATPLMTos.h"

class CATIPLMSessionDataSource;
class CATError;
class CATIPLMTransferToNewProjectCallbacks;

/**
 * Session wrapper on fork server command (Meyerwerft "sistership" project)
 * Fork consists in iteratively cloning a structure from a source collaborative space ("prototype") to a destination collaborative space ("sistership")
 * Each object can be cloned only once in destination collab space.
 * All links (instance or semantic relations) are rerouted within destination collab space if possible (ie: if "origin"/"target" of a link have been cloned in destination target)
 * This class will
 *   check if fork operation is possible
 *   tranform the session into a preview of the server-side fork result (warning at this point session will contain temporary/invalid PLMIDs)
 *   start an asynchronous fork request on the server
 * At this point user can work on the session (with some restrictions, for example save is not possible)
 * Once the asynchronous has completed the session will be refreshed (with correct ids) and session will reach a "normal" state.
 */
class CATIPLMTransferToNewProject : public CATBaseUnknown
{
public:
  /**
   * Create engine
   * @param iCloningString:
   *   optional cloning string
   * @param iCallbacks
   *   mandatory callbacks
   */
  static ExportedByCATPLMTos HRESULT Create(CATIPLMTransferToNewProjectCallbacks* iCallbacks, CATOmxSR<CATIPLMTransferToNewProject>& oEngine);

  /**
   * Add an object to the set of objects to transfer
   * @param iComponent
   *   a reference or representation reference to transfer
   *   rules:
   *    - It must not belong to current "Collaborative space"
   *    - All added objects must belong to the same "Collaborative space"
   *    - The "parents" (references aggregating instances of this object) must be in current "Collaborative space" or in the set of objects to transfer
   *      NB: this rule is checked in StartTransfer
   *    - It must not be dirty ("created" or "modified" states)
   *    - It must be "loaded" (explore results, UWP "light mode" not supported)
   */
  virtual HRESULT AddObject(CATBaseUnknown* iComponent, const CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock>& iAttributes = {}) = 0;

  /**
   * Start transfer operation
   * - The set of objects to transfer is completed with aggregated objects (instances, connections, ports, mono-instanciated representations)
   * - The set of objects to transfer is checked (see AddObject rules)
   * - objects are reidentified (with a temporary identifier) and links are rerouted
   * - Cloning operation is STARTED on server
   * At this point session contains a preview (with invalid temporary identifiers) of the eventual server result.
   * "Save" commands must be locked (Save, SaveAs, Clone, LocalSave, Offline, probably export too).
   * Server operation completion will eventually trigger CATIPLMTransferToNewProjectCallbacks::OnServerSideCloningCompleted
   * @param oAsyncTaskId
   *   Asynchronous task id (see asynchronism infrastructure)
   * @return
   *    SUCCESS: the session has been processed and the request has been sent to the server
   *    FAILURE: the session cannot be processed or the request cannot be sent to the server
   * in all cases some warnings, error messages can be available, see GetErrors()
   */
  virtual HRESULT StartTransfer(CATUuid& oAsyncTaskId) = 0;

  /**
    * Finalize transfer
    * Session is refreshed using server operation return message.
    * MUST be called when server-side cloning task has completed (CATIPLMTransferToNewProjectCallbacks::OnServerSideCloningCompleted)
    * (not calling it would result in leaving the session in a corrupted state)
    * After calling this method all commands locked (see StartTransfer) can be unlocked
    * @return
    *   S_OK: everything is fine
    *   S_FALSE: the request has been successfully processed by the server
    *   FAILURE: the server failed to process the request or a problem occured in session
    * in all cases some warnings, error messages can be available, see GetErrors()
    */
  virtual HRESULT FinalizeTransfer() = 0;

  /**
   * Set fork operation options.
   * @see server fork operation documentation
   * By default none are used
   * According to 11/2016 server PES, are supported:
   * 	KEEP_ORGANIZATION, KEEP_MATURITY, KEEP_LOCK, KEEP_VERSIONNING
   * (and value must be true)
   */
  virtual HRESULT SetOptions(const CATOmxKeyValueBlock& iOptions) = 0;

  /**
    * Retrieve the errors that has been logged until now during operation
    * Calling this method flushes error list so that a subsequent call to this method will return empty list.
    * Errors may be CATIPLMTransferToNewProjectError objects (use CAT_DYNAMIC_CAST to check that) with additional informations
    */
  virtual CATOmxIter<CATError> GetErrors() = 0;

  /**
   * to be used in GetStats
   */
  enum Stat
  {
    ForkedObjects //number of objects sent in server fork request grouped by type.
  };

  /**
   * Retrieve statistics
   */
  virtual HRESULT GetStats(Stat iStat, CATOmxOMap<CATOmxKeyString, int>& oMap) = 0;
};


#endif
