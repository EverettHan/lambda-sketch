/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2006  
//-----------------------------------------------------------------------------
// class CATOmbUndoRedoActorDeclarationServices:
//
//===================================================================
//  July 2006  Creation: RJS
//===================================================================
#ifndef CATOmbUndoRedoActorDeclarationServices_H_
#define CATOmbUndoRedoActorDeclarationServices_H_

/**
* @level Protected 
* @usage U6
*/

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATOmbUndoRedoDefs.h"
#include "CATLISTP_Declare.h"
#include "CATOmbSessionService.h"
#include "CATUndoSpecialStepHandler.h"
#include "CATOmxSR.h"
class CATBaseUnknown;
class CATUnicodeString;
class CATDocument;
class CATIContainer;
class CATLISTP(CATIContainer);
class CATOmbUndoRedoAction;



/** 
  * CATOmbSpecialStepHandler enable caller to declare that log have to stop logging (Undo/Redo, DirtyManagement) during special steps : such as Open, Save, LocalSave.
  * Notice : using this to disable Undo/Redo will force to purge whole Undo/Redo log recorder before the step.
*/
class ExportedByAD0XXBAS CATOmbSpecialStepHandler: public CATOmeSpecialStepHandler{

  CATUnicodeString m_DebugInfos;
  CATOmbSpecialStepHandler (const CATOmbSpecialStepHandler&);
  CATOmbSpecialStepHandler operator=(CATOmbSpecialStepHandler&);

public:
  /** 
  * CATOmbSpecialStepHandler enable caller to declare that log have to handle logging during special step : such as Open, Save, LocalSave.
  * Instanciates this service.
  * <br><b>Role</b>: This constructor instanciates this services. It must not be instanciated by a new.
  * @param iAuthorizedRecorder [in] : declare which kind of recorder associated to a software layout could be authorized to record information whenever its disabled
  *                                   Legal values are :
  *                                     - OMB_R_UNKNOWN     : No recorder is authorized.
  *                                     - OMB_R_CONTAINER   : Only Recorder from container are authorized.
  *                                     - OMB_R_COMPONENT   : Only Recorder from Component are authorized.
  *                                     - OMB_R_OBSERVER    : Only Recorder from Observer are authorized.
  *                                     - OMB_R_SPECIALTOS  : Only Recorder from TOS are authorized.
  *                                     - OMB_R_ALL         : All Recorders are authorized.
  * @param iSpecialStepType [in] : enum to declare which strategy will be used to manage error (Assert, Abend, Extended error).
  * @param iHandlingMode [in] : enum to declare which kind of logging is disabled.
  * @param iIsReversible [in] : declare whether the special step is reversible and then leads to purge of Undo/Redo log when it is irreversible
  * @param iDebugInfos [in] : useful informations for debug
  */
  CATOmbSpecialStepHandler(OmbRecorderType iAuthorizedRecorder,OmbHandlingMode iHandlingMode,CATBoolean iIsReversible,OmbSpecialStepType iSpecialStepType,const char* iDebugInfos,CATOmbSessionContext* ipSessionContext=NULL);
  
  /**
  * Starts...
  */
  HRESULT StartHandling();
  /**
  * Stops...
  */
  HRESULT StopHandling();

  ~CATOmbSpecialStepHandler();
};


/**
* <b>Role</b> : CATOmbUndoRedoLifeCycleManager informs UndoRedoEngine about status of Containers in Session.
* Containers may be loaded or created in session. Moreover they can have a context which is their owning document.
* On Document Load/Creation the context must be defined StartDocumentContext at the beginning of load of document
* and EndDocumentContext at the end of Load.
* Then you can declare Containers, by using RegisterContainerInUndoRedoEngine.
* On unitary Load or Creation of containers, you don't need to use Start/EndDocumentContext
*/
#define FIXMAND577490
class ExportedByAD0XXBAS CATOmbUndoRedoLifeCycleManager{
public:

  /**
  * Declare begining of Document Context for Load/Create operation of document. 
  * @param iDocument
  *		Document context. 
  * @param iContainer
  *		iContainer to add. 
  * @param iContext
  *		To distinguish OPEN, NEW, and UNDEFINED cases. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, operation was already done.
  *   <code>E_FAIL</code>, operation failed.
  */
  static HRESULT StartDocumentContext(OmbDocumentUndoRedoContext iContext);
  /**
  * Declare begining of Document Context for Load/Create operation of document. 
  * @param iDocument
  *		Document context. 
  * @param iContainer
  *		iContainer to add. 
  * @param iContext
  *		To distinguish OPEN, NEW, and UNDEFINED cases. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, operation was already done.
  *   <code>E_FAIL</code>, operation failed.
  */
  static HRESULT UpdateDocumentContext(CATDocument& iDocument,OmbDocumentUndoRedoContext iContext);

  /**
  * Register a container in UndoRedo Engine.
  * When added iContainer is AddReffed by UndoRedo Engine. 
  * @param iContainer
  *		iContainer to add. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, operation was already done.
  *   <code>E_FAIL</code>, operation failed.
  */
  static HRESULT RegisterContainerInUndoRedoEngine(CATDocument& iDocument,CATIContainer& iContainer);

  /**
  * Declare end of Document Context for Load/Create operation of document. 
  * @param iDocument
  *		Document context. 
  * @param iContainer
  *		iContainer to add. 
  * @param iOperationSucceeded
  *		TRUE if Load/Create operation has succeeded. 
  * @param iContext
  *		To distinguish OPEN, NEW, and UNDEFINED cases. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, operation was already done.
  *   <code>E_FAIL</code>, operation failed.
  */
  static HRESULT EndDocumentContext(CATDocument& iDocument, CATBoolean iOperationSucceeded,OmbDocumentUndoRedoContext iContext);

  /**
  * Declare that document is removing
  * @param iDocument
  *		Document to be removed. 
  * 
  */
  static HRESULT UpdateUndoRedoEngineAboutDocumentRemoval(CATDocument& iDocument);
  /**
  * Declare that container is removing
  * @param iDocument
  *		Document to be removed. 
  * @param iContainer
  *		Container to be removed.  
  */
  static HRESULT UpdateUndoRedoEngineAboutContainerRemoval(CATDocument* iDocument,CATIContainer& iContainer);

#ifdef FIXMAND577490
  /**
  * Declare that a transaction has been started with Server
  * @param iReason
  *		Debug purpose : example UpdateUndoRedoEngineAboutServerTransactionStart("Long transaction for Save");
  */
  static HRESULT UpdateUndoRedoEngineAboutServerTransactionStart(const char* iReason);

  /**
  * Declare that a transaction has been ended with Server
  * @param iReason
  *		Debug purpose : example UpdateUndoRedoEngineAboutServerTransactionEnd("Long transaction for Save");
  */
  static HRESULT UpdateUndoRedoEngineAboutServerTransactionEnd(const char* iReason);
#endif
  /**
  * EnableDirtyManagement
  * @param iReason
  *		Debug purpose : example EnableDirtyManagement("Long transaction for Save");
  */
  static HRESULT EnableDirtyManagement(const char* iReason);

  /**
  * DisableDirtyManagement
  * @param iReason
  *		Debug purpose : example DisableDirtyManagement("Long transaction for Save");
  */
  static HRESULT DisableDirtyManagement(const char* iReason);

private:

  CATOmbUndoRedoLifeCycleManager(){};
  virtual ~CATOmbUndoRedoLifeCycleManager(){};  
  CATOmbUndoRedoLifeCycleManager(const CATOmbUndoRedoLifeCycleManager &);
  CATOmbUndoRedoLifeCycleManager& operator =(const CATOmbUndoRedoLifeCycleManager &);
};

#endif
