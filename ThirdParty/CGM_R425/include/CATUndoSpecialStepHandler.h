/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2010  
//-----------------------------------------------------------------------------
// class CATOmeSpecialStepHandler:
//
//===================================================================
//  July 2010  Creation: KRV
//===================================================================
#ifndef CATUndoSpecialStepHandler_H_
#define CATUndoSpecialStepHandler_H_

/**
* @level Private
* @usage U6
*/
// System
#include "CATBaseUnknown.h"
// ObjectModelerCollection
#include "CATOmxSR.h"
// SystemTS
#include "CATBoolean.h"
// ObjectModelerEngines
#include "CATITempModelUndoRedoManager.h"
#include "CATOme.h"
#include "CATOmeUndoRedoDefs.h"
#include "CATUpd.h"
class CATBaseUnknown;

#define FIXSTEPHANDLER

/**
* CATOmbSpecialStepHandler enable caller to declare that log have to stop logging (Undo/Redo, DirtyManagement) during special steps : such as Open, Save, LocalSave.
* Notice : using this to disable Undo/Redo will force to purge whole Undo/Redo log recorder before the step.
*/
class ExportedByCATOme CATOmeSpecialStepHandler {
protected:
  /*  0x80 : isHandling
      0x40 : isReversible
      else : ?
  */
  unsigned char m_mask;
  static CATULONG32 m_occ;
  CATULONG32 m_id;
  OmbSpecialStepType m_stype;
  CATBoolean isRevers;
  OmeHandlingMode m_previousHM;
  OmeHandlingMode m_HM;
  CATOmeSpecialStepHandler* m_previousSH;
  CATOmxSR<CATOmbUndoRedoAction> m_PreAction;
  CATOmxSR<CATOmbUndoRedoAction> m_PostAction;
  CATOmxSR<CATITempModelUndoRedoManager> m_urManager;

  OmeHandlingMode FindModeToRestore(OmeHandlingMode iSSHMode, OmeHandlingMode iPreviousMode);
  CATOmxSR<CATITempModelUndoRedoManager> GetManager();
public:

  CATOmeSpecialStepHandler(CATBoolean iIsReversible);
  virtual ~CATOmeSpecialStepHandler();

  /**
  * Start...
  */
  virtual HRESULT StartHandling();
  HRESULT StartHandling(CATOmxSR<CATOmbUndoRedoAction> iPreAction);
  /*
  * Stop...
  */
  virtual HRESULT StopHandling();
  HRESULT StopHandling(CATBoolean iEndSpecialOpenStep);
  HRESULT StopHandling(CATOmxSR<CATOmbUndoRedoAction> iPostAction);

  HRESULT PerformPurgeUndoRedoLog();
  /**
  * Returns the special step type
  */
  OmbSpecialStepType GetSpecialStepType();/**
  * Adds an Action which will be executed in StartHandling
  * @param iAction [in]
  */
  void AddPreAction(CATOmbUndoRedoAction* iAction) { m_PreAction = iAction; }
  /**
  * Adds an Action which will be executed in StopHandling
  * @param iAction [in]
  */
  void AddPostAction(CATOmbUndoRedoAction* iAction) { m_PostAction = iAction; }

private:
  CATOmeSpecialStepHandler();
  CATOmeSpecialStepHandler(const CATOmeSpecialStepHandler&);
  CATOmeSpecialStepHandler operator=(CATOmeSpecialStepHandler&);
};


#endif
