#ifndef CATVidCtlTweakerfloat_h
#define CATVidCtlTweakerfloat_h

// COPYRIGHT Dassault Systemes 2008

#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>
#include <CATVidBoxing.h>

class ExportedByVisuDialogEx CATVidCtlTweakerfloat : public CATVidCtlTweaker
{
  CATDeclareTweaker(float);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerfloat();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();
  virtual CATBoolean SupportsRange() const;
  virtual CATBoolean GetUseRangeState() const;
  virtual CATBoolean IsValueValid(const CATBaseUnknown_var& i_value) const;
  virtual void CATSYPModifyMinimumProperties();
  virtual void CATSYPModifyMaximumProperties();

  void SetValueAsDouble(double i_x);
  double GetValueAsDouble();

  /**
   * Gets the minimum value
   */
  float GetMinimumValue() const;

  /**
   * Sets the minimum value
   * @param i_minVal
   *  The value to set.
   */
  void SetMinimumValue(float i_minVal);

  /**
   * Gets the maximum value
   */
  float GetMaximumValue() const;

  /**
   * Sets the maximum value
   * @param i_maxVal
   *  The value to set.
   */
  void SetMaximumValue(float i_maxVal);

  void SetMinimumValueAsDouble(double i_minVal);
  double GetMinimumValueAsDouble() const;
  void SetMaximumValueAsDouble(double i_maxVal);
  double GetMaximumValueAsDouble() const;

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

protected:

  virtual ~CATVidCtlTweakerfloat();

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
  CATVidCtlTweakerfloat (CATVidCtlTweakerfloat &);
  CATVidCtlTweakerfloat& operator=(CATVidCtlTweakerfloat& original);

  int _sliderValue;
  CATBoolean _sliderLock;
  CATBoolean _valueLock;
};

#endif // CATVidCtlTweakerfloat_h
