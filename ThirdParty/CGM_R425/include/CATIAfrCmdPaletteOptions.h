#ifndef CATIAfrCmdPaletteOptions_H
#define CATIAfrCmdPaletteOptions_H

// COPYRIGHT Dassault Systemes 2003

/**
* @CAA2Level L1
* @CAA2Usage U5
*/

#include "CATAfrPalette.h"
#include "CATBaseUnknown.h"

class CATListPtrCATCommandHeader;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrPalette IID IID_CATIAfrCmdPaletteOptions;
#else
extern "C" const IID IID_CATIAfrCmdPaletteOptions ;
#endif
/**
 * Interface for state commands to dynamically fill the Tools Palette.
 * <b>Role</b>: The Tools Palette is a special toolbar which updates dynamically when:
 * <ul>
 *  <li>Entering a workbench. The workbench implements the @href CATIAfrPaletteOptions interface.</li>
 *  <li>Executing a command. The command implements this interface.</li>
 * </ul>
 * The Tools Palette contains <b>options</b>. 
 * <br>An option is a command header instance which may start a simple command 
 * ( @href CATCommand ) ; avoid dialog ( @href CATDlgDialog ) or state commands
 * (<tt>CATStateCommand</tt>). Often a check header, encapsulated by the 
 * @href CATAfrCheckHeaderAccessor class, is sufficient.
 * <br><br>The @href #GetPaletteOptions enables you to specify the options available as 
 * long as the command is alive,
 * and the @href #GetPaletteStateOptions enables you 
 * to specify the options depending on states. 
 * <br>When the command is interrupted by a shared command, all its options become
 *  unavailable. 
 * <br><br><b>About the command header instance usage</b>
 * <br>You may create the header instances at any time before the <tt>GetPaletteOptions</tt> 
 * or the <tt>GetPaletteStateOptions</tt> methods are called or even inside these methods. 
 * You have only one rule to respect, a
 * command header instance must be created only once during the @href CATFrmEditor life. 
 * The @href CATAfrGetCommandHeader global fuction can be used to retrieve 
 * a command header instance from its identifier, or to check its existence
 * before its creation.
 * 
 */

class ExportedByCATAfrPalette CATIAfrCmdPaletteOptions: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /** 
     * Gets the options to display when entering the command. 
     * <br><b>Role:</b>This method provides the options available during the
     * life of the command. But this method is called at the first command activation,
     * it means that the command must be a shared or exclusive command. 
     * @return
     *  List of options. 
     *  <br> The returned options are added to the Palette when the command 
     * is started and they are automatically removed when leaving the command.
     * The list can be empty.
     */
    virtual CATListPtrCATCommandHeader GetPaletteOptions() = 0;

    /** 
     * Gets the options to display when changing the command current state. 
     * <br><b>Role</b>This method is called when entering a state. In most cases,
     * the name of the current state should be compared to a string to
     * return a specific list. Here is an example that you can find in such method:
     * <pre>
     *    CATLISTP(CATCommandHeader) PaletteStateOptions;
     *    CATDialogState * pCurrentState = <b>GetCurrentState</b>();
     *    if ( NULL != pCurrentState )
     *    {
     *       CATString StateName = pCurrentState-><b>GetResourceID</b>();
     *
     *        if ( ! strcmp("MyStateId",StateName) )
     *        {
     *           PaletteStateOptions.Append(pCmdHdr);
     *           ...
     * </pre>
     *    where <tt>pCmdHdr</tt> can be a command header pointer retrieval by the 
     *    @href CATAfrGetCommandHeader global function.
     * @return
     *  List of options. 
.    * <br>The returned options are added to the Palette for the current state
     * and they are automatically removed when leaving the state.
     * The list can be empty for all the states, or for some of them.
     * <br>If the command is a simple @href CATCommand , return an empty list.
     */
	  virtual CATListPtrCATCommandHeader GetPaletteStateOptions() = 0;
};

#endif
