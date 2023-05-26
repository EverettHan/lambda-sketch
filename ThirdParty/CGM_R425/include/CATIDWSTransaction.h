/**
 * @level Protected
 * @usage U5
 */
#ifndef CATIDWSTransaction_H
#define CATIDWSTransaction_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIDWSTransaction;
#else
extern "C" const IID IID_CATIDWSTransaction ;
#endif

class CATPLMID;

/**
 * This interface allows the implementation of CATIDWSOperationsForEngine to know:
 *   - the contextual workspace
 *   - the components treated by the engine
 * and to tell the engine whether the operation must be run in the connected DWS or in the reference.
 * A pointer to this interface is given by CATIDWSOperationsForEngine::InformOnComponents.
 */
class ExportedByCATPLMIntegrationInterfaces CATIDWSTransaction : public CATBaseUnknown
{
  CATDeclareInterface;

public:

 /**
  * Provides the identifier of the contextual Designer Workspace.

  * @param oPLMID [out]
  *        The identifier of the Designer Workspace in the context of which the engine operation is run.
  *        Equals to CATPLMID_Null if no DWS specified (Reference).
  * @return
  *        S_OK    : if correct PLMID is returned
  *        E_UNEXPECTED : if some error happened
  */
  virtual HRESULT GetWorkspaceId(CATPLMID & oWorkspaceId) = 0;

 /**
  * Provides the next component treated by the engine.
  * Call the method in a while loop as long as it return S_OK:
  *   CATPLMID plmid;
  *   while (ptr->GetNextComponent(plmid) == S_OK)
  *   {
  *     // treat plmid
  *   }

  * @param oPLMID [out]
  *        The identifier of the next component treated by the engine.
  * @return
  *        S_OK         : if correct PLMID is returned
  *        S_FALSE      : if all components have already been returned. oPLMID is left unchanged.
  *        E_UNEXPECTED : if some error happened
  */
  virtual HRESULT GetNextComponent(CATPLMID & oPLMID) = 0;

 /**
  * Tells the engine that it should take the connected workspace into account.
  *
  * @return
  *        S_OK   : the engine will do as told
  *        E_FAIL : an inconsistency has been deteceted.
  *                 The ShouldRunInReferenceWorkspace method has been previoulsy called.
  *                 The engine will abort its treatment and raise an error.
  */
  virtual HRESULT ShouldRunInConnectedWorkspace() = 0;

 /**
  * Tells the engine that it should NOT take the connected workspace into account.
  *
  * @return
  *        S_OK   : the engine will do as told
  *        E_FAIL : an inconsistency has been deteceted.
  *                 The ShouldRunInConnectedWorkspace method has been previoulsy called.
  *                 The engine will abort its treatment and raise an error.
  */
  virtual HRESULT ShouldRunInReferenceWorkspace() = 0;

};

CATDeclareHandler(CATIDWSTransaction, CATBaseUnknown);

#endif
