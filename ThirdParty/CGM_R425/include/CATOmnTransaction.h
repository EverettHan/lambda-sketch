#ifndef CATOmnTransaction_H
#define CATOmnTransaction_H

#include "IUnknown.h"
#include "CATSysBoolean.h"
#include "CATOmnMain.h"
#include "CATINavigElement.h"

class CATNavigControllerPrivateData;

class ExportedByCATOmnMain CATOmnTransaction
{
public:
  // element won't be addrefed nor released by this class
  CATOmnTransaction(CATINavigElement* element);
  ~CATOmnTransaction();
  // Start optimized transaction with CATNavigController (requires OMN_FAST_EXPANDED_NODE_LOOKUP variable). Returns counter updated, -1 if fail.
  int Start();
  // End Transaction (it will be done at destructor if not done manually). Returns counter updated, -1 if fail.
  int End();

private:
  CATNavigControllerPrivateData* _controllerPrivateData;
  CATBaseUnknown_var _controllerWithAddRef;
  CATBoolean _startDone;
};

#endif
