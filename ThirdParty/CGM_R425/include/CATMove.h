#ifndef _CATMove
#define _CATMove

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that the mouse is moving on a representation
// ----------   controlled by a manipulator
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATMove
// -------        CATVueNotification
//                  CATNotification
//------------------------------------------------------------------------------

#include "CATManipulatorNotification.h"
#include "CATVisFoundation.h"

/**
 * Class to notify the mouse movement above the representation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates
 * that the mouse is moving above the representation controlled by the manipulator.
 * It can be received by any @href CATCommand class by means of 
 * @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATMove : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATMove notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position and move vector.
 */
    CATMove(CATNotification *iNotification);
    virtual ~CATMove();
    
};

#endif
