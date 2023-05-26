/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//  July 2006  Creation: RJS
//===================================================================

#ifndef CATOmbSessionUndoRecordServices_H
#define CATOmbSessionUndoRecordServices_H

/**
* @level Protected 
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATOmbUndoRedoDefs.h"
#include "CATOmbUndoRedoActorDeclarationServices.h"

class CATOmbUndoRedoMementoFactory;
class CATOmbSessionUndoRedoTransaction;
class CATOmbUndoRedoObserver;
class CATProxySpace;
class CATOmbObserverRecorder;
class UndoRedoContainer;
struct CATOmbUndoRedoData;
/**
* Service grouping calls related to record of Mementos of Model's states in session. 
* <b>Role</b>: This session service exposes ObjectModelerBase APIs to record mementos in SessionUndo log. <br>
* NOTE: <i>Always instanciate this service on the stack.</i>
*/
#define OMB_PREREQ_FOR_UNDO_DIRTY

#define RECORDER_CATBASEUNKNOWN


#ifdef CATOmbSessionRecorderExportOldSignature
class CATIContainer;
#else
#include "CATIContainer.h"
#endif

struct CATOmbMementoId;
#include "CATOmeSessionRecorder.h"
#include "CATComponentId.h"

class ExportedByAC0XXLNK CATOmbSessionRecorder : public CATOmeSessionRecorder
{            
public:

  /**
  * Creates the service. New signature using CATBaseUnknown
  * @param iWorkingContainer
  *		A pointer related to current working container. 
  */
  CATOmbSessionRecorder(const CATBaseUnknown* iWorkingContainer);
#ifdef CATOmbSessionRecorderExportOldSignature
  /**
  * Creates the service.   
  * @param iWorkingContainer
  *		A pointer related to current working container. 
  */
  CATOmbSessionRecorder(const CATIContainer* iWorkingContainer);
#endif

  CATBoolean CanRecord();

  HRESULT RecordMemento(const CATOmbUndoRedoMementoFactory& iMementoFactory, CATOmbMementoId& ioMtoId);

  
  /**
  * Data Modelers which don’t want to record mementos in SessionUndo log during initialization step of their data use this API jointly with EndModelerInitStep API.
  * @param iWorkingContainer
  *		Container related to modified data. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, already done.
  *   <code>E_ACCESSDENIED</code>, container is removed or EndModelerInitStep has already been done.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  */
  static HRESULT StartModelerInitStep(const CATIContainer* iWorkingContainer);

  /**
  * Data Modelers which don’t want to record mementos in SessionUndo log during initialization step of their data use this API jointly with StartModelerInitStep API.
  * @param iWorkingContainer
  *		Container related to modified data. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, already done.
  *   <code>E_ACCESSDENIED</code>, container is removed or StartModelerInitStep have ever been done.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  */
  static HRESULT EndModelerInitStep(const CATIContainer* iWorkingContainer);

  /**
  * Data Modelers which don’t want to record mementos in SessionUndo log for a Container.
  * Data Modelers declare that this container will never record memento and/or update Dirty Status of related document during the whole session life cyle.
  * @param iWorkingContainer
  *		Container related to modified data. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, already done.
  */
  static HRESULT DisableRecordOnContainer(const CATIContainer* iWorkingContainer);

  /**
  * Update the service regarding current state of UndoRedo Engine .   
  * @param iWorkingContainer
  *		A pointer related to current working container. 
  */
  inline void UpdateInternals(const CATIContainer* iWorkingContainer){Init(iWorkingContainer);}
  inline void UpdateInternalsForContainer(const CATBaseUnknown* iWorkingContainer){InitForContainer(iWorkingContainer);}

  // do not use 
  CATBoolean NeverRecord(const CATBaseUnknown* iWorkingContainer);

  virtual ~CATOmbSessionRecorder();
private:
  
  CATBaseUnknown_var m_component;  // gestion undo sur composant
  CATOmxSR<UndoRedoContainer> m_container;

  HRESULT ProcessAfterRecord(const CATOmeUndoRedoMementoFactory& iMementoFactory,CATOmbUndoRedoData& oUndoRedoData);

  CATOmeSessionRecorder::ObjectState GetState();
  CATOmbSessionRecorder (const CATOmbSessionRecorder &);
  CATOmbSessionRecorder& operator=(const CATOmbSessionRecorder&);

  void SetRecordModeFromUndoMode(OmbUndoRedoMode iUndoMode,OmbHandlingMode hmode);
  //TODO HRESULT Init(OmbRecorderType iRecorderType);
  void Init(const CATIContainer* iWorkingContainer);
  void InitForContainer(const CATBaseUnknown* iWorkingContainer);

  CATBoolean CheckV5NativeReadOnly(const CATOmeUndoRedoMementoFactory & iMementoFactory);

protected:
  CATOmbSessionRecorder();
};

/** 
* CATOmbSessionFilterForSaveTransaction enables caller to ask session log to filter forbidden operation on container which lead Undo/Redo record during special steps : such as Open, Save, LocalSave.
* Notice : 
*      + This is a temporary bypass and will be remove as soon as ProductStructure will stop to modify bounding box during save operation.
*      + Using this means you know the impact of modification performed on your container during save and you are aware that it is safe to ignore them
*/
class ExportedByAC0XXLNK CATOmbSessionFilterForSaveTransaction{
  static CATULONG32 m_occ;
  CATULONG32 m_id;
  CATUnicodeString m_DebugInfos;
  CATBaseUnknown_var m_holder;
  unsigned char m_state;
  CATOmbSessionFilterForSaveTransaction (const CATOmbSessionFilterForSaveTransaction&);
  CATOmbSessionFilterForSaveTransaction operator=(CATOmbSessionFilterForSaveTransaction&);
  friend class SessionUndoErrorManager;
  CATBaseUnknown& GetFilteringKey();
public:
  /** 
  * CATOmbSessionFilterForSaveTransaction enables caller to ask session log to filter forbidden operation on container which lead Undo/Redo record during special steps : such as Open, Save, LocalSave.
  * Instanciates this service.
  * <br><b>Role</b>: This constructor instanciates this services. It must not be instanciated by a new.
  * @param iContainer [in] : declare on which container filter is put
  * @param iDebugInfos [in] : useful informations for debug
  */
  CATOmbSessionFilterForSaveTransaction(CATIContainer* iContainer,const char* iDebugInfos);
  /**
  * Start...
  */
  HRESULT StartFiltering();
  /* 
  * Stop...
  */
  HRESULT StopFiltering();
  ~CATOmbSessionFilterForSaveTransaction();
};


/** 
* CATOmbSessionApplicativeUndoStepHandler enables caller to invalidate undo log until next transaction.
* Notice : 
*      + This is a temporary bypass only for ProductStructure
*/
#if !defined(_WINDOWS_SOURCE) || defined (__CATPrdModelInit) || defined (__AC0XXLNK) || defined (__TestSessionUndoSSH)

class ExportedByAC0XXLNK CATOmbSessionApplicativeUndoStepHandler: public CATOmbSpecialStepHandler{
public:
  /** 
  * CATOmbSessionApplicativeUndoStepHandler enables caller to invalidate undo log until next transaction.
  * Instanciates this service.
  * <br><b>Role</b>: This constructor instanciates this services. It must not be instanciated by a new.
  * @param iDebugInfos [in] : useful informations for debug
  */
  CATOmbSessionApplicativeUndoStepHandler(const char* iDebugInfos);
  /**
  * Start...
  */
  HRESULT Begin();
  /* 
  * Stop...
  */
  HRESULT End();
  ~CATOmbSessionApplicativeUndoStepHandler();
};
#endif

#endif


