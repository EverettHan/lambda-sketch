#ifndef CATSYPModelBinding_H
#define CATSYPModelBinding_H

#include <CATUnicodeString.h>
#include <CATSYPStyleProcessor.h>
#include <UIVCoreToolsInline.h>

#include <CATSYPModelTag.h>
/** 
 * Describes a binding, that is a bind with another object an one of its properties
 * This binding can be created in sypstyle by using the arobase sign.
 */
class ExportedByCATStyleProcessor CATSYPModelBinding
{
public:
  /**@return the property name*/
  INLINE const CATUnicodeString& GetPropertyName() const
  {
    return _propertyName;
  }
  /** Sets the binding mode. Only in case of binding mode downgrade*/
  void SetBindingMode(CATSYPStyleProcessor::BindingMode i_bindingMode);
  /**@return the binding mode*/
  INLINE CATSYPStyleProcessor::BindingMode GetBindingMode() const
  {
    return _bindingMode;
  }
  /**
   * @return the source model tag, 
   * that is the model tag corresponding to the ElementName property.
   */
  INLINE CATSYPModelTag* GetSourceTag () const
  {
    return _pSourceTag;
  }
  /**
   * @return the source PropertyDescriptor.
   */
  INLINE const CATSYPPropertyDescriptor& GetSourcePropertyDescriptor() const
  {
    return _sourcePropertyDescriptor;
  }
  /**@return the element name*/
  INLINE const CATUnicodeString& GetElementName() const
  {
    if(GetSourceTag() && strcmp(_elementName,GetSourceTag()->GetSypName()))
      return GetSourceTag()->GetSypName();
    return _elementName;
  }
private:
  /**
   * Constructor.
   * @param i_sourcePropertyName the name of the property to bind with.
   * @param i_elementName the syp:name of the object to bind with. 
   * @param i_bindingMode the type of binding to create.
   * @param i_pSourceTag the tag corresponding to the syp:name string can be found in the binding definition. can be NULL.
   * @see CATSYPStyleProcessor#BindingMode
   */
  CATSYPModelBinding(
    const CATUnicodeString& i_sourcePropertyName, 
    const CATUnicodeString& i_elementName, 
    CATSYPStyleProcessor::BindingMode i_bindingMode, 
    CATSYPModelTag* i_pSourceTag);
  CATSYPModelBinding(
    const CATUnicodeString& i_sourcePropertyName, 
    const CATUnicodeString& i_elementName, 
    CATSYPStyleProcessor::BindingMode i_bindingMode, 
    CATSYPModelTag* i_pSourceTag, 
    const CATSYPPropertyDescriptor& i_sourcePropertyDescriptor);
  /**Destructor*/
  ~CATSYPModelBinding();
private:
  CATUnicodeString _propertyName;
  CATUnicodeString _elementName;
  CATSYPStyleProcessor::BindingMode _bindingMode;
  CATSYPModelTag* _pSourceTag;
  CATSYPPropertyDescriptor _sourcePropertyDescriptor;
  friend class CATSYPStyleProcessor;
  friend class CATSYPModelPropertyBase;
  friend class CATSYPSaxModelBuilder;
  friend class VIDBindingEdit;
  friend class CATSYPDynamicTreeVisitor;
};

#endif
