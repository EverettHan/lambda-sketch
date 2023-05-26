// COPYRIGHT DASSAULT SYSTEMES 2011
#ifndef CATSYPTemplateData_h
#define CATSYPTemplateData_h
// System framework
#include <CATBaseUnknown.h>
#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATSYPHashMap.h>
#include <UIVCoreToolsInline.h>
#include <CATSYPArray.h>

class CATSysWeakRef;
class CATSYPObjectGet;
class CATSYPObjectSet;
class CATSYPMetaClass;
class CATISYPIntrospectable_var;
class LeftObjectEventListeningStruct;
class CATSysWeakRef;
class CATSYPTriggerBase;
class CATSYPObjectConnector;
/**
 *
 * @see CATSYPStyleProcessor
 */
class ExportedByIntroInfra CATSYPTemplateData : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** Constructor.
   * @param i_useAConnectorToModelObjectFlag allow to create an objectConnector that 
   * Will allow to change dynamically the model object that is represented by the template.
   * @see CATSYPObjectConnector
   */
  CATSYPTemplateData(int i_useAConnectorToModelObjectFlag=0);
  /**@return the template name*/
  const CATUnicodeString& GetTemplateName() const;
  /** @return the variation name */
  const CATUnicodeString& GetVariationName() const;
  /** Retrieve an object from ist registration name*/
  CATBaseUnknown* FindFromName(const CATUnicodeString& i_sypName) const;
  /**
   * @return the top object build by the syle processor from a template.
   */
  CATBaseUnknown* GetViewObject() const;
  /**
   * @return the connector relying the model to its view. Note that is can be NULL if 
   * the TemplateData didn't specify in its constructor to use it.
   * @see #CATSYPTemplateData
   * @see CATSYPObjectConnector
   */
  CATSYPObjectConnector* GetModelObjectConnector() const{return _pObjectConnector;}
protected:
  /** Destructor*/
  ~CATSYPTemplateData();
private:
  /** Accessible only by friendship {*/
  /**
   * The style processor will use this name to recover a template, associated to
   * the variation name and the IsA value of the implementation.
   * @param i_templateName the name of the template to associate to the object.
   */
  void SetTemplateName(const CATUnicodeString& i_templateName);
  /**
   * The style processor will use this name to recover a template, associated to
   * the template name and the IsA value of the implementation.
   * This property is used to define variations of a same template. For example a slider
   * can be horizontal or vertical. So for a same look (corresponding to a template name), 
   * to templates will have to be defined. This variation name have to be setted by the Object, 
   * and is a part of its model. In a slider, a SetOrientation method will internally modify the 
   * variation name if its representation, and refresh it.
   * Note that an templated object must declare its variation, so people creating its reprentation template
   * can create all the required variations.
   * Note that if no variation name is assigned, a default template will be used.
   * @param i_variationName the name of the variatioon of the template to associate to the object.
   */
  void SetVariationName(const CATUnicodeString& i_variationName);
  HRESULT RegisterName(const CATUnicodeString& i_sypName, CATBaseUnknown* i_pObject);
  /** Sets the top object build by the style processor. A weak ref on it is kept. This method can be called only once on an instance.*/
  void SetViewObject(CATBaseUnknown* i_pViewObject);
  /** }*/

private:
  CATSYPObjectConnector* _pObjectConnector;
  CATUnicodeString _templateName;
  CATUnicodeString _variationName;
  CATSysWeakRef* _pViewObjectWR;
  CATSYPHashMap<CATUnicodeString, CATSysWeakRef*> _namedObjectsMap;
  friend class CATSYPModelTagVisitorBuilder;
public:
  /** @deprecated, use FindFromName instead...*/
  INLINE CATBaseUnknown* FindName(const CATUnicodeString& i_sypName) const{return FindFromName(i_sypName);}
};

#endif // CATSYPTemplateData_h
