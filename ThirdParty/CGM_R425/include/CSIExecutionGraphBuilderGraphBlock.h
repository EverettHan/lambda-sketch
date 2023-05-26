#ifndef CSIExecutionGraphBuilderGraphBlock_H
#define CSIExecutionGraphBuilderGraphBlock_H

#include "CSIExecutionGraphBuilderBlock.h"
#include "CSICommandBinderModule.h"
#include <string>

namespace JSON
{
  class JOStream;
}

namespace CSI
{
  class Parameters;

  namespace ExecutionGraph
  {
    namespace Builder
    {
      class Block;
      class NodeIdSelector;
      class GraphBlockImpl;
      class ParametersFactory;
      class Port;
      class RuntimeSettings;

/* Build a graph and generate a function's implementation settings */
      class ExportedByCSIBinderModule GraphBlock : public Block
      {
      public:
        GraphBlock();
        GraphBlock(const std::string name);
        GraphBlock(const GraphBlock&);
        GraphBlock& operator=(const GraphBlock&);
        GraphBlock(GraphBlock&&) noexcept;
        GraphBlock& operator=(GraphBlock&&) noexcept;

        bool AddBlock(Block&);

        bool AddControlFlow(Port srcPort, Port dstPort);
        bool AddDataFlow(Port srcPort, Port dstPort);

        bool AddNodeIdSelector(NodeIdSelector);

        bool SetRuntimeSettings(RuntimeSettings);

        JSON::JOStream ToJSON() const;
        Parameters ToParameters(ParametersFactory)const;

        Port GetLocalDataPort(Path path) const;

        bool AddLocalDataPort(Path path, Parameters& value);

        template <typename T>
        bool AddLocalDataPort(ParametersFactory, Path path, T value);

      private:
        bool AddLocalDataPortNoHelper(Path path, Parameters& value);

      private:
        friend GraphBlockImpl& getImpl(const GraphBlock&);
      };
    }
  }
}

template <typename T>
bool CSI::ExecutionGraph::Builder::GraphBlock::AddLocalDataPort(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, Path path, T value)
{
  if (path.size() == 0u)
    return false;
  CSI::Parameters parameters = CreateLocalDataPortParameters(parametersFactory, path.back(), value);
  Path callPath({ "localData" });
  callPath.insert(callPath.end(), path.begin(), path.end());
  return AddLocalDataPortNoHelper(callPath, parameters);
}

#endif
