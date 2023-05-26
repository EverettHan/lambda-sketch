#ifndef _CATISYPIntrospectable_H
#define _CATISYPIntrospectable_H

// IntrospectionInfrastructure framework
#include <IntroInfra.h>
#include <CATSYPPropertyDescriptor.h>
#include <CATSYPEventDescriptor.h>
#include <CATSYPEventHandlerDescriptor.h>
#include <CATISYPIntrospectableEx.h>

// UIVCoreTools framework
#include <CATSYPArray.h>

// System framework
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATSysWeakRef.h>
#include <CATEventSubscriber.h>

class CATSYPObjectProperty;
class CATSYPTriggerBase;
class CATSYPProperties;
class CATISYPIntrospectable_var;
class CATSYPMetaClass;
class CATSYPEventHandler;

/** 
 * @ingroup groupCIDIntrospection
 * Creates an introspectable object from its class name.
 * This function uses .CATFactory dictionnary files to find the library that owns the component, 
 * and builds it by using CATCreateExternalObject.
 * @param i_className the class name
 * @return a handler on an introspectable object. Can be NULL_var.
 * @see CATISYPIntrospectable
 */
ExportedByIntroInfra CATBaseUnknown* CreateIntrospectableObject(const CATUnicodeString &i_className, CATSYPMetaClass*& o_pMetaClass);

extern ExportedByIntroInfra IID IID_CATISYPIntrospectable;

/** 
 * @ingroup groupCIDIntrospection
 * This interface allows to expose the methods of its implementation to introspection. 
 * Properties with a compatible signature can be accessed directly from their name with this interface.
 * This interface is implemented by the extensions generated by mkmk
 * when parsing .sypintro XML file, which describes the properties exposed to introspection.
 */
class ExportedByIntroInfra CATISYPIntrospectable : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Returns the introspection meta class of this instance.
   * @see CATSYPMetaClass
   */
  virtual const CATSYPMetaClass * GetSYPMetaClass() const = 0;

  /**
   * Sets the value of a property referenced by its name.
   * The value is a CATBaseUnknown_var : depending on the type of the property (see GetPropertyType), 
   * it can be directly assigned for object types or it has to be encapsulated in a box for primitive data types
   * (see CATBoxing.h).
   * @param i_propertyName the property name
   * @param i_spPropertyValue the property value.
   */
  virtual void SetProperty(const CATUnicodeString &i_propertyName, const CATBaseUnknown_var &i_spPropertyValue) = 0;

  /**
   * Returns the value of a property referenced by its name.
   * The returned value is a CATBaseUnknown_var : depending on the type of the property (see GetPropertyType), 
   * the value has been directly assigned for object types or it has been encapsulated in a box for primitive data types
   * (see CATBoxing.h).
   * @param i_propertyName the property name
   * @return the property value directly, or encaspulated by boxing
   */
  virtual CATBaseUnknown_var GetProperty(const CATUnicodeString &i_propertyName) = 0;
  
  /**
   * Sets the value of an attached property referenced by its name, associated to the given child of the object.
   * The value is a CATBaseUnknown_var : depending on the type of the property (see GetPropertyType), 
   * it can be directly assigned for object types or it has to be encapsulated in a box for primitive data types
   * (see CATBoxing.h).
   * @param i_child the child to associate to the given property
   * @param i_propertyName the property name
   * @param i_spPropertyValue the property value.
   */
  virtual void SetAttachedProperty(const CATBaseUnknown_var &i_child, const CATUnicodeString &i_propertyName, const CATBaseUnknown_var &i_spPropertyValue) = 0;
  
  /**
   * Returns the value of an attached property referenced by its name, associated to the given child of the object.
   * The returned value is a CATBaseUnknown_var : depending on the type of the property (see GetPropertyType), 
   * the value has been directly assigned for object types or it has been encapsulated in a box for primitive data types
   * (see CATBoxing.h).
   * @param i_child the child associated to the requested property
   * @param i_propertyName the property name
   * @return property directly, or encaspulated by boxing
   */
  virtual CATBaseUnknown_var GetAttachedProperty(const CATBaseUnknown_var &i_child, const CATUnicodeString &i_propertyName) = 0;

  /**
   * Gets an event handler.
   *
   * This function may return the same instance of @ref
   * CATSYPEventHandler or a new one each time it is
   * called. Nevertheless the returned object should always have the
   * same behavior. For example if the returned handler calls a member
   * function, it should always call the same function even if a
   * different handler instance is returned each time this function is
   * called.
   *
   * @param i_name the name of the event handler
   *
   * @return [IUnknown#Release] return an instance of event
   * handler. @c AddRef has been called on the returned pointer. Note
   * that a new instance of event handler may be returned each time
   * the function is called for the s
   ame @a i_name. Return @c NULL and
   * raise a @ref FAILURE if no event handler named @a i_name exists.
   */
  virtual CATSYPEventHandler * GetEventHandler(const CATUnicodeString &i_name) = 0;

  /**
   * Returns the interface used to enrich the property description of the introspectable object.
   * The CATISYPIntrospectableEx interface stores the additional information used by the tweaker 
   * infrastructure to customize the widget created to edit the introspectable properties.
   */
  virtual CATISYPIntrospectableEx_var GetIntrospectableEx() = 0;
};

CATDeclareHandler( CATISYPIntrospectable, CATBaseUnknown );

#include <CATSYPIntrospectableAdapter.h>
#include <CATSysMacros.h>

/** 
 * @ingroup groupCIDIntrospection
 * This macros has to be used by an introspectable object inside a method that 
 * has throw an introspectable event. The introspectable events listener that are 
 * connected to it will be called synchronously.
 * See CATSYP#Connect to connect an event to an event handler.
 * @param event the event name, that should be a CATUnicodeString
 * @param args a CATSYPProperties dictionnary, that associate boxed data to a property name.
 * @code
 * void MyClass::Method() 
 * {
 *   // Something is performed here that could interest someone.
 *   ...
 *   CATSYPSendEvent("TheEventName");
 * }
 * @endcode
 * @see CATSYPProperties
 * @see CATSYP#Connect
 */
#define CATSYPSendEvent( event, args )\
{  CATISYPIntrospectable_var intro( this );\
  if( intro != NULL_var ){\
    CATSYPIntrospectableAdapter* pAdapter = CAT_DYNAMIC_CAST(CATSYPIntrospectableAdapter, intro->GetImpl(1));\
    if (pAdapter)pAdapter->SendEvent( event, args );else FAILURE("Bad Introspectable implementation!"); }}

/** 
 * @ingroup groupCIDIntrospection
 * This macros has to be used by an introspectable object inside an introspectable property accessor
 * to update data bound properties. This update is performed synchronously.
 * See CATSYP#Connect to connect a property to another on 2 introspectable objects.
 * @param event the property name, that should be a CATUnicodeString
 * @code
 * void MyClass::SetMyProperty(PropertyType &i_property) 
 * {
 *   // Avoid infinite loop that could be involved by two ways connections.
 *   if (_property == i_property) return;
 *   // The following line to precise that even if a property is not valid or 
 *   // out of bounds, the CATSYPModifyProperty has to be sent, to update listeners.
 *   if (MyValidateMethod(i_property))
 *     _property == i_property;
 *   CATSYPModifyProperty("MyProperty");
 * }
 * @endcode
 */
#define CATSYPModifyProperty( MyPropertyName )\
{  CATISYPIntrospectable_var intro( this );\
  if( intro != NULL_var ){\
    CATSYPIntrospectableAdapter* pAdapter = CAT_DYNAMIC_CAST(CATSYPIntrospectableAdapter, intro->GetImpl(1));\
    if (pAdapter)pAdapter->DispatchModifyProperty( MyPropertyName );else FAILURE("Bad Introspectable implementation!"); }}

/** 
 * @ingroup groupCIDIntrospection
 * This macros has to be used by an introspectable collection in the accessor of an attached property
 * to update data bound properties related to a given child. This update is performed synchronously.
 * See CATSYP#ConnectAttachedProperty and CATSYP#ConnectPropertyToAttachedProperty to connect
 * an attached property to a property with 2 introspectable objects.
 * @param event the property name, that should be a CATUnicodeString
 * @code
 * void MyClass::SetMyAttachedProperty(PropertyType &i_property, ChildType& i_oneChild) 
 * {
 *   Property currentChildProperty = GetMyAttachedProperty(i_oneChild);
 *   // Avoid infinite loop that could be involved by two ways connections.
 *   if (currentChildProperty == i_property) return;
 *   // Associate property to child.
 *   ...
 *   CATSYPModifyProperty("MyAttachedProperty", i_oneChild);
 * }
 * @endcode
 */
#define CATSYPModifyAttachedProperty( MyPropertyName , child)\
{  CATISYPIntrospectable_var intro( this );\
  if( intro != NULL_var ){\
    CATSYPIntrospectableAdapter* pAdapter = CAT_DYNAMIC_CAST(CATSYPIntrospectableAdapter, intro->GetImpl(1));\
    if (pAdapter)pAdapter->DispatchModifyAttachedProperty( MyPropertyName, child );else FAILURE("Bad Introspectable implementation!"); }}

#endif