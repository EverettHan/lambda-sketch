/* -*-c++-*- */
#ifndef CATREDRAWOBJECT_H
#define CATREDRAWOBJECT_H

// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATRedrawObject :
//     
//       Direct implementation of the interface CATIRedrawEvent
//
//=============================================================================
//
//=============================================================================
// Dec 98   Creation                                mbv
//=============================================================================

/**
 * @level Protected
 * @usage U1
 */

#include "CATBaseUnknown.h"
#include "CATOmnMain.h"
#include "CATCallbackManager.h"


class ExportedByCATOmnMain CATRedrawObject : public CATEventSubscriber
{
  CATDeclareClass;
  public:

//Definition de l'evenement Redraw
  CATDefineCBEvent( EvtRedrawNotification )

//Methode de CATIRedrawEvent
  CATRedrawObject();
  ~CATRedrawObject();
  CATCallbackEvent  GetRedrawNotification() ;
  void	Redraw() ;
  void  CBRedraw ( CATCallbackEvent  evt,
				      void*             from,
				      CATNotification*  evtdata,
				      CATSubscriberData data,
				      CATCallback       ident ) ;
  
  HRESULT RedrawParent();
  
  HRESULT RedrawNodeVisu();
  HRESULT RedrawChildren();
  HRESULT RedrawChildrenVisu();
};


#endif
