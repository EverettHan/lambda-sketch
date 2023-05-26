#ifndef CATAfrAccessFactory_H
#define CATAfrAccessFactory_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"

#include "CATString.h"
#include "CATCollec.h"

class CATCmdAccess;
class CATCmdContainer;
class CATCmdSeparator;
class CATCmdStarter;
class CATCmdWorkbench;
class CATCmdWorkshop;

class ExportedByCATAfrFoundation CATAfrAccessFactory
{

public:

  /** 
  * Position of the toolbar in the application window.
  * @param CATAfrUnDock 
  *   The toolbar is undocked. 
  * @param CATAfrBottom  
  *   The toolbar is docked at the bottom of the application window 
  * @param CATAfrTop 
  *   The toolbar is docked at the top of the application window
  * @param CATAfrLeft 
  *   The toolbar is docked at the left of the application window
  * @param CATAfrRight 
  *   The toolbar is docked at the right of the application window
  * @param CATAfrCompassWest 
  *   The toolbar is docked on the west side of the compass
  */
  enum ComponentPosition { CATAfrTop, CATAfrBottom, CATAfrLeft, CATAfrRight, CATAfrUnDock, CATAfrCompassWest };

/**
 * Defines the button representation in the toolbars.
 * @param Icons
 *  Each button in all toolbars of the workbench are represented by an icon.
 * <br>Icons are defined in the CATRsc file of the header.  
 * @param Text
 *  Each button in all toolbars of the workbench are represented by a text. 
 *  <br>The text is the title of the button. See the CATNls file of the header.
 */
  enum CATAfrToolbarStyleDef {Icons, Text};
  
  
/**
 * Creates an access.
 * Use macro defined in CATCreateWorkshop.h 
 */
  static CATCmdAccess* NewAccess(CATString className, CATString objectName);

/**
 * Adds a view to a CATCmdContainer object
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void AddToolbarView(CATCmdContainer *variableName, int visibility, enum ComponentPosition position);

/**
 * Sets the following access...
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetAccessNext(CATCmdAccess *variableName, CATCmdAccess* nextName);

/**
 * Defines the child of an access
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetAccessChild(CATCmdContainer *variableName, CATCmdAccess* childName);

/**
 * Adds a child to an access
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void AddAccessChild(CATCmdContainer *variableName, CATCmdAccess* childName);

/**
 * Defines the access command...
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetAccessCommand(CATCmdStarter *variableName, CATString command);

/**
 * Defines the anchor name for an access
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetAccessAnchorName(CATCmdAccess *variableName, CATString anchor);

/**
 * Defines toolbar's style for an access...
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetWorkbenchToolbarStyle(CATCmdWorkbench *variableName, CATAfrToolbarStyleDef style);

/**
 * Sets the toolbars for an access to be exclusive....
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetWorkbenchToolbarsExclusive(CATCmdWorkbench *variableName);

/**
 * Sets an addinmenu for the access
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetAddinMenu(CATCmdContainer *variableName, CATCmdContainer* menu);

/**
 * Sets a menu for the workbench
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetWorkbenchMenu(CATCmdContainer *variableName, CATCmdContainer* menu);

/**
 * Sets a menu for the workshop
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetWorkshopMenu(CATCmdContainer *variableName, CATCmdContainer* menu);

/**
 * Removes a toolbar while in a workbench.
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetWorkbenchWithoutToolbar(CATCmdWorkbench *variableName, CATString TbName);

/**
 * Hides a toolbar while in a workbench.
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetWorkbenchHiddenToolbar(CATCmdWorkbench *variableName, CATString TbName);

  /**
 * Releases an existing Access object.
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void AccessRelease(CATCmdAccess *variableName);

  /**
   * Releases an existing Access object and set its pointer to NULL.
   * Use macro defined in CATCreateWorkshop.h 
   */
  static void AccessReleaseAndNull(CATCmdAccess * & variableName);


 /**
 * Sets the representation type for an access.
 * Use macro defined in CATCreateWorkshop.h 
 */
  static void SetRepresentationType(CATCmdAccess *variableName, CATString RepresentationType);

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
  static void CATAfrSetActiveSection(const CATString & i_name);

  /**
   * Get the name of the currently active section (the one displayed by the
   * ActionBar).
   * This function returns the name of the first section found that is active.
   *
   * To get all the active sections of the ActionBar, prefer using
   * CATAfrGetActiveSections function.
   *
   * @return
   *   the name of the active section.
   */
  static CATString CATAfrGetActiveSection();

  /**
   * Get the name of the currently active sections (those displayed by the
   * ActionBar).
   *
   * @param o_activeSections
   *   the names of the active sections.
   */
  static void CATAfrGetActiveSections(CATListOfCATString & o_activeSections);

  /**
   * Set the access weight.
   *
   * @param i_pAccess
   *   the CATCmdAccess object on which to set the weight.
   *
   * @param i_weight
   *   the weight value to associate to the given CATCmdAccess object.
   */
  static void SetAccessWeight(CATCmdAccess * i_pAccess, float i_weight);

};

#endif
