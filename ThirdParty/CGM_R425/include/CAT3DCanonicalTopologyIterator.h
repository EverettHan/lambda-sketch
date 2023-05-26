#ifndef CAT3DCanonicalTopologyIterator_h_
#define CAT3DCanonicalTopologyIterator_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (ProtectedInterfaces)
#include "CAT3DCanonicalRep.h"
#include "CATCompVizPrimitiveCache.h"
#include "CATCompVizPrimitiveCacheBehavior.h"

#include <vector>

class CATVizPrimitive;
class CATViz3DFace;
class CATViz3DEdge;
class CATVizVertexBuffer;
class CATRepPath;

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
*   Correct usage:
*
*       CAT3DCanonicalTopologyIterator canonicalTopologyIterator(iRep);
*
*       CATVizVertexBuffer* vertexBuffer = canonicalTopologyIterator.GetVertexBuffer();
*
*       const int nbFaces = canonicalTopologyIterator.GetNbFaces();
*       for (int faceNum = 0; faceNum < nbFaces; ++faceNum)
*       {
*           CATViz3DFace* vizFace = canonicalTopologyIterator.GetFace(faceNum);
*
*           // <do some work on the face>
*
*           CATSysReleasePtr(vizFace);
*       }
*
*       const int nbEdges = canonicalTopologyIterator.GetNbEdges();
*       for (int edgeNum = 0; edgeNum < nbEdges; ++edgeNum)
*       {
*           CATViz3DEdge* vizEdge = canonicalTopologyIterator.GetEdge(edgeNum);
*
*           // <do some work on the edge>
*
*           CATSysReleasePtr(vizEdge);
*       }
*
*       CATSysReleasePtr(vertexBuffer);
*/
class ExportedBySGInfra CAT3DCanonicalTopologyIterator
{
public:
    CAT3DCanonicalTopologyIterator(CAT3DCanonicalRep& iRep, VizPrimitiveCacheBehavior iVizPrimitiveCacheBehavior = VizPrimitiveCache_DoNotUse);
    ~CAT3DCanonicalTopologyIterator();

    // VertexBuffer
    // ------------

    /** Most efficient method (without copy).
    * Note: ownership of the arrays stays with CAT3DCanonical::Mesh inside CAT3DCanonicalRep.
    * Call iRep->GetMesh and then use AddRef/Release on the mesh if needed.
    */
    HRESULT GetVertexBuffer(float const*& oVertices, int& oVerticesArraySize);

    /** Most efficient method (without copy).
    * Note: ownership of the arrays stays with CAT3DCanonical::Mesh inside CAT3DCanonicalRep.
    * Call iRep->GetMesh and then use AddRef/Release on the mesh if needed.
    */
    HRESULT GetVertexBuffer(float const *& oVertices,
                            int          & oVerticesArraySize,
                            float const *& oNormals,
                            int          & oNormalsArraySize);
    /** Less efficient method (with copy).
    * Note: ownership of CATVizVertexBuffer is given to the caller of GetVertexBuffer. You must call Release when you are done with it.
    */
    CATVizVertexBuffer* GetVertexBuffer();

    // Faces
    // -----

    /** Returns the number of faces for this CAT3DCanonicalRep.
    */
    int GetNbFaces() const;

    /** Most efficient method (without copy).
    * WARNING: oTriangleIndices (and strips and fans) contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
    * Note: ownership of the arrays stays with CAT3DCanonical::Mesh inside CAT3DCanonicalRep.
    * Call iRep->GetMesh and then use AddRef/Release on the mesh if needed.
    */
    HRESULT GetFace(int const    iFaceNum,
                    int const *& oTriangleIndices,
                    int        & oNbTriangle,
                    int const *& oTriangleStripIndices,
                    int        & oNbTriangleStrip,
                    int const *& oNbVertexPerTriangleStrip,
                    int const *& oTriangleFanIndices,
                    int        & oNbTriangleFan,
                    int const *& oNbVertexPerTriangleFan,
                    bool       * oIsPlanar = nullptr);

    /** Less efficient method (with copy).
    * Note: ownership of CATViz3DFace is given to the caller of GetFace. You must call Release when you are done with it.
    */
    CATViz3DFace* GetFace(const int iFaceNum, bool* oIsPlanar = nullptr);

    /** Less efficient method (with copy).
    * Every triangle of the CAT3DCanonicalRep is stored inside 1 face.
    * Note: ownership of CATViz3DFace is given to the caller of GetFace. You must call Release when you are done with it.
    */
    CATViz3DFace* GetCombinedFace();

    // Edges
    // -----

    /** Returns the number of edges for this CAT3DCanonicalRep.
    */
    int GetNbEdges() const;

    /** Most efficient method (without copy).
    * WARNING: oVertexIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
    * Note: ownership of the array stays with CAT3DCanonical::Mesh inside CAT3DCanonicalRep.
    * Call iRep->GetMesh and then use AddRef/Release on the mesh if needed.
    */
    HRESULT GetEdge(const int iEdgeNum, int& oNbVertexInEdge, const int*& oVertexIndices);

    /** Less efficient method (with copy).
    * Note: ownership of CATViz3DEdge is given to the caller of GetEdge. You must call Release when you are done with it.
    */
    CATViz3DEdge* GetEdge(const int iEdgeNum);

    /** An edge is usually a separation element between two faces.
    * This method returns the face number for both adjacent faces of an edge.
    */
    HRESULT GetFacesOfEdge(const int iEdgeNum, int& oFaceNum1, int& oFaceNum2);

    // CATRepPath utils
    // ----------------

    /** This method takes a CATRepPath and it will use either 'oFace' or 'oEdge' (never both) to return a pointer to the sub-element.
    * A CATRepPath points to a CATRep, but it can also contain a list of specific sub-elements.
    * In the case of a CATRepPath pointing to a CAT3DCanonicalRep, the sub-elements will be either CATViz3DFace or CATViz3DEdge.
    * WARNING: only call this method with a CATRepPath pointing to a CAT3DCanonicalRep.
    * WARNING: only call this method with a CATRepPath containing exactly 1 sub-element in the list.
    */
    HRESULT GetSubElementFromCATRepPath(CATRepPath& iRepPath, CATViz3DFace*& oFace, CATViz3DEdge*& oEdge);

    /** This method takes a CATRepPath and it will use both 'oFaces' and 'oEdges' to return vectors of sub-elements.
    * A CATRepPath points to a CATRep, but it can also contain a list of specific sub-elements.
    * In the case of a CATRepPath pointing to a CAT3DCanonicalRep, the sub-elements will be either CATViz3DFace or CATViz3DEdge.
    */
    HRESULT GetSubElementsFromCATRepPath(CATRepPath& iRepPath, std::vector<CATViz3DFace*>& oFaces, std::vector<CATViz3DEdge*>& oEdges);

private:
    CATCompVizPrimitiveCachePtr _vizPrimitiveCache;
    VizPrimitiveCacheBehavior   _vizPrimitiveCacheBehavior;
    CAT3DCanonicalRep&          _rep;
    CAT3DCanonical::Mesh*       _mesh;
    int                         _nbFaces;
    int                         _nbEdges;
};

#endif // !CAT3DCanonicalTopologyIterator_h_
