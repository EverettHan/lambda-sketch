//===================================================================
// COPYRIGHT Dassault Systemes 2018-04-25
//===================================================================

#ifndef CATIVisRayTracingWarningPanelFactory_H
#define CATIVisRayTracingWarningPanelFactory_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"

extern ExportedBySGInfra  IID IID_CATIVisRayTracingWarningPanelFactory;

class CATCommand;
class ExportedBySGInfra CATIVisRayTracingWarningPanelFactory : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual bool ShowWarningPanel(CATCommand* iFather) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIVisRayTracingWarningPanelFactory, CATBaseUnknown);

#endif
