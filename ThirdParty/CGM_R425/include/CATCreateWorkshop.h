// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include <CATAfrAccessFactory.h>

/**
 * Creates an access.
 * <b>Role</b>: The workshop (or workbench) is a bag of accesses and this macro allows you
 * to create one access. To build your workshop (or workbench) you must chain accesses  
 * with the @href SetAccessChild or  @href SetAccessNext macro. If you want to display an 
 * access just before a given one, you can use the @href SetAccessAnchorName macro.
 * @param classname 
 *   The name of the class created 
 *   <b><Legal values></b>: 
 *   <dl>
 *   <dt><tt>CATCmdContainer</tt> 
 *   <ul>
 *   <li> To create a <b>menubar</b>. Then use the macro @href SetWorkshopMenu (or @href SetWorkbenchMenu )
 *   to attach the menubar to the workshop (or to the workbench).</li>
 *   <li> To create a <b>menu</b>. </li>
 *   <li> To create a <b>sub menu</b>. </li>
 *   <li> To create an <b>icon box</b>. </li>
 *   <li> To create a <b>toolbar</b>. Then use the @href AddToolbarView macro to declare the new toolbar.</li>
 *   </ul>
 *   <dt><tt>CATCmdWorkbench</tt>
 *   <dd> To create a <b>workbench</b>. It's the return value of the @href CATIWorkbench#CreateWorkbench method
 *   <dt><tt>CATCmdStarter</tt>
 *   <dd> To create a <b>starter</b>. Then to attach a command header to this starter use 
 *        the @href SetAccessCommand macro
 *   <dt><tt>CATCmdSeparator</tt>
 *   <dd> To create a <b>separator</b> between accesses.
 *   </dl>
 * @param variableName
 *   The pointer to the instance created 
 * @param objectName
 *   The name of the access. This name is used to reference resources except for a CATCmdStarter 
 *   or a CATCmdSeparator. 
 */
#define NewAccess(className, variableName, objectName) \
 className * variableName = (className*)CATAfrAccessFactory::NewAccess(#className, #objectName)


/**
 * Adds a toolbar into the workshop or into the workbench.
 * @param variableName 
 *   The pointer to the toolbar's instance created by @href NewAccess with 
 *   <tt>CATCmdContainer</tt> as <tt>classname</tt> parameter.
 * @param visibility
 *   The toolbar visibility. 
 * <br><b>Legal values</b>: 1: visible , -1:invisible  
 * @param position
 *   The toolbar's position in the frame.
 * <br><b>Legal values</b>: 
 * <dl>
 * <dt><tt>UnDock</tt>: 
 * <dd>The toolbar is undocked. 
 * <dt><tt>Bottom</tt>: 
 * <dd>The toolbar is docked at the bottom of the application window 
 * <dt><tt>Top</tt>:
 * <dd>The toolbar is docked at the top of the application window
 * <dt><tt>Left</tt>:
 * <dd>The toolbar is docked at the left of the application window
 * <dt><tt>Right</tt>: 
 * <dd>The toolbar is docked at the right of the application window
 * </dl>
 */
#define AddToolbarView(variableName, visibility, position) \
CATAfrAccessFactory::AddToolbarView(variableName, visibility, CATAfrAccessFactory::CATAfr##position)


/**
 * Chains an access to a previous one in a container.
 * <b>Role</b>: Container's accesses are chained. The first access 
 * is attached to its container by the @href SetAccessChild macro. To chain accesses
 * you use this macro.
 * @param variableName 
 *   The pointer to an access instance already chained by a <tt>SetAccessNext</tt> or 
 *   <tt>SetAccessChild</tt> macro.
 * @param nextName
 *   The pointer to the access instance which follows <tt>variableName</tt>
 */
#define SetAccessNext(variableName, nextName) \
CATAfrAccessFactory::SetAccessNext((CATCmdAccess*)variableName, (CATCmdAccess*)nextName)

/**
 * Declares the first access of a container.
 * <b>Role</b>: Container's accesses are chained. The first access 
 * is attached to its container by this macro. To chain accesses you use 
 * the @href SetAccessNext macro.
 * @param variableName 
 *   The pointer to the container's instance. This pointer is created by @href NewAccess whose
 *   <tt>classname</tt> parameter can be:
 *   <dl>
 *   <dt><tt>CATCmdContainer</tt>
 *   <dd>The container is a toolbar. <tt>childName</tt> is the first access of the toolbar 
 *   <dt><tt>CATCmdContainer</tt>
 *   <dd>The container is a menubar. <tt>childName</tt> is the first menu of the menubar
 *   <dt><tt>CATCmdWorkshop</tt>
 *   <dd>The container is a workshop. <tt>childName</tt> is the first toolbar of the workshop
 *   <dt><tt>CATCmdWorkbench</tt> 
 *   <dd>The container is a workbench. <tt>childName</tt> is the first toolbar of the workbench
 * </dl>
 * @param childName
 *   The pointer to the first access instance 
 * 
 */
#define SetAccessChild(variableName, childName) \
CATAfrAccessFactory::SetAccessChild(variableName, (CATCmdAccess*)childName)

/**
 * Declares an access to add in a container.
 * <b>Role</b>: Container's accesses are chained. The access 
 * is attached to its container by this macro at the end 
 * of the container's children list. To chain accesses  you use 
 * the @href SetAccessNext macro.
 * If an access with the same name already exists in the container,
 * it is replaced by the given access.
 * @param variableName 
 *   The pointer to the container's instance. This pointer is created by @href NewAccess whose
 *   <tt>classname</tt> parameter can be:
 *   <dl>
 *   <dt><tt>CATCmdContainer</tt>
 *   <dd>The container is a toolbar. <tt>childName</tt> is the last access of the toolbar 
 *   <dt><tt>CATCmdContainer</tt>
 *   <dd>The container is a menubar. <tt>childName</tt> is the last menu of the menubar
 *   <dt><tt>CATCmdWorkshop</tt>
 *   <dd>The container is a workshop. <tt>childName</tt> is the last toolbar of the workshop
 *   <dt><tt>CATCmdWorkbench</tt> 
 *   <dd>The container is a workbench. <tt>childName</tt> is the last toolbar of the workbench
 * </dl>
 * @param childName
 *   The pointer to the last access instance 
 * 
 */
#define AddAccessChild(variableName, childName) \
CATAfrAccessFactory::AddAccessChild(variableName, (CATCmdAccess*)childName)

/**
 * Attaches a command header to a starter.
 * @param variableName 
 *   The pointer to a CATCmdStarter's instance. This pointer is created by @href NewAccess 
 *   with <tt>CATCmdStarter<tt> as <tt>classname</tt> parameter.
 * @param command
 *   The identifier (a CATString) of a @href CATCommandHeader instance.
 *   <pre>
 *   Example:
 *      NewAccess(CATCmdStarter,pMyAccess,"accessname")
 *      SetAccessCommand(pMyAccess,"MyCommandHeaderId") 
 *   </pre>
 */
#define SetAccessCommand(variableName, command) \
CATAfrAccessFactory::SetAccessCommand(variableName, command)

/**
 * Anchors an access before a given access.
 * @param variableName 
 *   The pointer to the access to be anchored
 * @param anchor
 *   The name of the access before which <tt>variableName</tt> is anchored
 *   <pre>
 *   Example: 
 *
 *   In a workshop you write :
 *      NewAccess(CATCmdStarter,pMyAccess1,"accessname1")
 *   
 *   In a workbench you have:
 *      NewAccess(CATCmdStarter,pMyAccess2,"accessname2")
 *      SetAccessAnchorName(pMyAccess2,"accessname1") 
 *
 *      The access whose pointer is pMyAccess2 is anchored before the 
 *      access whose name is accessname1. 
 *   </pre>
 */
#define SetAccessAnchorName(variableName, anchor) \
CATAfrAccessFactory::SetAccessAnchorName((CATCmdAccess*)variableName, anchor)

/**
 * Sets the toolbar style for the workbench.
 * @param variableName 
 *   The pointer to the workbench's instance. This pointer is created by @href NewAccess with
 *   <tt>CATCmdWorkbench</tt> as <tt>classname</tt> parameter.
 * @param style
 *   enum : Icon for toolbars to show icons
 *          Text for toolbars to show text only.
 */
#define SetWorkbenchToolbarStyle(variableName, style) \
CATAfrAccessFactory::SetWorkbenchToolbarStyle(variableName, style)

/**
 * Sets the toolbars exclusive for the workbench. The Global toolbars will not appear.
 * @param variableName 
 *   The pointer to the workbench's instance. This pointer is created by @href NewAccess with
 *   <tt>CATCmdWorkbench</tt> as <tt>classname</tt> parameter.
 */
#define SetWorkbenchToolbarsExclusive(variableName) \
CATAfrAccessFactory::SetWorkbenchToolbarsExclusive(variableName)

/**
 * Merges the addin's menubar with the workbench's menubar.
 * @param variableName 
 *   The pointer to the addin's instance. This pointer is created by @href NewAccess with
 *   <tt>CATCmdContainer</tt> as <tt>classname</tt> parameter.
 * @param menu
 *   The pointer to the menu's instance created by @href NewAccess with 
 *   <tt>CATCmdContainer<tt> as <tt>classname</tt> 
 */
#define SetAddinMenu(variableName, menu) \
CATAfrAccessFactory::SetAddinMenu(variableName, menu)

/**
 * Merges the workbench's menubar with the workshop's menubar.
 * @param variableName 
 *   The pointer to the workbench's instance. This pointer is created by @href NewAccess with
 *   <tt>CATCmdWorkbench</tt> as <tt>classname</tt> parameter.
 * @param menu
 *   The pointer to the menu's instance created by @href NewAccess with 
 *   <tt>CATCmdContainer<tt> as <tt>classname</tt> 
 */
#define SetWorkbenchMenu(variableName, menu) \
CATAfrAccessFactory::SetWorkbenchMenu(variableName, menu)


/**
 * Merges the workshop's menubar with the default menubar.
 * @param variableName 
 *   The pointer to the workshop's instance. This pointer is created by @href NewAccess with
 *   <tt>CATCmdWorkshop</tt> as <tt>classname</tt> parameter
 * @param menu
 *   The pointer to the menu's instance. This pointer is created by @href NewAccess with 
 *   <tt>CATCmdContainer<tt> as <tt>classname</tt> parameter
 */
#define SetWorkshopMenu(variableName, menu) \
CATAfrAccessFactory::SetWorkshopMenu(variableName, menu)


/**
 * Removes a toolbar while in a workbench.
 * Use this macro for each toolbar you want to remove.
 * @param variableName 
 *   The pointer to the workbench instance. This pointer is created by @href NewAccess with
 *   <tt>CATCmdWorkbench</tt> as <tt>classname</tt> parameter
 * @param TbName
 *   The name of the toolbar to remove. For example, setting TbName to Standard will remove the Standard toolbar
 *   while variableName is the current workbench.
 */
#define SetWorkbenchWithoutToolbar(variableName, TbName) \
CATAfrAccessFactory::SetWorkbenchWithoutToolbar(variableName, TbName)


/**
 * Hides a toolbar while in a workbench.
 * Use this macro for each toolbar you want to remove.
 * @param variableName 
 *   The pointer to the workbench instance. This pointer is created by @href NewAccess with
 *   <tt>CATCmdWorkbench</tt> as <tt>classname</tt> parameter
 * @param TbName
 *   The name of the toolbar to hide. For example, setting TbName to Standard will hide the Standard toolbar
 *   while variableName is the current workbench. The user can display the toolbar by using the toolbar list.
 */
#define SetWorkbenchHiddenToolbar(variableName, TbName) \
CATAfrAccessFactory::SetWorkbenchHiddenToolbar(variableName, TbName)

/**
 * @deprecated R422 AccessReleaseAndNull
 *
 * Release an Access.
 * @param variableName 
 *   The pointer to the Access to release.
 */
#define AccessRelease(variableName) \
CATAfrAccessFactory::AccessRelease((CATCmdAccess *)variableName)


/**
 * Release an Access and set to NULL the given pointer.
 * @param variableName 
 *   The pointer to the Access to release.
 */
#define AccessReleaseAndNull(variableName) \
CATAfrAccessFactory::AccessReleaseAndNull((CATCmdAccess * &)variableName)


/**
 * Sets the representation type for an access.
 * @param variableName 
 *   The pointer to the Access to set the representation type.
 * @param RepresentationType 
 *   The representation type.
 */
#define SetAccessRepresentationType(variableName, RepresentationType) \
CATAfrAccessFactory::SetRepresentationType((CATCmdAccess*)variableName,RepresentationType)

/**
 * Creates a container and declares it as the first access of a container.
 * @param fatherName 
 *   The pointer to the container's instance.
 * @param variableName
 *   The pointer to the instance created 
 * @param command
 *   The name of the access. 
 *   or a CATCmdSeparator. 
*/
#define CATMacAddChildContainer(fatherName,variableName,command) \
  NewAccess(CATCmdContainer,variableName,command); \
  SetAccessChild(fatherName,variableName)

/**
 * Creates a container and declares it as the next access of a container.
 * @param previousName 
 *   The pointer to an access instance already chained.
 * @param variableName
 *   The pointer to the instance created 
 * @param command
 *   The name of the access. 
 *   or a CATCmdSeparator. 
*/
#define CATMacAddNextContainer(previousName,variableName,command) \
  NewAccess(CATCmdContainer,variableName,command); \
  SetAccessNext(previousName,variableName)

/**
 * Creates a container and declares it as the first access of a container with anchor before another given access.
 * @param fatherName 
 *   The pointer to the container's instance.
 * @param variableName
 *   The pointer to the instance created 
 * @param command
 *   The name of the access. 
 *   or a CATCmdSeparator. 
 * @param anchorName
 *   The name of the access before which <tt>variableName</tt> is anchored
*/
#define CATMacAddChildContainerA(fatherName,variableName,command,anchorName) \
   NewAccess(CATCmdContainer,variableName,command); \
   SetAccessAnchorName(variableName,anchorName); \
   SetAccessChild(fatherName,variableName)

/**
 * Creates a container and declares it as the next access of a container with anchor before another given access.
 * @param previousName 
 *   The pointer to an access instance already chained.
 * @param variableName
 *   The pointer to the instance created 
 * @param command
 *   The name of the access. 
 *   or a CATCmdSeparator. 
 * @param anchorName
 *   The name of the access before which <tt>variableName</tt> is anchored
 * 
*/
#define CATMacAddNextContainerA(previousName,variableName,command,anchorName) \
   NewAccess(CATCmdContainer,variableName,command); \
   SetAccessAnchorName(variableName,anchorName); \
   SetAccessNext(previousName,variableName)

/**
 * Creates a container and declares it as the first toolbar in the workshop or into the workbench.
 * @param fatherName 
 *   The pointer to the container's instance.
 * @param variableName
 *   The pointer to the instance created 
 * @param object
 *   The name of the access. 
 *   or a CATCmdSeparator. 
 * @param nColumns
 *   The toolbar visibility. 
 * <br><b>Legal values</b>: 1: visible , -1:invisible  
 * @param position
 *   The toolbar's position in the frame.
 * <br><b>Legal values</b>: 
 * <dl>
 * <dt><tt>UnDock</tt>: 
 * <dd>The toolbar is undocked. 
 * <dt><tt>Bottom</tt>: 
 * <dd>The toolbar is docked at the bottom of the application window 
 * <dt><tt>Top</tt>:
 * <dd>The toolbar is docked at the top of the application window
 * <dt><tt>Left</tt>:
 * <dd>The toolbar is docked at the left of the application window
 * <dt><tt>Right</tt>: 
 * <dd>The toolbar is docked at the right of the application window
 * </dl>
 * 
*/
#define CATMacAddChildToolbar(fatherName,variableName,object,nColumns,position) \
  NewAccess(CATCmdContainer,variableName,object); \
  AddToolbarView(variableName,nColumns,position); \
  SetAccessChild(fatherName,variableName)

/**
 * Creates a container and declares it as a next toolbar in the workshop or into the workbench.
 * @param fatherName 
 *   The pointer to the container's instance.
 * @param variableName
 *   The pointer to the instance created 
 * @param object
 *   The name of the access. 
 *   or a CATCmdSeparator. 
 * @param nColumns
 *   The toolbar visibility. 
 * <br><b>Legal values</b>: 1: visible , -1:invisible  
 * @param position
 *   The toolbar's position in the frame.
 * <br><b>Legal values</b>: 
 * <dl>
 * <dt><tt>UnDock</tt>: 
 * <dd>The toolbar is undocked. 
 * <dt><tt>Bottom</tt>: 
 * <dd>The toolbar is docked at the bottom of the application window 
 * <dt><tt>Top</tt>:
 * <dd>The toolbar is docked at the top of the application window
 * <dt><tt>Left</tt>:
 * <dd>The toolbar is docked at the left of the application window
 * <dt><tt>Right</tt>: 
 * <dd>The toolbar is docked at the right of the application window
 * </dl>
 * 
*/
#define CATMacAddNextToolbar(previousName,variableName,object,nColumns,position) \
  NewAccess(CATCmdContainer,variableName,object); \
  AddToolbarView(variableName,nColumns,position); \
  SetAccessNext(previousName,variableName)

/**
 * Creates a separator and declares it as the first separator with anchor before a given access.
 * @param fatherName 
 *   The pointer to the container's instance.
 * @param variableName
 *   The pointer to the instance created 
 * @param anchorName
 *   The name of the access before which <tt>variableName</tt> is anchored
 * 
*/
#define CATMacAddChildSeparatorA(fatherName,variableName,anchorName) \
   NewAccess(CATCmdSeparator,variableName,variableName##Separator); \
   SetAccessAnchorName(variableName,anchorName); \
   SetAccessChild(fatherName,variableName)

/**
 * Creates a separator and declares it as the next separator with anchor before a given access.
 * @param previousName 
 *   The pointer to an access instance already chained.
 * @param variableName
 *   The pointer to the instance created 
 * @param anchorName
 *   The name of the access before which <tt>variableName</tt> is anchored
 * 
*/
#define CATMacAddNextSeparatorA(previousName,variableName,anchorName) \
   NewAccess(CATCmdSeparator,variableName,variableName##Separator); \
   SetAccessAnchorName(variableName,anchorName); \
   SetAccessNext(previousName,variableName)

/**
 * Creates a separator and declares it as the next separator.
 * @param previousName 
 *   The pointer to an access instance already chained.
 * @param variableName
 *   The pointer to the instance created 
 * 
*/
#define CATMacAddNextSeparator(previousName,variableName) \
   NewAccess(CATCmdSeparator,variableName,variableName##Separator); \
   SetAccessNext(previousName,variableName)

/**
 * Creates a starter and declares it as the first access of a container.
 * @param fatherName 
 *   The pointer to the container's instance.
 * @param variableName
 *   The pointer to the instance created 
 * @param object
 *   The name of the access. 
 * @param command
 *   The identifier (a CATString) of a @href CATCommandHeader instance.
 * 
*/
#define CATMacAddChildStarter(fatherName,variableName,object,command) \
  NewAccess(CATCmdStarter,variableName,object); \
  SetAccessCommand(variableName,command); \
  SetAccessChild(fatherName,variableName)

/**
 * Creates a starter and declares it as the next access of a container.
 * @param previousName 
 *   The pointer to an access instance already chained.
 * @param variableName
 *   The pointer to the instance created 
 * @param object
 *   The name of the access. 
 * @param command
 *   The identifier (a CATString) of a @href CATCommandHeader instance.
 * 
*/
#define CATMacAddNextStarter(previousName,variableName,object,command) \
  NewAccess(CATCmdStarter,variableName,object); \
  SetAccessCommand(variableName,command); \
  SetAccessNext(previousName,variableName)

/**
 * Creates a starter and declares it as the first access of a container with anchor before another given access.
 * @param fatherName 
 *   The pointer to the container's instance.
 * @param variableName
 *   The pointer to the instance created 
 * @param object
 *   The name of the access. 
 * @param command
 *   The identifier (a CATString) of a @href CATCommandHeader instance.
 * @param anchorName
 *   The name of the access before which <tt>variableName</tt> is anchored
 * 
*/
#define CATMacAddChildStarterA(fatherName,variableName,object,command,anchorName) \
  NewAccess(CATCmdStarter,variableName,object); \
  SetAccessCommand(variableName,command); \
  SetAccessAnchorName(variableName,anchorName); \
  SetAccessChild(fatherName,variableName)

/**
 * Creates a starter and declares it as the next access of a container with anchor before another given access.
 * @param previousName 
 *   The pointer to an access instance already chained.
 * @param variableName
 *   The pointer to the instance created 
 * @param object
 *   The name of the access. 
 * @param command
 *   The identifier (a CATString) of a @href CATCommandHeader instance.
 * @param anchorName
 *   The name of the access before which <tt>variableName</tt> is anchored
 * 
*/
#define CATMacAddNextStarterA(previousName,variableName,object,command,anchorName) \
  NewAccess(CATCmdStarter,variableName,object); \
  SetAccessCommand(variableName,command); \
  SetAccessAnchorName(variableName,anchorName); \
  SetAccessNext(previousName,variableName)

/**
 * Creates an access and declares it as the next access of a container with anchor before another given access.
 * @param previousName 
 *   The pointer to an access instance already chained.
 * @param variableName
 *   The pointer to the instance created 
 * @param anchorName
 *   The name of the access before which <tt>variableName</tt> is anchored
 * 
*/
#define CATMacAddNextAccessA(previousName,variableName,anchorName) \
   NewAccess(CATCmdAccess,variableName,variableName##Access); \
   SetAccessAnchorName(variableName,anchorName); \
   SetAccessNext(previousName,variableName)

/**
 * Set the given section by its name as active. The active section is the one
 * displayed by the ActionBar.
 *
 * @param i_name
 *   the name of the section to set active. If this name doesn't refer
 *   to a section, nothing happens.
 *
 * The fixed area can't be set as active as it's always displayed.
 */
#define CATMacSetActiveSection(i_name) \
 CATAfrAccessFactory::CATAfrSetActiveSection(#i_name)


/**
 * Get the name of the currently active section (the one displayed by the
 * ActionBar).
 *
 * This macro returns the name of the first section found that is active.
 *
 * To get all the active sections of the ActionBar, prefer using
 * CATMacGetActiveSections macro.
 *
 * @return
 *   the name of the active section.
 */
#define CATMacGetActiveSection() \
 CATAfrAccessFactory::CATAfrGetActiveSection()

/**
 * Get the names of the currently active sections (those displayed by the
 * ActionBar).
 *
 * @param o_activeSections
 *   the names of the active sections.
 */
#define CATMacGetActiveSections(o_activeSections) \
 CATAfrAccessFactory::CATAfrGetActiveSections(o_activeSections)

/**
 * Set the given weight to the given access.
 *
 * <b>Role</b>: By default, access objects have a weight of 1.0.
 * The weight is used only for CATCmdStarter to be displayed in secondary
 * area of the ActionBar. To display a CATCmdStarter object in secondary
 * area, you to call this macro on the starter object giving 0.f as weight.
 *
 * @param variableName
 *   The pointer to a CATCmdAccess's instance. This pointer is created by @href NewAccess 
 *   with <tt>CATCmdStarter<tt> as <tt>classname</tt> parameter.
 *
 * @param weight
 *   The new weight to associate to the given access. To be put in secondary area of the
 *   Action Bar, 0.f must be given.
 */
#define SetAccessWeight(variableName, weight) \
  CATAfrAccessFactory::SetAccessWeight((CATCmdAccess*)variableName, weight)

/**
 * @nodoc
 * obsolete, does nothing.
 * To remove a workbench from the Start menu, set its Transient resource to TRUE.
*/
//#define SetWorkbenchTransient(variableName, transient) \
//  variableName -> SetTransient (transient)
  
/**
 * @nodoc
 * obsolete, does nothing.
*/
//#define SetWorkbenchPriority(variableName, priority) \
//  variableName -> SetPriority(priority)
  
/**
 * @nodoc
 * Do not use, use a CATRsc resource file instead
*/
//#define SetAccessIconName(variableName, icon) \
//  variableName -> SetIconName(icon)
  
/**
 * @nodoc
 * Do not use, use a CATNls resource file instead
*/
//#define SetAccessTitle(variableName, title) \
//  variableName -> SetTitle(title)
 
/**
 * @nodoc
 * Do not use, use a CATNls resource file instead
*/
//#define SetAccessCustomerName(variableName, customerName) \
//  variableName -> SetCustomerName(customerName)

/**
 * @nodoc
 * Do not use, use a CATNls resource file instead
*/
//#define SetAccessMnemonic(variableName, mnemonic) \
//  variableName -> SetMnemonic(mnemonic)
