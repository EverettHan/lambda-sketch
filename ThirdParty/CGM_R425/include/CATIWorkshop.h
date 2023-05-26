#ifndef CATIWorkshop_h
#define CATIWorkshop_h

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATCmdWorkshop;

extern ExportedByCATAfrItf IID IID_CATIWorkshop;

/**
* Interface to create a workshop.
* <b>Role</b>: The workshop is the object that gathers the tools to work on the document. 
* It may contain different workbenches. Tools are grouped in toolbars and menus. 
* These tools are commands which are handled by workshop and its workbenches by means of 
* command headers. 
* To be able to request its workshop, the document must contain an object which implements 
* the @href CATIUIActivate  interface.
* <br><br>
* To enable the instanciation of the workshop you must:
* <ul>
* <li> Create a workshop factory interface which derives from @href CATIGenericFactory. </li>
* <li> Implement this factory interface with the help of these two macros: @href CATDeclareWorkshopFactory 
* and @href CATImplementWorkshopFactory. </li>
* </ul>
* @see CATIWorkbench, CATIWorkbenchAddin
*/
class ExportedByCATAfrItf CATIWorkshop : public CATBaseUnknown
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
  virtual void             CreateCommands ()        = 0;

  /**
  * Creates the workshop accesses.
  * <br><b>Role</b>: Creates the containers for the workshop, the menubar, the menus, and the toolbars, 
  * the starters for the commands, and arranges the commands in the menus and toolbars.
  * With the @href NewAccess macro you have explanations to create  each 
  * component of the workshop and how to arrange it. 
  * <br><b>Warning</b>:
  * The workshop's name must be the same as the class implementing this interface.
  * @return 
  *   The workshop's container . 
  */
  virtual CATCmdWorkshop * CreateWorkshop ()        = 0;

  /**
  * Returns the name of the interface exposed by the workshop to create workbenches.
  * <br><b>Role</b>: To enable client applications of your workshop to add their 
  * own workbenches, you should provide an interface that the client application will implement. 
  * This interface should derive from the @href CATIWorkbench interface. Each implementation 
  * of this interface is a workbench of this workshop.
  * <br><b>Warning</b>: The name of this interface must be <b>CATI</b>xxx<b>Configuration</b>, where xxx 
  * is the name of your workshop.
  */
  virtual CATClassId       GetWorkbenchInterface () = 0;
 
  /**
  * Returns the name of the interface exposed by the workshop to create add-ins.
  * <br><b>Role</b>: To enable client applications of your workshop to add their 
  * own addins , you should provide an interface that the client application will implement. 
  * This interface should derive from the @href CATIWorkbenchAddin interface. 
  * <br><b>Warning</b>: The name of this interface must be pppIxxx<b>Addin</b>, where 
  * ppp is your application prefix (such as CAT for CATIA) and xxx is the name of your 
  * workshop.
  */
  virtual CATClassId       GetAddinInterface ()     = 0;
};

CATDeclareHandler(CATIWorkshop, CATBaseUnknown);

#endif
