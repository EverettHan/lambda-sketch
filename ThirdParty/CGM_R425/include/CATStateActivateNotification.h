#ifndef CATStateActivateNotification_h
#define CATStateActivateNotification_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999-2008
// public DI0GRAF.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATNotification.h"

#include "CATBoolean.h"

/**
 * Class representing a notification whose instance is received when a state 
 * command is activated.
 * <b>Role</b>: As a command developer you don't need to create an instance
 * of this class.
 * @see CATStateCommand
 */

class ExportedByCATDialogEngine CATStateActivateNotification : public CATNotification
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Activate notification type.
  * @param Begin
  *   The command starts from the beggining.
  * @param Resume
  *   The command restarts at the state which was the current one when a shared 
  *   command took the focus from it.
  * @param ResumeThenLocalUndo
  *   The command restarts at the state which was the current one when a shared 
  *   command took the focus from it, but this shared reached the Cancel State.
  */
  enum ActivateType { Begin, Resume, ResumeThenLocalUndo };
  
  /** @nodoc */
  CATStateActivateNotification (ActivateType=Begin);
  
  virtual ~CATStateActivateNotification ();
  
  
  /**
  * Returns the type of the activate notification.
  * <br><b>Role</b>: It is useful to know whether the command begins or 
  * resumes after a deactivation.
  * If the type is ResumeThenLocalUndo, the returned type is Resume.
  * @return
  *   The type, which is Begin or Resume, not ResumeThenLocalUndo.
  */
  CATStateActivateNotification::ActivateType GetType ();

  /**
  * Returns whether the shared command reached the Cancel state.
  * <br><b>Role</b>: When the command resumes after a deactivation, it is useful to
  * know whether the shared command having involved the deactivation reached the Cancel state.
  * @return
  *   The type.
  */
  CATBoolean ResumedAfterSharedKO ();
  
private:
  
  ActivateType _type;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStateActivateNotification (const CATStateActivateNotification &);
  CATStateActivateNotification & operator= (const CATStateActivateNotification &);
  
};

#endif

