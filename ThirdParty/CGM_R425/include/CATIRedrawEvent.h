/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIREDRAWEVENT_H
#define CATIREDRAWEVENT_H

/**
  * @CAA2Level L1
  * @CAA2Usage U3
  */

#include "CATInterfaceEvents.h"
#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATIRedrawEvent ;

/**
* Interface to allow a graph to redraw when desired.
*/

class ExportedByCATOmnMain CATIRedrawEvent : public CATInterfaceEvents
{
  CATDeclareInterface;
  public:
  
	  /** @nodoc */
  virtual CATCallbackEvent GetRedrawNotification() = 0 ;
  
  /**
  * Updates current node and its children.
  */
  virtual void             Redraw() = 0 ;
  
  /** @nodoc */
  virtual void             CBRedraw ( CATCallbackEvent  evt,
				      void*             from,
				      CATNotification*  evtdata,
				      CATSubscriberData data,
				      CATCallback       ident ) = 0 ;
  /**
  * Updates the parent of the current node . 
  * <br><b> Note: </b> useful in case of destruction.
  */
  virtual void RedrawParent() = 0;
  
  /**
  * Updates current node.
  * <br><b>Role: </b> useful for icon modification.
  */
  virtual void RedrawNodeVisu () = 0;
  
  /**
  * Updates the children of the current node.
  * <br><b> Note: </b> deletes previous and creates new ones.
  */
  virtual void RedrawChildren () = 0;

  /**
  * Updates the visualisation of the children of the current node.
  * <br><b> Note: </b> useful for children's icon modification.
  */
  virtual void RedrawChildrenVisu() = 0;

} ;

CATDeclareHandler( CATIRedrawEvent, CATInterfaceEvents ) ;


#endif
