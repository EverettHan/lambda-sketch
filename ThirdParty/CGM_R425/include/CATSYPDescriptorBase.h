#ifndef CATSYPDescriptorBase_H
#define CATSYPDescriptorBase_H

#include <UIVCoreTools.h>
#include <CATUnicodeString.h>
#include <CATBaseUnknown.h>
#include <CATSysMacroPtr.h>
#include <UIVCoreToolsInline.h>

/**
 * Data class containing the description of a entry descriptor.
 * It is used by introspection mechanisms. 
 * Recovered from a CATISYPIntrospectable.
 * @see CATISYPIntrospectable
 */
class ExportedByUIVCoreTools CATSYPDescriptorBase
{
public:
  /**
   * Describes the different type of introspectable entries
   */
  enum IntrospectableEntryType {
    /** The entry is not existing on the met class, or on any parent meta class*/
    UnknownEntry=0, 
    /** The entry is a property*/
    Property, 
    /** The entry is an attached property*/
    AttachedProperty,
    /** The entry is an event*/
    Event, 
    /** The entry is an event handler*/
    EventHandler, 
    /** The entry is a method*/
    Method,
    /** The entry is a command notification*/
    CommandNotification, 
    /** The entry is a command callback method*/
    CommandCallback};
  /**
   * Default constructor. Build an invalid descriptor, 
   * that can be filled by a operator=.
   */
  CATSYPDescriptorBase(CATSYPDescriptorBase::IntrospectableEntryType i_type)
  {
    _type=i_type;
  }
  CATSYPDescriptorBase(CATSYPDescriptorBase::IntrospectableEntryType i_type, const CATUnicodeString& i_className)
  {
    _type=i_type;
  }
  virtual ~CATSYPDescriptorBase(){}
  /**
  * Copy Constructor.
  */
  CATSYPDescriptorBase(const CATSYPDescriptorBase & i_toCopy)
  {
    _type = i_toCopy._type;
    _className = i_toCopy._className;
  }
  /**
  * Operator=
  */
  virtual CATSYPDescriptorBase& operator=(const CATSYPDescriptorBase & i_toCopy)
  {
    _type = i_toCopy._type;
    _className = i_toCopy._className;
    return *this;
  }
  INLINE CATSYPDescriptorBase::IntrospectableEntryType GetType() const{return _type;}
  INLINE const CATUnicodeString& GetClassName() const{return _className;}

private:
  CATSYPDescriptorBase::IntrospectableEntryType _type;
  CATUnicodeString _className;
};

#endif
