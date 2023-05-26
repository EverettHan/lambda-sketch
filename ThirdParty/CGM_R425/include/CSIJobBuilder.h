//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/11
//===================================================================

#ifndef CSIJobBuilder_H
#define CSIJobBuilder_H

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
* The JobBuilder aims at building a job instance, giving its mandatory properties (pool, functionName, functionVersion)
* and its optional properties if needed.
*/
class ExportedByCSIBinderModule JobBuilder
{
public:
  /**
  * Creates a JobBuilder instance
  * @param context job context to use
  * @param pool pool of the server node
  * @param functionName name of the CSI function
  * @param functionVersion version of the CSI function
  */
  JobBuilder(const JobContext& context, const CATUnicodeString& pool, const CATUnicodeString& functionName, int functionVersion);
  ~JobBuilder() = default;

  JobBuilder(const JobBuilder&) = delete;
  JobBuilder& operator=(const JobBuilder&) = delete;

  /**
  * Create a Job in the database
  * @param jobId The identifier of the new job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT Create(CATUnicodeString& jobId, CATUnicodeString& error);

  /**
  * Create and submit a Job in the database
  * @param jobId The identifier of the new submitted job
  * @param error The message of a queuing error which may occur
  * @return S_OK if successful, S_FALSE if there was a queuing error, E_FAIL otherwise
  */
  HRESULT CreateAndSubmit(CATUnicodeString& jobId, CATUnicodeString& error);

  /**
  * Set the ttk value (in hours) of the Job object that will be built
  * Default is 24 * 7
  * @return this JobBuilder
  */
  JobBuilder& TTK(int ttk);

  /**
  * Set the ttl value (in minutes) of the Job object that will be built
  * Default is 60
  * @param ttl the ttl value of the Job
  * @return this JobBuilder
  */
  JobBuilder& TTL(int ttl);

  /**
  * Set the JobPriority of the Job object that will be built
  * Default is JobPriority.normal
  * @param priority the JobPriority of the Job
  * @return this JobBuilder
  */
  JobBuilder& Priority(JobPriority priority);

  /**
  * Set the inputs of the compute node that must execute the Job object that will be built
  * Default is empty
  * @param inputs the inputs of the compute node that must execute the Job
  * @return this JobBuilder
  */
  JobBuilder& Inputs(const Parameters& inputs);

  /**
  * Set the identifier of the compute node that must execute the Job object that will be built
  * Default is empty
  * @param identifier the identifier of the compute node that must execute the Job
  * @return this JobBuilder
  */
  JobBuilder& Identifier(const CATUnicodeString& identifier);

  /**
  * Set the custom properties of the job
  * Default is empty
  * @param customProp custom properties to set
  * @return this JobBuilder
  */
  JobBuilder& CustomProperties(const JSON::JIStream& customProp);

 /**
  * Set the estimated memory in MB of the job
  * Default estimation is 0MB
  * @param memInMB the estimated memory in MB
  * @return this JobBuilder
  */
  JobBuilder& EstimatedMemoryInMB(int memInMB);

  /**
  * Set the custom metric of the job
  * Default metric is zero
  * @param metric custom metric that will be associated with the job
  * @return this JobBuilder
  */
  JobBuilder& CustomMetric(int metric);

  /**
  * Set how job progress are stored.
  * By default each progress parameter overwrites the previous one,
  * if keepAllProgress is set then all progress parameters are kept.
  * @return this JobBuilder
  */
  JobBuilder& KeepAllProgress();

private:
  const JobContext context_;
  const CATUnicodeString functionName_;
  const int functionVersion_;
  const CATUnicodeString pool_;
  Parameters jobCreationProperties_;
};
}

#endif /*CSIJobBuilder_H*/
