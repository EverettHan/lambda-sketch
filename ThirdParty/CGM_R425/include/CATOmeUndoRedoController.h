
#ifndef CATOmeUndoRedoController_H
#define CATOmeUndoRedoController_H

#include "CATOme.h"
#include "CATOmxSharable.h"
#include "CATBaseUnknown.h"
#include "CATOmeUndoRedoDefs.h"
#include "CATOmxSR.h"

class ExportedByCATOme CATOmbUndoRedoController:public CATOmxSharable
{  
public : 
  CATOmbUndoRedoController();
  virtual ~CATOmbUndoRedoController();
  /** Perform a predefined action(CATOmbUndoRedoAction) 
  * returns: 
  *   S_OK: Action has been performed successfully
  *   E_FAIL: Action could not be performed successfully
  */
  virtual HRESULT PerformAction(CATOmbUndoRedoAction& iAction)=0;
  /** 
  * Provides subscriber of Model_UndoRedoEngine associated to controller
  */
  virtual CATBaseUnknown& GetAssociatedSubscriber()=0;
};

ExportedByCATOme void SetStaticController(CATOmbUndoRedoController* iController);

ExportedByCATOme CATOmbUndoRedoController* GetStaticController();

#endif
