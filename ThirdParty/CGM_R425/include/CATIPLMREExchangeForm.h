// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// CATIPLMREExchangeForm.h
// Define the CATIPLMREExchangeForm interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Oct 2016  Creation: WPU
//===================================================================
#ifndef CATIPLMREExchangeForm_H
#define CATIPLMREExchangeForm_H

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMREExchangeForm;
#else
extern "C" const IID IID_CATIPLMREExchangeForm ;
#endif

#include "CATCollec.h"
class CATLISTV(CATPLMID);

//------------------------------------------------------------------

/**
  * Interface associated with the Replication Engine.
  * <br><b>Role</b>: it allows to access to set CATPLMREExchangeForm  
  */

class ExportedByCATPLMIntegrationInterfaces CATIPLMREExchangeForm: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

      enum ExchangeContextCmd
      {
         EXCHANGE_UNKNOWN_CMD,
         EXCHANGE_EXPORT_CMD,
         EXCHANGE_PUBLISH_CMD,
         EXCHANGE_IMPORT_CMD,
         EXCHANGE_SYNCHRONIZE_CMD,
         EXCHANGE_SITEINFORMATION_CMD,
#ifdef CATIAR424 //FUN118229
		 EXCHANGE_EXPORT_DW_CMD
#endif
      };
     
    /**
      * Initialize context command of Exchange Form for objects selected as input by user. 
      * @param iCtxtCmd [in]
      *   The enum identifying the context command to be taken into account
      * @return 
      * <br><b>Legal values:</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Set exchange context successfully </dd>
      *   <dt>E_FAIL</dt>  <dd>Internal error when trying to set exchange context</dd>    
      * </dl>
      */
      virtual HRESULT SetExchangeContextCmd(const ExchangeContextCmd iCtxtCmd) = 0;
    
   /**
     * Set Exchange Objects from a list of PLMID.
     * @param ilstPLMIDs [in]
     *   The list of identifier of objects to be taken into account.
     * @return 
     * <br><b>Legal values:</b>
     * <dl>
     *   <dt>S_OK</dt>    <dd>Success</dd>
     *   <dt>E_FAIL</dt>  <dd>Internal error</dd>    
     * </dl>
     */
     virtual HRESULT SetExchangeObjects(CATLISTV(CATPLMID) &ilstPLMIDs) = 0;

   /**
     * Set Exchange Objects from a list of PLMID for objects brought by completion.
     * @param ilstPLMIDs [in]
     *   The list of identifier of objects to be taken into account.
     * @return 
     * <br><b>Legal values:</b>
     * <dl>
     *   <dt>S_OK</dt>    <dd>Success</dd>
     *   <dt>E_FAIL</dt>  <dd>Internal error</dd>    
     * </dl>
     */
     virtual HRESULT SetCompletionExchangeObjects(CATLISTV(CATPLMID) &ilstPLMIDs) = 0;

   /**
     * Set Exchange Objects from a list of PLMID for objects brought by completion.
     * @param ilstPLMIDs [in]
     *   The list of identifier of objects to be taken into account.
     * @return 
     * <br><b>Legal values:</b>
     * <dl>
     *   <dt>S_OK</dt>    <dd>Success</dd>
     *   <dt>E_FAIL</dt>  <dd>Internal error</dd>    
     * </dl>
     */

   /**
     * Set edition token scope on Exchange Objects that are 
     * 1. Part of Input Spec specifically for Delegation/Waive/Revoke
     * 2. Brought by completion from a list of PLMID. Completion scope is set on objects brought by completion specifically for Delegation/Waive/Revoke
     * @param ilstPLMIDsInputSpec [in]
     *   The list of identifier of objects selected by user as Input to be taken into account.
     * @param ilstPLMIDCompleted [in]
     *   The list of identifier of objects brought by completion to be taken into account.
     * @return 
     * <br><b>Legal values:</b>
     * <dl>
     *   <dt>S_OK</dt>    <dd>Success</dd>
     *   <dt>E_FAIL</dt>  <dd>Internal error</dd>    
     * </dl>
     */
     virtual HRESULT SetEditionTokenScopeOnExchangeObjects(CATLISTV(CATPLMID) &ilstPLMIDsInputSpec,
                                                           CATLISTV(CATPLMID) &ilstPLMIDCompleted) = 0;
#ifdef CATIAR424 
	 // FUN112334
	 virtual void SetGlobalInformation(const CATUnicodeString & iusGlobalInfo) = 0;
	 virtual CATUnicodeString GetGlobalInformation() = 0;
#endif

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMREExchangeForm, CATBaseUnknown );


#endif
