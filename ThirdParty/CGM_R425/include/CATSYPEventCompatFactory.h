#ifndef CATSYPEventCompatFactory_H
#define CATSYPEventCompatFactory_H

#include <UIVCoreTools.h>

class CATUnicodeString;
class CATSYPEvent;
class CATMetaClass;

/** @ingroup groupSypEventEvent
 * Instantiate events for introspectable classes that have not yet
 * updated their <tt>.sypintro</tt> file and their class to expose
 * @ref CATSYPEvent events.
 *
 * After the introduction of @ref CATSYPEvent, introspectable objects
 * that want to expose events have to provide a static function for
 * each event that returns the event created by their own factory of
 * events.
 *
 * Until all classes have migrated on the new event architecture, we
 * still need to support old events definition based only on the
 * declaration of the event in the <tt>.sypintro</tt> file.
 *
 * As a consequence we need a factory to build events in that specific
 * case. This function provides this factory.
 *
 * Created events have following properties:
 *   - propagation is @ref CATSYPEvent::NoPropagation
 *   - argument type is @ref CATSYPEventArgs
 *
 * @param i_name the name of the event. Must be an identifier; it must
 * match the regular expression @c [A-Za-z_][A-Za-z_0-9]*.
 *
 * @param i_pOwnerClass the class owning the event. Can't be @c NULL.
 *
 * @return the instance of event. Note that @c AddRef has NOT been
 * called on the returned pointer so the caller must not call @c
 * Release.  The factory keeps reference to all the events it has
 * created. Returns @c NULL in case of invalid arguments (a @ref
 * FAILURE will have been raised).
 */
ExportedByUIVCoreTools CATSYPEvent *CATSYPEventCompatFactory(const CATUnicodeString &i_eventName,
                                                           CATMetaClass *i_pOwnerClass);

#endif // CATSYPEventCompatFactory_H
