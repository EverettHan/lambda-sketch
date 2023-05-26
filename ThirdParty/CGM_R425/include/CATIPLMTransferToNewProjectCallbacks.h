#ifndef _CATIPLMTransferToNewProjectCallbacks_H_
#define _CATIPLMTransferToNewProjectCallbacks_H_ 1

#include "CATBaseUnknown.h"
#include "ExportedByCATPLMTos.h"

class CATIPLMTransferToNewProject;

/**
 * Collection of callbacks used by CATIPLMTransferToNewProject object, to be implemented by caller.
 */
class ExportedByCATPLMTos CATIPLMTransferToNewProjectCallbacks: public CATBaseUnknown
{
public:
  /**
   * Will be called on server-side server cloning completion.
   * see CATIPLMTransferToNewProject::FinalizeTransfer
   */
  virtual void OnServerSideCloningCompleted(CATIPLMTransferToNewProject& iTTNP) = 0;

  /**
   * Consecutive processing steps of a session fork operation.
   * There is absolutely no guarantee on:
   *   the order of the steps
   *   if a step will occur or not
   *   how many times a step will be called
   * This enum can be enriched at any time, caller must skip the values he isn't aware of.
   */
  enum Step
  {
    Unknown,
    CheckSession,      //session is checked to ensure that the operation is possible
    QueryMappingTable, //server query on the "fork" mapping table
    QueryServer,       //optional additional server query
    OpenData,          //optional open of objects already cloned
    ProcessSession     //session is being modified to reflect final result of the server "fork"
  };

  /**
   * Called before each step of the process, see CATIPLMTransferToNewProjectCallbacks::Step enum
   */
  virtual HRESULT OnProgress(CATIPLMTransferToNewProject& iTTNP,CATIPLMTransferToNewProjectCallbacks::Step iStep); //FIXME: pure virtual once implemented by caller
};

#endif
