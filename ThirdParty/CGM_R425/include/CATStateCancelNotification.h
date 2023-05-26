#ifndef CATStateCancelNotification_h
#define CATStateCancelNotification_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0GRAF.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATNotification.h"

/**
 * Class representing a notification whose instance is received when a 
 * state command is cancelled.
 * <b>Role</b>: As a command developer you don't need to create an instance 
 * of this class.
 * @see CATStateCommand
 */

class ExportedByCATDialogEngine CATStateCancelNotification : public CATNotification
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Cancel notification type.
  * @param End
  *   The command completes normally because it has reached the NULL state.
  * @param Interrupt
  *   The command ends because it is cancelled by an exclusive command.
  * @param Undo
  *   The command ends because its activation is undone.
  */
  enum CancelType { End, Interrupt, Undo };
  
  /** @nodoc */
  CATStateCancelNotification (CancelType=End);
  
  virtual ~CATStateCancelNotification ();
  
  /**
  * Returns the type of the activate notification.
  * <br><b>Role</b>: It is useful to know whether the command completes 
  * normally or is interrupted by an exclusive command.
  * @return
  *   The type.
  */
  CancelType GetType ();
  
private:
  
  CancelType _type;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStateCancelNotification (const CATStateCancelNotification &);
  CATStateCancelNotification & operator= (const CATStateCancelNotification &);
  
};

#endif
