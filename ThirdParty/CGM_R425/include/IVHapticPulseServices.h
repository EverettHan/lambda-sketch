//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVHapticPulseServices_H
#define IVHapticPulseServices_H

// IVInterfaces
#include "IVInterfaces.h"
#include "IVDeviceAtomicType.h"
#include "CATLib.h"


// IVHapticFeedback_Level
// -----------------------------------
typedef enum
{
  IVHapticFeedback_None
  , IVHapticFeedback_PreSelection
  , IVHapticFeedback_Selection
} IVHapticFeedback_Level;

namespace IVHapticPulseServices
{
  ExportedByIVInterfaces HRESULT LaunchControllerFeedback(IVAtomicID iID, IVHapticFeedback_Level iFeedback);
};
//-----------------------------------------------------------------------
#endif

