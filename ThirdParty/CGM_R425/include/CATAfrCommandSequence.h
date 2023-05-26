// COPYRIGHT Dassault Systemes 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATAfrCommandSequence_H
#define CATAfrCommandSequence_H

#include "CATAfrFoundation.h"
#include "CATAfrCommandHeaderStartInfo.h"
#include "CATListOfCATAfrCommandHeaderStartInfo.h"

#include "CATCommand.h"
#include "CATCallbackManager.h"
#include "CATString.h"
#include "CATBoolean.h"

class CATSysWeakRef;
class CATCommand;

/**
* Class representing a command sequence.
*
* <br><b>Role</b>: A sequence is a list of couples {command header identifier, argument list}.
* The sequence execution begins with the execution of the command pointed by the first command header
* and it ends with the execution of the command pointed by the last command header.
* <p>
* Kinds of Sequences.
* <ul>
*   <li>
*   Wizard
*   <br>A task is predefined and consists in a fixed sequence of commands. Each command in the sequence:
*   <ol>
*     <li>reads its input parameters
*     <li>runs
*     <li>sets its output parameters
*     <li>continues the sequence.
*     It does not need to access the sequence structure in order to pass its outputs as the inputs of the following command, or to start the following command.
*     <li>
*   </ol>
*   Cycle
*   <br>While running, a command decides to start a command sequence that ends with its re-starting (PLM Update case):
*   The main command detects a problem and proposes a solution to the user. The main command (C1) does not master this problem solving but knows the command (C2) or command sequence that does. C1 will dynamically build and start the following sequence:
*   <ol>
*     <li>C1 sets the right information for C2 to start C1 again;
*     <li>C1 start C2;
*     <li>C2 runs and starts C1 (though C2 does not know C1);
*     <li>C1 runs again, evaluates the progression to the solution and takes appropriate actions.
*   </ol>
*   Dynamic sequence
*   <br>During a sequence, each command may modify the remaining sequence:
*   <ul>
*     <li>Change any command header id in the sequence.
*     <li>Change any parameter of any command in the sequence.
*   </ul>
* </ul>
*/
class ExportedByCATAfrFoundation CATAfrCommandSequence: public CATCommand
{
  CATDeclareClass;

  public:
    /**
     * Event sent when the sequence ends.
     * <br><b>Role:</b><br>this event is sent by the sequence when it ends, normally or not.
     * It may be useful to end the object that started the sequence.
     * <br>Sample of use:
     * <pre>
     * ::AddCallback(this,
     *               pSequence,
     *	             CATAfrCommandSequence::SEQUENCE_ENDED(),
     *	             (CATSubscriberMethod)&MyClass::MyCBMethod,
     *	             NULL);
     * </pre>
     */
    CATDeclareCBEvent (SEQUENCE_ENDED);

    /**
     * Create a command sequence.
     * <br><b>Role:</b>Calls the constructor to create the current sequence.
     * <br>Do not directly call the constructor, the sequence would be unusable.
     * <br>Only one sequence may be running. Calling this method a second time before the first sequence ends
     * will not create a sequence and will return an error code.
     * @return 
     *  S_OK if creation succeeds, E_FAIL if no sequence could be created.
     */
    static HRESULT Create();

    /**
     * Start the command sequence.
     * <br><b>Role:</b>Starts the current sequence by starting the first command in the sequence.
     * If this service fails (see causes below) the sequence is deleted.
     * @return 
     *  S_OK if start succeeds, E_FAIL if no sequence was found or the command header was not found or the command header did not start any command.
     */
    static HRESULT Start();

    /**
     * Continue the command sequence.
     * <br><b>Role:</b>Continue the current sequence by starting the next command in the sequence.
     * <br>The preceding command is removed from the sequence AND RequestDelayedDestruction is called on it to stop it.
     * <br>Each command in the sequence must call Continue, even the last one,
     * else the sequence will never step to the next command of the sequence.
     * If this service fails (see causes below) the sequence is deleted.
     * <br> The output and input-output parameters of the preceding command are matched with the input and input-output parameters of the next command:
     * if identifiers are equal and value types are the same, the value of the output is copied to the input, even if the input already has a value.
     * @return 
     *  S_OK if continuation succeeds, E_FAIL if no sequence was found or the command header was not found or the command header did not start any command.
     */
    static HRESULT Continue();

    /**
     * Access to the command sequence.
     * <br><b>Role:</b>Returns the running sequence.
     * <br>The running sequence may be queried from anywhere while it is running.
     * <br>The returned sequence is modifyable by using other methods of this class.
     * @param oCurrentSequence
     *  The sequence.
     * @return 
     *  S_OK if continuation succeeds, E_FAIL if no sequence was found.
     */
    static HRESULT GetSequence(CATAfrCommandSequence *& oCurrentSequence);

    /**
     * Give the size of the list.
     * <br><b>Role:</b>Returns the number of objects in the list.
     * @param oSize
     *  The size.
     * @return 
     *  always S_OK.
     */
    HRESULT GetSize (int & oSize);

    /**
     * Access to a command information.
     * <br><b>Role:</b>Gets the information about a command of the sequence.
     * @param iIndex
     *  The index of the command to get in the sequence.
     * @return 
     *  The command information object.
     */
    CATAfrCommandHeaderStartInfo &  GetCommandHeaderStartInfo (int iIndex);

    /**
     * Access to a command information (Obsolete).
     * <br><b>Role:</b>Returns the information about a command of the sequence (Obsolete).
     * <br>Prefer the other signature; this one does not allow to change the content of the returned command information.
     */
    HRESULT GetCommandHeaderStartInfo (const int iIndex, CATAfrCommandHeaderStartInfo & oStartInfo);

    /**
     * Remove a command information.
     * <br><b>Role:</b>Deletes the information about a command of the sequence.
     * @param iIndex
     *  The number of the object to remove from the list.
     * @return 
     *  S_OK if remove was done, E_INVALIDARG if index is out of bounds.
     */
    HRESULT RemovePosition (const int iIndex);

    /**
     * Add a command information to the list.
     * <br><b>Role:</b>Adds a command information object at the end of the list.
     * <br>There is no way to add in the middle of the list.
     * @return 
     *  always S_OK.
     */
    HRESULT Append (const CATAfrCommandHeaderStartInfo & iStartInfo);

    // Do not use, reserved for command manager use
    virtual ~CATAfrCommandSequence ();

  private:

    CATAfrCommandSequence ();
    CATAfrCommandSequence (CATAfrCommandSequence &);
    CATAfrCommandSequence& operator=(CATAfrCommandSequence&);

    HRESULT StartNextCommand (CATAfrCommandHeaderArgs & iArgListToMatch);
    void Interrupt();
    void End();
    void EndCurrentCommand();
    HRESULT DoContinue();
    CATCommand * GetCurrentCommand() const;
    void AddUndoCallbacks ();
    void BeforeUndo (CATCallbackEvent, void *, CATNotification * ipNotif, CATSubscriberData, CATCallback);
    void AfterUndo (CATCallbackEvent, void *, CATNotification * ipNotif, CATSubscriberData, CATCallback);
    void OnCommandCancelled (CATCallbackEvent, void *, CATNotification * ipNotif, CATSubscriberData, CATCallback);
    void OnCommandDeleted (CATCallbackEvent, void *, CATNotification * ipNotif, CATSubscriberData, CATCallback);

    static CATAfrCommandSequence * _CurrentSequence;
    CATListOfCATAfrCommandHeaderStartInfo _StartInfoList;
    CATSysWeakRef *_pCurrentCommandWR;
    CATString _headerToStartID;
    int _numberOfStartedHeaders;
    CATBoolean _sequenceRunning;
};

#endif
