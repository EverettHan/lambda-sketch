#ifndef CATBasicMultiDocumentCommand_H
#define CATBasicMultiDocumentCommand_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATMultiDocumentCommand.h"

#include "CATDialogAgent.h"
#include "CATPathElementAgent.h"
#include "CATBooleanDef.h"

/**
* Class to define a state dialog command to achieve a selection in any nonactive document.
* <b>Role:</b>: This class enables a selection in a nonactive document from a state 
* dialog command running in the workbench of the active document.
* <br> Instantiate <tt>CATBasicMultiDocumentCommand </tt>to create a class that should 
* be instantiated by a dialog agent of another state dialog command that runs in 
* the active document. The dialog agent must be an instance of @href CATOtherDocumentAgent.
* <br>
* When the state with which the dialog agent is associated becomes active, an instance 
* of <tt>CATBasicMultiDocumentCommand</tt> is created for any nonactive document as a proxy
* of the active command to select either an object or a set of objects in one of these 
* nonactive documents. <tt>CATBasicMultiDocumentCommand</tt> contains a single state
* with a single selection agent, instance of @href CATPathElement. This selection agent is 
* assigned the same behavior than the @href CATOtherDocumentAgent dialog agent of the active 
* state dialog command that requests the <tt>CATBasicMultiDocumentCommand</tt> instantiation.
*/

class ExportedByCATDialogEngine CATBasicMultiDocumentCommand : public CATMultiDocumentCommand
{

  /** @nodoc */
  CATDeclareClass;
  
  /** @nodoc */
  CmdDeclareResource(CATBasicMultiDocumentCommand, CATMultiDocumentCommand)
    
public:
  
  /** @nodoc */
  CATBasicMultiDocumentCommand ();
  /** @nodoc */
  virtual ~CATBasicMultiDocumentCommand ();
  /** @nodoc */
  virtual void BuildGraph ();
  
private:

  /** @nodoc */
  CATBoolean SelectionDone (void * iDummy);
  /** @nodoc */
  CATPathElementAgent * _AcquisitionAgent;

};

#endif // CATBasicMultiDocumentCommand_H
