//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef CSIJobBatcher_H
#define CSIJobBatcher_H

#include "CSICommandBinderModule.h"

#include "CSIJobContext.h"
#include "CSIJobPriority.h"
#include "CSIJobStatus.h"
#include "CSIParameters.h"

#include "DSUnicodeString.h"

namespace JSON
{
class JIStream;
}

namespace CSI
{
 /**
 * The JobBatcher aims at batching multiple jobs in a single transaction
 */
class ExportedByCSIBinderModule JobBatcher
{
public:
  /**
  * Creates a JobBatcher instance
  * @param context the client node which will send jobs to the database
  * @param pool pool of the server node
  * @param functionName name of the CSI function
  * @param functionVersion version of the CSI function
  */
   JobBatcher(const JobContext& context, const CATUnicodeString& pool, const CATUnicodeString& functionName, int functionVersion);
  ~JobBatcher() = default;

  JobBatcher(const JobBatcher&) = delete;
  JobBatcher& operator=(const JobBatcher&) = delete;

  /**
  * Create and submit a Job in the database
  * @param jobId The identifier of the new submitted job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT CreateAndSubmit(std::vector<CATUnicodeString>& jobId, CATUnicodeString& error);

  /**
  * Set the ttk value (in hours) of the Job object that will be built
  * Default is 24 * 7
  * @return this JobBatcher
  */
  JobBatcher& TTK(int ttk);

  /**
  * Set the ttl value (in minutes) of the Job object that will be built
  * Default is 60
  * @param ttl the ttl value of the Job
  * @return this JobBatcher
  */
  JobBatcher& TTL(int ttl);

  /**
  * Set the JobPriority of the Job object that will be built
  * Default is JobPriority.normal
  * @param priority the JobPriority of the Job
  * @return this JobBatcher
  */
  JobBatcher& Priority(JobPriority priority);

  /**
  * Set the inputs of the batch. A job will be created for each parameter in the array.
  * Default is null
  * @param inputs the inputs of the compute node that must execute the Job
  * @return this JobBatcher
  */
  JobBatcher& Inputs(const std::vector<Parameters>& inputs);

  /**
  * Set the identifier of the compute node that must execute the Job object that will be built
  * Default is empty
  * @param identifier the identifier of the compute node that must execute the Job
  * @return this JobBatcher
  */
  JobBatcher& Identifier(const CATUnicodeString& identifier);

  /**
  * Set the custom properties of the job
  * Default is empty
  * @param customProp custom properties to set
  * @return this JobBatcher
  */
  JobBatcher& CustomProperties(const JSON::JIStream& customProp);

  /**
  * Set the estimated memory in MB of the jobs
  * Default estimation is 0MB
  * @param memInMB the estimated memory in MB for each job
  * @return this JobBatcher
  */
  JobBatcher& EstimatedMemoryInMB(const std::vector<int>& memInMB);

  /**
  * Set the custom metric of the jobs
  * Default metric is zero 
  * @param metric custom metric that will be associated with each job
  * @return this JobBatcher
  */
  JobBatcher& CustomMetric(const std::vector<int>& metric);

  /**
  * Set how job progress are stored.
  * By default each progress parameter overwrites the previous one,
  * if keepAllProgress is set then all progress parameters are kept.
  * @return this JobBatcher
  */
  JobBatcher& KeepAllProgress();

private:
  const JobContext context_;
  Parameters jobCreationProperties_;
  };
} // namespace CSI

#endif /*CSIJobBatcher_H*/
