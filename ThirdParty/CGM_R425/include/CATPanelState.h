#ifndef CATPanelState_H
#define CATPanelState_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0APPLI.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATCustomizableState.h"
#include "CATIAV5Level.h"

class CATCustomizableTransition;
class CATDlgDialog;
class CATString;
class CATDialogAgent;
class CATCommand;

/**
 * Class representing a state dedicated to manage a dialog box.
 * <b>Role</b>: A dialog state is linked to agents, conditions and outgoing 
 * transitions which depend on the Ok, Cancel, Apply, Preview, Close and
 * Help buttons of the dialog.
 * More precisely, this state has the following outgoing transitions:
 * <ul>
 * <li>a Cancel transition which fires when the Cancel button is selected
 * and whose target state is the cancel state.</li>
 * <li>an Ok transition which fires when the Ok button is selected
 * and whose target state is the NULL state.</li>
 * <li>an Apply transition which fires when the Apply button is selected
 * and whose target state is the dialog state itself.</li>
 * <li>a Preview transition which fires when the Preview button is selected
 * and whose target state is the dialog state itself.</li>
 * <li>a Close transition which fires when the Close button is selected
 * and whose target state is the NULL state.</li>
 * <li>a Help transition which fires when the Help button is selected
 * and whose target state is the dialog state itself.</li>
 * </ul>
 * As a command developer, you only need to associate an action to each 
 * transition.
 * You may also add agents and outgoing transitions to this state and even
 * add a condition on the state or on the transition if a button selection is
 * not sufficient to fire a transition.
 * @see CATDialogTransition
 */
class ExportedByCATDialogEngine CATPanelState : public CATCustomizableState
{

  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Constructs a dialog state.
  * @param iCmd
  *   The command to which the state belongs.
  *   <br><b>Legal values</b>: <tt>iCmd</tt> must be a @href CATStateCommand.
  * @param iId
  *   The resource identifier used to retrieve the state prompt in the command
  *   message file.
  * @param iDialog
  *   The dialog linked to the state.
  */
  CATPanelState (CATCommand * iCmd, 
                 const CATString & iId, 
                 CATDlgDialog * iDialog);
  
  virtual ~CATPanelState ();
  
  /*---------------------------------*/
  //     TRANSITIONS 
  /*---------------------------------*/
  
  /**
  * Returns the transition linked to the Ok button.
  * @return 
  *   The transition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATCustomizableTransition * GetOkTransition () const;
  
  /**
  * Returns the transition linked to the Cancel button.
  * @return 
  *   The transition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATCustomizableTransition * GetCancelTransition () const;
  
  /**
  * Returns the transition linked to the Apply button.
  * @return 
  *   The transition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATCustomizableTransition * GetApplyTransition () const;

  /**
  * Returns the transition linked to the Preview button.
  * @return 
  *   The transition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATCustomizableTransition * GetPreviewTransition () const;
  
  /**
  * Returns the transition linked to the Close button.
  * @return 
  *   The transition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATCustomizableTransition * GetCloseTransition () const;
  
  /**
  * Returns the transition linked to the Help button.
  * @return 
  *   The transition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATCustomizableTransition * GetHelpTransition () const;

  /** @nodoc */
  void SetOkTransition (CATCustomizableTransition * trans);
  /** @nodoc */
  void SetCancelTransition (CATCustomizableTransition * trans);
  /** @nodoc */
  void SetApplyTransition (CATCustomizableTransition * trans);
  /** @nodoc */
  void SetPreviewTransition (CATCustomizableTransition * trans);
  /** @nodoc */
  void SetCloseTransition (CATCustomizableTransition * trans);
  /** @nodoc */
  void SetHelpTransition (CATCustomizableTransition * trans);
  
protected:
  
  /*------------------*/
  // internal data 
  /*------------------*/
  
  CATCustomizableTransition * _OkTransition;
  CATCustomizableTransition * _CancelTransition;
  CATCustomizableTransition * _ApplyTransition;
  CATCustomizableTransition * _PreviewTransition;
  CATCustomizableTransition * _CloseTransition;
  CATCustomizableTransition * _HelpTransition;

  CATDlgDialog   * _Panel;       

  CATDialogAgent * _OkAcq;
  CATDialogAgent * _CancelAcq;
  CATDialogAgent * _ApplyAcq;
  CATDialogAgent * _PreviewAcq;
  CATDialogAgent * _CloseAcq;
  CATDialogAgent * _HelpAcq;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATPanelState ();
  CATPanelState (const CATPanelState &);
  CATPanelState & operator= (const CATPanelState &);
  
};

#endif 
