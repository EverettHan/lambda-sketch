#ifndef _CATPreactivate
#define _CATPreactivate

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that a manipulated object is surrounded by
// ----------   the mouse
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATPreactivate
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------


#include "CATManipulatorNotification.h"

#include "CATVisFoundation.h"

/**
 * Class to notify the preselection of the representation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates
 * that the mouse intersects the representation controlled by the manipulator.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATPreactivate : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATPreactivate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATPreactivate(CATNotification *iNotification);
    virtual ~CATPreactivate();

};

#endif
