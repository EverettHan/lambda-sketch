#ifndef CATFrFOpeZAP_H
#define CATFrFOpeZAP_H
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATFrFOpeZAP:
// Utility for code zap and code coverage for FreeFormOperators
// Not to be used except for debug and test purpose
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//=============================================================================
// 16 09 05 NLD Creation
// 19 09 05 NLD _CATGeneralizedSweepSurfaceCx2_ForceFitting
// 20 09 05 NLD _CATAdvancedLawUtilities_DumpLaw
// 21 09 05 NLD _CATFrFCompositeCurveMapping_DumpMapping
// 28 09 05 NLD _CATFrFSweepMesh_RunWithoutOrdering
// 29 09 05 NLD _CATExtrudedSweepSurface_NoLockGeometry
// 29 09 05 NLD _CATBiRailSweepCx2_ForceImposedPointsCoupling
// 05 10 05 JSX _CATGeneralizedSweepSurfaceCx2_UntwistShape
// 24 06 06 NLD _CATFrFCompositeCurveMapping_ValidLivingCurves
// 20 02 09 NLD _CATExtruder_C0Point_2PointsCaseToCover
// 11 07 12 NLD _CATExtruder_C0MeridianCurve_ForceKO
// 17 10 13 NLD _CATMathExplicitInterpolStoredData_DefaultMaxNumberOfPatches
//              _CATFrFExtractCombForSweep_G2Threshold
// 05 05 14 NLD _CATFrFSegmentProfile_ForceRidge
//=============================================================================
#include <FrFOpeUtil.h>
#include <CATBoolean.h>
class ExportedByFrFOpeUtil CATFrFOpeZAP 
{
 public:
 //-----------------------------------------------------------------------------
 // Constructor 
 //-----------------------------------------------------------------------------
 CATFrFOpeZAP() ;
 //-----------------------------------------------------------------------------
 // Destructor 
 //-----------------------------------------------------------------------------
 ~CATFrFOpeZAP() ;
 //
 CATBoolean _CATGeneralizedSweepSurfaceCx2_ComputeRecoilDistance ;
 int        _CATGeneralizedSweepSurfaceCx2_FittingMode ;                  // 0 : no fitting, 1: fitting, 2: fitting c2
 CATBoolean _CATAdvancedLawUtilities_DumpLaw ;
 CATBoolean _CATFrFCompositeCurveMapping_DumpMapping ;
 CATBoolean _CATFrFSweepMesh_RunWithoutOrdering ;
 CATBoolean _CATExtrudedSweepSurface_NoLockGeometry ;
 CATBoolean _CATBiRailSweepCx2_ForceImposedPointsCoupling ;
 int        _CATGeneralizedSweepSurfaceCx2_UntwistShape;                  // 0 : no untwist/ 1:UntwistZone / 2:Concatenation
 CATBoolean _CATFrFCompositeCurveMapping_ValidLivingCurves;               // pour verifier a tout moment que les courbes des ccvs sont vivantes
 int        _CATExtruder_C0Point_2PointsCaseToCover;                      // pour test boite blanche, passe-t-on dans le code?
 CATBoolean _CATExtruder_C0MeridianCurve_ForceKO;                         // pour forcer erreur C0MeridianCurve
 int        _CATMathExplicitInterpolStoredData_DefaultMaxNumberOfPatches;
 double     _CATFrFExtractCombForSweep_G2Threshold;
 CATBoolean _CATFrFSegmentProfile_ForceRidge;                             // pour forcer le mode Ridge (pliage) dans le sweep draft equerre

};
// Get current ZAP if exists
ExportedByFrFOpeUtil CATFrFOpeZAP* GetCurrentFrFOpeZAP() ;
// Delete current ZAP
ExportedByFrFOpeUtil void DeleteCurrentFrFOpeZAP() ;
// Create ZAP
ExportedByFrFOpeUtil CATFrFOpeZAP* CreateFrFOpeZAP() ;
#endif
