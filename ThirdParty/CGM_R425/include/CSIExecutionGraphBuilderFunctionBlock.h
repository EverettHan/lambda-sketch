#ifndef CSIExecutionGraphBuilderFunctionBlock_H
#define CSIExecutionGraphBuilderFunctionBlock_H

#include "CSIExecutionGraphBuilderBlock.h"
#include "CSICommandBinderModule.h"

#include <string>

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class FunctionBlockImpl;

      class ExportedByCSIBinderModule FunctionBlock : public Block
      {
      public:
        FunctionBlock(const std::string pool, const std::string name, int version);
        FunctionBlock(const FunctionBlock&);
        FunctionBlock& operator=(const FunctionBlock&);
        FunctionBlock(FunctionBlock&&) noexcept;
        FunctionBlock& operator=(FunctionBlock&&) noexcept;

        FunctionBlock(BlockImpl& impl);

      private:
        friend FunctionBlockImpl& getImpl(const FunctionBlock&);
      };
    }
  }
}

#endif
