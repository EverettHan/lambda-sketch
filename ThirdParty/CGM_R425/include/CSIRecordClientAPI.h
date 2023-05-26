#ifndef CSIRecordClientAPI_H
#define CSIRecordClientAPI_H

#include "CSICommandBinderModule.h"
#include "EKNodeId.h"

#include "DSUnicodeString.h"

#include <vector>

/* Record documentation
https://executionfw.dsone.3ds.com/docs/csi/AdvancedDocumentation/RecordAndReplay/

Reminder, for a pool to be recordable, you must either
* add "recordable": true in the server's main pool json file
* use the --recordable option in
  mkrun -c "3DExperienceNode --pool MyApplicationPool --hypervisor hypervisorUrl --recordable"
*/

namespace CSI
{
  class Node;

  struct RecordResults
  {
    /** filepath for informations files */
    std::vector<CATUnicodeString> infoPaths;

    /** filepath for records files*/
    std::vector<CATUnicodeString> recordPaths;

    /** filepath for warning files, like when a pool is not recordable */
    std::vector<CATUnicodeString> warnings;

    /** filepath on the client machine containing the paths for all available records on the server chain */
    CATUnicodeString clientInfoPath;
  };

  /* Record Client API
   * Used by a client to activate or stop a record on a server. This is kind of a record request, targeting all pools, or a list of specific pools.
   * 
   * When there is a server chain: 
   *   client <-communicates with-> Server1 <-clients with-> Server2 ...  <-clients with-> Server n
   *   The record request is forwarded through the whole server chain, each server will have its own local record, if its pool is targeted.
   * 
   * RecordClientAPI::Start() must be called before CSI::Node::Select()
   * Resulting files from record can be retrieved at any moment with RecordClientAPI::GetCurrentRecordResults()
   * 
   * Note: a CSI Server can only record for one client <=> nodeId at a time, meaning that further record request from other client and other select() than the first select() will be ignored
  **/
  class ExportedByCSIBinderModule RecordClientAPI
  {
  public:
    RecordClientAPI(Node& node);
    ~RecordClientAPI() = default;
    RecordClientAPI(const RecordClientAPI&) = default;
    RecordClientAPI& operator=(const RecordClientAPI&) = default;

    /** Start Record on server, request will be sent during first call to CSI::Node::Select()
      \param targetPools - list of pools targeted for record
      \Usage - Start({ "PoolA", "PoolB" });
    */
    void Start(std::vector<CATUnicodeString> targetPools = {});

    /** Retrieve all the filepaths or files created for the recording */
    RecordResults GetCurrentRecordResults() const;

    /** Ask the server to stop a recording */
    RecordResults Stop();

    /** Erase all the local files generated by the recording */
    void ClearAllRecordFiles();

    // @nodoc DO NOT USE
    void SetReplayMode(EK::NodeId& nodeId, bool b);

  private:
    RecordResults ParseInfoFile() const;
  private:
    Node& node_;
    CATUnicodeString clientInfoPath_;
  };
}

#endif /*CSIRecordClientAPI_H*/
