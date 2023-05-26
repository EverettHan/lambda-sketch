#ifndef CATSYPCommandNotificationDescriptor_H
#define CATSYPCommandNotificationDescriptor_H

#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATSYPDescriptorBase.h>
#include <UIVCoreToolsInline.h>

class CATNotification;

/**
 * Data class containing the description of a command notification.
 * <b>Role</b>: Used by introspection mechanisms. 
 * Recovered from a CATISYPIntrospectable.
 */
class ExportedByIntroInfra CATSYPCommandNotificationDescriptor : public CATSYPDescriptorBase
{
public:

  /** Constructor */
  CATSYPCommandNotificationDescriptor();

  /** Destructor*/
  virtual ~CATSYPCommandNotificationDescriptor();

  /** Constructor 
   * @param i_name name of the command notification
   * @param i_className name of class encapsulating the CATNotification
   */
  CATSYPCommandNotificationDescriptor(const CATUnicodeString& i_name, const CATUnicodeString& i_className, CATNotification *(*i_pCommandNotificationFunc)()=NULL);

  /** 
   * Copy constructor
   * @param i_toCopy the CATSYPCommandNotificationDescriptor to copy
   */
  CATSYPCommandNotificationDescriptor(const CATSYPCommandNotificationDescriptor & i_toCopy);

  /** 
   * Assignement operator. 
   */
  CATSYPCommandNotificationDescriptor& operator=(const CATSYPCommandNotificationDescriptor & i_toCopy);

  /**
    * Get the name of the function exposing the command notification.
    *
    * @return the name of the function exposing the command notification.
    */
  INLINE const CATUnicodeString& GetName () const{return _name;}
  /**
   * Get the name of the class encapsulating the command notification.
   *
   * @return the name of the class encapsulating the command notification.
   */
  INLINE const CATUnicodeString& GetCommandNotificationClassName() const{return _commandNotificationClassName;}
  /**
   * Get the command notification returned by the function exposing it.
   *
   * @return the name of the class exposing the command notification.
   */
  INLINE CATNotification* GetCommandNotification() const
  {
    // If the notification was referenced by its class name, a pointer on the function
    // exposing the notification is not necessary.
    // If it was not referenced at CTOR, we inhibit it. 

    if(_pCommandNotificationFunc == NULL) 
      return NULL;

    return (*_pCommandNotificationFunc)();
  }
private:
  /** The name of the function exposing the command notification */
  CATUnicodeString _name;
  /** The name of the class encapsulating the CATNotification */
  CATUnicodeString _commandNotificationClassName;
  /** Pointer on the method exposing the command notification */
  CATNotification *(*_pCommandNotificationFunc)();
};

#endif 
