
#ifndef CATAutomaticDraftContext_H
#define CATAutomaticDraftContext_H

// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
//
// CATAutomaticDraftContext : 
// Informations for the draft operator given by the automatic draft operator
//
// Jan. 05    Creation                         PFV
// 27/02/09 NLD Il faut proteger les configurations. On utilise
//              CATSoftwareConfigurationAddRef() et CATSoftwareConfigurationRelease()
//              N.B Tout cela serait largement aussi bien sans INLINE
//------------------------------------------------------------------------------

#include "Draft.h"
#include "CATTopRibDef.h"
#include "CATMath.h"
#include "CATMathPoint.h"
#include "ListPOfCATFace.h"
#include "CATCGMStream.h"
#include "CATListOfDouble.h"
#include "CATListOfCATGeometries.h"
#include "CATEdgeCurve.h"
#include "CATCGMVirtual.h"
#include "CATSoftwareConfiguration.h"
#include "CATSoftwareConfigurationAddRef.h"
#include "CATMathInline.h"

class CATGeoFactory;
class CATTopRib;
class CATDrftRib;
class CATTopRibNuplet;
class CATBody;
class CATGeometry;

class ExportedByDraft CATAutomaticDraftContext : public CATCGMVirtual
{
private:
  enum CATAutomaticDraftMode
  {
    CATAutoDraftAdd,
    CATAutoDraftRemove
  };
public :
  INLINE CATAutomaticDraftContext(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig);
  virtual ~CATAutomaticDraftContext();
  INLINE void SetAddMode();
  INLINE void SetRemoveMode();
  INLINE void SetDraftSkinHeight(double iHeight);
  INLINE void SetCriticalPointStoppingAngle(double iCriticalPointStoppingAngle);
  INLINE void SetRibbonStartPoint(CATMathPoint &iStartMathPoint, ListPOfCATFace &iStarPointSupportFaces);
  INLINE void SetRibbonEndPoint(CATMathPoint &iEndMathPoint, ListPOfCATFace &iEndPointSupportFaces);
  INLINE void SetStopRibbonBeforeCriticalPoint(CATBoolean iStopRibbon);

  INLINE SupportEdgeType GetEdgeType();
  INLINE void GetGlobalHeight(double ioGlobalHeight[2]);
  INLINE double GetCriticalPointStoppingAngle();
  CATBoolean IsDraftRibbonValid(CATTopRib * iDraftRibbon);
  void RestrictDrftRibToOuterConeNuplets(CATDrftRib &ioDrftRib);
  INLINE CATBoolean StopRibbonBeforeCriticalPoint();
  INLINE CATBoolean HasUsedCriticalPointStoppingAngle();
  INLINE void UsedCriticalPointStoppingAngle();
  
  INLINE CATBoolean IsTwistDetectionRequired() {return _IsTwistDetectionRequired;}
  INLINE void SetTwistDetectionRequired() {_IsTwistDetectionRequired = TRUE;}
  INLINE void SetPartingForTwistDetection(CATBody* iPartingBody) {_PartingForTwistDetection = iPartingBody; }
  INLINE CATBody* GetPartingForTwistDetection() {return _PartingForTwistDetection;}
  INLINE void SetDraftSurfaceHeights(CATLISTP(CATGeometry)& iSupportGeometry, CATListOfDouble& iSurfaceHeight,CATListOfDouble& iMinSurfaceHeight);
  CATBoolean GetDraftSurfaceHeight(CATGeometry* iSupportGeometry, double ioSurfaceHeight[2]);
  CATBoolean UpdateDraftSurfaceHeights(const CATLISTP(CATFace) &iInitialFaces );
  CATBoolean PossibleCriticalPoint(CATGeometry* iSupportGeometry);

  void  Stream   (CATCGMStream& os);
  void  UnStream (CATCGMStream& os);
  void  Dump (CATCGMOutput& os);
private:
  void NupletContainsExtremities(CATTopRibNuplet &ioNuplet, CATBoolean ioExtremityFound[2]);

private :
  CATGeoFactory * _Factory;
  CATSoftwareConfiguration * _Config;
  CATAutomaticDraftMode _Mode;
  double _DraftSkinHeight;
  double _CriticalPointStoppingAngle;
  CATBoolean _ExtremityPointSet[2];
  CATMathPoint _ExtremityMathPoint[2];
  ListPOfCATFace _ExtremityPointSupportFaces[2];
  CATBoolean _StopRibbonBeforeCriticalPoint;
  CATBoolean _UsedCriticalPointStoppingAngle;
  CATBoolean _IsTwistDetectionRequired;
  CATBody* _PartingForTwistDetection; //input

  CATListOfDouble _DraftSurfaceHeights, _MinDraftSurfaceHeights;//input
  CATLISTP(CATGeometry) _DraftSupportGeometry;//input
  CATListOfDouble _UpdatedDraftSurfaceHeights;//generated
  CATLISTP(CATFace) _FacesToDraft;//generated

private:
  CATAutomaticDraftContext(CATAutomaticDraftContext& iOperator);
  CATAutomaticDraftContext& operator=(const CATAutomaticDraftContext & iOperator);
};

INLINE CATAutomaticDraftContext::CATAutomaticDraftContext(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig)
{
  _Factory = iFactory;
  _Config = iConfig;
  CATSoftwareConfigurationAddRef(_Config, this);//NLD270209
  _Mode = CATAutomaticDraftContext::CATAutoDraftAdd;
  _DraftSkinHeight = 0.;
  _CriticalPointStoppingAngle = 0.;
  _ExtremityPointSet[0] = FALSE;
  _ExtremityPointSet[1] = FALSE;
  _StopRibbonBeforeCriticalPoint = FALSE;
  _UsedCriticalPointStoppingAngle = FALSE;
  _IsTwistDetectionRequired = FALSE;
  _PartingForTwistDetection = NULL;
}
INLINE void CATAutomaticDraftContext::SetAddMode()
{
  _Mode = CATAutomaticDraftContext::CATAutoDraftAdd;
}
INLINE void CATAutomaticDraftContext::SetRemoveMode()
{
  _Mode = CATAutomaticDraftContext::CATAutoDraftRemove;
}
INLINE void CATAutomaticDraftContext::SetDraftSkinHeight(double iHeight)
{
  _DraftSkinHeight = iHeight;
}
INLINE void CATAutomaticDraftContext::SetCriticalPointStoppingAngle(double iCriticalPointStoppingAngle)
{
  _CriticalPointStoppingAngle = iCriticalPointStoppingAngle;
}
INLINE void CATAutomaticDraftContext::SetStopRibbonBeforeCriticalPoint(CATBoolean iStopRibbon)
{
  _StopRibbonBeforeCriticalPoint = iStopRibbon;
}
INLINE SupportEdgeType CATAutomaticDraftContext::GetEdgeType()
{
  if (_Mode == CATAutomaticDraftContext::CATAutoDraftAdd)
    return EdgeTypeHigh;
  else
    return EdgeTypeLow;
}
INLINE void CATAutomaticDraftContext::GetGlobalHeight(double ioGlobalHeight[2])
{
  if (_Mode == CATAutomaticDraftContext::CATAutoDraftAdd)
  {
    ioGlobalHeight[0] = 0.;
    ioGlobalHeight[1] = CATMax(ioGlobalHeight[1], _DraftSkinHeight);
  }
  else
  {
    ioGlobalHeight[0] = CATMin(ioGlobalHeight[0], -_DraftSkinHeight);
    ioGlobalHeight[1] = 0.;
  }
}
INLINE double CATAutomaticDraftContext::GetCriticalPointStoppingAngle()
{
  return _CriticalPointStoppingAngle;
}
INLINE CATBoolean CATAutomaticDraftContext::StopRibbonBeforeCriticalPoint()
{
  return _StopRibbonBeforeCriticalPoint;
}

INLINE void 
CATAutomaticDraftContext::SetRibbonStartPoint(CATMathPoint &iStartMathPoint, ListPOfCATFace &iStarPointSupportFaces)
{
  _ExtremityPointSet[0] = TRUE;
  _ExtremityMathPoint[0] = iStartMathPoint;
  _ExtremityPointSupportFaces[0].RemoveAll();
  _ExtremityPointSupportFaces[0].Append(iStarPointSupportFaces);
}

INLINE void 
CATAutomaticDraftContext::SetRibbonEndPoint(CATMathPoint &iEndMathPoint, ListPOfCATFace &iEndPointSupportFaces)
{
  _ExtremityPointSet[1] = TRUE;
  _ExtremityMathPoint[1] = iEndMathPoint;
  _ExtremityPointSupportFaces[1].RemoveAll();
  _ExtremityPointSupportFaces[1].Append(iEndPointSupportFaces);
}

INLINE CATBoolean CATAutomaticDraftContext::HasUsedCriticalPointStoppingAngle()
{
  return _UsedCriticalPointStoppingAngle;
}

INLINE void CATAutomaticDraftContext::UsedCriticalPointStoppingAngle()
{
  if( TRUE == _StopRibbonBeforeCriticalPoint)
   _UsedCriticalPointStoppingAngle = TRUE;
}

INLINE void CATAutomaticDraftContext::SetDraftSurfaceHeights(CATLISTP(CATGeometry)& iSupportGeometry
                                                            ,CATListOfDouble& iSurfaceHeight
                                                            ,CATListOfDouble& iMinSurfaceHeight)
{
  _DraftSupportGeometry.RemoveAll();
  _DraftSurfaceHeights.RemoveAll();
  _MinDraftSurfaceHeights.RemoveAll();

  _DraftSupportGeometry.Append(iSupportGeometry);
  _DraftSurfaceHeights.Append(iSurfaceHeight);
  _MinDraftSurfaceHeights.Append(iMinSurfaceHeight);

}
#endif
