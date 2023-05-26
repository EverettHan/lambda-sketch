#ifndef GraphicsOptimizerBuilder_H
#define GraphicsOptimizerBuilder_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"

#include "GOIOptimizableParameter.h"
#include "CATErrorDef.h"

class GraphicsOptimizerSetOfParameters;
class CATDialog;
class GOTestRunner;

/**
 * This is the Graphics Optimizer document builder base-class.
 * You have to inherit from this class and override the necessary methods for being able to access
 * a set of optimizable parameters, defined by their name, their user interface and their test scenario.
 * The content of this set of parameters is left to the charge of the inherited class as all parameters are going
 * to publish their name and you'll make your choice among all parameters accessible.
 */
class ExportedByGraphicsOptimizer GraphicsOptimizerBuilder : public CATEventSubscriber
{
  CATDeclareClass;

public:
  
  /**
   * This event is dispatched when all tests have been performed.
   */
  CATDeclareCBEvent (OPTIMIZER_TESTS_FINISHED);

  /**
   * Destructor.
   */
  virtual ~GraphicsOptimizerBuilder();

  /**
   * Call this method to retrieve the set of optimizable parameters managed by the builder.
   */
  HRESULT GetOptimizableParameters(GraphicsOptimizerSetOfParameters** oUsedParameters);

  /**
   * Call this method to run the test scenario of all optimizable parameters managed by the builder.
   */
  void RunTests(CATDialog* pRenderingContext);

  /**
   * This method is called to stream all the Optimizable Parameters values.
   */
  void DoStreamParametersValues();

protected:

  /**
   * The Graphics Optimizer document builder constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GraphicsOptimizerBuilder();

  /**
   * This method is called when an optimizable parameter asks for being taken into account by the builder.
   * Each parameter publishes its name and, depending of the builder answer, it is taken into account or not.
   */
  virtual HRESULT DoConsiderOptimizableParameter(const CATUnicodeString& iParameterName, CATBoolean& oDoConsider) = 0;

private:

  /**
   * Copy not allowed.
   */
  GraphicsOptimizerBuilder(const GraphicsOptimizerBuilder&);
  GraphicsOptimizerBuilder& operator=(const GraphicsOptimizerBuilder&);

  HRESULT RetrieveOptimizableParameters();
  HRESULT RegisterParameters();
  HRESULT RegisterParameter(GOIOptimizableParameter* ipParameterToRegister);

  void OnEndOfTests(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

  GraphicsOptimizerSetOfParameters* _pSetOfParameters;
  CATBoolean _bSearchForParametersExecuted;

  GOTestRunner* _pTestRunner;
  CATCallback _EndOfTestsCB;
};

#endif // #ifndef GraphicsOptimizerBuilder_H
