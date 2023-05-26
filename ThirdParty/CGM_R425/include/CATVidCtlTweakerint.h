#ifndef CATVidCtlTweakerint_h
#define CATVidCtlTweakerint_h

// COPYRIGHT Dassault Systemes 2008

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>
class CATVidValidator;

class ExportedByVisuDialogEx CATVidCtlTweakerint : public CATVidCtlTweaker
{
  CATDeclareTweaker(int);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerint();

  // Overriden methods
  virtual CATBoolean SupportsRange() const;
  virtual CATBoolean GetUseRangeState() const;
  virtual CATBoolean IsValueValid(const CATBaseUnknown_var& i_value) const;
  virtual void CATSYPModifyMinimumProperties();
  virtual void CATSYPModifyMaximumProperties();

  void SetLabel(const CATUnicodeString& i_Label);
  CATUnicodeString GetLabel() const;

  /**
   * Gets the minimum value
   */
  int GetMinimumValue() const;

  /**
   * Sets the minimum value
   * @param i_minVal
   *  The value to set.
   */
  void SetMinimumValue(int i_minVal);

  /**
   * Gets the maximum value
   */
  int GetMaximumValue() const;

  /**
   * Sets the maximum value
   * @param i_maxVal
   *  The value to set.
   */
  void SetMaximumValue(int i_maxVal);

  /**
  * Get the Line validator
  */
  CATVidValidator* GetTextValidator();

  /**
  * Set the Line validator
  */
  void SetTextValidator(CATVidValidator* i_pValidator);

protected:

  virtual ~CATVidCtlTweakerint();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerint (CATVidCtlTweakerint &);
  CATVidCtlTweakerint& operator=(CATVidCtlTweakerint& original);

  CATUnicodeString _Label;
  CATVidValidator* _pValidator;
};

#endif // CATVidCtlTweakerint_h
