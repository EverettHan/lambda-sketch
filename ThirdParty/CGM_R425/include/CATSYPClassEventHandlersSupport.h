#ifndef CATSYPClassEventHandlersSupport_H
#define CATSYPClassEventHandlersSupport_H

#include <UIVCoreTools.h>
#include <CATSYPHashMap.h>

class CATSYPEventHandlersSupport;
class CATBaseUnknown;
class CATSYPEventHandler;
class CATSYPEvent;
class CATMetaClass;

/** @ingroup groupSypEventRegistration
 * Support for handlers of events registered on classes.
 *
 * This class can be used by a type of node tree to store for each
 * kind of class some class handlers.
 *
 * It uses the runtime type identification of system (i.e. the one
 * implemented by CATDeclareClass & CATImplementClass) to identify
 * classes.
 *
 * It associates for each @ref CATMetaClass instance a 
 * @ref CATSYPEventHandlersSupport. This support associates for each
 * @ref CATSYPEvent instance a list of handlers (see the documentation
 * of support for details).
 *
 * @par Inheritance
 * When using @ref #GetClassHandlerSupport for a given @c CATMetaClass
 * this support won't return the handlers registered on parent classes
 * (obtained by @ref CATMetaClass#GetMetaObjectOfBaseClass); it's up
 * to the user of this class to do it. Usually the handlers registered
 * on the child class are called before the handlers of its parent
 * class.
 *
 * @par Singleton
 * Usually there is only one instance of this class for a given type
 * of object tree. Please consult the documentation of this object
 * tree for details.
 *
 * @see CATSYPEventHandlersSupport
 */
class ExportedByUIVCoreTools CATSYPClassEventHandlersSupport
{
public:
  /** Initialize this class */
  CATSYPClassEventHandlersSupport();

  /** Destroy this class */
  virtual ~CATSYPClassEventHandlersSupport();

  /**
   * Add an handler for a given event and a given class.
   *
   * It is possible to call mutliple times this function with the same
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
  int AddClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents);

  /**
   * Remove an handler for an event and a given class.
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
  int RemoveClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);

  /**
   * Get the support of handlers for the given class.
   *
   * @param i_pClass the class. Can't be @c NULL.
   *
   * @return the support. @c NULL if there is no support yet
   * associated (i.e. when no handler have been added to that class).
   */
  CATSYPEventHandlersSupport *GetClassHandlersSupport(CATMetaClass *i_pClass);
private:
  /**
   * Clear @ref #_supports.
   *
   * This function will destroy first all values before emptying the
   * map. So it's not a simple call to @ref CATSYPHashMap#Clear.
   */
  void Clear();
private:
  CATSYPClassEventHandlersSupport(const CATSYPClassEventHandlersSupport &);
  CATSYPClassEventHandlersSupport &operator=(const CATSYPClassEventHandlersSupport &);
private:
  /** map associating classes with the support of their handlers. */
  CATSYPHashMap<CATMetaClass *, CATSYPEventHandlersSupport *, CATSYPHashMapPointerHasher> 
    _supports;
};

#endif // CATSYPClassEventHandlersSupport_H
