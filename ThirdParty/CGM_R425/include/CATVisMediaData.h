// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisMediaData_H
#define CATVisMediaData_H

#include "SGInfra.h"
#include "CATVisColorf.h"
#include "CATMathVectorf.h"
#include "CATString.h"
#include "IVisTexturePtr.h"

class ExportedBySGInfra CATVisMediaData
{
public:
  enum EType
  {
    eNone,
    eSkyScattering
  };

  CATVisMediaData();
  virtual ~CATVisMediaData();
};


class ExportedBySGInfra CATVisMediaSkyScatteringData : public CATVisMediaData
{
public:
  CATVisMediaSkyScatteringData();
  CATVisMediaSkyScatteringData(const CATVisMediaSkyScatteringData& iData);
  const CATVisMediaSkyScatteringData& operator=(const CATVisMediaSkyScatteringData& iData);
  virtual ~CATVisMediaSkyScatteringData();

  int operator!=(const CATVisMediaSkyScatteringData& iData) const;

  float           atmosphereHeight;         // épaisseur de l'atmosphère en km

  float           sunScatteringIntensity;   // intensity du soleil pour l'effet de scattering

  unsigned int    reflectedLightAttenuation;// attenuation of reflected light activation along path

  // Mie
  float           hM;                       // Mie scale height
  CATMathVectorf  betaM;                    // Mie scattering coefficients at sea level
  float           mieG;                     // Phase function: variable pour controler l'anisotropy du milieu

  // Rayleigh
  float           hR;                       // Rayleigh scale height
  CATMathVectorf  betaR;                    // Rayleigh scattering coefficients at sea level

  float           averageGroundReflectance;

  // Night Haze     
  CATVisColorf    nightHazeColor;        
  float           nightHazeFogIntensity; 
  float           nightHazeSkyIntensity;    
  float           nightHazeSkyPower;    
  
  // Textures for scattering
  CATString       skyTransmittance;
  CATString       skyIrradiance;
  CATString       skyInScatter;
  
  void SetSkyTransmittance (const IVisTexturePtr& iTexture);
  void SetSkyIrradiance    (const IVisTexturePtr& iTexture);
  void SetSkyInScatter     (const IVisTexturePtr& iTexture);

  inline const IVisTexturePtr&  GetSkyTransmittance () const {return m_SkyTransmittance;};
  inline const IVisTexturePtr&  GetSkyIrradiance    () const {return m_SkyIrradiance;};
  inline const IVisTexturePtr&  GetSkyInScatter     () const {return m_SkyInScatter;};

private:
  IVisTexturePtr  m_SkyTransmittance;
  IVisTexturePtr  m_SkyIrradiance;
  IVisTexturePtr  m_SkyInScatter;
};

#endif
