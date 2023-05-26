//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef CSIJobAdministration_H
#define CSIJobAdministration_H

#include "CSICommandBinderModule.h"

#include "CSIJobQueryRunner.h"
#include "DSUnicodeString.h"

#include <vector>

namespace CSI
{
class JobContext;
class JobAdministrationImpl;
class JobSelectQuery;

/**
* Class that enables to contact the queuing database in order to retrieve or modify jobs' information.
*/
class ExportedByCSIBinderModule JobAdministration
{
public:
  explicit JobAdministration(const JobContext& ctx);

  JobAdministration(const JobAdministration&) = delete;
  JobAdministration& operator=(const JobAdministration&) = delete;

  ~JobAdministration();

  HRESULT RemoveJobs(const std::vector<CATUnicodeString>& vecJobIds, CATUnicodeString& error);

  HRESULT CancelJobs(const std::vector<CATUnicodeString>& vecJobIds, CATUnicodeString& error);

  JobQueryResult ExecuteAsAdmin(const JobSelectQuery& query);

  [[deprecated("Use RemoveJobs() instead")]]
  HRESULT RemoveJob(const std::vector<CATUnicodeString>& vecJobIds, CATUnicodeString& error);
private:
  friend JobAdministrationImpl& getImpl(const JobAdministration& job);
  JobAdministrationImpl* pImpl_;
};
}

#endif /*CSIJobAdministration_H*/
