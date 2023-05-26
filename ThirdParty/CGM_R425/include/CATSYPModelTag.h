#ifndef CATSYPModelTag_H
#define CATSYPModelTag_H

#include <CATStyleProcessor.h>
#include <CATSYPMacros.h>
#include <CATSYPArray.h>
#include <CATSYPHashMap.h>
#include <CATUnicodeString.h>
#include <CATStyleProcessor.h>
#include <UIVCoreToolsInline.h>
#include <CATSYPRefCounted.h>
#include <CATBaseUnknown_WR.h>

class CATSYPModelAttachedProperty;
class CATSYPModelProperty;
class CATSYPModelContainer;
class CATSYPModelTagVisitor;
class CATSYPMetaClass;

class ExportedByCATStyleProcessor CATSYPModelTag : public CATSYPRefCounted
{
public:
  /**Describes the type of the tag. Used by CATSYPModelTagVisitor*/
  enum TagType{Default=0, Trigger, EventTrigger, Storyboard, TriggerCollection, Setter, Animation, TemplateStyles, TemplateStyle};
  /** Constructor with args */
  CATSYPModelTag(const CATUnicodeString& i_URI, const CATUnicodeString& i_className, CATSYPModelTag::TagType i_classType=Default);
  /** Constructor with args */
  CATSYPModelTag(const CATUnicodeString& i_URI, CATSYPModelTag::TagType i_classType);
  /** @return the object class name*/
  INLINE const CATUnicodeString& GetClassName() const
  {
    return _className;
  }
  const CATUnicodeString& GetDeclarativeClassName() const;
  /** @return the URI*/
  INLINE const CATUnicodeString& GetURI() const
  {
    return _URI;
  }
  /** Sets the template name of the tag*/
  INLINE void SetTemplateName(const CATUnicodeString& i_templateName)
  {
    _templateName = i_templateName;
  }
  /** @return the template name*/
  INLINE const CATUnicodeString& GetTemplateName() const
  {
    return _templateName;
  }
  /** @return if a template is defined on the tag*/
  INLINE CATBoolean GetTemplateFlag() const
  {
    return !_templateName.IsNull();
  }
  /** 
  * Sets the syp name of the tag if defined, that will be used 
  * for binding purpose and triggering by the style processor, 
  * to connect model tag each other.
  */
  INLINE void SetSypName(const CATUnicodeString& i_sypName)
  {
    _sypName = i_sypName;
  }
  /** @return the syp name*/
  INLINE const CATUnicodeString& GetSypName() const
  {
    return _sypName;
  }
  /** @return the attached properties of the object, for modification purpose*/
  INLINE CATSYPDynArray<CATSYPModelAttachedProperty*>& GetAttachedProperties()
  {
    return _attachedProperties;
  }
  /** @return the attached properties of the object*/
  INLINE const CATSYPDynArray<CATSYPModelAttachedProperty*>& GetAttachedProperties() const
  {
    return _attachedProperties;
  }

  /** @return attached property defined by i_propName name and  i_pChildTag, the attached child tag */
  CATSYPModelAttachedProperty* GetAttachedProperty(CATUnicodeString i_propName, const CATSYPModelTag* i_pChildTag);

  /** @return the properties of the object, for modification purpose */
  INLINE const CATSYPDynArray<CATSYPModelProperty*>& GetProperties() const
  {
    return _properties;
  }
  /** @return the properties of the object */
  INLINE CATSYPDynArray<CATSYPModelProperty*>& GetProperties()
  {
    return _properties;
  }

  /** @return property defined by i_propName name*/
  CATSYPModelProperty* GetProperty(CATUnicodeString i_propName);

  int GetChildContainerName(CATSYPModelTag* i_pChildTag, CATUnicodeString& o_name);

  /** @return the containers of the object, for modification purpose */
  INLINE CATSYPDynArray<CATSYPModelContainer*>& GetContainers()
  {
    return _containerList;
  }
  /** @return the containers of the object */
  INLINE const CATSYPDynArray<CATSYPModelContainer*>& GetContainers() const
  {
    return _containerList;
  }

  INLINE const CATSYPMetaClass* GetSYPMetaClass() const
  {
    return _pSYPMetaClass;
  }

  /** @return the children for the given container name of the object */
  const CATSYPDynArray<CATSYPModelTag*>& GetChildren(const CATUnicodeString& i_containerName) const;

  /** @return if i_pChildTag is a direct child for 'this' tag */
  int IsChildTag(CATSYPModelTag* i_pChildTag);

  /**
  * Add a child to the given container name of the object. 
  * Creates the container if it doesn't exist.
  */
  void AddChild(const CATUnicodeString& i_containerName, CATSYPModelTag* i_pChild);
  void RemoveChild(const CATUnicodeString& i_containerName, CATSYPModelTag* i_pChild);
  void DeleteChild(const CATUnicodeString& i_containerName, CATSYPModelTag* i_pChild);
  //set child tag on index
  int InsertChild(const CATUnicodeString& i_containerName,CATSYPModelTag* i_pChild,int i_index);

  // void DeleteAllChild(const CATUnicodeString& i_containerName, CATSYPModelTag* i_pChild);
  void ReplaceChild(const CATUnicodeString& i_containerName, CATSYPModelTag* i_pChildToReplace,CATSYPModelTag* i_pReplacement);
  //.

  /** @return direct father tag in hierarchical model tag tree */
  CATSYPModelTag* GetParentTag();
  
  /** 
  * Sets the father tag of "this" model tag in order to find hierarchical parents 
  */
  void SetParentTag(CATSYPModelTag* i_pTag);

  /** @return related introspectable object to this modelTag */
  CATBaseUnknown_var GetObject()const;
  
  /** 
  * Sets related introspectable object to this modelTag
  */
  void SetObject(CATBaseUnknown_var i_spObject);

  /** @return the type of the model tag*/
  CATSYPModelTag::TagType GetType()const
  {
    return _classType;
  }
  
  /**return 1 if i_propName is bound else return 0*/
  int IsBound(const CATUnicodeString i_propName);

  /**
  * Clean all the properties on the tag.
  */
  void CleanProperties();
  /**
  * Calls CleanProperties on the tag, and on all of its children.
  * Thus avoiding cycling references of other tags, since bound properties AddRef the source tag.
  */
  void CleanAllProperties();
  /**
   * Entry point of the visitor on the tag.
   * Calls recursively VisitEnter, Visit and VisitLeave on the input visitor,
   * to go through the model tag hierarchy.
   * @param i_visitor the visitor.
   * @see CATSYPModelTagVisitor
   * @see CATSYPModelTagVisitorBuilder
   */
  int Accept(CATSYPModelTagVisitor &i_visitor) const;

protected:
  /** Destructor */
  virtual ~CATSYPModelTag();
private:
  /** Copy Constructor */
  CATSYPModelTag(const CATSYPModelTag &i_toCopy);
  /** Operator = */
  CATSYPModelTag& operator = (const CATSYPModelTag &i_toCopy);
private:
  CATSYPMetaClass* _pSYPMetaClass;
  CATSYPModelTag::TagType _classType;
  CATUnicodeString _className;
  CATUnicodeString _URI;
  CATUnicodeString _sypName;
  CATUnicodeString _templateName;
  CATSYPDynArray<CATSYPModelProperty*> _properties;
  CATSYPDynArray<CATSYPModelAttachedProperty*> _attachedProperties;
  CATSYPDynArray<CATSYPModelContainer*> _containerList;
  CATSYPModelTag* _pParentTag;
  CATBaseUnknown_WR _wrObject;
};

/**
* Specialization of CATSYPHashMapHasher template for const CATSYPModelTag*.
*/
template <> struct CATSYPHashMapHasher<const CATSYPModelTag*> 
{
public:
  int ComputeHash(const CATSYPModelTag* const& i_key) {
#ifdef PLATEFORME_DS64
    return (unsigned int) ( ((CATUINTPTR) i_key) >> 3 );
#else
    return (unsigned int) ( ((CATUINTPTR) i_key) >> 2 );
#endif
  }
};

#endif
