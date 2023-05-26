#ifndef CSIExecutionGraphBuilderFunctionGraph_H
#define CSIExecutionGraphBuilderFunctionGraph_H

#include "CSICommandBinderModule.h"

#include <string>

namespace JSON
{
  class JOStream;
}

/* Generate a function's json from a GraphBlock*/
namespace CSI
{
  class Parameters;

  namespace ExecutionGraph
  {
    namespace Builder
    {
      class FunctionGraphImpl;
      class GraphBlock;
      class ParametersFactory;
      class Type;

      class ExportedByCSIBinderModule FunctionGraph
      {
      public:
        FunctionGraph(GraphBlock&, std::string description);
        FunctionGraph(const FunctionGraph&);
        FunctionGraph& operator=(const FunctionGraph&);
        FunctionGraph(FunctionGraph&&) noexcept;
        FunctionGraph& operator=(FunctionGraph&&) noexcept;
        ~FunctionGraph();

        void SetInput(Type&);
        void SetSuccess(Type&);

        JSON::JOStream ToJSON() const;
        Parameters ToParameters(ParametersFactory) const;
        Parameters ToDeclarativeDefinition(ParametersFactory, std::string name, int version) const;

      private:
        friend FunctionGraphImpl& getImpl(const FunctionGraph&);
        FunctionGraphImpl* impl_;
      };
    }
  }
}

#endif
