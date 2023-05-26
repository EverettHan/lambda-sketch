#ifndef CSIParametersTools_h
#define CSIParametersTools_h

#include "CSICommandBinderModule.h"
#include <vector>
#include "DSUnicodeString.h"

namespace CSI
{
  class Parameters;

  namespace ParametersHelper
  {
    ExportedByCSIBinderModule bool FindDifferences(const CATUnicodeString& context, const CSI::Parameters& lhs, const CSI::Parameters& rhs, std::vector<CATUnicodeString>& differences);
  };
}

#endif
