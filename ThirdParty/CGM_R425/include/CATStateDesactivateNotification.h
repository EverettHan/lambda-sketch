#ifndef CATStateDesactivateNotification_h
#define CATStateDesactivateNotification_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0GRAF.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATNotification.h"

/**
 * Class representing a notification whose instance is received when a state 
 * command is deactivated.
 * <b>Role</b>: As a command developer, you don't need to create an instance
 * of this class.
 * @see CATStateCommand
 */

class ExportedByCATDialogEngine CATStateDesactivateNotification : public CATNotification
{

  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /** @nodoc */
  CATStateDesactivateNotification ();
  
  virtual ~CATStateDesactivateNotification (); 

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStateDesactivateNotification (const CATStateDesactivateNotification &);
  CATStateDesactivateNotification & operator= (const CATStateDesactivateNotification &);
  
};

#endif
