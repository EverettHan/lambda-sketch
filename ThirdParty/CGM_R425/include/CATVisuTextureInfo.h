#ifndef CATVisuTextureInfo_H
#define CATVisuTextureInfo_H

#include "SGInfra.h"
#include "CATVisuTextureType.h"
#include "CATVisEyeType.h"

class ExportedBySGInfra CATVisuTextureInfo
{
public:
  CATVisuTextureInfo();
  CATVisuTextureInfo(const CATVisuTextureInfo& iInfo);
  ~CATVisuTextureInfo();
  const CATVisuTextureInfo& operator=(const CATVisuTextureInfo& iInfo);
  int operator==(const CATVisuTextureInfo& iInfo) const;

  CATVisuTextureType _type;
  CATVisEyeType      _eyeType;
  int                _dynamicType;
  int                _withTransparentObjects;
  int                _id;
  int                _state;
  float              _visibilityRatio;
};


#endif // CATVisuTextureInfo_H
