// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMCurveHealGroupOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveHealGroupOper_h
#define CATPolyMCurveHealGroupOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyMCurveAnalyzeOper.h"

#include "CATBoolean.h"

#include "CATLISTP_CATPolyMCurve.h"

#include "CATListPV.h"

class CATPolyHealDistanceRecord;
class CATMathBox;

/**
* Assembles mesh curves into groups (of two) that can then be used for
* closing gaps.
*
* The groups are outputted as vertexPathGroups. Those mesh curves that
* weren't placed in a group are outputted as otherMeshCurves.
*/

class ExportedByCATPolyHealOperators CATPolyMCurveHealGroupOper : public CATPolyMCurveAnalyzeOper
{

public :

  CATPolyMCurveHealGroupOper (void);
  ~CATPolyMCurveHealGroupOper (void);

  void SetTolerance (const double tolerance);

  void SetDecomposeFlag (const CATBoolean decomposeFlag);

  void SetCheckLengthFlag (const CATBoolean checkLengthFlag);

  void SetLengthRatio (const double lengthRatio);

  HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves,
    CATListPV & vertexPathGroups,
    CATListPtrCATPolyMCurve & otherMeshCurves);

private :

  CATBoolean CheckMeshCurves (const CATListPtrCATPolyMCurve & meshCurves) const;

  CATBoolean BuildMeshCurveGroups (const CATListPV & distanceRecords,
    const CATListPtrCATPolyMCurve & meshCurves,
    CATListPV & meshCurveGroups,
    CATListPtrCATPolyMCurve & otherMeshCurves);

  CATBoolean GroupMeshCurves (const CATListPtrCATPolyMCurve & meshCurves,
    CATListPV & meshCurveGroups,
    CATListPtrCATPolyMCurve & otherMeshCurves);

  CATPolyHealDistanceRecord * ProcessMeshCurves (CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1,
    CATPolyMCurve * superSampledMeshCurve0,
    CATPolyMCurve * superSampledMeshCurve1,
    const CATMathBox & box);

  void CleanupDistanceRecords (CATListPV & distanceRecords) const;

  double _tolerance;

  CATBoolean _decomposeFlag;

  CATBoolean _checkLengthFlag;

  double _lengthRatio;

};

#endif


