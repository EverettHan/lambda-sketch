//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVSUIHmdScenarioKey_H
#define IVSUIHmdScenarioKey_H

#include "IVInterfaces.h"

#include "CATUnicodeString.h"


//=============================================================================
/**
 * IVAmbianceMode
 */
enum IVAmbianceMode {
  IV_NATURAL_AMBIANCE,
  IV_DESIGNER_AMBIANCE
};

//=============================================================================
/**
 * IVGroundMode
 */
enum IVGroundMode {
  IV_NATURAL,
  IV_DESIGNER,
};

//=============================================================================
/**
 * IVGroundHeightMode
 */
enum IVGroundHeightMode {
  IV_GROUND_MANUAL_DEFINITION,
  IV_GROUND_ON_MODEL_MINIMUM
};

//=============================================================================
/**
 * IVNavigationMode
 */
enum IVNavigationMode {
  IV_NAV_NONE,
  IV_NAV_EXAMINE,
  IV_NAV_FLY,
  IV_NAV_WALK,
  IV_NAV_TELEPORT,
};


//=============================================================================
/**
 * IVNavigationMode
 */
enum IVGIVisualizeMode {
  IV_GI_TV,
  IV_GI_IMMERSIVE,
};

//=============================================================================
/**
 * IVSUIHmdScenarioKey
 */
struct ExportedByIVInterfaces IVSUIHmdScenarioKey
{
  static CATUnicodeString const HMDTYPE;                // value: CATUnicodeString, see IVDeviceFamily
  static CATUnicodeString const HMDREALITYTYPE;         // value: int 0 IV_VIRTUAL_REALITY, 1 IV_AUGMENTED_REALITY
  static CATUnicodeString const IPD;                    // value: double
  static CATUnicodeString const USERSIZE;               // value: double
  static CATUnicodeString const SPEED;                  // value: double
  static CATUnicodeString const NAVMODE;                // value: int: 0 NONE, 1 FLY, 2 WALK, 3 TELEPORT
  static CATUnicodeString const GROUNDMODE;                // value: int: 0 NATURAL, 1 DESIGNER, 2 CAMERA
  static CATUnicodeString const GROUNDAXIS;                // value: CATMathVector
  static CATUnicodeString const GROUNDHEIGHTMODE;          // value: int: 0 AUTOMATIC, 1 MANUAL
  static CATUnicodeString const GROUNDHEIGHT;              // value: double
  static CATUnicodeString const AMBIANCEMODE;              // value: int: 0 NATURAL, 1 DESIGNER
  static CATUnicodeString const SCALE;                     // value: double
  static CATUnicodeString const ICSCALE;                   // value: double
  static CATUnicodeString const DISABLEMASTERRENDERING;    // value: int
  static CATUnicodeString const DISABLEMIRRORWINDOW;       // value: int
  static CATUnicodeString const DISABLEPREHIGHLIGHT;       // value: int
  static CATUnicodeString const DISABLEHIGHLIGHT;          // value: int
  static CATUnicodeString const ENABLEGROUNDLOCK;          // value: int
  static CATUnicodeString const PRODUCTEXPLORE;            // value: int
  static CATUnicodeString const HUMANAVATAR;               // value: int
  static CATUnicodeString const ISWOMAN;                   // value: int
  static CATUnicodeString const AVATARHEIGHT;              // value: double
  static CATUnicodeString const DISPLAYCONTROLLERS;        // value: int
  static CATUnicodeString const DISPLAYGENERICTRACKERS;    // value: int
  static CATUnicodeString const DISPLAYANALOGFEEDBACK;     // value: int
  static CATUnicodeString const GICAPTURE;
  static CATUnicodeString const GIVISUALIZEMODE;
  static CATUnicodeString const CAMERASTYPE;               // value: int
  static CATUnicodeString const ENABLEDCAMERASLIST;        // value: CATListOfCATUnicodeString    

  //:FIXME: Make clients migrate and delete this key
  static CATUnicodeString const DISABLENAVIGATIONTEXTURE;  // value: int
};

#endif
