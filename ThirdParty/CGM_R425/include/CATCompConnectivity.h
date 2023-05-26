/**
 * COPYRIGHT Dassault Systemes 2016/05/19
 * ==================================================================
 *
 * CATCompConnectivity.h
 * Definition of the CATCompConnectivity interface
 *
 * ===================================================================
 * 2016/05/19 Creation
 */

#ifndef CATCompConnectivity_H
#define CATCompConnectivity_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
//#include "CATVisFoundation.h"
#include "CATCompMesh.h"
#include "CATCompositeTPtr.h"
#include "CATSGComposite.h"


/**
 * This class offers some services linked with the adjacency relationships of a mesh:
 *      - Incident triangles of a vertex
 *      - Neighbors vertices of a vertex
 *      - Vertices of a triangle
 */
class ExportedBySGComposites CATCompConnectivity : public CATSGComposite
{
    public:
        /**
         * @return Returns the number of vertices of the mesh
         */
        virtual CATSG::uint32 GetNbVertices() const = 0;

        /**
         * @return Returns the number of triangles of the mesh
         */
        virtual CATSG::uint32 GetNbTriangles() const = 0;

        /**
         * Updates the connectivity of the mesh.
         * @param iNbVertices   The number of vertices of the mesh
         * @param iNbTriangles  The number of triangles of the mesh
         * @param iConnectivity The connectivity of the mesh
         */
        virtual void SetConnectivity(CATSG::uint32 iNbVertices,
                                     CATSG::uint32 iNbTriangles,
                                     std::vector<CATSG::uint32>* iConnectivity) = 0;

        /**
         * @return Returns the mesh associated to the current connectivity
         */
        virtual CATCompMeshPtr GetMesh() const = 0;

        /**
         * Updates the mesh associated to the current connectivity.
         * @param iMesh New mesh
         */
        virtual void SetMesh(CATCompMeshPtr& iMesh) = 0;

        /**
         * Given a vertex V, returns the list of the incident triangles of V.
         * @param  iVertexIndex Index of the vertex
         * @param  oTriangles   List of incident triangles
         * @return S_OK if the operation succeeded, E_FAIL otherwise
         */
        virtual HRESULT GetTrianglesOfVertex(CATSG::uint32 iVertexIndex, std::vector<CATSG::uint32>& oTriangles) = 0;

        /**
         * Returns the valence of a vertex V.
         * @param  iVertexIndex   Vertex index
         * @param  oVertexValence Output vertex valence
         * @return S_OK if the operation succeeded, E_FAIL otherwise
         */
        virtual HRESULT GetVertexValence(CATSG::uint32 iVertexIndex, CATSG::uint32& oVertexValence) = 0;

        /**
         * Given a vertex V, returns the list of the vertex neighbors of V.
         * @param  iVertexIndex      Vertex index
         * @param  oneighborVertices List of vertex neighbors
         * @return S_OK if the operation succeeded, E_FAIL otherwise
         */
        virtual HRESULT GetNeighborVerticesOfVertex(CATSG::uint32 iVertexIndex, std::vector<CATSG::uint32>& oNeighborVertices) = 0;

        /**
         * Given a triangle T, returns the three vertices composing T.
         * @param  iTriangleIndex Index of the triangle
         * @param  oVertices      The vertices composing the triangle
         * @return S_OK if the operation succeeded, E_FAIL otherwise
         */
        virtual HRESULT GetVerticesOfTriangle(CATSG::uint32 iTriangleIndex, CATSG::uint32 oVertices[3]) = 0;
};


// {2CC1869C-4449-48BB-87D6-81CAD3F576DB}
static const GUID GUID_CATCompConnectivityTrait =
{ 0x2cc1869c, 0x4449, 0x48bb, { 0x87, 0xd6, 0x81, 0xca, 0xd3, 0xf5, 0x76, 0xdb } };


template<>
class CATTraitInfo<CATCompConnectivity>
{
    public:
        static const GUID& GetTraitGUID()
        {
            return GUID_CATCompConnectivityTrait;
        }

        static const int GetTraitTag()
        {
            // TODO
            return CATTraitTag(-1);
        }

        static const CATECompositionMode GetCompositeMode()
        {
            return CATECompositionModeExclusive;
        }

        static const CATTraitRawInfo GetRaw()
        {
            DefaultGetRawImplementation;
        }
};

typedef CATCompositeTWeakPtr<CATCompConnectivity> CATCompConnectivityWeakPtr;
typedef CATCompositeTPtr<CATCompConnectivity>     CATCompConnectivityPtr;
typedef CATOnStackBorrowPtr<CATCompConnectivity>  CATCompConnectivityBorrowPtr;



#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompConnectivity_H

