// COPYRIGHT DASSAULT SYSTEMES 2011

#ifndef CATVisRayTracingProperties_H
#define CATVisRayTracingProperties_H

#include "SGInfra.h"
#include "CATVisRayTracingQuality.h"
#include "CATUnicodeString.h"

//--------------------------------------------------------------
// RayTracing Properties

class ExportedBySGInfra CATVisRayTracingProperties
{
public:
  CATVisRayTracingProperties();
  ~CATVisRayTracingProperties();

  bool operator!=(const CATVisRayTracingProperties& iProperties) const;
  bool operator==(const CATVisRayTracingProperties& iProperties) const;
  
  void Update();
  
  // customisation
  enum CATVisRayTracingMode
  {
    CATVisNoRayTracing                      = 0,  // Raytracing is deactivated
    CATVisFullRayTracing                    = 1,  // Raytracing is used for all the scene but some fallback can be used when an object isn't managed by raytracing
    CATVisFullRayTracingWithoutFallbacks    = 2   // Only raytracing is used, no fallback is used
  };

  CATVisRayTracingMode  _mode;
  bool                  _smoothTransition;
  unsigned int          _smoothTransitionNumStep;
  bool                  _alphaBlending;
  bool                  _alphaPreMultiplied;
  unsigned int          _maxConvergenceTime;
  bool                  _GPUToneMapping;
  bool                  _invertY;                 // invert Y to display texture, usefull for fakeraytracing


  // Harddware properties
  struct ExportedBySGInfra Hardware
  {
    bool operator!=(const Hardware& iProperties) const;
    bool operator==(const Hardware& iProperties) const;

    enum EMode
    {
      eCPU = 0,
      eGPU
    };
    
    enum EDistributedRenderingMode
    {
      eFull,
      eCompressRGB
    };

    EMode                       _mode;
    bool                        _distributedRendering;
    CATUnicodeString            _hostName;
    unsigned int                _clusterPort;
    CATUnicodeString            _localHostName; 
    EDistributedRenderingMode   _distributedRenderingMode;
    unsigned int                _distributedCompressionRatio;

  };
  Hardware  _hardware;


  // quality
  CATVisRayTracingQuality                   _staticQuality;
  CATVisRayTracingQuality                   _dynamicQuality;
};

//-----------------------------------------------------------------------

#endif
