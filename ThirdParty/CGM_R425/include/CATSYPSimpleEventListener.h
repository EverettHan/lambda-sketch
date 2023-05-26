// COPYRIGHT Dassault Systemes 2017
//=============================================================================
#ifndef CATSYPSimpleEventListener_H
#define CATSYPSimpleEventListener_H

#include <UIVCoreTools.h>
#include <CATBaseUnknown.h>
class CATSYPEvent;
class CATSYPEventArgs;
class CATSYPEventFactory;
class CATSYPEventHandler;
class CATSYPEventHandlersSupport;
class CATSYPClassEventHandlersSupport;

/** @ingroup groupVidMenu
 *
 * Base class for all actions and action groups. Implements events dispatch
 * from action to action group.
 */
class ExportedByUIVCoreTools CATSYPSimpleEventListener : public CATBaseUnknown
{
  CATDeclareClass;
  friend class CATSYPSimpleEventListenerEventPathBuilder;
  friend class CATSYPSimpleEventListener_ClassHandlersSupportLifecycle;

public:
  /**
   * Add a handler for a given event.
   *
   * The handlers will be called in the order of their registration.
   *
   * If this function is called during the dispatch of an event, the
   * registered event handler won't be called for this dispatch but
   * will only be called for next dispatches.
   *
   * It is possible to call multiple times this function with the same
   * event and the same handler instance. In that case there will be
   * multiple registrations; no checks are made for duplication (the
   * caller will have to call @ref #RemoveHandler multiple times).
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
   *
   * @see #AddHandlerFunction
   * @see @AddHandlerWRefMeth
   * @see #RemoveHandler 
   */
  int AddHandler(CATSYPEvent * i_pEvent, CATSYPEventHandler * i_pHandler, int i_handleConsumedEvents = 0);
  /**
   * Remove an handler for an event.
   *
   * If this function is called during the dispatch of an event, the
   * unregistered event handler will be called for this dispatch but
   * will not be called for next dispatches.
   *
   * If the same handler has been added multiple times, this function
   * removes the first found registration (starting the look up from
   * the most ancient registration).
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
   *
   * @see #AddHandler
   */
  int RemoveHandler(CATSYPEvent * i_pEvent, CATSYPEventHandler * i_pHandler);
  /**
   * Add an handler for a given event and a given class.
   *
   * The handlers will be called in the order of their
   * registration. The class handlers will be called before any
   * instance handler (i.e. handlers registered using @ref
   * #AddHandler).
   *
   * If this function is called during the dispatch of an event, the
   * registered event handler won't be called for this dispatch but
   * will only be called for next dispatches.
   *
   * It is possible to call multiple times this function with the same
   * event, the same handler instance and the same class. In that case
   * there will be multiple registrations; no checks are made for
   * duplication (the caller will have to call @ref #RemoveHandler
   * multiple times).
   *
   * @param i_pClass the class. Can't be @c NULL.
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
  static int AddClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents);
  /**
   * Remove an handler for an event and a given class.
   *
   * If this function is called during the dispatch of an event, the
   * unregistered event handler will be called for this dispatch but
   * will not be called for next dispatches.
   *
   * If the same handler has been added multiple times, this function
   * removes the first found registration (starting the look up from
   * the most ancient registration).
   *
   * @param i_pClass the class. Can't be @c NULL.
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
  static int RemoveClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);
  /**
   * Dispatch the event.
   *
   * The event will be dispatched in the tree hierarchy depending on
   * the propagation mode of the event (@ref
   * CATSYPEvent#GetPropagation).
   *
   * The list of handlers that will be called will be frozen before
   * the first handler is called; as a consequence, changes in the
   * tree hierarchy or in the handlers for the event at each node
   * won't have any effect on the dispatch of this event (but will
   * have effect on next dispatches, even on dispatches that may be
   * triggered by handlers of this event).
   *
   * This call is synchronous; it is blocking until the dispatch is
   * ended.
   *
   * The origin on the event argument (@ref CATSYPEventArgs#GetOrigin)
   * must be either @c NULL or equal to this object. If @c NULL, it
   * will be positioned by this function to this object.
   *
   * The instance of arguments used on this function will be passed to
   * all handlers called during the dispatch.
   * 
   * @param i_pArgs the arguments of the event to dispatch (the
   * dispatched event is retreived though @ref
   * CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
   * either this object of @c NULL.
   *
   * @return @c !=0 if the dispatch succeeded, @c 0 if failed.
   */
  int Dispatch(CATSYPEventArgs * i_pArgs);

protected:
  /**
   * Default constructor. 
   */
  CATSYPSimpleEventListener();
  /**
   * Destructor.
   */
  virtual ~CATSYPSimpleEventListener();
  /**
   * Get the factory of events for this tree hierarchy.
   *
   * @return the event factory. Can't be @c NULL.
   */
  static CATSYPEventFactory * GetEventFactory();

private:
  CATSYPSimpleEventListener (CATSYPSimpleEventListener &);
  CATSYPSimpleEventListener& operator=(CATSYPSimpleEventListener&);

private:
  CATSYPEventHandlersSupport * _pEventHandlersSupport;
  static CATSYPClassEventHandlersSupport * _pClassEventHandlersSupport;
};

//-----------------------------------------------------------------------------
#endif
