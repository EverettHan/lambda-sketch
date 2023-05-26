// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyTriangulator2D.h
//
//===================================================================
// May 2016  Creation: NDO
//===================================================================
#ifndef CATPolyTriangulator2D_H
#define CATPolyTriangulator2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATMathPoint2D;


/**
 * This operator triangulates any polygon (simple or not simple and multiple-boundary polygons.)
 * If the sides of the input polygon intersect, then the operator will construct the 
 * intersections prior to triangulation.
 */
class ExportedByPolygonalOperators CATPolyTriangulator2D
{

public:

  CATPolyTriangulator2D () {}

public:

  /**
   * Interface defining a vertex iterator through the vertices of the boundaries
   * of the polygon to triangulate.  The vertices are returned in-sequence along
   * each boundary of the polygon. For a multiple-boundary polygon, the vertex iterator 
   * returns a null pointer before cycling through the vertices of the next boundary. 
   * The implementation of this interface must be thread-safe.
   */
  class VertexIterator
  {

  public:

    virtual ~VertexIterator () {}

  public:

    virtual VertexIterator& Begin () = 0;
    virtual CATBoolean End () const = 0;
    virtual VertexIterator& operator++ () = 0;

  public:

    /**
     * Returns the position of the current vertex of the boundary of a polygon.
     * For a multiple-boundary polygon, the iterator returns 0 between the 
     * vertices of different boundaries.
     */
    virtual const CATMathPoint2D* GetVertexPosition () = 0;

  };

public:

  /**
   * Interface defining the polygon to triangulate.
   * The polygon does not need to be a simple polygon;
   * Its sides may intersect in which case the intersections will be constructed
   * prior to the triangulation. 
   * Multiple-boundary polygons are acceptable (polygons with holes.)  
   * For a multiple-boundary polygon, the vertex iterator returns a null pointer 
   * before returning the vertices for the next loop. 
   * The implementation of this interface must be thread-safe.
   */
  class Polygon
  {

  public:

    /**
     * Returns a vertex iterator.
     * The vertex iterator should be deleted after a call to this method.
     * The implementation of this method must be thread-safe.
     */
    virtual VertexIterator* GetVertexIterator () const = 0;

  };

public:

  /**
   * Interface defining the winding rule of the faces to triangulate.
   * All other faces will not be triangulated and be flagged as hole-faces
   * (as opposed to solid-faces.)
   */
  class WindingRule 
  {
  public:

    /**
     * Returns <tt>TRUE</tt> for triangulating a face according to the value of its winding number.
     */
    virtual CATBoolean Triangulate (const int iWindingNumber) = 0;
  };

  /**
   * Returns the default winding rule.
   * The default winding rule returns <tt>TRUE</tt> when the winding number of a face is strictly
   * greater than 0 and <tt>FALSE</tt> otherwise.
   */
  static WindingRule& DefaultWindingRule ();

public:

  /**
   * Interface used for serialization of the triangulation result.
   * 
   */
  class Serializer
  {
  public:

    /**
     * This method is called first with the number of vertices and triangles in the result.
     */
    virtual void Size (unsigned int nbVertices, unsigned int nbTriangles) = 0;

    /**
     * After the call to Size (), this method is called for each vertex
     * with the index of the vertex from 0 to nbVertices - 1 and the 
     * position of the vertex.
     */
    virtual void Vertex (unsigned int v, const CATMathPoint2D& P) = 0;

    /**
     * This method is called for each triangle with the indices of the 
     * three triangle vertices.  The indices range from 0 to nbVertices - 1.
     */
    virtual void Triangle (unsigned int v0, unsigned int v1, unsigned int v2) = 0;

  };

public:

  /**
   * Triangulates a polygon and returns its triangles through a serializer.
   * @param iPolygon
   *   An instance defining the boundaries of the polygon.
   * @param iRule
   *   A custom winding rule specifying the faces to triangulate.
   * @param iSerializer
   *   An interface used to capture or serializes the triangles resulting from
   *   the triangulation.
   * @return
   *   <ul>
   *      <li> <tt>S_OK</tt> for successful triangulation and a non-empty result.
   *      <li> <tt>S_FALSE</tt> for an empty result.
   *      <li> <tt>E_FAIL</tt> if an error occurs.
   *   </ul>
   */
  static HRESULT Triangulate (const Polygon& iPolygon, WindingRule& iRule, Serializer& iSerializer);

};

#endif
