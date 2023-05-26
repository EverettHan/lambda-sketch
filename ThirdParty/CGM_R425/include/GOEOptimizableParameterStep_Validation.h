#ifndef GOEOptimizableParameterStep_Validation_H
#define GOEOptimizableParameterStep_Validation_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "GOEOptimizableParameterStep.h"

/**
 * This class is used to defined a validation Step.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterStep_Validation : public GOEOptimizableParameterStep
{
  CATDeclareClass;

public:  

  /**
   * Destructor.
   */
  virtual ~GOEOptimizableParameterStep_Validation();

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
  virtual HRESULT DoExecuteNextStep(CATBoolean& obDoExecute);


  /**
   * Call this method to retrieve the maximum time allowed for this step to execute.
   * The maximum time is expressed in milliseconds.
   */
  virtual HRESULT GetMaxExecutionTime(unsigned int& oMaxTime);

  /**
   * Call this method to retrieve the maximum number of frames allowed for this step to render.
   */
  virtual HRESULT GetMaxNbFramesToRender(unsigned int& oNbFrames);

  /**
   * Call this method to retrieve the number of frames that have been rendered after performing 
   * the scenario associated to this step.
   */
  virtual HRESULT GetNbFramesRendered(unsigned int& oNbFrames);

  /**
   * Call this method to retrieve the execution time of the scenario associated to this step.
   * All times are expressed in milliseconds
   */
  virtual HRESULT GetExecutionTime(unsigned int& oCPUTime, unsigned int& oElapsedTime);

  /**
   * Call this method to retrieve the "frames per second" ratio, computed based on performance results.
   */
  virtual HRESULT GetNbFramesPerSecond(double& oFramesPerSecond);

  /**
   * Call this method to retrieve the validation state. 
   */
  virtual HRESULT GetValidationResult(CATBoolean& obIsValid);

protected:

  /**
   * The validation step constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterStep_Validation(const CATUnicodeString& iName);

  /**
   * Call this method to set the validation state. 
   */
  HRESULT SetValidationResult(const CATBoolean& ibIsValid);

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterStep_Validation();
  GOEOptimizableParameterStep_Validation(const GOEOptimizableParameterStep_Validation&);
  GOEOptimizableParameterStep_Validation& operator=(const GOEOptimizableParameterStep_Validation&);

  CATBoolean _bValidationResult;
};

#endif
