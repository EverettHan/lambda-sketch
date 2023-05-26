#ifndef CATCheckHeader_H
#define CATCheckHeader_H

// Copyright Dassault Systemes 1997

//-----------------------------------------------------------------------------
// Inheritance: CATCheckHeader
//                CATCommandHeader
//-----------------------------------------------------------------------------
//
// CAA exposed using CATAfrCheckHeaderAccessor

#include "CATCommandHeader.h"
#include "CATAfrFoundation.h"

class CATCmdStarter;
class CATDialog;
class CATCmdRep;
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"

/**
* Class to create a check button command header.
* <b>Role</b>: 
*
* Simple CATCheckHeader and inherited classes like CATFrmCheckHeader can be
* displayed in new immersive views like for example Action Bar, App Mode Options,
* or Object Properties panel...
*
* To work correctly, you only need to ensure that 
*   - either your don't have overriden the following member function
*     void CATCheckHeader::SetCheck(int, int)
*   - or if you have overriden it and doesn't call the version of
*     CATCheckHeader::SetCheck in your implementation, you need to call
*     SetCmdState(CATAfrChecked) when it is checked and 
*     SetCmdState(CATAfrUnchecked) when it is unchecked to keep the view
*     synchronized with the state of the header.
*
* Then, you only need to set the correct representation type on the CATCmdStarter
* associated to your header or let the CATCmdStarter inherit the representation
* type from its parent CATCmdContainer.
*
* There is one limitation to this compatibility: the SetIconBoxAutoSelect member
* function of CATCheckHeader is not supported for immersive views. By default, 
* a fly-out will display the header icon automatically when the header
* is checked.
*/
class ExportedByCATAfrFoundation CATCheckHeader : public CATCommandHeader
{ 
  CATDeclareClass;
  // Création d'un Header de commande qui est un CheckButton => son état est conservé
  
  /**
   * The declaration of this macro implies that any derived class 
   * will benefit from this special service: the resources declaration 
   * is made in a distinctive file, which can varies according to the 
   * class derivation. 
   * @href CATDeclareHeaderSpecialResources 
   */
  CATDeclareHeaderSpecialResources;

public:

  /**
   * Constructor of a CATCheckHeader
   */
  CATCheckHeader ();
  CATCheckHeader (const CATString &, CATString iResourcesFileName="");

  /** @nodoc */
  virtual ~CATCheckHeader();
  
  /** @nodoc */
  virtual CATCommandHeader * Clone();
  
  /**
   * Override this method to do the actual job when the header changes states.
   * StartCommand must behave as a toggle and call the SetCheck method
   * for representation update. Correct implementation is :
   *
   * if (IsChecked())
   * {
   *    // write code to perform uncheck action
   *    SetCheck(0,0);
   * } 
   * else
   * {
   *    // write code to perform check action
   *    SetCheck(1,0);
   * }
   *
   * CATCheckHeader implementation of this method has no check/uncheck action, 
   * it only calls the SetCheck method.
   */
  virtual CATCommand * StartCommand();
  
  /** @nodoc */
  virtual CATCmdRep * CreateMenuRep(CATCmdStarter *, CATDialog *);

  /** @nodoc */
  virtual void DestroyMenuRep(CATCmdStarter *);

  /** @nodoc */
  virtual CATCmdRep * CreateToolbarRep(CATCmdStarter *, CATDialog *);

  /** @nodoc */
  virtual void DestroyToolbarRep(CATCmdStarter *);

  /** @nodoc */
  virtual CATCmdRep * CreateCtxMenuRep(CATCmdStarter *, CATDialog *);

  /** @nodoc */
  virtual void DestroyCtxMenuRep(CATCmdStarter *);

  /**
   * Returns true if the header is checked, otherwise returns false.
   * This is a virtual method for legacy reason.
   * Please do not override this method.
   */
  virtual int  IsChecked();

  /**
   * This is a virtual method for legacy reason.
   * Please do not override this method.
   * Do not call this method, except in the derivated StartCommand method.
   */
  virtual void SetCheck(int checked=1, int startCmd=1);

  /**
   * Override this method to perform an action when the header is checked
   * To avoid CPU loop, this action must not trigger a call to SetCheck method.
   * Do not call this method direcly, but rather call the StartCommand method
   * to check/uncheck the header.
   */
  virtual void SetChecked();

  /**
   * Override this method to perform an action when the header is unchecked
   * To avoid CPU loop, this action must not trigger a call to SetCheck method.
   * Do not call this method direcly, but rather call the StartCommand method
   * to check/uncheck the header.
   */
  virtual void SetUnChecked();

  /** 
   * @nodoc 
   * Internal use. Please do not use this method.
   */
  void SetCheckFromRep(CATBoolean Checked, CATBoolean startcmd, CATBoolean DoubleClickAction);

  /**
   * Returns TRUE if header has been checked or unchecked using a double click
   * on associated icon. 
   * Use this method in overrided SetChecked or SetUnchecked method, otherwise this
   * method returns always FALSE.
   */
  CATBoolean IsModifiedWithDoubleClick();

  /**
   * Call this method with argument equal to TRUE to give a specific behavior
   * to header when it is represented in a icon box. If this behavior is activated,
   * then the icon box will display the header icon automatically when the header
   * is checked.
   */
  void SetIconBoxAutoSelect(CATBoolean iAutoSelect);

  /**
   * Call this method in derivated header constructor if the header state does not depends on the
   * document context. Otherwise, toolbar containing this header will be destroyed and recreated 
   * each time the context is changed, that is when current document or workshop is changed.
   */
  void SetContextCanChange();

  /**
   * @nodoc
   * This method adds the Rep to the List (_repWeakRefList).
   * Internal use. Please do not use this method.
   */
  void AddRepToList(CATCmdRep * rep); 

  /**
   * @nodoc
   * This method removes the Rep to the List (_repWeakRefList).
   * Internal use. Please do not use this method.
   */
  void RemoveRepFromList(CATCmdRep * rep); 

  virtual void AcceptVisitor(AfrICommandHeaderVisitor* i_pVisitor) override;

protected:
  /**
   * @nodoc
   */
  CATCheckHeader (CATCommandHeader *);

  /**
   * @nodoc
   */
  int ResourcesRead();
  
  
private:

  /**
   * @nodoc
   */
  void ReadResources();

  CATListPV *  _repWeakRefList;

  CATBoolean _readResources;
  CATBoolean _checked;
  CATBoolean _doubleClickAction;
  CATBoolean _iconBoxAutoSelect;
  CATBoolean _contextCanChange;
  
};
#endif
