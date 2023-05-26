// COPYRIGHT Dassault Systemes 2018

#ifndef CATVisInfiniteEnvPostEffectsOverload_H
#define CATVisInfiniteEnvPostEffectsOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATVisToneMappingData.h"
#include "CATVisExposureData.h"
#include "CATVisDOFData.h"
#include "CATVisBloomData.h"
#include "CATVisVignettingData.h"
#include "CATVisGammaCorrectionData.h"
#include "CATVisColorGradingData.h"
#include "IVisTexturePtr.h"
#include "CATVisMotionBlurData.h"

class CATSupport;
class ExportedByCATVisFoundation CATVisInfiniteEnvPostEffectsOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvPostEffectsOverload* Create();
  
  //-------------------------------
  // Set data to overload all different post process on current infinite environement

  void  SetToneMapping    (const CATVisToneMappingPhotographicData& iData);
  void  SetExposure       (const CATVisExposureFixData&             iData);
  void  SetDOF            (const CATVisDOFBokehData&                iData);
  void  SetBloom          (const CATVisBloomBasicData&              iData);
  void  SetVignetting     (const CATVisVignettingPhotographicData&  iData);
  void  SetGammaCorrection(const CATVisGammaCorrectionData&         iData);
  void  SetColorGrading   (const CATVisColorGradingLUTData&         iData);
  void  SetMotionBlur     (const CATVisMotionBlurCameraMotionData&  iData);
  
  //-------------------------------
  // Deactivate overlaod on specific post process

  void  RemoveToneMapping ();
  void  RemoveExposure    ();
  void  RemoveDOF         ();
  void  RemoveBloom       ();
  void  RemoveVignetting  ();
  void  RemoveGammaCorrection();
  void  RemoveColorGrading();
  void  RemoveMotionBlur();
  
  virtual bool IsOverloaded(EProperty iProperty) const;
  virtual bool IsActivated() const;
  
protected:
  virtual void Overload (CATVisPostEffects& ioData)                     const;
  virtual void Overload (CATVisInfiniteEnvironmentExtendedData& ioData) const;
  
private:
  CATVisInfiniteEnvPostEffectsOverload();
  virtual ~CATVisInfiniteEnvPostEffectsOverload();
      
  IVisTexturePtr _CreateTextureFromFile(const CATString& iTexture) const;

  bool  m_ToneMappingActivation;
  bool  m_ExposureActivation;
  bool  m_DOFActivation;
  bool  m_BloomActivation;
  bool  m_VignettingActivation;
  bool  m_GammaCorrectionActivation;
  bool  m_ColorGradingActivation;
  bool  m_MotionBlurActivation;
  
  CATVisToneMappingPhotographicData m_ToneMapping;
  CATVisExposureFixData             m_Exposure;
  CATVisDOFBokehData                m_DOF;
  CATVisBloomBasicData              m_Bloom;
  CATVisVignettingPhotographicData  m_Vignetting;
  CATVisGammaCorrectionData         m_GammaCorrection;
  CATVisColorGradingLUTData         m_ColorGrading;
  CATVisMotionBlurCameraMotionData  m_MotionBlur;

  IVisTexturePtr  m_BokehTexture;
  IVisTexturePtr  m_LookupTable;
};

//-----------------------------------------------------------------------

#endif
