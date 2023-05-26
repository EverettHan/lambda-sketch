#ifndef CSIExecutionGraphBuilderLogicalOnlyOneBlock_H
#define CSIExecutionGraphBuilderLogicalOnlyOneBlock_H

#include "CSIExecutionGraphBuilderBlock.h"
#include "CSICommandBinderModule.h"
#include "CSIExecutionGraphBuilderType.h"

#include <string>

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class OnlyOneBlockImpl;
      class Port;

      class ExportedByCSIBinderModule OnlyOneBlock : public Block
      {
      public:
        OnlyOneBlock(size_t ioCount);
        OnlyOneBlock(const OnlyOneBlock&);
        OnlyOneBlock& operator=(const OnlyOneBlock&);
        OnlyOneBlock(OnlyOneBlock&&) noexcept;
        OnlyOneBlock& operator=(OnlyOneBlock&&) noexcept;

        //control flow in, index must be >= 1
        Port GetInPort(size_t index) const;

        //control flow out
        Port GetOutPort() const;

        //data flow in, index must be >= 1
        Port GetValuePort(size_t index) const;

        template <typename T>
        bool AddValueDefaultValue(ParametersFactory, size_t index, T value);

        //data flow out
        Port GetSelectedValuePort() const;

      private:
        std::string GetValuePropertyName(size_t index) const;

      private:
        friend OnlyOneBlockImpl& getImpl(const OnlyOneBlock&);
      };
    }
  }
}

template <typename T>
bool CSI::ExecutionGraph::Builder::OnlyOneBlock::AddValueDefaultValue(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, size_t index, T value)
{
  return AddCallDefaultValue(parametersFactory, { GetValuePropertyName(index) }, value);
}

#endif
