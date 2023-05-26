#ifndef CATMultiDocumentCommand_H
#define CATMultiDocumentCommand_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATStateCommand.h"

class CATPathElement;
class CATSO;
class CATOtherDocumentAgent;
class CATFrmEditor;

/**
* Base class to define a state dialog command to achieve a selection in any nonactive document. 
* <b>Role</b>: This class enables a selection in a nonactive document from a state dialog 
* command running in the workbench of the active document.
* <br>Derive <tt>CATMultiDocumentCommand</tt>  to create a class that should be instantiated 
* by a dialog agent of another state dialog command that runs in the active document. 
* The dialog agent must be an instance of @href CATOtherDocumentAgent.
* <br>
* When the state with which the dialog agent is associated becomes active, an instance 
* of <tt>CATMultiDocumentCommand</tt> is created for any nonactive document as a proxy of
* the active command to select either an object or a set of objects in one of these 
* nonactive documents.
* <br>
* As for any state dialog command, you need to override the @href CATStateCommand#BuildGraph method, 
* create at least a state, associate with this state a @href CATPathElement Agent instance 
* to enable selection, and create an Action method that uses the @href #ReturnValue or 
* @href #ReturnListOfValues method, depending on whether you enable multiselection.
*
* @see CATBasicMultiDocumentCommand
*/

class ExportedByCATDialogEngine CATMultiDocumentCommand : public CATStateCommand
{
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  virtual ~CATMultiDocumentCommand();
  
  /** @nodoc */
  void SetFromCommand (CATOtherDocumentAgent * iAgent);
  
  /**
  * Returns to the agent the selected object as a path element.
  * <br><b>Role:</b>Use this method when the selection is single.
  * Just after executing this method the command will be automatically deleted.
  * <br>The value is sent to the <tt>CATOtherDocumentAgent</tt> which has instantiated
  * this command.
  * @param iValue
  *  Element selected.
  */
  void ReturnValue (CATPathElement * iValue);
  
  /**
  * Returns to the agent the selected objects as a path element.
  * <br><b>Role:</b>Use this method in case of multi-selection.
  * Just after executing this method the command will be automatically deleted.
  * <br>The list is sent to the <tt>CATOtherDocumentAgent</tt> which has instantiated
  * this command.
  * @param iList
  *   List of selected elements.
  */
  void ReturnListOfValues (CATSO * iList);
  
  /** @nodoc */
  CATFrmEditor * GetEditor ();
  /** @nodoc */
  void SetEditor (CATFrmEditor * iEditor);
  /** @nodoc */
  void Stop ();
  
protected:
  
  /** @nodoc */
  CATMultiDocumentCommand ();
  
  /**
  * The agent which has instantiated this command.
  */
  CATOtherDocumentAgent * _fromCommand;
  
private:
  
  CATFrmEditor * _editor;
  
};

#endif
