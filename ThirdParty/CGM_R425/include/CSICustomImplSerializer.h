#ifndef CSICustomImplSerializer_H
#define CSICustomImplSerializer_H

#include "CATSysErrorDef.h"

namespace JSON
{
class JOStream;
}

namespace CSI
{
class Parameters;

class CustomImplSerializer
{
public:
  CustomImplSerializer() = default;
  virtual ~CustomImplSerializer() = default;

  CustomImplSerializer(const CustomImplSerializer&) = delete;
  CustomImplSerializer& operator=(const CustomImplSerializer&) = delete;

  virtual HRESULT Serialize(Parameters& /*out*/) const { return S_OK; }
  virtual HRESULT SerializeToJSON(JSON::JOStream& /*out*/) const { return S_OK; }
};
}

#endif
