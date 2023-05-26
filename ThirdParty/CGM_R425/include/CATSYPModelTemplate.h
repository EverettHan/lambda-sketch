#ifndef CATSYPModelTemplate_H
#define CATSYPModelTemplate_H

#include <CATStyleProcessor.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATSYPArray.h>
#include <CATSYPHashMap.h>
#include <CATSYPModelTag.h>

class CATSYPModelTag;

/**
* Describes a model template, used to represent 
* the complete view of an object, its bindings, and its triggers.
*/
class ExportedByCATStyleProcessor CATSYPModelTemplate
{
public:
  /** @return the class name the template represents*/
  const CATUnicodeString& GetClassName() const;
  /** @return the class name the template represents*/
  const CATUnicodeString& GetDeclarativeClassName() const;
  /** @return the template name*/
  const CATUnicodeString& GetTemplateName() const;
  /** @return the scope*/
  const CATUnicodeString& GetScope() const;
  /** @return the variation name*/
  const CATUnicodeString& GetVariationName() const;
  /** @return the version number. Default is 0. */
  const int& GetVersion() const;
  /** @return the main tag, top of the model tag tree*/
  CATSYPModelTag* GetTag() const;
  /** Gets the origin of the resource, i.e its file, and a flag indicating if the returned path is relative or absolute.*/
  void GetResourceOrigin(CATUnicodeString& o_resourceFilePath, int& o_resourceFullPathFlag) const;

  void SetBuildFlag(){_buildFlag = 1;}
  int GetBuildFlag() const{return _buildFlag;}

  /** 
  * @return the triggers collection tag, sum of all the triggers on properties
  * of left objects, or objects of the main tag tree.
  */
  CATSYPModelTag* GetTriggersTag() const;
  CATSYPModelTag* GetTemplateStylesTag() const;
  int GetDataTemplateFlag() const;
  CATSYPHashMap<CATUnicodeString, CATSYPModelTag*>* GetModelObjectsMap() const;
  ~CATSYPModelTemplate();
private:
  CATSYPModelTemplate(
    const CATUnicodeString& i_className, 
    const CATUnicodeString& i_declarativeClassName, 
    const CATUnicodeString& i_templateName,
    const CATUnicodeString& i_variationName,
    const int& i_version,
    const CATUnicodeString& i_scope,
    CATSYPModelTag* i_pTag,
    CATSYPHashMap<CATUnicodeString, CATSYPModelTag*>* i_pNamedObjectsMap);
  CATSYPModelTemplate(
    const CATUnicodeString& i_className, 
    const CATUnicodeString& i_declarativeClassName, 
    const CATUnicodeString& i_templateName,
    const CATUnicodeString& i_variationName,
    const int& i_version,
    const CATUnicodeString& i_scope,
    int i_dataTemplateFlag);
  void SetTag(CATSYPModelTag* i_pTag);
  void RemoveTag();
  void SetTriggersTag(CATSYPModelTag* i_pTriggersTag);
  void SetTemplateStylesTag(CATSYPModelTag* i_pTemplateStylesTag);
  //void SetDataTemplateFlag(int i_dataTemplateFlag);
  void SetResourceOrigin(const CATUnicodeString& i_resourceFilePath, int i_resourceFullPathFlag);
  /** Copy Constructor */
  CATSYPModelTemplate(const CATSYPModelTemplate &i_toCopy);
  /** Operator = */
  CATSYPModelTemplate& operator = (const CATSYPModelTemplate &i_toCopy);

  /** Sets the class name the template represents*/
  void SetClassName(const CATUnicodeString& i_className);
  /** Sets the template name*/
  void SetTemplateName(const CATUnicodeString& i_templateName);
  /** Sets the scope*/
  void SetScope(const CATUnicodeString& i_scope);
  /** Sets the variation name*/
  void SetVariationName(const CATUnicodeString& i_variationName);
  /** Sets the version number. Default is 0. */
  void SetVersion(int& i_version);
  void SetDataTemplateFlag(int i_dataTemplateFlag);
  /** Remove the Triggers Tag */
  void RemoveTriggersTag();
  /** Remove the TemplateStyles Tag */
  void RemoveTemplateStylesTag();
  /** Remove the Model Objects Map from the template */
  void RemoveModelObjectsMap();
  /** Delete the Model Objects Map from the template */
  void DeleteModelObjectsMap();
  
  void SetSerializedModelString(const CATUnicodeString& i_serializedModelString){_serializedModelString=i_serializedModelString;}
  const CATUnicodeString& GetSerializedModelString()const{return _serializedModelString;}

protected:
private:
  CATUnicodeString _className;
  CATUnicodeString _declarativeClassName;
  CATUnicodeString _templateName;
  CATUnicodeString _variationName;
  CATUnicodeString _scope;
  int _version;
  CATSYPModelTag* _pTag;
  CATSYPModelTag* _pTriggersTag;
  CATSYPModelTag* _pTemplateStylesTag;
  CATSYPHashMap<CATUnicodeString, CATSYPModelTag*>* _pNamedObjectsMap;
  CATUnicodeString _resourceFilePath;
  int _resourceFullPathFlag;
  unsigned char _dataTemplateFlag;
  int _buildFlag;
  CATUnicodeString _serializedModelString;
  friend class CATSYPStyleProcessor;
  friend class CATSYPSaxModelBuilder;
  friend class VIDDesignController;
  friend class CATSYPDynamicTreeVisitor;
  friend class VIDBindingEdit;
  friend class VIDEditMenuManager;
};

template <> struct CATSYPHashMapHasher<const CATSYPModelTemplate*> 
{
public:
  int ComputeHash(const CATSYPModelTemplate* const& i_key)
  {
#ifdef PLATEFORME_DS64
    return (unsigned int) ( ((CATUINTPTR) i_key) >> 3 );
#else
    return (unsigned int) ( ((CATUINTPTR) i_key) >> 2 );
#endif
  }
};

#endif
