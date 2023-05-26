#ifndef _CATEndEdit
#define _CATEndEdit

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that an object quit its edit state
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator. 
// ------       the edit state of a manipulator is valuated when a CATPopup 
//              instance is associated to the manipulator at edit time
//              ( method SetEditPopup ) . Until this popup instance exists,
//              the manipulator is in edit state. When it is quit (ok or cancel)//              the popup is destroyed by manipulator and an instance of
//              CATEndEdit notification is send to application.
//
//------------------------------------------------------------------------------
// Class :      CATEndEdit
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATManipulatorNotification.h"


/**
 * Class to notify the end of editing task.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates
 * that the edit state is quit and the edit panel is destroyed.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATEndEdit : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATEndEdit notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATEndEdit(CATNotification *iNotification);
    virtual ~CATEndEdit();
    
};

#endif
