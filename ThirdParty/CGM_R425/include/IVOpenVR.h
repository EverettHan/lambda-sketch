//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVOpenVR_H
#define IVOpenVR_H

/**
 * The following tables give the atomic type/id associated with the openVR
 * device components
 *
 *  HMD              : type      : atomic ID
 * -----------------------------------------
 * Pose              : tracker   : 0
 *
 * Proximity sensor  : button    : 31
 *
 *  Right controller : type      : atomic ID
 * -----------------------------------------
 *  Pose             : tracker   : 1
 *
 *  System           : button    : 0
 *  Menu             : button    : 1
 *  Grip             : button    : 2
 *  Touchpad         : button    : 3
 *  Trigger          : button    : 4
 *
 *  Touchpad Horiz   : analog    : 0
 *  Touchpad Vert    : analog    : 1
 *  Trigger          : analog    : 2
 *  Stick Horiz      : analog    : 3
 *  Stick Vert       : analog    : 4
 *
 *
 *  Left controller  : type      : atomic ID
 * -----------------------------------------
 *  Pose             : tracker   : 2
 *
 *  System           : button    : 8
 *  Menu             : button    : 9
 *  Grip             : button    : 10
 *  Touchpad         : button    : 11
 *  Trigger          : button    : 12
 *
 *  Touchpad Horiz   : analog    : 10
 *  Touchpad Vert    : analog    : 11
 *  Trigger          : analog    : 12
 *  Stick Horiz      : analog    : 13
 *  Stick Vert       : analog    : 14
 */
namespace IVOpenVR
{
  enum Tracker {
    // HMD
    tHMD             = 0,

    // Right
    tControllerRight = 1,

    // Left
    tControllerLeft  = 2,

    //Left Eyet
    tEyeLeft         = 3,

    //Right Eye
    tEyeRight        = 4,

    //Stylus
    tStylus          = 5,

    tUndef           = 0xFFFF
  };

  enum Button {

    // HMD
    bProximity       = 31,

    // Right
    bSystemRight     = 0,
    bMenuRight       = 1,
    bGripRight       = 2,
    bTouchpadRight   = 3,
    bTriggerRight    = 4,
    bThumbstickRight = 5, // eg. Oculus
    bARight          = 6, // eg. Oculus
    bBRight          = 7, // eg. Oculus

    // Left
    bSystemLeft      = 8,
    bMenuLeft        = 9,
    bGripLeft        = 10,
    bTouchpadLeft    = 11,
    bTriggerLeft     = 12,
    bThumbstickLeft  = 13, // eg. Oculus
    bXLeft           = 14, // eg. Oculus
    bYLeft           = 15, // eg. Oculus


    // Stylus
    bTip             = 20,
    bPrimary         = 21,
  };

  enum Analog {

    // Right
    aTouchpadXRight  = 0,
    aTouchpadYRight  = 1,
    aTriggerRight    = 2,
    aStickXRight     = 3,  // eg. Oculus
    aStickYRight     = 4,  // eg. Oculus
    aGripRight       = 5,  // eg. Oculus

    // Left
    aTouchpadXLeft   = 10,
    aTouchpadYLeft   = 11,
    aTriggerLeft     = 12,
    aStickXLeft      = 13,  // eg. Oculus
    aStickYLeft      = 14,  // eg. Oculus
    aGripLeft        = 15,  // eg. Oculus

    // Stylus
    aTip             = 20,
    aPrimary         = 21,
    aGrip            = 22,
  };
}


#endif
