// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisBloomData_H
#define CATVisBloomData_H

#include "SGInfra.h"
#include "CATString.h"

//-----------------------------------------------------------------------
// Bloom
class ExportedBySGInfra CATVisBloomData
{
public:
  enum EType
  {
    eNone,
    eBasic
  };

  CATVisBloomData           ();
  virtual ~CATVisBloomData  ();
};

class ExportedBySGInfra CATVisBloomBasicData : public CATVisBloomData
{
public:
  CATVisBloomBasicData          ();
  virtual ~CATVisBloomBasicData ();
  
  // General
  float         _intensity; // bloom scale factor
  float         _threshold; // light intensity threshold
  
  // FireFliy filtering
  // Add a pass to filter some fire fly effect
  bool          _filterFireFly; 
    
  // Dowscale/upscale
  // Add pass to downsample  bloom texture before blurring it
  // And pass to upscale-add before displaying it
  unsigned int  _texturesLevel;   
  enum EDownscaleQuality
  {
    eDownscaleLow = 0,
    eDownscaleMax
  };
  EDownscaleQuality _downscaleQuality;

  // Gaussian Blur
  unsigned int  _blurNumPass;
  float         _blurSize;
  float         _blurNumSamples;
    
  bool operator!=(const CATVisBloomBasicData& iData) const;
  bool operator==(const CATVisBloomBasicData& iData) const;
};

#endif
