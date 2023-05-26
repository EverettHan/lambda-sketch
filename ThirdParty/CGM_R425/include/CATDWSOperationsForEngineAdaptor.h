/**
* @level Protected
* @usage U2
*/
#ifndef CATDWSOperationsForEngineAdaptor_H
#define CATDWSOperationsForEngineAdaptor_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATIDWSOperationsForEngine.h"
#include "CATCollec.h"

class CATIDWSTransaction;
class CATListValCATPLMID;
class CATPLMID;
class CATIAdpErrorMonitor;
/**
 * This class is the adaptor corresponding to the  CATIDWSOperationsForEngine interface.
 * <br>This adaptor is supplied only for a better flexibility of CATIDWSOperationsForEngine; the methods are not really implemented.
 */
class ExportedByCATPLMIntegrationInterfaces CATDWSOperationsForEngineAdaptor: public CATIDWSOperationsForEngine
{
public:

  // Standard constructors and destructors
  // -------------------------------------
  CATDWSOperationsForEngineAdaptor ();
  virtual ~CATDWSOperationsForEngineAdaptor ();

  /**
   * @see CATPLMIntegrationInterfaces.CATIDWSOperationsForEngine#SetErrorMonitor
   */
  HRESULT SetErrorMonitor(CATIAdpErrorMonitor * iMonitor);

  /**
   * @see CATPLMIntegrationInterfaces.CATIDWSOperationsForEngine#InformOnComponents
   */
  HRESULT InformOnComponents(CATIDWSTransaction * iTransaction);

  /**
   * @see CATPLMIntegrationInterfaces.CATIDWSOperationsForEngine#InformOnComponent
   */
  HRESULT InformOnComponent(const CATPLMID & iComponent,
                            CATIDWSOperationsForEngine::ModificationState iModificationState,
                            CATBoolean & oCancelOperation);

  /**
   * @see CATPLMIntegrationInterfaces.CATIDWSOperationsForEngine#SetObjectsReservation
   */
  HRESULT SetObjectsReservation();

  /**
   * @see CATPLMIntegrationInterfaces.CATIDWSOperationsForEngine#Commit
   */
  HRESULT Commit(CATListValCATPLMID & iNewComponents);

  /**
   * @see CATPLMIntegrationInterfaces.CATIDWSOperationsForEngine#Rollback
   */
  HRESULT Rollback();

};

//-----------------------------------------------------------------------

#endif
