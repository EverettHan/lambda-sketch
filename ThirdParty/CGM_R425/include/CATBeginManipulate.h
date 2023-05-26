#ifndef _CATBeginManipulate
#define _CATBeginManipulate

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that an object is taken for drag
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATBeginManipulate
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATManipulatorNotification.h"

/**
 * Class to notify the begining of manipulation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates 
 * the begining of the manipulation.
 * It can be received by any @href CATCommand class by means of 
 * @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATBeginManipulate : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATBeginManipulate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position and move vector.
 */
    CATBeginManipulate(CATNotification *iNotification);
    virtual ~CATBeginManipulate();
    
};

#endif
