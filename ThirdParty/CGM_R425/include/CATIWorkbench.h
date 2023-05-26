#ifndef CATIWorkbench_h
#define CATIWorkbench_h

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @CAA2Level L1
 * @CAA2Usage U6
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATListPV.h"

extern ExportedByCATAfrItf IID IID_CATIWorkbench;

class CATCmdWorkbench;
/**
* Interface to derive to create a workbench.
* <b>Role</b>: The workbench is the object seen by the end user in place of the 
* workshop. As in workshops, tools are grouped in toolbars and menus. 
* These tools are commands which are handled by workshop and its workbenches by means of 
* command headers. 
* <br><br>
* The workshop dedicated to this workbench features a specific workbench 
* interface which derives from <tt>CATIWorkbench</tt>.
* Each workbench of this workshop is an implementation of this specific workbench interface. 
* <br><br>
* To enable the instanciation of the workbench you must:
* <ul>
* <li> Create a workbench factory interface which derives from @href CATIGenericFactory. </li>
* <li> Implement this factory interface with the help of these two macros: @href CATDeclareConfigurationFactory 
* and @href CATImplementConfigurationFactory. </li>
* </ul>
  * @see CATIWorkbenchAddin
*/
class ExportedByCATAfrItf CATIWorkbench : public CATBaseUnknown
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
  */
  virtual void              CreateCommands() = 0;

  /**
  * Creates the workbench accesses.
  * <br><b>Role</b>: Creates the containers for the workbench, the menubar, the menus, and the toolbars, 
  * the starters for the commands, and arranges the commands in the menus and toolbars.
  * With the @href NewAccess macro you have explanations to create  each 
  * component of the workbench and how to arrange it.
  * <br><b>Warning</b>:
  * The workbench's name must be the same as the class implementing this interface.
  * @return 
  *   The workbench's container . 
  */
  virtual CATCmdWorkbench * CreateWorkbench() = 0;

  /**
  * Returns the name of the interface exposed by the workbench to create add-ins.
  * <br><b>Role</b>: To enable client applications of your workbench to add their 
  * own addins , you should provide an interface that the client application will implement. 
  * This interface should derive from the @href CATIWorkbenchAddin interface. 
  * <br><b>Warning</b>: The name of this interface must be pppIxxx<b>Addin</b>, where 
  * ppp is your application prefix (such as CAT for CATIA) and xxx is the name of your 
  * workbench.
  */
  virtual CATClassId        GetAddinInterface () = 0;

  /**
  * @nodoc 
  * Replaces specifics interfaces by customized interfaces.
  * <br><b>Warning</b>: This method should be <i>empty</i> implemented. 
  */
  virtual void              GetCustomInterfaces(CATListPV * iDefaultIIDList,
						                        CATListPV * iCustomIIDList) = 0;
  
};

CATDeclareHandler(CATIWorkbench, CATBaseUnknown);

#endif
