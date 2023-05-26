#ifndef CATAdvTopoOpeZAP_H
#define CATAdvTopoOpeZAP_H
/**
* @fullReview NLD 05:09:16
*/
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATAdvTopoOpeZAP:
// Utility for code zap and code coverage for AdvancedTopologicalOpe
// Not to be used except for debug and test purpose
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//=============================================================================
// 16 09 05 NLD Creation
//              _CATFrFTopologicalSweepCx2_DumpWireByCCV ;
//              _CATFrFTopologicalSweepCx2_RemoveTwistedSurfaces ;
// 22 09 05 NLD _CATFrFTopologicalSweepCx2_SimuTopCleanError ;
//              _CATFrFTopologicalSweepCx2_InactiveLayDownBackup ;
// 11 10 05 NLD _CATFrFTopologicalSweepCx2_ForceDeformationByCurvesImprovement
//              _CATFrFTopologicalSweepCx2_ForceDeformationByCleanerV2
//              _CATFrFTopologicalSweepCx2_ForceDeformationToC2
// 24 06 06 NLD _CATFrFTopologicalSweepCx2_ForceComputeProfileDeviationWarning
// 02 08 06 NLD _CATFrFTopologicalSweepCx2_ForceMVDAutoBreak
// 19 09 07 NLD _CATFrFWireHomogenizationCx2_ForceValidComputeDefaultOrientations
// 09 02 10 NLD _CATTopBlendCx2_ForceCheckWarningBody
// 24 05 10 NLD _CATFrFTopologicalSweepCx2_AssemblyInLocationList
// 22 01 13 NLD _CATFrFTopologicalSweepCx2_ForceCleanInScale1Factory
// 07 10 14 NLD _CATFrFTopologicalSweepCx2_FillTwistWithSegmentAvailable
// 20 10 14 NLD _CATFrFTopologicalSweepCx2_NoMLKOnFakeCompositeLaw
// 16 05 17 NLD _CATFrFTopologicalSweepCx2_LightDumpOperatorBeforeRun
//=============================================================================
#include <AdvTopoUtil.h>
#include <CATBoolean.h>
class ExportedByAdvTopoUtil CATAdvTopoOpeZAP 
{
 public:
 //-----------------------------------------------------------------------------
 // Constructor 
 //-----------------------------------------------------------------------------
 CATAdvTopoOpeZAP() ;
 //-----------------------------------------------------------------------------
 // Destructor 
 //-----------------------------------------------------------------------------
 ~CATAdvTopoOpeZAP() ;
 //
 CATBoolean _CATFrFTopologicalSweepCx2_DumpWireByCCV ;
 CATBoolean _CATFrFTopologicalSweepCx2_RemoveTwistedSurfaces ;
 CATBoolean _CATFrFTopologicalSweepCx2_SimuTopCleanError ;
 CATBoolean _CATFrFTopologicalSweepCx2_InactiveLayDownBackup ;
 CATBoolean _CATFrFTopologicalSweepCx2_ForceDeformationByCurvesImprovement ;
 CATBoolean _CATFrFTopologicalSweepCx2_ForceDeformationByCleanerV2 ;
 CATBoolean _CATFrFTopologicalSweepCx2_ForceDeformationToC2 ;
 CATBoolean _CATFrFTopologicalSweepCx2_ForceComputeProfileDeviationWarning ;
 CATBoolean _CATFrFTopologicalSweepCx2_ForceMVDAutoBreak ;
 CATBoolean _CATFrFTopologicalSweepCx2_AssemblyInLocationList;
 CATBoolean _CATFrFTopologicalSweepCx2_ForceCleanInScale1Factory;
 CATBoolean _CATFrFTopologicalSweepCx2_FillTwistWithSegmentAvailable;
 CATBoolean _CATFrFTopologicalSweepCx2_NoMLKOnFakeCompositeLaw;
 CATBoolean _CATFrFTopologicalSweepCx2_LightDumpOperatorBeforeRun;
 CATBoolean _CATFrFWireHomogenizationCx2_ForceValidComputeDefaultOrientations ;
 CATBoolean _CATTopBlendCx2_ForceCheckWarningBody ;

};
// Get current ZAP if exists
ExportedByAdvTopoUtil CATAdvTopoOpeZAP* GetCurrentAdvTopoOpeZAP() ;
// Delete current ZAP
ExportedByAdvTopoUtil void DeleteCurrentAdvTopoOpeZAP() ;
// Create ZAP
ExportedByAdvTopoUtil CATAdvTopoOpeZAP* CreateAdvTopoOpeZAP() ;
#endif
