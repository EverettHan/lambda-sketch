// COPYRIGHT Dassault Systemes 2015
#ifndef CATPLMPathDataCst_H
#define CATPLMPathDataCst_H

#include "CATPLMIdentificationAccess.h"

#include "CATOmxKeyString.h"

class ExportedByCATPLMIdentificationAccess CATPLMPathDataCst
{
public:
  enum SynchroStatus{NotValuated=0,Synch=2,Unsynch=3,Broken=1,};

  enum RelevanceStatus{relevant=0,not_relevant=1,not_computed=2};

  //s() like singleton...
  static const CATPLMPathDataCst& s();

  CATOmxKeyString ksupdatestamp,ksC_updatestamp;

private:
  CATPLMPathDataCst();
  ~CATPLMPathDataCst();
};

#endif
