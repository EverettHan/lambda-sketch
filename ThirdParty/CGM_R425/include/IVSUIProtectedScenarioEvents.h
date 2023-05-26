//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2020
//-----------------------------------------------------------------------------
#ifndef IVSUIProtectedScenarioEvents_H
#define IVSUIProtectedScenarioEvents_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
class CATSYPEvent;

//=============================================================================
/**
 * IVSUIProtectedScenarioEvents
 */
class ExportedByIVInterfaces IVSUIProtectedScenarioEvents : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /**
   * Event emitted
   * - by SUI scenario
   * - the first time the SUI model is updated according to a device
   * - with a CATSYPEventArgs
   */
  static CATSYPEvent* IVSUITrackingStarted();

private:

  IVSUIProtectedScenarioEvents();
};

#endif
