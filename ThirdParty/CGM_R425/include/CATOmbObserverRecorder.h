
#ifndef CATOmbObserverRecorder_H
#define CATOmbObserverRecorder_H

/**
 * @level Protected
 * @usage U5   
 */
#include "AC0XXLNK.h"
#include "CATOmeSessionRecorder.h"
#include "CATOmbUndoRedoDefs.h"
#include "CATOmbSessionUndoMementoDefs.h"

class CATOmbUndoRedoObserver;
#ifdef FULLCOMPONENTRECORDERMIGRATION
class ExportedByAC0XXLNK CATOmbObserverRecorder : public CATOmeSessionRecorder
{
public:
  #if !defined(_WINDOWS_SOURCE) || defined (__CATAssyUpdateHeaderModel) || defined (__AC0XXLNK) || defined (__CATOmbTransientServices) || defined (__PLMModelerEventImp) || defined (__TestSessionUndoSSH) || defined (__TestSessionUndoObserver)
  /**
  * Creates the service. Notice using observer is allowed only for recording of state of volatile data.
  * @param iObserver
  *		A pointer related to current working observer. 
  */
  CATOmbObserverRecorder(const CATOmbUndoRedoObserver* iObserver);
  #endif

  
  HRESULT RecordMemento(const CATOmeUndoRedoMementoFactory& iMementoFactory, CATOmeMementoId& ioMtoId);
  /**
  * Update the service regarding current state of UndoRedo Engine .   
  * @param iObserver
  *		A pointer related to current working iObserver. 
  */
  inline void UpdateInternals(const CATOmbUndoRedoObserver* iObserver){Init(iObserver);}

  virtual ~CATOmbObserverRecorder();
private:
  CATOmeSessionRecorder::ObjectState GetState();
  CATOmbObserverRecorder (const CATOmbObserverRecorder &);
  CATOmbObserverRecorder& operator=(const CATOmbObserverRecorder&);

  
  void SetRecordModeFromUndoMode(OmbUndoRedoMode iUndoMode,OmbHandlingMode hmode);

  void Init(const CATOmbUndoRedoObserver* iObserver);

  CATOmbObserverRecorder();
};
#endif

#endif
