#ifndef GOEOptimizableParameterStep_ValidationFramebuffer_H
#define GOEOptimizableParameterStep_ValidationFramebuffer_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "GOEOptimizableParameterStep_Validation.h"

class CAT3DViewer;
class CATPixelImage;

/**
 * This class is used to defined a Framebuffer validation Step.
 * This step is used to compare the content of the Framebuffer with an expected reference buffer, provided as an image. 
 * This process being entirely dependant of the graphics board realizing the rendering, a tolerance is applied.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterStep_ValidationFramebuffer : public GOEOptimizableParameterStep_Validation
{
  CATDeclareClass;

public:  

  /**
   * Destructor.
   */
  virtual ~GOEOptimizableParameterStep_ValidationFramebuffer();

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
   * This method is called when the test scenario has been executed. 
   * It is used to clean-up the environment before running a new test.
   */
  virtual HRESULT CleanupStepContext();

protected:

  /**
   * The Framebuffer validation step constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterStep_ValidationFramebuffer(const CATUnicodeString& iName);

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

  /**
   * This method is called when the captured frame buffer has to be compared with the reference. 
   * Output boolean parameter is used to specified whether the tests succeeded or not.
   */
  virtual HRESULT ValidateFramebuffer(CATPixelImage* ipFramebuffer, CATBoolean& obIsValid) = 0;

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterStep_ValidationFramebuffer();
  GOEOptimizableParameterStep_ValidationFramebuffer(const GOEOptimizableParameterStep_ValidationFramebuffer&);
  GOEOptimizableParameterStep_ValidationFramebuffer& operator=(const GOEOptimizableParameterStep_ValidationFramebuffer&);
};

#endif
