// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodySerializer.h
//
//===================================================================
// September 2010 Creation: ndo
//===================================================================
#ifndef CATTessBodySerializer_H
#define CATTessBodySerializer_H

#include "TessBodyAdapters.h"
#include "CATCGMTessBodySerializer.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfPtrToPtr.h"


class CATCGMTessBody;
class CATPolyBody;


/**
Serializes the tessellation data, specifically the vertices and the triangles, from a whole CATBody into compact arrays.  
The buffers must be allocated before calls to the serialize methods and their sizes should be sufficiently large to 
contain the data.
 */
class ExportedByTessBodyAdapters CATTessBodySerializer : public CATCGMTessBodySerializer
{

public:

  /**
   * Constructs the serializer for the tessellation of a CATBody.
   */
  CATTessBodySerializer (CATCGMTessBody& iTessBody);

  ~CATTessBodySerializer ();

public:

  /**
   * Returns a reference to the CATBody that is tessellated.
   * @return
   *   The CATBody that is tessellated.
   */
  CATBody& GetBody ();

/** @name Queries about the size of the buffers for serialization.
    @{ */

  /**
   * Returns the number of vertices to be serialized.
   */
  int GetNbVertices () const;

  /**
   * Returns the number of triangles to be serialized.
   */
  int GetNbTriangles () const;

  /**
   * Returns the required size of the buffer for serialization of the vertex position layer.
   */
  int GetSizeOfVertexPositionBuffer () const;

  /**
   * Returns the required size of the buffer for serialization of the triangles.
   * The size of the buffer is equal to 3 * CATIPolySurface::GetNbTriangles ().
   */
  int GetSizeOfTriangleBuffer () const;

/** @} */

public:

/** @name Serialization to float buffers.
    @{ */

  /**
   * Serializes the vertex coordinate layer into a float buffer and the triangle indices.
   *
   * The buffers must be pre-allocated.
   */
  HRESULT Serialize (float* ioVertexPositionBuffer, int* ioTriangleVertices) const;

/** @} */

public:

/** @name Serialization to double buffers
    @{ */

  /**
   * Serializes the vertex coordinate layer into a double buffer and the triangle indices.
   *
   * The buffers must be pre-allocated.
   */
  HRESULT Serialize (double* ioVertexPositionBuffer, int* ioTriangleVertices) const;

/** @} */

private:

  CATCGMTessBody& _TessBody;
  CATPolyBody* _PolyBody;

  int _NbVertices;
  int _NbTriangles;

  CATMapOfPtrToPtr _MapOfVertexMaps;

};

/** @file 
 */

/**
 * Creates an instance of CATTessBodySerializer for serialization of the tessellation data of a whole CATBody.
 *
 * @param iTessBody
 *   The input CATCGMTessBody.
 * @return
 *   An instance of a CATTessBodySerializer.
 */
ExportedByTessBodyAdapters CATTessBodySerializer* CATCreateTessBodySerializer (CATCGMTessBody& iTessBody);

#endif // !CATTessBodySerializer_H
