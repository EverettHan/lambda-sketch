#ifndef CATVisClippingVolumesFilter_H
#define CATVisClippingVolumesFilter_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2016
//-----------------------------------------------------------------------------
// Class  :  	CATVisClippingVolumesFilter
// Date   :  	13/01/16
//-----------------------------------------------------------------------------
//  Inheritance : CATVisClippingVolumesFilter
//					CATVisFilter
//-----------------------------------------------------------------------------
//  Abstract : EXPERIMENTAL, NO SUPPORT!
//             DO NOT USE WITHOUT ASKING TO RENDER ENGINE TEAM!
//-----------------------------------------------------------------------------
//  Main Methods : N/A
//-----------------------------------------------------------------------------

// Local Framework
#include "SGInfra.h"

#include "CATVisFilter.h"
#include "CATMathDirectionf.h"
#include "VisClippingDesc.h"
class CATVisClippingVolume;
class CAT3DViewpoint;
class IVisSGClippingFilter;

//#define DEBUG_CLIPPING_VOLUME_WITH_GP
#ifdef DEBUG_CLIPPING_VOLUME_WITH_GP
class CATGraphicPrimitive;
#endif


class ExportedBySGInfra CATVisClippingVolumesFilter : public CATVisFilter 
{
	CATDeclareVisFilter(CATVisClippingVolumesFilter);
  CATVisDeclarePublicInterfaceAdhesion(CATVisClippingVolumesFilter, IVisSGClippingFilter, CATVisClippingVolumesFilterIVisSGClippingFilterBOAImpl);

public:
  enum class EClippingMethod : unsigned int
  {
    eInvalid = 0,
    eTriangleListOctree,
    eDistanceFieldOctree,
    eFullscreenMap,
    eAdvised = eTriangleListOctree,
  };
  static CATVisClippingVolumesFilter* Create(EClippingMethod iMethod = EClippingMethod::eAdvised, unsigned int iFlags = VisClippingDesc::fAllowUncutting /*fDefault*/);

  unsigned int GetClippingDescFlags() const;

  EClippingMethod GetClippingMethod() const;

	HRESULT AddVolume(CATVisClippingVolume* iVolume);
	HRESULT RemoveVolume(CATVisClippingVolume* iVolume);
	HRESULT RemoveAllVolumes();

	const unsigned int GetVolumesCount() const;
	const CATVisClippingVolume* GetVolume(unsigned int iVolumeID) const;

  enum EClipDirMode
  {
    eRemoveInside_XORIntersect,
    eRemoveOutside_XORIntersect,
    eClipDirMode_Count,
    eClipDirMode_Invalid
  };
  HRESULT SetClippingDirectionMode(EClipDirMode iClipDirMode);
  const EClipDirMode GetClippingDirectionMode() const;

  HRESULT SetOctreeDepth(unsigned int iDepth);
  const unsigned int GetOctreeDepth() const;

  HRESULT SetDebugMode(CATBoolean iDebug);
  CATBoolean GetDebugMode() const;

  enum EViewpointsType
  {
    eAllViewpoints,
    eOnlyCylindricViewpoints,
    eOnlyConicViewpoints,
    eUserDefinedViewpoints,
    eViewpointsType_Count,
    eViewpointsType_Invalid
  };
  HRESULT SetSupportedViewpointsType(const EViewpointsType iVpType);
  const EViewpointsType GetSupportedViewpointsType() const;

  HRESULT AddUserViewpoint(CAT3DViewpoint* iVp);
  HRESULT RemoveUserViewpoint(CAT3DViewpoint* iVp);
  HRESULT RemoveAllUserViewpoints();

  const unsigned int GetUserViewpointsCount() const;
  const CAT3DViewpoint* GetUserViewpoint(unsigned int iVpID) const;

  HRESULT SetSavedCylindricViewsCount(unsigned int iSavedCount);
  const unsigned int GetSavedCylindricViewsCount() const;

  HRESULT GenerateCylindricViewData(const CATMathDirectionf& iEyeDir, const CATMathDirectionf& iEyeUp);

  const unsigned int GetCylindricViewDataSize(const CATMathDirectionf& iEyeDir) const;
  HRESULT ExportCylindricViewData(const CATMathDirectionf& iEyeDir, unsigned char* iDataBuffer) const;
  HRESULT ImportCylindricViewData(const CATMathDirectionf& iEyeDir, const unsigned char* iDataBuffer, const unsigned int iDataSize);

  const unsigned int GetDataSize() const;
  HRESULT ExportData(unsigned char* iDataBuffer) const;
  HRESULT ImportData(const unsigned char* iDataBuffer, const unsigned int iDataSize);

  // WARNING: When data computation is not allowed and no data has been imported, the filter won't be applied!
  HRESULT AllowDataComputation(CATBoolean iAllow);
  CATBoolean IsDataComputationAllowed() const;

  bool IsObservable() const;

  virtual void Visit(VisSGFilterVisitor& iVisitor) const;

#ifdef DEBUG_CLIPPING_VOLUME_WITH_GP
  CATGraphicPrimitive* BuildGPFromClippingVolumes() const;
#endif

private:
	CATVisClippingVolumesFilter(EClippingMethod iMethod, unsigned int iFlags);
	virtual ~CATVisClippingVolumesFilter();
};

#endif
