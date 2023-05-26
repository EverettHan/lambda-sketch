#ifndef CATVisuRotatePerfo_H
#define CATVisuRotatePerfo_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATVisFoundation.h"

#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATVizDuration.h"

class CATVizViewer;

class ExportedByCATVisFoundation CATVisuRotatePerfo : public CATEventSubscriber
{
public:
  CATDeclareCBEvent (END_ROTATE_PERFO);  

  CATVisuRotatePerfo(CATVizViewer* i_pVizViewer);
  ~CATVisuRotatePerfo();
  
  void InitRotatePerfo(int i_numberOfSteps=40, float i_angle=9.0f, int i_axisNum=1, int i_useDynamicLOD = 0, int i_maxTimeInMilliseconds = 0, bool iProfiling = false);

  void GetValues(float &o_cullTime,float &o_drawTime, float &o_frameTime,float &o_totalTime);
  void GetCPUValues(float &o_cullTime,float &o_drawTime, float &o_frameTime,float &o_totalTime);
  void GetValue(int& o_nbFramesRendered);
  void GetValues(CATVizDuration ** o_pplDuration, int &o_nbDuration);

private:
  void OnSwap(CATCallbackEvent, void*, CATNotification*, CATSubscriberData , CATCallback);
  void OnUpdate(CATCallbackEvent, void*, CATNotification*, CATSubscriberData , CATCallback);
  
  CATVizViewer* _pVizViewer;

  int _numberOfSteps;
  int _currentStep;
  int _axisNum;  
  int _useDynamicLOD;
  int _maxTimeInMilliseconds;
  int _nbFramesRendered;
  
  float _angle;
  float _frameTime;
  float _totalTime;

  bool m_Profiling;

  CATVizDuration _duration;

  CATCallback _swapCB;
  CATCallback _updateCB;

  CATULONG32 _uiLastSwapTime;
};
#endif
