// COPYRIGHT Dassault Systemes 2009
//===================================================================
//  June 2009  Creation: Code generated by the LRG wizard
//===================================================================
#ifndef PLMIPointingVariantsManager_H
#define PLMIPointingVariantsManager_H

/**
* @level Protected
* @usage U3
*/

#include "PLMPointingCmpVarsMgmt.h"
#include "CATBaseUnknown.h"
class CATIPLMComponent_var;
class CATListPtrCATIPLMComponent;
class PLMIPointingVariant_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMPointingCmpVarsMgmt IID IID_PLMIPointingVariantsManager;
#else
extern "C" const IID IID_PLMIPointingVariantsManager;
#endif

class ExportedByPLMPointingCmpVarsMgmt PLMIPointingVariantsManager : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Mode of management of the variants of an impacted pointing component by <tt>this</tt> PLMIPointingVariantsManager.
  *
  * @param DoNothing                 - No variants of the impacted pointed component will be created, even if effective.<br>
  *                                    Existing variants are kept unmodified. That is to say nothing is done!
  * @param RepairAllVariants         - Existing and new variants of the impacted pointing component will be rerouted/deleted/created<br>
  *                                    with regards to the validity of its evaluated effectivity.
  * @param DeleteAllVariants         - All existing variants of the impacted pointed component are deleted, even if effective.
  * @param DeleteIneffectiveVariants - Existing variants of the impacted pointed component are deleted if ineffective.<br>
  *                                    Effective existing variants are kept unmodified.
  * @param CreateAllVariants         - All missing variants of the impacted pointed component will be created, even if ineffective.<br>
  *                                    Existing variants are kept unmodified.
  * @param CreateEffectiveVariants   - Variants of the impacted pointed component will be created only if effective.<br>
  *                                    Existing variants are kept unmodified.
  */
  enum PointingVariantsManagementMode {
    DoNothing = 0x0000,
    RepairAllVariants = 0x0006,
    DeleteAllVariants = 0x000c,
    DeleteIneffectiveVariants = 0x0004,
    CreateAllVariants = 0x0003,
    CreateEffectiveVariants = 0x0002
  };


  /**
  * Type (Synchronous/Asynchronous) of <tt>this</tt> PLMIPointingVariantsManager.
  *
  * @param Synchronous  - <tt>this</tt> PLMIPointingVariantsManager's behavior is adequate to be used _during_ an authoring command (Replace/Delete/Move...).
  * @param Asynchronous - <tt>this</tt> PLMIPointingVariantsManager's behavior is adequate to be used _after_ an authoring operation has been performed.
  */
  enum PointingVariantsManagerType { Synchronous, Asynchronous };

  /**
  * Return the type (Synchronous/Asynchronous) of <tt>this</tt> PLMIPointingVariantsManager.
  *
  *   @return
  *      The type (Synchronous/Asynchronous) of <tt>this</tt> PLMIPointingVariantsManager. @see PointingVariantsManagerType.<br>
  */
  virtual PointingVariantsManagerType GetType() = 0;

  //////////////////////////////////////////////////////////////////////////////////////
  //////////#################################################################///////////
  //////////# PRE ANALYSIS/MANAGEMENT APIS (FOR SYNCHRONOUS MANAGERS ONLY!) #///////////
  //////////#################################################################///////////
  //////////////////////////////////////////////////////////////////////////////////////

  /**
  * Log in the scope treaten by <tt>this</tt> _synchronous_ PLMIPointingVariantsManager
  * that a configured split has been performed on <tt>ispOriginalInstance</tt>,
  * creating the clone <tt>ispVariantInstance</tt>.
  * THIS API FAILS IF CALLED ON AN ASYNCHRONOUS PLMIPointingVariantsManager! THIS API ONLY APPLIES TO A
  * SYNCHRONOUS PLMIPointingVariantsManager.
  *
  *  @param  ispOriginalInstance
  *      The original instance that have been split.<br>
  *      This input must not be provided by caller as NULL_var.
  *      This input must be a PLM instance of a configurable modeler.
  *  @param  ispVariantInstance
  *      The corresponding variant instance that has been created by the split. <br>
  *      This input must not be provided by caller as NULL_var.
  *      This input must be a PLM instance of a configurable modeler.
  *   @return
  *     <ul>
  *       <li> S_OK if the split has been successfully logged.</li>
  *       <li> S_FALSE if this split has already been logged.</li>
  *       <li> E_INVALIDARG if some of the input arguments are not valid.</li>
  *       <li> E_FAIL if failed to log the split.<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional
  *           information about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href
  *           CATError#CATCleanLastError to clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_01</tt>:</li>
  *                The type (synchronous/asynchronous) of the manager of impacted pointing components is wrong.
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT LogSplitOperationInScope(const CATIPLMComponent_var& ispOriginalInstance, const CATIPLMComponent_var& ispVariantInstance) = 0;

  /**
  * Log in the scope treaten by <tt>this</tt> _synchronous_ PLMIPointingVariantsManager
  * that an insert a new variant has been performed on <tt>ispOriginalInstance</tt>,
  * creating the clone <tt>ispVariantInstance</tt>.
  * THIS API FAILS IF CALLED ON AN ASYNCHRONOUS PLMIPointingVariantsManager! THIS API ONLY APPLIES TO A
  * SYNCHRONOUS PLMIPointingVariantsManager.
  *
  *  @param  ispOriginalInstance
  *      The original instance that have been clone.<br>
  *      This input must not be provided by caller as NULL_var.
  *      This input must be a PLM instance of a configurable modeler.
  *  @param  ispVariantInstance
  *      The corresponding variant instance that has been created by the clone. <br>
  *      This input must not be provided by caller as NULL_var.
  *      This input must be a PLM instance of a configurable modeler.
  *   @return
  *     <ul>
  *       <li> S_OK if the split has been successfully logged.</li>
  *       <li> S_FALSE if this split has already been logged.</li>
  *       <li> E_INVALIDARG if some of the input arguments are not valid.</li>
  *       <li> E_FAIL if failed to log the split.<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional
  *           information about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href
  *           CATError#CATCleanLastError to clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_01</tt>:</li>
  *                The type (synchronous/asynchronous) of the manager of impacted pointing components is wrong.
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT LogLogicalCloneOperationInScope(const CATIPLMComponent_var& ispOriginalInstance, const CATIPLMComponent_var& ispVariantInstance) = 0;

  /**
  * Log in the scope treaten by <tt>this</tt> _synchronous_ PLMIPointingVariantsManager
  * that a configured trim has been performed on <tt>ispTrimmedInstance</tt>.
  * THIS API FAILS IF CALLED ON AN ASYNCHRONOUS PLMIPointingVariantsManager! THIS API ONLY APPLIES TO A
  * SYNCHRONOUS PLMIPointingVariantsManager.
  *
  *  @param  ispTrimmedInstance
  *      The instance which effectivity has been trimmed.<br>
  *      This input must not be provided by caller as NULL_var.
  *   @return
  *     <ul>
  *       <li> S_OK if the effectivity trim has been successfully logged.</li>
  *       <li> E_INVALIDARG if the input argument is not valid.</li>
  *       <li> E_FAIL if failed to log the effectivity trim.<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional
  *           information about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href
  *           CATError#CATCleanLastError to clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_01</tt>:</li>
  *                The type (synchronous/asynchronous) of the manager of impacted pointing components is wrong.
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT LogTrimOperationInScope(const CATIPLMComponent_var& ispTrimmedInstance) = 0;

  /**
  * Log in the scope treaten by <tt>this</tt> _synchronous_ PLMIPointingVariantsManager
  * that a substitute has been created from <tt>ispOriginalInstance</tt>,
  * creating <tt>ispVariantInstance</tt>.
  * THIS API FAILS IF CALLED ON AN ASYNCHRONOUS PLMIPointingVariantsManager! THIS API ONLY APPLIES TO A
  * SYNCHRONOUS PLMIPointingVariantsManager.
  *
  *  @param  ispOriginalInstance
  *      The original instance that have been used to create substitute.<br>
  *      This input must not be provided by caller as NULL_var.
  *  @param  ispVariantInstance
  *      The corresponding subsitute instance. <br>
  *      This input must not be provided by caller as NULL_var.
  *   @return
  *     <ul>
  *       <li> S_OK if the substitute have been successfully logged.</li>
  *       <li> S_FALSE if this substitute have already been logged.</li>
  *       <li> E_INVALIDARG if some of the input arguments are not valid.</li>
  *       <li> E_FAIL if failed to log the substitute.<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional
  *           information about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href
  *           CATError#CATCleanLastError to clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_01</tt>:</li>
  *                The type (synchronous/asynchronous) of the manager of impacted pointing components is wrong.
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT LogSubstituteCreationInScope(const CATIPLMComponent_var& ispOriginalInstance, const CATIPLMComponent_var& ispVariantInstance) = 0;


  /////////////////////////////////////////////////////////////////////////////////////////
  //////////############################################################///////////////////
  //////////# THE API FOR ANALYSIS OF THE IMPACTED POINTING COMPONENTS #///////////////////
  //////////############################################################///////////////////
  /////////////////////////////////////////////////////////////////////////////////////////

  /**
  * Find, analyze and return the impacted pointing components.
  * This API can be called on a synchronous or an asynchronous PLMIPointingVariantsManager.
  * This API must be called prior to <tt>ManageVariantsOfImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_02</tt>!
  *
  *  @param oListOfImpactedPointingComponents
  *      The list of of impacted pointing components.<br>
  *      Output parameter. <br>
  *      This list MUST be provided by caller as empty. This method returns an error otherwise. <br>
  *      This list is returned to caller as empty if method fails.
  *      ITEMS IN THIS RETURNED LIST MUST BE RELEASED BY THE CALLER AFTER USE !!
  *   @return
  *     <ul>
  *       <li> S_OK if search and analysis of all impacted pointing components has been successful.</li>
  *       <li> S_FALSE if there is no impacted pointing component at all in this search.</li>
  *       <li> E_INVALIDARG if the input argument is not valid.</li>
  *       <li> E_FAIL if the search or analysis fails. There are several reasons that can explain this failure that are
  *           listed below!<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional information
  *           about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href CATError#CATCleanLastError to
  *           clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT AnalyzeAndReturnImpactedPointingComponents(CATListPtrCATIPLMComponent& oListOfImpactedPointingComponents) = 0;




  ///////////////////////////////////////////
  //////////######################///////////
  //////////# POST-ANALYSIS APIS #///////////
  //////////######################///////////
  ///////////////////////////////////////////

  /**
  * Retrieves a diagnosis (four counts actually) for a given impacted pointing component <tt>ispImpactedPointingCompo</tt>.
  * This API can be called on a synchronous or an asynchronous PLMIPointingVariantsManager.
  * This API must be called after a call to <tt>AnalyzeAndReturnImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_03<br>!
  * This API must be called prior to <tt>ManageVariantsOfImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_02</tt>!
  *
  *  @param   ispImpactedPointingCompo
  *      An impacted pointing component.<br>
  *      Input parameter. <br>
  *      If must be an impacted pointing component of the list returned by <tt>AnalyzeAndReturnImpactedPointingComponents</tt>
  *      otherwise this method will fail with error code <tt>PointingCmpVarMngr_ERR_03</tt><br>
  *  @param oNbOfExistingEffectiveVariants
  *      The number of existing variants of <tt>ispImpactedPointingCompo</tt> that are effective.<br>
  *      Output parameter.<br>
  *  @param oNbOfExistingIneffectiveVariants
  *      The number of existing variants of <tt>ispImpactedPointingCompo</tt> that are ineffective.<br>
  *      Output parameter.<br>
  *  @param oNbOfMissingEffectiveVariants
  *      The number of missing variants of <tt>ispImpactedPointingCompo</tt> that would be effective if created.<br>
  *      Output parameter.<br>
  *  @param oNbOfMissingIneffectiveVariants
  *      The number of missing variants of <tt>ispImpactedPointingCompo</tt> that would be ineffective if created.<br>
  *      Output parameter.<br>
  *   @return
  *     <ul>
  *       <li> S_OK if this method succeeds to give a proposed operation (even DoNothing)
  *            for the given impacted connection.</li>
  *       <li> E_INVALIDARG if <tt>ispImpactedPointingCompo</tt> is NULL_var/unset.</li>
  *       <li> E_FAIL if this methods fails to give a proposed operation for the given impacted connection. There
  *            are several reasons that can explain this failure that are listed below!<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional information
  *           about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href CATError#CATCleanLastError to
  *           clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *             <li><tt>PointingCmpVarMngr_ERR_03</tt>:</li>
  *                This component is not impacted.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT GetDiagnosisForImpactedPointingComponent(const CATIPLMComponent_var& ispImpactedPointingCompo,
    int &oNbOfExistingEffectiveVariants, int &oNbOfExistingIneffectiveVariants,
    int &oNbOfMissingEffectiveVariants, int &oNbOfMissingIneffectiveVariants) = 0;


  /**
  * Set the management mode to apply for a given impacted pointing component.<br>
  * This API can be called on a synchronous or an asynchronous PLMIPointingVariantsManager.<br>
  * This API must be called after a call to <tt>AnalyzeAndReturnImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_03</tt>!<br>
  * This API must be called prior to <tt>ManageVariantsOfImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_02</tt>!
  *
  *  @param   ispImpactedPointingCompo
  *      An impacted pointing component.<br>
  *      Input parameter. <br>
  *      If must be an impacted pointing component of the list returned by <tt>AnalyzeAndReturnImpactedPointingComponents</tt>
  *      otherwise this method will fail with error code <tt>PointingCmpVarMngr_ERR_03</tt><br>
  *  @param iManagementMode
  *      The mode for treatment of the impacted pointing component <tt>ispImpactedPointingCompo</tt>. @see PointingVariantsManagementMode.<br>
  *   @return
  *     <ul>
  *       <li> S_OK if the management mode to apply on the given impacted connection is successfully set.</li>
  *       <li> E_INVALIDARG if <tt>ispImpactedPointingCompo</tt> is NULL_var/unset.</li>
  *       <li> E_FAIL if this methods fails to set the management mode to apply to the given impacted pointing component.<br>
  *            There are several reasons that can explain this failure that are listed below!<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional information
  *           about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href CATError#CATCleanLastError to
  *           clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *             <li><tt>PointingCmpVarMngr_ERR_03</tt>:</li>
  *                This component is not impacted.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT SetManagementModeForImpactedPointingComponent(const CATIPLMComponent_var& ispImpactedPointingCompo, PointingVariantsManagementMode iManagementMode) = 0;





  ///////////////////////////////////////////////////////////////////////////////////////////
  //////////##############################################################///////////////////
  //////////# THE API FOR MANAGEMENT OF THE IMPACTED POINTING COMPONENTS #///////////////////
  //////////##############################################################///////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////

  /**
  * Manage the impacted pointing components variants following the input default mode of management<br>
  * <tt>PointingVariantsManagementMode</tt> given as input.
  * This API can be called on a synchronous or an asynchronous PLMIPointingVariantsManager.
  * Note that this API can be called even if <tt>AnalyzeAndReturnImpactedPointingComponents</tt> has not been called before.
  *
  *  @param iDefaultManagementMode
  *      The default mode for treatment of impacted pointing components. @see PointingVariantsManagementMode.<br>
  *      Note that <tt>iDefaultManagementMode</tt> may be overriden by some explicit modes chosen for a given impacted
  *      pointing component thanks to <tt>SetManagementModeForImpactedPointingComponent</tt> API.
  *   @return
  *     <ul>
  *       <li> S_OK if all impacted pointing components have been successfully treaten.</li>
  *       <li> S_FALSE if there is no impacted pointing component at all.</li>
  *       <li> E_FAIL if this methods fails. There are several reasons that can explain this failure that are
  *           listed below!<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional information
  *           about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href CATError#CATCleanLastError to
  *           clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_02</tt>:</li>
  *                The impacted pointing components have already been treaten.
  *             <li><tt>PointingCmpVarMngr_ERR_06</tt>:</li>
  *                Authoring operations have been performed on pointed instance that prevent from correctly treating it (asynchronous mode only)
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT ManageVariantsOfImpactedPointingComponents(const PointingVariantsManagementMode &iDefaultManagementMode) = 0;




  /////////////////////////////////////////////
  //////////########################///////////
  //////////# POST-MANAGEMENT APIS #///////////
  //////////########################///////////
  /////////////////////////////////////////////

  /**
  * Check wether or not the variant <tt>ispPointingVariant</tt> (of a pointing component) given as input
  * is effective.
  * This API can be called on a synchronous or an asynchronous PLMIPointingVariantsManager.
  * This API must be called after a call to <tt>ManageVariantsOfImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_04</tt>!
  * Any component that adheres to PLMIPointingVariant interface can be analyzed,<br>
  * it must not be necessarily an impacted pointing component of the list returned by <tt>AnalyzeAndReturnImpactedPointingComponents</tt>!
  *
  *  @param   ispPointingVariant
  *      Any component that adheres to PLMIPointingVariant interface.<br>
  *      Input parameter. <br>
  *   @return
  *     <ul>
  *       <li> S_OK if the variant of the pointing component <tt>ispPointingVariant</tt> given as input is effective.</li>
  *       <li> S_FALSE if the variant of the pointing component <tt>ispPointingVariant</tt> given as input is ineffective.</li>
  *       <li> E_INVALIDARG if <tt>ispPointingVariant</tt> is NULL_var/unset.</li>
  *       <li> E_FAIL if this methods fails to determine wether or not the variant<br>
  *            <tt>ispPointingVariant</tt> (of a pointing component) given as input is effective.<br>
  *            There are several reasons that can explain this failure that are listed below!<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional information
  *           about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href CATError#CATCleanLastError to
  *           clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_04</tt>:</li>
  *                The impacted pointing components have not yet been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT IsVariantEffective(const PLMIPointingVariant_var& ispPointingVariant) = 0;

  /**
  * Given an input variant <tt>ispPointingVariant</tt> of a pointing component, returns the list
  * of its _other_ existing variants in the session, no matter if they are effective or not.
  * This API can be called on a synchronous or an asynchronous PLMIPointingVariantsManager.
  * This API must be called after a call to <tt>ManageVariantsOfImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_04</tt>!
  * Any component that adheres to PLMIPointingVariant interface can be passed as input argument,<br>
  * it must not be necessarily an impacted pointing component of the list returned by <tt>AnalyzeAndReturnImpactedPointingComponents</tt>!
  *
  *  @param ispPointingVariant
  *      Any component that adheres to PLMIPointingVariant interface.<br>
  *      Input parameter. <br>
  *  @param oListOfOtherExistingVariants
  *      The list of _other_ existing variants in the session of the pointing components, no matter if they are effective or not.<br>
  *      Please not that this list does not contain the input variant <tt>ispPointingVariant</tt>.<br>
  *      Output parameter. <br>
  *      This list MUST be provided by caller as empty. This method returns an error otherwise. <br>
  *      This list is returned to caller as empty if method fails.
  *      ITEMS IN THIS RETURNED LIST MUST BE RELEASED BY THE CALLER AFTER USE !!
  *   @return
  *     <ul>
  *       <li> S_OK if the other existing variants of the pointing component <tt>ispPointingVariant</tt> given as input are successfully returned.</li>
  *       <li> S_FALSE if no other existing variant than <tt>ispPointingVariant</tt> is found in the session. The list returned is empty.</li>
  *       <li> E_INVALIDARG if <tt>ispPointingVariant</tt> is NULL_var/unset or if <tt>oListOfOtherExistingVariants</tt> is not passed empty.</li>
  *       <li> E_FAIL if this methods fails to return the list of the other existing variants in the session.<br>
  *            There are several reasons that can explain this failure that are listed below!<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional information
  *           about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href CATError#CATCleanLastError to
  *           clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_04</tt>:</li>
  *                The impacted pointing components have not yet been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT GetListOfOtherExistingVariants(const PLMIPointingVariant_var& ispPointingVariant,
    CATListPtrCATIPLMComponent& oListOfOtherExistingVariants) = 0;

  /**
  * Returns a small report (three counts actually) about how many existing variants have been deleted,<br>
  * how many existing variants have been rerouted and how many missing variants have been created.
  * This API can be called on a synchronous or an asynchronous PLMIPointingVariantsManager.
  * This API must be called after a call to <tt>ManageVariantsOfImpactedPointingComponents</tt> otherwise it fails with error code <tt>PointingCmpVarMngr_ERR_04</tt>!
  *
  *  @param oNbOfExistingVariantsDeleted
  *      The number of existing variants that have been deleted.<br>
  *      Output parameter.<br>
  *  @param oNbOfExistingVariantsRerouted
  *      The number of existing variants that have been rerouted.<br>
  *      Output parameter.<br>
  *  @param oNbOfMissingVariantsCreated
  *      The number of missing variants that have been created.<br>
  *      Output parameter.<br>
  *   @return
  *     <ul>
  *       <li> S_OK if this method succeeds to report.</li>
  *       <li> E_FAIL if this method fails to report. There
  *            are several reasons that can explain this failure that are listed below!<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional information
  *           about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href CATError#CATCleanLastError to
  *           clean the error manager.
  *           <ul>
  *             <li><tt>PointingCmpVarMngr_ERR_04</tt>:</li>
  *                The impacted pointing components have not yet been treaten.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT GetPostManagementReport(int &oNbOfExistingVariantsDeleted, int &oNbOfExistingVariantsRerouted, int &oNbOfMissingVariantsCreated) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(PLMIPointingVariantsManager, CATBaseUnknown);

#endif
