// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonVertex3DPositionLayerSerializer.h
//
//===================================================================
// September 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonVertex3DPositionLayerSerializer_H
#define CATPolyPolygonVertex3DPositionLayerSerializer_H

#include "PolygonalSerializers.h"
#include "CATErrorDef.h"

class CATPolyVertex2D;
class CATPolyLoop2D;
class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyVertexIter2D;


/**
Class fetching the coordinates of the vertices from the 3D vertex position layer of a CATPolyPolygon2D and 
* copying them into a buffer of coordinates in series.  The vertex buffer must be allocated by the caller.
It must be large enough to contain all the coordinates.
*/
class ExportedByPolygonalSerializers CATPolyPolygonVertex3DPositionLayerSerializer
{

public :

  CATPolyPolygonVertex3DPositionLayerSerializer () {}
  ~CATPolyPolygonVertex3DPositionLayerSerializer () {}

public:

/** @name Double Serializers
    @{ */

  /**
   * Serializes into a buffer of double the 3D coordinates from a vertex position layer of a CATPolyPolygon2D.
   * @param iVertexPositionLayer
   *   The input vertex position layer.
   *   @see CATPolyPolygonVertex3DPositionLayerImpl
   * @param iVertexIterator
   *   An iterator through all the vertices of the polygon.
   * @param iVertexPositionBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the polygon:
   *   at least 3 x CATPolyPolygon2D::GetNbVertices ().
   */
  HRESULT Serialize (const CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
                     CATPolyVertexIter2D& iVertexIterator,
                     double* iVertexPositionBuffer);

  /**
   * Serializes into a buffer of double the 3D coordinates from a vertex position layer of a CATPolyPolygon2D
   * for a loop.
   * @param iVertexPositionLayer
   *   The input vertex position layer.
   *   @see CATPolyPolygonVertex3DPositionLayerImpl
   * @param iLoop
   *   A loop from a face of the CATPolyPolygon2D.
   * @param iCoordinateBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the loop:
   *   at least 3 x CATPolyGetNbVertices (iLoop).
   *  @see CATPolyPolygonServices2D.h
   * @param oNbVertices
   *  The number of vertices written into the buffer (three coordinates per vertex.)
   */
  HRESULT Serialize (const CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
                     const CATPolyLoop2D& iLoop,
                     double* iCoordinateBuffer, unsigned int& oNbVertices);

/** @} */

public:

/** @name Float Serializers
    @{ */

  /**
   * Serializes into a buffer of float the 2D coordinates of a CATPolyPolygon2D.
   * The third coordinate of the points in the buffer is set to 0.
   * @param iPolygon
   *   The input polygon.
   * @param iVertexPositionBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the polygon:
   *   at least 3 x CATPolyPolygon2D::GetNbVertices ().
   */
  HRESULT Serialize (const CATPolyPolygon2D& iPolygon, float* iVertexPositionBuffer);

  /**
   * Serializes into a buffer of float the 3D coordinates of a CATPolyPolygon2D.
   * @param iVertexPositionLayer
   *   The input vertex position layer.
   * @param iVertexIterator
   *   An iterator through all the vertices of the polygon.
   * @param iVertexPositionBuffer
   *   An input buffer large enough to contain all the 3D coordinates from the layer of the polygon:
   *   at least 3 x CATPolyPolygon2D::GetNbVertices ().
   */
  HRESULT Serialize (const CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
                     CATPolyVertexIter2D& iVertexIterator,
                     float* iVertexPositionBuffer);

/** @} */

};

#endif
