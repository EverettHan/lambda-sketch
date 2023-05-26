#ifndef CATDIALOGPROTECTED_H
#define CATDIALOGPROTECTED_H

#include "CATBoolean.h"

#include "DI0PANV2.h"
#include "CATDialog.h"
#include "CATBoolean.h"

class CATDlgDialog;
class CATNotification;

#include "CATUnicodeString.h"
#include "CATCallbackManager.h"
#include "CATListPV.h"

class ExportedByDI0PANV2 CATDialogProtected
{
  public :
  static CATUnicodeString GetInputText(CATDialog* dia);
  static void Deletion(CATDialog* dia);
  static void PartialUpdate(CATDialog* dia);

  /**
   * @deprecated R421 Use the second GetCursorImage method
   *
   * Retrieves the image of a Dialog object current cursor
   * @param iDia
   *  the dialog object.
   * @param oWidth
   *  image width in pixels
   * @param oHeight
   *  image height in pixels
   * @param oXspot
   * The x coordinate of the hot spot.
   * @param oYspot
   * The y coordinate of the hot spot.
   * @param oImage
   *  address of the pixels. Dimension is 4*oWidth*oHeight. The pixels are in RGBA format.
   *  Allocated by the callee. To be deallocated by the caller through delete [].
   *  NULL if no cursor defined at the level of the object or if defined through image file.
   * @param oFilePath
   *  when the cursor was defined through the specification of an image file name, complete file path of this image.
   *  empty string otherwise.
   *  When the string is not empty, then oWidth and oHeight are equal to 0 and oImage is equal to NULL.
   *
   */ 
  static void GetCursorImage(CATDialog* iDia, int& oWidth, int& oHeight, int& oXspot, int& oYspot, unsigned char*& oImage, CATUnicodeString& oFilePath);

  /**
   * Retrieves the image of the current cursor of a Dialog object
   * @param iDialog the dialog object
   * @param oWidth the image width in pixels
   * @param oHeight the image height in pixels
   * @param oXspot the x coordinate of the hot spot.
   * @param oYspot the y coordinate of the hot spot.
   * @param oImage the image RGBA buffer (its size is 4*oWidth*oHeight, it is allocated by the callee and must be deallocated by the caller with delete [])
   */
  static void GetCursorImage(CATDialog * iDialog, int& oWidth, int& oHeight, int& oXspot, int& oYspot, unsigned char *& oImage);

  static CATNotification* GetCursorDefinitionChangedNotification(CATDialog* iDia);

  /**
   * Hides the mouse cursor inside a Dialog object. 
   *
   * @param iDia
   *  the dialog object.
   *
   * In the current implementation, if cursor is hidden for at least one Dialog object, then busy cursor management is inhibited for the whole application.
   */ 
  static void HideCursor(CATDialog* iDia);

  /**
   * Restores the mouse cursor inside a Dialog object. 
   *
   * @param iDia
   *  the dialog object.
   *
   *
   */ 
  static void RestoreCursor(CATDialog* iDia);

  /**
   * Declares the CursorDefinitionChanged event.
   * <br><b>Role</b>
   * This event is sent through DispatchCallbacks by the @href CATDialog whenever the definition of its cursor changes.
  */
  CATDeclareCBEvent(CursorDefinitionChanged);
  
  #define CATDLGMULTITOUCHRIGHTHANDED 1
  #define CATDLGMULTITOUCHLEFTHANDED  2

  #define CATDLGMULTITOUCHSETTINGREPOSITORY "IVInteractions"
  #define CATDLGSENSORIALUSERSETTINGREPOSITORY "IVSensorialUser"
  #define CATDLGMULTITOUCHACTIVATIONSETTINGNAME "MultiTouch"
  #define CATDLGSENSORIALUSERDOMINANTHANDSETTINGNAME "DominantHand"

  /**
   * Returns the MultiTouch configuration
   * <br>
   * The MultiTouch configuration can be :
   * <dl>
   * <dt><tt>0</tt><dd> MultiTouch is not activated.
   * <dt><tt>CATDLGMULTITOUCHRIGHTHANDED</tt><dd> MultiTouch is activated and dominant hand is the right one.
   * <dt><tt>CATDLGMULTITOUCHLEFTHANDED</tt><dd> MultiTouch is activated and dominant hand is the left one.
   * </dl>
   * <br>
   * This configuration can be set by two ways.
   *
   * 1 - Through environment variable "CATTouchInteraction"
   *     If its value is "1" or "righthanded", then MultiTouch configuration is CATDLGMULTITOUCHRIGHTHANDED 
   *     If its value is "2" or "lefthanded",  then MultiTouch configuration is CATDLGMULTITOUCHLEFTHANDED
   *     Other values are ignored.
   *
   * 2 - With lower priority, through settings.
   *     Please ref to "Tools+Options" + "General/Immersive Virtuality" section, "Interactions" and "Sensorial user" tabs. 
   */
   static int IsMultiTouch();

   static CATNotification* GetTitleChangedNotification(CATDialog* iDia);

   // SCA : From l_CATDlgBmp
   static CATBoolean PngPriorityOnBmp();

   static void LimitedRefresh(CATDialog* iDia); // DBE July 2014 Provisional . Should be removed for R2016

   static void DontDisplayNextContextualMenu(CATDialog* iDia);      // DBE June 2015. For exclusive usage of ApplicationFrame
   static void VirtuallyCloseCurrentContextualMenu(CATDialog* iDia);// DBE June 2015. For exclusive usage of ApplicationFrame

  /**
   * @deprecated R422 Use GetScreenPositionEx
   * Get the screen position of a dialog object
   * @param iDialog the dialog object.
   * @param oX the X position in pixels
   * @param oY the Y position in pixels
   */
  static void GetScreenPosition(CATDialog * iDialog, int& oX, int& oY);

  /**
   * Get the screen position of a dialog object
   * @param iDialog the dialog object.
   * @param oX the X position in pixels
   * @param oY the Y position in pixels
   * @param iAlreadyScaled specifies if oX, oY must respect the current display scaling
   * When FALSE, oX, oY coordinates will match a 100% display scaling
   * When TRUE, oX, oY coordinates will match the current display scaling
   */
  static void GetScreenPositionEx(CATDialog * iDialog, int& oX, int& oY, CATBoolean iAlreadyScaled);

  /**
   * @deprecated R422 Use IsPartiallyOrTotallyHiddenEx
   * - Windows only -
   * Check if a specific area is hidden by another dialog popup window.
   * @param iDialog the main dialog object (that must not be taken into account in the computing of the potential conflict with the given area)
   * @param iAbsoluteLeft, iAbsoluteTop the absolute area position
   * @param iWidth, iHeight the area size
   * @param oOverlappingDialogs the list of hidden dialogs
   * @return 1 if the area is hidden or partially hidden, 0 otherwise
   */
  static int IsPartiallyOrTotallyHidden(CATDialog * iDialog, int iAbsoluteLeft, int iAbsoluteTop, int iWidth, int iHeight, CATListPV& oOverlappingDialogs);

  /**
   * - Windows only -
   * Check if a specific area is hidden by another dialog popup window.
   * @param iDialog the main dialog object (that must not be taken into account in the computing of the potential conflict with the given area)
   * @param iAbsoluteLeft, iAbsoluteTop the absolute area position
   * @param iWidth, iHeight the area size
   * @param iAlreadyScaled specifies if position and size respect the current display scaling
   * When FALSE, position and size must match a 100% display scaling, they will be automatically scaled according to current display scaling
   * When TRUE, position and size must match the current display scaling, they won't be scaled
   * @param oOverlappingDialogs the list of hidden dialogs
   * @return 1 if the area is hidden or partially hidden, 0 otherwise
   */
  static int IsPartiallyOrTotallyHiddenEx(CATDialog * iDialog, int iAbsoluteLeft, int iAbsoluteTop, int iWidth, int iHeight, CATBoolean iAlreadyScaled, CATListPV& oOverlappingDialogs);
};

#endif
