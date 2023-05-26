#ifndef CATSYPModelAttachedProperty_H
#define CATSYPModelAttachedProperty_H

#include <CATStyleProcessor.h>
#include <CATSYPModelPropertyBase.h>
#include <CATUnicodeString.h>
#include <UIVCoreToolsInline.h>
class CATSYPModelTag;
class CATBaseUnknown_var;
class CATSYPPropertyDescriptorBase;
/**
 * Class that describes an attached property. It is used with a 
 * CATSYPModelTag that specify the object that own the attached property.
 */
class ExportedByCATStyleProcessor CATSYPModelAttachedProperty : public CATSYPModelPropertyBase{
public:
  /** Constructor*/
  CATSYPModelAttachedProperty(){}
  /** Constructor with args*/
  CATSYPModelAttachedProperty(CATSYPModelTag* i_pChildObject, const CATBaseUnknown_var& i_spCreatedProperty, const CATSYPAttachedPropertyDescriptor& i_propertyDescriptor, const CATUnicodeString& i_attachedPropertyName);
  /** Constructor with args*/
  CATSYPModelAttachedProperty(CATSYPModelTag* i_pChildObject, const CATUnicodeString& i_propertyValue, const CATSYPAttachedPropertyDescriptor& i_propertyDescriptor, const CATUnicodeString& i_attachedPropertyName);
  /** For a case where the value is not a binding, nor a value, but a CATSYPModelTag
   * Used in CATSYPSaxModelBuilder::CreateAnimation */
  CATSYPModelAttachedProperty(CATSYPModelTag* i_pChildObject, CATSYPModelTag* i_pTagValue, const CATSYPAttachedPropertyDescriptor& i_propertyDescriptor, const CATUnicodeString& i_attachedPropertyName);
  /** Constructor with args*/
  CATSYPModelAttachedProperty(CATSYPModelTag* i_pChildObject, CATSYPModelBinding* i_pBinding, const CATSYPAttachedPropertyDescriptor& i_propertyDescriptor, const CATUnicodeString& i_attachedPropertyName);
  /** @return the child object the property is attached to */
  INLINE const CATSYPModelTag* GetChildObject() const{return _pChildObject;}
  /** When the value is not binding, not a CBU, but a CATSYPModelTag  */
  INLINE const CATSYPModelTag* GetTagValue() const{return _pTagValue;}
  /** @return the child object the property is attached to */
  inline void SetChildObject(CATSYPModelTag* i_pChildObject) 
  {
    _pChildObject = i_pChildObject;
    if(NULL != _pChildObject)_pChildObject->AddRef();
  }
  INLINE const CATUnicodeString& GetStringPropertyValue() const{return _propertyValue;}
  INLINE void SetStringPropertyValue(const CATUnicodeString& i_propertyValue){_propertyValue = i_propertyValue;}
  INLINE const CATSYPAttachedPropertyDescriptor& GetAttachedPropertyDescriptor(){return _attachedPropertyDescriptor;}
protected:
  /** Destructor */
  ~CATSYPModelAttachedProperty()
  {
    if(_pTagValue) _pTagValue->Release();
  }
private:
  /** = operator*/
  CATSYPModelAttachedProperty & operator = (const CATSYPModelAttachedProperty &i_toCopy);
  /** Copy Constructor*/
  CATSYPModelAttachedProperty(const CATSYPModelAttachedProperty &i_toCopy);
private:
  CATSYPModelTag* _pChildObject;
  CATSYPModelTag* _pTagValue;
  CATUnicodeString _propertyValue;
  CATSYPAttachedPropertyDescriptor _attachedPropertyDescriptor;
};

#endif
