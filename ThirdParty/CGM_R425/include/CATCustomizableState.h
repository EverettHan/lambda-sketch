#ifndef CATCustomizableState_H
#define CATCustomizableState_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0APPLI.m

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDialogState.h"

//#include "CATListOfCATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

class CATDiaAction;
class CATStateCondition;
class CATString;

class CATDlgDialog;

/**
* Class base to create user state.
* @see CATPanelState
*/
class ExportedByCATDialogEngine CATCustomizableState : public CATDialogState
{

  /** @nodoc */
  CATDeclareClass;
  
public:

  /** @nodoc */
  CATCustomizableState (const CATString & RsrId);
  virtual ~CATCustomizableState ();
  
  //------------------------------------------------------------------- 
  //   Management of Actions
  //-------------------------------------------------------------------
  /** @nodoc */
  virtual void SetLeaveAction (CATDiaAction * Action);
  /** @nodoc */
  virtual void SetEnterAction (CATDiaAction * Action);
  /** @nodoc */
  virtual void SetCustomizableLeaveAction (CATDiaAction * Action);
  /** @nodoc */
  virtual CATDiaAction * GetCustomizableLeaveAction () const;
  /** @nodoc */
  virtual void SetCustomizableEnterAction (CATDiaAction * Action);
  /** @nodoc */
  virtual CATDiaAction * GetCustomizableEnterAction () const;
  
  //------------------------------------------------------------------- 
  //   Management of Conditions
  //-------------------------------------------------------------------
  /** @nodoc */
  virtual void SetLeaveCondition (CATStateCondition * Condition);
  /** @nodoc */
  virtual void SetCustomizableLeaveCondition (CATStateCondition * Condition);
  /** @nodoc */
  virtual CATStateCondition * GetCustomizableLeaveCondition () const;
  
protected:

  /** @nodoc */
  CATDiaAction      * _CustomizableLeaveAction;
  /** @nodoc */
  CATDiaAction      * _CustomizableEnterAction;
  /** @nodoc */
  CATStateCondition * _CustomizableLeaveCondition;
  /** @nodoc */
  CATLISTP(CATBaseUnknown) _ReleaseL;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCustomizableState ();
  CATCustomizableState (const CATCustomizableState &);
  CATCustomizableState & operator= (const CATCustomizableState &);

};

#endif 
