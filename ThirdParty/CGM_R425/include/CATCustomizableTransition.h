#ifndef CATCustomizableTransition_h
#define CATCustomizableTransition_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0APPLI.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialogTransition.h"

//#include "CATListOfCATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

class CATDiaAction;
class CATCommand;
class CATDialogState;
class CATStateCondition;

/**
 * Class representing a specialized transition.
 * <b>Role</b>: A specialized transition is a reusable transition which may be
 * associated with generic action and condition and on which specific action
 * and condition may be added as usual.  
 * <br>Such transitions are used to program a @href CATPanelState state which
 * is a state dedicated to manage a dialog.
 * Only these transitions linked to a @href CATPanelState are usable in
 * L1 CAA2 exposition.
 * So, as a command developer, you don't need to instantiate such transitions.
 */
class ExportedByCATDialogEngine CATCustomizableTransition : public CATDialogTransition
{
  
  /** @nodoc */
  CATDeclareClass;

public:
  
  /*---------------------------------*/
  //      INTERNAL METHODS 
  /*---------------------------------*/
  
  /** @nodoc */
  CATCustomizableTransition (CATDialogState *, CATDialogState *);
  
  /** 
  * @nodoc
  * obsolete.
  */
  CATCustomizableTransition (CATCommand *, CATDialogState *, CATDialogState *);
  virtual ~CATCustomizableTransition ();
  
  /**
  * Sets or adds a transition action.
  * <br><b>Role</b>: This action is executed when the transition fires.
  * <br>If a default action has been set by a call to <tt>SetCustomizableAction</tt>,
  * both actions will be executed when the transition fires, this action first.
  * @param iAction
  *   The action.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAction</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  * see CATDialogTransition 
  */
  virtual void SetAction (CATDiaAction *);
  /**
  * Sets the default transition action.
  * <br><b>Role</b>: This action is executed when the transition fires.
  * <br>A customizable transition can have only one default action, so successive calls to 
  * <tt>SetCustomizableAction</tt> for the same transition successively overwrite the 
  * default action.
  * @param iAction
  *   The action.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAction</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  * see CATDialogTransition 
  */
  virtual void SetCustomizableAction (CATDiaAction *);
  /** @nodoc */
  virtual CATDiaAction * GetCustomizableAction () const;
  
  /**
  * Sets or adds a transition condition.
  * <br><b>Role</b>: This condition must evaluate TRUE to make the transition
  * fire. 
  * <br>If a default condition has been set by a call to <tt>SetCustomizableCondition</tt>,
  * both conditions will be evaluated to make the transition fire, this condition first.
  * @param iCond
  *   The condition.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  * see CATDialogTransition 
  */
  virtual void SetCondition (CATStateCondition *);
  /**
  * Sets the default transition condition.
  * <br><b>Role</b>: This condition must evaluate TRUE to make the transition
  * fire. 
  * <br>A customizable transition can have only one default condition, so successive calls to 
  * <tt>SetCustomizableCondition</tt> for the same transition successively overwrite the 
  * default condition.
  * @param iCond
  *   The condition.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  * see CATDialogTransition 
  */
  virtual void SetCustomizableCondition (CATStateCondition *);
  /** @nodoc */
  virtual CATStateCondition * GetCustomizableCondition ()const;
  
protected:
  
  CATDiaAction * _CustomizableAction; 
  CATStateCondition * _CustomizableCondition; 
  CATLISTP(CATBaseUnknown) _ReleaseL;
  
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCustomizableTransition ();
  CATCustomizableTransition (const CATCustomizableTransition &);
  CATCustomizableTransition & operator= (const CATCustomizableTransition &);

};
#endif
