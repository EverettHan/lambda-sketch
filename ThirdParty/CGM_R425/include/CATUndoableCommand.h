#ifndef CATUndoableCommand_H
#define CATUndoableCommand_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2007
// public DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATCommand.h"

class CATString;
class CATNotification;
class CATCommandGlobalUndo;

/**
 * Class representing an undoable command.
 * <b>Role</b>: An undoable command adds an item in the Undo stack when it is activated,
 * replaced by a new global one when it ends in order to enable the user to reverse what
 * has been done during the command.
 * <p>IMPORTANT NOTICE :</p>
 * <p>To activate your command either in exclusive, shared or undefined mode,
 * you must respectively call one of the following methods immediately after its creation:
 * <ul>
 * <li><tt>RequestStatusChange(CATCommandMsgRequestExclusiveMode);</tt></li>
 * <li><tt>RequestStatusChange(CATCommandMsgRequestSharedMode);</tt></li>
 * <li><tt>Activate(NULL,NULL);</tt></li>
 * </ul></p>
 * <p>To end your command, you must call <tt>RequestDelayedDestruction();</tt>
 * <br>note: the command cannot end before it has been activated. So @href #RequestDelayedDestruction
 * cannot be called immediately after the (asynchronous) RequestStatusChange call
 * if the command is exclusive or shared. Then you must call it at the end of the overriden
 * @href #Activate method if the command is expected to end without any user interaction.
 * <p>To localize your command, you must create a NLS file whose name is the command identifier.
 * For example if you create an instance with <tt>"MyCommand"</tt> as identifier,
 * you must create a <tt>MyCommand.CATNls</tt> file including the <tt>UndoTitle</tt> key definition.
 * (for example : <tt>UndoTitle="Object Analysis"</tt>;)
 * If for any reason you want to use another file or another key you must use the
 * @href #SetResourceID method to set them.
 * </p>
 */
class ExportedByCATDialogEngine CATUndoableCommand : public CATCommand
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Constructs an undoable command.
  * @param iId
  *   The command identifier. It is used to identify both the resource file and the Undo title.
  */
  CATUndoableCommand (const CATString &iId);
  
  virtual ~CATUndoableCommand ();

  /**
  * Requests the command delayed destruction.
  * <br><b>Role</b>: The command will be destroyed as soon as this will be possible.
  */
  virtual void RequestDelayedDestruction();
  
  /**
  * Activates a command.
  * <br><b>Role</b>: Gives the focus to the command.
  * <br>If you override this method, the CATUndoableCommand::Activate method must be called
  * at the beginning of your own method.
  * @param iFromClient
  *   The command that requests to activate the current one
  * @param iNotification
  *   The associated notification
  * @return The command status.
  */
  virtual CATStatusChangeRC Activate (CATCommand * iFromClient,
                                      CATNotification * iNotification);

  /**
  * Deactivates a command.
  * <br><b>Role</b>: Called by the command selector to temporarily
  * withdraw the focus from the command.
  * <br>If you override this method, the CATUndoableCommand::Desactivate method must be called
  * anywhere in your own method.
  * @param iFromClient
  *   The command that requests to deactivate the current one
  * @param iNotification
  *   The associated notification
  * @return The command status.
  */
  virtual CATStatusChangeRC Desactivate (CATCommand * iFromClient,
                                         CATNotification * iNotification);

  /**
  * Cancels a command.
  * <br><b>Role</b>: Called by the command selector to definitely
  * withdraw the focus from the command.
  * The command should then request its destruction, using the @href RequestDelayedDestruction method.
  * <br>If you override this method, the CATUndoableCommand::Cancel method must be called
  * at the end of your own method.
  * @param iFromClient
  *   The command that requests to cancel the current one
  * @param iNotification
  *   The notification sent
  * @return The command status.
  */
  virtual CATStatusChangeRC Cancel (CATCommand * iFromClient,
                                    CATNotification * iNotification);

  /**
  * Returns the command global undo.
  * <br><b>Role</b>: Enables to add actions during Undo or Redo.
  */
  virtual CATCommandGlobalUndo * GetGlobalUndo ();
  
  /**
  * Requests to undo the command when it ends.
  * <br><b>Role</b>: This method requests a global undo at the end of the command.
  */
  void ExecuteUndoAtEnd ();

  /**
  * Sets specific resource file name and key.
  * <br><b>Role</b>: Defines resource file and/or key for localization.
  * <br>If you call this method, call it before the CATUndoableCommand::Activate method is called.
  * @param iRscFileName
  *   The resource file name
  * @param iRscKey
  *   The resource key
  */
  void SetResourceID (const CATString & iRscFileName, const CATString & iRscKey);
  
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATUndoableCommand ();
  CATUndoableCommand & operator= (const CATUndoableCommand &);
  CATUndoableCommand (const CATUndoableCommand &);

  int _firstTransactionIndex;
  int _firstTransactionSet;
  int _startUndoRequestIndex;
  CATBoolean _undoAtEndRequested;
  CATBoolean _deactivated;
  CATBoolean _cancelled;
  CATBoolean _undefinedMode;
  CATString _rscFileName;
  CATString _rscKey;

};

#endif
