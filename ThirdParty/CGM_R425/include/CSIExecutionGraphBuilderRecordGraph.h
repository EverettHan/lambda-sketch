#ifndef CSIExecutionGraphBuilderRecordGraph_H
#define CSIExecutionGraphBuilderRecordGraph_H

#include "CSICommandBinderModule.h"

#include <string>

namespace JSON
{
  class JOStream;
}

/* Generate a record json from a GraphBlock*/
namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class GraphBlock;
      class RecordGraphImpl;

      class ExportedByCSIBinderModule RecordGraph
      {
      public:
        RecordGraph(std::string serverPool, GraphBlock&, std::string description);
        RecordGraph(const RecordGraph&);
        RecordGraph& operator=(const RecordGraph&);
        RecordGraph(RecordGraph&&) noexcept;
        RecordGraph& operator=(RecordGraph&&) noexcept;
        ~RecordGraph();

        JSON::JOStream ToJSON() const;

      private:
        friend RecordGraphImpl& getImpl(const RecordGraph&);
        RecordGraphImpl* impl_;
      };
    }
  }
}

#endif
