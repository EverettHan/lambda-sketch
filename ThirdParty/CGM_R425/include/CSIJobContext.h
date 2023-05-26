//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//===================================================================

#ifndef CSIJobContext_H
#define CSIJobContext_H

#include "CSICommandBinderModule.h"

class CATUnicodeString;

namespace EK
{
class ChannelInfos;
}

namespace CSI
{
class JobContextImpl;
class Node;

class ExportedByCSIBinderModule JobContext
{
public:
  /**
  * Creates a JobContext instance
  * @param node: the client node which will send jobs to the database
  * @param infos: caller channel infos - for RESTful web services
  */
  JobContext(Node& node, const EK::ChannelInfos& infos);

  /**
  * Creates a JobContext instance
  * @param node: the client node which will send jobs to the database
  * @param tenantId: id of caller tenant
  */
  JobContext(Node& node, const CATUnicodeString& tenantId);

  ~JobContext();

  JobContext(const JobContext&);
  JobContext(JobContext&&);

  JobContext& operator=(const JobContext&);
  JobContext& operator=(JobContext&&);

private:
  friend JobContextImpl& getImpl(const JobContext& jobCtx);
  JobContextImpl* pImpl_;
};
}

#endif /*CSIJobContext_H*/
