#ifndef CATOmeSessionRecorder_H_
#define CATOmeSessionRecorder_H_

#include "CATOme.h"
#include "CATOmeUndoRedoDefs.h"
#include "CATOmeSessionUndoRedoTransaction.h"

class ExportedByCATOme CATOmeSessionRecorder
{            
public:
  CATOmeSessionRecorder();
  
  /**
  * Internal Use Only DO NOT USE IT!!!!
  */
  CATBoolean IsDirtyActive();
  /**
  * Check whether SessionUndo log is able to record mementos for UndoRedo. 
  * @return
  *   A boolean value:
  *   <br><b>Legal values</b>:
  *   <code>TRUE</code>, if it is enabled,<code>FALSE</code> otherwise.
  */
  virtual CATBoolean CanRecord();

  /**
  * Record  Memento in SessionUndo log and/or WarmStart log. 
  * Memento is built from factory.
  * Factory must inherit from CATOmbUndoRedoMementoFactory and must implement the Memento creation.
  * Memento must inherit CATOmbUndoRedoMemento.
  * When memento is recorded, UndoRedo Engine does not AddRef it because lifecycle of memento is linked to lifecyle of transaction owning it.
  * @param iMementoFactory
  *		Factory of memento you want to record. 
  * @param oMtoId
  *		identifier of Memento which was created and recorded. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, record in UndoRedo log has been performed.
  *   <code>S_FALSE</code>, no record in UndoRedo log only Dirty Status has been computed.
  *   <code>E_ACCESSDENIED</code>, SessionUndo log access is denied to record memento.
  *   <code>E_OUTOFMEMORY</code>, Not enough memory to create Memento from factory.
  *   <code>E_NOTIMPL</code>, MementoFactory didn't define how to create memento.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  */
  HRESULT RecordMemento(const CATOmeUndoRedoMementoFactory& iMementoFactory, CATOmeMementoId& ioMtoId, CATOmeUndoRedoMemento*& oMemento);


  CATOmbSessionUndoRedoTransaction* GetCurrentTransaction(OmbRecorderType iRecorderType, OmeUndoRedoMode& oUndoMode, OmeHandlingMode& oHandlingMode);

  virtual ~CATOmeSessionRecorder();
private:
  CATOmeSessionRecorder (const CATOmeSessionRecorder &);
  CATOmeSessionRecorder& operator=(const CATOmeSessionRecorder&);
  
protected:
  enum ObjectState{Invalid,Valid};
  virtual ObjectState GetState()=0;
  enum OmbRecordMode{INVALIDRECORDCONTEXT,NEVERRECORD,DISABLEDFORLOGREPLAY,DISABLEDFORLIFECYCLE,NONEDISABLEDBYSTEPHANDLER,ALLDISABLEDBYSTEPHANDLER,MODELDISABLEDBYSTEPHANDLER,UNDOREDODISABLEDBYSTEPHANDLER,BASICUNDORECORD,FIXUNDORECORD,MODELRECORD,TRANSACTIONZERORECORD};
  OmbRecordMode m_recordmode;
  OmbRecorderType m_recordtype;
  CATBaseUnknown_var m_holder;
  char const * TraceDebugMode(OmbRecordMode iMode);
  OmbRecordMode OmbHandlingModeToOmbRecordMode(OmeHandlingMode iHM);
  void SetRecordMode(OmeUndoRedoMode iUndoMode,OmeHandlingMode hmode);
  CATOmbSessionUndoRedoTransaction* m_CurrentTransaction;

};


#endif
