#ifndef __CATDlgSession_h
#define __CATDlgSession_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "DI0PANV2.h"
#include "CATBooleanDef.h"

class l_CATDlgSession;

class ExportedByDI0PANV2 CATDlgSession {

public:

  /**
    *
    */
  enum CATDlgCompletionStatus {
    CATUndefined,
    CATComplete,
    CATAbort
  };

  /**
    * The session state.
    * APM means Advandced Power Management
    *
    * CATNormal:                  normal state
    * CATInQueryEndSession:       the system is about to shutdown
    * CATInEndSession:            the system shuts down
    * CATInAPMQuerySuspend:       the system requests permission to suspend
    * CATInAPMSuspend:            the system suspends
    * CATInAPMQuerySuspendFailed: one of the suspend request failed
    * CATInAPMResumeCritical:     resume after a critical suspension
    * CATInAPMResumeSuspend:      resume after normal suspension
    */
  enum CATDlgSessionState {
    CATNormal,
    CATInQueryEndSession,
    CATInEndSession,
    CATInAPMQuerySuspend,
    CATInAPMSuspend,
    CATInAPMQuerySuspendFailed,
    CATInAPMResumeCritical,
    CATInAPMResumeSuspend
  };

  /**
    * Create a new session. The session must be created
    * in the main thread.
    */
  CATDlgSession ();

  virtual ~CATDlgSession ();

  /**
    * Completes a session event treatment. That means,
    * returning to the normal state and answering to the
    * system request.
    */
  void Complete (CATDlgCompletionStatus);

  /**
    * Get the session state
    */
  CATDlgSessionState GetState () const;

  /**
    * Get the completion status
    */
  CATDlgCompletionStatus GetStatus () const;

  /**
    * Tells whether the user can be prompted during
    * session event management or not
    */
  boolean CanPromptUser () const;

  l_CATDlgSession * GetLetter ();

protected:

  l_CATDlgSession * _letter;

};

#endif//__CATDlgSession_h
