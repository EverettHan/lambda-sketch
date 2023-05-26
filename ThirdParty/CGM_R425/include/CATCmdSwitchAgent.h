#ifndef CATCmdSwitchAgent_h
#define CATCmdSwitchAgent_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected CATCmdDialogAgents.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialogAgent.h"

#include "CATDlgEngUtility.h"
#include "CATCommand.h"

class CATString;

/**
 * Class which defines an acquisition agent visualizable in a toolbar.
 * <b>Role:</b> This agent is displayed in a toolbar. Each valuation (switch) is represented by
 * an icon. The count of switch represents the count of possible value for the agent.
 * <br>Use the @href CATICmdSwitchAgent interface to handle it.
 * <br>To see the agent in the toolbar:
 * <ul>
 * <li> Create a CATStateCommand with this agent</li>
 * <li> Add this agent to the SDO in using i
 *      the @href CATStateCommand#AddSDOElement(CATBaseUnknown*) method</li>
 * </ul>
 * <br>In a toolbar you must have a starter with a @href CATCommandHeaderWithSDOForAgent 
 * command header. In the constructor of this header you have set the IID of 
 * the @href CATIAfrDialogForAgent interface. <tt>CATCmdSwitchAgent</tt> implements this interface.
 */
class ExportedByCATDialogEngine CATCmdSwitchAgent : public CATDialogAgent
{

  /** @nodoc */
  CATDeclareClass;

public:

  /**
  * Constructs the dialog agent. 
  * @param iName
  *   The name of the command
  * @param iAgentResID
  *   The resource identificator of the agent. Refer to the @href CATICmdSwitchAgent#AddSwitch 
  *   method to get explanations about this parameter.
  * @param iBehavior
  *  See @href CATDialogAgent#CATDialogAgent.
  * @param iStatus
  *   See @href CATCommand.
  */
  CATCmdSwitchAgent (const CATString & iName,
                     const CATString & iAgentResID,
                     CATDlgEngBehavior iBehavior=NULL, 
                     CATCommandMode iStatus=CATCommandModeUndefined);

protected:

  virtual ~CATCmdSwitchAgent (void);

  /**
   * @href CATDialogAgent methods to override to customize the Undo behavior
   */
  /** @nodoc */
  void UndoCommand (void);
  /** @nodoc */
  void RedoCommand (void);
  /** @nodoc */
  void Reset (void);

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCmdSwitchAgent ();
  CATCmdSwitchAgent (const CATCmdSwitchAgent &);
  CATCmdSwitchAgent & operator= (const CATCmdSwitchAgent &);

};

#endif
