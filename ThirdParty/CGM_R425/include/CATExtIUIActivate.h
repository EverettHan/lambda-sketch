#ifndef CATExtIUIActivate_H_
#define CATExtIUIActivate_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATBaseUnknown.h"

#include "CATString.h"
#include "CATBoolean.h"
#include "CATAfrFoundation.h"
#include "CATPathElement.h"
#include "CATCollec.h"
#include "CATEventSubscriber.h"
#include "CATEventSubscriberTypedefs.h"

class CATCmdContainer;
class CATUndoRequest;
class CATCommandGlobalUndo;
class CATDocument;
class CATIUndoTransaction;
class CATFrmDropTarget;
class CATFrmDropSource;
class CATLISTP(CATUndoRequest);


/** @nodoc
  * Tells whether the active object contained in referencePath
  * is already active in any editor but the current editor
  */
CATBoolean ExportedByCATAfrFoundation CATFrmIsAlreadyUIActive (CATPathElement & referencePath);


/**
  * Adapter class for the CATIUIActivate interface.
  *
  * To implement the interface <tt>CATIUIActivate</tt> for a class <tt>MyClass</tt>,
  * write a class <tt>MyClassExtUIActivate</tt> subclassed from 
  * <tt>CATExtIUIActivate</tt> and defined as an extension of <tt>MyClass</tt>. 
  * <tt>MyClassExtUIActivate</tt> may <b>not</b> override any methods, but
  * <b>must</b> set the protected variables <tt>_WorkshopString</tt> and 
  * <tt>_DefaultCommandString</tt> in its constructor. These strings are
  * respectively returned by the @href #GetWorkshop and @href #GetDefaultCommand
  * methods.
  * 
  * @see CATIUIActivate 
  */

class ExportedByCATAfrFoundation CATExtIUIActivate : public CATBaseUnknown
{

  CATDeclareClass;
  
public :
  
  /** @nodoc */
  CATExtIUIActivate ();
  
  /** @nodoc */
  virtual ~CATExtIUIActivate ();
  
  /**
    * Returns the name of the workshop. 
    * @see CATIUIActivate
    */
  virtual CATString & GetWorkshop ();
  
  /** 
    * Returns the name of the default command.
    * @see CATIUIActivate
    */
  virtual CATString & GetDefaultCommand ();
  
  /** 
    * @nodoc
    * Returns a contextual menu. The <tt>CATExtIUIActivate</tt> instance is 
    * responsible for destroying the returned <tt>CATCmdContainer</tt>.
    * @see CATIUIActivate, CATCmdContainer
    */
  virtual CATCmdContainer * GetContextualMenu ();
  
  /**
    * @nodoc 
    * Override it in order to add your ui-activation specific intialization 
    * code. Don't forget to call <tt>CATExtIUIActivate::UIActivate</tt>
    * from your overridden method.
    */
  virtual void UIActivate (CATPathElement &);
  
  /**
    * @nodoc
    * Override it in order to add your ui-deactivation specific destruction 
    * code. Don't forget to call <tt>CATExtIUIActivate::UIDeactivate</tt>
    * from your overridden method.
    */
  virtual void UIDeactivate ();
  
  /**
    * @nodoc
    * Tells whether the ui-activable object is currently
    * active or inactive.
    * @return
    * The activation state (0 if inactive, != 0 otherwise)
    */
  virtual int IsActive ();
  
  /** @nodoc */
  virtual CATCommandGlobalUndo * GetGlobalUndo ();
  
  /** @nodoc */
  virtual CATDocument * GetDocument ();  
  
  /** @nodoc */
  virtual void SetDocument (CATDocument * Doc);  
  
  /** @nodoc */
  virtual void SetDropSource (CATFrmDropSource * source);
  
  /** @nodoc */
  virtual CATFrmDropSource * GetDropSource ();
  
  /** @nodoc */
  virtual void SetDropTarget (CATFrmDropTarget * target);
  
  /** @nodoc */
  virtual CATFrmDropTarget * GetDropTarget ();
  
  /** @nodoc */
  virtual void ChangePathToActivate(CATPathElement * ioPathElement);
  
  
  /** @nodoc */  
  void StackUndoCB (CATCallbackEvent, void *, CATNotification * notif,
                    CATSubscriberData, CATCallback);
  
  /** @nodoc */
  void UnstackUndoCB (CATCallbackEvent, void *, CATNotification * notif,
                      CATSubscriberData, CATCallback);

  /** @nodoc */
  void ObjectEdition(CATBoolean iObjectEdition);
    
  
  /** @nodoc */
  static CATCmdContainer * GetInitialContextualMenu ();

  /** @nodoc */
  virtual HRESULT ChangeComponentState (ComponentState iFromState,
                                        ComponentState iToState,
                                        const CATSysChangeComponentStateContext * iContext);
  
protected :
  
  /** @nodoc */
  void Clean ();

  /**
  * The Name of the workshop .
  */
  CATString             _WorkshopString;

  /**
  * The Name of the first command .
  */
  CATString             _DefaultCommandString;

  /** @nodoc */
  CATUndoRequest      * _Undo;
  /** @nodoc */
  CATCmdContainer     * _ctxMenu;
  /** @nodoc */
  CATBoolean            _ObjectEdition;
  /** @nodoc */
  int                   _ObjectTransaction;
  /** @nodoc */
  CATDocument         * _document;
  /** @nodoc */
  CATIUndoTransaction * _IUndoTrans;
  /**
  * Sets whether the implementation for Undo is part of the standard model management or not. Default = TRUE.
  */
  CATBoolean            _undoModelManagement;
  /** @nodoc */
  HRESULT               _boundingBoxDrawn; // S_OK when TRUE, S_FALSE when FALSE
  /** @nodoc */
  CATFrmDropSource    * _DropSource;
  /** @nodoc */
  CATFrmDropTarget    * _DropTarget;
  /** @nodoc */
  int                   _UndoNumberBeforeUIactivate;
  /** @nodoc */
  CATLISTP(CATUndoRequest) * _UndoList;
  /** @nodoc */
  int _DeleteAllUndo;
  /** @nodoc */
  void DeleteAllUndoCB (CATCallbackEvent, void *, CATNotification * notif,
                        CATSubscriberData, CATCallback);
  
private :
  
  /**
    * @nodoc
    * Reminds whether an implementation for Undo has been added or was already registered.
    */
  CATBoolean            _undoClient;

  /**
    * @nodoc
    * For Undo/Redo management.
    */
  void                  ManageUndoRedoActivation ();
  void                  ManageUndoRedoDeactivation ();
  void               OldManageUndoRedoActivation ();
  void               OldManageUndoRedoDeactivation ();
  
};

#endif 
