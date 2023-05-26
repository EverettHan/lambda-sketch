// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisGlowingData_H
#define CATVisGlowingData_H

#include "SGInfra.h"

#include "CATVisColor.h" 
#include "CATVisColorf.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATString.h"

//-----------------------------------------------------------------------
// Glow

class ExportedBySGInfra CATVisGlowingData
{
public:
  CATVisGlowingData();
  virtual ~CATVisGlowingData();

  // backgrounds' glow effect
  unsigned int  _activationOnBackground;
  unsigned int  _numPassOnBackground;
  float         _effectSizeOnBackground;
  float         _effectCoefOnBackground;

  // 3D scene' glow effect
  unsigned int  _activationOnScene;
  unsigned int  _numPassOnScene;
  float         _effectSizeOnScene;
  float         _effectCoefOnScene;
  float         _basicSpecularCoef;
  float         _glowObjectsCoef;
};

#endif
