#include "CATUndoSpecialStepHandler.h"
#include "CATUnicodeString.h"

//#define FULL_UNDO_OPEN

class ExportedByCATOme CATOpenUndoManager : CATOmeSpecialStepHandler
{

public :
  CATOpenUndoManager(CATUnicodeString iSshId, CATBoolean isDirtyEnable=TRUE);
  ~CATOpenUndoManager();

  HRESULT StartOpenManagement();
  HRESULT StopOpenManagement();

  CATUnicodeString GetId() { return _sshID; }

private :
  CATUnicodeString _sshID;


};
