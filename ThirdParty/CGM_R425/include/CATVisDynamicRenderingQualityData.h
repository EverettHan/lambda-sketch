// COPYRIGHT Dassault Systemes 2008

#ifndef CATVisDynamicRenderingQualityData_H
#define CATVisDynamicRenderingQualityData_H

#include "SGInfra.h"

#include "CATVisRayTracingProperties.h"
class ExportedBySGInfra CATVisAOQualityData
{
public:
  CATVisAOQualityData();
  ~CATVisAOQualityData();

  int operator!= (const CATVisAOQualityData& iData) const;
  int operator== (const CATVisAOQualityData& iData) const;
  CATVisAOQualityData& operator= (const CATVisAOQualityData& iData);

  unsigned int  _deactivation     : 1;
  unsigned int  _samplingMax      : 2;
  unsigned int  _blurDeactivation : 1; 
  unsigned int  _blurLevelMax     : 4; 
};

// util pour migration
typedef CATVisAOQualityData CATVisSSAOQualityData;

class ExportedBySGInfra CATVisEnvMapQualityData
{
public:
  CATVisEnvMapQualityData();
  ~CATVisEnvMapQualityData();

  int operator!= (const CATVisEnvMapQualityData& iData) const;
  int operator== (const CATVisEnvMapQualityData& iData) const;
  CATVisEnvMapQualityData& operator= (const CATVisEnvMapQualityData& iData);

  unsigned int  _deactivation     : 1; 
};

class ExportedBySGInfra CATVisOutlineQualityData
{
public:
  CATVisOutlineQualityData();
  ~CATVisOutlineQualityData();

  int operator!= (const CATVisOutlineQualityData& iData) const;
  int operator== (const CATVisOutlineQualityData& iData) const;
  CATVisOutlineQualityData& operator= (const CATVisOutlineQualityData& iData);

  unsigned int  _deactivation     : 1; 
};

class ExportedBySGInfra CATVisGlowQualityData
{ 
public:
  CATVisGlowQualityData();
  ~CATVisGlowQualityData();

  int operator== (const CATVisGlowQualityData& iData) const;
  CATVisGlowQualityData& operator= (const CATVisGlowQualityData& iData);

  unsigned int  _deactivation   : 1;
  unsigned int  _numPassMax     : 5;
};

class ExportedBySGInfra CATVisMirrorQualityData
{ 
public:
  CATVisMirrorQualityData();
  ~CATVisMirrorQualityData();

  int operator== (const CATVisMirrorQualityData& iData) const;
  CATVisMirrorQualityData& operator= (const CATVisMirrorQualityData& iData);

  unsigned int  _deactivation     : 1;
  unsigned int  _blurDeactivation : 1;
  unsigned int  _numBlurPassMax   : 5;
};

class ExportedBySGInfra CATVisShadowQualityData
{ 
public:
  CATVisShadowQualityData();
  ~CATVisShadowQualityData();

  int operator== (const CATVisShadowQualityData& iData) const;
  CATVisShadowQualityData& operator= (const CATVisShadowQualityData& iData);

  unsigned int  _shadowGroundUpdateDeactivation : 1;
  unsigned int  _shadowInterObjectsDeactivation : 2;
  unsigned int  _shadowMapSize : 16;
};

class ExportedBySGInfra CATVisPlaneQualityData
{ 
public:
  CATVisPlaneQualityData();
  ~CATVisPlaneQualityData();

  int operator== (const CATVisPlaneQualityData& iData) const;
  CATVisPlaneQualityData& operator= (const CATVisPlaneQualityData& iData);

  unsigned int  _positionUpdateDeactivation : 1;
};

class ExportedBySGInfra CATVisAAQualityData
{
public:
  CATVisAAQualityData();
  ~CATVisAAQualityData();

  int operator== (const CATVisAAQualityData& iData) const;
  CATVisAAQualityData& operator= (const CATVisAAQualityData& iData);

  unsigned int  _deactivation : 1;
  unsigned int  _numJitteringSampleMax : 5;
  unsigned int  _disableAAOnSSAO :1;
  unsigned int  _postProcessAATechnique : 1; ///< Cast from VisPostProcessAntialisingInfo::Technique
  unsigned int  _fxaaQuality : 2; ///< Cast from VisPostProcessAntialisingInfo::FXAA::Quality
  unsigned int  _ssaaFactor : 2; ///<Cast from VisAntialiasingInfo::SSAA::Factor
};


class ExportedBySGInfra CATVisDoFQualityData
{
public:
  CATVisDoFQualityData();
  ~CATVisDoFQualityData();

  int operator== (const CATVisDoFQualityData& iData) const;
  CATVisDoFQualityData& operator= (const CATVisDoFQualityData& iData);

  unsigned int  _deactivation : 1;
};

class ExportedBySGInfra CATVisBloomQualityData
{
public:
  CATVisBloomQualityData();
  ~CATVisBloomQualityData();

  int operator== (const CATVisBloomQualityData& iData) const;
  CATVisBloomQualityData& operator= (const CATVisBloomQualityData& iData);

  unsigned int  _deactivation : 1;
  unsigned int  _qualityIndex : 5; // from 1 to 10 (both included)   
};

class CATSupport;
class ExportedBySGInfra CATVisDynamicRenderingQualityData 
{
public:
  CATVisDynamicRenderingQualityData();
  CATVisDynamicRenderingQualityData(const CATSupport& iSupport);
  ~CATVisDynamicRenderingQualityData();

  int operator== (const CATVisDynamicRenderingQualityData& iData) const;
  int operator!= (const CATVisDynamicRenderingQualityData& iData) const;
  CATVisDynamicRenderingQualityData& operator= (const CATVisDynamicRenderingQualityData& iData);

  void Reset();  
  void ApplicateCustomization();

  // General
  unsigned int              _forceDynamicModeOnDraw;

  // AA
  CATVisAAQualityData       _AA;

  // mirroring
  CATVisMirrorQualityData   _mirror;

  // shadow
  CATVisShadowQualityData   _shadows;

  // outlines
  CATVisOutlineQualityData  _outlines;

  // inf env Plane
  CATVisPlaneQualityData    _plane;

  // Glow
  CATVisGlowQualityData     _glowOnScene;
  CATVisGlowQualityData     _glowOnBackground;
    
  // Global Illumination
  CATVisAOQualityData       _ao;

  // Global Illumination
  CATVisEnvMapQualityData   _envMap;

  // Depth of field
  CATVisDoFQualityData _dof;

  // Bloom
  CATVisBloomQualityData _bloom;

};

// pour eviter probleme de compilation
// car anciennement le CATVisRenderingQualityManager se trouvait ici
#include "CATVisRenderingQualityManager.h" 

//-----------------------------------------------------------------------

#endif
