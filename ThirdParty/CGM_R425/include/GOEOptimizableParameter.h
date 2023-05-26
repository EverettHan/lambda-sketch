#ifndef GOEOptimizableParameter_H
#define GOEOptimizableParameter_H

// COPYRIGHT Dassault Systemes 2007

#include "GraphicsOptimizer.h"

#include "GOIOptimizableParameter.h"
#include "CATErrorDef.h"

#include "GOIOptimizableParameter.h"

class GOEOptimizableParameterUI;
class GOEOptimizableParameterScenario;
class GOEOptimizableParameterValue;

/**
 * This is the Graphics Optimizable Parameter base adapter.
 * This class is used as an adapter for the @href GOIOptimizableParameter interface. All extensions implementing
 * the @href GOIOptimizableParameter interface HAVE TO inherit from this adapter.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameter : public GOIOptimizableParameter
{
  CATDeclareClass;

public:

  virtual ~GOEOptimizableParameter();

  /**
   * Call this method to retrieve the parameter name.
   */
  virtual HRESULT GetName(CATUnicodeString& oName);

  /**
   * Call this method to retrieve the parameter execution mode.
   */
  virtual HRESULT GetExecutionMode(GOExecutionMode& oMode);

  /**
   * Call this method to retrieve the parameter category.
   */
  virtual HRESULT GetCategory(GOParameterCategory& oCategory);

  /**
   * Call this method to retrieve the parameter optimizable flag.
   */
  virtual HRESULT IsOptimizable(CATBoolean& obIsOptimizable);

  /**
   * Call this method to retrieve the parameter executable flag.
   */
  virtual HRESULT IsExecutable(CATBoolean& obIsExecutable);



  /**
   * This method is called to initialize the parameter, that is to say to determine its default value. 
   * This process is performed only once, when the parameter has been successfully elected by a @href GraphicsOptimizerBuilder.
   */
  virtual HRESULT CreateParameter();

  /**
   * Call this method to retrieve the parameter value.
   * Warning! The returned @href GOEOptimizableParameterValue is allocated in this method.
   * IT HAS TO BE DELETED BY CALLER.
   */
  virtual HRESULT GetValue(GOEOptimizableParameterValue** opValue);

  /**
   * Call this method to modify the parameter value.
   */
  virtual HRESULT SetValue(GOEOptimizableParameterValue* ipValue);

  /**
   * This method is called when the parameter value is read from settings. 
   */
  virtual HRESULT ReadValueFromSettings();

  /**
   * This method is called when the parameter value is written in settings. 
   */
  virtual HRESULT WriteValueToSettings();



  /**
   * Call this method to check if the user interface associated to the parameter has been built.
   */
  virtual HRESULT UserInterfaceCreated(CATBoolean& obCreated);

  /**
   * This method is called when the user interface associated to the parameter needs to be builded, but only if
   * the parameter has been successfully elected by a @href GraphicsOptimizerBuilder.
   */
  virtual HRESULT GetUserInterface(CATDialog* iParent, GOEOptimizableParameterUI** oBuilder);

  /**
   * This method is called when the test scenario associated to the parameter needs to be builded, but only if
   * the parameter has been successfully elected by a @href GraphicsOptimizerBuilder.
   * Based on the information contained in the @href GOEOptimizableParameterScenario object, the parameter 
   * can update its value right after the performance and validation tests have been performed.
   */
  virtual HRESULT GetScenario(GOEOptimizableParameterScenario** oBuilder);

protected:

  /**
   * The adapter constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameter(const CATUnicodeString& iName, const GOParameterCategory& iCategory, const GOExecutionMode& iMode);


  /**
   * Call this method to modify the parameter optimizable flag.
   */
  virtual HRESULT SetAsOptimizable(const CATBoolean& ibIsOptimizable);

  /**
   * Call this method to modify the parameter executable flag.
   */
  virtual HRESULT SetAsExecutable(const CATBoolean& ibIsExecutable);


  /**
   * This method is called once to create the value associated to the parameter.
   * This method has to be overriden by the inheriting classes.
   */
  virtual HRESULT CreateParameterValue(GOEOptimizableParameterValue** opValue) = 0;

  /**
   * This method is called to check that the parameter value is correct regarding the streaming process.
   * It is called :
   *  - before writing the value to settings
   *  - after reading the value from settings.
   * For each case, it is possible to modify the parameter value if it is incorrect.
   * This method has to be overriden by the inheriting classes.
   */
  virtual HRESULT ValidateSettingsValue(GOEOptimizableParameterValue* ipValue) = 0;

  /**
   * This method is called once when the user interface associated to the parameter needs to be builded. 
   * This method has to be overriden by the inheriting classes.
   */
  virtual HRESULT CreateUserInterface(CATDialog* iParent, GOEOptimizableParameterUI** oBuilder) = 0;

  /**
   * This method is called once when the test scenario associated to the parameter needs to be builded. 
   * This method has to be overriden by the inheriting classes.
   */
  virtual HRESULT CreateScenario(GOEOptimizableParameterScenario** oBuilder) = 0;

private:

  /**
   * Copy not allowed.
   */
  GOEOptimizableParameter();
  GOEOptimizableParameter(const GOEOptimizableParameter&);
  GOEOptimizableParameter& operator=(const GOEOptimizableParameter&);

  CATUnicodeString _strParameterName;
  
  GOParameterCategory _eParameterCategory;
  GOExecutionMode _eParameterExecutionMode;

  CATBoolean _bIsOptimizable;
  CATBoolean _bIsExecutable;

  CATBoolean _bValueCreated;
  CATBoolean _bUserInterfaceCreated;
  CATBoolean _bTestScenarioCreated;

  GOEOptimizableParameterValue* _pValue;

  GOEOptimizableParameterUI* _pUI;
  GOEOptimizableParameterScenario* _pScenario;
};

//------------------------------------------------------------------

#endif
