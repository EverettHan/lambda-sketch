#ifndef CAT3DCanonicalRep_h_
#define CAT3DCanonicalRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
#include "CAT3DRep.h"

#include <cstdint>
#include <atomic>

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

enum CAT3DCanonicalRepType
{
    CAT3DCanonicalRepType_Undefined = 0,
    CAT3DCanonicalRepType_Cuboid = 1,
    CAT3DCanonicalRepType_Sphere = 2,
    CAT3DCanonicalRepType_PartialSphere = 3,
    CAT3DCanonicalRepType_Cylinder = 4,
    CAT3DCanonicalRepType_Cone = 5,
    CAT3DCanonicalRepType_Torus = 6,
    CAT3DCanonicalRepType_PartialTorus = 7,
    CAT3DCanonicalRepType_CurvedPipe = 8
};

namespace CAT3DCanonical
{
    class ExportedBySGInfra Mesh
    {
    public:
        Mesh(float const *& iVertices,
             int          & iVerticesArraySize,
             float const *& iNormals,
             int          & iNormalsArraySize,
             int   const *& iTriangleIndices,
             int          & iNbTriangle,
             int   const *& iTriangleStripIndices,
             int          & iNbTriangleStrip,
             int   const *& iNbVertexPerTriangleStrip,
             int   const *& iTriangleFanIndices,
             int          & iNbTriangleFan,
             int   const *& iNbVertexPerTriangleFan,
             int          & iNbVisuEdges,
             int   const *& iNbVertexPerVisuEdge,
             int   const *& iVisuEdgeIndices);

        ~Mesh();

        unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

        /**
        * Increment reference counter.
        */
        void AddRef();

        /**
        * Decrement reference counter. If counter reaches zero, the object is destroyed.
        */
        void Release();

        /**
        * Vertices:
        *     - oVertices is the buffer for all vertex coordinates.
        *     - oVerticesArraySize is the number of float coordinates in the buffer. It is equal to 3 times the number of vertices.
        */
        HRESULT GetVertices(float const*& oVertices, int& oVerticesArraySize) const;

        /**
        * Normals:
        *     - oNormals is the buffer for all normals (each vertex has exactly 1 normal).
        *     - oNormalsArraySize is the number of float coordinates in the buffer. It is equal to 3 times the number of normals.
        */
        HRESULT GetNormals(float const*& oNormals, int& oNormalsArraySize) const;

        /**
        * Triangles:
        *     WARNING: oTriangleIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     - oNbTriangle is the number of isolated triangles.
        *     - oTriangleIndices is the buffer for all isolated triangles.
        *     - Each triangle is made from 3 successive values in the buffer.
        *
        * TriangleStrips:
        *     WARNING: oTriangleStripIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     - oNbTriangleStrip is the number of triangle strips.
        *     - oNbVertexPerTriangleStrip gives the size of each strip (number of vertices).
        *     - oTriangleStripIndices is the buffer for all triangle strips.
        *
        * TriangleFans:
        *     WARNING: oTriangleFanIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     - oNbTriangleFan is the number of triangle fans.
        *     - oNbVertexPerTriangleFan gives the size of each fan (number of vertices).
        *     - oTriangleFanIndices is the buffer for all triangle fans.
        */
        HRESULT GetTriangles(int const *& oTriangleIndices,
                             int        & oNbTriangle,
                             int const *& oTriangleStripIndices,
                             int        & oNbTriangleStrip,
                             int const *& oNbVertexPerTriangleStrip,
                             int const *& oTriangleFanIndices,
                             int        & oNbTriangleFan,
                             int const *& oNbVertexPerTriangleFan) const;

        /**
        * VisuEdges:
        *     WARNING: oVisuEdgeIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     VisuEdges are lines that can be drawn on top of the mesh. They are for visualization purposes only. They have no topological meaning.
        *     VisuEdges are optional. You can use nullptr if you don't need VisuEdges.
        *     - oNbVisuEdges is the number of VisuEdges.
        *     - oNbVertexPerVisuEdge gives the size of each VisuEdge (number of vertices).
        *     - oVisuEdgeIndices is the combined buffer for all VisuEdges.
        */
        HRESULT GetVisuEdges(int        & oNbVisuEdges,
                             int const *& oNbVertexPerVisuEdge,
                             int const *& oVisuEdgeIndices) const;

        /**
        * Vertices:
        *     - oVertices is the buffer for all vertex coordinates.
        *     - oVerticesArraySize is the number of float coordinates in the buffer. It is equal to 3 times the number of vertices.
        *
        * Normals:
        *     - oNormals is the buffer for all normals (each vertex has exactly 1 normal).
        *     - oNormalsArraySize is the number of float coordinates in the buffer. It is equal to 3 times the number of normals.
        *
        * Triangles:
        *     WARNING: oTriangleIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     - oNbTriangle is the number of isolated triangles.
        *     - oTriangleIndices is the buffer for all isolated triangles.
        *     - Each triangle is made from 3 successive values in the buffer.
        *
        * TriangleStrips:
        *     WARNING: oTriangleStripIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     - oNbTriangleStrip is the number of triangle strips.
        *     - oNbVertexPerTriangleStrip gives the size of each strip (number of vertices).
        *     - oTriangleStripIndices is the buffer for all triangle strips.
        *
        * TriangleFans:
        *     WARNING: oTriangleFanIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     - oNbTriangleFan is the number of triangle fans.
        *     - oNbVertexPerTriangleFan gives the size of each fan (number of vertices).
        *     - oTriangleFanIndices is the buffer for all triangle fans.
        *
        * VisuEdges:
        *     WARNING: oVisuEdgeIndices contains VERTEX indices (not coord indices). Values range between 0 and nbVertices-1.
        *     VisuEdges are lines that can be drawn on top of the mesh. They are for visualization purposes only. They have no topological meaning.
        *     VisuEdges are optional. You can use nullptr if you don't need VisuEdges.
        *     - oNbVisuEdges is the number of VisuEdges.
        *     - oNbVertexPerVisuEdge gives the size of each VisuEdge (number of vertices).
        *     - oVisuEdgeIndices is the combined buffer for all VisuEdges.
        */
        HRESULT Get(float const *& oVertices,
                    int          & oVerticesArraySize,
                    float const *& oNormals,
                    int          & oNormalsArraySize,
                    int   const *& oTriangleIndices,
                    int          & oNbTriangle,
                    int   const *& oTriangleStripIndices,
                    int          & oNbTriangleStrip,
                    int   const *& oNbVertexPerTriangleStrip,
                    int   const *& oTriangleFanIndices,
                    int          & oNbTriangleFan,
                    int   const *& oNbVertexPerTriangleFan,
                    int          & oNbVisuEdges,
                    int   const *& oNbVertexPerVisuEdge,
                    int   const *& oVisuEdgeIndices) const;

    private:
        std::atomic<std::int32_t> m_cRef;

        float const* Vertices;
        int          VerticesArraySize;

        float const* Normals;
        int          NormalsArraySize;

        int   const* TriangleStripIndices;
        int          NbTriangleStrip;
        int   const* NbVertexPerTriangleStrip;

        int          NbVisuEdges;
        int   const* NbVertexPerVisuEdge;
        int   const* VisuEdgeIndices;
    };
};

class CAT3DCanonicalSphereRep;
class CAT3DCanonicalPartialSphereRep;
class CAT3DCanonicalTorusRep;
class CAT3DCanonicalPartialTorusRep;
class CAT3DCanonicalCuboidRep;
class CAT3DCanonicalConeRep;
class CAT3DCanonicalCurvedPipeRep;
class CAT3DCanonicalCylinderRep;

/**
* Abstract class from which all 3DCanonicalRep classes must derive.
*/
class ExportedBySGInfra CAT3DCanonicalRep : public CAT3DRep
{
    CATDeclareClass;

protected:

    virtual ~CAT3DCanonicalRep();

public:
    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
     *	Compute BBox based on canonical information.
     */
    virtual HRESULT GetBoundingBox(CATMathPoint& oBBoxMin, CATMathPoint& oBBoxMax) const = 0;

    /**
     * Do not call this method. BoundingElement is only updated when canonical information changes (see Modify method).
     */
    virtual void SetBoundingElement(const CAT3DBoundingSphere& iBoundingSphere);

    /**
    * Generate a mesh (vertices/normals/triangles) from canonical information stored on the rep.
    * NB: You MUST call Release() on the mesh when you're finished with it.*
    *
    * WARNING: Use this method only when you cannot use the canonical methods from derived classes.
    */
    virtual HRESULT GetMesh(CAT3DCanonical::Mesh*& oMesh);

    /**
     *	@brief DMU stream
     */
    virtual void Stream(CATStreamer& oStream, int iSaveType = 0);

    /**
    *	@brief DMU stream
    */
    virtual void UnStream(CATStreamer& iStream);

    /**
     *	@brief Render handling
     */
    virtual void DrawShading(CATRender& iRender, int iInside);

    /**
     *	@brief Render handling
     */
    virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath);

protected:
    virtual void _SetBoundingElement(const CAT3DBoundingSphere& iBoundingSphere);

    virtual HRESULT BuildMesh(float const ** oVertices,
                              int          * oVerticesArraySize,
                              float const ** oNormals,
                              int          * oNormalsArraySize,
                              int   const ** oTriangleIndices,
                              int          * oNbTriangle,
                              int   const ** oTriangleStripIndices,
                              int          * oNbTriangleStrip,
                              int   const ** oNbVertexPerTriangleStrip,
                              int   const ** oTriangleFanIndices,
                              int          * oNbTriangleFan,
                              int   const ** oNbVertexPerTriangleFan,
                              int          * oNbVisuEdges,
                              int   const ** oNbVertexPerVisuEdge,
                              int   const ** oVisuEdgeIndices) = 0;

    virtual const vDrawInformation* GetDrawInformation();

    static void InitDrawInformation(CATRep* iRep);

    CAT3DCanonical::Mesh* _mesh;

private:
    friend class CAT3DCanonicalSphereRep;
    friend class CAT3DCanonicalPartialSphereRep;
    friend class CAT3DCanonicalTorusRep;
    friend class CAT3DCanonicalPartialTorusRep;
    friend class CAT3DCanonicalCuboidRep;
    friend class CAT3DCanonicalConeRep;
    friend class CAT3DCanonicalCurvedPipeRep;
    friend class CAT3DCanonicalCylinderRep;

    CAT3DCanonicalRep();
};

#endif // !CAT3DCanonicalRep_h_
