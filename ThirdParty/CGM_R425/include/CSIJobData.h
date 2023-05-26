//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/11
//===================================================================

#ifndef CSIJobData_H
#define CSIJobData_H

#include "CSICommandBinderModule.h"
#include "CSIParameters.h"

#include "DSUnicodeString.h"

#include <memory>

namespace CSI
{

/**
* Class that wraps job CSI::Parameters data such as inputs, progress and answers
*/
class ExportedByCSIBinderModule JobData
{
public:
  explicit JobData(const Parameters& jobProperties);
  ~JobData() = default;

  JobData(const JobData& rhs) = default;
  JobData& operator=(const JobData& rhs) = default;

  void ToParameters(Parameters& parameters) const;

  const Parameters* GetInputs() const;
  const Parameters* GetProgress() const;
  const Parameters* GetAnswer() const;

private:
  std::unique_ptr<Parameters> inputs_;
  std::unique_ptr<Parameters> progress_;
  std::unique_ptr<Parameters> answer_;
};
}

#endif /*CSIJobData_H*/
