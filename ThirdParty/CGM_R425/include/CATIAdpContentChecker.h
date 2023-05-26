/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2011
//==================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIAdpContentChecker_H
#define CATIAdpContentChecker_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATAdpComponentModificationState.h"
class CATIAdpPLMIdentificator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpContentChecker;
#else
extern "C" const IID IID_CATIAdpContentChecker;
#endif

/**
 * Interface defining the protocol enabling to be informed about the Components being treated through a transaction.
 * <br><b>Role</b>: This interface, implemented by the caller of @href CATAdpProtectedSaver#Save for example, enables the caller to be 
 * informed about the Component which will be trated during a transaction and enables him to ask the process to be stopped.
 */
class ExportedByCATPLMIntegrationAccess CATIAdpContentChecker: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Informs about a Component which will be treated during the transaction.
 * <br><b>Role</b>: Enables the user to be informed about a Component which will be part of the next Transaction. The user
 * can decide to cancel the operation right after the call.
 *
 * @param iComponent [in]
 *   The component being part of the Transaction.
 * @param iModificationState [in]
 *   The modification state of the Component in the Authoring Session.
 * @param oCancelOperation [out]
 *   The resulting diagnostic describing if the transaction must be stopped or not.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Component was succesfully analyzed.</li>
 *   <li><code>E_FAIL</code> if an internal error occured.</li>
 *   <li><code>E_INVALIDARG</code> if the provided Component is nul.</li>
 *   </ul>
 */
  virtual HRESULT InformOnComponent( CATIAdpPLMIdentificator * iComponent, CATAdpComponentModificationState::ModificationState iModificationState, 
                                     CATBoolean & oCancelOperation )=0;
/** 
 * Asks the user if the Transaction must be canceled or not.
 * <br><b>Role</b>: Enables the current Operation to ask the user if the process must be canceled. This method
 * is called once all the Components have been given to the user through the @href InformOnComponent entry point.
 *
 * @param oCancelOperation [out]
 *   The resulting diagnostic describing if the transaction must be stopped or not.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the operation was succesfully performed.</li>
 *   <li><code>E_FAIL</code> if an internal error occured.</li>
 *   </ul>
 */
  virtual HRESULT CancelOperation( CATBoolean & oCancelOperation )=0;
};
CATDeclareHandler(CATIAdpContentChecker, CATBaseUnknown);
#endif

