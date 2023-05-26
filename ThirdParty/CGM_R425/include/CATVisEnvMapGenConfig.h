#ifndef CATVisEnvMapGenConfig_H_
#define CATVisEnvMapGenConfig_H_

#include "SGInfra.h"

class CATSupport;
class CAT3DViewpoint;


/**
  * Interface class which allow to customize environment map generation
  * @warning Overridden methods must not modify given support and viewpoint!
  */
class ExportedBySGInfra CATVisEnvMapGenConfig
{
public:
  CATVisEnvMapGenConfig();

  void AddRef() const;
  void Release() const;

  enum FInfEnvCleanFlags
  {
    fInfEnvClean_None = 0,
    fInfEnvClean_CustomEffects = (1 << 0),
    fInfEnvClean_Exposure = (1 << 1),
    fInfEnvClean_GammaCorrection = (1 << 2),
    fInfEnvClean_ToneMapping = (1 << 3),
    fInfEnvClean_Plane = (1 << 4),
    fInfEnvClean_Bloom = (1 << 5),
    fInfEnvClean_Vignetting = (1 << 6),
    fInfEnvClean_DOF = (1 << 7),
    fInfEnvClean_ReflectedLighting = (1 << 8),
    fInfEnvClean_GenerateHDR = (fInfEnvClean_ToneMapping | fInfEnvClean_Exposure | fInfEnvClean_Bloom),
    fInfEnvClean_MapEdgesInconsistency = (fInfEnvClean_DOF | fInfEnvClean_ReflectedLighting),
    fInfEnvClean_All = 0xFFFFFFFF
  };
  void SetEnvironmentCleaning(unsigned int iCleanFlags) { m_CleanInfEnv = iCleanFlags; }
  unsigned int GetEnvironmentCleaning() const { return m_CleanInfEnv; }

  // Methods which should be overridden
  virtual void BeginCubeMapFaceRender(const CATSupport& iSupport, const CAT3DViewpoint& iVp) {}
  virtual void EndCubeMapFaceRender(const CATSupport& iSupport, const CAT3DViewpoint& iVp) {}

protected:
  virtual ~CATVisEnvMapGenConfig();

private:
  mutable int m_RefCount;
  unsigned int m_CleanInfEnv;
};

#endif // CATVisEnvMapGenConfig_H_
