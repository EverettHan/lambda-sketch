//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2019
//-----------------------------------------------------------------------------
#pragma once

/**
 * The following tables give the atomic type/id associated with the Hololens
 * device components
 *
 * Notes:
 *
 * - The feft/right Pointer is the hand ray. It is positioned at the wrist,
 *   oriented according to the shoulder.
 *
 *
 *  HMD              : type      : atomic ID
 * -----------------------------------------
 * Pose              : tracker   : 0
 *
 *  Left Pointer     : type      : atomic ID
 * -----------------------------------------
 *  Pose             : tracker   : 2
 *
 *  Press            : button    : 8
 *  Grab             : button    : 9
 *
 *  Right Pointer    : type      : atomic ID
 * -----------------------------------------
 *  Pose             : tracker   : 1
 *
 *  Press            : button    : 0
 *  Grab             : button    : 1
 */
namespace IVHololens
{
  enum Tracker {
    
    tHMD              = 0,
    
    //
    tPointerRight     = 1, 
    tPointerLeft      = 2,

    //
    tUndef            = 0xFFFF
  };

  enum Button {
    
    //
    bPointerRight     = 0,
    bPointerRightGrab = 1,
    
    //
    bPointerLeft      = 8,
    bPointerLeftGrab  = 9,
    
    //
    bUndef            = 0xFFFF
  };
}


