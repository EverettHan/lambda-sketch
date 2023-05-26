#ifndef CATICmdSwitchAgent_H
#define CATICmdSwitchAgent_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2000
// protected CATCmdDialogAgents.m

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// System Framework
#include "IUnknown.h"

#include "CATBoolean.h"  
#include "CATString.h"

// Global Unique IDentifier defined in .cpp 
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATICmdSwitchAgent;
#else
extern "C" const IID IID_CATICmdSwitchAgent;
#endif

/**
 * Interface to define an acquisition agent visualizable in a toolbar.
 * <b>Role:</b> Interface implemented by @href CATCmdSwitchAgent. This interface allows you
 * to add switches to the agent.
 */
class ExportedByCATDialogEngine CATICmdSwitchAgent : public IUnknown
{
  
public:

  /**
  * Adds a switch to a switch agent. 
  * <br><b>Role</b>: The first switch is the default active switch if 
  * <tt>iNoActive</tt> is <tt>FALSE</tt>.
  * <br>
  * <br>In the <tt>.CATNls</tt> or <tt>.CATRsc</tt> files dedicated to your 
  * state command you can define Nls and icons resources: 
  * <pre> 
  *      (xxxxx).iAgentResId.iSwitchResID.yyyy = "....";
  * </pre>
  * <ul>
  * <li>xxxxx: First parameter of the @href CmdDeclareResource macro or first and second 
  * parameters of the @href CmdDeclareResourceFile macro </li>
  * <li>iAgentResID : Second parameter of the @href CATCmdSwitchAgent#CATCmdSwitchAgent </li> 
  * <li>iSwitchResID : First parameter of this method  </li> 
  * <li>yyy          </li>
  * <ul>
  * <li>In the <tt>CATRsc</tt> file:</li>
  * <ul>
  * <li>Icon: P1 bitmap </li>
  * </ul>
  * <li>In the <tt>CATNls</tt> file:</li>
  * <ul>
  * <li>Title : When there is no icon</li>
  * <li>ShortHelp: Text that appears, in balloons, in the toolbar when the mouse moves over the icon</li>
  * <li>Help: Text that appears in the status bar</li>
  * <li>LongHelp: Text that appears in balloon when you select the help icon</li>
  * </ul>
  * </ul>
  * </ul>
  * @param iSwithResID
  *   Nls identificator of the switch.
  * @param iNoActive
  *  <b>Legal values</b>:
  *  <br><tt>FALSE</tt> :The first switch is the active switch. 
  *  <br><tt>TRUE</tt>  :Any switch is activated, call the @href #SetActiveSwitch method 
  * @param oIdxSwitch
  *  Index of the created switch
  * @return 
  *  S_OK 
  */
  virtual HRESULT AddSwitch (const CATString & iSwitchResID, 
                             CATBoolean iNoActive,
                             int & oIdxSwitch) = 0;

  /**
  * Returns the index of the active switch.
  * @param oIndex
  *   The index of the active switch. 
  *   <br><b>Legal values</b>:zero the switch is inactiv, else the switch is activ.
  * @return 
  * <dl>
  * <dt> <tt>S_OK</tt>     <dd> There is an active switch
  * <dt> <tt>S_FALSE</tt>  <dd> No switch is active
  * </dl>   
  */
  virtual HRESULT GetActiveSwitch (int & oIndex) = 0;

  /**
  * Activates a switch without triggering a transition.
  * @param iIndex
  *   The index of the switch to activate.
  * @return oResult  
  * <dl>
  * <dt> <tt>S_OK</tt>     <dd> The switch is successfully activated.
  * <dt> <tt>S_FALSE</tt>  <dd> The switch is locked.
  * <dt> <tt>E_FAIL</tt>   <dd> Cookie invalide.
  * </dl>
  */
  virtual HRESULT SetActiveSwitch (int iIndex) = 0;

  /**
  * Deactivates the active switch.
  */
  virtual HRESULT UnsetActiveSwitch () = 0;

  /**
  * Locks a switch.
  * @param iIndex
  *   The index of the switch is to lock, it cannot be more actived. 
  * @return 
  * <dl>
  * <dt> <tt>S_OK</tt>      <dd> The index is valid and the corresponding switch is not yet locked
  * <dt> <tt>E_FAIL</tt>    <dd> The index is invalid or the corresponding switch is yet locked
  * </dl>
  */
  virtual HRESULT LockSwitch (int iIndex) = 0;


  /**
  * Unlocks a switch.
  * @param iIdx
  *    Position of the switch to unlock.
  * @return 
  * <dl>
  * <dt> <tt>S_OK</tt>      <dd> iIdx is valid and locked
  * <dt> <tt>E_FAIL</tt>    <dd> iIdx is invalid or switch yet unlocked
  * </dl>
  */
  virtual HRESULT UnlockSwitch (int iIdx) = 0;

};

#endif

