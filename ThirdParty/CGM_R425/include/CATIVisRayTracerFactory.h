//-------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2010/04/23
//-------------------------------------------------------------------

#ifndef CATIVisRayTracerFactory_H
#define CATIVisRayTracerFactory_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"


extern ExportedBySGInfra  IID IID_CATIVisRayTracerFactory ;

class CATVisRayTracer;
class ExportedBySGInfra CATIVisRayTracerFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual CATVisRayTracer* Create() = 0;
};

CATDeclareHandler(CATIVisRayTracerFactory, CATBaseUnknown);

//-----------------------------------------------------------------------

#endif
