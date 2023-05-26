/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
#ifndef CATOmySessionMngtToolbox_H
#define CATOmySessionMngtToolbox_H

/**
 * @level Private
 * @usage U3
 */

#include "CATOMYBaseSessionRestrictedUseForIntegration.h"
#include "CATErrorDef.h"
#include "CATSysBoolean.h"

class ExportedByCATOMYBaseSessionRestrictedUseForIntegration CATOmySessionMngtToolbox
{

public:
  static CATBoolean _emulateNavigationOk; //for ODT CATAdpProtectedOpenerImpl... I don't see any correct way to test this :/

  enum OmyWorkspaceCapability { FullAuthoring = 0, LightAuthoring = 1, Navigation = 2 };
/**
 * Service checking the working mode of the current session.
 */
  static HRESULT CheckWorkspaceCapability(OmyWorkspaceCapability iCapability);
};
#endif
