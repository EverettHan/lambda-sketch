// COPYRIGHT Dassault Systemes 2016

#ifndef CATVisReflectedLightingData_H
#define CATVisReflectedLightingData_H

#include "SGInfra.h"

#include "CATVisParameters.h"

#include "CATString.h"

class ExportedBySGInfra CATVisReflectedLightingData
{
public:
  CATVisReflectedLightingData();
  virtual ~CATVisReflectedLightingData();

  int operator!=(const CATVisReflectedLightingData& iData) const;

  enum EType
  {
    eNone,
    eSSR
  };

  unsigned int _usePlane;

private:
  friend class  VisCustomizeReflections;
  friend class  CATVisInfiniteEnvironmentStreamer;
  friend class  vREPassSystemUpdater;
  friend class  VisInfiniteEnvNewPanel;

  unsigned int _ignoreQualitySetting;
};

class ExportedBySGInfra CATVisSSRData : public CATVisReflectedLightingData
{
public:
  CATVisSSRData();
  virtual ~CATVisSSRData();

  inline bool IsActiveOnGround() const { return (0 != _activeOnGround); }
  inline bool IsActiveOnOpaque() const { return (0 != _activeOnOpaque); }
  inline bool IsStochasticSSRActive() const { return (0 != _activeOnGround || 0 != _activeOnOpaque); }
  inline bool IsSSRTemporalActive() const { return (0 != _temporalFilter); }

  int operator!=(const CATVisSSRData& iData) const;

  bool          _activeOnGround;
  bool          _activeOnOpaque;

private:
  friend class  VisCustomizeReflections;
  friend class  CATVisInfiniteEnvironmentStreamer;
  friend class  l_vREPassSystemFactory;
  friend class  vREPassSystemUpdater;
  friend class  VisInfiniteEnvNewPanel;

  float         _rayDepthDiscontinuity;
  float         _rayMarchingPrecision;
  float         _rayZBias;

  // Pass system rebuild needed
  enum ERadFromRoughType
  {
    eDisabled   = 0,
    eMipMap     = 1
  };

  ERadFromRoughType _radianceFromRoughness;
  unsigned int  _radFromRoughMipsCount;
  unsigned int  _maxDepthResolutionX;
  unsigned int  _maxDepthResolutionY;
  unsigned int  _lowResDepthDivider;
  bool          _rayMarchingZHierarchy;
  bool          _normalization;
  bool          _temporalFilter;
  bool          _rayBasedReprojection;
  bool          _pixelResolveJitter;
};

#endif
