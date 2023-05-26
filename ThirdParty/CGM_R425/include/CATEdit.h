#ifndef _CATEdit
#define _CATEdit

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that an object is asked to be edited.
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATEdit
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATManipulatorNotification.h"
#include "CATVisFoundation.h"

class CATDlgWindow;

/**
 * Class to notify the mouse double click of the representation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates
 * that the button 1 of the mouse is double clicked above
 * the representation controlled by the manipulator.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATEdit : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATEdit notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 * @param iPopupFatherWindow 
 *   The father window of the edit panel.
 *   If the application wants to create an edit panel, it has to create it
 *   with a father window.
 */
    CATEdit(CATNotification *iNotification, CATDlgWindow *iPopupFatherWindow = NULL);
    virtual ~CATEdit();
    
/**
 * Returns the father window for creating edit panel.
 */
    CATDlgWindow * GetPopupFatherWindow() const;

  protected:
    CATDlgWindow *_popupFatherWindow;

};

#endif
