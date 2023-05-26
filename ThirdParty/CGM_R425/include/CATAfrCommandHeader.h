#ifndef CATAfrCommandHeader_H
#define CATAfrCommandHeader_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"
#include "CATAfrCommandHeaderArgs.h"
#include "CATAfrAvailabilityType.h"
#include "CATString.h"

class CATBaseUnknown;
class CATCommand;
class CATUnicodeString;

/** @nodoc */
#define MkHeaderStr(x)  #x
/** @nodoc */
#define XMkHeaderStr(x) MkHeaderStr(x)


//---------------------------------------------------------------------------
/**
 * Starts the command associated with a command header.
 * <br><b>Role</b>: This function starts the @href CATCommand associated
 * with a @href CATCommandHeader, and returns a pointer to this command.
 * @param iCommandHeaderId
 *  The identifier of the CATCommandHeader.
 * @param oCommand
 *  The CATCommand.
 * @return
 * Returns S_OK on success. Returns E_FAIL if the identifier is not an existing CATCommandHeader identifier.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrStartCommand (CATString iCommandHeaderId,
                            CATCommand *& oCommand);

//---------------------------------------------------------------------------
/**
 * Creates a command header.
 * <br><b>Role</b>: This function creates a command header from an official V5 command header.
 * You can find the reusable command headers in the corresponding CAA documentation.
 * After calling this service the identifier can be used in a toolbar or in a menu to give an access to the corresponding command.
 * @param iCommandHeaderId
 *  The identifier of the Command Header. Only identifiers which are documented in any CAA documentation can be used.
 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>         <dd>the service has succeeded and the command header was created
 *   <dt><tt>S_FALSE</tt>      <dd>the service has succeeded but no command header was created because it already existed
 *   <dt><tt>E_NOTIMPL</tt>    <dd>the service has failed because the identifier is not an authorized command header identifier
 *   <dt><tt>E_FAIL</tt>       <dd>the service has failed because a licensing control fails
 *   <dt><tt>E_UNEXPECTED</tt> <dd>the service has failed because another error has occurred
 */
ExportedByCATAfrFoundation
HRESULT CATAfrCreateCommandHeader (CATString iCommandHeaderId);

/**
 * Changes the icon of a command header.
 * @param iCommandHeaderId
 *  The identifier of the command header.
 * @param iIconName
 *  The name of the icon.
 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>    <dd>the service has succeeded and the icon was changed.
 *   <dt><tt>E_FAIL</tt>  <dd>the service has failed and the icon was not changed. Notice that no check is performed on the icon existence.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrSetCommandHeaderIconName (const CATString & iCommandHeaderId, const CATString & iIconName);

/**
 * Changes the title of a command header.
 * @param iCommandHeaderId
 *  The identifier of the command header.
 * @param iTitle
 *  The unicode string containing the title.
 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>    <dd>the service has succeeded and the title was changed.
 *   <dt><tt>E_FAIL</tt>  <dd>the service has failed and the title was not changed.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrSetCommandHeaderTitle    (const CATString & iCommandHeaderId, const CATUnicodeString & iTitle);

/**
 * Changes the availability of a command header.
 * <br><b>Role</b>: This function changes an availability mode of a command header.
 * An availability mode has an effect only when the corresponding mode is activated.
 * <br>The command header will be disabled as soon as one activated availability mode is set to CATFrmUnavailable on the command header.
 * @param iCommandHeaderId
 *  The identifier of the command header.
 * @param iAvailabilityType
 *  The availability style to be set.
 * @param iAvailability
 *  The availability status to be set (available or not).
 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>    <dd>the service has succeeded and the availability type was changed.
 *   <dt><tt>E_FAIL</tt>  <dd>the service has failed and the availability type was not changed.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrSetCommandHeaderAvailability    (const CATString & iCommandHeaderId, CATAfrAvailabilityType iAvailabilityType, CATFrmState iAvailability);

/**
 * Returns the current argument list.
 * <br><b>Role</b>: Call this function in the command constructor to get the argument list passed thru its command header.
 * <br>After the command construction the list is reseted.
 * @return
 *   the argument list
 */
ExportedByCATAfrFoundation
CATAfrCommandHeaderArgs  & CATAfrGetArguments ();

 /**
   * GetArgs returns a pointer on the CATAfrCommandHeaderArgs object associated
   * to the CATCommandHeader.
   * The CATAfrCommandHeaderArgs corresponds to the list of arguments given to the
   * launched CATCommand associated to this CATCommandHeader.
   * When you have finished to use the reference, you need to call Release on it
   * (unusual way to use a reference but legacy).
   *
   * Sample:
   * // Get arguments list to populate it. Note: returned by reference.
   * CATAfrCommandHeaderArgs * argList = NULL;GetArgs("MyHeader",argList);
   *
   * // Here you can add your arguments to the list using the CATAfrCommandHeaderArgs::Set function
   * argList->Set("MyArgument", CATBoxingOfint::Box(1));
   *
   * // When you finished to set your arguments, don't forget to release the arguments list
   * argsList->Release();
   *
   * Thanks to a CATAfrCommandHeaderArgsIterator ( CATAfrCommandHeaderArgs::CreateIterator )
   * Command header's arguments list can be scanned.
   *
   * @param iHeaderID
   *     The identifier of the command header (CATCommandHeader).
   *
   * @param opCmdHdrArgs [CATBaseUnknown#Release]
   *     Returns a pointer on the arguments list given to the launched CATCommand associated to this 
   *     CATCommandHeader
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>    <dd>Arguments list have been successfully retrieved.
   *   <dt><tt>E_FAIL</tt>  <dd>Failed to retrieve arguments list.
   */
  ExportedByCATAfrFoundation HRESULT GetArgs(const CATString & iHeaderID, CATAfrCommandHeaderArgs * &opCmdHdrArgs );


ExportedByCATAfrFoundation CATBaseUnknown * CreateCmdHdrArgs(CATString iHeaderID, CATString iLoadName, CATString iClassName,
															 void* iArgument, CATString iResourceFileName, CATString iFw, CATFrmState iState = CATFrmAvailable);

ExportedByCATAfrFoundation CATBaseUnknown * GetCmdHdr(const CATString & iHeaderID);

ExportedByCATAfrFoundation CATBaseUnknown * CreateRadioGroup(CATString iHeaderID, CATString iFw);

/**
* Class to create a command header.
* <b>Role</b>: Each command you want to make available in your workshop or workbench 
* must have a command header. It holds the necessary information to load the command, 
* such as the name of the shared library in which the 
* command's executable code is located, the name of the command class, and the data to pass 
* to the command's code when this command becomes the current one. 
* <p>The command header has 
* resources for each command  to display, such as the command name shown to the end user, 
* its ToolTip displayed in a balloon, its help message, and its icon. This enables the 
* workshop or workbench to be  displayed, that is loaded in memory, without any of its 
* commands being itself loaded, except the default one, spares memory space, and improves 
* performance. The end user can  see the icons in the toolbars, the items in the menu bar, 
* can ask for help on a given command, without the command being loaded. It is only when 
* he/she clicks on the menu item or on the icon that the command code is actually loaded.</p>
*/

class ExportedByCATAfrFoundation CATAfrCommandHeader
{
public:
  /**
  * Constructs a command header. 
  * @param iHeaderID
  *     The identifier of the header. It is the <tt>command</tt> argument of the <tt>
  *     SetAccessCommand </tt> macro.
  * @param iLoadName
  *    The name of the shared library where <tt>iClassName</tt> is.
  * @param iClassName
  *    The name of the <tt> CATCommand </tt> class.
  * @param iArgument
  *    The argument of the <tt> CATCommand </tt> class.
  * @param iResourceFileName
  *    The name of the resource file.
  * @param iState
  *    The CATCommandHeader state.
  *    <br><b>Legal values</b>: 
  *       <li> CATFrmAvailable (The default value) </li>
  *       <li> CATFrmUnavailable </li>
  * 
  * @see CATCommand, SetAccessCommand, CATFrmState
  */
	static CATBaseUnknown * CATCreateCommandHeader(const CATString & iHeaderID, const CATString & iLoadName, 
												   const CATString & iClassName, void * iArgument, 
												   const CATString & iResourceFileName, 
												   CATFrmState iState = CATFrmAvailable);
  /**
  * Constructs a command header for a DE² state command. 
  * @param iHeaderID
  *     The identifier of the header. It is the <tt>command</tt> argument of the <tt>
  *     SetAccessCommand </tt> macro.
  * @param iResourceFileName
  *    The name of the resource file.
  * @param iState
  *    The CATCommandHeader state.
  *    <br><b>Legal values</b>: 
  *       <li> CATFrmAvailable (The default value) </li>
  *       <li> CATFrmUnavailable </li>
  * 
  * @see CATCommand, SetAccessCommand, CATFrmState
  */
	static CATBaseUnknown * CATCreateDE2CommandHeader(const CATString & iHeaderID, const CATString & iResourceFileName, CATFrmState iState = CATFrmAvailable);

  /**
  * Gets a pointer to a command header. 
  * @param iHeaderID
  *     The identifier of the command header.
  * @return
  *		Returns the command header if it exists or NULL if the identifier is not an existing command header identifier.
  */
	static CATBaseUnknown * CATGetCommandHeader(const CATString & iHeaderID);


};


/** @nodoc */
#define CATAfrCommandHeader
/** @nodoc */
#define CATCreateCommandHeader(iHeaderID, iLoadName, iClassName, iArgument, iResourceFileName, ...) \
	CreateCmdHdrArgs(iHeaderID, iLoadName, iClassName, iArgument, iResourceFileName, XMkHeaderStr(_MK_FWNAME_), ##__VA_ARGS__)
/** @nodoc */
#define CATCreateDE2CommandHeader(iHeaderID, iResourceFileName, ...) \
	CreateCmdHdrArgs(iHeaderID, "CATDialogEngine", "CATDE2Manager", NULL, iResourceFileName, XMkHeaderStr(_MK_FWNAME_), ##__VA_ARGS__)
/** @nodoc */
#define CATGetCommandHeader(iHeaderID) GetCmdHdr(iHeaderID)

/** @nodoc */
#define CATCreateRadioGroup(iHeaderID, ...) \
	CreateRadioGroup(iHeaderID, XMkHeaderStr(_MK_FWNAME_))



#endif
