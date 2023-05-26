#ifndef GraphicsOptimizerServices_H
#define GraphicsOptimizerServices_H

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "GraphicsOptimizer.h"

#include "IUnknown.h"
#include "CATBoolean.h"

class GOIOptimizableParameter;
class GOEOptimizableParameterValue;
class GraphicsOptimizerBuilder;

class CATUnicodeString;

typedef HRESULT (*IterateCallback)(GOIOptimizableParameter* ipCurrentParameter);

/**
 * This is the Graphics Optimizer services class.
 * You'll find here several methods to retrieve information about the Graphics Optimizer state.
 */
class ExportedByGraphicsOptimizer GraphicsOptimizerServices
{
public:
  
  /**
   * Call this method to check if the graphics configuration used for last tests execution has changed.
   * This method is going to check that the current graphics configuration (card name, driver and package)
   * is the same than the last one used for the tests.
   * If any of this information has changed, TRUE is returned. Otherwise, FALSE is returned. 
   */
  static HRESULT HasGraphicsConfigurationChanged(CATBoolean& obChanged);

  /**
   * Call this method to save the current graphics configuration.
   * Input argument is used to signify if a "has changed" check has to be performed before saving, or not.
   * If a check is asked and the configuration has not changed, nothing is saved.
   */
  static HRESULT SaveGraphicsConfiguration(CATBoolean ibSaveIfChanged);

  /**
   * Call this method to iterate on all parameters associated to a builder.
   */
  static HRESULT IterateOnAllParameters(GraphicsOptimizerBuilder* ipBuilder, IterateCallback iCallbackFunction);

  /**
   * Call this method to retrieve the parameter value as it is streamed in settings.
   * Input arguments are the parameter name and default value (if nothing is found in settings)
   * Output argument is the parameter value, as read from settings.
   */
  static HRESULT ReadParameterValueFromSettings(const CATUnicodeString& iParameterName, GOEOptimizableParameterValue* ioParameterValue);

  /**
   * Call this method to specify if large font has to be used to display information message in the viewer.
   */
  static HRESULT SetInformationMessageSize(CATBoolean ibUseLargeFont);

  /**
   * Call this method to check if large font is used to display information message in the viewer.
   */
  static HRESULT GetInformationMessageSize(CATBoolean& obLargeFontUsed);

  /**
   * Call this method to retrieve the position and size of the optimizer window..
   */
  static HRESULT GetOptimizerWindowSize(int& oXPos, int& oYPos, int& oWidth, int& oHeight);

private:

  /**
   * Copy not allowed.
   */
  GraphicsOptimizerServices();
  GraphicsOptimizerServices(const GraphicsOptimizerServices&);
  GraphicsOptimizerServices& operator=(const GraphicsOptimizerServices&);
  ~GraphicsOptimizerServices();

  static int GetScreenSize(int& oScreenWidth, int& oScreenHeight);

  static CATBoolean _sbUseLargeFont;
  static unsigned int _suiGraphicsOptimizerVersion;
};

#endif // #ifndef GraphicsOptimizerServices_H
