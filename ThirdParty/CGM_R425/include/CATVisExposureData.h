// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisExposureData_H
#define CATVisExposureData_H

#include "SGInfra.h"

class CATVisParameters;

//-------------------------------------------------------------------------------------
// Exposure

class ExportedBySGInfra CATVisExposureData
{
public:
  CATVisExposureData();
  virtual ~CATVisExposureData();

  enum EType
  {
    eNone,
    eFix,
    eAutoLuminance,
    eAutoHistogram
  };
};

//-------------------------------------------------------------------------------------
// Fix

class ExportedBySGInfra CATVisExposureFixData : public CATVisExposureData
{
public:
  CATVisExposureFixData();
  virtual ~CATVisExposureFixData();
  bool operator==(const CATVisExposureFixData& iData) const;
  bool operator!=(const CATVisExposureFixData& iData) const;

  float _value;
};

//-------------------------------------------------------------------------------------
// Automatic 


class ExportedBySGInfra CATVisExposureAutomaticData : public CATVisExposureData
{
public:
  virtual bool operator==(const CATVisExposureAutomaticData& iData) const;
  virtual bool operator!=(const CATVisExposureAutomaticData& iData) const;

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);

  float         _evC;                     // exposure compensation (unit=log(luminance))
  float         _evMin;                   // exposure min (unit=log(luminance))
  float         _evMax;                   // exposure max (unit=log(luminance))

  bool          _eyeAdaptationActivation;
  float         _eyeAdaptationSpeedUp;
  float         _eyeAdaptationSpeedDown;

protected:
  CATVisExposureAutomaticData();
  virtual ~CATVisExposureAutomaticData();
};


//-------------------------------------------------------------------------------------
// Automatic 

class ExportedBySGInfra CATVisExposureAutomaticBasicData : public CATVisExposureAutomaticData
{
public:
  CATVisExposureAutomaticBasicData();
  virtual ~CATVisExposureAutomaticBasicData();
  virtual bool operator==(const CATVisExposureAutomaticBasicData& iData) const;
  virtual bool operator!=(const CATVisExposureAutomaticBasicData& iData) const;

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);
  
  unsigned int  _luminanceTextureLevel;   // number of mipmap of luminance texture
};

//-------------------------------------------------------------------------------------
// Automatic Histogram


class ExportedBySGInfra CATVisExposureAutomaticHistogramData : public CATVisExposureAutomaticData
{
public:
  CATVisExposureAutomaticHistogramData();
  virtual ~CATVisExposureAutomaticHistogramData();
  virtual bool operator==(const CATVisExposureAutomaticHistogramData& iData) const;
  virtual bool operator!=(const CATVisExposureAutomaticHistogramData& iData) const;

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);

  float _lowPercentage;
  float _highPercentage;
  float _histoEVMin;
  float _histoEVMax;

  unsigned int  _histoPrecision;   // precision of histogram
};


#endif
