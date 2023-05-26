#ifndef CATIPLMGenericListenerAbstract_h
#define CATIPLMGenericListenerAbstract_h

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATListPtrCATIPLMErrorCell.h"


class CATIPLMListConsultation;
class CATIAdpErrorMonitorAbstract;

/**
 * @level Private
 * @usage U6
 */

//------------------------------------------------------------------

//DOCUMENTER LES RETOUR OU LES ENLEVER !!



class ExportedByCATPLMIntegrationInterfaces CATIPLMGenericListenerAbstract : public CATBaseUnknown
{
 public :
  //===================   Methods concerning process progression   =====================

  /**
   * Informs the save/open command about the decomposition in main steps of the global save/open process.
   * @param iStepNames  
   *    The list of the name  
   * @param oCancelProcess  
   *    TRUE if the process'client desirs to stop the process.
   */
  virtual HRESULT Inform_ProcessSteps (const CATListOfCATUnicodeString & iStepNames, CATBoolean & oCancelProcess) =0;


  /**
   * Informs the save/open command that the process is beginning the next step (among the process steps declared by Inform_ProcessSteps).
   * @param iNsubparts      how many subparts constitue the process steps we are going to begin. 
   *                         Is equal to the number of times that Inform_ProgressInStep will be called during this step.
   *                         0 is a possible value.
   * @param oCancelProcess  TRUE if the process'client desirs to stop the process.
   */
  virtual HRESULT Inform_NextStep (int iNsubparts, CATBoolean & oCancelProcess)=0;


  /**
   * Informs the save/open command  about the progress in the current process phase.
   * @param iProgressValue  the progress state of the current phase, in percent
   * @param oCancelProcess  TRUE if the process'client desirs to stop the process
   */
  virtual HRESULT Inform_ProgressInStep (int iProgressValue, CATBoolean & oCancelProcess)=0;



  //===================   Methods concerning elements concerned by the process   =====================


  /**
   * Informs the save/open command  about which elements will be treated by the process.
   * @param iGlobalListAsSoFar  The overall list of the elements that the process has already determined as being concerned by the process.
   *                             iGlobalListAsSoFar list may increase during the process performing, that's why Inform_ElementToProcess can be calles several times.
   *                             This pointer is built and destructed by the Inform_ElementsToProcess's client
   * @param iDefinitiveGlobalList  indicates whether the process may determine new elements participating to the process (FALSE value) or the iGlobalListAsSoFar is definitely computed (TRUE value).
   * @param oCancelProcess  TRUE if the process'client desirs to stop the process.
   */
  virtual HRESULT Inform_ElementsToProcess (const CATIPLMListConsultation * iGlobalListAsSoFar,
					    CATBoolean iDefinitiveGlobalList,
					    CATBoolean & oCancelProcess)=0;

  /**
   * Gives a quantitative view of the process.
   * <br><b>Role</b>: For the moment this method is used only for the save process to inform at the end of the process on the volume of the saved data.
   * @param iNAttr 
   *        Number of metadata attributes treated by the process
   * @param iNSemanticalRelation 
   *        Number of semantical relations treated by the process
   * @param iNStreams 
   *        Number of streams treated by the process
   * @param iNtotalStreamSize 
   *        Total suze of the streams treated by the process,in kilo bytes.
   */
  virtual HRESULT Inform_QuantitativeView (int iNAttr,
					   int iNSemanticalRelation,
					   int iNStreams,
					   int iNtotalStreamSize) = 0 ;


  //===================   Methods concerning error occurences   =====================

  //-------- 1rst error mode :  The Default alternative mode   -------------------------

  /**
   * @deprecated V6R2010x
   * @use CATIAdpErrorMonitor
   */
  virtual HRESULT Inform_Incident (const CATListPtrCATIPLMErrorCell & iErrList,
				   const CATUnicodeString iDefaultAlternative)=0;

  /**
   * @deprecated V6R2010x
   * @use CATIAdpErrorMonitor
   */
  virtual HRESULT Inform_Incidents (const CATIAdpErrorMonitorAbstract * ipErrorMonitor,
				   const CATUnicodeString iDefaultAlternative)=0;

  /**
   * Ask for confirmation before ending the process.
   * <br><b>Role</b>: Errors may have occured during the process. And the process may have been influenced by this errors (for example, a save may have restrict its save domain)
   * That's why the end user has to confirm that he aggrees with the suggested way to perform the process.
   * @param oAccept 
   *        TRUE if the end user aggrees with the process (as initially defined or as rerooted because of the errors). 
   *        FALSE if not. The FALSE value implies a total cancel of the process.
   * <dl>
   *   <dt>TRUE</dt>  
   *   <dd>The performing is accepted</dd>
   *   <dt>FALSE</dt>  
   *   <dd>The performing is not accepted, the processing will be canceled.</dd>
   * </dl>
   */
  virtual HRESULT AskForConfirmation_Freezing(CATBoolean & oAccept)=0;

  /**
   * Informs that the process ends.
   */
  virtual HRESULT Inform_TheEnd()=0;

};

#endif
