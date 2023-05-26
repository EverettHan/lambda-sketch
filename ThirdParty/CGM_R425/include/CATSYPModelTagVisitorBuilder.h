#ifndef CATSYPModelTagVisitorBuilder_H
#define CATSYPModelTagVisitorBuilder_H

#include <CATSYPModelTagVisitor.h>
#include <CATStyleProcessor.h>
#include <CATSYPStyleProcessor.h>
#include <CATSYPMacros.h>
#include <CATSYPArray.h>
#include <CATBaseUnknown_var.h>
#include <CATISYPIntrospectable.h>
#include <CATSYPErrorReport.h>

class CATSYPTxtErrorReport;
class CATSYPModelTag;
class CATSYPStyleProcessor;
class CATSYPTemplateData;
class CATSYPModelContainer;
class CATSYPMetaClass;
class CATSYPModelPropertyBase;
class CATSYPModelSetter;
class CATSYPSetter;
class CATSYPModelTrigger;
class CATSYPTrigger;
class CATSYPEventTrigger;
class CATSYPObjectConnector;
class CATSYPObjectGet;
class CATSYPObjectSet;

class ExportedByCATStyleProcessor CATSYPModelTagVisitorBuilder : public CATSYPModelTagVisitor
{
  FORCE_STACK_ALLOCATION();
protected:
  static CATBaseUnknown_var sGetSYPProperty(
    const CATUnicodeString& i_propertyName,
    const CATSYPMetaClass& i_SYPMetaClass, 
    const CATBaseUnknown_var& i_spObject);

  static void sSetSYPAttachedProperty( 
    const CATBaseUnknown_var &i_index, 
    const CATUnicodeString &i_name, 
    const CATBaseUnknown_var &i_spPropertyValue, 
    const CATSYPMetaClass& i_SYPMetaClass, 
    const CATBaseUnknown_var& i_spObject);

  void  sSetProperty( 
    const CATUnicodeString &i_name, 
    const CATBaseUnknown_var &i_spPropertyValue, 
    const CATSYPMetaClass& i_SYPMetaClass, 
    const CATBaseUnknown_var& i_spObject);

  static CATISYPCollection_var GetImplicitCollection(const CATBaseUnknown_var& spObject, const CATSYPMetaClass& i_SYPMetaClass);
  static CATISYPPresenter_var GetImplicitPresenter(const CATBaseUnknown_var& spObject, const CATSYPMetaClass& i_SYPMetaClass);
  int CheckProperty(const CATSYPMetaClass* i_pSYPMetaClass, const CATUnicodeString& i_propertyName);
  int BuildPropertyFromMetaClass(const CATSYPMetaClass* i_pSYPMetaClass, const CATUnicodeString& i_propertyName, const CATUnicodeString& i_propertyValue, CATBaseUnknown_var& o_output);

  static void sRegisterLeftObjectBinding(CATSYPObjectConnector*_pObjectConnector, const CATUnicodeString &i_name, const CATSYPObjectGet& i_getter, const CATSYPObjectSet& i_setter, CATBoolean i_initWhenConnectFlag);

public:
  CATSYPModelTagVisitorBuilder(CATSYPStyleProcessor& i_styleProcessor, const CATISYPIntrospectable_var& i_spLeftObject, const CATSYPModelTemplate* i_pLeftTemplate, CATBoolean i_buildEmbeddedTemplatesFlag);
  ~CATSYPModelTagVisitorBuilder();
  /** @copydoc CATSYPModelTagVisitor#Visit */
  virtual void Visit(const CATSYPModelTag& i_tag); 
  /** @copydoc CATSYPModelTagVisitor#VisitEnter */
  virtual int VisitEnter(const CATSYPModelTag& i_tag); 
  /** @copydoc CATSYPModelTagVisitor#VisitChildrenEnter */
  virtual int VisitChildrenEnter(const CATSYPModelContainer& i_tag); 
  /** @copydoc CATSYPModelTagVisitor#VisitChildrenLeave */
  virtual int VisitChildrenLeave(const CATSYPModelContainer& i_tag);
  /** @copydoc CATSYPModelTagVisitor#VisitLeave */
  virtual int VisitLeave(const CATSYPModelTag& i_tag);
  /** 
  * Runs the build process, that will construct the view widget, 
  * that has to be recovered by calling #GetViewWidget
  */
  virtual void Run(CATSYPTemplateData * o_pTemplateData = NULL);
  /**
  * Recovers the generated object, representing the introspectable object.
  */
  const CATBaseUnknown_var& GetViewWidget()const;

protected:
  class StackObject
  {
  public:
    StackObject():_childrenObjectList(0)
    {
      _pMetaClass = NULL;
      _pTag = NULL;
    }
    StackObject(const CATSYPModelTag& i_tag, const CATBaseUnknown_var& i_spObject, const CATSYPMetaClass* i_pMetaClass):_childrenObjectList(0)
    {
      _pTag = &i_tag;
      _spObject = i_spObject;
      _pMetaClass = i_pMetaClass;
    }
    StackObject(const StackObject& i_toCopy):_childrenObjectList(i_toCopy._childrenObjectList)
    {
      _pTag = i_toCopy._pTag;
      _spIntro = i_toCopy._spIntro;
      _spObject = i_toCopy._spObject;
      _currentContainerName = i_toCopy._currentContainerName;
      _pMetaClass = i_toCopy._pMetaClass;
    }
    StackObject& operator= ( const StackObject & i_toCopy)
    {
      _pTag = i_toCopy._pTag;
      _spIntro = i_toCopy._spIntro;
      _spObject = i_toCopy._spObject;
      _childrenObjectList = i_toCopy._childrenObjectList;
      _currentContainerName = i_toCopy._currentContainerName;
      _pMetaClass = i_toCopy._pMetaClass;
      return *this;
    }
    ~StackObject()
    {
      _pTag = NULL;
      _spIntro = NULL;
      _childrenObjectList.RemoveAll();
    }
    void SetCurrentContainerName ( const CATUnicodeString& i_currentContainerName)
    {
      _currentContainerName = i_currentContainerName;
    }
    const CATUnicodeString& GetCurrentContainerName () const
    {
      return _currentContainerName;
    }
    const CATSYPModelTag& GetTag() const
    {
      return *_pTag;
    }
    const CATBaseUnknown_var& GetObject() const
    {
      return _spObject;
    }
    const CATISYPIntrospectable_var& GetIntrospectable()
    {
      if (_spIntro == NULL_var)
        _spIntro=_spObject;
      return _spIntro;
    }
    const CATSYPDynArray<CATBaseUnknown_var>& GetChildren() const 
    {
      return _childrenObjectList;
    };
    CATSYPDynArray<CATBaseUnknown_var>& GetChildren() 
    {
      return _childrenObjectList;
    };
    const CATSYPMetaClass* GetSYPMetaClass() const
    {
      return _pMetaClass;
    }
  private:
    const CATSYPMetaClass* _pMetaClass;
    const CATSYPModelTag* _pTag;
    CATISYPIntrospectable_var _spIntro;
    CATBaseUnknown_var _spObject;
    CATSYPDynArray<CATBaseUnknown_var> _childrenObjectList;
    CATUnicodeString _currentContainerName;
  };


protected:
  CATSYPModelTagVisitorBuilder(const CATSYPModelTagVisitorBuilder &);
  CATSYPModelTagVisitorBuilder &operator=(const CATSYPModelTagVisitorBuilder &);

  void AddErrorToReport(const CATUnicodeString& i_message, CATSYPErrorReport::Severity i_errorType=CATSYPErrorReport::Error);
  void ProceedDataBinding(CATSYPModelTag* i_pTag, CATSYPHashMap<const CATSYPModelTag*, CATBaseUnknown_var>& i_objectMap);
  void Connect(CATSYPIntrospectableAdapter* spBindingSourceObject, const CATSYPMetaClass* spBindingSourceObjectMC, CATSYPIntrospectableAdapter* spBindingTargetObject, const CATSYPMetaClass* spBindingTargetObjectMC, CATSYPModelPropertyBase* i_pProperty, CATBaseUnknown* spBindingTargetObjectChild);
  void FillTemplateData(CATSYPTemplateData * o_pTemplateData);

  CATISYPIntrospectable_var& GetLeftObject();
  CATSYPStyleProcessor& GetStyleProcessor();
  const CATSYPModelTemplate* GetLeftTemplate();
  CATSYPHashMap<const CATSYPModelTag*, CATBaseUnknown_var>& GetObjectMap();
  CATSYPDynArray<StackObject>& GetObjectsHierarchyStack();
  CATSYPDynArray<CATSYPTriggerBase*>& GetTriggerToApplyArray() { return _pTriggerToApplyArray; }
  CATSYPDynArray<CATISYPIntrospectable_var>& GetTriggerToApplySourceArray() { return _pTriggerToApplySourceArray; }

  void ConnectViewToModel(const CATISYPIntrospectable_var& i_spLeftObject,const CATSYPModelTemplate* i_pLeftTemplate, const StackObject& i_topStackObject, CATBaseUnknown_var& o_spView);
  void VisitTriggers(const CATSYPModelTag* i_pTriggers,CATSYPDynArray<StackObject>& i_objectsHierarchyStack);

  void TreatStoryBoard(const CATSYPModelTag& i_tag,const CATSYPMetaClass* i_pMetaClass,const CATBaseUnknown_var& i_spLeftObject,const CATBaseUnknown_var& i_spObject,CATSYPHashMap<const CATSYPModelTag*, CATBaseUnknown_var>& i_objectMap,StackObject& i_stackObject);
  void TreatSetters(const CATSYPModelSetter& i_tag, CATSYPSetter* i_pSetter);
  void TreatTrigger(const CATSYPModelTrigger& i_tag,const CATBaseUnknown_var& i_spLeftObject, CATSYPTriggerBase* i_pTrigger,CATSYPHashMap<const CATSYPModelTag*, CATBaseUnknown_var>& i_objectMap,StackObject& i_stackObject);
  void TreatTriggerCollection(const CATSYPModelTag& i_tag,const CATBaseUnknown_var& i_spObject,const CATSYPMetaClass* i_pMetaClass);
  void TreatTemplate(const CATSYPModelTag& i_tag,const CATBaseUnknown_var& i_spObject,CATSYPStyleProcessor& i_styleProcessor,CATBaseUnknown_var& o_spView);
  void TreatTriggers(const CATSYPModelTag& i_tag, const CATSYPModelTemplate* i_pLeftTemplate,const CATISYPIntrospectable_var& i_spLeftObject);

  void TreatContainer(const CATSYPModelContainer& i_tag,CATSYPDynArray<StackObject>& i_objectsHierarchyStack);

  void TreatAttachedProperties(const CATSYPModelTag& i_tag,  const CATSYPMetaClass* i_pMetaClass,const CATBaseUnknown_var& i_spObject);
  void TreatStandardProperties(const CATSYPModelTag& i_tag, const CATBaseUnknown_var& i_spObject);


private:
  CATSYPTemplateData* _pTemplateData;
  CATSYPTxtErrorReport* _pErrorReport;
  CATSYPStyleProcessor& _styleProcessor;
  CATBaseUnknown_var _spView;
  CATISYPIntrospectable_var _spLeftObject;
  CATSYPIntrospectableAdapter* _pLeftObjectAdapter;
  const CATSYPModelTemplate* _pLeftTemplate;
  const CATSYPMetaClass* _pLeftObjecSYPMetaClass;
  int _buildEmbeddedTemplatesFlag;
  CATSYPHashMap<const CATSYPModelTag*, CATBaseUnknown_var> _objectMap;
  CATSYPDynArray<StackObject> _objectsHierarchyStack;

  CATSYPDynArray<CATSYPTriggerBase*> _pTriggerToApplyArray;
  CATSYPDynArray<CATISYPIntrospectable_var> _pTriggerToApplySourceArray;

};
#endif
