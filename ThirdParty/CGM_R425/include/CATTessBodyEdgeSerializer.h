// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyEdgeSerializer.h
//
//===================================================================
// September 2010 Creation: ndo
//===================================================================
#ifndef CATTessBodyEdgeSerializer_H
#define CATTessBodyEdgeSerializer_H

#include "TessBodyAdapters.h"
#include "CATCGMTessBodyEdgeSerializer.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATCGMTessBody;
class CATEdge;
class CATIPolyCurve;
class CATIPolyCurveVertexIterator;
class CATCGMTessellateID;
class CATTessDataCache;


/**
Serializes the tessellation data into compact arrays of floats, doubles and integers.  
The buffers must be allocated before calls to the serialize methods and their sizes should be sufficiently large to 
contain the data.
 */
class ExportedByTessBodyAdapters CATTessBodyEdgeSerializer : public CATCGMTessBodyEdgeSerializer
{

public:

  /**
   * Constructs the serializer for the tessellation of a CATEdge within its CATBody context.
   */
  CATTessBodyEdgeSerializer (CATCGMTessBody& iTessBody, CATEdge& iEdge);

  ~CATTessBodyEdgeSerializer ();

public:

  /**
   * Returns the tessellation ID associated to the CATEdge.
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
   * Returns the tessellation ID associated to the CATEdge.
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
   * Returns the number of vertices to be serialized.
   */
  int GetNbVertices () const;

  /**
   * Returns the required size of the buffer for serialization of the vertex position layer.
   */
  int GetSizeOfVertexPositionBuffer () const;

  /**
   * Returns the required size of the buffer for serialization of the vertex W (parameter) layer.
   * The method may return 0 if no W layer is available.
   */
  int GetSizeOfVertexWBuffer () const;

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

  /**
   * Serializes the vertex W layer into a float buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexWBuffer ().
   */
  HRESULT SerializeVertexWLayer (float* ioVertexWBuffer) const;

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

  /**
   * Serializes the vertex W layer into a double buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexWBuffer ().
   */
  HRESULT SerializeVertexWLayer (double* ioVertexWBuffer) const;

/** @} */

	/**
	* WARNING : only use this with the new implemenation of CATCGMTessBody (that is created with CATCGMTessellateParam)
	* Direct access to the tessellation cache (local mesh) 
	* returns oCellDataCache=NULL if there is delta mesh in the body context
  */
	HRESULT GetCellDataCache (const CATTessDataCache*& oCellDataCache);

private:
	void GetPolyCurve () const;

private:

  CATCGMTessBody& _TessBody;
  CATEdge& _Edge;

  CATIPolyCurve* _PolyCurve;

  CATIPolyCurveVertexIterator* _VertexIterator;

};

/** @file 
 */

/**
 * Creates an instance of CATTessBodyEdgeSerializer for serialization of the tessellation data for a CATEdge.
 *
 * @param iTessBody
 *   The input CATCGMTessBody.
 * @param iEdge
 *   The input CATEdge whose tessellation data is to be serialized.
 * @return
 *   An instance of a CATTessBodyEdgeSerializer.
 */
ExportedByTessBodyAdapters CATTessBodyEdgeSerializer* CATCreateTessBodyEdgeSerializer (CATCGMTessBody& iTessBody, CATEdge& iEdge);

#endif // !CATTessBodyEdgeSerializer_H
