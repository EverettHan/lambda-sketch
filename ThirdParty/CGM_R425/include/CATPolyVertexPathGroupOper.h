// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexPathGroupOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyVertexPathGroupOper_h
#define CATPolyVertexPathGroupOper_h

#include "CATPolyMCurveCreateOperators.h"
#include "CATPolyMCurveCreateOper.h"
#include "CATBoolean.h"
#include "CATLISTP_CATPolyMCurve.h"

#include "CATPolyVertexPathUtil.h"

#ifdef USE_NEW_VERTEX_PATH_CODE
// Use of Vertex Path in CATPolyHealOper
#include "CATPolyBars.h"
#include "CATHTableOfVertexPath.h"
#endif

class CATHTableOfIntToPtr;
class CATHTableOfCATPolyMCurve;


class ExportedByCATPolyMCurveCreateOperators CATPolyVertexPathGroupOper : public CATPolyMCurveCreateOper
{

public :

  CATPolyVertexPathGroupOper (void);
  ~CATPolyVertexPathGroupOper (void);

  HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves,
               CATListPtrCATPolyMCurve & newMeshCurves);

#ifdef USE_NEW_VERTEX_PATH_CODE
	HRESULT RunTest (const CATPolyBars* freeBars, CATListOfVertexPath & vertexPaths);
#endif

private :

  void ClearVertexInfo (void);

  CATBoolean UpdateVertexInfo (const int vertex,
    CATPolyMCurve * meshCurve);

  CATBoolean UpdateVertexInfo (const int vertex,
    CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1);

  CATBoolean BuildVertexInfo (void);

  CATBoolean GroupVertexPaths (void);

  CATHTableOfIntToPtr * _vertexCurvesMap;

  CATHTableOfCATPolyMCurve * _meshCurveHashTable;


#ifdef USE_NEW_VERTEX_PATH_CODE
  // Use Vertex Paths
  CATHTableOfVertexPath * _vertexPathHashTable;

  void ClearVertexInfoTest (void);
  CATBoolean UpdateVertexInfoTest (const int vertex, CATListOfInt * vertexPath);
  CATBoolean UpdateVertexInfoTest (const int vertex, CATListOfInt * vertexPath0, CATListOfInt * vertexPath1);
  CATBoolean BuildVertexInfoTest (void);
  CATBoolean GroupVertexPathsTest (void);
#endif

};

#endif
