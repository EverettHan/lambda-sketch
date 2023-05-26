#ifndef CATSYPTranslatorAttribute_H
#define CATSYPTranslatorAttribute_H

#include <CATBaseUnknown.h>
#include <CATSYPTranslatorElement.h>
#include <CATStyleProcessor.h>
#include <CATUnicodeString.h>

class ExportedByCATStyleProcessor CATSYPTranslatorAttribute : public CATSYPTranslatorElement
{
  CATDeclareClass;

public:
  CATSYPTranslatorAttribute();
  virtual ~CATSYPTranslatorAttribute();
};

#endif
