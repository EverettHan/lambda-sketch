// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonTools2D.h
//
//===================================================================
// August  2004 Creation: ndo
// Dec MNA 2005 Adding of a new signature for GetTriangularFace method.
//===================================================================
#ifndef CATPolyPolygonTools2D_H
#define CATPolyPolygonTools2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATListPV.h"
#include "CATPolyDeprecatedM.h"

class CATPolyPolygon2D;
class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyFace2D;
class CATPolyLoop2D;
class CATPolyCoBar2D;
class CATMathPoint2D;
class CATPolyExactArithmetic;


/**
* Services for CATPolyPolygon2D objects.
*/
class ExportedByPolygonalModel CATPolyPolygonTools2D
{

public :

  /** @name Vertex Services
  @{ */

  /**
  * Returns the index of a vertex.
  */
  static int GetVertexIndex (const CATPolyVertex2D* iVertex);

  /**
  * Returns the position of a vertex.
  */
  static HRESULT GetVertexPosition (const CATPolyVertex2D* iVertex, CATMathPoint2D& oPosition);

  /**
  * Returns the two vertices of a bar.
  * @param iBar
  *   The input bar.
  * @param oVertex0
  *   The start vertex of the bar.
  * @param oVertex1
  *   The end vertex of the bar.
  */
  static HRESULT GetVertices (const CATPolyBar2D* iBar, CATPolyVertex2D*& oVertex0, CATPolyVertex2D*& oVertex1);

  /** @} */

public:

  /** @name Bar Services
  @{ */

  /**
  * Returns the index of a bar.
  */
  static int GetBarIndex (const CATPolyBar2D* iBar);

  /**
  * Returns the bar between two vertices.  
  * If there is more than one bar between the two vertices, then the method returns the first bar it finds.
  * @param iVertex0
  *   The first vertex of the bar.
  * @param
  *   The second vertex of the bar.
  * @return
  *   The bar or <code>null</code> if there is none.
  */
  static CATPolyBar2D* GetBar (const CATPolyVertex2D* iVertex0, const CATPolyVertex2D* iVertex1);

  /**
  * Returns the unique bar referring to a start vertex as seen from a face.
  * If there is more than one bar referring to this start vertex as seen from this face 
  * (case of a non-manifold vertex) then the method returns 0.
  * @param iVertex
  *   The input start vertex of the bar.
  * @param iFace
  *   The input face from where the vertex is seen.
  * @return
  *   The unique bar to which this vertex belongs as seen from the face.
  */
  static CATPolyBar2D* GetUniqueBar (const CATPolyVertex2D* iVertex, const CATPolyFace2D* iFace);

  /**
  * Proceeds to the next bar around the vertex.
  * The vertex must obviously belong to the bar.
  * @param vertex
  *   The input vertex.
  * @param bar
  *   The input and output bar.
  */
  static HRESULT NextBar (const CATPolyVertex2D* vertex, CATPolyBar2D*& bar);

  /**
  * Proceeds to the previous bar around the vertex.
  * The vertex must obviously belong to the bar.
  * @param vertex
  *   The input vertex.
  * @param bar
  *   The input and output bar.
  */
  static HRESULT PreviousBar (const CATPolyVertex2D* vertex, CATPolyBar2D*& bar);

  /** @} */

public:

  /** @name Loop Services
  @{ */

  /**
  * Returns the loop associated to a vertex and a bar.
  * The vertex is the start vertex of the bar in the direction of the loop.
  * @param iVertex
  *   The input start vertex of the bar.
  * @param iFace
  *   The input bar.
  * @return
  *   The output loop.
  */
  static CATPolyLoop2D* GetLoop (const CATPolyVertex2D& iVertex, CATPolyBar2D& iBar);

  /**
  * @deprecated
  * Returns the first loop of a face which is not necessarily the outer loop.
  * @param iFace
  *   The input face
  * @return
  *   The first loop referenced by the face.
  *
  * @see CATPolyPolygonServices2D.h
  * @see Poly::GetOuterLoop
  */
  POLY_DEPRECATED ("Replace by a call to Poly::GetOuterLoop ().", 
                   static CATPolyLoop2D* GetOuterLoop (const CATPolyFace2D* iFace);)

    /**
    * @deprecated
    * @see CATPolyPolygonServices2D.h
    * @see Poly::GetNextLoop
    */
    POLY_DEPRECATED ("Replace by a call to Poly::GetNextLoop ().", 
                     static CATPolyLoop2D* GetNextLoop (const CATPolyLoop2D* iLoop);)

    /**
    * Returns the loop associated to a full vertex.
    * @param iVertex
    *   The input full vertex.
    * @return
    *   The output loop.
    */
    static CATPolyLoop2D* GetLoop (const CATPolyVertex2D* iVertex);

  /**
  * Returns the two loops associated to a bar.
  * Note that the loops on each side of a bar may be the same.
  * @param iBar
  *   The input bar.
  * @param oLoop1
  *   The first output loop.
  * @param oLoop2
  *   The second output loop.
  */
  static HRESULT GetLoops (const CATPolyBar2D* iBar, CATPolyLoop2D*& oLoop1, CATPolyLoop2D*& oLoop2);

  /**
  * Given a vertex and a bar, proceeds to the next vertex and bar along the associated loop.
  * The vertex is the start vertex of the bar in the direction of the loop.
  * @param vertex
  *   The input and output start vertex.
  * @param bar
  *   The input and output bar.
  */
  static HRESULT NextVertexAndBar (CATPolyVertex2D*& vertex, CATPolyBar2D*& bar);

  /**
  * Given a vertex and a bar, proceeds to the previous vertex and bar along the associated loop.
  * The vertex is the start vertex of the bar in the direction of the loop.
  * @param vertex
  *   The input and output start vertex.
  * @param bar
  *   The input and output bar.
  */
  static HRESULT PreviousVertexAndBar (CATPolyVertex2D*& vertex, CATPolyBar2D*& bar);

  /** @} */

public:

  /** @name Face Services
  @{ */

  /**
  * Returns the index of a face.
  */
  static int GetFaceIndex (const CATPolyFace2D* iFace);

  /**
  * Returns the face to which the loop belongs.
  */
  static CATPolyFace2D* GetFace (const CATPolyLoop2D* iLoop) ;

  /**
  * Returns the face on the left (right) side of the bar looking from a vertex for 
  * a CCW polygon (CW polygon, respectively.)
  */
  static CATPolyFace2D* GetFace (const CATPolyVertex2D* V, const CATPolyBar2D* B);

  /** @} */

public:

  /** @name Triangle Face Services
  @{ */

  /**
  * Tests whether a polygon is triangular, that is whether all the faces are triangles with no hole.
  * The polygon may have non-triangular holes.
  * @param iPolygon
  *   The polygon.
  * @return
  *   TRUE if the polygon is triangular.
  *   FALSE otherwise.
  */
  static CATBoolean IsTriangular (CATPolyPolygon2D& iPolygon);

  /**
  * Tests whether a face is triangular, that is whether a face is composed of three vertices without any hole.
  * @param iFace
  *   The face.
  * @return
  *   TRUE if the face is triangular.
  *   FALSE otherwise.
  */
  static CATBoolean IsTriangular (const CATPolyFace2D* iFace);

  /**
  * Returns the three points defining a triangular face.
  * @param iFace
  *   The face of the polygon.
  * @param oVertices
  *   The three vertices of a triangular face.
  * @return
  *   S_OK if the face is a valid triangular face and E_FAIL otherwise.
  */
  static HRESULT GetTriangularFace (const CATPolyFace2D* iFace, CATPolyVertex2D* oVertices[]);

  /**
  * Returns the three points defining a triangular face.
  * @param iFace
  *   The face of the polygon.
  * @param oPoint0
  *   The first point.
  * @param oPoint1
  *   The second point.
  * @param oPoint2
  *   The third point.
  * @return
  *   S_OK if the face is a valid triangular face and E_FAIL otherwise.
  */
  static HRESULT GetTriangularFace (const CATPolyFace2D* iFace,
                                    CATMathPoint2D& oPoint0, CATMathPoint2D& oPoint1, CATMathPoint2D& oPoint2);

  /**
  * Returns the three index of points defining a triangular face.
  * @param iFace
  * The face of the polygon.
  * @param oIdx0
  * The first index.
  * @param oIdx1
  * The second index.
  * @param oIdx2
  * The third index.
  * @return
  * S_OK if the face is a valid triangular face and E_FAIL otherwise.
  */

  static HRESULT GetTriangularFace (const CATPolyFace2D* iFace,
                                    int& oIdx0, int& oIdx1,int& oIdx2);

  /**
  * Flips a bar between two triangular faces of a CATPolyPolygon2D object.
  */
  static HRESULT FlipBar (CATPolyBar2D* iBar);

  /** @} */

public:

  /** @name Other Services
  @{ */

  /**
  * Tests if a point is inside, on or outside a polygon. 
  * 
  * @see CATPolyGeoServices.h
  * @see CATPolyIsInsidePolygon
  */
  static int IsInsidePolygon (const CATMathPoint2D* iPoints, const int nbPoints, 
                              const CATMathPoint2D& iPointToTest, 
                              const CATPolyExactArithmetic* iExactArithmetic,
                              int* oSegment = 0);

  /** 
  * Checks whether the sequence of points turns in the counter-clockwise direction or in the 
  * clockwise direction. The first and last points in the sequence should not be the same; 
  * a segment is automatically added between the last and first point to close the loop.
  * Consecutive points should not be identical.
  * @param iPoints
  *   The sequence of points.
  * @param nbPoints
  *   The number of points in the sequence.
  * @param iExactArithmetic
  *   An exact arithmetic instance.
  * @return
  *   -1: The points are turning in the CW direction.
  *    0: The direction is undetermined.
  *   +1: The points are turning in the CCW direction.
  */
  static int ArePointsTurningCCW (const CATMathPoint2D* iPoints, const int nbPoints,
                                  const CATPolyExactArithmetic* iExactArithmetic);

  /** @} */

public:

  /**
  * @deprecated
  */
  static HRESULT AddLoop (CATPolyPolygon2D& iPolygon, const CATListPV& iVertices, CATPolyLoop2D*& oLoop);

  /**
  * Split a bar by a vertex.
  * @param iSplitBar
  *   The bar that is split.  This bar is modified: its end vertex is replaced by the new vertex.
  * @param iVertex
  *   The (new) vertex that split the bar. 
  * @param iNewBar
  *   The new bar created by this process.  Its start vertex is the new vertex. 
  *   Its end vertex is the end vertex of the split bar.
  * @return
  *   S_OK upon success; E_FAIL otherwise.
  */
  //static HRESULT SplitBar (CATPolyPolygon2D& iPolygon, CATPolyLoop2D& loop,
  //CATPolyBar2D& bar, CATPolyVertex2D& vertex, CATPolyBar2D* barTo = 0,
  //CATPolyBar2D** oNewBar = 0);

  //static HRESULT MergeVertices (CATPolyPolygon2D& iPolygon, CATPolyLoop2D& loop,
  //CATPolyVertex2D& vertexTo, CATPolyVertex2D& vertexFrom);



};

#endif

