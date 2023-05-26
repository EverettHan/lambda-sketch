#ifndef GOEOptimizableParameterStep_PerformanceTurntable_H
#define GOEOptimizableParameterStep_PerformanceTurntable_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "GOEOptimizableParameterStep_Performance.h"

class CAT3DViewer;
class CAT3DViewpoint;
class CATVisuRotatePerfo;
class CATVizTimerInteraction;

/**
 * This class can be used in the context of defining the test scenario associated to one Optimizable Parameter.
 * This step is an interactive test relying on the use of a turn-table to rotate the scenario model along one axis.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterStep_PerformanceTurntable : public GOEOptimizableParameterStep_Performance
{
  CATDeclareClass;

public:  

  virtual ~GOEOptimizableParameterStep_PerformanceTurntable();

  /**
   * This method is called when the test scenario is going to be executed. 
   * It is used to set the environment before running the test.
   */
  virtual HRESULT InitializeStepContext();

  /**
   * This method is called to run the test scenario. 
   */
  virtual void RunStepScenario();

  /**
   * Call this method to set the rotation angle of the turn-table.
   */
  HRESULT SetRotationAngle(const float iAngle);

  /**
   * Call this method to retrieve the rotation angle of the turn-table.
   */
  HRESULT GetRotationAngle(float& oAngle);

  /**
   * Call this method to set the rotation axis of the turn-table.
   */
  HRESULT SetRotationAxis(const unsigned int iAxisNum);

  /**
   * Call this method to retrieve the rotation axis of the turn-table.
   */
  HRESULT GetRotationAxis(unsigned int& oAxisNum);

  /**
   * This method is called when the test scenario has been executed. 
   * It is used to clean-up the environment before running a new test.
   */
  virtual HRESULT CleanupStepContext();

  /**
   * This method is called to decide whether or not the next scenario step has to be executed. 
   */
  virtual HRESULT DoExecuteNextStep(CATBoolean& obDoExecute);

protected:

  /**
   * The turn table scenario step constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterStep_PerformanceTurntable(const CATUnicodeString& iName);

  /**
   * This method is called when the test scenario is going to be executed. 
   * It is used to set the environment before running the test.
   */
  virtual HRESULT InitializeStepContext(CAT3DViewer* ipViewer) = 0;

  /**
   * This method is called when the test scenario has been executed. 
   * It is used to clean-up the environment before running a new test.
   */
  virtual HRESULT CleanupStepContext(CAT3DViewer* ipViewer) = 0;

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterStep_PerformanceTurntable();
  GOEOptimizableParameterStep_PerformanceTurntable(const GOEOptimizableParameterStep_PerformanceTurntable&);
  GOEOptimizableParameterStep_PerformanceTurntable& operator=(const GOEOptimizableParameterStep_PerformanceTurntable&);

  void OnWindowSwap(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);
  void OnEndOfInteraction(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

  void SaveViewpoint(CAT3DViewer* ipViewer);
  void RestoreViewpoint(CAT3DViewer* ipViewer);

  void RunTurnTable();

  CATVisuRotatePerfo* _pTurntable;
  CATVizTimerInteraction* _pTimer;

  CAT3DViewpoint* _pSavedViewpoint;

  CATCallback _SwapCB;
  CATCallback _EndOfInteractionCB;

  float _Angle;
  unsigned int _AxisNum;

  unsigned int _delayedSwap;
};

#endif
