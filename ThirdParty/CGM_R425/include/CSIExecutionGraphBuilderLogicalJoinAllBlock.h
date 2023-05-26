#ifndef CSIExecutionGraphBuilderLogicalJoinAllBlock_H
#define CSIExecutionGraphBuilderLogicalJoinAllBlock_H

#include "CSIExecutionGraphBuilderBlock.h"
#include "CSICommandBinderModule.h"

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class JoinAllBlockImpl;
      class Port;

      class ExportedByCSIBinderModule JoinAllBlock : public Block
      {
      public:
        JoinAllBlock();
        JoinAllBlock(const JoinAllBlock&);
        JoinAllBlock& operator=(const JoinAllBlock&);
        JoinAllBlock(JoinAllBlock&&) noexcept;
        JoinAllBlock& operator=(JoinAllBlock&&) noexcept;

        Port GetInPort() const;   //control flow in
        Port GetOutPort() const;  // control flow out

      private:
        friend JoinAllBlockImpl& getImpl(const JoinAllBlock&);
      };
    }
  }
}

#endif
