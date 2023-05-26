/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2008
#ifndef CATIPLMTransferBehaviors_H
#define CATIPLMTransferBehaviors_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATIPLMTransferEngine.h"

class CATListValCATString;
class CATListValCATUnicodeString;
class CATString;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMTransferBehaviors;
#else
extern "C" const IID IID_CATIPLMTransferBehaviors ;
#endif

/**
 * This interface enables to get and set options related to the data transfer.
 * <br>
 * <ul>
 *   <li>These information are used by  @href  CATIPLMTransferToProvider</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMTransferBehaviors: public CATBaseUnknown
{
  CATDeclareInterface;

  /**
   * DEPRECATED R209
   */
  enum CATPLMTEUpdateMode {NOUPDATE = 0, NONE = 1, REPLACE = 2};

public:

/** 
 * Enables to activate the lock behavior with a dedicated lock mode for the transfer.
 *
 * @param iLockMode [in]
 *   The mode of Lock Behavior.
 *
 */
	virtual void ActivateLock(CATIPLMTransferEngine::CATPLMTELockMode& iLockMode)= 0;

/** 
 * Enables to activate the publication behavior during transfer.
 ***************************************************************
 *******************    DEPRECATED    **************************
 *************** USE one of these :
 * ActivateCustomization
 * ActivateVersioning
 * ActivateMaturity
 * ActivatePeopleAndOrganization
 ***************************************************************
 */
 virtual void ActivatePublication()= 0;

/** 
 * Enables to activate the Stop and Restart behavior during transfer.
 *
 * @param iSRValue [in]
 *   The number of objects to be treated in each transaction during transfer.
 *
 */
 virtual void ActivateStopAndRestart(int iSRValue)= 0;

 /** 
 * Enables to activate the Rename behavior during transfer.
 *
 * @param iRenameValue [in]
 *   The value of the suffix to be added to each objects PLMExternalID
 *
 * @deprecated V6R2010x use @href CATIPLMTransferBehaviors#ActivateIdentificationInitialization
 */
 virtual void ActivateRename(CATUnicodeString& iRenameValue)= 0;


 /** 
 * Enables to activate BusinessRule during transfer.
 * BusinessRule OpeningId = PLMIdentificationInitialization
 *
 */
 virtual void ActivateIdentificationInitialization()= 0;

 /** 
 * DEPRECATED R209
 *
 */
 virtual void ActivateMemorization()= 0;

 /** 
 * DEPRECATED R209
 *
 */
 virtual void ActivateUpdate(CATPLMTEUpdateMode& iUpdateMode)= 0;

 /** 
 * Enables to activate the batch behavior for transfer.
 *
 * @param ibOnlyXML [in]
 * CATTrue to generate the batch XML file without launching the batch
 *
 */
 virtual void ActivateBatch(CATBoolean ibOnlyXML)= 0;
  
 /** 
 * Enables to activate the transfer of custo attributes.
 *
 */
 virtual void ActivateCustomization()= 0;

 /** Deprecated since R209**/
  /** 
 * Enables to activate the transfer of V_version.
 *
 */
 virtual void ActivateVersioning()= 0;

  /** 
 * Enables to activate the transfer of V_maturity.
 *
 */
 virtual void ActivateMaturity()= 0;

  /** 
 * Enables to activate the transfer of ownership attributes.
 *
 */
 virtual void ActivatePeopleAndOrganization()= 0;


 /** 
 * Enables to activate the "ulti PDM" reconciliation mechanism.
 *
 */
 virtual void ActivateMultiPDMReconciliation()= 0;

 /** 
 * Enables to activate the "Representation Migration in Light Mode".
 *
 */
 virtual void ActivateRepLightMode() = 0;

 /** 
 * Enables to activate the "Refresh Data" mechanism.
 *
 */
 virtual void ActivateRefreshData()= 0;

 /** 
 * Enables to activate the "Custo attributes protection" mechanism.
 *
 */
 virtual void ActivateCustoAttributesProtection()=0;

 /** 
 * Enables to activate the "Execution log" mechanism.
 *
 */
 virtual void ActivateExecutionLog()=0;

 /** 
 * Enables to activate the "Post Process Preparation" mechanism.
 *
 */
 virtual void ActivatePostProcessPreparation(CATUnicodeString& iType, CATUnicodeString& iPath)=0;

 /** 
 * Enables to activate the "Post Process" mechanism.
 *
 */
 virtual void ActivatePostProcess(CATUnicodeString& iType)=0;

 /** 
 * Enables activation of V5Native transfer mode mechanism.
 *
 */
virtual void ActivateV5NativeMode()=0;

/** 
 * Enables activation of check mode.
 *
 */
virtual void ActivateCheckMode()=0;

/** 
 * Enables activation of BL mandatory.
 *
 */
virtual void ActivateBLMandatory()=0;

/** 
 * Enables activation of Configured data and non configured data transfer.
 *
 */
virtual void ActivateConfiguredDataTransfer()=0;

/** 
 * Enables activation of dictionnary config transfer.
 *
 */
virtual void ActivateConfigDictionaryTransfer()=0;

/** 
 * Enables activation of Proxy vault file access.
 *
 */
virtual void ActivateProxyVaultFileAccess()=0;

/** 
 * Enables activation of ExpandByLevel for ConfigDico transfer.
 *
 */

virtual void ActivateExpandByLevel(int iExpandByLevel)=0;

};
CATDeclareHandler( CATIPLMTransferBehaviors, CATBaseUnknown );
#endif
