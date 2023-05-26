// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// ConvertTessBodyToPolyMesh
//
//===================================================================
//
// Dec 2020 Creation: H7W
//===================================================================
#ifndef ConvertTessBodyToPolyMesh_h
#define ConvertTessBodyToPolyMesh_h

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
class CATPGMTessBody;
class CATIPolyMesh;
class CATPolyCell;
class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexUVConstLayer;
class CATIPolySurfaceVertexNormalConstLayer;
class CATTessPolyMeshTriangleAttributeLayer;
class CATTessPolyMeshVertexAttributeLayer;


class ExportedByTessPolygon ConvertTessBodyToPolyMesh
{
public:
	ConvertTessBodyToPolyMesh(CATPGMTessBody * iTessBody, CATIPolyMesh & ioMesh, CATLONG32 iVertexInfo,
                            CATTessPolyMeshTriangleAttributeLayer *oTriangleAttr, CATTessPolyMeshVertexAttributeLayer *oVertexAttr);
	~ConvertTessBodyToPolyMesh();

	int Run();

	int TessellateFaces2();

	HRESULT StoreFace(CATFace * iFace, CATIPolySurface * iPolyFace, int iSide, CATIPolyMesh * iMesh, CATIPolySurfaceVertexPositionConstLayer * iXYZs, CATIPolySurfaceVertexUVConstLayer * iUVs, CATIPolySurfaceVertexNormalConstLayer * iNormals, CATMapOfIntToInt * iDejaMis);

  CATBoolean CheckMeshCoords(CATIPolyMesh * ioMesh);

  CATBoolean CheckPointEdgeVsCld(CATIPolyMesh * ioMesh, int iNumPoint, CATEdge * iEdge, double iParam);

public:

	CATPGMTessBody * _TessBody;
  CATIPolyMesh & _PolyMeshResult;

	ListPOfCATCell *    _Cells;
	CATListOfInt        _Sides;

	CATLONG32			_VertexInfo;
  CATTessPolyMeshTriangleAttributeLayer *_oTriangleAttr;
  CATTessPolyMeshVertexAttributeLayer *_oVertexAttr;
  std::map<CATIPolySurface *,CATMapOfIntToInt *> _MapPolyCellToMapOfInt;
	CATMapOfEdgeToPolySurfaceVertexLine* _EdgeDejaFaite;
	CATMapOfVertexToPolySurfaceVertex* _VertexDejaFait;
};

#endif
