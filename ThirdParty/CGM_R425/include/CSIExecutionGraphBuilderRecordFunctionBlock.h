#ifndef CSIExecutionGraphBuilderRecordFunctionBlock_H
#define CSIExecutionGraphBuilderRecordFunctionBlock_H

#include "CSIExecutionGraphBuilderFunctionBlock.h"
#include "CSICommandBinderModule.h"

#include <string>

namespace CSI
{
  class Parameters;

  namespace ExecutionGraph
  {
    namespace Builder
    {
      class RecordFunctionBlockImpl;

      class ExportedByCSIBinderModule RecordFunctionBlock : public FunctionBlock
      {
      public:
        RecordFunctionBlock(const std::string pool, const std::string name, int version);
        RecordFunctionBlock(const RecordFunctionBlock&);
        RecordFunctionBlock& operator=(const RecordFunctionBlock&);
        RecordFunctionBlock(RecordFunctionBlock&&) noexcept;
        RecordFunctionBlock& operator=(RecordFunctionBlock&&) noexcept;

        bool SetInput(const Parameters&);
        bool SetSuccess(const Parameters&);
        bool SetError(const Parameters&);
        bool AddProgress(const Parameters&);

      private:
        friend RecordFunctionBlockImpl& getImpl(const RecordFunctionBlock&);
      };
    }
  }
}

#endif
