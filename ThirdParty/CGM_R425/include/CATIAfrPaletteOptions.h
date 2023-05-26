#ifndef CATIAfrPaletteOptions_H
#define CATIAfrPaletteOptions_H

// COPYRIGHT Dassault Systemes 2003

/**
* @CAA2Level L1
* @CAA2Usage U5
*/

#include "CATAfrPalette.h"
#include "CATBaseUnknown.h"

class CATListPtrCATCommandHeader;
class CATCommandHeader;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrPalette IID IID_CATIAfrPaletteOptions;
#else
extern "C" const IID IID_CATIAfrPaletteOptions ;
#endif


/**
 * Interface for workbenches to dynamically fill the Tools Palette.
 * <b>Role</b>: The Tools Palette is a special toolbar which updates dynamically when:
 * <ul>
 *  <li>Entering a workbench. The workbench implements this interface.</li>
 * <li>Executing a command. The command 
 * implements the @href CATIAfrCmdPaletteOptions interface. </li>
 * </ul>
 * To be exact, a workbench may implement <tt>CATIAfrPaletteOptions</tt> interface 
 * using the <tt>WORKBENCHId<b>_Palette</b></tt> late type where 
 * <tt>WORKBENCHId</tt> is the identifier of the workbench. This identifier is the third 
 * argument of the @href NewAccess macro used in the @href CATIWorkbench#CreateWorkbench
 * method to define the contents of the workbench.
 * <pre>
 *NewAccess(<b>CATCmdWorkbench</b>,pWORKBENCHId,WORKBENCHId);
 *</pre> 
 * The Tools Palette contains <b>options</b>. 
 * <br>An option is a command header instance which may start a simple command 
 * ( @href CATCommand ) ; avoid dialog ( @href CATDlgDialog ) or state commands
 * (<tt>CATStateCommand</tt>). Often a check header, encapsulated by the 
 * @href CATAfrCheckHeaderAccessor class, is sufficient.
 * <br>The @href #GetPaletteOptions enables you to specify the options available when 
 * the workbench is the current one.
 * <br><br><b>About the command header instance usage</b>
 * <br>You may create the header instances at any time before the <tt>GetPaletteOptions</tt> 
 * method is called or even inside this method. You have only one rule to respect, a
 * command header instance must be created only once during the @href CATFrmEditor life. 
 * The @href CATAfrGetCommandHeader global fuction can be used to retrieve 
 * a command header instance from its identifier, or to check its existence
 * before its creation.
 * 
 */
class ExportedByCATAfrPalette CATIAfrPaletteOptions: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /** 
     * Gets the options to display when entering the workbench. 
     * @return
     *  List of options.
     * <br>The returned options are added to the Palette when the workbench 
     * is started and they are automatically removed when leaving the workbench.
     */
    virtual CATListPtrCATCommandHeader GetPaletteOptions() = 0;
};

#endif
