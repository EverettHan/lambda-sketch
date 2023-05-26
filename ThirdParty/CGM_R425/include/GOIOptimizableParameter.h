#ifndef GOIOptimizableParameter_H
#define GOIOptimizableParameter_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATErrorDef.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGraphicsOptimizer IID IID_GOIOptimizableParameter;
#else
extern "C" const IID IID_GOIOptimizableParameter;
#endif

class GOEOptimizableParameterUI;
class GOEOptimizableParameterScenario;
class GOEOptimizableParameterValue;

class CATDialog;

//------------------------------------------------------------------

/**
 * This enumeration defines the execution modes an optimizable parameter can be defined in.
 * When the test associated to each parameter is executed, this mode can be used to choose in which order
 * to replay these tests.
 * The defined modes are the following:
 * - GOEM_Setup
 *  This mode is used to identify parameters that don't rely on an interactive context to be executed and that need to be executed only once during setup
 * - GOEM_Batch
 *  This mode is used to identify parameters that don't rely on an interactive context to be executed and that need to be executed at each tests run
 * - GOEM_Interactive
 *  This mode is used to identify parameters that have to rely on an interactive context to be executed  and that need to be executed at each tests run
 */
enum GOExecutionMode
{
  GOEM_Setup        = 1,
  GOEM_Batch        = 2,
  GOEM_Interactive  = 3
};


/**
 * This enumeration defines the various categories an optimizable parameter can be defined in.
 * When the user interface associated to each parameter is displayed, it can be regrouped, based on this information.
 * The defined categories are the following:
 * - GOPC_Performance
 *  This category contains parameters that mainly have an impact on an application performance
 * - GOPC_Display
 *  This category contains parameters that mainly have an impact on an application display
 * - GOPC_Navigation
 *  This category contains parameters that mainly have an impact on an application navigation behavior
 * - GOPC_Misc
 *  This category contains all other kind of parameters
 */
enum GOParameterCategory
{
  GOPC_Performance=1,
  GOPC_Display,
  GOPC_Navigation,
  GOPC_Misc
};

//------------------------------------------------------------------

/**
 * This is the Graphics Optimizable Parameter base interface.
 * This interface is used to define optimizable parameters. Each parameter is defined by its name, the category
 * it belongs to (see @href GOParameterCategory), its execution mode (see @href GOExecutionMode), 
 * an user interface and a test scenario. 
 * A parameter can be optimizable or not, that is to say that its value can be modified or not.
 * A parameter can be executable or not, that is to say that its test scenario can be executed or not.
 * This interface HAS TO BE USED with the provided adapter, define in @href GOEOptimizableParameter.
 */
class ExportedByGraphicsOptimizer GOIOptimizableParameter : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Call this method to retrieve the parameter name.
   */
  virtual HRESULT GetName(CATUnicodeString& oName) = 0;

  /**
   * Call this method to retrieve the parameter execution mode.
   */
  virtual HRESULT GetExecutionMode(GOExecutionMode& oMode) = 0;

  /**
   * Call this method to retrieve the parameter category.
   */
  virtual HRESULT GetCategory(GOParameterCategory& oCategory) = 0;

  /**
   * Call this method to retrieve the parameter FPS decision step.
   */
  virtual HRESULT GetFPSDecisionStep(double& oFPSDecisionStep) = 0;

  /**
   * Call this method to retrieve the parameter optimizable flag.
   */
  virtual HRESULT IsOptimizable(CATBoolean& obIsOptimizable) = 0;

  /**
   * Call this method to retrieve the parameter executable flag.
   */
  virtual HRESULT IsExecutable(CATBoolean& obIsExecutable) = 0;



  /**
   * This method is called to create the parameter, that is to say to determine its default value. 
   * This process is performed only once, when the parameter has been successfully elected by a @href GraphicsOptimizerBuilder.
   */
  virtual HRESULT CreateParameter() = 0;

  /**
   * Call this method to retrieve the parameter value.
   * Warning! The returned @href GOEOptimizableParameterValue is allocated in this method.
   * IT HAS TO BE DELETED BY CALLER.
   */
  virtual HRESULT GetValue(GOEOptimizableParameterValue** opValue) = 0;

  /**
   * Call this method to modify the parameter value.
   */
  virtual HRESULT SetValue(GOEOptimizableParameterValue* ipValue) = 0;

  /**
   * This method is called when the parameter value is read from settings. 
   */
  virtual HRESULT ReadValueFromSettings() = 0;

  /**
   * This method is called when the parameter value is written in settings. 
   */
  virtual HRESULT WriteValueToSettings() = 0;

  /**
   * This method is called to take decision on the new parameter value, based on test performed in the scenario.
   */
  virtual HRESULT TakeDecisionOnParameterValue() = 0;



  /**
   * Call this method to check if the user interface associated to the parameter has been built.
   */
  virtual HRESULT UserInterfaceCreated(CATBoolean& obCreated) = 0;

  /**
   * This method is called when the user interface associated to the parameter needs to be builded, but only if
   * the parameter has been successfully elected by a @href GraphicsOptimizerBuilder.
   */
  virtual HRESULT GetUserInterface(CATDialog* iParent, GOEOptimizableParameterUI** oBuilder) = 0;

  /**
   * This method is called when the test scenario associated to the parameter needs to be builded, but only if
   * the parameter has been successfully elected by a @href GraphicsOptimizerBuilder.
   * Based on the information contained in the @href GOEOptimizableParameterScenario object, the parameter 
   * can update its value right after the performance and validation tests have been performed.
   */
  virtual HRESULT GetScenario(GOEOptimizableParameterScenario** oBuilder) = 0;
};

//------------------------------------------------------------------

#endif
