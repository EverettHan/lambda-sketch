// COPYRIGHT DASSAULT SYSTEMES 2014
#ifndef CATSYPObjectConnector_h
#define CATSYPObjectConnector_h
// System framework
#include <CATSYPRefCounted.h>
#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATSYPArray.h>

class CATSYPMetaClass;
class CATISYPIntrospectable_var;
class BindingStruct;
class EventListeningStruct;
class CATSysWeakRef;
class CATSYPTriggerBase;
class CATSYPPropertyGetter;
class CATSYPPropertySetter;
class CATSYPAttachedPropertyGetter;
class CATSYPAttachedPropertySetter;
class CATSYPEventHandler;
/**
 * This object record bindings made on an object, and allow later to disconnect all these bindings, 
 * to reconnect them to another model object that would be compatible with it.
 * The is very usefull to reuse component, and creates some pools of them.
 * Of course every binding to the object must be done through this connector to ensure that the disconnection is complete.
 */
class ExportedByIntroInfra CATSYPObjectConnector : public CATSYPRefCounted
{
public:
  enum BindingPosition{SourceBindingPosition, SourceChildBindingPosition, TargetBindingPosition, TargetChildBindingPosition};
  /** 
   * Constructor
   * @param i_autoApplyFlag ensure that when a binding is registered to the connector, the registered model object is bound accordingly.
   * Otherwise, the actual registering in the model object is made by the caller.
   * @param i_failOnBindingErrorsFlag allow to throw an assertion if a binding connection with the model object fail. If set to 0, 
   * the object connector is permissive, and will allow the model object to not expose every property registered in the connector.
   */
  CATSYPObjectConnector(int i_autoApplyFlag, int i_failOnBindingErrorsFlag);

  /** 
  * Destructor
  */
  virtual ~CATSYPObjectConnector();
  /**
   * Sets the model object on the connector. This will first detach every connection of an eventual current model object, 
   * and bound them to the new one that is given.
   * @param i_pModelObject the new model to bound the connector to.
   */
  virtual void SetModelObject(CATBaseUnknown* i_pModelObject);
  /** @return the object that is currently connected.*/
  CATBaseUnknown* GetModelObject() const;
  /** Detachs the current model, that is remove every binding that is registered on the connector.*/
  void DetachViewFromItsModelObject();
  /** 
   * Registers a binding where the model object is the source.
   * @param i_sourcePropertyName the name of the property on the model object. 
   * @param i_targetPropertyName the name of the property on the target. Must correspond to an existing property on the target.
   * @param i_spTarget the target of the binding. Can't be NULL_var.
   * @param i_initWhenConnectFlag sets if when the binding is apply, the target property value must be updated by the value of the source property.
   * @param i_pValueToSetIfGetterIsNULL must contain the value to apply to the target property when the source object doesn't expose the registered binding. 
   * This case may append the object connector has been created with the option i_failOnBindingErrorsFlag set to 0. So this field has to be filled optionnally.
   * @see #CATSYPObjectConnector
   */
  void RegisterBindingWithModelObjectAsSource(
    const CATUnicodeString& i_sourcePropertyName,
    const CATUnicodeString& i_targetPropertyName,
    const CATISYPIntrospectable_var& i_spTarget,
    int i_initWhenConnectFlag, 
    const CATBaseUnknown_var& i_pValueToSetIfGetterIsNULL=NULL_var);
  /** 
   * Registers a binding where the model object is the target.
   * @param i_sourcePropertyName the name of the property on the model object. 
   * @param i_spSource the source of the binding. Can't be NULL_var.
   * @param i_targetPropertyName the name of the property on the target. Must correspond to an existing property on the target.
   * @param i_initWhenConnectFlag sets if when the binding is apply, the target property value must be updated by the value of the source property.
   * @see #CATSYPObjectConnector
   */
  void RegisterBindingWithModelObjectAsTarget(
    const CATUnicodeString& i_sourcePropertyName,
    const CATISYPIntrospectable_var& i_spSource,
    const CATUnicodeString& i_targetPropertyName,
    int i_initWhenConnectFlag);
  /**
   * Generic method to register a binding. In case of simple binding, 
   * better use #RegisterBindingWithModelObjectAsTarget or #RegisterBindingWithModelObjectAsSource
   * @param i_modelObjectBindingPosition the position of the model object in the binding. 
   * For example, it can be the source or the target of the binding.
   * @param i_pSource source of the binding.
   * @param i_pSourceChild source child, in case of attached property getter.
   * @param i_sourcePropertyName source property of the binding. Can't be an empty string.
   * @param i_pSourceGetter getter of the binding.
   * @param i_pSourceAttachedGetter attached getter of the binding, in case of attached property binding.
   * @param i_pTarget target of the binding.
   * @param i_pTargetChild target child, in case of attached property setter.
   * @param i_targetPropertyName name of the property to bind to.
   * @param i_pTargetSetter setter of the binding.
   * @param i_pTargetAttachedSetter attached setter of the binding
   * @param i_initWhenConnectFlag sets if when the binding is apply, the target property value must be updated by the value of the source property.
   * @param i_pValueToSetIfGetterIsNULL must contain the value to apply to the target property when the source object doesn't expose the registered binding. 
   * This case may append the object connector has been created with the option i_failOnBindingErrorsFlag set to 0. So this field has to be filled optionnally.
   * @see #RegisterBindingWithModelObjectAsTarget, #RegisterBindingWithModelObjectAsSource
   */
  void RegisterBinding(
    CATSYPObjectConnector::BindingPosition i_modelObjectBindingPosition, 
    CATBaseUnknown* i_pSource,
    CATBaseUnknown* i_pSourceChild,
    const CATUnicodeString& i_sourcePropertyName,
    CATSYPPropertyGetter* i_pSourceGetter,
    CATSYPAttachedPropertyGetter* i_pSourceAttachedGetter,
    CATBaseUnknown* i_pTarget,
    CATBaseUnknown* i_pTargetChild,
    const CATUnicodeString& i_targetPropertyName,
    CATSYPPropertySetter* i_pTargetSetter,
    CATSYPAttachedPropertySetter* i_pTargetAttachedSetter,
    int i_initWhenConnectFlag, 
    const CATBaseUnknown_var& i_pValueToSetIfGetterIsNULL=NULL_var);
  /**
   * Registers an event listening.
   * @param the name of the event to listen.
   * @param the object responsible of the emission of the event. Can't be NULL.
   * @param the name of the event handler to use on the model object.
   */
  void RegisterEventListening(const CATUnicodeString &i_event, CATBaseUnknown* i_pEmitterObject, const CATUnicodeString &i_eventHandlerName, CATSYPEventHandler *i_pEventHandler=NULL);
  /**
   * Unregister an event listening.
   * @param the name of the event to listen.
   * @param the object responsible of the emission of the event. Can't be NULL.   
   */
	void UnregisterEventListening(const CATUnicodeString &i_event, CATBaseUnknown* i_pEmitterObject);

  /**
   * Registers a trigger.
   * @param i_pTrigger the trigger to register. Can't be NULL;
   */
  void RegisterTrigger(CATSYPTriggerBase* i_pTrigger);
private:
  void ApplyBindingToModel( BindingStruct* i_pBindingStruct, CATBaseUnknown* i_pModelObject, int updateSYPMetaClassFlag);
  void ApplyEventListening(EventListeningStruct* i_pEventListeningStruct, CATBaseUnknown* i_pModelObject);
  void ApplyTriggerAdd(CATSYPTriggerBase* i_pTrigger, CATBaseUnknown* i_pModelObject);
private:  
  CATSYPMetaClass* _pModelObjectMetaClass;
  CATSysWeakRef* _pModelObjectWR;
  CATSYPDynArray<BindingStruct*>_BindingStructList;
  CATSYPDynArray<EventListeningStruct*>_EventListeningStructList;
  CATSYPDynArray<CATSYPTriggerBase*>_TriggerList;
  int _autoApplyFlag;
  int _failOnBindingErrorsFlag;
};

#endif // CATSYPObjectConnector_h
