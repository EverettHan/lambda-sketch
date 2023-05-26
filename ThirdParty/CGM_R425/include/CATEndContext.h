#ifndef _CATEndContext
#define _CATEndContext

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that the contextual ask on an object is ended
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATEndContext
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATManipulatorNotification.h"


/**
 * Class to notify the end of context task.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates 
 * that the mouse button 3 is released or the callback task is ended.
 * The items of the context menu are automatically destroyed when
 * this notification is sent.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATEndContext : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATEndContext notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATEndContext(CATNotification *iNotification);
    virtual ~CATEndContext();
    
};

#endif
