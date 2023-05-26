
#ifndef CATOmbComponentRecorder_H
#define CATOmbComponentRecorder_H

/**
 * @level Protected
 * @usage U5   
 */
#include "AC0XXLNK.h"
#include "CATOmeSessionRecorder.h"
#include "CATComponentId.h"

class CATIPLMComponent;

#ifdef FULLCOMPONENTRECORDERMIGRATION

class ExportedByAC0XXLNK CATOmbComponentRecorder : public CATOmeSessionRecorder
{
public:
  /**
  * Creates the service.   
  */
  CATOmbComponentRecorder(CATComponentId& iComp);
  CATOmbComponentRecorder(CATIPLMComponent* iComp);

  HRESULT RecordMemento(const CATOmeUndoRedoMementoFactory& iMementoFactory, CATOmeMementoId& ioMtoId);

  HRESULT RecordMemento(const CATOmeUndoRedoMementoFactory& iMementoFactory, CATOmeMementoId& ioMtoId, CATOmeUndoRedoMemento*& oMemento);

  virtual ~CATOmbComponentRecorder();
protected:
  CATOmeSessionRecorder::ObjectState GetState();
private:
  HRESULT Init(CATComponentId& iComp);
  CATOmeSessionRecorder::ObjectState m_state;
  
  CATOmbComponentRecorder(){};
};
#endif

#endif
