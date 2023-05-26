//===================================================================
// COPYRIGHT Dassault Systemes 2010/06/14
//===================================================================
//  2010/06/14 Creation: am2
//===================================================================
#ifndef CATVidTweakerValidatorAbstract_H
#define CATVidTweakerValidatorAbstract_H

#include <VisuDialog.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
/**
 * Validates the values of a tweaker.
 */
class ExportedByVisuDialog CATVidTweakerValidatorAbstract : public CATBaseUnknown
{
  enum ValidationCode{
    /** Validation ok, without any modification*/
    ValidationSuccess,
    /** Validation failed, without any modification*/
    ValidationFail,
    /** Validation failed, but value has been corrected */
    ValidationModify
  };
  enum ErrorCode
  {
    /** No error occured */
    NoError=0,
    /** Value was out of bounds*/
    OutOfBounds,
    /** Undefined error */
    CustomError
  };
  /**
   *
   */
  class ValidationResult
  {
  public:
    ValidationResult();
    ValidationResult(CATVidTweakerValidatorAbstract::ValidationCode i_validationCode, CATVidTweakerValidatorAbstract::ErrorCode i_errorCode);
    ValidationResult(CATVidTweakerValidatorAbstract::ValidationCode i_validationCode, const CATUnicodeString& i_errorMessage);
    ValidationCode GetValidationCode ()const;
    ErrorCode GetErrorCode ()const;
    const CATBaseUnknown_var& GetCorrectedValue();
    const CATUnicodeString& GetCustomErrorMessage();
  private:
    ValidationResult(const ValidationResult& i_toCopy);
    ValidationCode _validationCode;
    ErrorCode      _errorCode;
    CATBaseUnknown_var _correctedValue;
    CATUnicodeString _errorMessage;
  };
public:
  /**
   * Validates the input data, and modify it if necessary.
   * @param i_spValue the value to validate.
   * @return a ValidationResult
   */
   virtual CATVidTweakerValidatorAbstract::ValidationResult Validate(const CATBaseUnknown_var& i_spValue)=0;
};

//-----------------------------------------------------------------------
#endif

