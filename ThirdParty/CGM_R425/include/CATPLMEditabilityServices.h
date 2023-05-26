// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMEditabilityServices.h
// Header definition of CATPLMEditabilityServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2006  Creation: Code generated by the CAA wizard  YGN
//===================================================================
/**
* @level Protected 
* @usage U1 
*/

#ifndef CATPLMEditabilityServices_H
#define CATPLMEditabilityServices_H


#include "CATBaseUnknown.h"
#include "CATPLMComponentInterfaces.h"
#include "CATListPtrCATIPLMComponent.h"
#include "CATListOfCATBoolean.h"
#include "CATListOfInt.h"
#include "CATLISTPIUnknown.h"
#include "CATListPtrCATEditabilityError.h"
class CATListValCATComponentId;


class CATIAdpErrorMonitor;
//-----------------------------------------------------------------------

/**
* Class to manage Editability.
*
* <br><b>Role</b>: this class enables you to check Editability. 
*
*/
class ExportedByCATPLMComponentInterfaces CATPLMEditabilityServices
{
public:
  /** 
  * Check the edit ability of a list of objects.
  * This method does not chat with the server.
  * @param iObjectsList
  * The list of objects to check edit ability of (features, containers, documents or components)
  * @param oList
  * The list of editability status
  *	TRUE : the object is editable
  *	FALSE : the object os not editable
  * @param ioErrorList
  *	If not NULL, in case of non editability of some objects, diagnosis of error can be accessed.
  *	If many objects are located inside a same not editable component, only one error on the component is raised.
  *	Error can contain only session information but no database information.
  * @return
  *      <ul>
  *       <li><tt>S_OK</tt> all objects are editable.</li>
  *       <li><tt>E_FAIL</tt> at least one object is not editable.</li>
  *      </ul>
  */

  static HRESULT GetEditabilityStatus(const CATListOfIUnknown& iObjectsList, CATListOfCATBoolean& oList,
    CATLISTP(CATPLMEditabilityError)* ioErrorList = NULL);

  /** 
  * Check the edit ability of a list of objects and lock them if necessary.
  * This method is likely to chat with the server, depending on the session editability configuration.
  * FullEdit configuration => no chat with the server, Lock is not attempted in database.
  * Optimistic Warning configuration => no chat with the server, components were opened in ReadOnly, so only the SwitchToReadWrite can report warnings.
  * Pessimistic => no chat with the server, editability status in session is exactly the same that the one in the database.
  * Opportunistic configuration => chat with the server, Lock is attempted in database in Forbid mode, warning are raised if necessary in Warning mode.
  * @param iObjectsList
  * The list of objects to lock or to check edit ability of (features, containers, documents or components)
  * @param oRCList
  * The list of editability status
  *	S_OK : object is editable (RW in session and its component has been locked in database if necessary)
  *	S_FALSE : object is editable (RW in session but not lockable in database (only in warning mode))
  *   E_FAIL : object not editable (RO in session or not lockable in database (only in forbid mode))
  * @param iStopAtFirstError
  *	Set to FALSE if you want to try to lock all objects or to check editability of all objects even if one can not be locked or is not editable.
  * @param ioErrorList
  *	If not NULL, in case of non editability of some objects, diagnosis of error can be accessed.
  *	If many objects are located inside a same not editable component, only one error on the component is raised.
  *	Error can contain session information or database information.
  * @return
  *      <ul>
  *       <li><tt>S_OK</tt> editability status of all object is S_OK.</li>
  *		<li><tt>S_FALSE</tt> editablity status of some objects (but not all) is S_FALSE or E_FAIL with iStopAtFirstError FALSE.
  *							 To sum up, operation is possible (warning mode and/or iStopAtFirstError FALSE) but save is not guaranteed.</li>
  *       <li><tt>E_FAIL</tt> editability status of all objects is S_FALSE or E_FAIL.
  *							Or when iStopAtFirstError is TRUE, means that the status of one object is E_FAIL.
  *							To sum up, operation is not possible.</li>
  *      </ul>
  */

  static HRESULT CheckAndLock(const CATListOfIUnknown& iObjectsList, CATListOfInt& oRCList,
    CATBoolean iStopAtFirstError = TRUE, CATLISTP(CATPLMEditabilityError)* iErrorList = NULL );

  /** 
  * Switch a set components to ReadOnly.
  * This method is likely to chat with the server depending on session editability configuration.
  * FullEdit configuration => no chat with the server, components are switched in session not in database.
  * Optimistic Warning/Opportunistic configuration => no chat with the server, components are switched in session.
  * Pessimistic configuration => chat with the server, switch is attempted in session and in database.
  *
  * @param iComponentsList
  *	      The list of components to switch
  * @param StopAtFirstError
  *	      TRUE  : The processing stops as soon as errors encounters, processing is done either completly or not at all
  *       FALSE : A partial success of the service is allowed
  *               Components that gets switched are returned in opImpactedComponent
  *               Information about components that fail switching returned in oErrorList
  * @param oErrorList
  *	      diagnostics of error
  *	      Can contain session or database information.
  *       In addition to the CATError information, if the error is specific to a component, the CATPLMEditabilityError can return a ptr to that component
  * @param opImpactedComponents
  *       Optional, components that were switched (or were already ReadOnly), coming from iComponentsList, or impacted by propagation.
  * @return
  *      S_OK   : all components were switched. oErrorList may contain warning (exemple component already ReadOnly) but no error.
  *      E_FAIL : at least one switch failed. oErrrorList contains error about the PLMComponents that fail to switch.
  *               If StopAtFirstError=TRUE, not a single switch has been performed neither in session or in base (no need to roll back).
  *      E_UNEXPECTED : Total failure of the service. oErrorList may be empty. Not a single switch has been performed.
  */

#if !defined(_WINDOWS_SOURCE) || defined (__CATPLMComponentInterfaces) || defined (__CATPLMUIEditability) || defined (__CATPLMTestCommands) || defined (__TSTCATEditabilityServices) || defined (__CATPCTEditabilityTests)
	static HRESULT SwitchToReadOnly(const CATListPtrCATIPLMComponent& iComponentsList,CATBoolean iStopAtFirstError = TRUE, CATLISTP(CATPLMEditabilityError)* ioErrorList = NULL, CATListPtrCATIPLMComponent* impactedComponents = NULL);
#endif


  /** 
  * Switch a set of components to ReadWrite.
  * This method is likely to chat with the server depending on session editability configuration.
  * FullEdit configuration => no chat with the server, components are switched in session not in database.
  * Optimistic Warning/Opportunistic configuration => chat with the server, components are switched in session, but database status is contriled and warning can be raised.
  * Pessimistic configuration => chat with the server, switch is attempted in session and in database.
  * 
  * @param iComponentsList
  *	      The list of components to switch
  * @param StopAtFirstError
  *	      TRUE  : The processing stops as soon as errors encounters, processing is done either completly or not at all
  *       FALSE : A partial success of the service is allowed
  *               Components that gets switched are returned in opImpactedComponent
  *               Information about components that fail switching returned in oErrorList
  * @param oErrorList
  *	      Diagnostics of error
  *	      Can contain session or database information.
  *       In addition to the CATError information, if the error is specific to a component, the CATPLMEditabilityError can return a ptr to that component
  * @param opImpactedComponents
  *       Optional, components that were switched (or were already ReadOnly), coming from iComponentsList, or impacted by propagation.
  * @return
  *      S_OK   : All components were switched in session. oErrorList may contain warning
  *               exemple component already ReadWrite
  *               or stronger information (in optimist warning, element switched in session, but its modification won't be saveable in base)
  *      E_FAIL : at least one switch failed. oErrrorList contains error about the PLMComponents that fail to switch.
  *               If StopAtFirstError=TRUE, not a single switch has been performed neither in session or in base (no need to roll back).
  *      E_UNEXPECTED : Total failure of the service. oErrorList may be empty. Not a single switch has been performed.
  */

#if !defined(_WINDOWS_SOURCE) || defined (__CATPLMComponentInterfaces) || defined (__CATPLMEditabilityImpl) || defined (__CATPLMUIEditability) || defined (__CATPLMTestCommands) || defined (__TSTCATEditabilityServices) || defined (__CATFmtBatchServices) || defined (__CATPCTEditabilityTests)
  static HRESULT SwitchToReadWrite(const CATListPtrCATIPLMComponent& iComponentsList,CATBoolean iStopAtFirstError = TRUE, CATLISTP(CATPLMEditabilityError)* ioErrorList = NULL, CATListPtrCATIPLMComponent* impactedComponents = NULL);
#endif

 /**
  * @deprecated drop 25, use first signature of the service (without oList)
  */
#if !defined(_WINDOWS_SOURCE) || defined (__CATPLMComponentInterfaces) || defined (__CATPLMUIEditability)
  static HRESULT SwitchToReadWrite(const CATListPtrCATIPLMComponent& iComponentsList, CATListOfCATBoolean& oList,
    CATBoolean iStopAtFirstError = TRUE, CATLISTP(CATPLMEditabilityError)* ioErrorList = NULL, CATListPtrCATIPLMComponent* impactedComponents = NULL);
#endif

  /** 
  * Cancel all the switch to read / write for PLM entities still in session.
  * This even if the PLM entity has been edited (saving it becomes then impossible.
  * API to be called when closing the client session, before disconnection from the server and before removing the PLM entities
  * from the client session, such that in Pessimistic locking, the lock on the PLM Entities get effectively remove from server.
  */
#if !defined(_WINDOWS_SOURCE) || defined (__CATPLMComponentInterfaces) || defined (__CATPLMEditabilityImpl) || defined (__CATPLMUIEditability) || defined (__CATPLMTestCommands) || defined (__TSTCATEditabilityServices) || defined (__CATPLMCloseExit)
  static HRESULT CancelAllSwitchToReadWrite();
#endif

  /**
   * Resets every opened component to its computed-at-open editability status.
   */
#if !defined(_WINDOWS_SOURCE) || defined(__CATPLMComponentInterfaces) || defined(__CATPLMEditabilityImpl) || defined(__PLMManagementItfServices) || defined(__CATPLMWorkspaceImpl) || defined(__CATPCTEditabilityTests)
  static HRESULT ResetsAllEditabilityStatusOnContextChange(CATIAdpErrorMonitor * iopErrorMonitor = NULL);
#endif


  /** 
  * Check if a list of objects can currently be saved, whitout locking them in base
  * This method is likely to chat with the server, depending on the session editability configuration:
  *
  * FullEdit & Optimistic Warning => Chat with the server to control lockability hence saveability
  * Pessimist Warning [& Opportunistic Warning] => Chat with the server for writable components not locked by connected user
  * Pessimist Forbid [&  Opportunistic Forbid] => no chat with the server.
  * Is just contoled the status of the PLM entity in session. To be edited in these modes, the entity has to be locked 
  * in base before the edition, and is tagged so in session
  *
  * @param iObjectsList
  *     The list of objects to check if they can be saved
  * @param oErrorList
  *	    If not NULL, in case of non editability of some objects, diagnosis of error can be accessed.
  *	    Error can contain session information or database information.
  *
  * @return
  *     S_OK :  See iErrorList to check which elements can not be saved.
  *             if iErrorList is empty, all can be.
  *
  *     Failure return code: Global failure of the service.
  *     returned oErrorList is empty but saveability of the iObjectsList has not been checked.
  *     list of errors TBD
  */

  static HRESULT CanBeSaved(const CATListPtrCATIPLMComponent& iObjectsList,
                            CATLISTP(CATPLMEditabilityError)& oErrorList);
  /** 
  * Check if a list of modifications on components can currently be saved, whitout locking them in base
  * This method is likely to chat with the server, depending on the session editability configuration:
  *
  * FullEdit & Optimistic Warning => Chat with the server to control lockability hence saveability
  * Pessimist Warning [& Opportunistic Warning] => Chat with the server for writable components not locked by connected user
  * Pessimist Forbid [&  Opportunistic Forbid] => no chat with the server.
  * Is just contoled the status of the PLM entity in session. To be edited in these modes, the entity has to be locked 
  * in base before the edition, and is tagged so in session
  *
  * @param iObjectsList
  *     The list of IDs of objects to check if they can be saved
  * @param oErrorList
  *	    If not NULL, in case of non editability of some objects, diagnosis of error can be accessed.
  *	    Error can contain session information or database information.
  *
  * @return
  *     S_OK :  See iErrorList to check which elements can not be saved.
  *             if iErrorList is empty, all can be.
  *
  *     Failure return code: Global failure of the service.
  *     returned oErrorList is empty but saveability of the iObjectsList has not been checked.
  *     list of errors TBD
  */

  static HRESULT CanBeSaved(const CATListValCATComponentId& iObjectsList,
                            CATLISTP(CATPLMEditabilityError)& oErrorList);
  /** 
  * Check if a list of objects can currently be saved, whitout locking them in base
  * This method chat with the server to control lockability hence future saveability
  *
  * @param iObjectsList
  *     The list of objects to check if they can be saved
  * @param oErrorList
  *	    If not NULL, in case of non editability of some objects, diagnosis of error can be accessed.
  *	    Error can contain session information or database information.
  *
  * @return
  *     S_OK :  See iErrorList to check which elements can not be saved.
  *             if iErrorList is empty, all can be.
  *
  *     Failure return code: Global failure of the service.
  *     returned oErrorList is empty but saveability of the iObjectsList has not been checked.
  *     list of errors TBD
  */

  static HRESULT CheckServerEditRules(const CATListPtrCATIPLMComponent& iObjectsList,
                            CATLISTP(CATPLMEditabilityError)& oErrorList);

};

//-----------------------------------------------------------------------

#endif
