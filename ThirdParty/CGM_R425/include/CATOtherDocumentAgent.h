#ifndef CATOtherDocumentAgent_H
#define CATOtherDocumentAgent_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected CATCmdDialogAgents.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATPathElementAgent.h"

#include "CATDlgEngUtility.h"
#include "CATListOfCATCommand.h"
#include "CATBaseUnknown.h"

class CATMultiDocumentCommand;
class CATString;
class CATPathElement;
class CATSO;
class CATCommand;
class CATNotification;
class CATFrmEditor;
class CATCommandSelector;

/**
* Class to define a dialog agent that enables selection in a nonactive document. 
* <b>Role:</b>This dialog agent enables you to select objects in a nonactive document 
* thanks to a command launched from the active state dialog command. As usual, you need
* to instantiate the dialog agent in the state dialog command' BuildGraph method and 
* associate it with a given state. The dialog agent constructor includes a parameter to
* indicate the class name of the command to launch when the state becomes 
* the active one. This command is then launched in all the other open documents' editors. 
* Such a command class must derive from @href CATMultiDocumentCommand. 
* The dialog agent is assigned a value using this command, and all the launched
* command instances are automatically deleted.
* <br><b>Important:</b>A transaction must be triggered when this agent is valuated.
*/

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATOtherDocumentAgent : public CATPathElementAgent
{
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Constructs a dialog agent that enables selection in a non-active document
  * @param  iId
  *   The agent identifier. It is used to retrieve the undo/redo titles in 
  *   the command message file.
  * @param  iCommandToLaunchInDocuments
  *   The class name of the command to launch in the other documents to select
  *   objects. This command must 
  *   derive from @href CATMultiDocumentCommand. 
  * @param  iLibrary
  *   The name of the shared library, without its extension and without 
  *   the prefix <tt>lib</tt>, that contains the command code.
  * @param  iType
  *   The type of the expected objects.
  *   The type corresponds to an interface implemented by the object. 
  *   <br><b>Legal values</b>: <tt>iType</tt> is the name of an interface
  *   that the expected objects must implement. If it is NULL, all the objects
  *   are accepted.
  * @param  iBehavior 
  *   The behavior of the dialog agent.
  *   <br><b>Legal values</b>: The behavior is given as a
  *   concatenation of the facet values using the | character.
  *   <br>e.g.: <code>CATDlgEngRepeat|CATDlgEngActive</code>
  *   <br>If it is NULL, the agent has the default behavior value for each
  *   facet.
  *   <br>The behavior may be specified later using the @href CATDialogAgent#SetBehavior 
  *   method.
  */
  CATOtherDocumentAgent (const CATString & iId,
                         CATClassId        iCommandToLaunchInDocuments,
                         const char      * iLibrary,
                         CATClassId        iType=NULL,
                         CATDlgEngBehavior iBehavior=NULL);

  virtual ~CATOtherDocumentAgent ();
  
  /** @nodoc */
  virtual void SetValue (CATPathElement * value, CATCommand *acqCommand);
  /** @nodoc */
  virtual void SetListOfValues (CATSO * List, CATCommand *acqCommand);
  /** @nodoc */
  void RemoveCommand (CATMultiDocumentCommand * cmd);
  /** @nodoc */
  CATStatusChangeRC Activate (CATCommand * fromClient, CATNotification * notif);
  /** @nodoc */
  CATStatusChangeRC Desactivate (CATCommand * fromClient, CATNotification * notif);
  /** @nodoc */
  CATStatusChangeRC Cancel (CATCommand * fromClient, CATNotification * notif);
  
private:
  
  void LaunchCommands ();
  void KillCommands ();

  void CBEditorActivated (CATCallbackEvent iEvent, void* iPublisher,
              CATNotification* iNotif, CATSubscriberData iData,
              CATCallback iCallbackId);
  void CBEditorDesactivated (CATCallbackEvent iEvent, void* iPublisher,
              CATNotification* iNotif, CATSubscriberData iData,
              CATCallback iCallbackId);

  CATCommandSelector * _commandSelector;
  CATLISTP(CATCommand) _launchedCommandsList;
  CATLISTP(CATCommand) _otherEditorsList;
  char * _CommandToLaunch;
  char * _Library;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATOtherDocumentAgent ();
  CATOtherDocumentAgent (const CATOtherDocumentAgent &);
  CATOtherDocumentAgent & operator= (const CATOtherDocumentAgent &);

protected:
  
  /*----------------------------------------------------------*/
  /*          Set/Retrieve the agent properties	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  virtual HRESULT _GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
  virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);

private:
  
  /*----------------------------------------------------------*/
  /*                Getters for DE² DUMP	-DE² use only-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  const CATUnicodeString GetLibrary()const {if(_Library) return CATUnicodeString(_Library); else return CATUnicodeString("");}
  const CATUnicodeString GetCommandToLaunch()const {if(_CommandToLaunch) return CATUnicodeString(_CommandToLaunch); else return CATUnicodeString("");}

  friend class CATDE2DumpCppStateCommand;
};

#endif
