/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
#ifndef CATIPLMVersioningEngineAbstract_H
#define CATIPLMVersioningEngineAbstract_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATTime;
class CATPLMID;
class CATLISTV(CATPLMID); // Include CATLISTV_CATPLMId to access to that entities.
class CATIPLMOperationResult;
class CATIPLMAttributeSet;

class ExportedByCATPLMIntegrationInterfaces CATIPLMVersioningEngineAbstract: public CATBaseUnknown
{
public:
/**
 * Requests a new version on a set of components.
 * <br><b>Role:</b>This method launches a versioning request on the components provided through the @href CATIPLMVersioningEngineAbstract#AddVersioningDatum entry point.<br>
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> All elements have been versionned. </li> 
 *   <li><tt>E_INVALIDARG</tt> No element have been provided through the @href CATIPLMVersioningEngineAbstract#AddVersioningDatum entry point.</li>
 *   <li><tt>E_FAIL</tt> At least one elements has failed, nothing is committed in the base.
 *   Errors encountered are communicated through the provided @href CATIAdpErrorMonitor added to.</li>
 *   </ul>
 */
  virtual HRESULT RunVersioningOperation( void ) = 0;

/**
 * Iterator enabling to access to the results of the versioning operation.
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
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if access is given to the next result. </li> 
 *   <li><tt>S_FALSE</tt> if the end of the iteration is reached. No result is available anymore. </li> 
 *   <li><tt>E_INVALIDARG</tt> the provided data are invalid.</li>
 *   <li><tt>E_FAIL</tt> if the operation failed. It can be because @href CATIPLMVersioningEngineAbstract#RunVersioningOperation was not triggered.</li>
 *   </ul>
 */
  virtual HRESULT NextVersioningResult( int & ioPosition, CATIPLMOperationResult *& oResult )=0;

/**
 * Gives access to a particular result of the versioning operation.
 * <br><b>Role:</b>This method enables to get some information about the result of a particular operation.<br>
 *
 * @param iComponent [in]
 *   One of the iComponent provided though the @href CATIPLMVersioningEngineAbstract#AddVersioningDatum entry point.
 * @param oResult  [out,CATBaseUnknown#Release]
 *   A pointer on the result descriptor.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if access is given to the searched result. </li> 
 *   <li><tt>S_FALSE</tt> if there is no result associated to this component. </li> 
 *   <li><tt>E_FAIL</tt> if the operation failed. It can be because @href CATIPLMVersioningEngineAbstract#RunVersioningOperation was not triggered.</li>
 *   </ul>
 */
  virtual HRESULT GetVersioningResult( const CATPLMID & iComponent, CATIPLMOperationResult *& oResult )=0;

/**
 * Gives access to an attribute set.
 * <br><b>Role:</b>This method enables to get an attribute set enabling to specify some attributes to use in the @href #AddVersioningDatum entry point.<br>
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
#endif
