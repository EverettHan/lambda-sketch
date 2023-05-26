#ifndef CSIExecutionGraphBuilderLogicalSyncFlowsBlock_H
#define CSIExecutionGraphBuilderLogicalSyncFlowsBlock_H

#include "CSIExecutionGraphBuilderBlock.h"
#include "CSICommandBinderModule.h"

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class SyncFlowsBlockImpl;
      class Port;

      class ExportedByCSIBinderModule SyncFlowsBlock : public Block
      {
      public:
        SyncFlowsBlock(size_t inCount);
        SyncFlowsBlock(const SyncFlowsBlock&);
        SyncFlowsBlock& operator=(const SyncFlowsBlock&);
        SyncFlowsBlock(SyncFlowsBlock&&) noexcept;
        SyncFlowsBlock& operator=(SyncFlowsBlock&&) noexcept;

        Port GetInPort(size_t index) const; //control flow in, index must be >= 1
        Port GetOutPort() const;            //control flow out

      private:
        friend SyncFlowsBlockImpl& getImpl(const SyncFlowsBlock&);
      };
    }
  }
}

#endif
