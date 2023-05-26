#ifndef CATPolyWatershedContributionsOperator_h__
#define CATPolyWatershedContributionsOperator_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2018
//===================================================================
// CATPolyWatershedContributionsOperator.h
//===================================================================
//
// Usage notes: Compute the contribution from any point of a terrain mesh
// point contributors consist in a submesh in which any point will flow down to the given triangle
//===================================================================
// HISTORIQUE :
// 05/02/2019 : NUA : Add new contributor implementation
// 26/10/2018 : NUA : Creation
//===================================================================


#include "ExportedByCATPolyWatershedOperators.h"
#include "CATErrorDef.h"


#include "CATPolyDropPathOnTerrainOperator.h"

class CATMathSetOfPoints;
class CATIPolyMesh;
class CATPolyWatershedFlowGraph;
class CATTolerance;
struct CATPolyWatershedCallback;

class CATPolyWatershedSegmentationOperator;
struct CATPolyWatershedSegmentationData_t;

#include <memory>
#include <map>
#include <vector>

//////////
// - call "init" method
// - call "run" method to retrieve the mesh corresponding to the terrain part which flow to the given vertex 
//////////
class ExportedByCATPolyWatershedOperators CATPolyWatershedContributionsOperator
{
  public:
    
    static CATPolyWatershedContributionsOperator * CreateInstance(const CATIPolyMesh & iMesh, const std::shared_ptr<CATPolyWatershedFlowGraph> & iGraph);
    static CATPolyWatershedContributionsOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTol);
    static CATPolyWatershedContributionsOperator * CreateInstanceForPolyline(const CATIPolyMesh & iMesh, const CATTolerance & iTol);
    static CATPolyWatershedContributionsOperator * CreateInstance(CATPolyWatershedSegmentationOperator * iWatershedOpe, const CATPolyWatershedSegmentationData_t & WatershedSegmentation);
    static CATPolyWatershedContributionsOperator * CreateInstance2(const CATIPolyMesh & iMesh, CATPolyWatershedSegmentationOperator * iWatershedOpe, const CATPolyWatershedSegmentationData_t & WatershedSegmentation);
    
    virtual void SetProgressCallback(CATPolyWatershedCallback * iCallback) = 0;

    virtual ~CATPolyWatershedContributionsOperator() {}

    virtual HRESULT Init() = 0;

    ////////////
    // user must release the produced mesh
    // oValueAtTriangle will store the total amount of water reaching each triangle
    virtual HRESULT Run(int iNumTriangle, CATIPolyMesh *& oMeshContribution, std::map<int,double> & oValueAtTriangle) = 0;

    struct ContributorBoundary_t
    {
      std::vector<CATPolyDropPathOnTerrainOperator::WaterFlow_t> m_PathFromVertex;
      std::vector<std::array< std::vector<CATPolyDropPathOnTerrainOperator::WaterFlow_t>, 2 > > m_BordingPaths;
    };
    // new implementation
    // - LIMITATION : input point must lie on a valley
    virtual HRESULT Run(const CATMathPoint & iPoint, int iTriangle, CATIPolyMesh * & oProducedMesh, ContributorBoundary_t & oBoundaryPaths, std::map<int, double> * oAmountByTriangle = NULL) = 0;

    virtual HRESULT Run(const CATMathSetOfPoints & iPolylinePoints, CATIPolyMesh * & oProducedMesh, ContributorBoundary_t & oBoundaryPaths, std::map<int, double> * oAmountByTriangle = NULL) = 0;

    // a appeler uniquement apres un run
    // permet de recuperer la projection de la polyline utilisee lors du dernier Run
    // VALABLE UNIQUEMENT POUR CreateInstanceForPolyline
    virtual HRESULT GetLastProjectedPolyline(CATMathSetOfPoints & oLastProjectedPolyline) const = 0;
};


#endif // CATPolyWatershedContributionsOperator_h__
