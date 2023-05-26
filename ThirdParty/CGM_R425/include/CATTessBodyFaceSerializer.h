// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyFaceSerializer.h
//
//===================================================================
// September 2010 Creation: ndo
//===================================================================
#ifndef CATTessBodyFaceSerializer_H
#define CATTessBodyFaceSerializer_H

#include "TessBodyAdapters.h"
#include "CATCGMTessBodyFaceSerializer.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfEdgeToPolySurfaceVertexLine.h"
#include "CATMapOfVertexToPolySurfaceVertex.h"

class CATCGMTessBody;
class CATFace;
class CATEdge;
class CATIPolySurface;
class CATIPolySurfaceVertexIterator;
class CATPolySurfaceCompactVertexIndexMapper;
class CATCGMTessellateID;
class CATTessDataCache;


/**
Serializes the tessellation data into compact arrays of floats, doubles and integers.  
The buffers must be allocated before calls to the serialize methods and their sizes should be sufficiently large to 
contain the data.
 */
class ExportedByTessBodyAdapters CATTessBodyFaceSerializer : public CATCGMTessBodyFaceSerializer
{

public:

  /**
   * Constructs the serializer for the tessellation of a CATFace within its CATBody context.
   */
  CATTessBodyFaceSerializer (CATCGMTessBody& iTessBody, CATFace& iFace);

  ~CATTessBodyFaceSerializer ();

public:

  /**
   * Returns the tessellation ID associated to the CATFace.
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
   * Returns the tessellation ID associated to the CATFace.
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

  /**
   * Sets a parameter to include the facet size (3 for a CATIPolyMesh) during the serialization of the triangles.
   *
   * When this flag is set to <tt>TRUE</tt>, the triangles are serialized as follows: 
   * <br>
   * <tt>3 t0v0 t0v1 t0v2 3 t1v0 t1v1 t1v2 ... 3 tnv0 tnv1 tnv2</tt>.
   * <br>
   * Otherwise, the triangles are serialized as follows:
   * <br>
   * <tt>t0v0 t0v1 t0v2 t1v0 t1v1 t1v2 ... tnv0 tnv1 tnv2</tt>.
   * <br>
   * By default this flag is set to <tt>FALSE</tt>.
   */
  inline void DoIncludePolygonSize (CATBoolean iDoIncludeFacetSize);

public:

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
   * Returns the required size of the buffer for serialization of the vertex normal layer.
   * The method may return 0 if no normal layer is available.
   */
  int GetSizeOfVertexNormalBuffer () const;

  /**
   * Returns the required size of the buffer for serialization of the vertex UV layer.
   * The method may return 0 if no UV layer is available.
   */
  int GetSizeOfVertexUVBuffer () const;

  /**
   * Returns the required size of the buffer for serialization of the triangles.
   * The size of the buffer is equal to 3 * CATIPolySurface::GetNbTriangles ().
   */
  int GetSizeOfTriangleBuffer () const;

  /**
   * Returns the required size of the buffer for serialization of the surface vertex line indices
   * for a given CATEdge.
   * See SerializeSurfaceVertices.
   */
  int GetSizeOfSurfaceVertexBuffer (CATEdge& iEdge) const;

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
   * Serializes the vertex normal layer into a float buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexNormalBuffer ().
   */
  HRESULT SerializeVertexNormalLayer (float* ioVertexNormalBuffer) const;

  /**
   * Serializes the vertex UV layer into a float buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexUVBuffer ().
   */
  HRESULT SerializeVertexUVLayer (float* ioVertexUVBuffer) const;

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
   * Serializes the vertex normal layer into a double buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexNormalBuffer ().
   */
  HRESULT SerializeVertexNormalLayer (double* ioVertexNormalBuffer) const;

  /**
   * Serializes the vertex UV layer into a double buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfVertexUVBuffer ().
   */
  HRESULT SerializeVertexUVLayer (double* ioVertexUVBuffer) const;

/** @} */

public:

/** @name Serialization of the facets.
    @{ */

  /**
   * Serializes the triangle vertices into an integer buffer.
   *
   * The buffer must be pre-allocated and its size should be at least GetSizeOfTriangleBuffer ().
   * The buffer is filled with the vertex indices after their mapping into a compact vertex array
   * ranging from 0 to CATIPolyMesh::GetNbVertices () - 1 inclusive.
   */
  HRESULT SerializeTriangles (int* ioTriangleVertices) const;

/** @} */

public:

/** @name Serialization of an edge bounding a face.
    @{ */

  /**
   * Serializes the surface vertices along a tessellated CATEdge bounding the CATFace.
   * 
   * The buffer must be pre-allocated and its size should be at least iSurfaceVertexLine.GetNbVertices ().
   *
   * @param iEdge
   *   The CATEdge bounding the CATFace and whose surface vertices are being serialized.
   * @param ioIndexBuffer
   *   The buffer for the surface vertices defining the tessellated CATEdge.
   *   The buffer is filled with the surface vertices after their mapping into a compact vertex array
   *   ranging from 0 to CATIPolyMesh::GetNbVertices () - 1 inclusive.
   */
    HRESULT SerializeSurfaceVertices (CATEdge& iEdge,
                                      int* ioIndexBuffer) const;

/** @} */

	/**
	* WARNING : only use this with the new implemenation of CATCGMTessBody (that is created with CATCGMTessellateParam)
	* Direct access to the tessellation cache (local mesh) and orientation of the cell regarding data cache 
	* returns oCellDataCache=NULL if there is delta mesh in the body context
  */
	HRESULT GetCellDataCache(const CATTessDataCache*& oCellDataCache, int & oOrientation);

private:
	void GetPolySurface () const;

private:

  CATCGMTessBody& _TessBody;
  CATFace& _Face;

  CATIPolySurface* _PolySurface;
	CATMapOfEdgeToPolySurfaceVertexLine _EdgeMapToPolyCurve;
	CATMapOfVertexToPolySurfaceVertex _VertexMapToPolyPoint;

  CATIPolySurfaceVertexIterator* _VertexIterator;
  CATPolySurfaceCompactVertexIndexMapper* _VertexMapper;

  CATBoolean _DoIncludeFacetSize;

};

/** @file 
 */

/**
 * Creates an instance of CATTessBodyFaceSerializer for serialization of the tessellation data for a CATFace.
 *
 * @param iTessBody
 *   The input CATCGMTessBody.
 * @param iFace
 *   The input CATFace whose tessellation data is to be serialized.
 * @return
 *   An instance of a CATTessBodyFaceSerializer.
 */
ExportedByTessBodyAdapters CATTessBodyFaceSerializer* CATCreateTessBodyFaceSerializer (CATCGMTessBody& iTessBody, CATFace& iFace);

inline void CATTessBodyFaceSerializer::DoIncludePolygonSize (CATBoolean iDoIncludeFacetSize)
{
  _DoIncludeFacetSize = iDoIncludeFacetSize;
}


#endif // !CATTessBodyFaceSerializer_H
