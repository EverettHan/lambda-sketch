//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/11
//===================================================================

#ifndef CSIJobController_H
#define CSIJobController_H

#include "CSICommandBinderModule.h"
#include "CSIJobPriority.h"
#include "CSIParameters.h"

#include "DSUnicodeString.h"

#include <vector>

namespace JSON
{
class JIStream;
}

namespace CSI
{
class JobContext;
class JobControllerImpl;
class JobProperties;

class JobProgress
{
public:
  JobProgress() = delete;
  JobProgress(const Parameters& progress, int64_t timestamp)
    : progress_(progress)
    , timestamp_(timestamp)
  {
  }

  JobProgress(const JobProgress&) = default;
  JobProgress& operator=(const JobProgress&) = default;

  ~JobProgress() = default;

  const Parameters& GetProgress() const
  {
    return progress_;
  }

  Parameters& GetProgress()
  {
    return progress_;
  }

  int64_t GetTimeStamp()
  {
    return timestamp_;
  }

private:
  Parameters progress_;
  int64_t timestamp_;
};

/**
* Class that enables to contact the queuing database in order to retrieve or modify jobs' information.
*/
class ExportedByCSIBinderModule JobController
{
public:
  explicit JobController(const JobContext& ctx);

  JobController(const JobController&) = delete;
  JobController& operator=(const JobController&) = delete;

  ~JobController();

  /**
  * Enables to get the status of a job
  * @param jobId The identifier of the targeted job
  * @param input The input of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetInput(const CATUnicodeString& jobId, Parameters& input, CATUnicodeString& error);

  /**
  * Enables to get the answer of a job
  * @param jobId The identifier of the targeted job
  * @param answer The answer of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetAnswer(const CATUnicodeString& jobId, Parameters& answer, CATUnicodeString& error);

  /**
  * Enables to get the progress values of a job
  * @param jobId The identifier of the targeted job
  * @param progress The progress values of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetProgress(const CATUnicodeString& jobId, Parameters& progress, int64_t& timestamp, CATUnicodeString& error);

  /**
  * Enables to get the progress values of a job
  * @param jobId The identifier of the targeted job
  * @param vecProgress list of all progresses
  * @param error The message of a queuing error which may occur
  * @param offset The offset of the first row to return starting at 0. If set to a positive value rowCount must be > 0
  * @param rowCount Limit the number of rows returned by the query. Values <= 0 are ignored, if set to a strictly positive value offset must be >= 0
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetAllProgress(const CATUnicodeString& jobId, std::vector<JobProgress>& vecProgress, CATUnicodeString& error, int offset = -1, int rowCount = -1);

  /**
  * Enables to get all the properties of a job
  * @param jobId The identifier of the targeted job
  * @param properties The properties of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetProperties(const CATUnicodeString& jobId, JobProperties& properties, CATUnicodeString& error);

  /**
  * Enables to get all the properties of a list of jobs
  * @param vecJobIds Vector of job identifiers
  * @param vecProperties Vector of job properties (can be shorter of vecJobIds if some jobs are not found)
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetProperties(const std::vector<CATUnicodeString>& vecJobIds, std::vector<JobProperties>& vecProperties, CATUnicodeString& error);

  /**
  * Enables to get all the properties of a job including job data (inputs/progress/answer)
  * @param jobId The identifier of the targeted job
  * @param properties The properties of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetPropertiesAndData(const CATUnicodeString& jobId, JobProperties& properties, CATUnicodeString& error);

  /**
  * Enables to get all the properties of a job including job data (inputs/progress/answer)
  * @param vecJobIds Vector of job identifiers
  * @param vecProperties Vector of job properties (can be shorter of vecJobIds if some jobs are not found)
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetPropertiesAndData(const std::vector<CATUnicodeString>& vecJobIds, std::vector<JobProperties>& vecProperties, CATUnicodeString& error);

  /**
  * Enables to get the custom properties of a job
  * @param jobId The identifier of the targeted job
  * @param customProp The custom properties of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetCustomProperties(const CATUnicodeString& jobId, JSON::JIStream& customProp, CATUnicodeString& error);

  /**
  * Enables to get all the jobIds from the database
  * @param jobIds The jobIds
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT GetJobs(std::vector<CATUnicodeString>& jobIds, CATUnicodeString& error, int offset = 0, int rowCount = 100);

  /**
  * Enables to set the priority of a job
  * @param jobId The identifier of the targeted job
  * @param priority The new priority for the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT SetJobPriority(const CATUnicodeString& jobId, const JobPriority& priority, CATUnicodeString& error);

  /**
  * Enables to extend the ttk of a job
  * @param jobId The identifier of the targeted job
  * @param ttkExtension The extension value for the job's ttk
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT ExtendTTK(const CATUnicodeString& jobId, int ttkExtension, CATUnicodeString& error);

  /**
  * Enables to extend the ttl of a job
  * @param jobId The identifier of the targeted job
  * @param ttl extension value for the job's ttl
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT ExtendTTL(const CATUnicodeString& jobId, int ttl, CATUnicodeString& error);

  /**
  * Enables to set the custom properties of a job
  * @param jobId The identifier of the targeted job
  * @param customProp The custom properties of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT SetCustomProperties(const CATUnicodeString& jobId, const JSON::JIStream& customProp, CATUnicodeString& error);

  /**
  * Enables to set the inputs of a job
  * @param jobId The identifier of the targeted job
  * @param inputs The inputs of the job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT SetInputs(const CATUnicodeString& jobId, const Parameters& inputs, CATUnicodeString& error);

  /**
  * Enables to submit a job. Its status will be upgraded from created to pending
  * @param jobId The identifier of the targeted job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT Submit(const CATUnicodeString& jobId, CATUnicodeString& error);

  /**
  * Cancels a pending or running job. You can't cancel a finished (succeeded/failed) job
  * If the job is running the execution is interrupted/killed.
  * @param jobId The identifier of the targeted job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT CancelJob(const CATUnicodeString& jobId, CATUnicodeString& error);

  /**
  * Wait for a job to be in a final state: succeeded, failed or canceled
  * @param jobId The identifier of the targeted job
  * @param error The message of a queuing error which may occur
  * @param timeoutInSeconds The maximum time to wait in seconds. Negative value means no timeout.
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_ABORT in case of timeout, E_FAIL otherwise
  */
  HRESULT WaitForTermination(const CATUnicodeString& jobId, CATUnicodeString& error, double timeoutInSeconds = -1.0);

  /**
  * Create a new job from a reference one. The reference job has to be in a final state: succeeded, failed or canceled
  * Only the reference job's owner will be allowed to call this method on it.
  * @param jobId The identifier of the reference job
  * @param createdJobId The identifier of the newly created job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT CreateFrom(const CATUnicodeString& jobId, CATUnicodeString& createdJobId, CATUnicodeString& error);

  /**
  * Create and directly submit a new job from a reference one. The reference job has to be in a final state: succeeded, failed or canceled
  * Only the reference job's owner will be allowed to call this method on it.
  * @param jobId The identifier of the reference job
  * @param submittedJobId The identifier of the newly submitted job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT CreateAndSubmitFrom(const CATUnicodeString& jobId, CATUnicodeString& submittedJobId, CATUnicodeString& error);

  /**
  * Enables to remove a job from the database
  * @param jobId The identifier of the targeted job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT RemoveJob(const CATUnicodeString& jobId, CATUnicodeString& error);

  /**
  * Enables to remove jobs from the database
  * @param vecJobIds List of jobs identifiers to remove
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT RemoveJob(const std::vector<CATUnicodeString>& vecJobIds, CATUnicodeString& error);

private:
  friend JobControllerImpl& getImpl(const JobController& job);
  JobControllerImpl* pImpl_;
};
}

#endif /*CSIJobController_H*/
