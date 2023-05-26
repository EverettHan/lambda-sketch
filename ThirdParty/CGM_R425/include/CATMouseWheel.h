#ifndef CATMouseWheel_H
#define CATMouseWheel_H

// COPYRIGHT DASSAULT SYSTEMES 2001

//
// CATIA Version 5 Release 8
// Copyright Dassault Systemes 2001
//------------------------------------------------------------------------------
// Abstract :   defines the fact that the mouse is moving on a representation
// ----------   controlled by a manipulator
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :    CATMouseWheel
// -------      CATManipulatorNotification
//                CATVueNotification
//                  CATNotification
//------------------------------------------------------------------------------

#include "CATManipulatorNotification.h"
#include "CATVisFoundation.h"

/**
 * Class to notify the mouse movement above the representation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates
 * that the mouse is moving above the representation controlled by the manipulator.
 * It can be received by any @href CATCommand class by means of 
 * @href #AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATMouseWheel : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATMouseWheel notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position and move vector.
 */
    CATMouseWheel(CATNotification *iNotification);
    virtual ~CATMouseWheel();
    
};

#endif
