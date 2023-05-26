/* -*-c++-*- */
#ifndef CATINavigElementEvents_H
#define CATINavigElementEvents_H

// COPYRIGHT DASSAULT SYSTEMES  1996
//=============================================================================
//
// Interface CATINavigElementEvents :
//     
//       Interface to subscribe to some events about rep modification
//
//=============================================================================
// Usage Notes:
//
//    - You can Query this interface on Many Objects
//    - GetNotification function is aloud to return NULL pointer
//      if object doesn't send this kind of notification
//=============================================================================
// Jun. 96   Creation                                R. Aymard
//=============================================================================

/**
 * @level Protected
 * @usage U3
 */

#include "CATInterfaceEvents.h"
#include "CATBaseUnknown.h"

#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATINavigElementEvents;

class ExportedByCATOmnMain CATINavigElementEvents: public CATInterfaceEvents
{
  CATDeclareInterface;
  public:
  
  // To Get Notification
  //---------------------------------------------------------------------
  virtual CATCallbackEvent GetSelectNotification() = 0 ;
  virtual CATCallbackEvent GetExtSelectNotification() = 0 ;
  virtual CATCallbackEvent GetActionNotification() = 0 ;
  virtual CATCallbackEvent GetExpandNotification() = 0 ;
  virtual CATCallbackEvent GetDeleteNotification() = 0 ;
  
  virtual CATCallbackEvent GetEditNotification() = 0 ;

  virtual CATCallbackEvent GetMethodNotification() = 0;
} ;

// Declaration du handler

CATDeclareHandler( CATINavigElementEvents, CATInterfaceEvents);


#endif
