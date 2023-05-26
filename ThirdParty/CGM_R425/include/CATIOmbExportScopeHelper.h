#ifndef __CATIOmbExportScopeHelper_H
#define __CATIOmbExportScopeHelper_H

// System
#include "CATError.h"
// ObjectModelerCollection
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxSet.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATPLMCEStamp.h"
// CATPLMIdentification
// ObjectModelerBase
#include "CATOmbImportExportParameters.h"
#include "CATPLMStreamDescriptorForAll.h"

class CATComponentId;

/**
 * Interface allowing to retrieve download streams in the PLMCache for components with a concurrency check.
 * Do not use this interface to bypass switch engine.
 * Do not use without Omb team approval.
 * Try to factorize calls as each call to CATIOmbExportScopeHelper::DownloadStreamsAndReset may trigger a database query.
 * Usage:
 * CATOmbImportExportParameters* myparams;
 * Add information in my Params;
 * CATOmxSR<CATIOmbExportScopeHelper> hESH=CATIOmbExportScopeHelper::Create(myparams);
 * if(hESH)
 * {
 *   HRESULT hr=hESH->RegisterComponent(myComponentId,myComponenCEStamp);
 *   // do it as many time as you have component
 *   
 *   CATComponentIds oListFailures;
 *   hr=DownloadStreamsAndReset(oListFailures);
 *  ...
 *  }
 *
 */
class ExportedByCATPLMStreamDescriptor CATIOmbExportScopeHelper: public CATOmxSharable
{
public:
  /**
  * in iCtx we store some information such as type of data to be downloaded (CATPart, cgr,...)
  */
  static CATOmxSR<CATIOmbExportScopeHelper> Create(CATOmbImportExportParameters* iCtx);

  /**
  * Register component for whom we check if a stream needs to be dowloaded
  * @return
   *   S_OK if everything ran fine
   *   E_FAIL the component is not valid
  */
  virtual HRESULT RegisterComponent(CATComponentId& iID, CATPLMCEStamp& iStamp)=0;
  /**
  * Prefetch urls
  * this would download all requested urls
  * @params oFailures
  *  the list of component for which no download could be performed
  * @return: 
   *   The first failure HRESULT encountered during execution.
   *   S_OK if everything ran fine
   *   E_XXX at least one of the queries have failed (concurrent acces issue or download failure)
  */
  virtual HRESULT DownloadStreamsAndReset(CATComponentIds& oFailures)=0;

};

#endif
