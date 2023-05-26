// COPYRIGHT Dassault Systemes 2012
//===================================================================
#ifndef CATSYPModelTagFactory_H
#define CATSYPModelTagFactory_H

#include <CATBaseUnknown.h>
#include <CATStyleProcessor.h>
#include <CATUnicodeString.h>
class CATSYPModelTag;
class CATISAXAttributes_var;
/**
 * This component translate XML tags, attributes and values to CATSYPModelTag classname and attributes.
 */
class ExportedByCATStyleProcessor CATSYPModelTagFactory : public CATBaseUnknown
{
public:
  CATSYPModelTagFactory(const CATUnicodeString& i_URI);
  virtual ~CATSYPModelTagFactory();
  /**
   * @return the namespace URI.
   */
  const CATUnicodeString& GetURI() const;
  /**
   * Creates a model tag from an XML local tag name.
   * The class name of the generated model tag can be different fom the i_localTagName, and some 
   * attributes can be added directly to the returned model tag. 
   * @param i_localTagName the XML local tag name used to create a CATSYPModelTag
   * @param i_spAttributes the XML attributes of the tag, that could be used to determine the creation of the ModelTag. 
   *    Ex : if (i_localTagName==CATVidCtlButton) and one of the attributes is CheckMode=TRUE, create a special CheckButton model tag.
   */
  virtual CATSYPModelTag* CreateModelTag(const CATUnicodeString & i_localTagName, const CATISAXAttributes_var & i_spAttributes) const = 0;
  /**
   * @return a class name corresponding to an xml tag.
   */
  virtual CATUnicodeString GetClassName(const CATUnicodeString& i_tagName) const = 0;
  /**
   * @return the attribute name for a given class name, from an xml attribute.
   */
  virtual CATUnicodeString GetAttributeName(const CATUnicodeString& i_className, const CATUnicodeString& i_attributeName) const = 0;
  /**
   * @return the attribute value string for a given class name and a given propoerty name, from a xml attribute value.
   */
  virtual CATUnicodeString GetAttributeValue(const CATUnicodeString& i_className, const CATUnicodeString& i_propertyName, const CATUnicodeString& i_attributeValue_xml) const = 0;
  
private:
  CATUnicodeString _URI;
};

#endif
