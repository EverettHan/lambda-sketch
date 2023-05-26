// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshTopoUtils.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// September 2008  Creation: NDO
//===================================================================
#ifndef CATPolyMeshTopoUtils_h
#define CATPolyMeshTopoUtils_h

#include "CATPolyMiscellaneous.h"
#include "CATErrorDef.h"     // HRESULT definition
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATIPolyMesh;


class ExportedByCATPolyMiscellaneous CATPolyMeshTopoUtils 
{

public :

  CATPolyMeshTopoUtils () {}
  ~CATPolyMeshTopoUtils () {}

public:

  /**
   * Generates a unique list of triangles that reference the list of vertices.
   * @param vertices
   *   The relative indices of the vertices.
   * @param triangles
   *   The indices of the triangles.
   * @return
   *   S_OK if successful or E_FAIL otherwise.
   */
  static HRESULT GetTrianglesFromVertices (const CATIPolyMesh& iMesh, const CATListOfInt& iVertices,
                                           CATListOfInt& oTriangles);

  /**
   * Generates a unique list of vertices that reference the list of triangles.
   * @param triangles
   *   The indices of the triangles.
   * @param vertices
   *   The relative indices of the vertices.
   * @return
   *   S_OK if successful or E_FAIL otherwise.
   */
  static HRESULT GetVerticesFromTriangles (const CATIPolyMesh& iMesh, const CATListOfInt& iTriangles,
                                           CATListOfInt& oVertices);

};

#endif

