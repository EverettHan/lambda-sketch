#ifndef _CATEndPreactivate
#define _CATEndPreactivate

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that an object manipulated is no more under
// ----------   mouse.
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATEndPreactivate
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATManipulatorNotification.h"
#include "CATVisFoundation.h"
class CATManipulator;

/**
 * Class to notify the end of preselection of the representation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates
 * that the mouse leaves the representation controlled by the manipulator.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATEndPreactivate : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATEndPreactivate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATEndPreactivate(CATNotification *iNotification);

/**
 * Constructs a CATEndPreactivate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 * @param ipManipulator 
 *   The next preactivated manipulator.
 */
    CATEndPreactivate(CATNotification *iNotification, CATManipulator* ipManipulator);

    virtual ~CATEndPreactivate();
    
/**
 * Informs about the manipulator that will be preactivated after this EndPreactivate event.
 * @param ipManipulator 
 *   The next preactivated manipulator.
 */
    void SetNextPreactivatedManipulator(CATManipulator* ipManipulator);

/**
 * Informs about the manipulator that will be preactivated after this EndPreactivate event.
 * @return
 *   The next preactivated manipulator.
 */
    CATManipulator* GetNextPreactivatedManipulator() const;

private:

    CATManipulator* _pNextPreactivatedManipulator;
};

#endif
