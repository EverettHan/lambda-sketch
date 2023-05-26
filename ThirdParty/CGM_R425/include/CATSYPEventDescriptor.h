#ifndef CATSYPEventDescriptor_H
#define CATSYPEventDescriptor_H

#include <UIVCoreTools.h>
#include <CATUnicodeString.h>
#include <CATSYPDescriptorBase.h>
#include <UIVCoreToolsInline.h>

class CATSYPEvent;

/**
 * Data class containing the description of an event.
 * <b>Role</b>: Used by introspection mechanisms. 
 * Recovered from a CATISYPIntrospectable.
 */
class ExportedByUIVCoreTools CATSYPEventDescriptor: public CATSYPDescriptorBase
{
public:
  /** Constructor*/
  CATSYPEventDescriptor();

  /** Destructor */
  ~CATSYPEventDescriptor();

  /**
   * Constructor.
   * @param i_name name of the event
   */
  CATSYPEventDescriptor(const CATUnicodeString& i_name, CATSYPEvent *(*i_pEventFunc)(), const CATUnicodeString& i_className);

  /**
   * Copy Constructor.
   * @param i_toCopy the CATSYPEventDescriptor to copy
   */
  CATSYPEventDescriptor(const CATSYPEventDescriptor & i_toCopy);

  /**
   * Assignement operator.
   */
  CATSYPEventDescriptor& operator=(const CATSYPEventDescriptor & i_toCopy);

  /**
   * Get the name of the function exposing the event.
   *
   * Usually it should match @ref CATSYPEvent#GetName but this is not
   * mandatory. Please note that @ref CATSYPEvent#GetName should only
   * be used for debugging purposes.
   *
   * @return the name of the function exposing the event.
   *
   * @see #GetEventFunc
   */
  const CATUnicodeString& GetName () const;
  /**
   * Get the static function that return the event.
   *
   * @return the static function. @c NULL in case of severe internal
   * error.
   */
  CATSYPEvent *(*GetEventFunc() const)();

private:
  /** the name of the function exposing the event */
  CATUnicodeString _name;

  /** the function exposing the event */
  CATSYPEvent *(*_pEventFunc)();
};

#endif
