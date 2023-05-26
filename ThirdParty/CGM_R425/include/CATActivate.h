#ifndef _CATActivate
#define _CATActivate

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that an object has been selected.
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------        
//
//------------------------------------------------------------------------------
// Class :      CATActivate
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATManipulatorNotification.h"
#include "CATVisFoundation.h"


/**
 * Class to notify the selection of the representation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates 
 * that the mouse button 1 is pressed above the representation
 * controlled by the manipulator.
 * It can be received by any <tt> CATCommand</tt> class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATActivate : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATActivate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATActivate(CATNotification *iNotification);
    virtual ~CATActivate();
    
};

#endif
