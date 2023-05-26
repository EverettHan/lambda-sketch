// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisToneMappingData_H
#define CATVisToneMappingData_H

#include "SGInfra.h"
#include "CATVisColorf.h"

//-------------------------------------------------------------------------------------
// Tone Mapping

class ExportedBySGInfra CATVisToneMappingData
{
public:
  CATVisToneMappingData();
  virtual ~CATVisToneMappingData();

  enum EType
  {
    eNone,
    eReinhard,
    eFilmicALU,
    ePhotographic
  };
};

//-------------------------------------------------------------------------------------
// Reinhard

class ExportedBySGInfra CATVisToneMappingReinhardData :  public CATVisToneMappingData
{
public:
  CATVisToneMappingReinhardData();
  virtual ~CATVisToneMappingReinhardData();
};

//-------------------------------------------------------------------------------------
// FilmicALU

class ExportedBySGInfra CATVisToneMappingFilmicALUData :  public CATVisToneMappingData
{
public:
  CATVisToneMappingFilmicALUData();
  virtual ~CATVisToneMappingFilmicALUData();

  float a, b, c, d, e, f;
  float w;

  bool operator==(const CATVisToneMappingFilmicALUData& iData) const;
  bool operator!=(const CATVisToneMappingFilmicALUData& iData) const;
};

//-------------------------------------------------------------------------------------
// Photographic

class ExportedBySGInfra CATVisToneMappingPhotographicData :  public CATVisToneMappingData
{
public:
  CATVisToneMappingPhotographicData();
  virtual ~CATVisToneMappingPhotographicData();

  float         _crushBlacks;
  float         _burnHighlights;
  float         _saturation;
  CATVisColorf  _colorCorrection;

  bool operator==(const CATVisToneMappingPhotographicData& iData) const;
  bool operator!=(const CATVisToneMappingPhotographicData& iData) const;
};

#endif
