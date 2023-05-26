#ifndef _CATEndActivate
#define _CATEndActivate

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines the fact that an new object has been selected.
// ----------   It tell to old selected object that it is no more current.
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATEndActivate
// -------        CATManipulatorNotification
//                  CATManipulator
//------------------------------------------------------------------------------

#include "CATManipulatorNotification.h"
#include "CATVisFoundation.h"
class CATManipulator;

/**
 * Class to notify the end of selection of the representation.
 * <b>Role</b>: This notification sent by a @href CATManipulator indicates 
 * that the mouse botton 1 is pressed above another representation not
 * controlled by the manipulator or above the background.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATEndActivate : public CATManipulatorNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATEndActivate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATEndActivate(CATNotification *iNotification);

/**
 * Constructs a CATEndActivate notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 * @param ipManipulator 
 *   The next activated manipulator.
 */
    CATEndActivate(CATNotification *iNotification, CATManipulator* ipManipulator);

    virtual ~CATEndActivate();

/**
 * Informs about the manipulator that will be activated after this EndActivate event.
 * @param ipManipulator 
 *   The next activated manipulator.
 */
    void SetNextActivatedManipulator(CATManipulator* ipManipulator);

/**
 * Informs about the manipulator that will be activated after this EndActivate event.
 * @return
 *   The next activated manipulator.
 */
    CATManipulator* GetNextActivatedManipulator() const;

private:

    CATManipulator* _pNextActivatedManipulator;
};

#endif
