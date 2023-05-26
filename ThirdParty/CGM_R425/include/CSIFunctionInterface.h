//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/18
//===================================================================

#ifndef CSIFunctionInterface_H
#define CSIFunctionInterface_H

#include "CSICommandBinderModule.h"
#include "CATSysErrorDef.h"

namespace CSI
{
class Channel;
class Node;
class Parameters;

class ExportedByCSIBinderModule FunctionInterface
{
public:
           FunctionInterface() = default;
  virtual ~FunctionInterface() = default;

  FunctionInterface(const FunctionInterface&) = delete;
  FunctionInterface& operator=(const FunctionInterface&) = delete;

  virtual HRESULT OnCall(const Parameters& parameters, Channel& origin) = 0;
};
}

#include "DSYExport.h"

#define CSI_INSTANTIATE_FUNCTION(className, pool, function, version) \
extern "C" \
{ \
  DSYExport CSI::FunctionInterface* CFI_##pool##_##function##version(CSI::Node&) \
  { \
    return new className(); \
  } \
  DSYExport void DFI_##pool##_##function##version(CSI::FunctionInterface* f) \
  { \
    delete f; \
  } \
}

#define CSI_INSTANTIATE_FUNCTION_WITH_NODE(className, pool, function, version) \
extern "C" \
{ \
  DSYExport CSI::FunctionInterface* CFI_##pool##_##function##version(CSI::Node& node) \
  { \
    return new className(node); \
  } \
  DSYExport void DFI_##pool##_##function##version(CSI::FunctionInterface* f) \
  { \
    delete f; \
  } \
}

#endif /*CSIFunctionInterface_H*/
