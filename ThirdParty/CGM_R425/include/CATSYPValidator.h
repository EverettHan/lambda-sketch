#ifndef CATSYPValidator__H
#define CATSYPValidator__H

#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATBaseUnknown.h>
#include <CATISYPIntrospectable.h>

class ExportedByIntroInfra CATSYPValidator : public CATBaseUnknown
{
  CATDeclareClass;

public:
  class ExportedByIntroInfra ValidationData
  {
  public:
    ValidationData(CATBaseUnknown_var i_spNewValue, const CATUnicodeString & i_editedProperty, CATISYPIntrospectable_var i_spDataItem, int i_columnNumber, int i_rowNumber);
    ~ValidationData();
    
    CATBaseUnknown_var GetOldValue() const;
    CATBaseUnknown_var GetNewValue() const;
    const CATUnicodeString & GetEditedProperty() const;
    CATISYPIntrospectable_var GetDataItem() const;
    int GetRowNumber() const;
    int GetColumnNumber() const;

  private:
    ValidationData();
    ValidationData(const ValidationData &);
    ValidationData& operator=(const ValidationData &);

    CATBaseUnknown_var _spNewValue;
    CATUnicodeString _editedProperty;
    CATISYPIntrospectable_var _spDataItem;
    int _columnNumber;
    int _rowNumber;
  };

	  /**
   * Possible icons used to display an informative message in a window.
   */
  enum ActionIcon { 
    /** No icon used */
    NoIcon = 0, 
    /** Icon indicating that the message is asking a question */
    Question, 
    /** Icon indicating that the message is purely informative */
    Information, 
    /** Icon indicating that the message is a warning, but can be dealt with */
    Warning, 
    /** Icon indicating that the message represents a critical problem */
    Critical,
    /** Icon indicating that the message represents a success */
    Successful
  };

	struct OutputMessage{
		CATSYPValidator::ActionIcon ActionIcon;
		CATUnicodeString Title;
		CATUnicodeString DetailedText;
		CATUnicodeString InformativeText;
		CATUnicodeString Text;
	};

  CATSYPValidator();
  virtual ~CATSYPValidator();

	virtual int Validate(ValidationData & data) {return 1;};

	virtual int ValidateAndRaiseMessage(ValidationData & data, OutputMessage & o_message) {return 1;};

private:
  CATSYPValidator(const CATSYPValidator &);
  CATSYPValidator& operator= (const CATSYPValidator &);
};

#endif
