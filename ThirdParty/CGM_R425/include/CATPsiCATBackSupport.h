// COPYRIGHT Dassault Systemes 2088
//===================================================================
//
// CATPrdSessionServices.h
// Header definition of CATPrdSessionServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
#ifndef CATPsiCATBackSupport_H
#define CATPsiCATBackSupport_H

/**
 * @level Private
 * @usage U1
 */

#include "PLMPSISessionInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

//-----------------------------------------------------------------------

class ExportedByPLMPSISessionInterfaces CATPsiCATBackSupport
{
public:
  static HRESULT EnableCATBackSupport(CATBoolean bEnable);
  static CATBoolean IsCATBackSupportEnabled();

private:
  static CATBoolean _sbEnable;
};

//-----------------------------------------------------------------------

#endif
