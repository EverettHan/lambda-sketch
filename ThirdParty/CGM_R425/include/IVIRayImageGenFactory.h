#ifndef IVIRayImageGenFactory_H
#define IVIRayImageGenFactory_H

#include "CATBaseUnknown.h"
#include "CATVisItf.h"
#include "IVIRayImageGenerator.h"


extern ExportedByCATVisItf IID IID_IVIRayImageGenFactory;

class ExportedByCATVisItf IVIRayImageGenFactory : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual IVIRayImageGenerator* __stdcall Create(CAPTUREMODE mode) = 0;
};

CATDeclareHandler(IVIRayImageGenFactory, CATBaseUnknown);

#endif
