/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATOmbSwitchWizard_H
#define CATOmbSwitchWizard_H

/**
* @level Protected 
* @usage U1
*/

#include "CATOmbSwitchEngine.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATOmiSwitchOperation.h"
#include "CATBoolean.h"
#include "CATOmxSR.h"
#include "CATOmxAutoPtr.h"

class CATSession;
class CATOmbLoadingModeRuleSet;
class CATOmiSwitchOperation;
class CATIOmiSwitchEngine;
class CATOmbLoadingModeRuleSet;
class CATBaseUnknown;
class CATLISTP(CATError);
class CATLISTV(CATOmbSwitchOperationInformation);


/*
*	Helps to analyse and solve switch engine validation errors.
*  Can be use during the second batch execution step of a switch operation (three steps : AddLoadingModeRules, 
*  ValidateSwitchOperations and ExecuteSwitchOperations).
*/

class ExportedByCATOmbSwitchEngine CATOmbSwitchWizard
{
	friend class CATOmbSwitchEngineImpl;

public:

	CATOmbSwitchWizard();
	~CATOmbSwitchWizard();

	/** 
	* Retrieve Switch that cannot be performed.
	*
	* <br><b>Role</b>: Retrieve Switches that cannot be performed.
	*
	* @param oRefusedSwitchs [out]
	*   List of failed switches after Validation step.
	*
	* @return
	*       <li> S_OK :   Execution successfull.
	*       <li> E_FAIL : Unexpected error.
	*
	*/
	HRESULT RetrieveRefusedSwitch(CATLISTP(CATOmiSwitchOperation)& oRefusedSwitchs);

	/** 
	* Retrieve Switch that can be performed.
	*
	* <br><b>Role</b>: Retrieve Switches that can be performed.
	*
	* @param oAuthorizedSwitchs [out]
	*   List of succeeded switches after Validation step.
	*
	* @return
	*       <li> S_OK :   Execution successfull.
	*       <li> E_FAIL : Unexpected error.
	*
	*/
	HRESULT RetrieveAuthorizedSwitch(CATLISTP(CATOmiSwitchOperation)& oAuthorizedSwitchs );


	/** 
	* Apply current proposal set (calculated by Switch Wizard and modified by user) and do a SwitchEngine Validate step.
	*
	* <br><b>Role</b>: Explain what this method does.
	*
	*
	* @return
	*   <code>S_OK</code> Validation succeeded, ready to execute ExecuteSwitchOperations.
	*   <code>S_FALSE</code> Validation failed on a/several RepRef. A new Rule set has been calculated.
	*  				      Use previous methods to analyse error and try this method again.
	*   <code>E_FAIL</code> Internal error.
	*
	*/
	HRESULT ApplyProposedModeAtNextExecute();

private :

	HRESULT ReInitialize();
	HRESULT CalculateProposedAlternateMode();

	CATOmxSR<CATIOmiSwitchEngine> _pSwitchEngine;
	CATOmxAutoPtr<CATOmbLoadingModeRuleSet> _pOmbAlternativeModeSet;

	CATLISTP(CATOmiSwitchOperation) _SwitchOperationToValidate;
	CATLISTP(CATOmiSwitchOperation) _RefusedSwitchOperations;
	
	CATBoolean _HasBeenCalculated;
	CATBoolean _IsValidated;
	CATBoolean _ForbiddenToUnloadDirtyAuthoringSD;
  CATBoolean _ForbiddenToLoadAdditionalStream;

};

#endif
