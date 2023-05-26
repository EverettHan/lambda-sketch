#ifndef CATIUIActivate_H_
#define CATIUIActivate_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtIUIActivate
 */

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"
class CATPathElement;
class CATString;
class CATCmdContainer;
class CATCommandGlobalUndo;
class CATDocument;
class CATFrmDropSource;
class CATFrmDropTarget;

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATAfrItf IID_CATIUIActivate;
#else
extern "C" const IID IID_CATIUIActivate;
#endif

/**
  * Interface that enables the activation of a workshop when double-
  * clicking an object.
  *
  * A document contains a hierarchical structure of objects. Some 
  * of these objects are able to provide a set of commands, called 
  * a workshop. Such objects get this ability by 
  * implementing the <tt>CATIUIActivate</tt> interface, and these objects 
  * are then said to be <b>ui-activable</b>. An ui-activable object whose 
  * workshop is displayed is the <b>ui-active</b> object. UI-activation 
  * operates on @href CATPathElement objects which are paths from the 
  * document's root to an object in the document's tree structure.
  *
  * The basis of the ui-activation mechanisms lay on three actors :
  * <ul>
  * <li>- the <tt>CATIUIActivate</tt> interface implemented by 
  * ui-activable objects,</li>
  * <li>- the @href CATInPlaceSite interface implemented by site 
  * objects,</li>
  * <li>- the @href CATFrmEditor class that manages the current ui-active 
  * object.</li>
  * </ul>
  * 
  * The role of the ui-activable object is to provide a workshop, a 
  * contextual menu and a default command upon activation.
  *
  * <br><b>Note :</b>
  * Using a subclass of @href CATExtIUIActivate is mandatory when 
  * implementing the <tt>CATIUIActivate</tt> interface.
  * <p><b>BOA information</b>: this interface CANNOT be implemented
  * using the BOA (Basic Object Adapter).
  * To know more about the BOA, refer to the CAA Encyclopedia home page.
  * Click Middleware at the bottom left, then click the Object Modeler tab page.
  * Several articles deal with the BOA.</p>
  */
class ExportedByCATAfrItf CATIUIActivate: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /** @nodoc */
  virtual void  UIActivate (CATPathElement & path) = 0;

  /** @nodoc */
  virtual void  UIDeactivate () = 0;
  
  /**
    * Returns the name of the workshop associated with this ui-activable
    * object.
    * @return
    *  The ui-activable object's workshop name. 
    */
  virtual CATString & GetWorkshop() = 0;
  
  /**
    * Returns the name of the default command to start for this 
    * ui-activable object. The default command is the command that is
    * started when there is no started command.
    * @return 
    *   The name of the default command
    */
  virtual CATString & GetDefaultCommand() = 0;
  
  /**
    * @nodoc
    * Returns a @href CATCmdContainer containing the contextual menu 
    * to be associated with this ui-activable object.
    * @return 
    *   Returns a CATCmdContainer
    */
  virtual CATCmdContainer * GetContextualMenu() = 0;

  /** @nodoc */
  virtual CATCommandGlobalUndo * GetGlobalUndo () = 0;

  /**
    * @nodoc
    * Returns the document instance containing this ui-activable object.
    */
  virtual CATDocument * GetDocument()= 0;  
  
  /** @nodoc */
  virtual void SetDocument(CATDocument * Doc)= 0;  
  
  /** @nodoc */
  virtual void SetDropSource (CATFrmDropSource * source)= 0;
  
  /** @nodoc */
  virtual CATFrmDropSource * GetDropSource ()= 0;
  
  /** @nodoc */
  virtual void SetDropTarget (CATFrmDropTarget * target)= 0;
  
  /** @nodoc */
  virtual CATFrmDropTarget * GetDropTarget ()= 0;

  /** @nodoc */
  virtual void ChangePathToActivate(CATPathElement * ioPathElement) = 0;

  /** @nodoc */
  virtual void ObjectEdition(CATBoolean iObjectEdition) = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler (CATIUIActivate, CATBaseUnknown);


#endif
