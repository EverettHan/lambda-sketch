// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATVidCtlDoubleSpinBox.h
// Header definition of CATVidCtlDoubleSpinBox
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2009  Creation: 3dPLM
//===================================================================
#ifndef CATVidCtlDoubleSpinBox_H
#define CATVidCtlDoubleSpinBox_H

#include <VisuDialog.h>
//#include <CATVidCtl.h>
#include <CATVid.h>
//#include <CATDlgUtility.h>
#include <CATUnicodeString.h>
#include <CATVidColor.h>
#include <CATVidCtlAbstractSpinBox.h>

class CATVidCtlLineEditor;
class CATVidCtlButton;
class CATVidDoubleValidator;
/**
* A basic SpinBox of doubles.
* <b>Role</b>:
* This widget is used to edit doubles, either by entering its value,
* or by using increment/decrement buttons.
* You can specify minimum and maximum values, a prefix, a suffix.
*/
class ExportedByVisuDialog CATVidCtlDoubleSpinBox: public CATVidCtlAbstractSpinBox
{
  CATDeclareClass;

public:

  enum Range { Left = 0, Within, Right };

  /**
  * Constructs a CATVidCtlDoubleSpinBox with standard style.
  * @param i_pParent
  *   The parent of the widget.
  * @param i_pIdentifier
  *   The name of the widget.
  */
  static CATVidCtlDoubleSpinBox* CreateSpinBox(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
  * Constructs a CATVidCtlDoubleSpinBox.
  * No associsated style, use static factory CreateEditor
  */
  CATVidCtlDoubleSpinBox ();

  /**
  * Get the value edited by the spinner
  */
  double GetValue();
  /**
  * Set the value edited in the spinner
  * If value is not valid then it is corrected and then set
  */
  CATINT32 SetValue(double i_value);

  /**
  * Gets the precision of the double spin box.
  */
  CATINT32 GetDecimalPlaces();

  /**
  * Sets the precision of the double spin box.
  */
  void SetDecimalPlaces(CATINT32 i_decimalPlaces);

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
  * Returns the step value.
  * When the user uses the arrows to change the spin box's value,
  * the value will be incremented/decremented by the amount of the single step.
  */
  double GetSingleStepValue();

  /**
  * Sets the step value.
  * When the user uses the arrows to change the spin box's value,
  * the value will be incremented/decremented by the amount of the single step.
  * @param i_singleStepValue
  *  The value to set.
  */
  void SetSingleStepValue(double i_singleStepValue);

  /**
  * Gets the minimum value of the spin box.
  */
  double GetMinimumValue();

  /**
  * Gets the maximum value of the spin box.
  */
  double GetMaximumValue();

  /**
  * Sets the maximum value of the spin box.
  * @param i_maxVal
  *  The value to set.
  */
  void SetMaximumValue(double i_maxVal);

  /**
  * Sets the minimum value of the spin box.
  * @param i_minVal
  *  The value to set.
  */
  void SetMinimumValue(double i_minVal);

  /*
  * Virtual function that is called whenever the user triggers a step.
  * The steps parameter indicates how many steps were taken,
  * If you subclass CATVidCtlAbstractSpinBox you must reimplement this function.
  * Note that this function is called even if the resulting value will be outside the bounds of minimum and maximum.
  * It's this function's job to handle these situations.
  * @param i_nbSteps
  *   The number of steps to change the value
  */
  virtual CATINT32 StepBy(CATINT32 i_nbSteps);

  double GetValueFromText();
  
protected:
  virtual ~CATVidCtlDoubleSpinBox ();

private:
  double GetLastValidValue();
  CATUnicodeString GetTextFromValue(double i_value);
  CATBoolean IsNewVersionForODT();
  void UpdateCursorPosition();

  friend class CATVidTstSpinBox;

};
//-----------------------------------------------------------------------

#endif
