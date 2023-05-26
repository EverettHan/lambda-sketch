#ifndef GOEOptimizableParameterStep_H
#define GOEOptimizableParameterStep_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATUnicodeString.h"
#include "CATErrorDef.h"
#include "CATViz.h" // JQT : Added for applicative build impact : CATViz --> CATVisFoundation

class GOEOptimizableParameterScenario;

/**
 * Base class to define a step of the test scenario associated to a Graphics Optimizable Parameter.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterStep : public CATEventSubscriber
{
  CATDeclareClass;

public:  

  /**
   * Event dispatched when a step has finished its replay.
   */
  CATDeclareCBEvent (ENDOFSTEPREPLAY);

  virtual ~GOEOptimizableParameterStep();

  /**
   * This method is called to specify which scenario the step is associated with.
   */
  HRESULT SetAssociatedScenario(GOEOptimizableParameterScenario* ipScenario);

  /**
   * Call this method to retrieve the scenario this step is associated with.
   */
  HRESULT GetAssociatedScenario(GOEOptimizableParameterScenario** opScenario);

  /**
   * Call this method to retrieve the step name.
   */
  HRESULT GetName(CATUnicodeString& oName);

  /**
   * This method is called when the test scenario is going to be executed. 
   * It is used to set the environment before running the test.
   */
  virtual HRESULT InitializeStepContext() = 0;

  /**
   * This method is called to run the test scenario. 
   */
  virtual void RunStepScenario() = 0;

  /**
   * This method is called when the test scenario has been executed. 
   * It is used to clean-up the environment before running a new test.
   */
  virtual HRESULT CleanupStepContext() = 0;

  /**
   * This method is called to decide whether or not the next scenario step has to be executed. 
   */
  virtual HRESULT DoExecuteNextStep(CATBoolean& obDoExecute) = 0;


  /**
   * Call this method to retrieve the maximum time allowed for this step to execute.
   * The maximum time is expressed in milliseconds.
   */
  virtual HRESULT GetMaxExecutionTime(unsigned int& oMaxTime) = 0;

  /**
   * Call this method to retrieve the maximum number of frames allowed for this step to render.
   */
  virtual HRESULT GetMaxNbFramesToRender(unsigned int& oNbFrames) = 0;

  /**
   * Call this method to retrieve the number of frames that have been rendered after performing 
   * the scenario associated to this step.
   */
  virtual HRESULT GetNbFramesRendered(unsigned int& oNbFrames) = 0;

  /**
   * Call this method to retrieve the execution time of the scenario associated to this step.
   * All times are expressed in milliseconds
   */
  virtual HRESULT GetExecutionTime(unsigned int& oCPUTime, unsigned int& oElapsedTime) = 0;

  /**
   * Call this method to retrieve the "frames per second" ratio, computed based on performance results.
   */
  virtual HRESULT GetNbFramesPerSecond(double& oFramesPerSecond) = 0;

  /**
   * Call this method to retrieve the validation state. 
   */
  virtual HRESULT GetValidationResult(CATBoolean& obIsValid) = 0;

  /**
   * Call this method to retrieve the FPS decision step associated to the parameter. 
   */
  HRESULT GetFPSDecisionStep(double& oFPSDecisionStep);

protected:

  /**
   * The test scenario step constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterStep(const CATUnicodeString& iName);

  /**
   * This method has to be called when the test scenario is finished. 
   */
  void EndTest();

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterStep(const GOEOptimizableParameterStep&);
  GOEOptimizableParameterStep& operator=(const GOEOptimizableParameterStep&);

  CATUnicodeString _strStepName;

  GOEOptimizableParameterScenario* _pAssociatedScenario;
};

#endif
