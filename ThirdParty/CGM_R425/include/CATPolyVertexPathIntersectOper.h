// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexPathIntersectOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyVertexPathIntersectOper_h
#define CATPolyVertexPathIntersectOper_h

#include "CATPolyMCurveCreateOperators.h"
#include "CATPolyMCurveCreateOper.h"
#include "CATLISTP_CATPolyMCurve.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"

#include "CATPolyVertexPathUtil.h"

#ifdef USE_NEW_VERTEX_PATH_CODE
// Use of Vertex Path in CATPolyHealOper
#include "CATHTableOfVertexPath.h"
#endif

class CATIPolyMesh;
class CATPolyMCurve;
class CATHTableOfIntToPtr;


/**
* This operator is used to intersect and break vertex paths. It's
* assumed that the mesh curves are all vertex paths. It's additionally
* assumed that if two vertex paths intersect somewhere different than
* their endpoints, then the intersection must be at a vertex.
*
* This operator creates new mesh curves which must be released by the caller.
*/
class ExportedByCATPolyMCurveCreateOperators CATPolyVertexPathIntersectOper : public CATPolyMCurveCreateOper
{

public :

  CATPolyVertexPathIntersectOper (CATIPolyMesh * polyMesh);
  ~CATPolyVertexPathIntersectOper (void);

  HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves,
               CATListPtrCATPolyMCurve & newMeshCurves);

#ifdef USE_NEW_VERTEX_PATH_CODE
	HRESULT RunTest (const CATListOfVertexPath & vertexPaths,
                   CATListOfVertexPath & newVertexPaths);
#endif

private :

  CATBoolean CheckMeshCurves (void) const;

  void ClearVertexInfo (void);

  void BuildVertexInfo (void);

  void PrintVertexInfo (void);

  CATBoolean BuildBreakPoints (CATListOfInt * breakPoints) const;

  CATBoolean BreakMeshCurve (CATPolyMCurve * meshCurve,
    const CATListOfInt & breakPoints,
    CATListPtrCATPolyMCurve & meshCurves) const;

  CATBoolean BreakMeshCurves (CATListOfInt * breakPoints,
    CATListPtrCATPolyMCurve & meshCurves) const;

  CATListOfInt _vertices;

  CATListPtrCATPolyMCurve _meshCurves;

  CATHTableOfIntToPtr * _vertexCurvesMap;
  CATHTableOfIntToPtr * _vertexIndicesMap;

  int _numVertices;

#ifdef USE_NEW_VERTEX_PATH_CODE
	CATListOfVertexPath _vertexPaths;
	void BuildVertexInfoTest (void);
	CATBoolean BuildBreakPointsTest (CATListOfInt * breakPoints) const;
	CATBoolean BreakVertexPaths (CATListOfInt * breakPoints, CATListOfVertexPath & vertexPaths) const;
#endif

};

#endif
