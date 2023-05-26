#ifndef CATSYPObjectProperty_H
#define CATSYPObjectProperty_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATSysWeakRef.h>
#include <CATUnicodeString.h>
#include <CATSYPArray.h>
#include <CATSYPPropertyDescriptor.h>
#include <CATSYPTriggerAction.h>
#include <UIVCoreToolsInline.h>

class CATSYPPropertyGetter;
class CATSYPAttachedPropertyGetter;
class CATSYPPropertySetter;
class CATSYPAttachedPropertySetter;
class CATSysWeakRef;

class CATSYPObjectSet
{
private:
  INLINE CATSYPObjectSet():_pTargetWR(NULL),
        _pTargetChildWR(NULL)
  {
    _pTargetSetter = NULL;
    _pTargetAttachedSetter = NULL;
  }
  INLINE CATSYPObjectSet(
    CATBaseUnknown* i_pTarget, 
    CATSYPPropertySetter* i_pTargetSetter, 
    const CATUnicodeString& i_targetPropertyName)
      : _pTargetSetter(i_pTargetSetter),
        _targetPropertyName(i_targetPropertyName),
        _pTargetWR(NULL),
        _pTargetChildWR(NULL)
  {
    if (i_pTarget)
      _pTargetWR = i_pTarget->GetComponentWeakRef();
    if(_pTargetSetter) _pTargetSetter->AddRef();
    _pTargetAttachedSetter = NULL;
  }
  INLINE CATSYPObjectSet(
      CATBaseUnknown* i_pTarget,
      CATBaseUnknown* i_pTargetChild,
       CATSYPAttachedPropertySetter* i_pTargetAttachedSetter, 
      const CATUnicodeString& i_targetPropertyName)
      : _pTargetAttachedSetter(i_pTargetAttachedSetter),
        _targetPropertyName(i_targetPropertyName),
        _pTargetWR(NULL),
        _pTargetChildWR(NULL)
 {
    if (i_pTarget)
      _pTargetWR = i_pTarget->GetComponentWeakRef();
    if (i_pTargetChild)
      _pTargetChildWR = i_pTargetChild->GetComponentWeakRef();
    _pTargetSetter = NULL;
    if(_pTargetAttachedSetter) _pTargetAttachedSetter->AddRef();
  }
  INLINE CATSYPObjectSet(const CATSYPObjectSet& i_object)
  {
    _pTargetWR = i_object._pTargetWR;
    _pTargetWR->AddRef();
    _pTargetChildWR = i_object._pTargetChildWR;
    if (_pTargetChildWR)
      _pTargetChildWR->AddRef();
    _targetPropertyName = i_object._targetPropertyName;

    _pTargetSetter = i_object._pTargetSetter;
    if(_pTargetSetter) _pTargetSetter->AddRef();
    _pTargetAttachedSetter = i_object._pTargetAttachedSetter;
    if(_pTargetAttachedSetter) _pTargetAttachedSetter->AddRef();
  }   
  INLINE ~CATSYPObjectSet()
  {
    CATSysReleasePtr(_pTargetWR);
    CATSysReleasePtr(_pTargetChildWR);
    CATSysReleasePtr(_pTargetSetter);
    CATSysReleasePtr(_pTargetAttachedSetter);
  }
  INLINE void Set(const CATBaseUnknown_var& i_spValue)
  {
    CATBaseUnknown* pTarget = NULL;
    if (_pTargetWR)
      pTarget = _pTargetWR->GiveComponent();
    if (pTarget)
    {
      if (_pTargetSetter != NULL)
        ((CATSYPPropertySetter*)_pTargetSetter)->Set(pTarget, i_spValue);
      else if (_pTargetAttachedSetter != NULL)
        ((CATSYPAttachedPropertySetter*)_pTargetAttachedSetter)->Set(pTarget, (_pTargetChildWR?_pTargetChildWR->GiveComponent():NULL), i_spValue);
      else
        FAILURE("CATSYPObjectSet has no setter function.");
    }
  }
  INLINE void Set_int(int i_value)
  {
    CATBaseUnknown* pTarget = NULL;
    if (_pTargetWR)
      pTarget = _pTargetWR->GiveComponent();
    if (pTarget)
    {
      if (_pTargetSetter != NULL)
        ((CATSYPPropertySetter*)_pTargetSetter)->Set_int(pTarget, i_value);
      else if (_pTargetAttachedSetter != NULL)
        ((CATSYPAttachedPropertySetter*)_pTargetAttachedSetter)->Set_int(pTarget, (_pTargetChildWR?_pTargetChildWR->GiveComponent():NULL), i_value);
      else
        FAILURE("CATSYPObjectSet has no setter function.");
    }
  }
  INLINE void Set_CATUnicodeString(CATUnicodeString i_value)
  {
    CATBaseUnknown* pTarget = NULL;
    if (_pTargetWR)
      pTarget = _pTargetWR->GiveComponent();
    if (pTarget)
    {
      if (_pTargetSetter != NULL)
        ((CATSYPPropertySetter*)_pTargetSetter)->Set_CATUnicodeString(pTarget, i_value);
      else if (_pTargetAttachedSetter != NULL)
        ((CATSYPAttachedPropertySetter*)_pTargetAttachedSetter)->Set_CATUnicodeString(pTarget, (_pTargetChildWR?_pTargetChildWR->GiveComponent():NULL), i_value);
      else
        FAILURE("CATSYPObjectSet has no setter function.");
    }
  }
  INLINE CATSYPPropertyDescriptorBase::Type GetPropertyType()
  {
    CATBaseUnknown* pTarget = NULL;
    if (_pTargetWR)
      pTarget = _pTargetWR->GiveComponent();
    if (_pTargetSetter != NULL)
      return ((CATSYPPropertySetter*)_pTargetSetter)->GetPropertyType();
    else if (_pTargetAttachedSetter != NULL)
      return ((CATSYPAttachedPropertySetter*)_pTargetAttachedSetter)->GetPropertyType();
    else
      return CATSYPPropertyDescriptorBase::Type_Unknown;
  }
  INLINE CATSYPObjectSet& operator= ( const CATSYPObjectSet& i_object)
  {
    if (this == &i_object)return *this;
    CATSysReleasePtr(_pTargetWR);
    _pTargetWR = i_object._pTargetWR;
    _pTargetWR->AddRef();
    CATSysReleasePtr(_pTargetChildWR);
    _pTargetChildWR = i_object._pTargetChildWR;
    if (_pTargetChildWR)_pTargetChildWR->AddRef();
    _targetPropertyName = i_object._targetPropertyName; 

    CATSysReleasePtr(_pTargetSetter);
    _pTargetSetter = i_object._pTargetSetter;
    if(_pTargetSetter) _pTargetSetter->AddRef();

    CATSysReleasePtr(_pTargetAttachedSetter);
    _pTargetAttachedSetter = i_object._pTargetAttachedSetter;
    if(_pTargetAttachedSetter) _pTargetAttachedSetter->AddRef();

    return *this;
  }
  INLINE int operator == ( const CATSYPObjectSet & i_object) const
  {
    return !(*this!=i_object);
  }
  INLINE int operator != ( const CATSYPObjectSet & i_object) const
  {
    if (
      _pTargetWR != i_object._pTargetWR ||
      _pTargetSetter != i_object._pTargetSetter ||
      _pTargetChildWR != i_object._pTargetChildWR ||
      _pTargetAttachedSetter != i_object._pTargetAttachedSetter ||
      _targetPropertyName != i_object._targetPropertyName
      )
      return 1;
    return 0;
  }

public:
  /**Get binding target object*/
  INLINE CATBaseUnknown* GetTarget() const {return (_pTargetWR?_pTargetWR->GiveComponent():NULL);}

  /**Returns != 0 if the binding target object is valid, 0 otherwise */
  INLINE int IsTargetValid() const {return (GetTarget() != NULL);}

  /**Get target child object if the binding concerne the attached property*/
  INLINE CATBaseUnknown* GetTargetChild() const {return (_pTargetChildWR?_pTargetChildWR->GiveComponent():NULL);}

  /**Get the target property name*/
  INLINE const CATUnicodeString& GetTargetPropertyName() const {return _targetPropertyName;}

private:
  CATSysWeakRef * _pTargetWR;
  CATSysWeakRef * _pTargetChildWR;
  CATSYPPropertySetter* _pTargetSetter;
  CATSYPAttachedPropertySetter* _pTargetAttachedSetter;
  CATUnicodeString _targetPropertyName;

private:
  friend class CATSYPBindingTargetData;
  friend class CATSYPModelTagVisitorBuilder;
  friend class SYPDesignerViewBuilder;
  friend class CATSYPTemplateData;
  friend class CATSYPObjectConnector;
  friend class CATSYP;
};

class CATSYPObjectGet
{
private:
  INLINE CATSYPObjectGet():_pSourceWR(NULL), _pSourceChildWR(NULL)
  {
    _pSourceGetter = NULL;
    _pSourceAttachedGetter = NULL;
  }
  INLINE CATSYPObjectGet(
    const CATBaseUnknown* i_pSource, 
    CATSYPPropertyGetter* i_pSourceGetter, 
    const CATUnicodeString& i_sourcePropertyName)
    : _pSourceGetter(i_pSourceGetter),
      _sourcePropertyName(i_sourcePropertyName), 
      _pSourceWR(NULL), 
      _pSourceChildWR(NULL)
  {
    if (i_pSource)
      _pSourceWR = i_pSource->GetComponentWeakRef();
    if(_pSourceGetter) _pSourceGetter->AddRef();
    _pSourceAttachedGetter = NULL;
  }
  INLINE CATSYPObjectGet(
    const CATBaseUnknown* i_pSource,
    const CATBaseUnknown* i_pSourceChild,
    CATSYPAttachedPropertyGetter* i_pSourceGetter, 
    const CATUnicodeString& i_sourcePropertyName)
    : _pSourceAttachedGetter(i_pSourceGetter),
      _sourcePropertyName(i_sourcePropertyName), 
      _pSourceWR(NULL), 
      _pSourceChildWR(NULL)
  {
    if (i_pSource)
      _pSourceWR = i_pSource->GetComponentWeakRef();
    if (i_pSourceChild)
    _pSourceChildWR = i_pSourceChild->GetComponentWeakRef();
    _pSourceGetter = NULL;
    if(_pSourceAttachedGetter) _pSourceAttachedGetter->AddRef();
  }
  INLINE CATSYPObjectGet(const CATSYPObjectGet& i_object)
  {
    _pSourceWR=i_object._pSourceWR;
    if (_pSourceWR)_pSourceWR->AddRef();
    _pSourceChildWR=i_object._pSourceChildWR;
    if (_pSourceChildWR)_pSourceChildWR->AddRef();
    _sourcePropertyName = i_object._sourcePropertyName;

    _pSourceGetter=i_object._pSourceGetter;
    if(_pSourceGetter) _pSourceGetter->AddRef();
    _pSourceAttachedGetter=i_object._pSourceAttachedGetter;
    if(_pSourceAttachedGetter) _pSourceAttachedGetter->AddRef();
  }
  INLINE ~CATSYPObjectGet()
  {
    CATSysReleasePtr(_pSourceWR);
    CATSysReleasePtr(_pSourceChildWR);
    CATSysReleasePtr(_pSourceGetter);
    CATSysReleasePtr(_pSourceAttachedGetter);
  }
  INLINE CATSYPPropertyDescriptorBase::Type GetPropertyType()
  {
    if (_pSourceGetter != NULL)
      return ((CATSYPPropertyGetter*)_pSourceGetter)->GetPropertyType();
    else if (_pSourceAttachedGetter != NULL)
      return ((CATSYPAttachedPropertyGetter*)_pSourceAttachedGetter)->GetPropertyType();
    else
      return CATSYPPropertyDescriptorBase::Type_Unknown;
  }
  INLINE CATBaseUnknown_var Get()
  {
    if (_pSourceWR)
    {
      CATBaseUnknown* pSource=_pSourceWR->GiveComponent();
      if (pSource)
      {
        if (_pSourceGetter != NULL)
          return ((CATSYPPropertyGetter*)_pSourceGetter)->Get(pSource);
        else if (_pSourceAttachedGetter != NULL)
          return ((CATSYPAttachedPropertyGetter*)_pSourceAttachedGetter)->Get(pSource, (_pSourceChildWR?_pSourceChildWR->GiveComponent():NULL));
        else
        {
          FAILURE("CATSYPObjectGet has no getter function.");
          return NULL_var;
        }
      }
    }
    return NULL_var;
  }
  INLINE int Get_int()
  {
    if (_pSourceWR)
    {
      CATBaseUnknown* pSource=_pSourceWR->GiveComponent();
      if (pSource)
      {
        if (_pSourceGetter != NULL)
          return ((CATSYPPropertyGetter*)_pSourceGetter)->Get_int(pSource);
        else if (_pSourceAttachedGetter != NULL)
          return ((CATSYPAttachedPropertyGetter*)_pSourceAttachedGetter)->Get_int(pSource, (_pSourceChildWR?_pSourceChildWR->GiveComponent():NULL));
        else
        {
          FAILURE("CATSYPObjectGet has no getter function.");
          return 0;
        }
      }
    }
    return 0;
  }
  INLINE CATUnicodeString Get_CATUnicodeString()
  {
    if (_pSourceWR)
    {
      CATBaseUnknown* pSource=_pSourceWR->GiveComponent();
      if (pSource)
      {
        if (_pSourceGetter != NULL)
          return ((CATSYPPropertyGetter*)_pSourceGetter)->Get_CATUnicodeString(pSource);
        else if (_pSourceAttachedGetter != NULL)
          return ((CATSYPAttachedPropertyGetter*)_pSourceAttachedGetter)->Get_CATUnicodeString(pSource, (_pSourceChildWR?_pSourceChildWR->GiveComponent():NULL));
        else
        {
          FAILURE("CATSYPObjectGet has no getter function.");
          return "";
        }
      }
    }
    return "";
  }

  INLINE CATSYPObjectGet& operator= ( const CATSYPObjectGet& i_object)
  {
    if (this == &i_object) return *this;
    CATSysReleasePtr(_pSourceWR);
    _pSourceWR=i_object._pSourceWR;
    if (_pSourceWR)_pSourceWR->AddRef();
    CATSysReleasePtr(_pSourceChildWR);
    _pSourceChildWR=i_object._pSourceChildWR;
    if (_pSourceChildWR)_pSourceChildWR->AddRef();

    _sourcePropertyName = i_object._sourcePropertyName;

    if(_pSourceGetter) _pSourceGetter->Release();
    _pSourceGetter=i_object._pSourceGetter;
    if(_pSourceGetter) _pSourceGetter->AddRef();

    if(_pSourceAttachedGetter) _pSourceAttachedGetter->Release();
    _pSourceAttachedGetter=i_object._pSourceAttachedGetter;
    if(_pSourceAttachedGetter) _pSourceAttachedGetter->AddRef();

    return *this;
  }
  INLINE int operator != ( const CATSYPObjectGet & i_object) const
  {
    if (
      _pSourceWR!=i_object._pSourceWR ||
      _pSourceGetter!=i_object._pSourceGetter ||
      _pSourceChildWR!=i_object._pSourceChildWR ||
      _pSourceAttachedGetter!=i_object._pSourceAttachedGetter
      )
      return 1;
    return 0;
  }
  /**Get binding source object*/
  INLINE CATBaseUnknown* GetSource() const {return (_pSourceWR?_pSourceWR->GiveComponent():NULL);}

  /**Get source child object if the binding concerne the attached property*/
  INLINE CATBaseUnknown* GetSourceChild() const {return (_pSourceChildWR?_pSourceChildWR->GiveComponent():NULL);}

  /**Get the source property name*/
  INLINE const CATUnicodeString& GetSourcePropertyName() const {return _sourcePropertyName;}

private:
  CATSysWeakRef*  _pSourceChildWR;
  CATSysWeakRef*  _pSourceWR;
  CATSYPPropertyGetter* _pSourceGetter;
  CATSYPAttachedPropertyGetter* _pSourceAttachedGetter;
  CATUnicodeString _sourcePropertyName;
 
private:
  friend class CATSYPIntrospectableAdapter;
  friend class CATSYPTemplateData;
  friend class CATSYPObjectConnector;
  friend class CATSYPBindingSourceData;
  friend class CATSYPModelTagVisitorBuilder;
  friend class SYPDesignerViewBuilder;
  friend class CATSYP;
  friend class CATSYPStaticPropertySetter;
  friend class CATSYPSetNammedPropertyFunc;
  friend class CATSYPStaticAttachedPropertySetter;
  friend class CATSYPStaticPropertySetter_int;
  friend class CATSYPStaticPropertySetter_CATUnicodeString;
};

class ExportedByIntroInfra CATSYPBindingTargetData
{
public:
  //for arrays
  INLINE CATSYPBindingTargetData()
  {
  }
  INLINE CATSYPBindingTargetData(const CATSYPObjectSet& i_set):_set(i_set)
  {
  }
  INLINE CATSYPBindingTargetData(const CATSYPBindingTargetData& i_objectProperty):_set(i_objectProperty._set)
  {
  }
  /**destructor*/
  INLINE ~CATSYPBindingTargetData()
  {
  }
  INLINE CATSYPBindingTargetData& operator= ( const CATSYPBindingTargetData &i_objectProperty )
  {
    _set = i_objectProperty._set;
    return *this;
  }
  INLINE int operator != ( const CATSYPBindingTargetData &i_item ) const
  {
    return (_set != i_item._set);
  }
  INLINE int operator == ( const CATSYPBindingTargetData &i_item ) const
  {
    return (_set == i_item._set);
  }

  /*get target object**/
  INLINE CATBaseUnknown* GetTarget() {return _set.GetTarget();}
  
  /**Returns != 0 if the binding target object is valid, 0 otherwise */
  INLINE int IsTargetValid() const {return _set.IsTargetValid();}

  /*get target child object if attached binding**/
  INLINE CATBaseUnknown* GetTargetChild() {return _set.GetTargetChild();}

  /**Get the target property name*/
  INLINE const CATUnicodeString& GetTargetPropertyName() const {return _set.GetTargetPropertyName();}

private:
   /** Apply the target value on the binded object property*/
  INLINE void Set(const CATBaseUnknown_var& i_spValue){_set.Set(i_spValue);}
  INLINE void Set_int(int i_value){_set.Set_int(i_value);}
  INLINE void Set_CATUnicodeString(CATUnicodeString i_value){_set.Set_CATUnicodeString(i_value);}
  INLINE CATSYPPropertyDescriptorBase::Type GetPropertyType(){return _set.GetPropertyType();}
private:

  CATSYPObjectSet _set;

  friend class CATSYPIntrospectableAdapter;
};

class ExportedByIntroInfra CATSYPBindingSourceData
{
public:
  INLINE CATSYPBindingSourceData(const CATSYPObjectGet& i_get) : _targets(1), _get(i_get)
  {
  }
  INLINE CATSYPBindingSourceData(const CATSYPBindingSourceData& i_bindingST) : _targets(i_bindingST._targets), _get(i_bindingST._get)
  {
  }
  INLINE ~CATSYPBindingSourceData()
  {
    _targets.QuickRemoveAll();
  }
  INLINE int operator != ( const CATSYPBindingSourceData &i_item ) const
  {
    if (_get!=i_item._get)
      return 1;
    for (int i=0; i<_targets.QuickGetLength(); i++)
    {
      if (_targets.QuickGet(i)!= i_item._targets.QuickGet(i)) return 1;
    }
    return 0;
  }

  /**Gets list of binding target data for non-modifications purposes*/
  INLINE const CATSYPDynArray<CATSYPBindingTargetData>& GetTargets() const {return _targets;}

  /**@copydoc CATSYPObjectGet#GetSource*/
  INLINE CATBaseUnknown* GetSource() {return _get.GetSource();}
  /**@copydoc CATSYPObjectGet#GetSourceChild*/
  INLINE CATBaseUnknown* GetSourceChild() {return _get.GetSourceChild();}
  /**@copydoc CATSYPObjectGet#GetSourcePropertyName*/
  INLINE const CATUnicodeString& GetSourcePropertyName() const {return _get.GetSourcePropertyName();}

private:
  /**Gets list of binding target data for modifications purposes*/
  INLINE CATSYPDynArray<CATSYPBindingTargetData>& GetTargetsList(){return _targets;}

  /**Getter Target property value*/
  INLINE CATBaseUnknown_var Get(){return _get.Get();}
  INLINE int Get_int(){return _get.Get_int();}
  INLINE CATUnicodeString Get_CATUnicodeString(){return _get.Get_CATUnicodeString();}
  INLINE CATSYPPropertyDescriptorBase::Type GetPropertyType(){return _get.GetPropertyType();}

  INLINE CATSYPObjectGet& GetGetObject(){return _get;}

private:
  CATSYPObjectGet _get;
  CATSYPDynArray<CATSYPBindingTargetData> _targets;

  friend class CATSYPIntrospectableAdapter;
};

#endif
