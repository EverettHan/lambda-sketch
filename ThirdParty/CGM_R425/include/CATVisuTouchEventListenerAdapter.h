//// COPYRIGHT DASSAULT SYSTEMES 2018
//=============================================================================
//
// CATVisuTouchEventListenerAdapter
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// March 2018                                                            JMA
//=============================================================================


#ifndef CATVisuTouchEventListenerAdapter_H
#define CATVisuTouchEventListenerAdapter_H

#include "CATVisuEventListener2Adapter.h"
#include "CATVisFoundation.h"
#include "CATListOfVisTouchGesture.h"

#include "CATListPV.h"

class CATVizViewer;
class VisTouchListener;
class VisTouchInterpretor;
class VisTouchGesture;
//-----------------------------------------------------------------------
class ExportedByCATVisFoundation CATVisuTouchEventListenerAdapter : public CATVisuEventListener2Adapter
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVisuTouchEventListenerAdapter (CATVizViewer* ipVizViewer);
  virtual ~CATVisuTouchEventListenerAdapter ();

  unsigned int DeviceAction_post(CATNotification *i_pNotification);
  void RegisterTouchGesturesListener();
  void UnregisterTouchGesturesListener();

  void GetCurrentGestureList (CATLISTP(VisTouchGesture)&  oCurrentGestureList); 
  //CATUnicodeString& GetGestureName (void * Gesture);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVisuTouchEventListenerAdapter (CATVisuTouchEventListenerAdapter &);
  CATVisuTouchEventListenerAdapter& operator=(CATVisuTouchEventListenerAdapter&);

  int InterpretTouchEvent(CATNotification *i_pNotification, CATListPV& pCurrentGestureList);

  CATVizViewer* _pVizViewer;
   // touch listener
  VisTouchListener* _pTouchListener;

  // touch interpretor
  VisTouchInterpretor* _pTouchInterpretor;


  CATListPV _pCurrentGestureList;

};
#endif
