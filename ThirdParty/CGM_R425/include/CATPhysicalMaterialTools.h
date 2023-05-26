#ifndef _CATPhysicalMaterialTools_h
#define _CATPhysicalMaterialTools_h

#include "SGInfra.h"

#include "CATIPhysicalMaterial.h"


class ExportedBySGInfra CATPhysicalMaterialTools
{
public:
  static unsigned int SetSampling(CATIPhysicalMaterial* iPhysMat, const VPM::TextureSampler& iSampler);
  static HRESULT GetSampling(const CATIPhysicalMaterial* iPhysMat, VPM::TextureSampler& oSampler);


  static unsigned int SetMinFilterType(CATIPhysicalMaterial* iPhysMat, const VPM::Filtering::Type iFilter);
  static const VPM::Filtering::Type GetMinFilterType(const CATIPhysicalMaterial* iPhysMat);

  static unsigned int SetMagFilterType(CATIPhysicalMaterial* iPhysMat, const VPM::Filtering::Type iFilter);
  static const VPM::Filtering::Type GetMagFilterType(const CATIPhysicalMaterial* iPhysMat);

  static unsigned int SetMipFilterType(CATIPhysicalMaterial* iPhysMat, const VPM::Filtering::Type iFilter);
  static const VPM::Filtering::Type GetMipFilterType(const CATIPhysicalMaterial* iPhysMat);


  static unsigned int SetTexCoordUWrapMode(CATIPhysicalMaterial* iPhysMat, const VPM::Wrapping::Mode iWrap);
  static const VPM::Wrapping::Mode GetTexCoordUWrapMode(const CATIPhysicalMaterial* iPhysMat);

  static unsigned int SetTexCoordVWrapMode(CATIPhysicalMaterial* iPhysMat, const VPM::Wrapping::Mode iWrap);
  static const VPM::Wrapping::Mode GetTexCoordVWrapMode(const CATIPhysicalMaterial* iPhysMat);


  static unsigned int SetBorderColor(CATIPhysicalMaterial* iPhysMat, const CATVisColorf& iColor);
  static HRESULT GetBorderColor(const CATIPhysicalMaterial* iPhysMat, CATVisColorf& oColor);
};

#endif
