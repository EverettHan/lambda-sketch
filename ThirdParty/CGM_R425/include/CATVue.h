#ifndef _CATVue
#define _CATVue
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
#include "CATVisFoundation.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//
// Abstract :   abstract class defining basic events exported by vue 
// ---------    component. it defines also a global interactive state
//              ( i.e. VALIDATION / ( NON_VALIDATION / CHOOSE ) )
//              
//              sends messages to notify new state
//
//
//------------------------------------------------------------------------------
//
// Usage :      used by dialog component to register to interactive events.
// -------     
//            
//              
//------------------------------------------------------------------------------
//
// Main methods :(static)
// --------------
//                        global interactive state
//                        ------------------------
//
//                        SetCATInteractiveState()
//                      
//
//------------------------------------------------------------------------------
//
// Class :      CATVue
// -------        CATBaseUnknown (SYSTEM framework)   
//
//------------------------------------------------------------------------------

#include "CATBaseUnknown.h"

class CATNotificationDispatcher;

enum CATVueInteractiveState { NON_VALIDATION, CHOOSE, VALIDATION };

class ExportedByCATVisFoundation CATVue : public CATBaseUnknown
{

  public :

  static CATVueInteractiveState GetInteractiveState();
  static void SetInteractiveState( CATVueInteractiveState );

  static CATNotificationDispatcher * GetDispatcher();

  private :

  static CATVueInteractiveState _interactiveState;
  static CATNotificationDispatcher * _dispatcher;
  

};

#endif
