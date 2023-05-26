#ifndef GOEOptimizableParameter_Setup_H
#define GOEOptimizableParameter_Setup_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "GOEOptimizableParameter.h"

/**
 * This class is used to defined a Setup Parameter.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameter_Setup : public GOEOptimizableParameter
{
  CATDeclareClass;

public:

  /**
   * Destructor.
   */
  virtual ~GOEOptimizableParameter_Setup();

  /**
   * This method is called to initialize the parameter, that is to say to determine its default value. 
   * This process is performed only when the parameter has been successfully elected by a @href GraphicsOptimizerBuilder.
   */
  virtual HRESULT CreateParameter();

  /**
   * Call this method to retrieve the parameter FPS decision step.
   */
  virtual HRESULT GetFPSDecisionStep(double& oFPSDecisionStep);

protected:

  /**
   * The Setup Parameter constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameter_Setup(const CATUnicodeString& iName, const GOParameterCategory& iCategory);

  /**
   * This method is called to create test scenario associated to the Generic Driver Optimizable Parameter.
   */
  virtual HRESULT CreateScenario(GOEOptimizableParameterScenario** oBuilder);

  /**
   * This method is called to take decision on the new parameter value, based on test performed in the scenario.
   */
  virtual HRESULT TakeDecisionOnParameterValue();

  /**
   * This method is called to define the session value associated to the parameter.
   * This value is defined once and for all and won't change until the end of the program.
   */
  virtual HRESULT DefineSessionValue() = 0;

private:

  /**
   * Copy not allowed.
   */
  GOEOptimizableParameter_Setup();
  GOEOptimizableParameter_Setup(const GOEOptimizableParameter_Setup&);
  GOEOptimizableParameter_Setup& operator=(const GOEOptimizableParameter_Setup&);
};

//------------------------------------------------------------------

#endif
