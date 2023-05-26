	/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMTransferEngine_H
#define CATIPLMTransferEngine_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATError.h"

class CATIPLMCompleteGraph;
class CATIPLMTransferInformation;
class CATIAdpErrorMonitor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMTransferEngine;
#else
extern "C" const IID IID_CATIPLMTransferEngine ;
#endif

/**
 * This interface enables to ask the transfer of data between 2 providers.
 * Use @href CATPLMEngineToolbox#GetTransferEngine to get a pointer on the transfer engine. 
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMTransferEngine: public CATBaseUnknown
{
  CATDeclareInterface;

  /**
   * Different values of TransferMode:
   *
   *	TRANSFER_ME: transfer with source PLMIDs as input. (It is the default value)
   *				 in this mode we consider the source provider is already connected.
   *
   *	UPDATE_ME: transfer with target PLMIDs as input.
   *			   in this mode we consider the target provider is already connected.
   *			   in this mode it is mandatory to have the mapping elements corresponding
   *			   to the input PLMIDs in the target provider.
   */
  enum CATPLMTETransferMode {TRANSFER_ME = 1, UPDATE_ME = 2};

public:

   /**
   * Different scenarios:
   *	ASNEW : one shot transfer - objects are created as new ones in the destination provider
   *	ASNEWINCREMENTAL : transfer of objects "as new" in several steps
   *	MIGRATION : migration of objects including version information duplication
   *	COEXISTENCE : migrated objects can be updated during the successive transfers
   *	PUBLISH : Used while exporting objects to 3DXML
   */
 // enum CATPLMTEScenario {ASNEW = 0,/* ASNEWINCREMENTAL = 1,*/ MIGRATION = 1, COEXISTENCE_V5V6 = 2, COEXISTENCE_V6V5 = 3, PUBLISH = 4};
  enum CATPLMTEScenario {ASNEW = 0, MIGRATION = 1, COEXISTENCE_V5V6 = 2, COEXISTENCE_V6V5 = 3, PUBLISH = 4,ASNEWINCREMENTAL = 5, COEXISTENCE=6};

    /**
   * Different values of Lock Mode:
   *	NOLOCK: no lock transaction to be performed
   *	LOCK: locked object in the source will be locked in destination
   *	FULLLOCK: all object will be lock in the destination
   */
  enum CATPLMTELockMode {NOLOCK = 0, LOCK = 1, FULLLOCK = 2};

 /**
   * Elements composing scenarioUserInfo structure:
   *	name: Name of the user that will be used to transfer the data
   *	pwd: Password of the user that will be used to transfer the data
   *	role: Role of the user that will be used to transfer the data
   *	Note that these info will overwrite user information from profile if they are set (different from "")
   */
	struct scenarioUserInfo{
    CATUnicodeString name;
    CATUnicodeString pwd;
	CATUnicodeString role;
};

/**
   * Elements composing scenarioTransferScope structure:
   *	completeGraph: The input complete graph defining the set of elements to transfer.
   *	filter: The filter to be applied to the expand of the root object
   *	
   */
	struct scenarioTransferScope{
    CATIPLMCompleteGraph* completeGraph;
    CATUnicodeString filter;
};

/**
   * Elements composing scenarioBatchInfo structure:
   *	batchMode: Boolean that is used to force transition engine to launch transfer in batch mode.
   *	batchXMLPath: The path of the directory where the XML batch file will be generated
   *	batchProcessID: Process ID of the batch
   *	
   */
	struct scenarioBatchInfo{
	CATBoolean batchMode;
    CATUnicodeString batchXMLPath;
    char * batchProcessID;
};


/** 
 * Deprecated R205
 *
 */
  virtual HRESULT Transfer(CATIPLMCompleteGraph& iCompleteGraph,
						   CATIPLMTransferInformation& iTransferInfo) = 0;


/** 
 * Deprecated R215
 *
 */
  virtual HRESULT Transfer(CATIPLMCompleteGraph& iCompleteGraph,
						   CATUnicodeString& iSourceProviderName, 
						   CATUnicodeString& iTargetProviderName,
						   CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;

  /** 
 * Enables to transfer a set of objects between 2 providers.
 *
 * <br><b>Role</b>: This method transfers data from source provider to target provider.
 * <li>The transition engine will be in charge of opening the elements listed by the CompleteGraph and save them in the destination repository</li>
 * <li>A report logging all the transferrred objects and the possible messages generated during the process can be generated</li>
 *
 * @param iCompleteGraph [in]
 *   The input complete graph defining the set of elements to transfer.
 *
 * @param iSourceProviderName [in]
 *   The name of the source provider.
 *
 * @param iTargetProviderName [in]
 *   The name of the target provider.
 *
 * @param oErrorMonitor [out,CATBaseUnknown#Release]
 *   Error collector to log high level errors occurring during the transfer
 *
 * @param iTransferMode [in]
 *   The transfer mode "TransferMe" or "UpdateMe".
 *
 * @return
 *   <code>S_OK</code>Transfer is successfull. 
 *   <code>S_FALSE</code>Transfer has run until the end but some errors have occurred, see details in the report.
 *   <code>E_FAIL</code>Transfer failed.
 *
 */
  virtual HRESULT Transfer(CATIPLMCompleteGraph& iCompleteGraph,
						   CATUnicodeString& iSourceProviderName, 
						   CATUnicodeString& iTargetProviderName,
						   CATIAdpErrorMonitor*& oErrorMonitor,
						   CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;

/** 
 * Deprecated R215
 *
 */
  virtual HRESULT LaunchNavigationMigration(CATIPLMCompleteGraph& iCompleteGraph, 
											CATUnicodeString& iSourceProviderName, 
											CATUnicodeString& iTargetProviderName,
											CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;


/** 
 *
 * Enables to launch a navigation migration of a set of objects from a phase1 provider to a V6 provider.
 *
 * <br><b>Role</b>: This method migrates metadata info and Authoring Visu streams of objects from phase1 provider to V6 provider.
 * <li>Warning: The different Transfer Options should not be set in case of migration</li>
 *
 * @param iCompleteGraph [in]
 *   The input complete graph defining the set of elements to transfer.
 *
 * @param iSourceProviderName [in]
 *   The name of the source provider.
 *
 * @param iTargetProviderName [in]
 *   The name of the target provider.
 *
 * @param oErrorMonitor [out,CATBaseUnknown#Release]
 *   Error collector to log high level errors occurring during the transfer
 *
 *
 * @param iTransferMode [in]
 *   The transfer mode "TransferMe" or "UpdateMe".
 *
 * @return
 *   <code>S_OK</code>Migration is successfull. 
 *   <code>S_FALSE</code>Migration has run until the end but some errors have occurred,see details in the report.
 *   <code>E_FAIL</code>Migration failed.
 *
 */
  virtual HRESULT LaunchNavigationMigration(CATIPLMCompleteGraph& iCompleteGraph, 
											CATUnicodeString& iSourceProviderName, 
											CATUnicodeString& iTargetProviderName,
											CATIAdpErrorMonitor*& oErrorMonitor,
											CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;


/** 
 * Deprecated R215
 *
 */
   virtual HRESULT LaunchAuthoringMigration(CATIPLMCompleteGraph& iCompleteGraph, 
											CATUnicodeString& iSourceProviderName, 
											CATUnicodeString& iTargetProviderName,
											CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;

/** 
 * Enables to launch a authoring migration of a set of objects from a phase1 provider to a V6 provider.
 *
 * <br><b>Role</b>: This method migrates metadata info of objects and performs the authoring streams conversion from phase1 provider to V6 provider.
 * <li>Warning: The different Transfer Options should not be set in case of migration</li>
 *
 * @param iCompleteGraph [in]
 *   The input complete graph defining the set of elements to transfer.
 *
 * @param iSourceProviderName [in]
 *   The name of the source provider.
 *
 * @param iTargetProviderName [in]
 *   The name of the target provider.
 *
 * @param oErrorMonitor [out,CATBaseUnknown#Release]
 *   Error collector to log high level errors occurring during the transfer
 *
 * @param iTransferMode [in]
 *   The transfer mode "TransferMe" or "UpdateMe".
 *
 * @return
 *   <code>S_OK</code>Migration is successfull. 
 *   <code>S_FALSE</code>Migration has run until the end but some errors have occurred,see details in the report.
 *   <code>E_FAIL</code>Migration failed.
 *
 */
  virtual HRESULT LaunchAuthoringMigration(CATIPLMCompleteGraph& iCompleteGraph, 
											CATUnicodeString& iSourceProviderName, 
											CATUnicodeString& iTargetProviderName,
											CATIAdpErrorMonitor*& oErrorMonitor,
											CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;

 /** 
 * Deprecated R215
 *
 */ 
  virtual HRESULT LaunchAuthoringReverseMigration(CATIPLMCompleteGraph& iCompleteGraph, 
												  CATUnicodeString& iSourceProviderName, 
												  CATUnicodeString& iTargetProviderName,
												  CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;

 /** 
 *
 * Enables to launch a authoring REVERSE migration of a set of objects from a V6 provider to a phase1 provider.
 *
 * <br><b>Role</b>: This method migrates metadata info of objects and performs the authoring streams reverse conversion
 *					from V6 provider to phase1 provider.
 * <li>Warning: The different Transfer Options should not be set in case of migration</li>
 *
 * @param iCompleteGraph [in]
 *   The input complete graph defining the set of elements to transfer.
 *
 * @param iSourceProviderName [in]
 *   The name of the source provider.
 *
 * @param iTargetProviderName [in]
 *   The name of the target provider.
 *
 * @param oErrorMonitor [out,CATBaseUnknown#Release]
 *   Error collector to log high level errors occurring during the transfer
 *
 * @param iTransferMode [in]
 *   The transfer mode "TransferMe" or "UpdateMe".
 *
 * @return
 *   <code>S_OK</code>Reverse Migration is successfull. 
 *   <code>S_FALSE</code>Reverse Migration has run until the end but some errors have occurred,see details in the report.
 *   <code>E_FAIL</code>Reverse Migration failed.
 *
 */
  virtual HRESULT LaunchAuthoringReverseMigration(CATIPLMCompleteGraph& iCompleteGraph, 
												  CATUnicodeString& iSourceProviderName, 
												  CATUnicodeString& iTargetProviderName,
												  CATIAdpErrorMonitor*& oErrorMonitor,
												  CATPLMTETransferMode iTransferMode = TRANSFER_ME) = 0;

 /** 
 *
 * Deprecated R215
 *
 */
 //Old Signature - To be removed - IR-724068
  virtual HRESULT ProcessScenario(char * iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATUnicodeString& iBatchXMLPath,
								  CATUnicodeString& iFilter,
								  CATError * oError ) = 0;

  virtual HRESULT ProcessScenario(CATUnicodeString iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATUnicodeString& iBatchXMLPath,
								  CATUnicodeString& iFilter,
								  CATError * oError ) = 0;

/** 
 *
 * Enables to parse the Transition Profile, set information and launch respective migration.
 *
 * <br><b>Role</b>: This method parses the Transition profile.
 * <li>Warning: </li>
 *
   @param iXMLBuffer [in]
 *   The Transition Profile XML Buffer.
 *
 * @param iCompleteGraph [in]
 *   The input complete graph defining the set of elements to transfer.
 *
 * @param iUserPwd [in]
 *   .
 *
 * @param iBatchMode [in]
 *   .
 *
 * @param iBatchXMLPath [in]
 *  The path of the directory where the XML batch file will be generated
 *
 * @param iFilter [in]
 *  The filter to be applied to the expand of the root object
 *
 * @param oErrorMonitor [out,CATBaseUnknown#Release]
 *   Error collector to log high level errors occurring during the transfer
 *
 * @return
 *   <code>S_OK</code>ProcessScenario is successfull. 
 *   <code>S_FALSE</code>ProcessScenario has run until the end but some errors have occurred,see details in the report.
 *   <code>E_FAIL</code>ProcessScenario failed.
 *
 */
 //Old Signature - To be removed - IR-724068
  virtual HRESULT ProcessScenario(char * iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATUnicodeString& iBatchXMLPath,
								  CATUnicodeString& iFilter,
								  CATIAdpErrorMonitor*& oErrorMonitor) = 0;

  virtual HRESULT ProcessScenario(CATUnicodeString iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATUnicodeString& iBatchXMLPath,
								  CATUnicodeString& iFilter,
								  CATIAdpErrorMonitor*& oErrorMonitor) = 0;

/** 
 * Deprecated R215
 *
 */
 //Old Signature - To be removed - IR-724068
  virtual HRESULT ProcessScenario(char * iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATError * oError ) = 0;

  virtual HRESULT ProcessScenario(CATUnicodeString iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATError * oError ) = 0;

  /** 
 *
 * Enables to parse the Transition Profile, set information and launch respective migration.
 *
 * <br><b>Role</b>: This method parses the Transition profile.
 * <li>Warning: </li>
 *
   @param iXMLBuffer [in]
 *   The Transition Profile XML Buffer.
 *
 * @param iCompleteGraph [in]
 *   The input complete graph defining the set of elements to transfer.
 *
 * @param iUserPwd [in]
 *   .
 *
 * @param iBatchMode [in]
 *   .
 *
 * @param oErrorMonitor [out,CATBaseUnknown#Release]
 *   Error collector to log high level errors occurring during the transfer
 *
 * @return
 *   <code>S_OK</code>ProcessScenario is successfull. 
 *   <code>S_FALSE</code>ProcessScenario has run until the end but some errors have occurred,see details in the report.
 *   <code>E_FAIL</code>ProcessScenario failed.
 *
 */
 //Old Signature - To be removed - IR-724068
  virtual HRESULT ProcessScenario(char * iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATIAdpErrorMonitor*& oErrorMonitor) = 0;

  virtual HRESULT ProcessScenario(CATUnicodeString iXMLBuffer,
								  CATIPLMCompleteGraph& iCompleteGraph,
								  CATUnicodeString iUserPwd,
								  CATBoolean iBatchMode,
								  CATIAdpErrorMonitor*& oErrorMonitor) = 0;

  
  /** 
 * Enables to parse the Transition Profile, set information and launch respective migration.
 *
 * <br><b>Role</b>: This method parses the Transition profile.
 * <li>Warning: </li>
 *
   @param iXMLBuffer [in]
 *   The Transition Profile XML Buffer.
 *
 * @param iTransferScope [in]
 *   Informations related to the scope of objects to transfer. See scenarioTransferScope structure for more information.
 *
 * @param iUserInfo [in]
 *   Informations related to the user that is used to transfer the objects. See scenarioUserInfo structure for more information.
 *
 * @param iBatchInfo [in]
 *   Informations related to the batch. See scenarioBatchInfo structure for more information.
 *
 * @param oError [out]
 *   .
 *
 * @return
 *   <code>S_OK</code>ProcessScenario is successfull. 
 *   <code>S_FALSE</code>ProcessScenario has been rollbacked, see details in the report.
 *   <code>E_FAIL</code>ProcessScenario failed.
 *
 */
 //Old Signature - To be removed - IR-724068
  virtual HRESULT ProcessScenario(char * iXMLBuffer,
								  scenarioTransferScope& iTransferScope,
								  scenarioUserInfo& iUserInfo,
								  scenarioBatchInfo& iBatchInfo,
								  CATError * oError ) = 0;

  virtual HRESULT ProcessScenario(CATUnicodeString iXMLBuffer,
								  scenarioTransferScope& iTransferScope,
								  scenarioUserInfo& iUserInfo,
								  scenarioBatchInfo& iBatchInfo,
								  CATError * oError ) = 0;

};
CATDeclareHandler( CATIPLMTransferEngine, CATBaseUnknown );
#endif
