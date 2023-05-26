#ifndef CATSYPEventMap_H
#define CATSYPEventMap_H

#include <UIVCoreTools.h>
#include <CATUnicodeString.h>
#include <CATSYPHashMap.h>

class CATSYPEvent;

/** @ingroup groupSypEventEvent
 * Map that associate @ref CATSYPEvent instances to their name.
 *
 * This class has a value semantic, as a consequence it behaves as a
 * value and have a working copy constructor and assignement operator.
 *
 * It references the events it contains using @c AddRef.
 */
class ExportedByUIVCoreTools CATSYPEventMap
{
public:
  /** Initialize this class */
  CATSYPEventMap();

  /** 
   * Copy constructor.
   *
   * @param i_other the map to copy.
   */
  CATSYPEventMap(const CATSYPEventMap &i_other);

  /**
   * Assignement operator.
   *
   * @param i_other the map to copy.
   */
  CATSYPEventMap &operator=(const CATSYPEventMap &i_other);
 
  /** Destory this class */
  virtual ~CATSYPEventMap();

  /**
   * Put an event in the map.
   *
   * @param i_pEvent the event. Can't be @c NULL.
   */
  void Put(CATSYPEvent *i_pEvent);

  /**
   * Get an event using its name.
   *
   * @param i_name the name of the event.
   *
   * @return the event instance. @c NULL if no event is found with the
   * given name. @c AddRef is NOT called on the returned pointer.
   */
  CATSYPEvent * Get(const char *i_name) const;
private:
  /**
   * Remove all events from @ref #_events map, releasing them.
   */
  void Clear();
private:
  /** the map containing the events */
  CATSYPHashMap<CATUnicodeString, CATSYPEvent*> _events;
};

#endif // CATSYPEventMap_H
