//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/11
//===================================================================

#ifndef CSIJobCreationProperties_H
#define CSIJobCreationProperties_H

#include "CSICommandBinderModule.h"
#include "CSIJobStatus.h"
#include "CSIJobPriority.h"
#include "CSIParameters.h"

#include "DSUnicodeString.h"

namespace
{
  const int DEFAULT_TTK = INT_MAX;
  const int DEFAULT_TTL = 60;
  const CSI::JobPriority DEFAULT_PRIORITY = CSI::JobPriority::normal;
  const CSI::JobStatus DEFAULT_STATUS = CSI::JobStatus::created;
}

namespace CSI
{
/**
* Class that wraps creation properties information about a job
*/
class ExportedByCSIBinderModule JobCreationProperties
{
public:
  explicit JobCreationProperties(const Parameters& properties);
  ~JobCreationProperties() = default;

  JobCreationProperties(const JobCreationProperties& rhs) = default;
  JobCreationProperties& operator=(const JobCreationProperties& rhs) = default;

public:
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
  * @return the tenant of the associated job
  */
  CATUnicodeString GetTenant() const;

  /**
  * @return the inputs of the associated job
  */
  Parameters GetInputs() const; //renvoyé CSI::Clob/Blob/Data/JobData vide

  /**
  * @return true if the associated job has inputs
  */
  bool HasInputs() const;

  /**
  * @return the keep all progress option value
  */
  bool GetKeepProgress() const;

  /**
  * @return the estimated memory in MB of the job
  */
  int GetEstimatedMemoryInMB() const;

  /**
  * @return the custom metric of the job
  */
  int GetCustomMetric() const;

  /**
  * @return the custom properties of the associated job
  */
  CATUnicodeString GetCustomProperties() const;

  /**
  * @return true if the associated job has custom properties
  */
  bool HasCustomProperties() const;

private:
  CATUnicodeString pool_;
  CATUnicodeString identifier_;
  CATUnicodeString functionName_;
  CATUnicodeString casUser_;
  CATUnicodeString credentials_;
  CATUnicodeString tenant_;
  int functionVersion_ = 0;
  int ttk_ = DEFAULT_TTK;
  int ttl_ = DEFAULT_TTL;
  JobPriority priority_ = DEFAULT_PRIORITY;
  JobStatus status_ = DEFAULT_STATUS;
  int estimatedMemoryInMB_ = 0;
  int customMetric_ = 0;
  Parameters inputs_;
  CATUnicodeString customProperties_;
  bool hasInputs_;
  bool keepProgress_;
  bool hasCustomProperties_;
};
}

#endif /*CSIJobCreationProperties_H*/
