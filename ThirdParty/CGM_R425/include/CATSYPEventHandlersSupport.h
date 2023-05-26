#ifndef CATSYPEventHandlersSupport_H
#define CATSYPEventHandlersSupport_H

#include <UIVCoreTools.h>
#include <CATSYPEventHandlerInfoList.h>
#include <CATSYPHashMap.h>

class CATSYPEvent;
class CATSYPEventHandler;

/** @ingroup groupSypEventRegistration
 * Support of handlers for events.
 *
 * This class can be used by a node in a object tree to store its list
 * of handlers.
 *
 * It associates for each @ref CATSYPEvent instance, a @ref CATSYPEventHandlerInfoList
 * that lists all handlers associated to that event on the node
 * holding the support and that also associate with the handlers a
 * flag indicating if they want to be called for consumed events.
 *
 * @see CATSYPEvent
 * @see CATSYPEventHandler
 * @see CATSYPEventHandlerInfo
 * @see CATSYPEventHandlerInfoList
 */
class ExportedByUIVCoreTools CATSYPEventHandlersSupport
{
public:
  /** Initialize this class */
  CATSYPEventHandlersSupport();

  /** Destory this class */
  virtual ~CATSYPEventHandlersSupport();

  /**
   * Add a handler for a given event.
   *
   * It is possible to call mutliple times this function with the same
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
   */
  int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents);

  /**
   * Remove an handler for an event.
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
   */
  int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);

  /**
   * Get a copy of the list of handlers for a given event.
   *
   * Before return a copy, the list of handlers will be simplified by
   * removing all handlers that request to be automatically removed.
   *
   * @param i_pEvent the event. Can't be @c NULL.
   *
   * @return the list of event. An empty list if @c i_pEvent is 
   * @c NULL (in that case a @ref FAILURE has been raised).
   *
   * @see CATSYPEventHandlerInfoList#AutoRemove
   */
  CATSYPEventHandlerInfoList GetHandlersList(CATSYPEvent *i_pEvent);

  /**
   * Replace the content of the support with the content of the given
   * support.
   *
   * @note
   * If @a i_support is this object then calling this function has no
   * effect.
   *
   * @param i_support the support to get new handlers from
   */
  void ReplaceHandlers(const CATSYPEventHandlersSupport &i_support);
private:
  /**
   * Clear @ref #_eventHandlers.
   *
   * This function will call @c Release on the keys before emptying
   * the map. So it's not a simple call to @ref CATSYPHashMap#Clear.
   */
  void Clear();
private:
  CATSYPEventHandlersSupport(const CATSYPEventHandlersSupport &);
  CATSYPEventHandlersSupport &operator=(const CATSYPEventHandlersSupport &);
private:
  /** map associating event instances to the list of handlers for that
      event. Note that @c AddRef has been called on keys. */
  CATSYPHashMap<CATSYPEvent*, CATSYPEventHandlerInfoList, CATSYPHashMapPointerHasher> _eventHandlers;
};

#endif // CATSYPEventHandlersSupport_H
