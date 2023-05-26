/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
#ifndef CAT_IDATA_EVENTS_H
#define CAT_IDATA_EVENTS_H
// COPYRIGHT DASSAULT SYSTEMES  1996
//=============================================================================
//
// Interface CATIDataEvents :
//     
//       Interface to subscribe to some events about data modification
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

#include "CATInterfaceEvents.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDataEvents ;

class ExportedByAD0XXBAS CATIDataEvents : public CATInterfaceEvents
{
  CATDeclareInterface;
  public:
  
  // To Get Notification
  //---------------------------------------------------------------------
  virtual CATCallbackEvent GetModifyNotification() = 0 ;
  virtual CATCallbackEvent GetDeleteNotification() = 0 ;
  virtual CATCallbackEvent GetCreateNotification() = 0 ;
 
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDataEvents, CATInterfaceEvents ) ;


#endif
