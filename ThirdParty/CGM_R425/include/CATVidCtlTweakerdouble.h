#ifndef CATVidCtlTweakerdouble_h
#define CATVidCtlTweakerdouble_h

// COPYRIGHT Dassault Systemes 2008

#include <VisuDialog.h>
#include <CATVidCtlTweaker.h>
#include <CATVidBoxing.h>
#include <CATBoolean.h>
class CATVidValidator;

class ExportedByVisuDialog CATVidCtlTweakerdouble: public CATVidCtlTweaker
{
  CATDeclareTweaker(double);

public:
  
  // Standard constructors and destructors
  CATVidCtlTweakerdouble();

  // Overriden methods
  virtual CATBoolean SupportsRange() const;
  virtual CATBoolean GetUseRangeState() const;
  virtual CATBoolean IsValueValid(const CATBaseUnknown_var& i_value) const;
  virtual void CATSYPModifyMinimumProperties();
  virtual void CATSYPModifyMaximumProperties();

  /**
   * Gets the minimum value
   */
  double GetMinimumValue() const;

  /**
   * Sets the minimum value
   * @param i_minVal
   *  The value to set.
   */
  void SetMinimumValue(double i_minVal);

  /**
   * Gets the maximum value
   */
  double GetMaximumValue() const;

  /**
   * Sets the maximum value
   * @param i_maxVal
   *  The value to set.
   */
  void SetMaximumValue(double i_maxVal);

  /**
   * Returns how many decimals will be use for displaying doubles.
   */
  int GetDecimalPlaces() const;

  /**
   * Sets how many decimals will be use for displaying doubles.
   */
  void SetDecimalPlaces(int i_decimalPlaces);

  /**
   * Returns the exponent used to switch between standard notation and exponential notation for big values.<br>
   * For example, if this exponent is 6, values greater that 10e6 will be shown with the exponential notation.
   */
  int GetHighExponentProperty() const;

  /**
   * Sets the exponent used to switch between standard notation and exponential notation for big values.<br>
   * For example, if this exponent is 6, values greater that 10e6 will be shown with the exponential notation.
   */
  void SetHighExponentProperty(int i_exponentValue);

  /**
	  * Returns the exponent used to switch between standard notation and exponential notation for low values.<br>
	  * For example, if this exponent is 6, values lower that 10e-6 will be shown with the exponential notation.
   */
  int GetLowExponentProperty() const;

  /**
	  * Sets the exponent used to switch between standard notation and exponential notation for low values.<br>
	  * For example, if this exponent is 6, values lower that 10e-6 will be shown with the exponential notation.
   */
  void SetLowExponentProperty(int i_exponentValue);

  /**
   * Returns TRUE if the trailing zeros must be displayed, FALSE otherwise.
   */
  CATBoolean GetShowTrailingZerosFlag() const;

  /**
   * Specifies whether the trailing zeros must be displayed or not.
   */
  void SetShowTrailingZerosFlag(CATBoolean i_flag);

  /**
   * Sets the slider value.
   * This value must be contained between 0 and 100.
   */
  void SetSliderValue(int i_sliderValue);

  /**
   * Returns the slider value.
   * This value is contained between 0 and 100.
   */
  int GetSliderValue() const;

  void SetUnitSymbol(const CATUnicodeString& i_unitSymbol);
  CATUnicodeString GetUnitSymbol();

  /**
  * Get the Line validator
  */
  CATVidValidator* GetTextValidator();

  /**
  * Set the Line validator
  */
  void SetTextValidator(CATVidValidator* i_pValidator);

protected:

  virtual ~CATVidCtlTweakerdouble ();

  // Overriden methods
  virtual void OnValueChanged();

  /**
   * Updates the tweaker value from the slider value.
   * The slider value is contained between 0 and 100.
   */
  void _UpdateTweakerFromSlider();

  /**
   * Updates the slider value from the tweaker value.
   * The slider value must be contained between 0 and 100.
   */
  void _UpdateSliderFromTweaker();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerdouble (CATVidCtlTweakerdouble &);
  CATVidCtlTweakerdouble& operator=(CATVidCtlTweakerdouble& original);

  int _decimalPlaces;
  int _highExponentProperty;
  int _lowExponentProperty;
  int _sliderValue;
  CATBoolean _sliderLock;
  CATBoolean _valueLock;
  CATBoolean _bShowTrailingZerosFlag;
  CATUnicodeString _unitSymbol;
  CATVidValidator * _pValidator;
};

#endif // CATVidCtlTweakerdouble_h
