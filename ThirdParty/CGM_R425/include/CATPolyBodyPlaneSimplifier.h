
// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.

#ifndef CATPolyPlaneSimplifier_H
#define CATPolyPlaneSimplifier_H

#include "CATIAV5Level.h"
#ifdef CATIAR420

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)

#include "PolyBodyDecimate.h"
#include "CATIPolyMesh.h"

#include "CATMathPlane.h"
#include "CATMathPoint.h"

#include "CATPolyPolygonSplitBarsObserver2D.h"

#include <map>
#include <vector>


class CATPolyBody;
class CATIPolyMesh;
class CATIPolyIntIterator;
class CATMathTransformation;
class GriddedMesh;
class CATMathBox;
class CATPolyBar2D;
class CATPolyVertex2D;
class CATMathPoint2D;
class CATPolyPolygon2D;

/**
 *	@brief Segment and simplify input polybody
 */
class ExportedByPolyBodyDecimate CATPolyBodyPlaneSimplifier
{
public:

    /**
    *
    */
    struct Cluster
    {
        CATMathPlane plane;
        int id;
        double area;
        std::vector<int> triangles_ids;
        CATIPolyMesh* mesh;
        int merged;
        CATMathBox box;
        CATMathVector n_mean;
        unsigned n_vertices;

        ~Cluster()
        {
            if( mesh )
            {
                mesh->Release();
            }
            mesh = 0;
        }
    };

    /* For texture processing */
    typedef std::vector< std::pair< CATIPolyMesh*, int > > TriangleMap;
    typedef std::map< std::pair< double, double >, std::pair< double, double > > V2DTexMap;

    class CATPolyPolygonSplitBarsObserver2DImpl : public CATPolyPolygonSplitBarsObserver2D
    {
    public:
        CATPolyPolygonSplitBarsObserver2DImpl( CATPolyPolygon2D &iPolygon, V2DTexMap &iMap );
        virtual ~CATPolyPolygonSplitBarsObserver2DImpl();

        virtual HRESULT PrepareToSplitBars( const CATPolyBar2D* iBar0, const CATPolyBar2D* iBar1, const CATPolyVertex2D* iVertex );

    private:
        CATPolyPolygon2D &m_Polygon;
        V2DTexMap &m_Map;
    };

    CATPolyBodyPlaneSimplifier();

    virtual ~CATPolyBodyPlaneSimplifier();

    /**
     * @brief Run
     *
     * @param iBody          input PolyBody
     * @param iBodyTransfo   apply transformation
     * @param oBody          output body holds one face per cluster
     *
     */
    HRESULT Run( const CATPolyBody& iBody, const CATMathTransformation& iBodyTransfo, CATPolyBody*& oBody );


    HRESULT Run( const CATPolyBody& iBody, const CATMathTransformation& iBodyTransfo, std::map<unsigned, Cluster>& oClusters );

    /**
     *	@brief dihedral angle between two triangles
     *  If within tolerance a triangle is assigned to the current cluster
     */
    inline void SetDihedralAngleTolerance( double iValue ) { m_DihedralAngle = iValue; }

    /**
     *	@brief Decimate the resulting cluster
     */
    inline void DecimateCluster( bool iValue ) { m_DecimateCluster = iValue; }

    /**
     *	@brief Decimate tolerance
     *  @warning a bad tolerance may remove too much triangles
     */
    inline void SetDecimateClusterTolerance( double iValue ) { m_DecimateClusterTolerance = iValue; }

    /**
     *	@brief Fill detected holes inside a cluster
     *  To be detected, a hole must be bounded inside the cluster
     */
    inline void FillHolesFaces( bool iValue ) { m_FillHolesFaces = iValue; }

    /**
     *	@brief Discard cluster with fewer triangles
     */
    inline void SetMinClusterTriangles( int iValue ) { m_MinClusterTriangles = iValue; }

    /**
     *	@brief Discard cluster with lower area
     */
    inline void SetMinClusterlArea( double iValue ) { m_MinClusterArea = iValue; }

    /**
     *	@brief Griding tolerance of the input mesh
     *  Input mesh is voxelized to remove small details and stitch vertices
     */
    inline void SetGridSize( double iValue ) { m_GridSize = iValue; }

    /**
     *	@brief Merge cluster close to each other
     */
    inline void SetClusterMerging( bool iValue ) { m_MergeCluster = iValue; }

    /**
    *	@brief Merge cluster close to each other
     */
    inline void SetClusterMergingTolerance( double iValue ) { m_MergingTolerance = iValue; }

    /**
    * @brief Enable processing of texture coordinates
    */
    inline void ProcessTexCoords( bool iValue ) { m_ProcessTexCoords = iValue; }

private:


    /**
     *	@brief Grid the mesh with an octree like algorithm, in order to erase small details and merge duplicates triangles 
     */
    HRESULT GridMesh( const CATPolyBody& iBody, const CATMathTransformation& iBodyTransfo, GriddedMesh& oMesh, TriangleMap& oMapGriddedToInputTriangles );

    /**
     * @brief DetectPlaneClusters
     *
     * @param iMesh
     * @param oClusters
     *
     */
    HRESULT DetectPlaneClusters( GriddedMesh& iMesh, std::map<unsigned, Cluster >& oClusters );

    /**
     * @brief OptimizeClusters
     *
     * @param iMesh
     * @param oClusters
     *
     */
    HRESULT OptimizeClusters( GriddedMesh& iMesh, std::map<unsigned, Cluster >& oClusters );

    /**
     * @brief MergeClusters
     *
     * @param iMesh
     * @param oClusters
     *
     */
    HRESULT MergeClusters( GriddedMesh& iMesh, std::map<unsigned, Cluster >& oClusters );

    /**
     * @brief FilterClusters
     *
     * @param oClusters
     *
     */
    HRESULT FilterClusters( std::map<unsigned, Cluster >& oClusters );

    /**
     * @brief ProjectAndSimplify
     *
     * @param iMesh
     * @param oClusters
     *
     */
    HRESULT ProjectAndSimplify( GriddedMesh& iMesh, const TriangleMap& iMapGriddedToInputTriangles, std::map<unsigned, Cluster >& oClusters );


    double m_DihedralAngle;            ///<
    double m_DecimateClusterTolerance; ///<
    double m_GridSize;                 ///<
    bool m_DecimateCluster;            ///<
    bool m_FillHolesFaces;             ///<
    int m_MinClusterTriangles;         ///<
    bool m_MergeCluster;               ///<
    double m_MergingTolerance;         ///<
    double m_MinClusterArea;           ///<
    bool m_ProcessTexCoords;           ///<
};

#endif // _SOURCE

#endif // CATIAR420

#endif
