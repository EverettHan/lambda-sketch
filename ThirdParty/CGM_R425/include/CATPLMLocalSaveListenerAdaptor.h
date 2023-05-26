#ifndef CATIPLMLocalSaveListenerAdaptor_h
#define CATIPLMLocalSaveListenerAdaptor_h

/**
* @level Protected
* @usage U2
*/

#include "CATIPLMLocalSaveListener.h"

/**
 * This class is the adaptor corresponding to the  CATIPLMLocalSaveListener interface.
 * <br>This adaptor is supplied only for a better flexibility of CATIPLMLocalSaveListener; CATPLMLocalSaveListenerAdaptor's methods are not really implemented.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMLocalSaveListenerAdaptor: public CATIPLMLocalSaveListener
{
  public:

  // Standard constructors and destructors
    // -------------------------------------
    CATPLMLocalSaveListenerAdaptor ();
    virtual ~CATPLMLocalSaveListenerAdaptor ();
    
    
    
    //===================   Methods concerning process progression   =====================
    
    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_ProcessSteps
    */
    HRESULT Inform_ProcessSteps (const CATListOfCATUnicodeString & iStepNames, CATBoolean & oCancelProcess) ;
    
    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_NextStep
    */
    HRESULT Inform_NextStep (int iNsubparts, CATBoolean & oCancelProcess);
    
    
    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_ProgressInStep
    */
    HRESULT Inform_ProgressInStep (int iProgressValue, CATBoolean & oCancelProcess);
    
    
    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_ElementsToProcess
    */
    HRESULT Inform_ElementsToProcess (const CATIPLMListConsultation * iGlobalListAsSoFar,
      CATBoolean iDefinitiveGlobalList,
      CATBoolean & oCancelProcess);

    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_QuantitativeView
    */
    HRESULT Inform_QuantitativeView (int iNAttr,
      int iNSemanticalRelation,
      int iNStreams,
      int iNtotalStreamSize) ;


    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_Incident
    */
    HRESULT Inform_Incident (const CATListPtrCATIPLMErrorCell & iErrList,
      const CATUnicodeString iDefaultAlternative);

   /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_Incidents
    */
	HRESULT Inform_Incidents(const CATIAdpErrorMonitorAbstract *, const CATUnicodeString iDefaultAlternative);

    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#AskForConfirmation_Freezing
    */
    HRESULT AskForConfirmation_Freezing(CATBoolean & oAccept);

    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#Inform_TheEnd
    */
    HRESULT Inform_TheEnd();
    
    /**
     * @see CATPLMIntegrationInterfaces.CATIPLMLocalSaveListener#AskForConfirmation
     */
    HRESULT ValidateDataSize(const SessionComponentsInfos & iNewComponents, 
			     const SessionComponentsAndSizeInfos &iModifiedComponents,
			     CATBoolean &oAccept);

};


#endif
