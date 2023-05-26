// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMCurveBreakOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// jul 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveBreakOper_h
#define CATPolyMCurveBreakOper_h

#include "CATPolyMCurveCreateOperators.h"
#include "CATPolyMCurveCreateOper.h"
#include "CATPolyVertexPathUtil.h"
#include "CATBoolean.h"
#include "CATLISTP_CATPolyMCurve.h"
#include "CATListOfInt.h"

class CATPolyMCurve;
class CATIPolyMesh;


/*
Breaks mesh curves at a mesh point if the angle formed by the two segments
sharing the mesh point is greater than the angleTolerance (given in degrees;
defaults to 90 degrees).
*/
class ExportedByCATPolyMCurveCreateOperators CATPolyMCurveBreakOper : public CATPolyMCurveCreateOper
{

public :

  CATPolyMCurveBreakOper (void);

#ifdef USE_NEW_VERTEX_PATH_CODE
  CATPolyMCurveBreakOper (CATIPolyMesh * polyMesh);
#endif

  ~CATPolyMCurveBreakOper (void);

  void SetTolerance (const double angleTolerance);

  HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves,
               CATListPtrCATPolyMCurve & newMeshCurves);

#ifdef USE_NEW_VERTEX_PATH_CODE
  HRESULT RunTest	(const CATListOfVertexPath & vertexPaths,
                   CATListOfVertexPath & newVertexPaths);
#endif

private :

  CATBoolean Break (CATPolyMCurve * meshCurve,
                    CATListPtrCATPolyMCurve & newMeshCurves) const;

  CATBoolean BreakSegment (CATPolyMCurve * meshCurve,
                           const int index0,
                           const int index1,
                           const int index2) const;

#ifdef USE_NEW_VERTEX_PATH_CODE
	CATBoolean BreakTest (CATListOfInt * vertexPath,
                        CATListOfVertexPath & newVertexPaths) const;

	CATBoolean BreakSegmentTest (CATListOfInt * vertexPath,
                               const int index0,
                               const int index1,
                               const int index2) const;
#endif

  CATListPtrCATPolyMCurve _meshCurves;
  double _angleTolerance;

};

#endif
