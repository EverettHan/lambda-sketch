// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisEnvMapData_H
#define CATVisEnvMapData_H

#include "SGInfra.h"

#include "CATVisSkyLightingData.h"
#include "CATVisColor.h" 
#include "CATVisColorf.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATString.h"
#include "CATIblParameter.h"

class CATVisParameters;
class ExportedBySGInfra CATVisEnvMapData : public CATVisSkyLightingData
{
public:
  CATVisEnvMapData();
  CATVisEnvMapData(const CATVisEnvMapData&);
  virtual ~CATVisEnvMapData();

  CATString     _reflectionCubeMap;
  unsigned int  _reflectionCubeMapSize;
  CATString     _reflectionSphereMap;

  CATString     _diffuseCubeMap;  
  
  CATVisColorf _envAmbient;
  CATVisColorf _envDiffuse;
  CATVisColorf _envSpecular;
  CAT4x4Matrix _transfoMatrix;
  EnvironmentState _iblMode;  

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);
};

#endif
