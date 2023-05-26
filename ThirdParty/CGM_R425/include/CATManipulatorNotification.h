#ifndef _CATManipulatorNotification
#define _CATManipulatorNotification

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"
#include "CATVueNotification.h"
#include <string.h>

          // WILL DISEAPPEAR IN 418.10 VERSION
          // --------------------------------- 
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//
// Abstract :   basic class for a vue component. (are sent by manipulators
// ---------    in graphical vue and by CATDialog instance for panel vue)
//
//
//------------------------------------------------------------------------------
//
// Usage :      This events show interactivity and are used
// -------      to decode applicative object. (i.e. objects under mouse
//              or transformation matrix)
//              
//------------------------------------------------------------------------------
//
// Main methods :
// --------------
//                      GetDataNotification()
//                      InitElementList()
//                      MoveToNextElement()
//                      
//
//------------------------------------------------------------------------------
//
// Class :      CATManipulatorNotification
// -------         CATNotification
//
//------------------------------------------------------------------------------


/**
 * Basic class to notify the interactive manipulation of visualized objects.
 * <b>Role</b>: This notification sent by a @href CATManipulator
 * is used to decode application model data from representations
 * controlled by the manipulator or to get the transformation matrix.
 * It can be received by any @href CATCommand class by means of the callback
 * through the @href CATCommand#AddAnalyseNotificationCB method. 
 */

class ExportedByCATVisFoundation CATManipulatorNotification : public CATVueNotification
{
  CATDeclareClass;

  public:
/**
 * Constructs a CATManipulatorNotification notification.
 * @param iNotification 
 *   The device event notification.
 *   This notification contains the manipulation device 
 *   parameters like mouse position.
 */
    CATManipulatorNotification(CATNotification *iNotification = NULL);
    virtual ~CATManipulatorNotification();
    
};

#endif
