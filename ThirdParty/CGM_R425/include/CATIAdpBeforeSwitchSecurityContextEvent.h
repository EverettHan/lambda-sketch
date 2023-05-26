#ifndef CATIAdpBeforeSwitchSecurityContextEvent_h
#define CATIAdpBeforeSwitchSecurityContextEvent_h


#include "CATNotification.h"
#include "CATPLMIntegrationAccess.h"

/**
* Event notified when a switch of security context is about to occur.
* Provides a way to abort the switch.
* Be aware that the switch will abort if ANY subscriber asks for it, so at this
* step you do not know if the switch will actually happen or not.
*/
class ExportedByCATPLMIntegrationAccess CATIAdpBeforeSwitchSecurityContextEvent : public CATNotification
{
  CATDeclareClass;
public:
  /**
   * @return The target repository for the new security context.
   */
  virtual CATUnicodeString GetTargetRepository() const = 0;

  /**
   * @return The source role for the new/next/future security context.
   */
  virtual CATUnicodeString GetTargetSecurityContext() const = 0;

  /**
   * @return The source role for the old security context.
   */
  virtual CATUnicodeString GetSourceSecurityContext() const = 0;

  /**
   * @return The source role uuid for the old security context.
  */
  virtual CATUnicodeString GetSourceSecurityContextUuid() const = 0;

  /**
   * Aborts the switch of security context.
   * The switch of security context is aborted if at least one event subscriber 
   * calls this method, however the other subscribers will still be notified.
   */
  virtual void Abort() = 0;

  // @deprecated
  // replaced by GetTargetSecurityContext
  virtual CATUnicodeString GetTargetRole() const = 0;

  //  @deprecated
  // replaced by GetSourceSecurityContext
  virtual CATUnicodeString GetSourceRole() const = 0;

  //  @deprecated
  // replaced by GetSourceSecurityContextUuid
  virtual CATUnicodeString GetSourceRoleUuid() const = 0;

};

#endif
