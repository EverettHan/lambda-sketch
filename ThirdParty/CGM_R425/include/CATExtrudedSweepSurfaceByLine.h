// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATExtrudedSweepSurfaceByLine:
// Utility for producing sweep of Geometric entities.
//=============================================================================
// Usage notes:
//
// - CXR2.
// - reserve (Protected) a l operateur topologique de Sweep.
//=============================================================================
// 17 07 98 CPL Creation
// 03 07 01 CPL quasi 3 ans apres _IncRefToProfileCrv
// 28 05 03 NLD Argument iCenterLimits à GetParams()
// 05/12/14 NLD Suppression du constructeur inutilise avec surface (phase 1: flaggage)
//              Reordonnancement des arguments du constructeur avec CCVs
// 26/04/21 NLD Suppression du constructeur inutilise avec surface (phase 2: suppression)
//=============================================================================
#ifndef CATExtrudedSweepSurfaceByLine_H
#define CATExtrudedSweepSurfaceByLine_H


#include <FrFAdvancedOpeSur.h>                  // For Windows 
class CATGeoFactory ;
class CATSweepSurface ;
class CATCurve;
class CATFrFCompositeCurve;
class CATMathDirection;
class CATPointOnEdgeCurve;
class CATEdgeCurve;
class CATPlane;
#include <CATMathTransformation.h>
#include <CATSoftwareConfiguration.h>

#include <CATMathDef.h>                       // Pour typedef CATBoolean

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur
 CATExtrudedSweepSurfaceByLine : public CATExtrudedSweepSurface
{
  public :

//-------------------------------------------------------------------------
// Constructor from Geometry
//-------------------------------------------------------------------------
CATExtrudedSweepSurfaceByLine( CATGeoFactory            *  iFactory              ,
                               CATSoftwareConfiguration *  iSoftwareConfiguration,
                               CATFrFCompositeCurve     *  iProfileCcv           ,
                               CATFrFCompositeCurve     *  iGuideCcv             ,
                               CATMathTransformation     & iTransfo              ,
                               CATBoolean                  iRmGuide              = CATBoolean(0)
                             );

//-----------------------------------------------------------------------------
//- Destructor 
//-----------------------------------------------------------------------------
virtual            ~CATExtrudedSweepSurfaceByLine() ;

//-------------------------------------------------------------------------
// Run : Calculate Surface
//-------------------------------------------------------------------------
         void       GetResult           ();

         CATPCurve* CreateParallelPCurve(CATPointOnEdgeCurve*  iProfile         ,
                                         CATEdgeCurve       *  iCenter          ,
                                         CATCrvLimits        & iCenterLimits    ,
                                         CATSurface         *  iSupport         ,
                                         short               & oOrientation     );

 private:
  // On peut passer optionnellement des limites
         void       GetParams           (CATCrvLimits       *  iCenterLimits    ,
                                         CATMathDirection    & oExtrudeDirection,
                                         CATLength           & oStart           ,
                                         CATLength           & oEnd             );

  CATBoolean                 _RmGuide;
  CATMathTransformation      _Transfo;
  CATLONG32                  _IncRefToProfileCrv ;
  CATSoftwareConfiguration * _SoftwareConfiguration;
} ;

#endif
