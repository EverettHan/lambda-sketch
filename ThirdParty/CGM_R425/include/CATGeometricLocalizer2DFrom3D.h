
//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================


#ifndef CATGeometricLocalizer2DFrom3D_H
#define CATGeometricLocalizer2DFrom3D_H
#include "CATLocalizer2DFrom3D.h"
#include "FrFAdvancedOpeCrv.h"

class CATSurParam;
class CATMathPoint;
class CATPCurve;
class CATSurface;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATSurLimits;
class CATDistanceMinPtSur;
class CATCrvLimits;
//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeCrv CATGeometricLocalizer2DFrom3D : public CATLocalizer2DFrom3D
{
public :
           CATGeometricLocalizer2DFrom3D(      CATGeoFactory            * geoFact    ,
                                               CATSoftwareConfiguration * iSoftConfig,
                                               CATSurface               * surface    ,
                                               CATSurLimits             * iSurLimits );

  virtual ~CATGeometricLocalizer2DFrom3D();

  //-------------------  Other Methods ------------------------ 
  CATLONG32 WhatSupportOfCurve          (const CATPCurve    * iPCurve       ,
                                               CATLONG32    & ioSupportIndex);

  CATLONG32 WhatSupportOfCurve          (const CATPCurve    * iPCurve       ,
                                               CATLONG32    & ioSupportIndex,
                                         const CATCrvLimits * iLimits       );

  CATLONG32 ProjPoint3DOnSupportBoundary(const CATMathPoint & i3DPoint      ,
                                               CATLONG32      iSupport1Index,
                                               CATLONG32      iSupport2Index,
                                               CATSurParam  & ioSurParam1   ,
                                               CATSurParam  & ioSurParam2   );

  CATLONG32 ProjPoint3DOnSupport        (const CATMathPoint & i3DPoint      ,
                                               CATLONG32      iSupportIndex ,
                                               CATSurParam  & ioSurParam   );
private :
  CATGeoFactory           * _Factory;
  CATSoftwareConfiguration* _SoftConfig;
  CATSurface              * _Surface;
  CATSurLimits            * _Limits;
  CATDistanceMinPtSur     * _DistanceMinPtSur;
};
#endif








