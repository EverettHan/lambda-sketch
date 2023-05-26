#ifndef CATSYPEventHandlersSupportDescriptor_H
#define CATSYPEventHandlersSupportDescriptor_H

#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <UIVCoreToolsInline.h>

class CATBaseUnknown;
class CATSYPEvent;
class CATSYPEventHandler;
class CATSYPEventArgs;

/** @ingroup groupCIDIntrospection
 * Value-like class describing a support for handlers of events.
 *
 * The support can be used to add, remove event handlers. It may
 * optionally be used to dispatch events.
 *
 * @see CATSYPMetaClass
 */
class ExportedByIntroInfra CATSYPEventHandlersSupportDescriptor
{
public:
  /**
   * Type of the function to use to call the function that adds a
   * handler for a given event and for a given object instance.
   *
   * It is possible to call mutliple times this function with the same
   * event and the same handler instance. In that case there will be
   * multiple registrations; no checks are made for duplication (the
   * caller will have to call @ref #RemoveHandler multiple times).
   *
   * @param i_pObj the object instance.
   *
   * @param i_pEvent the event that we are interested in. Note that @c
   * AddRef will be called on the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler to call. Can't be @c NULL. 
   * @c AddRef will be called on this pointer. Note that the type of 
   * @c CATSYPEventArgs supported by this handler will be compared to
   * the type of arguments of the event. It must be a super-type of
   * the one of the event.
   *
   * @param i_handleConsumedEvents @c !=0 if the handler should be
   * called for consumed events.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
   * invalid input or internal error (in that case a @ref FAILURE has
   * been raised).
   */
  typedef int (*AddHandlerFunc)(CATBaseUnknown *i_pObj, 
                                CATSYPEvent *i_pEvent, 
                                CATSYPEventHandler *i_pHandler, 
                                int i_handleConsumedEvents);

  /**
   * Type of the function to use to call the function that removes a
   * handler for an event and for a given object instance.
   *
   * If the same handler has been added multiple times, this function
   * removes the first found registration (starting the look up from
   * the most ancient registration).
   *
   * @param i_pObj the object instance.
   *
   * @param i_pEvent the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler. Can't be @c NULL.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to remove handler due
   * to invalid input or internal error (in that case a @ref FAILURE has
   * been raised) or if the handler was never registered for the given
   * event (in that case NO @ref FAILURE is raised, it is valid to do
   * so; this is important for auto-remove handlers).
   */
  typedef int (*RemoveHandlerFunc)(CATBaseUnknown *i_pObj, 
                                   CATSYPEvent *i_pEvent, 
                                   CATSYPEventHandler *i_pHandler);

  /**
   * Type of the function to use to call the function that dispatches
   * an event.
   *
   * This call is synchronous; it is blocking until the dispatch is
   * ended.
   *
   * The dispatch is reentrant; it is safe to call @c Dispatch while
   * being called on a handler by another call to @c Dispatch. The
   * first @c Dispatch will simply be paused until the new @c Dispatch
   * has ended (@c Dispatch is synchronous) and then it will be
   * resumed an continue as expected.
   *
   * The event arguments instance will be passed to each handler; it
   * may be used to pass informations between handlers and/or to give
   * a result to the dispatch. Since the call of @c Dispatch is
   * synchronous, the caller may look at the state of the arguments
   * after the dispatch (for example after the dispatch the caller can
   * check if the event has been consumed).
   *
   * The origin on the event argument (@ref CATSYPEventArgs#GetOrigin)
   * must be either @c NULL or equal to @a i_pObj. If @c NULL, it will
   * be positioned by this function to @a i_pObj.
   *
   * Instance handlers are called in the order of their
   * registration.<br/>
   * Class handlers are called in this order:
   *   - first the class handlers of the class of the widget are 
   *     called in the order of their registration
   *   - then the class handlers of the parent class of the widget
   *     are called in the order of their registration
   *   - ...
   *
   * When a handler consume the event (@ref CATSYPEventArgs#Consume),
   * the handlers that should have been called after it and that are
   * not registered to be called for consumed events are not
   * called.<br/>
   * This include the handlers on the same widget. For example if two
   * handlers have been registered (with @c i_handleConsumedEvents=0)
   * on a widget for the same event and the first one consume the
   * event, the second one (in the order of registration) won't be
   * called.
   *
   * @param i_pObj the object instance.
   *
   * @param i_pArgs the arguments of the event to dispatch (the
   * dispatched event is retrieved using @ref
   * CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
   * either this object or @c NULL.
   *
   * @return @c !=0 if the dispatch succeeded, @c 0 if failed.
   */
  typedef int (*DispatchFunc)(CATBaseUnknown *i_pObj,
                              CATSYPEventArgs *i_pArgs);

  /** 
   * Initialize this class with empty value.
   *
   * @ref #GetName will be empty; @ref #GetAddHandlerFunc and @ref
   * #GetRemoveHandlerFunc will return @c NULL.
   */
  CATSYPEventHandlersSupportDescriptor();

  /** Destroy this class */
  ~CATSYPEventHandlersSupportDescriptor();

  /**
   * Initialize this class.
   *
   * @param i_addHandlerName the name of the member function used to add the
   * handler and described by this descriptor.
   *
   * @param i_pAddHandlerFunc the function to call to add a handler on
   * an event for an instance of object. Can't be @c NULL.
   *
   * @param i_removeHandlerName the name of the member function used
   * to remove the handler and described by this descriptor.
   *
   * @param i_pRemoveHandlerFunc the function to call to remove a
   * handler on an event for an instance of object. Can't be @c NULL.
   *
   * @param i_dispatchName the name of the member function used to
   * dispatch events. Empty string if dispatch is not supported (in
   * that case @a i_pDispatchFunc must be @c NULL).
   *
   * @param i_pDispatchFunc the function to call to dispatch an event
   * on an instance of object. Can be @c NULL if dispatch is not
   * supported (in that case @a i_dispatchName must be emtpy).
   */
  CATSYPEventHandlersSupportDescriptor(const CATUnicodeString &i_addHandlerName,
                                       AddHandlerFunc i_pAddHandlerFunc,
                                       const CATUnicodeString &i_removeHandlerName,
                                       RemoveHandlerFunc i_pRemoveHandlerFunc,
                                       const CATUnicodeString &i_dispatchName = "",
                                       DispatchFunc i_pDispatchFunc = NULL);

  /**
   * Copy constructor.
   *
   * @param i_other the descriptor to copy.
   */
  CATSYPEventHandlersSupportDescriptor(const CATSYPEventHandlersSupportDescriptor &i_other);

  /**
   * Assignement operator.
   *
   * @param i_other the descriptor to copy.
   */
  CATSYPEventHandlersSupportDescriptor &operator=(const CATSYPEventHandlersSupportDescriptor &i_other);


  /** 
   * Return the name of the member function used to add the handler
   * and described by this descriptor. 
   *
   * @return the name. An empty string when the value is emtpy.
   */
  INLINE const CATUnicodeString &GetAddHandlerName() const{return _addHandlerName;}
  /** 
   * Return the name of the member function used to remove the handler
   * and described by this descriptor.
   *
   * @return the name. An empty string when the value is emtpy.
   */
  INLINE const CATUnicodeString &GetRemoveHandlerName() const{return _removeHandlerName;}

  /** 
   * Return the function to call to add a handler on an event for an
   * instance of object.
   *
   * @return the function pointer. @c NULL when the value is empty.
   */
  INLINE AddHandlerFunc GetAddHandlerFunc() const{return _pAddHandlerFunc;}

  /** 
   * Return the function to call to remove a handler on an event for
   * an instance of object.
   *
   * @return the function pointer. @c NULL when the value is empty.
   */
  INLINE RemoveHandlerFunc GetRemoveHandlerFunc() const{return _pRemoveHandlerFunc;}

  /**
   * Return the name of the member function used to dispatch
   * events. Empty string if dispatch is not supported (in that case
   * @a i_pDispatchFunc must be @c NULL).
   *
   * @return the name. An empty string when the value is emtpy.
   */
  INLINE const CATUnicodeString &GetDispatchName() const{return _dispatchName;}

  /**
   * Return the function to call to dispatch an event on an instance
   * of object. Can be @c NULL if dispatch is not supported (in that
   * case @a i_dispatchName must be emtpy).
   *
   * @return the function pointer. @ NULL when the value is empty of
   * if dispatch is not supported.
   */
  INLINE DispatchFunc GetDispatchFunc() const{return _pDispatchFunc;}
private:
  /** the name of the member function used to add the handler and
      described by this descriptor. */
  CATUnicodeString _addHandlerName;
  /** the name of the member function used to remove the handler and
      described by this descriptor. */
  CATUnicodeString _removeHandlerName;
  /** the name of the member function used to dispatch events. Empty
      string if dispatch is not supported (in that case @ref
      #_pDispatchFunc is @c NULL). */
  CATUnicodeString _dispatchName;
  /** the function to call to add a handler on an event for an
      instance of object. */
  AddHandlerFunc _pAddHandlerFunc;
  /** the function to call to remove a handler on an event for an
      instance of object. */
  RemoveHandlerFunc _pRemoveHandlerFunc;
  /** the function to call to dispatch an event on an instance of
      object. Can be @c NULL if dispatch is not supported (in that
      case @a i_dispatchName must be emtpy). */
  DispatchFunc _pDispatchFunc;
};

#endif // CATSYPEventHandlersSupportDescriptor_H
