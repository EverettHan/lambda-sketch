// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonToMeshOper2D.h
//
//===================================================================
//
// April 2006 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonToMeshOper2D_H
#define CATPolyPolygonToMeshOper2D_H

#include "CATPolyMiscellaneous.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATIPolyMesh;
class CATPolyExactArithmetic;
class CATMapOfPtrToInt;


/**
 This operator creates a mesh from a polygon.
*/
class ExportedByCATPolyMiscellaneous CATPolyPolygonToMeshOper2D
{

public:

  CATPolyPolygonToMeshOper2D (const CATPolyExactArithmetic& iExactArithmetic);
  ~CATPolyPolygonToMeshOper2D () {}

public:

  /** 
   * Creates a mesh in the (O, x, y) plane from the polygon data.
   * If the polygon data are not triangular, then the polygon is triangulated.
   */
  HRESULT Run (CATPolyPolygon2D& iPolygon, CATIPolyMesh& oMesh, CATMapOfPtrToInt* ioMapPolygonVertexToMeshVertex = 0);

  /**
   * Creates a mesh from the polygon data and the layer of vertex 3D positions (optional).
   */
  HRESULT Run (CATPolyPolygon2D& iPolygon, const CATPolyPolygonVertex3DPositionLayer* iPositions,
               CATIPolyMesh& oMesh, CATMapOfPtrToInt* ioMapPolygonVertexToMeshVertex = 0);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;

};

#endif
