#ifndef CATMagnifierEvent_H
#define CATMagnifierEvent_H

// COPYRIGHT DASSAULT SYSTEMES 2014
/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"

class CATVizViewer;

/**
 * Class notification for CATViewer interactions.
 * <b>Role</b>: A such notification is sent when any magnifier event occurs in a 
 * @href CATViewer which has any magnifier mode active. 
 * <br>To receive such notifications, you should set a callback on a
 * <tt>CATVizViewer::VIEWER_MAGNIFIER_EVENT</tt> class event. 
 * @see CATVizViewer
 */
class ExportedByCATVisFoundation CATMagnifierEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  /** @nodoc */
  CATMagnifierEvent(CATVizViewer* iViewer);

  /** @nodoc */
  virtual ~CATMagnifierEvent();

  /** @nodoc */
  enum MagnifierEvent
  {
    ShowMagnifierEvent = 0,
    MoveMagnifierEvent,
    HideMagnifierEvent
  };

  /** @nodoc */
  enum MagnifierAction
  {
    MagnifierAction_PreActivation = 0,
    MagnifierAction_Navigation,
    MagnifierAction_Manipulation
  };

  /** @nodoc */
  CATVizViewer* GetViewer();   

public :

  /** @nodoc */
  float           _xPos;

  /** @nodoc */
  float           _yPos;

  /** @nodoc */
  MagnifierEvent  _magEvent;

  /** @nodoc */
  MagnifierAction _magAction;

protected :

  /** @nodoc */
  CATVizViewer*   _Viewer;
};

#endif
