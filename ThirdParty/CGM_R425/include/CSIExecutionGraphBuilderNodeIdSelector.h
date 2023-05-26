#ifndef CSIExecutionGraphBuilderNodeIdSelector_H
#define CSIExecutionGraphBuilderNodeIdSelector_H

#include "CSICommandBinderModule.h"

#include <string>

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class NodeIdSelectorImpl;

      class ExportedByCSIBinderModule NodeIdSelector
      {
      public:
        NodeIdSelector(const std::string id, const std::string pool);
        NodeIdSelector(const NodeIdSelector&);
        NodeIdSelector& operator=(const NodeIdSelector&);
        NodeIdSelector(NodeIdSelector&&) noexcept;
        NodeIdSelector& operator=(NodeIdSelector&&) noexcept;
        ~NodeIdSelector();

        enum ECriterion
        {
          eOnlyMyHypervisor,
          eNotMyHypervisor,
          ePreferMyHypervisor
        };

        void SetCriterionIdentifier(std::string); //overrides criterion
        void SetCriterion(ECriterion criterion); //overrides CriterionIdentifier
        void SetNoQueuing(bool);
        void SetTimeout(uint32_t);
        void SetMaxInstanceCount(uint32_t);

      private:
        friend NodeIdSelectorImpl& getImpl(const NodeIdSelector&);
        NodeIdSelectorImpl* impl_;
      };
    }
  }
}

#endif
