/* -*-c++-*- */
#ifndef CATIContentObjectEvents_h
#define CATIContentObjectEvents_h
// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// Interface CATIContentObjectEvents :
//        - Events published by Ole Inserted Objects: 
//              * Creation       (not implemeneted)
//              * Modification   (Data Modifications)
//              * Delete
//              * View Modification
//                 
//
//
//=============================================================================
// Usage Notes:
//

//=============================================================================
//	Jan.98   Creation                                slg
//=============================================================================

/**
 * @level Private 
 * @usage U3
 */

#include "CATIDataEvents.h"
#include "AC0WINLNK.h"


extern ExportedByAC0WINLNK IID IID_CATIContentObjectEvents ;

class ExportedByAC0WINLNK CATIContentObjectEvents : public CATIDataEvents
{
  CATDeclareInterface;
  public:
  
  // Server View Modification Events
  virtual CATCallbackEvent GetViewNotification() = 0 ;

   // Server Save Modification Events (useful for Embed)
  virtual CATCallbackEvent GetSaveNotification() = 0 ;

   // Server Close Modification Events 
  virtual CATCallbackEvent GetCloseNotification() = 0 ;
	
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIContentObjectEvents, CATIDataEvents ) ;


#endif
