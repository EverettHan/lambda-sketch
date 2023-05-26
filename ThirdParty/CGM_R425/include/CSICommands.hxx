#include "CSITypes.h"

namespace CSI
{

template <class T>
[[deprecated("CSI COMMAND BINDER - DEPRECATED - 2020/02/04 - Method Commands::CreateParameters(...) is deprecated, please use Node::CreateParameters(...) instead")]]
Parameters Commands::CreateParameters(const CATUnicodeString& type, const T& value) const
{
  return GetTypes().CreateParameters(type, value);
}
}
