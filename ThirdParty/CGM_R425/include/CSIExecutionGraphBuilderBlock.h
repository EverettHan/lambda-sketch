#ifndef CSIExecutionGraphBuilderBlock_H
#define CSIExecutionGraphBuilderBlock_H

#include "CSICommandBinderModule.h"
#include "CSIExecutionGraphBuilderPort.h"

#include <string>
#include <vector>

namespace CSI
{
  class Parameters;

  namespace ExecutionGraph
  {
    namespace Builder
    {
      class BlockImpl;
      class NodeIdSelector;
      class ParametersFactory;
      class Port;

      typedef std::vector<std::string> Path;

      class ExportedByCSIBinderModule Block
      {
      public:
        Block(BlockImpl& impl);
        Block(const Block&) = delete;
        Block& operator=(const Block&) = delete;
        Block(Block&&) noexcept = delete;
        Block& operator=(Block&&) noexcept = delete;
        virtual ~Block() = 0;

        bool SetNodeIdSelector(NodeIdSelector&);
        bool SetNodeIdSelectorParent();

        Port GetCallPort() const;
        Port GetCallPort(Path path) const;

        Port GetSuccessPort() const;
        Port GetSuccessPort(Path path) const;

        Port GetProgressPort() const;
        Port GetProgressPort(Path path) const;

        Port GetErrorPort() const;
        Port GetErrorPort(Path path) const;

        bool AddCallDefaultValue(Parameters& value);
        bool AddCallDefaultValue(Path path, Parameters& value);
        template <typename T>
        bool AddCallDefaultValue(ParametersFactory, Path path, T value);

      protected:
        friend BlockImpl& getImpl(const Block&);
        BlockImpl* impl_;

      protected:
        bool AddDefaultValue(Path path, Parameters& value);

        Port GetPort(std::string) const;
        Port GetPort(Path path) const;

        template<typename T>
        Parameters CreateLocalDataPortParameters(ParametersFactory, std::string propertyName, T value) const;
      };
    }
  }
}

#include "CSIExecutionGraphBuilderBlock.hxx"

#endif
