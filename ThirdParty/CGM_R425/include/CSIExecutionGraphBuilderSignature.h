#ifndef CSIExecutionGraphBuilderSignature_H
#define CSIExecutionGraphBuilderSignature_H

#include "CSICommandBinderModule.h"

namespace JSON
{
  class JIStream;
}

namespace CSI
{
  class Parameters;
}

ExportedByCSIBinderModule bool SerializeSignatureToParameters(const JSON::JIStream& jis, CSI::Parameters& parameters);

#endif /*CSIExecutionGraphBuilderSignature*/
