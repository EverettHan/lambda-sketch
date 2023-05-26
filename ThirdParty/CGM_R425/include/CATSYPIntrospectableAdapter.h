#ifndef CATSYPIntrospectableAdapter_H
#define CATSYPIntrospectableAdapter_H

// IntrospectionInfrastructure framework
#include <IntroInfra.h>
#include <CATISYPIntrospectable.h>
#include <CATISYPIntrospectableEx.h>
#include <CATBoxing.h>
#include <CATBasicBoxing.h>
#include <CATSYPMetaClass.h>
#include <CATSYPMappingTablePointerToPointer.h>

// UIVCoreTools framework
#include <CATSYPArray.h>

// System framework
#include <CATUnicodeString.h>

class CATSYPBindingTargetData;
class CATSYPBindingData;
class CATUnicodeString;
class CATSYPTriggerCollection;
class CATHashDico;
class CATSYPProperties;
class CATListOfCATSYPObjectProperty;
class CATSYPEventHandler;
class CATSYPPropertyGetter;
class CATSYPBindingSourceData;
class CATSYPObjectGetter;
class CATSYPObjectGet;
class CATSYPDynamicTreeVisitor;

/**
 * @ingroup groupCIDIntrospection
 * Adapter for CATISYPIntrospectable implementation.
 * @see CATISYPIntrospectable
 * The adapter adds the ability to connect introspectable property
 * of any component each others.
 * To connect by C++ introspectable objects, use the class CATSYP
 * @see CATSYP
 */
class ExportedByIntroInfra CATSYPIntrospectableAdapter : public CATISYPIntrospectable
{
  CATDeclareClass;

public:

  /** Constructor */
  CATSYPIntrospectableAdapter();
  /** Destructor */
  virtual ~CATSYPIntrospectableAdapter();

  // Implementation of CATISYPIntrospectable

  /** @copydoc CATISYPIntrospectable#SetProperty */
  virtual void SetProperty(const CATUnicodeString &i_name, const CATBaseUnknown_var &i_spPropertyValue);
  /** @copydoc CATISYPIntrospectable#GetProperty */
  virtual CATBaseUnknown_var GetProperty(const CATUnicodeString &i_name);
  /** @copydoc CATISYPIntrospectable#SetAttachedProperty */
  virtual void SetAttachedProperty(const CATBaseUnknown_var &i_index, const CATUnicodeString &i_name, const CATBaseUnknown_var &i_spPropertyValue);
  /** @copydoc CATISYPIntrospectable#GetAttachedProperty */
  virtual CATBaseUnknown_var GetAttachedProperty(const CATBaseUnknown_var &i_index, const CATUnicodeString &i_name);
  /** @copydoc CATISYPIntrospectable#GetEventHandler */
  virtual CATSYPEventHandler *GetEventHandler(const CATUnicodeString &i_name);
  /** @copydoc CATISYPIntrospectable#GetIntrospectableEx */
  virtual CATISYPIntrospectableEx_var GetIntrospectableEx();

    /**
  * Gets Binding data of a property referenced by its name.
  * The return is a CATSYPBindingSourceData pointer which gives acces to :
  * 1. the supposed binded source object\property.
  * 2. a list of binding targets CATSYPBindingTargetData and their respective target object and "binded to" property 
  * @param i_name: the name of the supposed binded property 
  * @see CATSYPBindingData
  * @see CATSYPBindingData#CATSYPBindingTargetData
  * @see CATSYPBindingData#CATSYPBindingSourceData
  */
  CATSYPBindingSourceData* GetBinding(const CATUnicodeString &i_name);

  /**
  * Gets Binding data of an attached property referenced by its name.
  * The return is a CATSYPBindingSourceData pointer which gives acces to :
  * 1. the supposed binded source and child object with the binded property
  * 2. also, a list of binding targets CATSYPBindingTargetData; 
  * @param i_name: the name of the supposed binded property 
  * @see CATSYPBindingData
  * @see CATSYPBindingData#CATSYPBindingTargetData
  * @see CATSYPBindingData#CATSYPBindingSourceData
  */
  CATSYPBindingSourceData* GetAttachedBinding(const CATUnicodeString &i_name, const CATBaseUnknown_var &i_spChild);

  /**
   * Sends an event to all its registred listener callback methods.
   * @param i_eventName the name of the event that is being send
   * @param i_spArgs the arguments related to the event
   * @see CATSYPProperties
   */
  void SendEvent(const CATUnicodeString &i_eventName, const CATSYPProperties &i_spArgs);

  /**
   * Recovers property on intropsectable objects and sets it to all connected properties.
   * @param i_name the name of the property that needs to be updated on connected properties.
   */
  void DispatchModifyProperty(const CATUnicodeString &i_name);

  /**
   * Recovers attached property on intropsectable objects and sets it to all connected properties.
   * @param i_name the name of the property that needs to be updated on connected properties.
   * @param i_spChild the child the attached property is related to.
   */
  void DispatchModifyAttachedProperty(const CATUnicodeString &i_name, const CATBaseUnknown_var &i_spChild);

  /*
   * Retrieve the meta class set by SetSYPMetaClass
   */
  const CATSYPMetaClass* GetSYPMetaClass() const;

  /**
   * Get the number of listeners of the given property.
   * This can not be an attached property
   */
  unsigned int GetNbListener(const CATUnicodeString &i_name);

  /**
   * Get the number of listeners of the given attached property, for the given child.
   * This must be an attached property
   */
  unsigned int GetNbListener(const CATUnicodeString &i_name, const CATBaseUnknown_var &i_spChild);

  /** 
  * Check if a source property i_name binding already exist with the target object and property : i_bindingT 
  * @param i_name : source property name
  * @param i_getter : gives access on source object and property descriptor 
  * @param i_bindingT : gives access on target object and property descriptor
  * @see CATSYPBindingTargetData
  * @see CATSYPObjectGet
  */ 
  int IsBound(const CATUnicodeString &i_name, const CATSYPObjectGet& i_getter, CATSYPBindingTargetData& i_bindingT);

  /**
   * Adds a trigger to the object. Asserts if i_pTrigger is NULL.
   */
  void AddTrigger(CATSYPTriggerBase* i_pTrigger);
  /**
   * Removes a trigger from this object. Asserts if i_pTrigger is NULL.
   */
  void RemoveTrigger(CATSYPTriggerBase* i_pTrigger);
protected:
  void SetSYPMetaClass(CATSYPMetaClass* i_pSYPMetaClass);
private:
  INLINE void FixSYPMetaClass()
  {
    if (_sypMetaClassFixedFlag)return;
    UpdateSYPMetaClass();
    _sypMetaClassFixedFlag = 1;
  }
  INLINE int UpdateSYPMetaClass()
  {
    if (_sypMetaClassFixedFlag)
      return 0;
    CATBaseUnknown* pCBU = GetImpl();
    if (!pCBU)
      return 0;
    CATSYPMetaClass* pSYPMetaClass = CATSYPMetaClass::ForMetaObject(pCBU->GetMetaObject());
    if (pSYPMetaClass == _pSYPMetaClass)
      return 0;
    if (_pSYPMetaClass && _pSYPMetaClass->GetClassName().IsNull())
      _pSYPMetaClass->Release();
    _pSYPMetaClass = pSYPMetaClass;
    if (_pSYPMetaClass && _pSYPMetaClass->GetClassName().IsNull())
      _pSYPMetaClass->AddRef();
    return 1;
  }
  INLINE CATSYPMetaClass* _GetSYPMetaClass()
  {
    if (_sypMetaClassFixedFlag)
      return _pSYPMetaClass;
    UpdateSYPMetaClass();
    return _pSYPMetaClass;
  }
  INLINE const CATSYPMetaClass* GetUsedMetaClass()
  {
    if (!_pSYPMetaClass)
      _pSYPMetaClass = _GetSYPMetaClass();
    return _pSYPMetaClass;
  }

  /** A temporary flag used to indicate that introspectable events
      should use the CATSYPEvent infrastructure for dispatching and
      handler registration instead of old binding infrastructure. */ 
  static int usePropagatingEvents;

  CATSYPIntrospectableAdapter(const CATSYPIntrospectableAdapter&);
  CATSYPIntrospectableAdapter& operator=(const CATSYPIntrospectableAdapter&);

  /**Used by friends*/
  void SetBindingTarget(const CATUnicodeString &i_name, const CATSYPObjectGet& i_getter, CATSYPBindingTargetData& i_objectProperty, CATBoolean i_applyPropertyFlag);
  /**Used by friends*/
  CATSYPTriggerCollection * GetTriggerCollection();
  /**Used internally*/
  int ApplyProperty( CATSYPBindingSourceData* i_pSource, CATSYPBindingTargetData& i_target);

   /**
   * Adds an event handler for the given event.
   *
   * This function must only be used when using @ref CATSYPEvent
   * registration infrastructure for events (see @ref
   * #usePropagatingEvents).
   *
   * @param i_eventName the name of the event on this component.
   *
   * @param i_pTarget the event handler object.
   *
   * @param i_pTargetEventHandler the name of the event handler on @a
   * i_pTarget.
   *
   * @param opHandler the created handler.
   * Need to be released by the caller!!!!!
   * 
   */
  void AddHandler(const CATUnicodeString &i_eventName,
                  CATBaseUnknown *i_pTarget,
                  const CATUnicodeString &i_pTargetEventHandler,
                  CATSYPEventHandler * & opHandler);


  /**
   * Removes an event handler for the given event.
   *
   * This function must only be used when using @ref CATSYPEvent
   * registration infrastructure for events (see @ref
   * #usePropagatingEvents).
   *
   * @param i_eventName the name of the event on this component.
   *
   * @param i_pTarget the event handler object.
   *
   * @param i_pTargetEventHandler the name of the event handler on @a
   * i_pTarget.
   *
   * @param iphandler the handler to remove @a
   * 
   */
  void RemoveHandler(const CATUnicodeString &i_eventName,
                  CATBaseUnknown *i_pTarget,
                  const CATUnicodeString &i_pTargetEventHandler, 
                  CATSYPEventHandler * iphandler);  
  /**
   * Add a command callback for a given command notification.
   *
   * @param i_spTemplateTarget the template target object on which is defined the command callback method.
   *
   * @param i_pCommandNotificationName the name of the command notification.
   *
   * @param i_pCommandCallbackName the name of the command callback method.
   *
   */
  
  void AddCommandCallback(CATISYPIntrospectable_var i_spTemplateTarget, CATUnicodeString  i_pCommandNotificationName, CATUnicodeString  i_pCommandCallbackName);

  /*
   * Clean bindings, depending wether they are on attached properties or not
   */
  void _Cleanup();

  /*
   * Internal functions, called internally
   */
  CATSYPMappingTablePointerToPointer* GetAttachedBindingsTable(const CATUnicodeString &i_name);

  /**
  * Insert a property binding data in _pSourceToTargetBindings dico 
  * @param i_name :  source property name
  * @param i_bindingST : source binding data that gives access to the source object and property getter
  * @param i_objectProperty : target binding data that gives access to the target object and property setter
  * @see CATSYPBindingData
  * @see CATSYPBindingData#CATSYPBindingTargetData
  * @see _pSourceToTargetBindings
  */
  void InsertBinding(const CATUnicodeString &i_name, CATSYPBindingSourceData* i_bindingST,CATSYPBindingTargetData& i_objectProperty);
  
  /**
  * Insert attached properties binding data in _pSourceToTargetBindings dico 
  * @param i_name :  source property name
  * @param i_bindingST : source binding data that gives access to the source object and property getter
  * @param i_objectProperty : target binding data that gives access to the target object and property setter
  * @see CATSYPBindingData
  * @see CATSYPBindingData#CATSYPBindingSourceData
  * @see _pSourceToTargetBindings
  */
  void InsertAttachedBinding(const CATUnicodeString &i_name, const CATBaseUnknown_var &i_spChild, CATSYPBindingSourceData* i_bindingST);
  
  /**Check if the input property is an attached property*/
  CATBoolean IsAttachedProperty(const CATUnicodeString &i_name);

  /**
  * Removes attached property (defined by i_name) binding from CATSYPBindingSourceData targets list. 
  * we Calls to GetAttachedBinding(i_name) in order to get the CATSYPBindingSourceData information and remove targets that matches with the input (i_name & i_spChild & i_bindingT)
  * And if no matched target binding we returns
  * The source binding is also removed and deleted from the AttachedBindingsTable "_pSourceToTargetBindings" if no more binding.
  * 
  * @see GetAttachedBinding
  * @see GetAttachedBindingsTable()
  * @see IsAttachedProperty()
  * @ see _pSourceToTargetBindings
  */
  void RemoveAttachedBinding(const CATUnicodeString &i_name, const CATBaseUnknown_var &i_spChild,CATSYPBindingTargetData* i_bindingT);
  /**
  * Removes property binding defined by (defined by i_name) from CATSYPBindingSourceData targets list.
  * we Calls to GetBinding(i_name) in order to get the CATSYPBindingSourceData information and remove targets that matches with the input (i_name & i_spChild & i_bindingT)
  * And if no matched target binding we returns
  * The source binding is deleted if no more binding.
  * 
  * @see GetBinding()
  */
  void RemoveBinding(const CATUnicodeString &i_name, CATSYPBindingTargetData* i_bindingT);

  /*
   * A dictionnary that maps a property name to a void*
   * This void* can be :
   * - a CATSYPBindingSourceData in the case of normal properties
   * - a mapping (CATSYPMappingTablePointerToPointer) of weakref of children to CATSYPBindingSourceData in the case of attached properties
   * We store the fact that the void* correspond to a nomalr or an attached property by setting the lowest bit of the pointer to :
   * - 0 in the case of a normal property.
   * - 1 in the case of an attached property.
   * NEVER USE DIRECTLY THIS POINTER, even in the implementation of this class.
   * Use the following functions, lower-bit-safe :
   * - GetBindingTargets
   * - GetAttachedBindingsTable
   * - InsertBinding
   * - InsertAttachedBinding
   * - IsAttachedProperty
   */
  CATHashDico * _pSourceToTargetBindings;

  CATSYPTriggerCollection * _pTriggerCollection;
  CATSYPMetaClass * _pSYPMetaClass;
  CATISYPIntrospectableEx_var _introspectableEx;
  unsigned char _sypMetaClassFixedFlag;

  friend class CATSYP;
  friend class CATSYPStyleProcessor;
  friend class CATSYPSaxModelBuilder;
  friend class CATSYPModelTagVisitorBuilder;
  friend class CATSYPTstOldIntrospectionEventsTestDeliveryError;
  friend class CATSYPTstUsePropagatingEvents;
  friend class SYPDesignerViewBuilder;
  friend class CATSYPDynamicTreeVisitor;
  //friend class CATSYPTemplateData;
  friend class CATSYPObjectConnector;
};

#endif
