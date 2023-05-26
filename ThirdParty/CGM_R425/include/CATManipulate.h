#ifndef _CATManipulate
#define _CATManipulate

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines manipulation time
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator to notify a manipulation state
//
//------------------------------------------------------------------------------
// Class :      CATManipulate
// -------        CATManipulatorNotification
//                  CATNotification
//
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATManipulatorNotification.h"

/**
 * Class to notify the progress of manipulation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates
 * that the manipulation is in progress.
 * It can be received by any @href CATCommand class by means of 
 * @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATManipulate : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATManipulate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position and move vector.
 */
    CATManipulate(CATNotification *iNotification);
    virtual ~CATManipulate();
    
};

#endif
