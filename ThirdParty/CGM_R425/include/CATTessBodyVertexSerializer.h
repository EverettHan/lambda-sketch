// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyVertexSerializer.h
//
//===================================================================
// September 2010 Creation: ndo
//===================================================================
#ifndef CATTessBodyVertexSerializer_H
#define CATTessBodyVertexSerializer_H

#include "TessBodyAdapters.h"
#include "CATCGMTessBodyVertexSerializer.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATCGMTessBody;
class CATVertex;
class CATIPolyPoint;
class CATCGMTessellateID;


/**
Serializes the tessellation data into compact arrays of floats and doubles.  
The buffers must be allocated before calls to the serialize methods and their sizes should be sufficiently large to 
contain the data.
 */
class ExportedByTessBodyAdapters CATTessBodyVertexSerializer : public CATCGMTessBodyVertexSerializer
{

public:

  /**
   * Constructs the serializer for the tessellation of a CATVertex within its CATBody context.
   */
  CATTessBodyVertexSerializer (CATCGMTessBody& iTessBody, CATVertex& iVertex);

  ~CATTessBodyVertexSerializer ();

public:

  /**
   * Returns the tessellation ID associated to the CATVertex.
   * @param oTessID
   *   The output CATCGMTessellateID, to be deleted by the caller.
   * @return
   *   <ul>
   *     <li> S_OK if the CATCGMTessellateID has been set.
   *     <li> E_FAIL or any other error when a failure occurs and the CATCGMTessellateID has not been set.
   *   </ul>
   */
  HRESULT GetTessellateID (CATCGMTessellateID* &oTessID);

  /**
   * @nodoc
   * @deprecated
	 *
   * Returns the tessellation ID associated to the CATVertex.
   * @param oTessID
   *   The output CATCGMTessID.
   * @return
   *   <ul>
   *     <li> S_OK if the CATCGMTessID has been set.
   *     <li> E_FAIL or any other error when a failure occurs and the CATCGMTessID has not been set.
   *   </ul>
   */
  HRESULT GetTessID (CATCGMTessID &oTessID);

  /**
   * Returns a reference to the CATBody that is tessellated.
   * @return
   *   The CATBody that is tessellated.
   */
  CATBody& GetBody ();

/** @name Queries about the size of the buffers for serialization.
    @{ */

  /**
   * Returns the required size of the buffer for serialization of the vertex position layer.
   */
  int GetSizeOfVertexPositionBuffer () const;

/** @} */

public:

/** @name Serialization to float buffers.
    @{ */

  /**
   * Serializes the vertex coordinate layer into a float buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexPositionBuffer ().
   */
  HRESULT SerializeVertexPositionLayer (float* ioVertexPositionBuffer) const;

/** @} */

public:

/** @name Serialization to double buffers
    @{ */

  /**
   * Serializes the vertex coordinate layer into a double buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexPositionBuffer ().
   */
  HRESULT SerializeVertexPositionLayer (double* ioVertexPositionBuffer) const;

/** @} */

private:

  CATCGMTessBody& _TessBody;
  CATVertex& _Vertex;

  CATIPolyPoint* _PolyPoint;

};

/** @file 
 */

/**
 * Creates an instance of CATTessBodyVertexSerializer for serialization of the tessellation data for a CATVertex.
 *
 * @param iTessBody
 *   The input CATCGMTessBody.
 * @param iEdge
 *   The input CATVertex whose tessellation data is to be serialized.
 * @return
 *   An instance of a CATTessBodyVertexSerializer.
 */
ExportedByTessBodyAdapters CATTessBodyVertexSerializer* CATCreateTessBodyVertexSerializer (CATCGMTessBody& iTessBody, CATVertex& iVertex);

#endif // !CATTessBodyVertexSerializer_H
