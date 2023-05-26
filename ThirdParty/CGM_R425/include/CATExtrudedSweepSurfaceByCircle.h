// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATExtrudedSweepSurfaceByCircle:
// Utility for producing sweep of Geometric entities.
//=============================================================================
// Usage notes:
//
// - CXR2.
// - reserve (Protected) a l operateur topologique de Sweep.
//=============================================================================
// 17 07 98 CPL Creation
// 17 07 00 NLD 2 ans apres _IncRefToProfileCrv
// 05 12 14 NLD Suppression du constructeur inutile avec surface (phase 1: flaggage)
//              Reordonnancement des arguments du constructeur avec CCVs
// 26/04/21 NLD Suppression du constructeur inutilise avec surface (phase 2: suppression)
//=============================================================================
#ifndef CATExtrudedSweepSurfaceByCircle_H
#define CATExtrudedSweepSurfaceByCircle_H


#include <FrFAdvancedOpeSur.h>                  // For Windows 
class     CATGeoFactory ;
class     CATSweepSurface ;
class     CATCurve;
class     CATFrFCompositeCurve;
class     CATPointOnEdgeCurve;
class     CATEdgeCurve;
class     CATPlane;
#include "CATExtruderByCircle.h"
#include "CATMathAxis.h"
#include "CATMathTransformation.h"

#include <CATMathDef.h>                       // Pour typedef CATBoolean

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur
 CATExtrudedSweepSurfaceByCircle : public CATExtrudedSweepSurface
{
  // NLD051214 friend class CATExtruderByCircle;

  public :

//-------------------------------------------------------------------------
// Constructor from Geometry
//-------------------------------------------------------------------------
CATExtrudedSweepSurfaceByCircle(CATGeoFactory             *  iFactory              ,
                                CATSoftwareConfiguration  *  iSoftwareConfiguration,
                                CATFrFCompositeCurve      *  iProfileCcv           ,
                                CATFrFCompositeCurve      *  iGuideCcv             ,
                                CATMathAxis                & iAxis                 ,
                                CATMathTransformation      & iTransfo              ,
                                CATBoolean                   iRmGuide              = CATBoolean(0));

//-----------------------------------------------------------------------------
//- Destructor 
//-----------------------------------------------------------------------------
virtual ~CATExtrudedSweepSurfaceByCircle() ;

//-------------------------------------------------------------------------
// Run : Calculate Surface
//-------------------------------------------------------------------------
         void       GetResult           ();

         CATPCurve* CreateParallelPCurve(CATPointOnEdgeCurve*  iProfile     ,
                                         CATEdgeCurve       *  iCenter      ,
                                         CATCrvLimits        & iCenterLimits,
                                         CATSurface         *  iSupport     ,
                                         short               & oOrientation )    ;

 private:


  void     GetParams        (CATAngle    & oStart,
                             CATAngle    & oEnd  );
  CATAngle GetAngleFromPoint(CATMathPoint& iPoint);

  CATMathAxis                _Axis;
  CATBoolean                 _RmGuide;
  CATMathTransformation      _Transfo;
  int                        _IncRefToProfileCrv ;
  CATSoftwareConfiguration * _SoftwareConfiguration;
} ;

#endif
