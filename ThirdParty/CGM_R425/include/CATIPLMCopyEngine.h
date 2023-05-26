// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMCopyEngine.h
// Define the CATIPLMCopyEngine interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  May 2009  Creation: Code generated by the CAA wizard  ZUP
//===================================================================
#ifndef CATIPLMCopyEngine_H
#define CATIPLMCopyEngine_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATPLMCloningEngineAbstract.h"
#include "CATPLMCloningMode.h"
#include "CATPLMKeepAttributes.h"

class CATTime;
class CATPLMID;
class CATIPLMAttributeSet;
class CATIPLMOperationResult;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMCopyEngine;
#else
extern "C" const IID IID_CATIPLMCopyEngine;
#endif

//------------------------------------------------------------------

/**
* Interface representing the unique protocol of communication between the users and the copy engine.
* Use @href CATPLMIntegration.CATPLMEngineToolbox#GetCopyEngine to get a pointer on the cloning engine.
*
* <br><b>Role</b>: Components that implement
* CATIPLMCopyEngine is CATPLMCopyEngine.
* <p>
* Use CATIPLMCopyEngine interface to perform a copy from a specific set of components, choosing which attributes to reinitialize.
* Retrieve the new components availables after the operation.
*
* @example
*  CATIPLMCopyEngine* pCopyEngine = NULL;
*  rc = CATPLMEnginesToolbox::GetCopyEngine(clone_mode, pEngine, NULL )
*
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMCopyEngine : public CATPLMCloningEngineAbstract
{
  CATDeclareInterface;

public:

  /**
  * Adds a copy datum (reference or rep reference only) for further processing by the engine.
  * <br><b>Role</b>: Make it possible to add a copy datum in the set of data which will be processed when calling the
  * @href CATIPLMCopyEngine#RunCloningOperation entry point.
  * @param iComponent [in]
  *   The component which must be cloned
  *   <ul><li> The identifier must not be CATPLMID_Null. Otherwise, the call will result in a E_INVALIDARG return.</li></ul>
  * @param iModifiedAttributes
  *   The set of attributes which need to be applied to the new component.
  * @param iNoResetAttributes
  *   The set of attributes which need to be NOT reset. Bit mask. @href CATIPLMKeepAttributes#ReferenceNoReset
  * @param iApplicabilityDate
  *   The applicability date for the new version availability.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt> if the component can be taken into account by the engine. It was added to the set of data to be treated by the engine. </li>
  *   <li><tt>E_INVALIDARG</tt> if one of the provided entry is invalid.</li>
  *   <li><tt>E_FAIL</tt> if the operation failed.</li>
  *   </ul>
  */

  virtual HRESULT AddReferenceCloningDatum(const CATPLMID                          & iComponent,
    CATIPLMAttributeSet                       * iAttributes,
    const CATTime                                   & iApplicabilityDate,
    const CATPLMKeepAttributes::ReferenceNoReset    & iRefNoReset) = 0;

  /**
  * Adds a copy datum (instance or rep instance only) for further processing by the engine.
  * <br><b>Role</b>: Make it possible to add a copy datum in the set of data which will be processed when calling the
  * @href CATIPLMCopyEngine#RunCloningOperation entry point.
  * @param iComponent [in]
  *   The component which must be cloned
  *   <ul><li> The identifier must not be CATPLMID_Null. Otherwise, the call will result in a E_INVALIDARG return.</li></ul>
  * @param iModifiedAttributes
  *   The set of attributes which need to be applied to the new component.
  * @param iNoResetAttributes
  *   The set of attributes which need to be NOT reset. Bit mask. @href CATIPLMKeepAttributes#InstanceNoReset
  * @param iApplicabilityDate
  *   The applicability date for the new version availability.
  * @param iOwner
  *   Owner of the instance
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt> if the component can be taken into account by the engine. It was added to the set of data to be treated by the engine. </li>
  *   <li><tt>E_INVALIDARG</tt> if one of the provided entry is invalid.</li>
  *   <li><tt>E_FAIL</tt> if the operation failed.</li>
  *   </ul>
  */
  virtual HRESULT AddInstanceCloningDatum(const CATPLMID                          & iComponent,
    CATIPLMAttributeSet                       * iAttributes,
    const CATTime                                   & iApplicabilityDate,
    const CATPLMKeepAttributes::InstanceNoReset     & iInstanceNoReset,
    const CATPLMID                                  & iOwner) = 0;

  /**
  * @nodoc Deprecated version. Will make an additional call.
  **/
  virtual HRESULT AddInstanceCloningDatum(const CATPLMID                          & iComponent,
    CATIPLMAttributeSet                       * iAttributes,
    const CATTime                                   & iApplicabilityDate,
    const CATPLMKeepAttributes::InstanceNoReset     & iInstanceNoReset) = 0;

  /**
 * Requests a copy on a set of components.
 * <br><b>Role:</b>This method launches a cloning request on the components provided through the @href CATIPLMCloningEngine#AddCloningDatum entry point.<br>
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> All elements have been cloned. </li>
 *   <li><tt>E_INVALIDARG</tt> No element have been provided through the @href CATIPLMCloningEngine#AddCloningDatum entry point.</li>
 *   <li><tt>E_FAIL</tt> At least one elements has failed, nothing is committed in the base.
 *   Errors encountered are communicated through the provided @href CATIPLMEngineListener#Inform_Incident implementation.</li>
 *   </ul>
 */
  virtual HRESULT RunCloningOperation() = 0;

  /**
   * Iterator enabling to access to the results of the cloning operation.
   * <br><b>Role:</b>This method enables to get some information about the operations that were performed.<br>
   *
   * @param ioPosition  [inout]
   *   The cursor of the iterator. Provide 0 to initialize the iteration process.
   * <ul>
   * <li> The cursor is then self incremented.</li>
   * <li> A negative value will result in a E_INVALIDARG return.</li>
   * </ul>
   * @param oResult  [out,CATBaseUnknown#Release]
   *   A pointer on the result descriptor.
   * <ul>
   * <li> The result is common to a versioning operation (@href CATIPLMOperationResult).</li>
   * <li> The <code>oVersioningFamilyAncestor</code> parameter of @href CATIPLMOperationResult#GetResultIdentifiers entry point will be CATPLMID_Null.</li>
   * </ul>
   * @return
   *   <ul>
   *   <li><tt>S_OK</tt> if access is given to the next result. </li>
   *   <li><tt>S_FALSE</tt> if the end of the iteration is reached. No result is available anymore. </li>
   *   <li><tt>E_INVALIDARG</tt> the provided data are invalid.</li>
   *   <li><tt>E_FAIL</tt> if the operation failed. It can be because @href CATIPLMCloningEngine#RunCloningOperation was not triggered.</li>
   *   </ul>
   */
  virtual HRESULT NextCloningResult(int & ioPosition, CATIPLMOperationResult *& oResult) = 0;

  /**
   * Gives access to a particular result of the cloning operation.
   * <br><b>Role:</b>This method enables to get some information about the result of a particular operation.<br>
   *
   * @param iComponent [in]
   *   One of the iComponent provided though the @href CATIPLMCloningEngine#AddCloningDatum entry point.
   * @param oResult  [out,CATBaseUnknown#Release]
   *   A pointer on the result descriptor.
   * <ul>
   * <li> The result is common to a versioning operation (@href CATIPLMOperationResult).</li>
   * <li> The <code>oVersioningFamilyAncestor</code> parameter of @href CATIPLMOperationResult#GetResultIdentifiers entry point will be CATPLMID_Null.</li>
   * </ul>
   * @return
   *   <ul>
   *   <li><tt>S_OK</tt> if access is given to the searched result. </li>
   *   <li><tt>S_FALSE</tt> if there is no result associated to this component. </li>
   *   <li><tt>E_FAIL</tt> if the operation failed. It can be because @href CATIPLMCloningEngine#RunCloningOperation was not triggered.</li>
   *   </ul>adl_promot
   */
  virtual HRESULT GetCloningResult(const CATPLMID & iComponent, CATIPLMOperationResult *& oResult) = 0;

  /**
   * Gives access to an attribute set.
   * <br><b>Role:</b>This method enables to get an attribute set enabling to specify some attributes to use in the @href #AddCloningDatum entry point.<br>
   *
   * @param oAttributeSet  [out,CATBaseUnknown#Release]
   *   A pointer on the attribute set.
   * @return
   *   <ul>
   *   <li><tt>S_OK</tt> if access is given to an attribute set.</li>
   *   <li><tt>E_FAIL</tt> if the operation failed.</li>
   *   </ul>
   */
  virtual HRESULT GetAttributeSet(CATIPLMAttributeSet *& oAttributeSet) = 0;

  //No constructors or destructors on this pure virtual base class
  //--------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler(CATIPLMCopyEngine, CATBaseUnknown);
#endif