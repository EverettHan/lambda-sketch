// COPYRIGHT DASSAULT SYSTEMES   2001
//=============================================================================
//
// class CATGREvent :
//		classe generique pour les evenements du graph
//
//=============================================================================
// Jan. 01   Creation                                           
//=============================================================================
#ifndef CATGREvent_h
#define CATGREvent_h

/**
 * @level Private 
 * @usage U1
 */

#include "CATOmnMain.h"
#include "CATNotification.h"
#include "CATCallbackManager.h"

class ExportedByCATOmnMain CATGREvent : public CATNotification  
{
  CATDeclareClass ;
public :
  CATGREvent() {};
  ~CATGREvent() {};
}; 

#endif




