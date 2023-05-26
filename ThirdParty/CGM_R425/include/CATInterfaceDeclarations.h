/* -*-c++-*- */

///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT DASSAULT SYSTEMES  1996                                         //
/** 
  * @level Protected
  * @usage U1
*/
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************
// ========================================================================= //
//                                                                           //
// No class declared inside                                                  //
//                                                                           //
// ========================================================================= //
// Usage Notes:                                                              //
//                                                                           //
// set of global declarations for ObjectModeler FrameWorks                   //
// ========================================================================= //
// Nov. 96   Creation                                   J-L MALAVAL          //
///////////////////////////////////////////////////////////////////////////////

#ifndef CAT_INTERFACES_DECLARATIONS_H
#define CAT_INTERFACES_DECLARATIONS_H

// --------------------------------------------------------------------------
//                           Macro definitions 
// --------------------------------------------------------------------------
#define InterfaceMode

#include "CATMacForInterfaces.h"
#include "assert.h"

// --------------------------------------------------------------------------
//                         Exception managements
// --------------------------------------------------------------------------

#include "CATObjectModelerError.h"


// --------------------------------------------------------------------------
//                             NULL VALUES
// --------------------------------------------------------------------------

#ifndef NULL
#define NULL  0
#endif

// --------------------------------------------------------------------------
//                            LOGICAL CONSTANTS
// --------------------------------------------------------------------------

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


#endif









