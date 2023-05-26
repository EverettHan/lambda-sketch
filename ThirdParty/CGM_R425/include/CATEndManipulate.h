#ifndef _CATEndManipulate
#define _CATEndManipulate

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the end of drag action on an object.
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator when mouse (or spaceball) is released
// ------       at the end of a manipulation.
//
//------------------------------------------------------------------------------
// Class :      CATEndManipulate
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATManipulatorNotification.h"

/**
 * Class to notify the end of manipulation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates 
 * the end of the manipulation.
 * It can be received by any @href CATCommand class by means of 
 * @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATEndManipulate : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATEndManipulate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position and move vector.
 */
    CATEndManipulate(CATNotification *iNotification);
    virtual ~CATEndManipulate();
    
};

#endif
