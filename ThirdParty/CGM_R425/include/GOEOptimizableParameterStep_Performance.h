#ifndef GOEOptimizableParameterStep_Performance_H
#define GOEOptimizableParameterStep_Performance_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "GOEOptimizableParameterStep.h"

/**
 * This class is used to defined a validation Step.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterStep_Performance : public GOEOptimizableParameterStep
{
  CATDeclareClass;

public:  

  /**
   * Destructor.
   */
  virtual ~GOEOptimizableParameterStep_Performance();

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


  /**
   * Call this method to set the maximum time allowed for this step to execute.
   * The maximum time is expressed in milliseconds. It this value is equal to zero, it means that there
   * is no time-limit on this step, all the frames will be rendered.
   */
  HRESULT SetMaxExecutionTime(const unsigned int iMaxTime);

  /**
   * Call this method to set the maximum number of frames allowed for this step to render.
   */
  HRESULT SetMaxNbFramesToRender(const unsigned int iNbFrames);

protected:

  /**
   * The validation step constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterStep_Performance(const CATUnicodeString& iName);

  /**
   * Call this method to set the number of frames that have been rendered after performing 
   * the scenario associated to this step.
   * This method is protected so that only this class or other sub-classes can call it.
   */
  HRESULT SetNbFramesRendered(const unsigned int iNbFrames);

  /**
   * Call this method to set the execution time of the scenario associated to this step.
   * This method is protected so that only this class or other sub-classes can call it.
   */
  HRESULT SetExecutionTime(const unsigned int iCPUTime, const unsigned int iElapsedTime);

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterStep_Performance();
  GOEOptimizableParameterStep_Performance(const GOEOptimizableParameterStep_Performance&);
  GOEOptimizableParameterStep_Performance& operator=(const GOEOptimizableParameterStep_Performance&);

  unsigned int _uiMaxTime;
  unsigned int _uiMaxNbFramesToRender;

  unsigned int _uiNbFramesRendered;
  unsigned int _uiCPUTime;
  unsigned int _uiElapsedTime;
};

#endif
