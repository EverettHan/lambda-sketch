#ifndef _CATMultiSel
#define _CATMultiSel

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that objects has been multi selected.
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by indicator
// ------        
//
//------------------------------------------------------------------------------
// Class :      CATMultiSel
// -------        CATVueNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATVueNotification.h"
#include "CATVisFoundation.h"


/**
 * Class to notify the multi selection of the representations.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates 
 * that a group of representations controlled by the manipulator
 * has been selected.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATMultiSel : public CATVueNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATMultiSel notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATMultiSel(CATNotification *iNotification);
    virtual ~CATMultiSel();
    
};

#endif
