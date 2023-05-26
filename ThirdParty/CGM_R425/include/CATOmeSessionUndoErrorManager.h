
#ifndef __CATOmeSessionUndoErrorManager_h__
#define __CATOmeSessionUndoErrorManager_h__

// ObjectModelerEngines
#include "CATOme.h"

enum OmbSessionUndoDebugTool { OMB_ALLUNDOEVENT = 0, OMB_TRANSACTIONEVENT, OMB_RECORDEVENT, OMB_LIFECYCLEENTITIES1, OMB_MEMENTOSEVENT, OMB_ODTMODE, OMB_ODTMCMODE, OMB_WARNINGMODE };
enum OmbSessionUndoErrorKind { OMB_UNDEFUNDOERROR = 1, OMB_DEPRECATED, OMB_BADMIGRATION, OMB_RECORDERROR, OMB_MEMENTOSERROR, OMB_TRANSACTIONERROR, OMB_OBSERVERERROR };

class ExportedByCATOme OmeSessionUndoErrorManager
{
public:

  /**
   * RaiseError
   */
  int RaiseError(OmbSessionUndoErrorKind iKind, unsigned int iErrorCode, char const * mess = nullptr);

  /**
   * RaiseWarning
   */
  int RaiseWarning(OmbSessionUndoErrorKind iKind, unsigned int iErrorCode, char const * mess = nullptr);

protected:
  unsigned int m_debuginfos;
};

ExportedByCATOme OmeSessionUndoErrorManager & OmeUndoErrorManager();

#define CATOmbUndoRedoCondition(Expr,iKind,iErrorCode) ((int)((Expr) ? 1 : OmeUndoErrorManager().RaiseError(iKind, iErrorCode,#Expr)))

#define CATOmbUndoRedoUnexpected(Expr,iKind,iErrorCode) (!CATOmbUndoRedoCondition(!(Expr), iKind,iErrorCode))


#endif
