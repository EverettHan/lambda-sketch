#ifndef CATSYPModelTemplateStyle_H
#define CATSYPModelTemplateStyle_H

#include <CATStyleProcessor.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATSYPArray.h>
#include <CATSYPHashMap.h>
#include <CATSYPModelTag.h>

class CATSYPModelTag;
class CATSYPModelSetter;

/**
* Describes a templatestyle, used to configure template dynamically.
*/
class ExportedByCATStyleProcessor CATSYPModelTemplateStyle : public CATSYPModelTag
{
public:
  /** @return the factory name*/
  const CATUnicodeString& GetName() const { return _name; }

  virtual ~CATSYPModelTemplateStyle(){}
private:
  CATSYPModelTemplateStyle(const CATUnicodeString& i_name) :CATSYPModelTag("", CATSYPModelTag::TemplateStyle) { _name = i_name;}
  /** Copy Constructor */
  CATSYPModelTemplateStyle(const CATSYPModelTemplateStyle &i_toCopy);
  /** Operator = */
  CATSYPModelTemplateStyle& operator = (const CATSYPModelTemplateStyle &i_toCopy);
private:
  CATUnicodeString _name;
  friend class CATSYPStyleProcessor;
  friend class CATSYPSaxModelBuilder;
  friend class VIDDesignController;
};

#endif
