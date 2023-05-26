#ifndef CATDWSTransactionImpl_h
#define CATDWSTransactionImpl_h

#include "CATPLMIntegrationBase.h"
#include "CATIDWSTransaction.h"
#include "CATBoolean.h"
#include "CATPLMID.h"
#include "CATLISTV_CATPLMID.h"

class ExportedByCATPLMIntegrationBase CATDWSTransactionImpl : public CATIDWSTransaction
{
  CATDeclareClass;

public:
  CATDWSTransactionImpl(const CATPLMID & iWorkspaceId);
  virtual ~CATDWSTransactionImpl();

  // methodes de CATIDWSTransaction
  HRESULT GetWorkspaceId(CATPLMID & oWorkspaceId);
  HRESULT GetNextComponent(CATPLMID & oPLMID);
  HRESULT ShouldRunInConnectedWorkspace();
  HRESULT ShouldRunInReferenceWorkspace();

  HRESULT AddComponent(const CATPLMID & iComponent);
  HRESULT InWhichWorkspace(CATBoolean & oInConnectedWorkspace);

private:
  CATPLMID _WorkspaceId;
  CATPLMIDs _Components;
  int _index; // index of the next component to return. From 1 to _Components.Size()+1
  enum Context { Unspecified=0, InConnectedWorkspace=1, InReference=2, Inconsistent=3 };
  Context _RunInWorkspace;
};
#endif
