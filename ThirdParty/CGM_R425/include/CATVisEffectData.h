// COPYRIGHT Dassault Systemes 2011

#ifndef CATVisEffectData_H
#define CATVisEffectData_H

#include "SGInfra.h"
#include "CATVisEffectPositionEnum.h"
#include "CATString.h"
#include "CATVisParameters.h"

class ExportedBySGInfra CATVisEffectData
{
public:
  CATVisEffectData();
  CATVisEffectData(const CATVisEffectData& iData);
  virtual ~CATVisEffectData();
  CATVisEffectData& operator=(const CATVisEffectData& iData);
  int operator!=(const CATVisEffectData& iData) const;
    
  CATVisParameters          _parameters;
  CATString                 _shaderFile;
  CATString                 _shaderFile2;
  CATString                 _technique;
  CATVisEffectPositionEnum  _position;
  unsigned int              _recursivity;
  bool                      _activation;
  struct Quality
  {
    bool  _forceNoMSAA;
    float _downScaleRatio;
  };
  Quality                   _quality;
  Quality                   _mirrorQuality;
  
  unsigned int              _projConic;
  unsigned int              _projCylindric;
};

#endif
