#ifndef VisTouchEvent_H
#define VisTouchEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisTouchEvent
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisTouchEvent
//					        CATTimeStampedEvent
//					          CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event used by other events to describe a touch 
//            from touch devices.
//------------------------------------------------------------------------------
// Role :     The VisMultitouchEvent notifies the viewer of any multi touch sequence.
//            It contains several or one VisTouchEvent, each of them describing a touche.
//            Idem for the VisMultitouchDeviceEvent.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	  manage the event of one touch
//		  GetTouchEventCount
//		  GetTouchEvent
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
#include "CATMathPoint2Df.h"


#define CURSORNONE  0
#define CURSORUP    1
#define CURSORDOWN  2
#define CURSORMOVE  3
#define CURSORFIX   4
#define CURSORERROR 5

class ExportedByCATVisFoundation VisTouchEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public :

  // constructor / destructor
  VisTouchEvent();
  virtual ~VisTouchEvent();

  // Copy constructor and equal operator
	VisTouchEvent (const VisTouchEvent &);
	VisTouchEvent & operator = (const VisTouchEvent &);

  // Touch position
   CATMathPoint2Df _touchPt; // Pixel coordinates of current touch point on touchable window

  // Touch state (CURSORDOWN, CURSORUP, CURSORMOVE, ...)
  int _touchType;

  // Touch identifier
  int _touchID;
};

#endif
