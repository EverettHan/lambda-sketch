#ifndef CATSYPModelPropertyBase_H
#define CATSYPModelPropertyBase_H

#include <CATStyleProcessor.h>
#include <CATBaseUnknown.h>
#include <CATSYPStyleProcessor.h>
#include <CATUnicodeString.h>
#include <CATSYPModelTag.h>
#include <UIVCoreToolsInline.h>
#include <CATSYPRefCounted.h>
class CATSYPModelBinding;
/**
 * Describes a property. Built by CATSYPStyleProcessor when building templates.
 * And used by CATSYPModelTagVisitor, by parsing the model tree describing the view of
 * an introspectable object.
 * A property must have a name, and a value or a binding object.
 */
class ExportedByCATStyleProcessor CATSYPModelPropertyBase : public CATSYPRefCounted
{
public:
  /** Constructor*/
  CATSYPModelPropertyBase();
  /** Constructor of a property in case of simple property with value*/
  CATSYPModelPropertyBase(const CATUnicodeString& i_propertyName, const CATBaseUnknown_var& i_spValue);
  /** Constructor of a property in case of simple property with value*/
  CATSYPModelPropertyBase(const CATUnicodeString& i_propertyName, const CATUnicodeString& i_valueAsText);
  /** Constructor of a bound property*/
  CATSYPModelPropertyBase(const CATUnicodeString& i_propertyName, CATSYPModelBinding* i_pBinding);
  /** 
   * @return the name of the property
   */
  INLINE const CATUnicodeString& GetName()const{return _propertyName;}
  /**
   * Sets the value of the property.
   * Note that it can't be done directly on the constructor in case of attached properties.
   */
  void SetValue(const CATBaseUnknown_var& i_spValue);
  /** 
   * @return the value of the property, NULL_var in case of data binding
   * OR in case of NULL value.
   */
  INLINE const CATBaseUnknown_var& GetValue()const{return _spValue;}
  /**
   * @return a value set as text.
   */
  INLINE const CATUnicodeString& GetValueAsText()const { return _valueAsText; }
  /**
   * @return the binding object of the property. NULL if the property owns a built value.
   */
  INLINE CATSYPModelBinding* GetBinding()const{return _pBinding;}

  /**bind this property*/
  void AddBinding(CATSYPModelBinding* i_pBinding);

  /**break and delete this property binding*/
  void DeleteBinding();

  /**break this property binding without deleting it*/
  void RemoveBinding();

protected:
  /** Destructor */
  ~CATSYPModelPropertyBase();
private:
  /** Copy Constructor */
  CATSYPModelPropertyBase(const CATSYPModelPropertyBase &i_toCopy);
  /** Operator = */
  CATSYPModelPropertyBase& operator = (const CATSYPModelPropertyBase &i_toCopy);
private:
  CATUnicodeString _propertyName;
  CATUnicodeString _valueAsText;
  CATBaseUnknown_var _spValue;
  CATSYPModelBinding* _pBinding;
};

#endif
