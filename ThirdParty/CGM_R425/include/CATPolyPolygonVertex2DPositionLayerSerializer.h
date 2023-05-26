// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonVertex2DPositionLayerSerializer.h
//
//===================================================================
// September 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonVertex2DPositionLayerSerializer_H
#define CATPolyPolygonVertex2DPositionLayerSerializer_H

#include "PolygonalSerializers.h"
#include "CATErrorDef.h"

class CATPolyVertex2D;
class CATPolyLoop2D;
class CATPolyPolygon2D;
class CATPolyPolygonVertex2DPositionLayer;
class CATPolyVertexIter2D;


/**
Class fetching the coordinates of the vertices of a CATPolyPolygon2D and copying them into
a buffer of coordinates in series.  The vertex buffer must be allocated by the caller.
It must be large enough to contain all the coordinates.
*/
class ExportedByPolygonalSerializers CATPolyPolygonVertex2DPositionLayerSerializer
{

public :

  CATPolyPolygonVertex2DPositionLayerSerializer () {}
  ~CATPolyPolygonVertex2DPositionLayerSerializer () {}

public:

/** @name Double Serializers
    @{ */

  /**
   * Serializes into a buffer of double the 2D coordinates of a CATPolyPolygon2D.
   * @param iPolygon
   *   The input polygon.
   * @param iVertexPositionBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the polygon:
   *   2 x CATPolyPolygon2D::GetNbVertices ().
   */
  HRESULT Serialize (const CATPolyPolygon2D& iPolygon, double* iVertexPositionBuffer);

  /**
   * Serializes into a buffer of double the 2D coordinates of a CATPolyPolygon2D.
   * @param iVertexPositionLayer
   *   The input vertex position layer.
   *   @see CATPolyPolygonVertex2DPositionLayerImpl
   * @param iVertexIterator
   *   An iterator through all the vertices of the polygon.
   * @param iVertexPositionBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the polygon:
   *   at least 2 x CATPolyPolygon2D::GetNbVertices ().
   */
  HRESULT Serialize (const CATPolyPolygonVertex2DPositionLayer& iVertexPositionLayer,
                     CATPolyVertexIter2D& iVertexIterator,
                     double* iVertexPositionBuffer);

  /**
   * Serializes into a buffer of double the 2D coordinates of a loop from a CATPolyPolygon2D.
   * @param iVertexPositionLayer
   *   The input vertex position layer.
   *   @see CATPolyPolygonVertex2DPositionLayerImpl
   * @param iLoop
   *   A loop from a face of the CATPolyPolygon2D.
   * @param iCoordinateBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the loop:
   *   at least 2 x CATPolyGetNbVertices (iLoop).
   *  @see CATPolyPolygonServices2D.h
   * @param oNbVertices
   *  The number of vertices written into the buffer (two coordinates per vertex.)
   */
  HRESULT Serialize (const CATPolyPolygonVertex2DPositionLayer& iVertexPositionLayer,
                     const CATPolyLoop2D& iLoop,
                     double* iCoordinateBuffer, unsigned int& oNbVertices);

/** @} */

public:

/** @name Float Serializers
    @{ */

  /**
   * Serializes into a buffer of float the 2D coordinates of a CATPolyPolygon2D.
   * @param iPolygon
   *   The input polygon.
   * @param iVertexPositionBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the polygon:
   *   at least 2 x CATPolyPolygon2D::GetNbVertices ().
   */
  HRESULT Serialize (const CATPolyPolygon2D& iPolygon, float* iVertexPositionBuffer);

  /**
   * Serializes into a buffer of float the 2D coordinates of a CATPolyPolygon2D.
   * @param iVertexPositionLayer
   *   The input vertex position layer.
   * @param iVertexIterator
   *   An iterator through all the vertices of the polygon.
   * @param iVertexPositionBuffer
   *   An input buffer large enough to contain all the 2D coordinates of the polygon:
   *   at least 2 x CATPolyPolygon2D::GetNbVertices ().
   */
  HRESULT Serialize (const CATPolyPolygonVertex2DPositionLayer& iVertexPositionLayer,
                     CATPolyVertexIter2D& iVertexIterator,
                     float* iVertexPositionBuffer);

/** @} */

};

#endif
