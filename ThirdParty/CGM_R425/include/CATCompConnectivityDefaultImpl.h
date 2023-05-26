/**
 * COPYRIGHT Dassault Systemes 2016/05/19
 * ==================================================================
 *
 * CATCompConnectivityDefaultImpl.h
 * Definition of the CATCompConnectivityDefaultImpl class
 *
 * ===================================================================
 * 2016/05/19 Creation
 */

#ifndef CATCompConnectivityDefaultImpl_H
#define CATCompConnectivityDefaultImpl_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompConnectivity.h"
#include "CATCompMesh.h"
#include "CATSGCompositeHost.h"


/**
 * Default implementation of the CATCompConnectivity interface
 */
class ExportedBySGComposites CATCompConnectivityDefaultImpl : public CATSGCompositeHost1<CATCompConnectivity, CATSGComposite>
{
    public:
        CATCompConnectivityDefaultImpl();
        CATCompConnectivityDefaultImpl(CATSG::uint32 iNbVertices, CATCompMeshPtr& iMesh);
        virtual ~CATCompConnectivityDefaultImpl();

        virtual CATSG::uint32 GetNbVertices() const;
        virtual CATSG::uint32 GetNbTriangles() const;

        virtual void SetConnectivity(CATSG::uint32 iNbVertices,
                                     CATSG::uint32 iNbTriangles,
                                     std::vector<CATSG::uint32>* iConnectivity);

        virtual CATCompMeshPtr GetMesh() const;
        virtual void SetMesh(CATCompMeshPtr& iMesh);

        virtual HRESULT GetTrianglesOfVertex(CATSG::uint32 iVertexIndex, std::vector<CATSG::uint32>& oTriangles);
        virtual HRESULT GetNeighborVerticesOfVertex(CATSG::uint32 iVertexIndex, std::vector<CATSG::uint32>& oNeighborVertices);
        virtual HRESULT GetVertexValence(CATSG::uint32 iVertexIndex, CATSG::uint32& oVertexValence);
        virtual HRESULT GetVerticesOfTriangle(CATSG::uint32 iTriangleIndex, CATSG::uint32 oVertices[3]);

    private:
        CATSG::uint32               _nbVertices;
        CATSG::uint32               _nbTriangles;
        std::vector<CATSG::uint32>* _connectivity;
        CATCompMeshPtr              _mesh;
        CATSG::uint32*              _indices;
};


#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompConnectivityDefaultImpl_H

