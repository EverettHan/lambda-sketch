#ifndef CATSYPTranslatorElement_H
#define CATSYPTranslatorElement_H

#include <CATBaseUnknown.h>
#include <CATStyleProcessor.h>
#include <CATUnicodeString.h>


/**
 * 
 */
class ExportedByCATStyleProcessor CATSYPTranslatorElement : public CATBaseUnknown
{
  CATDeclareClass;

public:
  CATSYPTranslatorElement();
  virtual ~CATSYPTranslatorElement();

  /**
   * Sets input string for translation.
   */
  void SetInput(const CATUnicodeString& i_input);
  /**
   * @return input string for translation.
   */
  const CATUnicodeString& GetInput() const;
  /**
   * Sets ouput string for translation.
   */
  void SetOutput(const CATUnicodeString& i_output);
  /**
   * @return ouput string for translation.
   */
  const CATUnicodeString& GetOutput() const;

private:
  CATUnicodeString _input;
  CATUnicodeString _output;
};


#endif
