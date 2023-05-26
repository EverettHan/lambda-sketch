#ifndef CSIDeclarativeMacros_H
#define CSIDeclarativeMacros_H

#include "DSYExport.h"

namespace CSI
{
  class Arguments;
  class Node;
  class FunctionInterface;
  class Types;
}

#define CSIFUNCTION(className, pool, function, version) \
extern "C" \
{ \
  DSYExport FunctionInterface* CFI_##pool##_##function##version(CSI::Node& node) \
  { \
    return new className(node); \
  } \
  DSYExport void DFI_##pool##_##function##version(CSI::FunctionInterface* f) \
  { \
    delete f; \
  } \
}

#define CSICOMMAND(className, pool, function, version) \
extern "C" \
{ \
  DSYExport CSI::CommandInterface* CCI_##pool##_##function##version(CSI::Node& node) \
  { \
    return new className(node); \
  } \
  DSYExport void DCI_##pool##_##function##version(CSI::CommandInterface* ci) \
  { \
    delete ci; \
  } \
}

#define CSITYPE(typeName, serialize, unserialize) \
extern "C" \
{ \
  DSYExport HRESULT DT_##typeName(CSI::Types& csiTypes) \
  { \
    return csiTypes.DeclareType(#typeName, serialize, unserialize, strongTypingTag); \
  } \
}

#define CSIPOOLDATA(className, pool) \
extern "C" \
{ \
  DSYExport void* CPD_##pool(const CSI::Arguments& arguments) \
  { \
    return new className(arguments); \
  } \
  DSYExport void DPD_##pool(void* poolData) \
  { \
    delete static_cast<className*>(poolData); \
  } \
}

#endif
