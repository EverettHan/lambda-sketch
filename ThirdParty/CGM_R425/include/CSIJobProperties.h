//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/11
//===================================================================

#ifndef CSIJobProperties_H
#define CSIJobProperties_H

#include "CSICommandBinderModule.h"
#include "CSIJobData.h"
#include "CSIJobStatus.h"
#include "CSIJobPriority.h"

#include "DSUnicodeString.h"

#include <memory>

namespace CSI
{
class Parameters;

/**
* Class that wraps properties information about a job
*/
class ExportedByCSIBinderModule JobProperties
{
public:
  JobProperties() = default;
  JobProperties(const Parameters& properties);

  ~JobProperties() = default;

  JobProperties(const JobProperties& rhs) = default;
  JobProperties& operator=(const JobProperties& rhs) = default;

  /**
  * Create a Parameters from this JobProperties
  */
  void ToParameters(Parameters& parameters) const;

  /**
  * @return the job UUID
  */
  CATUnicodeString GetJobID() const;

  /**
  * @return the tenant of the associated job
  */
  CATUnicodeString GetTenant() const;

  /**
  * @return the pool of the associated job
  */
  CATUnicodeString GetPool() const;

  /**
  * @return the node identifier of the associated job
  */
  CATUnicodeString GetNodeIdentifier() const;

  /**
  * @return the function name of the associated job
  */
  CATUnicodeString GetFunctionName() const;

  /**
  * @return the function version of the associated job
  */
  int GetFunctionVersion() const;

  /**
  * @return the TTK of the associated job
  */
  int GetTTK() const;

  /**
  * @return the TTL of the associated job
  */
  int GetTTL() const;

  /**
  * @return the status of the associated job
  */
  JobStatus GetStatus() const;

  /**
  * @return the priority of the associated job
  */
  JobPriority GetPriority() const;

  /**
  * @return the CASUser of the associated job
  */
  CATUnicodeString GetCASUser() const;

  /**
   * @return the CASUserUUID of the associated job
   */
  CATUnicodeString GetCASUserUUID() const;

  /**
  * @return keepProgress option value
  */
  bool GetKeepProgress() const;

  /**
  * @return retry count
  */
  int16_t GetRetryCount() const;

  /**
  * @return whether the associated job is scheduled to be retried or not
  */
  bool GetRetryPending() const;

  /**
  * @return the creation time of the associated job
  */
  int64_t GetCreationTime() const;

  /**
  * @return the submission time of the associated job
  */
  int64_t GetSubmissionTime() const;

  /**
  * @return the time when the execution of the associated job began
  */
  int64_t GetStartingTime() const;

  /**
  * @return the time when the execution of the associated job ended
  */
  int64_t GetCompletionTime() const;

  /**
  * @return the duration of the execution of the associated job
  */
  int64_t GetExecutionDuration() const;

  /**
  * @return the custom properties associated to the job
  */
  CATUnicodeString GetCustomProperties() const;

  /**
  * @return the input/progress/answer parameters associated to the job
  */
  const JobData* GetJobData() const;

private:
  CATUnicodeString jobId_ = "";
  CATUnicodeString tenant_ = "";
  CATUnicodeString pool_ = "";
  CATUnicodeString identifier_ = "";
  CATUnicodeString functionName_ = "";
  CATUnicodeString user_ = "";
  CATUnicodeString user_uuid_ = "";
  CATUnicodeString customProperties_ = "";
  std::shared_ptr<JobData> jobData_;
  int64_t creationTime_ = 0;
  int64_t submissionTime_ = 0;
  int64_t startingTime_ = 0;
  int64_t completionTime_ = 0;
  int functionVersion_ = 0;
  int ttk_ = 0;
  int ttl_ = 0;
  int status_ = 0;
  int priority_ = 0;
  int16_t retryCount_ = 0;
  bool retryPending_ = false;
  bool keepProgress_ = false;
};
}

#endif /*CSIJobProperties_H*/
