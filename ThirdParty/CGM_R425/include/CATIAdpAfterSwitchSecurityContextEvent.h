#ifndef CATIAdpAfterSwitchSecurityContextEvent_h
#define CATIAdpAfterSwitchSecurityContextEvent_h


#include "CATNotification.h"
#include "CATPLMIntegrationAccess.h"

/**
* Event notified when a switch of security context occurred, so that any 
 * operation needed can be performed.
*/
class ExportedByCATPLMIntegrationAccess CATIAdpAfterSwitchSecurityContextEvent : public CATNotification
{
  CATDeclareClass;
public:
  /**
   * @return The target userId for the new security context.
   */
  virtual CATUnicodeString GetUserId() const = 0;

  /**
   * @return The target role for the new security context.
   */
  virtual CATUnicodeString GetTargetSecurityContext() const = 0;

  /**
   * @return The target role for the new security context (<=>TargetRole+"."+TargetOrganization+"."+TargetProject).
   */
  virtual CATUnicodeString GetTargetSecurityContextUuid() const = 0;

  /**
   * @return The target role for the new security context.
   */
  virtual CATUnicodeString GetTargetRoleId() const = 0;

  /**
   * @return The target organization for the new security context.
   */
  virtual CATUnicodeString GetTargetOrganizationId() const = 0;

  /**
   * @return The target project for the new security context.
   */
  virtual CATUnicodeString GetTargetProjectId() const = 0;

  // @deprecated
  // replaced by GetTargetSecurityContext
  virtual CATUnicodeString GetTargetRole() const = 0;

  // @deprecated
  // replaced by GetTargetSecurityContextUuid
  virtual CATUnicodeString GetTargetRoleUuid() const = 0;
};



#endif
