#ifndef CSIExecutionGraphBuilderPort_H
#define CSIExecutionGraphBuilderPort_H

#include "CSICommandBinderModule.h"

#include <string>
#include <vector>

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class BlockImpl;
      class PortImpl;

      class ExportedByCSIBinderModule Port
      {
      public:
        Port(BlockImpl& blockImpl, std::vector<std::string> path);
        Port(const Port&);
        Port& operator=(const Port&);
        Port(Port&&) noexcept;
        Port& operator=(Port&&) noexcept;
        ~Port();

      private:
        friend PortImpl& getImpl(const Port&);
        PortImpl* impl_;
      };
    }
  }
}

#endif
