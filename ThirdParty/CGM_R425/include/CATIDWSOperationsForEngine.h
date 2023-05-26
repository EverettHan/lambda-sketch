/**
 * @level Protected
 * @usage U5
 */
#ifndef CATIDWSOperationsForEngine_H
#define CATIDWSOperationsForEngine_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIDWSOperationsForEngine;
#else
extern "C" const IID IID_CATIDWSOperationsForEngine ;
#endif

//class CATDWSContext;
class CATPLMID;
class CATIAdpErrorMonitor;
class CATListValCATPLMID;
class CATIDWSTransaction;

/**
 * Interface allowing an engine to perform DWS operation.
 */
class ExportedByCATPLMIntegrationInterfaces CATIDWSOperationsForEngine : public CATBaseUnknown
{
  CATDeclareInterface;

public:

 /**
  * Sets the context (the given object gives access to WorkspaceId and Mapping Table).
  */
  //virtual HRESULT SetWorkspaceContext(CATDWSContext & iContext) = 0;
  virtual HRESULT SetErrorMonitor(CATIAdpErrorMonitor * iMonitor) = 0;

  enum ModificationState { Undefined=0, Created=1, Modified=2, Destroyed=3, Loaded=4 };
  virtual HRESULT InformOnComponents(CATIDWSTransaction * iTransaction) = 0;
  virtual HRESULT InformOnComponent(const CATPLMID & iComponent,
                                    CATIDWSOperationsForEngine::ModificationState iModificationState,
                                    CATBoolean & oWorkInReference) = 0;

  virtual HRESULT SetObjectsReservation() = 0;

  virtual HRESULT Commit(CATListValCATPLMID & iNewComponents) = 0;

  virtual HRESULT Rollback() = 0;

};

CATDeclareHandler(CATIDWSOperationsForEngine, CATBaseUnknown);

#endif
