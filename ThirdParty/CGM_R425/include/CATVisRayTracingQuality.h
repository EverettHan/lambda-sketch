// COPYRIGHT DASSAULT SYSTEMES 2011

#ifndef CATVisRayTracingQuality_H
#define CATVisRayTracingQuality_H

#include "SGInfra.h"

//--------------------------------------------------------------
// RayTracing Quality

class ExportedBySGInfra CATVisRayTracingQuality
{
public:
  CATVisRayTracingQuality();
  ~CATVisRayTracingQuality();

  bool operator!=(const CATVisRayTracingQuality& iProperties) const;
  bool operator==(const CATVisRayTracingQuality& iProperties) const;

  void Maximize(const CATVisRayTracingQuality& iMaxQuality);
  void Reset();

  unsigned int  _deactivation;
  float         _mapRatio;
  enum EUpscaleMode
  {
    eNearest,
    eLinear
  };
  EUpscaleMode  _upscaleMode;

  //---------------------------------------
  // ORE deprecated
  struct DummyStruct
  {
    unsigned int _deactivation;
    unsigned int _maxSampling;
  };
  DummyStruct _ao;
  DummyStruct _shadows;
};

#endif
