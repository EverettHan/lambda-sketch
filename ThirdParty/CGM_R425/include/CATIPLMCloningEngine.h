/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
#ifndef CATIPLMCloningEngine_H
#define CATIPLMCloningEngine_H


/**
* @level Protected
* @usage U3
*/
#include "CATPLMIntegrationInterfaces.h"
#include "CATPLMCloningEngineAbstract.h"
#include "CATPLMCloningMode.h"
class CATTime;
class CATPLMID;
class CATIPLMAttributeSet;
class CATIPLMOperationResult;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMCloningEngine;
#else
extern "C" const IID IID_CATIPLMCloningEngine;
#endif

/**
* This interface defines the unique protocol of communication between the users and the cloning engine.
* Use @href CATPLMIntegration.CATPLMEngineToolbox#GetCloningEngine to get a pointer on the cloning engine.
* Globally, the user can:
*   Ask for a clone operation to be performed on a component and specify a set of parameters for this clone operation.
*   Retrieve the new components available after the operation.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMCloningEngine: public CATPLMCloningEngineAbstract
{
	CATDeclareInterface;

public:

/** 
 * Adds a cloning datum for further treatment by the engine.
 *
 * <br><b>Role</b>: Enables to add a cloning datum in the set of data which will be treated when calling the 
 * @href CATIPLMCloningEngine#RunCloningOperation entry point.
 *
 * @param iComponent [in]
 *   The component asked to be cloned. 
 * <ul><li> The identifier must not be CATPLMID_Null. Otherwise, the call will result in a E_INVALIDARG return.</li></ul>
 * @param iAttributes [in]
 *   The set of attributes needing to be applied to the new component.
 * @param iApplicabilityDate [in]
 *   The applicability date for the new version availability.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the component can be taken into account by the engine. It was added to the set of data to be treated by the engine. </li> 
 *   <li><tt>E_INVALIDARG</tt> if one of the provided entry is invalid.</li>
 *   <li><tt>E_FAIL</tt> if the operation failed.</li>
 *   </ul>
 */
  virtual HRESULT AddCloningDatum( const CATPLMID & iComponent, CATIPLMAttributeSet * iAttributes, const CATTime & iApplicabilityDate ) = 0;

/**
 * Requests a cloning on a set of components.
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
  virtual HRESULT RunCloningOperation( void ) = 0;

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
  virtual HRESULT NextCloningResult( int & ioPosition, CATIPLMOperationResult *& oResult )=0;

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
 *   </ul>
 */
  virtual HRESULT GetCloningResult( const CATPLMID & iComponent, CATIPLMOperationResult *& oResult )=0;

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
  virtual HRESULT GetAttributeSet( CATIPLMAttributeSet *& oAttributeSet ) = 0;

};
CATDeclareHandler(CATIPLMCloningEngine, CATBaseUnknown);

#endif
