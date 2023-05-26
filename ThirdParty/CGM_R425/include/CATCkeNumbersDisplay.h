#ifndef __CATCkeNumbersDisplay__
#define __CATCkeNumbersDisplay__

/**
* @level Protected
* @usage U1
*/

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 98
//===========================================================================
//
// class CATCkeNumbersDisplay
// Offers services to convert values to string in respect to numbers display
// settings
//
//===========================================================================
// Usage Notes:
//
// 
//===========================================================================
// Oct. 99   Creation                                   TVQ
//===========================================================================

// KnowledgeInterfaces
#include "CATICkeMagnitude.h"
#include "CATICkeParm.h"
#include "CATICkeUnit.h"
#include "CATILieUnitsSheetSettingAtt.h"
// System
#include "CATUnicodeString.h"
// LiteralFeatures
#include "CATCkeScaleManagement.h"
#include "CATLifDictionary.h"

#define REALS_DECIMALS_NB 9

// This class contains services dedicated to transformation of various parameters formats to strings in respect to NumberDisplay settings (property sheet Units).
class ExportedByCATLifDictionary CATCkeNumbersDisplay
{
public:
  /**
  * Enum that contains the definition of formats used to display numbers.<br>
  * Auto can be used only with the method ParameterToString<br>
  * ShowTrailignZeros can be combined with others modes (Auto|ShowTrailingZeros for example)<br>
  * AsAnInput uses the setting for values that are read/write
  * AsAMeasure uses the setting for values that are read-only if the setting Same Display is 0
  */
  enum DisplayMode
  {
    Auto = 1,
    AsAnInput = 2,
    AsAMeasure = 4,
    ShowTrailingZeros = 8
  };

  // Returns the number of decimals to show with input magnitude for read/write values.
  static int GetRWDecimalsNbProperty(CATICkeMagnitude_var const & iMagnitude);

  // Returns the number of decimals to show with input magnitude for read-only values.
  // If the setting Same Display for read/write and read-only values is set, returns the same value as GetRWDecimalsNbProperty.
  static int GetRODecimalsNbProperty(CATICkeMagnitude_var const & iMagnitude);

  // Returns 1 if the setting Show Trailing Zeros is set, 0 otherwise.
  static int GetShowTrailingZerosProperty();

  // Returns 1 if the setting Same Display for read/write and read-only parameters is set, 0 otherwise.
  static int GetSameDisplayForRORWProperty();

  // Returns the exposant used to switch between standard notation and exponential notation for big values.
  // For example, if this exposant is 6, values greater that 10e6 will be shown with the exponential notation.
  static int GetHighExposantProperty();

  // Returns the exposant used to switch between standard notation and exponential notation for low values.<br>
  // For example, if this exposant is 6, values lower that 10e-6 will be shown with the exponential notation.
  static int GetLowExposantProperty();


  // Converts a double into a string formatted according to the settings (units and NumberDisplay). The result is shown with the input unit.
  static HRESULT DoubleToString(double iValue, CATICkeUnit_var const & iUnit, CATUnicodeString & oResult, CATCkeNumbersDisplay::DisplayMode iDisplayMode = AsAnInput);

  // Converts a double into a string formatted according to the settings (units and NumberDisplay). The result is shown with input unit symbol.
  static HRESULT DoubleToString(double iValue, char const * iUnitSymbol, CATUnicodeString & oResult, CATCkeNumbersDisplay::DisplayMode iDisplayMode = AsAnInput);

  // Converts a mks value of input magnitude into a string formatted according to the settings.
  static HRESULT MksDoubleToString(double iMksValue, CATICkeMagnitude_var const & iMagnitude, CATUnicodeString & oResult, CATCkeNumbersDisplay::DisplayMode iDisplayMode = AsAnInput);
  static HRESULT MksDoubleToString(double iMksValue, CATICkeMagnitude_var const & iMagnitude, CATUnicodeString & oResult, CATCkeNumbersDisplay::DisplayMode iDisplayMode, CATCkeScale iScale);

  // Converts a model value (a value expressed in storage unit) of input magnitude into a string formatted according to the settings.
  static HRESULT ModelDoubleToString(double iModelValue, CATICkeMagnitude_var const & iMagnitude, CATUnicodeString & oResult, CATCkeNumbersDisplay::DisplayMode iDisplayMode = AsAnInput);

  // Converts a double in a string according to its unit (the resulting string won't use the current unit of the magnitude if the input unit isn't the current unit of its magnitude).
  // Warning : if you use this method with a unit which isn't the current one of its magnitude, you won't respect Units settings.
  // The process to get a magnitude from a unit is time consuming. If you already know the magnitude, use the last argument, the method will be much faster.
  static HRESULT DoubleToStringForceUnit(double iValue, CATICkeUnit_var const & iUnit, CATUnicodeString & oResult, CATCkeNumbersDisplay::DisplayMode iDisplayMode, CATICkeMagnitude_var const & iMagnitude);
  static HRESULT DoubleToStringForceUnit(double iValue, CATICkeUnit_var const & iUnit, CATUnicodeString & oResult, CATCkeNumbersDisplay::DisplayMode iDisplayMode = AsAnInput, CATBoolean iIso = FALSE, CATICkeMagnitude_var const & iMagnitude = NULL_var);

  // Converts a double into a string according to iNbMaxDecimals and iShowTrailingZeros arguments. For example :
  //   DoubleToUString(0.123456789, 6, 0) returns "0.123457", and DoubleToUString(0.12, 4, 1) returns "0.1200".
  //   DoubleToUStringPlusUnit(0.123456789, 6, , "mm", 0) returns "0.123457mm", and DoubleToUStringPlusUnit(0.12, 4, "mm", 1) returns "0.1200mm"
  static CATUnicodeString DoubleToUString(double iValue, int iNbMaxDecimals, int iShowTrailingZeros = 0, CATBoolean iIso = FALSE);
  static CATUnicodeString DoubleToUStringPlusUnit(double iValue, int iNbMaxDecimals, char const * iUnitSymbolToAdd, int iShowTrailingZeros = 0, CATBoolean iIso = FALSE);

  /* DO NOT USE */ static char * DoubleToString(double doNotUse1, int doNotUse2, int doNotUse3 = 0, CATBoolean doNotUse4 = FALSE); /* DO NOT USE */
  /* DO NOT USE */ static char * DoubleToStringPlusUnit(double doNotUse1, int doNotUse2, char const * doNotUse3, int doNotUse4 = 0, CATBoolean doNotUse5 = FALSE);	/* DO NOT USE */
};

#endif
