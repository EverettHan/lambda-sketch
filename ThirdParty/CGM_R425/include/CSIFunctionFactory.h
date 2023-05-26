#ifndef CSIFunctionFactory_H
#define CSIFunctionFactory_H

#include "CATSysErrorDef.h"
#include "DSYExport.h"

namespace CSI
{
class ErrorContext;
class FunctionInterface;
class Node;

class FunctionFactory
{
public:
  FunctionFactory() = default;
  virtual ~FunctionFactory() = default;

  FunctionFactory(const FunctionFactory&) = delete;
  FunctionFactory& operator=(const FunctionFactory&) = delete;

  virtual FunctionInterface* CreateFunctionInstance(Node& node, bool debugMode, ErrorContext& errorContext) = 0;
  virtual HRESULT DeleteFunctionInstance(FunctionInterface* fun, bool debugMode) = 0;
};
}

#endif
