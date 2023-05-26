/**************************************************************************************************/
/**************************************************************************************************/
/*                                                                                                */
/*         WARNING - THIS FILE IS IDENTICAL BETWEEN V5 AND V6 - PLEASE KEEP IT IDENTICAL          */
/*                                                                                                */
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef DialogAPILevel_H
#define DialogAPILevel_H

#include "CATIAV5Level.h"

/**
 * Following macros lets customize behavior according to software level
 *
 * DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_COLOR               Popup dialogs background is customized with a color
 * DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_TILED       Popup dialogs background is customized with a texture bitmap, this bitmap is tiled on right
 * DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_STRETCHED   Popup dialogs background is customized with a texture bitmap, this bitmap is stretched in the middle
 * DialogAPI_POPUP_WITH_OK_CANCEL_APPLY_DIODES                Popup dialogs predefined buttons (OK, CANCEL and APPLY) are displayed with a diode
 * DialogAPI_POPUP_WITH_CUSTOM_DEFAULT_BUTTON                 Popup dialogs default predefined button has a custom background
 * DialogAPI_MENU_ITEMS_WITH_CUSTOM_BACKGROUND                Menu items background is customized with a bitmap or a gradient
 * DialogAPI_PNG_OLD_SUPPORT                                  PNG support is available with old api (YR3)
 * DialogAPI_PNG_PRIORITY                                     PNG has priority over BMP
 * DialogAPI_TOUCH_SUPPORT                                    Touch support is available
 * DialogAPI_LOGO_IN_BOTTOM_TOOLBAR                           Logo is displayed in the bottom toolbar
 * DialogAPI_DECLARATIVE_DIALOG_SUPPORT                       Declarative Dialog is available
 * DialogAPI_CIDFRAME_SUPPORT                                 CID Frame is available
 * DialogAPI_LOOK_P1_P2_P3_SUPPORT                            Look P1,P2,P3 are available
 */

// V6 '3D Experience'
#if defined (CATIAR214)
  #define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_COLOR
  //#define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_TILED
  //#define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_STRETCHED
  //#define DialogAPI_POPUP_WITH_OK_CANCEL_APPLY_DIODES
  #define DialogAPI_POPUP_WITH_CUSTOM_DEFAULT_BUTTON
  //#define DialogAPI_MENU_ITEMS_WITH_CUSTOM_BACKGROUND
  #define DialogAPI_PNG_OLD_SUPPORT
  #define DialogAPI_PNG_PRIORITY
  #define DialogAPI_TOUCH_SUPPORT
  //#define DialogAPI_LOGO_IN_BOTTOM_TOOLBAR
  #if defined (_WINDOWS_SOURCE) || defined (_LINUX_SOURCE)
  #define DialogAPI_DECLARATIVE_DIALOG_SUPPORT
  #endif // _WINDOWS_SOURCE
  #ifdef CATIAR419
  #define DialogAPI_CIDFRAME_SUPPORT
  #endif
  //#define DialogAPI_LOOK_P1_P2_P3_SUPPORT

// V6 'classic'
#elif defined (CATIAR212)
  //#define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_COLOR
  //#define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_TILED
  #define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_STRETCHED
  //#define DialogAPI_POPUP_WITH_OK_CANCEL_APPLY_DIODES
  #define DialogAPI_POPUP_WITH_CUSTOM_DEFAULT_BUTTON
  //#define DialogAPI_MENU_ITEMS_WITH_CUSTOM_BACKGROUND
  #define DialogAPI_PNG_OLD_SUPPORT
  #define DialogAPI_PNG_PRIORITY
  #define DialogAPI_TOUCH_SUPPORT
  //#define DialogAPI_LOGO_IN_BOTTOM_TOOLBAR
  //#define DialogAPI_DECLARATIVE_DIALOG_SUPPORT
  //#define DialogAPI_CIDFRAME_SUPPORT
  //#define DialogAPI_LOOK_P1_P2_P3_SUPPORT

// V5
#else
  //#define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_COLOR
  #define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_TILED
  //#define DialogAPI_POPUP_WITH_CUSTOM_BACKGROUND_TEXTURE_STRETCHED
  #define DialogAPI_POPUP_WITH_OK_CANCEL_APPLY_DIODES
  //#define DialogAPI_POPUP_WITH_CUSTOM_DEFAULT_BUTTON
  #define DialogAPI_MENU_ITEMS_WITH_CUSTOM_BACKGROUND
  //#define DialogAPI_PNG_OLD_SUPPORT
  //#define DialogAPI_PNG_PRIORITY
  //#define DialogAPI_TOUCH_SUPPORT
  #define DialogAPI_LOGO_IN_BOTTOM_TOOLBAR
  //#define DialogAPI_DECLARATIVE_DIALOG_SUPPORT
  //#define DialogAPI_CIDFRAME_SUPPORT
  #define DialogAPI_LOOK_P1_P2_P3_SUPPORT

#endif

#endif
