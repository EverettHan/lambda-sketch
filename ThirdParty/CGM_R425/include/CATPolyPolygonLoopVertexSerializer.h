// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonLoopVertexSerializer.h
//
//===================================================================
// September 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonLoopVertexSerializer_H
#define CATPolyPolygonLoopVertexSerializer_H

#include "PolygonalSerializers.h"
#include "CATErrorDef.h"
#include "CATListOfInt.h"

class CATPolyPolygon2D;
class CATPolyLoop2D;
class CATBucketsOfInt;


/**
Class fetching all the vertices of a loop and serializing their index in an array of integers.
The size of the array must be greater or equal than the number of vertices in the loop.
The map of the vertex indices is optional.  A map of the vertex indices to the compact indices
in a contiguous array can be defined by the CATPolyPolygonCompactIndexMapper class.

@see CATPolyPolygonVertex2DPositionLayerSerializer
@see CATPolyPolygonVertex3DPositionLayerSerializer
*/
class ExportedByPolygonalSerializers CATPolyPolygonLoopVertexSerializer
{

public:

  /**
   * Serializes the indices of the loop vertices.
   * @param iPolygon
   *   The polygon containing the loop to serialize.
   *  @param iLoop
   *    The loop to serialize.
   *  @param iIndexMap
   *    An optional map from the vertex indices to other indices (for instance indices in a compact array.)
   *  @param oLoopVertices
   *    A list of integers giving the sequence of vertex indices (or their map) in the loop.
   */
  HRESULT Serialize (const CATPolyPolygon2D& iPolygon,
                     const CATPolyLoop2D& iLoop, 
                     const CATBucketsOfInt* iIndexMap,
                     CATListOfInt& oLoopVertices);

};

#endif
