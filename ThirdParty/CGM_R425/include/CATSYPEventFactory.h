#ifndef CATSYPEventFactory_H
#define CATSYPEventFactory_H

#include <UIVCoreTools.h>
#include <CATSYPHashMap.h>
#include <CATSYPEvent.h>
#include <CATSYPEventMap.h>

class CATSYPEvent;

/** @ingroup groupSypEventEvent
 * Factory of @ref CATSYPEvent.
 *
 * There should a single factory instance for a specific tree of
 * objects. Please consult the documentation of the tree to find out
 * how to access to its factory.
 *
 * See @ref CATSYPEvent documentation for details.
 *
 * This factory also acts as the container for event instances. It
 * will keep references to the event is has created until it is
 * destroyed. That's why the @ref #NewEvent method does not call 
 * @c AddRef on its returned value.
 *
 * @see CATSYPEvent
 */
class ExportedByUIVCoreTools CATSYPEventFactory
{
public:
  /** Initialize this class */
  CATSYPEventFactory();
  
  /** Destory this class */
  virtual ~CATSYPEventFactory();
  
  /**
   * Instantiate an event.
   *
   * Note that instantiating an event with the same name and owner
   * class as an existing event will fail (with a @ref FAILURE and a
   * @c NULL returned value).
   *
   * See @ref CATSYPEvent documentation for details about event
   * registration and exposure.
   *
   * You may not call this function directly but instead use the
   * @ref CATImplementSYPEvent macro.
   *
   * @param i_name the name of the event (which should match the name
   * of the static function on its owner class that exposes the
   * event). Must be an identifier; it must match the regular
   * expression @c [A-Za-z_][A-Za-z_0-9]*.
   * 
   * @param i_propagation the propagation method of the event.
   *
   * @param i_pArgumentType the type of argument associated with the
   * event. Can't be @c NULL. It must be a sub-class of @ref CATSYPEventArgs.
   *
   * @param i_pOwnerClass the class owning the event. Can't be 
   * @c NULL.
   *
   * @return the instance of event. Note that @c AddRef has NOT been
   * called on the returned pointer so the caller must not call @c Release.
   * The factory keeps reference to all the events it has
   * created. Returns @c NULL in case of invalid arguments (a @ref FAILURE
   * will have been raised).
   */
  CATSYPEvent * NewEvent(const char *i_name, 
                         CATSYPEvent::Propagation i_propagation, 
                         CATMetaClass *i_pArgumentType, 
                         CATMetaClass *i_pOwnerClass);
private:
  CATSYPEventFactory(const CATSYPEventFactory &);
  CATSYPEventFactory &operator=(const CATSYPEventFactory &);
private:
  /** the events builts by this factory */
  CATSYPHashMap<CATMetaClass*, CATSYPEventMap, CATSYPHashMapPointerHasher> _events;
};

#endif // CATSYPEventFactory_H
