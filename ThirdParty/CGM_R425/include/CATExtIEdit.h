#ifndef CATExtIEdit_h
#define CATExtIEdit_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


#include "CATAfrFoundation.h"
#include "CATIEdit.h"
#include "CATCommand.h"

class CATCommand;
class CATDlgFrame;
class CATPathElement;
class CATDialog;
class CATString;


/**
  * Adapter for the CATIEdit interface .
  * <b>Role :</b> This base class provides usefull services making 
  * the management of the life cycle of the command returned by the @href CATIEdit#Activate
  * method easier.
  * <br>
  * The CATExtIEdit class provides the @href #IsActive method that
  * tells whether the @href CATCommand instance returned by the @href CATIEdit#Activate
  * method is in the active state or not.
  * <br>
  * Implementing CATIEdit just consists in subclassing the 
  * CATExtIEdit class and simply overriden the @href #Activate or
  * the @href #GetPanelItem or both methods. Do not forget to implement the CATIEdit interface
  * using : CATImplementBOA(CATIEdit, CATExtIEdit).
  */
class ExportedByCATAfrFoundation CATExtIEdit : public CATIEdit
{
  
 CATDeclareClass;

public:
 
  
  /**
  * Constructs the class.
  */
  CATExtIEdit();
  virtual ~CATExtIEdit ();

  /**
    * Edits the object.
    * <br><b>Role:</b>Called by the ui-activation manager (@href CATIUIActivate )
    * when the user double-clics on the feature, or selects the
    * "Definition .." sub-item on the feature's contextual menu or on the Edit menu.
    * @param iPath
    *   A @href CATPathElement to the current feature object
    * @return
    *   Returning the instanciated command, if any, is a good choice.
    */
  virtual CATCommand  * Activate(CATPathElement * path) ;

  /**
    * Deactivates the feature edition command.
    * <br><b>Role:</b>This method is called when the @href CATCommand 
    * issued by the @href CATIEdit#Activate leaves the 
    * active state. 
    */
  virtual void  Deactivate() ;

  /**
    * @nodoc
    */
  virtual CATDlgFrame * GetInPanelEditor() ;

  /**
    * Returns a widget representing the current feature.
    * <br><b>Role:</b>During a multi-selection of feature objects
    * implementing the CATIEdit interface, it is thus possible for a 
    * command to build a compound dialog containing each selected feature's 
    * editing widget.
    * @param iParent
    *   The widget that the returned CATDlgFrame must parented to.
    * @param iTitle
    *   The title that the returned widget must have.
    * @return
    *   A new @href CATDlgFrame, child of <tt>iParent</tt> with the title 
    * <tt>iTitle</tt>.
    */
  virtual CATDlgFrame * GetPanelItem(CATDialog * parent, const CATString& title);

  /**
    * Returns an integer value telling whether the command is launched 
    * or not. 
    * @return
    *   0 if inactive, != 0 otherwise.
    */
  virtual int IsActive() ;

  /**
    * @nodoc
    * Callback.
    */
  void DeactivateOnEnd (CATCommand *);

private:


  void DeactivationSignaled (CATCallbackEvent   EndCommandEvent, void * command, 
               CATNotification *cmdNotif, CATSubscriberData cmdData, CATCallback cbId);
 
  int  _IsActive;

  // save of cbIds to be able to remove 
  // them when Deactivation is signaled
  CATCallback   _callbackId[2];

};

#endif
