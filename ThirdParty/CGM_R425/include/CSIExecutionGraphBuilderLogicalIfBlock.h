#ifndef CSIExecutionGraphBuilderLogicalIfBlock_H
#define CSIExecutionGraphBuilderLogicalIfBlock_H

#include "CSIExecutionGraphBuilderBlock.h"
#include "CSICommandBinderModule.h"

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class IfBlockImpl;
      class Port;

      class ExportedByCSIBinderModule IfBlock : public Block
      {
      public:
        IfBlock();
        IfBlock(const IfBlock&);
        IfBlock& operator=(const IfBlock&);
        IfBlock(IfBlock&&) noexcept;
        IfBlock& operator=(IfBlock&&) noexcept;

        //control flow in
        Port GetInPort() const;

        //control flow out
        Port GetTruePort() const;
        Port GetFalsePort() const;

        //DataFlow In
        Port GetConditionPort() const;

        bool AddConditionDefaultValue(ParametersFactory, bool value);

      private:
        friend IfBlockImpl& getImpl(const IfBlock&);
      };
    }
  }
}

#endif
