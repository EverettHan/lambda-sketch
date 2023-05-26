#ifndef CATVidMagnitudeValidator_h
#define CATVidMagnitudeValidator_h

#include <VisuDialogEx.h>
#include <CATUnicodeString.h>
#include <CATVidValidator.h>
#include <CATICkeParm.h>

class CATBaseUnknown_var;

class ExportedByVisuDialogEx CATVidMagnitudeValidator : public CATVidDoubleValidator
{
  CATDeclareClass;

public:
  CATVidMagnitudeValidator(const CATICkeParm_var& i_spParm);
  virtual ~CATVidMagnitudeValidator();

  virtual CATVidTextValidationState Validate(const CATUnicodeString& i_strInputString) const { return TXT_VALID; }
  virtual CATVidTextValidationState ValidateKeyStroke(const CATUINT32 i_charCode) const { return TXT_VALID; }
  virtual CATVidTextValidationState FixUp(const CATUnicodeString& i_strInputString, CATUnicodeString& o_strCorrectedString) const { return TXT_VALID; }

  virtual CATUnicodeString GetTextFromDouble(double i_value, const NumericalValidatorInput& i_input);
  virtual double GetDoubleFromText(const CATUnicodeString& i_text, const NumericalValidatorInput& i_input);

private:
  CATICkeParm_var _spParm;
};

#endif // CATVidMagnitudeValidator_h
