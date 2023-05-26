#ifndef CATPLMWorkspaceIDAdapter_H
#define CATPLMWorkspaceIDAdapter_H
// COPYRIGHT DASSAULT SYSTEMES 2010

/**
* @level Protected
* @usage U3
*/

#include "CATIPLMWorkspaceID.h"

#include "CATPLMImplAdapterClass.h"

#include "CATPLMID.h"

class ExportedByCATPLMImplAdapterClass CATPLMWorkspaceIDAdapter : public CATIPLMWorkspaceID
{
public:

  CATPLMWorkspaceIDAdapter ();
  virtual ~CATPLMWorkspaceIDAdapter ();

  virtual HRESULT GetWorkspaceID (CATPLMID &oWspID);
  virtual HRESULT SetWorkspaceID (const CATPLMID &iWspID);

private:
  CATPLMWorkspaceIDAdapter (CATPLMWorkspaceIDAdapter &);
  CATPLMWorkspaceIDAdapter& operator=(CATPLMWorkspaceIDAdapter&);

  CATPLMID _WorkspaceID;

};

#endif
