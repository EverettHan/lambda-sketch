#ifndef CATVidCtlSpinBox_H
#define CATVidCtlSpinBox_H

// COPYRIGHT Dassault Systemes 2006

#include <VisuDialog.h>
#include <CATVid.h>
#include <CATUnicodeString.h>
#include <CATVidCtlAbstractSpinBox.h>

class CATVidCtlLineEditor;
class CATVidCtlButton;

/**
* A basic SpinBox of integers.
* <b>Role</b>:
* This widget is used to edit integers, either by entering its value,
* or by using increment/decrement buttons.
* You can specify minimum and maximum values, a prefix, a suffix.
*/
class ExportedByVisuDialog CATVidCtlSpinBox: public CATVidCtlAbstractSpinBox
{
  CATDeclareClass;

public:
  /**
  * Constructs a CATVidCtlSpinBox with standard style.
  * @param i_pParent
  *   The parent of the widget.
  * @param i_pIdentifier
  *   The name of the widget.
  */
  static CATVidCtlSpinBox* CreateSpinBox(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
  * Constructs a CATVidCtlSpinBox.
  * No associated style, use static factory CreateEditor
  */
  CATVidCtlSpinBox ();
  /**
  * Virtual function that is called whenever the user triggers a step. 
  * The steps parameter indicates how many steps were taken, 
  * If you subclass CATVidCtlAbstractSpinBox you must reimplement this function. 
  * Note that this function is called even if the resulting value will be outside the bounds of minimum and maximum. 
  * It's this function's job to handle these situations.
  */
  virtual CATINT32 StepBy(CATINT32 i_nbSteps);
  /**
  * Returns the spin box's text with no prefix(), suffix() or leading or trailing whitespace. 
  */
  CATUnicodeString GetCleanText();
  /**
  * Sets the spin box's text value (e.g. "5"). Text will then be displayed with prefix and/or suffix or 
  * as special value text if set already. 
  * @param i_strCleanText
  *  The text value to set.
  */
  CATINT32 SetCleanText(CATUnicodeString i_strCleanText);
  /**
  * Gets the maximum value of the spin box.
  */
  CATINT32 GetMaximumValue();
  /**
  * Sets the maximum value of the spin box.
  * @param i_maxVal
  *  The value to set.
  */
  void SetMaximumValue(CATINT32 i_maxVal);
  /**
  * Gets the minimum value of the spin box.
  */
  CATINT32 GetMinimumValue();
  /**
  * Sets the minimum value of the spin box.
  * @param i_minVal
  *  The value to set.
  */
  void SetMinimumValue(CATINT32 i_minVal);
  /**
  * Returns the step value.
  * When the user uses the arrows to change the spin box's value,
  * the value will be incremented/decremented by the amount of the single step. 
  */
  CATINT32 GetSingleStepValue();
/**
  * Sets the step value.
  * When the user uses the arrows to change the spin box's value,
  * the value will be incremented/decremented by the amount of the single step. 
  * @param i_singleStepValue
  *  The value to set.
  */
  void SetSingleStepValue(CATINT32 i_singleStepValue);

  /**
  * If the value entered in spinner is in intermidiate mode, This function sets the valid value in spinner. 
  * Value is set according to the correction mode set on the control.
  */

  virtual CATINT32 SetCorrectedValue();
  /**
  * Set the value in the spinner
  * If value is not valid then it is corrected and then set
  */
  CATINT32 SetValue(CATINT32 i_value);
  /**
  * Get the value of the text in the spinner
  */
  CATINT32 GetValue();

  CATINT32 GetValueFromText();
  

protected:
  virtual ~CATVidCtlSpinBox();

private:

  // Copy constructor and equal operator
  CATVidCtlSpinBox (CATVidCtlSpinBox &);
  CATVidCtlSpinBox& operator=(CATVidCtlSpinBox& original);
  CATUnicodeString GetTextFromValue(double i_value);
  CATBoolean IsNewVersionForODT();
  CATINT32 GetCorrectedValue(CATINT32 i_value);
  CATINT32 SetValue(CATINT32 i_value,CATBoolean i_bValidate);
  CATINT32 GetLastValidValue();
  void UpdateCursorPosition();

  CATUnicodeString      _strPrefix;
  CATUnicodeString      _strSuffix;
  CATUnicodeString      _strLastInterpretedText;

  friend class CATVidTstSpinBox;
};

#endif
