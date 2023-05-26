// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonServices2D.h
//
//===================================================================
// June 2013 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonServices2D_H
#define CATPolyPolygonServices2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATPolyDeprecatedM.h"

class CATUnicodeString;

class CATPolyExactArithmetic;
class CATPolyPolygon2D;
class CATPolyFace2D;
class CATPolyBar2D;
class CATPolyVertex2D;
class CATPolyLoop2D;
class CATPolyWire2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolySpatialPartition2D;

/** @file
 * Services for CATPolyPolygon2D.
 */

class CATMathBox;
class CATMathBox2D;
class CATMathPoint2D;
class CATMathTransformation;
class CATMathTransformation2D;
class CATMathPlane;
class CATMath2x2Matrix;
class CATMathStream;


namespace Poly
{
  /** @name Elements of CATPolyPolygon2D instances
   *
   * CATPolyPolygonServices2D.h
   * @{ */

  /**
   * Returns the index of a vertex.
   */
  ExportedByPolygonalModel int Index (const CATPolyVertex2D& V);

  /**
   * Returns the index of a bar.
   */
  ExportedByPolygonalModel int Index (const CATPolyBar2D& B);

  /**
   * Returns the index of a face.
   */
  ExportedByPolygonalModel int Index (const CATPolyFace2D& F);

  /**
   * Returns the position of a vertex.
   */
  ExportedByPolygonalModel const CATMathPoint2D& Position (const CATPolyVertex2D& V);

  /**
   * Returns the start vertex of the bar.
   */
  ExportedByPolygonalModel CATPolyVertex2D* StartVertex (const CATPolyBar2D& B);

  /**
   * Returns the end vertex of the bar.
   */
  ExportedByPolygonalModel CATPolyVertex2D* EndVertex (const CATPolyBar2D& B);

  /**
   * Returns the left vertex of the bar.
   */
  ExportedByPolygonalModel CATPolyVertex2D* LeftVertex (const CATPolyBar2D& B);

  /**
   * Returns the right vertex of the bar.
   */
  ExportedByPolygonalModel CATPolyVertex2D* RightVertex (const CATPolyBar2D& B);

  /**
   * Returns true if a vertex is full.
   */
  ExportedByPolygonalModel bool IsFullVertex (const CATPolyVertex2D& V);

  /**
   * Returns the face associated to the loop.
   */
  ExportedByPolygonalModel CATPolyFace2D* Face (const CATPolyLoop2D& L);

  /**
   * Returns the valence of the vertex (number of bars around the vertex.)
   */
  ExportedByPolygonalModel unsigned int Valence (const CATPolyVertex2D& V);

  /**
   * Returns the number of cobars, as defined by a pair (vertex, bar), in a CATPolyLoop2D.
   */
  ExportedByPolygonalModel unsigned int GetNbCobars (const CATPolyLoop2D& L);

  /**
   * Returns the number of loops associated to a CATPolyFace2D.
   */
  ExportedByPolygonalModel unsigned int GetNbLoops (const CATPolyFace2D& F);

  /**
   * Returns true if the face is a hole face (not a solid face).
   */
  ExportedByPolygonalModel bool IsHole (const CATPolyFace2D& F);

  /**
   * Returns the adjacent face to a face across a bar.
   */
  ExportedByPolygonalModel CATPolyFace2D* GetAdjacentFace (const CATPolyFace2D& F, const CATPolyBar2D& B);

  /**
   * Returns true if the bar is an arc.
   */
  ExportedByPolygonalModel bool IsArc(const CATPolyBar2D& B);

  /**
   * Retrive the third point of an arc.
   */
  ExportedByPolygonalModel HRESULT GetArcThirdPoint(const CATPolyBar2D& B, CATMathPoint2D &oPoint, bool &oThrough);

  /** @} */

};


namespace Poly
{
  /** @name Spatial Partition
   *
   * CATPolyPolygonServices2D.h
   * @{ */

   /**
    * Constructs a new spatial partition for a polygon.
    * @param iNbPixelsNotToExceedXorY
    *   Number of pixels not to exceed along the X or Y direction.  
    * @return 
    *   The returned instance must be deleted.
    */
  ExportedByPolygonalModel CATPolySpatialPartition2D* NewSpatialPartition (const CATPolyPolygon2D& iPolygon, unsigned int iNbPixelsNotToExceedXorY, 
                                                                           double iOffset = 0);

  ExportedByPolygonalModel CATPolySpatialPartition2D* NewSpatialPartition (const CATPolyPolygon2D& iPolygon, double iOffset);


  /** @} */

};


/** @name Orientation
    @{ */

/**
  * Checks whether the sequence of points turns in the counter-clockwise direction or in the
  * clockwise direction. The first and last points in the sequence do not need to be the same;
  * a segment is automatically added between the last and first point to close the loop.
  * There can be points (including consecutive points) with identical coordinates in the sequence.
  * If the loop is self-intersecting, the result is meaningless.
  * @param iExactArithmetic
  *   An instance of exact arithmetic.
  * @param iPoints
  *   The sequence of points.
  * @param nbPoints
  *   The number of points in the sequence.
  * @return
  *   -1: The points are turning in the CW direction.
  *    0: The direction is undetermined.
  *   +1: The points are turning in the CCW direction.
  */
ExportedByPolygonalModel int CATPolyArePointsTurningCCW (const CATPolyExactArithmetic& iExactArithmetic,
                                                         const CATMathPoint2D iPoints[], unsigned int nbPoints);

/**
 * Switches the orientation of a CATPolyPolygon2D instance.
 * This method modifies the CATPolyPolygon2D instance.
 * CCW loops become CW loops and vice-versa.
 *
 * @param iPolygon
 *   The input CATPolyPolygon2D.
 * @return
 *   <tt>S_OK</tt> when the orientation has been switched.
 *   <tt>E_FAIL</tt> if an error occurs.
 */
ExportedByPolygonalModel HRESULT CATPolySwitchOrientation (CATPolyPolygon2D& ioPolygon);

/** @} */

namespace Poly
{
  /** @name Measures
      @{ */

      /**
       * Computes the area of all solid faces from a CATPolyPolygon2D instance.
       * @param iPolygon
       *   The input CATPolyPolygon2D.
       * @param oArea
       *   The output area of the solid faces.
       */
  ExportedByPolygonalModel double GetArea(const CATPolyPolygon2D& iPolygon);
  inline void GetArea(const CATPolyPolygon2D& iPolygon, double& oArea) { oArea = GetArea(iPolygon); }

  /**
   * Computes the area of a face from a CATPolyPolygon2D instance.
   * @param iFace
   *   The input CATPolyFace2D.
   * @param oArea
   *   The output area of the face.
   */
  ExportedByPolygonalModel double GetArea(const CATPolyFace2D& iFace);
  inline void GetArea(const CATPolyFace2D& iFace, double& oArea) { oArea = GetArea(iFace); }

  /**
   * Computes the area of a loop from a CATPolyPolygon2D instance
   * @param iLoop
   *  The input CATPolyLoop2D
   * param oArea
   *  The output area of the loop;
   */
  ExportedByPolygonalModel double GetArea(const CATPolyLoop2D& iLoop);
  inline void GetArea(const CATPolyLoop2D& iLoop, double& oArea) { oArea = GetArea(iLoop); }

  /**
   * Computes the length of a loop from a CATPolyPolygon2D instance
   * @param iLoop
   *  The input CATPolyLoop2D
   */
  ExportedByPolygonalModel double GetLength(const CATPolyLoop2D& iLoop);

  /**
   * Computes the center of inertia of a CATPolyPolygon2D instance.
   * @param iPolygon
   *   The input CATPolyPolygon2D.
   * @param oCOI
   *   The output position of the center of inertia.
   * @param oArea
   *   Optionally, the area of the solid faces of the input polygon.
   */
  ExportedByPolygonalModel void GetCenterOfInertia(const CATPolyPolygon2D& iPolygon, CATMathPoint2D& oCOI, double* oArea = NULL);

  /**
   * Computes the center of inertia of a loop from a CATPolyPolygon2D instance.
   * @param iLoop
   *   The input CATPolyLoop2D.
   * @param oCOI
   *   The output position of the center of inertia.
   * @param oArea
   *   Optionally, the area of the solid faces of the input loop.
   */
  ExportedByPolygonalModel void GetCenterOfInertia(const CATPolyLoop2D& iLoop, CATMathPoint2D& oCOI, double* oArea = NULL);

  /**
   * Computes the moment of inertia of a CATPolyPolygon2D instance
   * relatively to an arbitrary origin. For convenience in some
   * application, this can be the center of inertia. See
   * @CATPolyGetCenterOfInertia to obtain it.
   * @param iPolygon
   *   The input CATPolyPolygon2D.
   * @param oInertiaMatrix
   *   The 2x2 inertia matrix of the polygon.
   * @param iOrigin
   *   Optionally, the origin relatively to which the inertia matrix is
   *   computed. By default, the global origin (0, 0) is used.
   */
  ExportedByPolygonalModel void GetMomentOfInertia(const CATPolyPolygon2D& iPolygon, CATMath2x2Matrix& oInertiaMatrix, const CATMathPoint2D* iOrigin = NULL);

  /**
   * Computes and returns a 2D bounding box of the CATPolyPolygon2D instance.
   * @param iPolygon
   *   The input CATPolyPolygon2D.
   * @param ioBox
   *   The 2D bounding box computed from the input data.
   * @param iPosMatrix
   *   An optional transformation applied to the points for the sake of the bounding box computation.
   * @return
   *   S_OK for a successful call
   *   S_FALSE if the bounding box has not been set.
   *   E_FAIL if an error occurs during the computation.
   */
  ExportedByPolygonalModel HRESULT ComputeBoundingBox (const CATPolyPolygon2D& iPolygon,
    CATMathBox2D& ioBox,
    const CATMathTransformation2D* iPosMatrix = 0);

  /**
    * Computes the bounding box of a CATPolyPolygon2D face.
    * @param iiPolygon
    *   The input CATPolyPolygon2D.
    * @param iFace
    *   The input CATPolyFace2D.
    * @param ioBox
    *   The 2D bounding box computed from the input data.
    * @return
    *   S_OK for a successful call
    *   S_FALSE if the bounding box has not been set.
    *   E_FAIL if an error occurs during the computation.
  */
  ExportedByPolygonalModel HRESULT ComputeBoundingBox (const CATPolyPolygon2D& iPolygon, const CATPolyFace2D& iFace, CATMathBox2D& ioBox);

  /**
   * Computes and returns a 3D bounding box of the CATPolyPolygon2D instance.
   * @param iPolygon
   *   The input CATPolyPolygon2D.
   * @param iPositionLayer
   *   An optional layer of 3D positions for the vertices of the polygon.
   *   If no layer if provided, then the 3D coordinates of the points are set to the 2D positions of the
   *   polygon vertices for x and y and 0 for z.
   * @param ioBox
   *   The 3D bounding box computed from the input data.
   * @param iPosMatrix
   *   An optional transformation applied to the points for the sake of the bounding box computation.
   * @return
   *   S_OK for a successful call
   *   S_FALSE if the bounding box has not been set.
   *   E_FAIL if an error occurs during the computation.
   */
  ExportedByPolygonalModel HRESULT ComputeBoundingBox (const CATPolyPolygon2D& iPolygon,
    const CATPolyPolygonVertex3DPositionLayer* iPositionLayer,
    CATMathBox& ioBox,
    const CATMathTransformation* iPosMatrix = 0);

  /** @} */
}

/** @name Other Services
    @{ */

/**
 * Checks if a bar is part of a boundary.
 * A boundary bar separates a solid face from a hole face.
 */
ExportedByPolygonalModel CATBoolean CATPolyIsBoundaryBar (const CATPolyBar2D& iBar);


/** Projects a polygon with a 3D position layer in a plane, such that
 *  all 2D vertices are the projection onto the given CATMathPlane of
 *  its corresponding 3D points in the layer.
 *@param ioPolygon: the polygon we'd like to project.
 *@param iPositionLayer: the layer assigning a 3D point to each vertex
 *of the polygon.
 *@param iPlane: the plane onto which one'd like to project the
 *polygon.
 */
//ExportedByPolygonalModel HRESULT CATPolyPolygonProject (CATPolyPolygon2D & ioPolygon, const CATPolyPolygonVertex3DPositionLayer * iPositionLayer, const CATMathPlane & iPlane);
//ExportedByPolygonalModel HRESULT CATPolyProjectPolygon (CATPolyPolygon2D & ioPolygon, const CATPolyPolygonVertex3DPositionLayer * iPositionLayer, const CATMathPlane & iPlane);


/**
 * Given the face and a bar of a CATPolyPolygon2D, returns the closest vertex from
 * this face to the bar.  The distance between the two elements gives a measure of the separation
 * of the returned vertex to the bar.
 * @param iFace
 *   The input face.
 * @param iBar
 *   The input bar.
 * @param oClosestVertex
 *   The output vertex from the face which is the closest to the input bar.
 * @param oBarVertex
 *   The start or end vertex of the bar if the shortest distance to the closest vertex is realized
 *   by this entity.  Will be null if the projection is a different point on the bar.
 * @return
 *   The square of the distance between the input bar and the closest face vertex.
 */
ExportedByPolygonalModel double CATPolyFindClosestVertex (const CATPolyFace2D& iFace, const CATPolyBar2D& iBar, CATPolyVertex2D*& oClosestVertex, CATPolyVertex2D*& oBarVertex);


/**
 * Given the face of a CATPolyPolygon2D, returns the two closest elements from the loops
 * of this face.  The distance between the two elements gives a measure of the separation
 * of the face.  The two closest elements are either a vertex and a bar, or two vertices.
 * @param iFace
 *   The input face.
 * @param oVertex
 *   The output vertex which is the cloest to the second element (bar or vertex).
 * @param oClosestBar
 *   The output bar which is the closest to oVertex.
 *   Will be null if the closest element is a vertex.
 * @param oClosestVertex
 *   The output vertex which is the closest to oVertex.
 *   Will be null if the closest element is a bar.
 * @return
 *   <tt>S_OK</tt> upon a successful findings of the two closest elements.
 *   <tt>E_FAIL</tt> if an error occurs.
 */
ExportedByPolygonalModel HRESULT CATPolyFindClosestEntities (const CATPolyFace2D& iFace, CATPolyVertex2D*& oVertex, CATPolyBar2D*& oClosestBar, CATPolyVertex2D*& oClosestVertex);

/** @} */

namespace Poly
{

/** @name Attributes for Polygon Cells
 * Faces of a CATPolyPolygon2D object can be associated to a generic attribute of type void*.
 *
 * Update of these attributes must be made by an observer.
 * None of the operators and services from PolygonalTools use or update these attributes.
 *
 * CATPolyPolygonServices2D.h
 * @{ */

  /**
   * Sets a vertex attribute.
   */
  ExportedByPolygonalModel void SetAttribute (CATPolyVertex2D& vertex, void* attribute);

  /**
   * Gets a vertex attribute.
   */
  ExportedByPolygonalModel void* GetAttribute (const CATPolyVertex2D& vertex);

  /**
   * Clears all vertex attributes.
   */
  ExportedByPolygonalModel void ClearVertexAttributes (const CATPolyPolygon2D& polygon);

  /**
   * Sets a bar attribute.
   */
  ExportedByPolygonalModel void SetAttribute (CATPolyBar2D& bar, void* attribute);

  /**
   * Gets a bar attribute.
   */
  ExportedByPolygonalModel void* GetAttribute (const CATPolyBar2D& bar);

  /**
   * Clears all bar attributes.
   */
  ExportedByPolygonalModel void ClearBarAttributes (const CATPolyPolygon2D& polygon);

  /**
   * Sets a face attribute.
   */
  ExportedByPolygonalModel void SetAttribute (CATPolyFace2D& face, void* attribute);

  /**
   * Gets a face attribute.
   */
  ExportedByPolygonalModel void* GetAttribute (const CATPolyFace2D& face);

  /**
   * Clears all face attributes.
   */
  ExportedByPolygonalModel void ClearFaceAttributes (const CATPolyPolygon2D& polygon);

  /**
   * Sets a vertex attribute.
   */
  inline void SetAttribute(CATPolyVertex2D* vertex, void* attribute) { if (vertex) SetAttribute(*vertex, attribute); }

  /**
   * Gets a vertex attribute.
   */
  inline void* GetAttribute(const CATPolyVertex2D* vertex) { return vertex ? GetAttribute(*vertex) : 0;  }

  /**
   * Sets a bar attribute.
   */
  inline void SetAttribute(CATPolyBar2D* bar, void* attribute) { if (bar) SetAttribute(*bar, attribute); }

  /**
   * Gets a bar attribute.
   */
  inline void* GetAttribute(const CATPolyBar2D* bar) { return bar ? GetAttribute(*bar) : 0; }

  /**
   * Sets a face attribute.
   */
  inline void SetAttribute(CATPolyFace2D* face, void* attribute) { if (face) SetAttribute(*face, attribute); }

  /**
   * Gets a face attribute.
   */
  inline void* GetAttribute(const CATPolyFace2D* face) { return face ? GetAttribute(*face) : 0; }

/** @} */

};


namespace Poly
{

/** @name Wire Services
 *
 * CATPolyPolygonServices2D.h
 * @{ */

  /**
   * Returns true or false depending if the wire is closed or not.
   */
  ExportedByPolygonalModel bool IsClosed (const CATPolyWire2D* wire);

/** @} */

};

namespace Poly
{

/** @name Topology Services
 *
 * CATPolyPolygonServices2D.h
 * @{ */

  /**
   * Returns the next loop given a loop.
   */
  ExportedByPolygonalModel CATPolyLoop2D* GetNextLoop (CATPolyLoop2D* loop);

/** @} */

};

namespace Poly
{

/** @name Geometry Services
 *
 * CATPolyPolygonServices2D.h
 * @{ */

 /**
  * Returns the outer face of the polygon if it has been defined.
  * @param
  *   The input polygon.
  * @param
  *   The outer face of the polygon.
  * @return
  *   * S_OK if the outer face has been defined.
  *   * S_FALSE if the outer face has not been defined.
  */
  ExportedByPolygonalModel HRESULT GetOuterFace (const CATPolyPolygon2D& polygon, CATPolyFace2D*& oFace);

  /**
   * Returns the outer loop of a face if it has been defined.
   * If the outer loop of the face has been defined, then it is always the first loop of the face.
   * @param
   *   The input face.
   * @param
   *   The outer loop of the face.
   * @return
   *   * S_OK if the outer loop has been defined.
   *   * S_FALSE if the outer loop has not been defined.
   */
  ExportedByPolygonalModel HRESULT GetOuterLoop (CATPolyFace2D const *face, CATPolyLoop2D*& loop);

  /**
   * Returns:
   *   * +1 if the loop is the outer loop of a face;
   *   *  0 if the loop is the inner loop of a face;
   *   * -1 if the state of the loop is unknown.
   */
  ExportedByPolygonalModel int IsOuterLoop (const CATPolyLoop2D* loop);

/** @} */

};


namespace Poly
{
  /** @name Streaming Services
   *
   * CATPolyPolygonServices2D.h
   * @{ */

  /**
   * Streams a CATPolyPolygon2D with an optional position matrix to a file.
   * @param iFileName
   *   The file name where the data are streamed.
   * @param iPolyPolygon
   *   The input CATPolyPolygon2D.
   * @param iPos3DLayer
   *   An optional vertex layer of 3D-positions.
   * @param iPosMatrix
   *   An optional transformation that applies to the 3D-position layer.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> if the entity has been successfully streamed.
   *   <li> <code> S_FALSE </code> if the entity cannot be streamed.
   *   <li> <code> E_FAIL </code> or any other error if an error occurs.
   * </ul>
   */
  ExportedByPolygonalModel HRESULT Stream (const CATUnicodeString& iFileName, const CATPolyPolygon2D& iPolygon, 
                                           const CATPolyPolygonVertex3DPositionLayer* iPos3DLayer = 0, const CATMathTransformation* iPosMatrix = 0);

  /**
   * Streams a CATPolyPolygon2D with an optional 3D-position layer (and associated matrix) to a CATMathStream.
   * @param str
   *   A CATMathStream (typically a CATCGMStream.)
   */
  ExportedByPolygonalModel HRESULT Stream (CATMathStream& str, const CATPolyPolygon2D& iPolygon, 
                                           const CATPolyPolygonVertex3DPositionLayer* iPos3DLayer = 0, const CATMathTransformation* iPosMatrix = 0);

  /**
   * Streams a CATPolyPolygon2D with an optional 3D-position layer (and associated matrix) to a buffer.
   * @param oBuffer
   *   The buffer containing the CATPolyPolygon2D data.  This buffer is allocated by a call to this method.
   *   It must be deleted by the caller.
   * @param oNbBytes
   *   The number of bytes in the buffer.
   */
  ExportedByPolygonalModel HRESULT Stream (char*& oBuffer, size_t& oNbBytes, const CATPolyPolygon2D& iPolygon, 
                                           const CATPolyPolygonVertex3DPositionLayer* iPos3DLayer = 0, const CATMathTransformation* iPosMatrix = 0);

  /**
   * Unstreams a CATPolyPolygon2D with its position matrix (if available) from a file.
   * Both instances must be deleted if different from null.
   * @param iFileName
   *   The name of the file where the data are stored.
   * @param oPolyPolygon
   *   The instance of the CATPolyPolygon unstreamed from the file.
   *   This instance must be deleted.
   * @param oPos3DLayer
   *   An optional vertex layer of 3D-positions.
   *   The instance must be deleted (if different from null.)
   * @param oPosMatrix
   *   An optional transformation associated to the 3D-position layer.
   *   The instance must be deleted (if different from null.)
   * @return
   * <ul>
   *   <li> <code> S_OK </code> if the entity has been successfully unstreamed.
   *   <li> <code> S_FALSE </code> if the entity cannot be unstreamed.
   *   <li> <code> E_FAIL </code> or any other error if an error occurs.
   * </ul>
   */
  ExportedByPolygonalModel HRESULT Unstream (const CATUnicodeString& iFileName, CATPolyPolygon2D*& oPolygon, 
                                             CATPolyPolygonVertex3DPositionLayer*& oPos3DLayer, CATMathTransformation*& oPosMatrix);

  /**
   * Unstreams a CATPolyPolygon2D from a file (ignoring layers if any).
   * The instance must be deleted if different from null.
   */
  ExportedByPolygonalModel HRESULT Unstream (const CATUnicodeString& iFileName, CATPolyPolygon2D*& oPolygon);

  /**
   * Unstreams a CATPolyPolygon2D with its vertex 3D-position layer (if any) from a CATMathStream.
   * Instances must be deleted if different from null.
   * @param str
   *   A CATMathStream (typically a CATCGMStream.)
   */
  ExportedByPolygonalModel HRESULT Unstream (CATMathStream& str, CATPolyPolygon2D*& oPolygon, 
                                             CATPolyPolygonVertex3DPositionLayer*& oPos3DLayer, CATMathTransformation*& oPosMatrix);

  /**
   * Unstreams a CATPolyPolygon2D from a CATMathStream (ignoring layers if any).
   * The instance must be deleted if different from null.
   */
  ExportedByPolygonalModel HRESULT Unstream (CATMathStream& str, CATPolyPolygon2D*& oPolygon);

  /**
   * Unstreams a CATPolyPolygon2D with its vertex 3D-position layer (if any) from a buffer.
   * Instances must be deleted if different from null.
   * @param iBuffer
   *   The buffer containing the CATPolyBody data.
   */
  ExportedByPolygonalModel HRESULT Unstream (const char* iBuffer, const size_t iNbBytes, CATPolyPolygon2D*& oPolygon, 
                                             CATPolyPolygonVertex3DPositionLayer*& oPos3DLayer, CATMathTransformation*& oPosMatrix);

  /**
   * Unstreams a CATPolyPolygon2D from a buffer (ignoring layers if any).
   * The instance must be deleted if different from null.
   */
  ExportedByPolygonalModel HRESULT Unstream (const char* iBuffer, const size_t iNbBytes, CATPolyPolygon2D*& oPolygon);

};

/** @} */

/** @name Copy Services
 *
 * CATPolyPolygonServices2D.h
* @{ */
namespace Poly
{
  ExportedByPolygonalModel HRESULT Duplicate(CATPolyPolygon2D & polygon,
                                             CATPolyPolygon2D *& oClone);
}
/** @} */

#ifndef DOXYGEN_SHOULD_SKIP_THIS

POLY_DEPRECATED ("Use Poly::GetNbCobars (const CATPolyLoop2D&);",
  ExportedByPolygonalModel unsigned int CATPolyGetNbVertices (const CATPolyLoop2D& iLoop););

inline void CATPolyGetArea(const CATPolyPolygon2D& iPolygon, double& oArea)
{
  Poly::GetArea(iPolygon, oArea);
}

inline void CATPolyGetArea(const CATPolyFace2D& iFace, double& oArea)
{
  Poly::GetArea(iFace, oArea);
}

inline void CATPolyGetArea(const CATPolyLoop2D& iLoop, double& oArea)
{
  Poly::GetArea(iLoop, oArea);
}

inline void CATPolyGetCenterOfInertia(const CATPolyPolygon2D& iPolygon, CATMathPoint2D& oCOI, double* oArea = NULL)
{
  Poly::GetCenterOfInertia(iPolygon, oCOI, oArea);
}

inline void CATPolyGetMomentOfInertia(const CATPolyPolygon2D& iPolygon, CATMath2x2Matrix& oInertiaMatrix, const CATMathPoint2D* iOrigin = NULL)
{
  Poly::GetMomentOfInertia(iPolygon, oInertiaMatrix, iOrigin);
}

inline HRESULT CATPolyGetBoundingBox (const CATPolyPolygon2D& iPolygon,
  CATMathBox2D& ioBox,
  const CATMathTransformation2D* iPosMatrix = 0)
{
  return Poly::ComputeBoundingBox (iPolygon, ioBox, iPosMatrix);
}

inline HRESULT CATPolyGetBoundingBox (const CATPolyPolygon2D& iPolygon,
  const CATPolyPolygonVertex3DPositionLayer* iPositionLayer,
  CATMathBox& ioBox,
  const CATMathTransformation* iPosMatrix = 0)
{
  return Poly::ComputeBoundingBox (iPolygon, iPositionLayer, ioBox, iPosMatrix);
}

#endif

#endif
