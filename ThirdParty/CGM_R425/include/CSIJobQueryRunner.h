//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//===================================================================

#ifndef CSIJobQueryRunner_H
#define CSIJobQueryRunner_H

#include "CSICommandBinderModule.h"

#include "CSIJobCondition.h"
#include "CSIJobProperties.h"

#include "DSUnicodeString.h"

#include <ctime>
#include <vector>

namespace CSI
{
  class JobContext;
  class JobQueryRunnerImpl;
  class JobSelectQuery;

  struct JobQueryResult
  {
    std::vector<JobProperties> jobs;
    int jobsCount = 0;
    int errorCode = 0;
    CATUnicodeString errorMsg;
  };

  class ExportedByCSIBinderModule JobQueryRunner
  {
  public:
    JobQueryRunner(const JobContext& ctx);
    ~JobQueryRunner();

    JobQueryResult Execute(const JobSelectQuery& query);

    // JobQueryResult ExecuteAsAdmin(const JobSelectQuery& query);

  private:
    friend JobQueryRunnerImpl& getImpl(const JobQueryRunner& job);
    JobQueryRunnerImpl* pImpl_;
  };
} // namespace CSI

#endif
