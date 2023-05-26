#ifndef CATDiaError_H
#define CATDiaError_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATError.h"

/** 
 * @nodoc
 */
enum CATDiaErrorType { ActionExecuteError, ActionUndoError ,ActionResetError, NoError };

/**
 * Class representing an error catched in a CATStateCommand command.
 * <b>Role</b>: If an exception is catched by DialogEngine during an action
 * or a condition, a <tt>CATDiaError</tt> instance stores a pointer to
 * the catched error.
 * By default, a dialog displays the error.
 * But, as a command developer, you may define a specific command to manage
 * the error thanks to the @href CATStateCommand#SetErrorCommand. 
 * This command can retrieve the error by the @href CATStateCommand#GetError
 * method which returns the <tt>CATDiaError</tt> instance.
 * <br>
 * However this way of managing errors is not recommended. Errors should be
 * processed in the conditions and actions and shouldn't reach the 
 * command level.
 */
class ExportedByCATDialogEngine CATDiaError
{
  
public:
  
  /** @nodoc */
  CATDiaError ();
  /** @nodoc */
  virtual ~CATDiaError ();
  
  /** @nodoc */
  CATDiaErrorType _errorType;
  
  /**
  * Error caught by DialogEngine.
  */
  CATError * _error;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDiaError (const CATDiaError &);
  CATDiaError & operator= (const CATDiaError &);
  
};

#endif
