//===================================================================
// COPYRIGHT Dassault Systemes 2015/09/02
//===================================================================

#ifndef CATIEnvMapGenerator_H
#define CATIEnvMapGenerator_H

#include "CATVisItf.h"

//System
#include "CATBaseUnknown.h"

extern ExportedByCATVisItf IID IID_CATIEnvMapGenerator;

class CATEnvMapGeneratorDesc;
class CATVizCubicEnvMapWithMipMap;
class CATVizTextureWithMipMap;

class ExportedByCATVisItf CATIEnvMapGenerator : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  virtual HRESULT  Generate   (const CATEnvMapGeneratorDesc& iDesc) = 0;
  virtual HRESULT  Begin      (const CATEnvMapGeneratorDesc& iDesc, const int iStepSize, int& oHandle) = 0;
  virtual HRESULT  Step       (const int iHandle, CATVizCubicEnvMapWithMipMap*& oMap) = 0;
  virtual HRESULT  StepLatLong(const int iHandle, CATVizTextureWithMipMap*& oMap) = 0;
  virtual void     End        (const int iHandle) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIEnvMapGenerator, CATBaseUnknown);

#endif // CATIEnvMapGenerator_H
