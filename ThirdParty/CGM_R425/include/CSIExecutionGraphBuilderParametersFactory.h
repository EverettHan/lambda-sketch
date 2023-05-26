#ifndef CSIExecutionGraphBuilderParametersFactory_H
#define CSIExecutionGraphBuilderParametersFactory_H

#include "CSICommandBinderModule.h"

namespace CSI
{
  class Commands;
  class Node;
  class Types;
  class Parameters;

  namespace ExecutionGraph
  {
    namespace Builder
    {
      class ParametersFactoryImpl;

      class ExportedByCSIBinderModule ParametersFactory
      {
      public:
        ParametersFactory(const Commands&);
        ParametersFactory(const Types&);
        ParametersFactory(const Node&);
        ParametersFactory(const Parameters&);

        ParametersFactory(const ParametersFactory&);
        ParametersFactory& operator=(const ParametersFactory&);
        ParametersFactory(ParametersFactory&&) noexcept;
        ParametersFactory& operator=(ParametersFactory&&) noexcept;
        ~ParametersFactory();

        Parameters CreateParameters() const;

      private:
        friend ParametersFactoryImpl& getImpl(const ParametersFactory& ParametersFactory);
        ParametersFactoryImpl* impl_;
      };
    }
  }
}

#endif
