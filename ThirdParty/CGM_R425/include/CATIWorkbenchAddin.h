#ifndef CATIWorkbenchAddin_h
#define CATIWorkbenchAddin_h

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @CAA2Level L1
 * @CAA2Usage U6
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATCmdContainer;

extern ExportedByCATAfrItf IID IID_CATIWorkbenchAddin;

/**
* Interface to derive to create an addin.
* <b>Role</b>: Existing workshops or workbenches can be customized by the client 
* application programmer. This customization consists in putting commands into one or 
* several new toolbars, and add these toolbars to the appropriate workshop or workbench. 
* Note that an add-in cannot customize the menu bar. 
* <br>
* The workshop or the workbench 
* should feature an add-in interface that you will implement to provide the toolbars 
* using a class extending a late type. This add-in interface derives from the <tt>CATIWorkbenchAddin</tt> 
* interface and it's valid for workshops as well as workbenches. 
* @see CATIWorkbench 
*/
class ExportedByCATAfrItf CATIWorkbenchAddin : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  /**
  * Instantiates the command headers.  
  * <br><b>Role</b>: Each command you want to make available in your workshop or 
  * workbench must have a command header. The command header holds the necessary 
  * information to load the command, such as the name of the 
  * shared library in which the command's executable code is located, the name of the 
  * command class, and the data to pass to the command's code when this command 
  * becomes the current one. The command header has resources for each command to display 
  * such as the command name shown to the end user, its ToolTip displayed in a balloon, 
  * its help message, and its icon.
  * <br>Each instance of header is deleted by CATIA.
  * @see CATCommandHeader
  */
  virtual void              CreateCommands () = 0;

  /**
  * Creates toolbars containers.
  * <br><b>Role</b>: Creates toolbars's container with the @href NewAccess macro, and arranges 
  * commands in the toolbars. Toolbars are chained together.
  * @return
  *    The first toolbar of the chain.
  */
  virtual CATCmdContainer * CreateToolbars () = 0;
 
};

CATDeclareHandler(CATIWorkbenchAddin, CATBaseUnknown);

#endif
