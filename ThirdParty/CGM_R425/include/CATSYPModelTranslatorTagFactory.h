// COPYRIGHT Dassault Systemes 2012
//===================================================================
#ifndef CATSYPModelTranslatorTagFactory_H
#define CATSYPModelTranslatorTagFactory_H

#include <CATBaseUnknown.h>
#include <CATStyleProcessor.h>
#include <CATUnicodeString.h>
#include <CATSYPModelTagFactory.h>

class CATSYPModelTag;
class CATISAXAttributes_var;
class CATSYPStyleProcessor;
class CATSYPTemplateData;
class CATSYPTranslatorGroup;

/**
 * This component translate XML tags, attributes and values to CATSYPModelTag classname and attributes.
 */
class ExportedByCATStyleProcessor CATSYPModelTranslatorTagFactory : public CATSYPModelTagFactory
{
  CATDeclareClass;

public:
  CATSYPModelTranslatorTagFactory(const CATUnicodeString& i_URI, const CATUnicodeString& i_alias, const CATUnicodeString& i_c2plusDomain);
  virtual ~CATSYPModelTranslatorTagFactory();
  /**
   * Factory used to create a Translator ModelTagFactory.
   * Creates a new CATSYPModelTranslatorTagFactory, the loads it (see CATSYPModelTranslatorTagFactory::Load).
   * @see Load
   */
  static CATSYPModelTranslatorTagFactory* CreateTranslatorTagFactory(const CATUnicodeString& i_URI, const CATUnicodeString& i_alias, const CATUnicodeString& i_c2plusDomain);
  /** 
   * Loads the XMl file describing the translation.
   * It must be placed in {CATInstallPath}/resources/CATSYPTranslator
   * It must be called CATSYPTranslator_{alias}_{c2plusdomain}.xml
   */
  void Load();
  /**
   * @return the C++ domain
   */
  const CATUnicodeString& GetC2PlusDomain() const;
  /**
   * @return the alias of the namespace
   */
  const CATUnicodeString& GetAlias() const;
  /**
   * Creates a model tag from an XML local tag name.
   * The class name of the generated model tag can be different fom the i_localTagName, and some 
   * attributes can be added directly to the returned model tag. 
   * @param i_localTagName the XML local tag name used to create a CATSYPModelTag
   * @param i_spAttributes the XML attributes of the tag, that could be used to determine the creation of the ModelTag. 
   *    Ex : if (i_localTagName==CATVidCtlButton) and one of the attributes is CheckMode=TRUE, create a special CheckButton model tag.
   */
  virtual CATSYPModelTag* CreateModelTag(const CATUnicodeString & i_localTagName, const CATISAXAttributes_var & i_spAttributes) const;
  /**
   * @return a class name corresponding to an xml tag.
   */
  virtual CATUnicodeString GetClassName(const CATUnicodeString& i_tagName) const;
  /**
   * @return the attribute name for a given class name, from an xml attribute.
   */
  virtual CATUnicodeString GetAttributeName(const CATUnicodeString& i_className, const CATUnicodeString& i_attributeName) const;
  /**
   * @return the attribute value string for a given class name and a given propoerty name, from a xml attribute value.
   */
  virtual CATUnicodeString GetAttributeValue(const CATUnicodeString& i_className, const CATUnicodeString& i_propertyName, const CATUnicodeString& i_attributeValue_xml) const;

public:
  /** @copydoc CATISYPTemplate::SetTemplateName */
  virtual void SetTemplateName(const CATUnicodeString& i_templateName);
  /** @copydoc CATISYPTemplate::GetTemplateName */
  virtual const CATUnicodeString& GetTemplateName() const;
  /** @copydoc CATISYPTemplate::SetVariationName */
  virtual void SetVariationName(const CATUnicodeString& i_variationName);
  /** @copydoc CATISYPTemplate::GetVariationName */
  virtual const CATUnicodeString& GetVariationName() const;
  /** @copydoc CATISYPTemplate::SetTemplatedView */
  virtual void SetTemplatedView(CATBaseUnknown_var& i_spView, CATSYPTemplateData* i_pTemplateData);

protected:
  /** 
   * @return the TranslatorTagFactory StyleProcessor singleton.
   */
  static CATSYPStyleProcessor& GetTranslatorTagFactoryStyleProcessor();

private:

private:
  CATUnicodeString _c2plusDomain;
  CATUnicodeString _alias;
  CATUnicodeString _templateName;
  CATUnicodeString _variationName;
  CATBoolean _built;
  CATSYPTranslatorGroup* _pTranslatorGroup;
};

#endif
