#ifndef GOEOptimizableParameterScenario_H
#define GOEOptimizableParameterScenario_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATErrorDef.h"

class CAT3DRep;
class GOIOptimizableParameter;
class GOEOptimizableParameterStep;

/**
 * Base class to define the test scenario associated to a Graphics Optimizable Parameter.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterScenario : public CATEventSubscriber
{
  CATDeclareClass;

public:  

  /**
   * Event dispatched when a scenario has finished its replay.
   * This event is dispatched when all steps defining the scenario have been replayed.
   */
  CATDeclareCBEvent (ENDOFSCENARIOREPLAY); 

  virtual ~GOEOptimizableParameterScenario();

  /**
   * This method is called to specify which parameter the scenario is associated with.
   */
  HRESULT SetAssociatedParameter(GOIOptimizableParameter* ipParameter);

  /**
   * Call this method to retrieve the parameter this scenario is associated with.
   */
  HRESULT GetAssociatedParameter(GOIOptimizableParameter** opParameter);

  /**
   * This method is called to check that the test scenario is valid. That is to say that it is going to
   * create it, if not already performed, through the @href CreateScenario method and it is going to check
   * that it contain at least one step.
   */
  HRESULT ValidateScenario();

  /**
   * This method is called to run the test scenario. 
   * If the scenario contains a model it will be displayed.
   * All the steps defined in the scenario will be executed, one after the other.
   */
  HRESULT RunScenario();

  /**
   * Call this method to retrieve the number of steps contained in the scenario.
   */
  HRESULT GetNumberOfSteps(unsigned int& ouiNbSteps);

  /**
   * Call this method to retrieve one specific step of the scenario, identified by its number.
   */
  HRESULT GetStep(const unsigned int iuiStep, GOEOptimizableParameterStep** opRetrievedStep);

  /**
   * Call this method to retrieve the FPS decision step associated to the parameter. 
   */
  HRESULT GetFPSDecisionStep(double& oFPSDecisionStep);

protected:

  /**
   * The test scenario constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterScenario();

  /**
   * This method is called only once, to create the test scenario associated with the optimizable parameter.
   */
  virtual HRESULT CreateScenario() = 0;

  /**
   * Call this method to specify the model that has to be used during the test scenario execution.
   */
  HRESULT SetModelToRender(CAT3DRep* ipModel);

  /**
   * Call this method to add a step in the test scenario associated to the optimizable parameter.
   * This step will be executed after all already added steps. If none, this step will be executed first.
   */
  HRESULT AddStep(GOEOptimizableParameterStep* ipStepToAdd);

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterScenario(const GOEOptimizableParameterScenario&);
  GOEOptimizableParameterScenario& operator=(const GOEOptimizableParameterScenario&);

  void RunSteps();
  void OnStepEnded (CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

  void EndOfScenarioReached();

  CATBoolean _bScenarioBuilded;
  CATBoolean _bUsesViewer;

  CAT3DRep* _pModelRep;

  unsigned int _uiNbSteps;
  GOEOptimizableParameterStep** _pSteps;

  unsigned int _uiCurrentExecutedStep;
  GOEOptimizableParameterStep* _pCurrentExecutedStep;

  CATCallback _EndOfStepCB;

  GOIOptimizableParameter* _pAssociatedParameter;
};

#endif
