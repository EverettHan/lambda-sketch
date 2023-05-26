/* -*-c++-*- */
#ifndef CATOmbSessionUndoErrorManagement_H
#define CATOmbSessionUndoErrorManagement_H
/// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//  December 2006  Creation: RJS
//===================================================================

/**
* @level Private
* @usage U3
*/

#include "CATError.h"
#include "AD0XXBAS.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATOmbUndoRedoDefs.h"

#define OmbSessionUndoDebugId unsigned int
class CATOmbSessionFilterForSaveTransaction;
//DEV en cours
//struct CATOmbErrContext {
//  const char*m_errortitle;
//  const char*m_file;
//  const unsigned int m_lineno;
//  const OmbSessionUndoErrorKind m_kind;
//  inline CATOmbErrContext(const char*iErrorTitle,const char*iFile,unsigned int iLineno,const char*iKind) : m_errortitle(iErrorTitle), m_file(iFile), m_lineno(iLineno),m_kind(iKind){}
// 
//};
/**
* <b>Role</b> SessionUndoErrorManager is list of Transaction Id  for CATOmbUndoRedoObserver operations
* NOTICE : CATOmbSessionUndoTransactionIdVector start from ZERO
*/

#include "CATOmeSessionUndoErrorManager.h"
class ExportedByAD0XXBAS SessionUndoErrorManager : OmeSessionUndoErrorManager
{
public:
  /**
  * RaiseError
  */
  int RaiseError(OmbSessionUndoErrorKind iKind,unsigned int iErrorCode,char* mess=0);
  /**
  * RaiseWarning
  */
  int RaiseWarning(OmbSessionUndoErrorKind iKind,unsigned int iErrorCode,char* mess=0);

  
  SessionUndoErrorManager();

  //En cours de DEV
  /**
  * StartTrackingSpecialStep
  */
  CATBoolean StartTrackingSpecialStep(OmbSpecialStepType iSpecialStep);
  /**
  * UnmanageSpecialStep
  */
  CATBoolean StopTrackingSpecialStep(OmbSpecialStepType iSpecialStep);
  /**
  * ManageSpecialStep
  */
  CATBoolean ManageSpecialStep(OmbSpecialStepType iSpecialStep);

/**
* LogSessionUndoMCStack
*/
  SessionUndoErrorManager& LogSessionUndoMCStack(OmbSessionUndoDebugId iErrorCode,const char* iParm1,const char* iParm2=0,const char* iParm3=0);
  SessionUndoErrorManager& MCStack_Open(OmbSessionUndoDebugId iErrorCode,const char* iParm1,const char* iParm2=0,const char* iParm3=0);
  SessionUndoErrorManager& MCStack_Save(OmbSessionUndoDebugId iErrorCode,const char* iParm1,const char* iParm2=0,const char* iParm3=0);
  SessionUndoErrorManager& MCStack_LocalSave(OmbSessionUndoDebugId iErrorCode,const char* iParm1,const char* iParm2=0,const char* iParm3=0);
  SessionUndoErrorManager& MCStack_Refresh(OmbSessionUndoDebugId iErrorCode,const char* iParm1,const char* iParm2=0,const char* iParm3=0);
  SessionUndoErrorManager& MCStack_DirtyStorage(OmbSessionUndoDebugId iErrorCode,const char* iParm1,const char* iParm2=0,const char* iParm3=0);
  SessionUndoErrorManager& CheckFilter(CATBaseUnknown* iFilter);

  /**
  * end
  */
  void end();
  HRESULT AddFilterOnError(CATOmbSessionFilterForSaveTransaction& iFilter);
  HRESULT RemoveFilterOnError(CATOmbSessionFilterForSaveTransaction& iFilter);
  void ClearFiltersOnError();

private:
  unsigned int m_trackedsteps;
  CATBoolean m_done;
  CATBoolean m_filtered;
  CATLISTV(CATBaseUnknown_var) m_filteringkeys;
};

/**
* Get SessionUndoErrorManager
*/
ExportedByAD0XXBAS SessionUndoErrorManager& UndoErrorManager();



#define OMBDEB_UNDEFINEDDEBUG      0
#define OMBDEB_BADRECORDERINIT1    1//tos
#define OMBDEB_BADRECORDERINIT2    2//obs
#define OMBDEB_BADRECORDERINIT3    3//cont
#define OMBDEB_DENIEDRECORD1       4
#define OMBDEB_DENIEDRECORD2       5
#define OMBDEB_DENIEDRECORD3       6
#define OMBDEB_SERVERTRANSACTION   7
#define OMBDEB_HOLDDIRTY           8
#define OMBDEB_LSSPECIALSTEP       9
#define OMBDEB_DENIEDDIRTY1       10
#define OMBDEB_DENIEDDIRTY2       11
#define OMBDEB_DENIEDDIRTY3       12
#define OMBDEB_PURGELOGONSAVEorLS 13
#endif
