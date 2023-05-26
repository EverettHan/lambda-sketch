/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpProtectedCloningServices_H
#define CATAdpProtectedCloningServices_H

#include "CATPLMIntegrationAccess.h"

#include "IUnknown.h"
#include "CATBooleanDef.h"
#include "CATCollec.h"
class CATLISTV(CATAdpCloneRequest);
class CATIAdpPLMIdentificator;
class CATListPtrCATIAdpPLMIdentificator;
class CATTime;
class CATIAdpErrorMonitor;

/**
* Class to manage cloning operations in CATIA session.
*
* <br><b>Role</b>: Provides basic functions to clone objects in the PLM repository. All 
* aggregates of a Reference are cloned by default (aggregated Instances, Ports and Connections).
* Internal links are rerouted automatically.
*/
class ExportedByCATPLMIntegrationAccess CATAdpProtectedCloningServices
{
public:

	/**
	* Clone a set of entities in the database with the option of updating the 
	* objects in session with their new identifiers.
	* <br><b>Role</b>: Launch a cloning process. 
	* @param ilToClone [in]
	*   The list of clone requests to process.
	* @param const CATTime & iApplicabilityDate [in]
	*   The applicability date for the configuration of the new instances. NOTE: For future
	*   development, not currently used.   
	* @param iUpdateSession [in]
	*   The indicator to update the session. If the session is not updated, then the clone
	*   will only be performed in the database and the current session will not be updated.
  *   <ul>
  *   <li>The use of this option will result in the deletion in the session of instances of the cloned component and the creation of instances of the newly created one.<li>
  *   <li>The use of this option will lead to a failure if configuration is applied on instances of the cloned component or if the user has no rights to modify the instances of the cloned component</li>
  *   </ul>
  * @param iopErrorMonitor [inout]
	*   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.	* @return
	*   HRESULT
	* <dt> <code>S_OK</code>     <dd> Success.
	* <dt> <code>E_FAIL</code>   <dd> Failure.
	*/
	static HRESULT Clone (const CATLISTV(CATAdpCloneRequest)& ilToClone, 
						  const CATTime & iApplicabilityDate, 
						  CATBoolean iUpdateSession=TRUE, CATIAdpErrorMonitor* iopErrorMonitor = NULL);

	/**
	* Clone a set of entities in the database without replacing the objects in session. 
	* Returns the lists of old and new identifiers.
	* <br><b>Role</b>: Launch a cloning process.
	* @param ilToClone [in]
	*   The list of clone requests to process.
	* @param const CATTime & iApplicabilityDate [in]
	*   The applicability date for the configuration of the new instances. NOTE: For future
	*   development, not currently used.  
	* @param olOldId [out]
	*   The list of old identifiers that have been cloned.
	* @param olNewId [out]
	*   The corresponding list of new identifiers.
	* @param iKeepFamily [in]
	*   Set to TRUE if the logical family should be kept on the resulting component.
	* @param iopErrorMonitor [inout]
	*   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.	* @return
	* @return
	*   HRESULT
	* <dt> <code>S_OK</code>     <dd> Success.
	* <dt> <code>E_FAIL</code>   <dd> Failure.
	*/
	static HRESULT Clone (const CATLISTV(CATAdpCloneRequest)& ilToClone, 
						  const CATTime & iApplicabilityDate, 
						  CATListPtrCATIAdpPLMIdentificator & lOldId, 
						  CATListPtrCATIAdpPLMIdentificator & olNewId,
						  CATBoolean iKeepFamily=FALSE, CATIAdpErrorMonitor* iopErrorMonitor = NULL);

  /**
  * Clone a set of entities in the database with the option of updating the
  * objects in session with their new identifiers.
  * <br><b>Role</b>: Launch a cloning process.
  * @param ilToClone [in]
  *   The list of clone requests to process.
  * @param const CATTime & iApplicabilityDate [in]
  *   The applicability date for the configuration of the new instances. NOTE: For future
  *   development, not currently used.
  * @param iUpdateSession [in]
  *   The indicator to update the session. If the session is not updated, then the clone
  *   will only be performed in the database and the current session will not be updated.
  *   <ul>
  *   <li>The use of this option will result in the deletion in the session of instances of the cloned component and the creation of instances of the newly created one.<li>
  *   <li>The use of this option will lead to a failure if configuration is applied on instances of the cloned component or if the user has no rights to modify the instances of the cloned component</li>
  *   </ul>
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.  * @return
  *   HRESULT
  * <dt> <code>S_OK</code>     <dd> Success.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  */
  static HRESULT CloneWithBusinessLogic (const CATLISTV(CATAdpCloneRequest)& ilToClone,
              const CATTime & iApplicabilityDate, const CATUnicodeString & iIdCloningString,
              CATBoolean iUpdateSession=TRUE, CATIAdpErrorMonitor* iopErrorMonitor = NULL);

  /**
  * Clone a set of entities in the database without replacing the objects in session.
  * Returns the lists of old and new identifiers.
  * <br><b>Role</b>: Launch a cloning process.
  * @param ilToClone [in]
  *   The list of clone requests to process.
  * @param const CATTime & iApplicabilityDate [in]
  *   The applicability date for the configuration of the new instances. NOTE: For future
  *   development, not currently used.
  * @param olOldId [out]
  *   The list of old identifiers that have been cloned.
  * @param olNewId [out]
  *   The corresponding list of new identifiers.
  * @param iKeepFamily [in]
  *   Set to TRUE if the logical family should be kept on the resulting component.
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.  * @return
  * @return
  *   HRESULT
  * <dt> <code>S_OK</code>     <dd> Success.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  */
  static HRESULT CloneWithBusinessLogic (const CATLISTV(CATAdpCloneRequest)& ilToClone,
              const CATTime & iApplicabilityDate, const CATUnicodeString & iIdCloningString,
              CATListPtrCATIAdpPLMIdentificator & lOldId,
              CATListPtrCATIAdpPLMIdentificator & olNewId,
              CATBoolean iKeepFamily=FALSE, CATIAdpErrorMonitor* iopErrorMonitor = NULL);

};
#endif
