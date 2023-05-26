#ifndef CATSYPEventExternalName_H
#define CATSYPEventExternalName_H

#include <IntroInfra.h>
#include <CATUnicodeString.h>

class CATSYPEvent;
class CATSYPMetaClass;

/** @ingroup groupSypEventEvent
 * Parse the external name of an event.
 *
 * @par External Name Definition
 * The external name of an event describes the name of the function
 * that returns the event and that is exposed through introspection on
 * a class (via its @ref CATSYPMetaClass).
 * 
 * @par
 * The external name of an event can be qualified, i.e. associated to
 * a class name, or unqualified.
 *
 * @par
 * A qualified external name should match the regular expression @c
 * [A-Za-z_][A-Za-z_0-9]*\.[A-Za-z_][A-Za-z_0-9]*. The expression
 * before the `.' is the class name and the expression after the `.'
 * is the name of the function that returns the event.
 *
 * @par
 * An unqualified external name should match the regular expression @c
 * [A-Za-z_][A-Za-z_0-9]*. It is the name of the function that returns
 * the event.
 *
 * @par
 * The unqualified external name can be used to represent an event
 * name when the class name can be deduced from context.
 *
 * @par Externa Name Resolution
 * The function @ref #ResolveEvent can be used to retrieve the event
 * described by this external name.
 */
class ExportedByIntroInfra CATSYPEventExternalName
{
public:
  /** 
   * Parse the external name.
   *
   * @param i_externalName the external name to parse.
   *
   * @param o_error [out] the parsing error if one occured. An empty
   * string if no error occured. Note that this parameter can be @c
   * NULL; in that case parsing errors will raise a @ref FAILURE if @a
   * i_ignoreErrors is @c 0 or be ignored if @a i_ignoreErrors is @c
   * !=0.
   *
   * @param i_ignoreErrors ensures that no @ref FAILURE is raised when
   * an error occurs. This parameter is only useful when @a o_error is
   * @c NULL.
   */
  explicit CATSYPEventExternalName(const CATUnicodeString &i_externalName, 
                                   CATUnicodeString *o_error = NULL, 
                                   int i_ignoreErrors = 0);

  /** Destroy this class */
  ~CATSYPEventExternalName();

  /**
   * Get the class name of this external name.
   *
   * @return the class name; empty string if the external name is
   * unqualified or if constructor failed.
   */
  const CATUnicodeString &GetClassName() const;

  /**
   * Get the name of the function that returns the events.
   *
   * @return the name of the function; empty string if constructor
   * failed.
   */
  const CATUnicodeString &GetEventFuncName() const;

  /**
   * Build the external name represented by this object.
   *
   * @return the external name; an empty string if constructor failed.
   */
  CATUnicodeString ToString() const;

  /**
   * Get the event described by this external name.
   *
   * The parameter @a i_pMetaClass is used when the external name is
   * unqualified. It can be @c NULL if the external name is qualified.
   *
   * @param i_pMetaClass class to use to resolve unqualified external
   * names. Can be @c NULL if the external name is qualified.
   *
   * @param o_error [out] the resolving error if one occured. An empty
   * string if no error occured. Note that this parameter can be @c
   * NULL; in that case errors will raise a @ref FAILURE if @a
   * i_ignoreErrors is @c 0 or be ignored if @a i_ignoreErrors is @c
   * !=0.
   *
   * @param i_ignoreErrors ensures that no @ref FAILURE is raised when
   * an error occurs. This parameter is only useful when @a o_error is
   * @c NULL.
   *
   * @return the event. @c NULL in case of error (in that case if @a
   * o_error is not NULL then the given string will contain the
   * error). Not that @c AddRef has NOT been called on the returned
   * value.
   */
  CATSYPEvent *ResolveEvent(const CATSYPMetaClass *i_pMetaClass, 
                            CATUnicodeString *o_error = NULL, 
                            int i_ignoreErrors = 0) const;

  /**
   * Shortcut function to test if a string is an event external name.
   *
   * This function won't raise any @ref FAILURE if @a i_externalName
   * is ill-formed or if it is not an event.
   *
   * @param i_externalName the external name to parse.
   *
   * @param i_pMetaClass class to use to resolve unqualified external
   * names. Can be @c NULL if the external name is qualified.
   *
   * @return @c !=0 if i_externalName is the external name (qualified
   * or unqualified) or an event.
   */
  static int IsEventExternalName(const CATUnicodeString &i_externalName, const CATSYPMetaClass *i_pMetaClass);
private:
  CATSYPEventExternalName(const CATSYPEventExternalName &);
  CATSYPEventExternalName &operator=(const CATSYPEventExternalName &);
 private:
  /** the class name; empty string if the external name is unqualified
      or if constructor failed */
  CATUnicodeString _className;
  /** the name of the function that returns the event; empty string if
      constructor failed */
  CATUnicodeString _eventFuncName;
};

#endif // CATSYPEventExternalName_H
