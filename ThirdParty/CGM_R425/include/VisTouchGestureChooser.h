#ifndef VisTouchGestureChooser_H
#define VisTouchGestureChooser_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisTouchGestureChooser
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisTouchGestureChooser
//-----------------------------------------------------------------------------
// Abstract : gesture recognized from a touch event sequence
//            class for gesture data.
//-----------------------------------------------------------------------------
//  Main Methods :
//      GetGestureId() gesture type
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
#include "CATMathPoint2Df.h"
#include "CATMathVector2Df.h"
#include "CATMathDirection2Df.h"
#include "CATITouchEditor.h"
#include "CATListPV.h"
#include "VisTouchDevice.h"
#include "CATListOfVisTouchGesture.h"


class VisTouchGesture;
class VisMultitouchEvent;
class CATVizViewer;
class CATPickPath;
class VisTouchDevice;

class ExportedByCATVisFoundation VisTouchGestureChooser : public CATBaseUnknown
{
  CATDeclareClass;
public:
  VisTouchGestureChooser(CATLISTP(VisTouchGesture)&  pCurrentGestureList, int iNavigation, CATVizViewer  *ipViewer, VisTouchDevice *iDevice);
 
  virtual ~VisTouchGestureChooser();

 const VisTouchGesture* GetVisTouchGesture(int index, CATUnicodeString& gestureName);
 int GetVisTouchGestureCount () const;

 const VisTouchGesture * ChooseAppropriateGesture (VisMultitouchEvent* pTouchEvent, CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);

private:
 
  const VisTouchGesture * ChooseAppropriateGestureDuringManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateDownTypeGestureDuringManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateMoveTypeGestureDuringManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateUninterpretedGestureDuringManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateUpTypeGestureDuringManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);

  const VisTouchGesture * ChooseAppropriateFirstClassNavigationGesture(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateNavigationGesture(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  
  const VisTouchGesture * ChooseAppropriateGestureDuringNoManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateDownTypeGestureDuringNoManipulation (CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateMoveTypeGestureDuringNoManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateUpTypeGestureDuringNoManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  const VisTouchGesture * ChooseAppropriateUninterpretedGestureDuringNoManipulation(CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);

  CATBoolean Is3DViewPointed( CATManipulator *iPointedManip, CATPickPath &iPickPath );

 // CATListPV  _myGestureList;
  CATLISTP(VisTouchGesture) _myGestureList;
  // when a pen (wacom) is present, and if the touch inside 3Dviewer is reserved only for navigation, The pick is done on the first down event.
  // the first down gesture decides if the Navigation only mode is on or off.
  CATBoolean _NavigationTouchOn;
  int _isNavigationMode;
  CATVizViewer  *_Viewer;
  VisTouchDevice *_Device;

 
};
#endif

