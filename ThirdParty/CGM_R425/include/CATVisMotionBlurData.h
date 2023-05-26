#ifndef CATVisMotionBlurData_H
#define CATVisMotionBlurData_H

#include "SGInfra.h"
//-----------------------------------------------------------------------
//Motionblur

class ExportedBySGInfra CATVisMotionBlurData
{
public:
  enum EType
  {
    eNone,
    eCameraMotion
  };

  CATVisMotionBlurData();
  virtual ~CATVisMotionBlurData();
};

class ExportedBySGInfra CATVisMotionBlurCameraMotionData : public CATVisMotionBlurData
{
public:
  CATVisMotionBlurCameraMotionData();
  virtual ~CATVisMotionBlurCameraMotionData();

  float m_Strength; // scale parameter for the length of the motion vectors.;
  
  bool operator!=(const CATVisMotionBlurCameraMotionData& iData) const;
  bool operator==(const CATVisMotionBlurCameraMotionData& iData) const;
};


#endif
