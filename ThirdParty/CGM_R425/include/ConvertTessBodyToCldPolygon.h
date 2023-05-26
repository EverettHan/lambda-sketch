// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// ConvertTessBodyToCldPolygon
//
//===================================================================
//
// Dec 2019 Creation: LVL
//===================================================================
#ifndef ConvertTessBodyToCldPolygon_h
#define ConvertTessBodyToCldPolygon_h

#include "TessPolygon.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"
#include "CATMapOfCellToMapOfInt.h"
#include "ListPOfCATEdge.h"
#include "CATMapOfEdgeToPolySurfaceVertexLine.h"
#include "CATMapOfVertexToPolySurfaceVertex.h"

#include "CATCGMSTDSafeIncludeStart.h"
#include <map>
#include "CATCGMSTDSafeIncludeEnd.h"
class CATFace;
class CATCldPolygon;
class CATPGMTessBody;
class CATIPolyMesh;
class CATPolyCell;
class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexUVConstLayer;
class CATIPolySurfaceVertexNormalConstLayer;


class ExportedByTessPolygon ConvertTessBodyToCldPolygon
{
public:
	ConvertTessBodyToCldPolygon(CATPGMTessBody * iTessBody, CATCldPolygon * ioCldPolygon, CATLONG32 iTriangleInfo, CATLONG32 iVertexInfo);
	~ConvertTessBodyToCldPolygon();

	int Run();

	int TessellateFaces2();

	HRESULT StoreFace(CATFace * iFace, CATIPolySurface * iPolyFace, int iSide, CATIPolyMesh * iMesh, CATIPolySurfaceVertexPositionConstLayer * iXYZs, CATIPolySurfaceVertexUVConstLayer * iUVs, CATIPolySurfaceVertexNormalConstLayer * iNormals, CATMapOfIntToInt * iDejaMis);

  CATBoolean CheckMeshCoords(CATCldPolygon * ioCldPolygon);

  CATBoolean CheckPointEdgeVsCld(CATCldPolygon * ioCldPolygon, int iNumPoint, CATEdge * iEdge, double iParam);

public:

	CATPGMTessBody * _TessBody;
	CATCldPolygon * _PolygonResult;

	ListPOfCATCell *    _Cells;
	CATListOfInt        _Sides;
	CATLONG32			_TriangleInfo;
	CATLONG32			_VertexInfo;
  std::map<CATIPolySurface *, CATMapOfIntToInt *> _MapPolyCellToMapOfInt;
	CATMapOfEdgeToPolySurfaceVertexLine* _EdgeDejaFaite;
	CATMapOfVertexToPolySurfaceVertex* _VertexDejaFait;
};

#endif
