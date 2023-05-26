#ifndef _CATContext
#define _CATContext

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that contextual behavior is asked 
// ----------   on an object
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATContext
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATManipulatorNotification.h"

class CATDlgContextualMenu;

/**
 * Class to notify that a contextual action is asked on a manipulator.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates 
 * that the mouse button 3 is pressed above the representation
 * controlled by the manipulator.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATContext : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATContext notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 * @param menu 
 *   The associated context menu.
 */
    CATContext(CATNotification *iNotification, CATDlgContextualMenu *menu=NULL);
    virtual ~CATContext();
    
/**
 * Returns the associated context menu. An application can subscribe to
 * this notfication to put specific items in the context menu associated
 * to manipulator. The contextual menu is specific to each manipulator and
 * is redefined each time a contextual action is asked on a manipulator.
 */
    CATDlgContextualMenu *GetContextualMenu() const;

    protected:
    CATDlgContextualMenu	*_menu;

};

#endif
