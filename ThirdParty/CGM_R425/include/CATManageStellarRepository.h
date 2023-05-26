#ifndef CATManageStellarRepository_H
#define CATManageStellarRepository_H

#include "DSYString.h"
#include "SGInfra.h"

class CATSettingRepository;

class ExportedBySGInfra CATManageStellarRepository
{
private:
  CATManageStellarRepository();
  
  static CATSettingRepository* stellarRepositoryCtrl;

public:
  enum class eDynamicMode     { Rasterizer = 0, GlobalIllumination = 1 };
  //PKO1: 08.Oct.20 replacing "enum" with "enum class" as per C++ guideline. Waiting for the migration of CATRdgLiveOptionsWidget
  enum /*class*/ eHardwareMode    { CPU = 0, GPU = 1 };
  enum class eDistributedMode { Full = 0, CompressRGB = 1 };

  ~CATManageStellarRepository();

  static CATSettingRepository* GetRepository();

  static eDynamicMode CATGetDynamicMode();
  static void CATSetDynamicMode(const eDynamicMode);

  static unsigned int CATGetTransitionFrames();
  static void CATSetTransitionFrames(const int);
  
  static eHardwareMode CATGetHardwareMode();
  static void CATSetHardwareMode(const eHardwareMode);

  static CATBoolean CATGetDistributedRendering();
  static void CATSetDistributedRendering(const CATBoolean);
   
  static eDistributedMode CATGetDistributedRenderingMode();
  static void CATSetDistributedRenderingMode(const eDistributedMode);

  static CATUnicodeString CATGetHostnameValue();
  static void CATSetHostnameValue(const CATUnicodeString);

  static unsigned int CATGetPortValue();
  static void CATSetPortValue(const int);

  static CATUnicodeString CATGetLocalHostnameValue();
  static void CATSetLocalHostnameValue(const CATUnicodeString);

  static CATBoolean CATGetEnableCompression();
  static void CATSetEnableCompression(const CATBoolean);

  static unsigned int CATGetCompressionRatio();
  static void CATSetCompressionRatio(const int);

  static CATBoolean CATGetEnablePersistencyMode();
  static void CATSetEnablePersistencyMode(const CATBoolean DisablePersistencyMode);

  static CATBoolean CATGetDisableNoShowTranslation();
  static void CATSetDisableNoShowTranslation(const CATBoolean DisableNoShowTranslation);
      
  static void CATSaveStellarRepository();
  static void CATCommitStellarRepository();
};

#endif
