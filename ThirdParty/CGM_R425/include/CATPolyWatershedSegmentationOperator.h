#ifndef CATPolyCatchmentBasinOperator_h__
#define CATPolyCatchmentBasinOperator_h__

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyWatershedSegmentationOperator.h
//
//===================================================================
//
// Usage notes: Compute the watershed decomposition of a given terrain mesh. See @CATPolyWatershedSegmentationData_t
//
//===================================================================
//
//===================================================================
// December 2017  Creation NUA
//===================================================================

#include "ExportedByCATPolyWatershedOperators.h"
#include "CATPolyWatershedSegmentationData.h"

#include <map>
#include <vector>
#include <array>

class CATIPolyMesh;
class CATTolerance;
struct CATPolyWatershedCallback;

/*
- Compute the catchment basins (see @CATPolyWatershedSegmentationData) , whose boundary represent the watersheds.
- The input mesh is internally copied, in order to be refined (triangles are refined so that the watershed boundaries are gven mesh edges)
*/
class ExportedByCATPolyWatershedOperators CATPolyWatershedSegmentationOperator
{
public:
  
  virtual ~CATPolyWatershedSegmentationOperator() {}

  virtual HRESULT Run(CATPolyWatershedSegmentationData_t & oResult) = 0;
  
  // return a refined copy of the input
  // geometrically identical except on flat horizontal area
  // call must release the returned mesh
  virtual CATIPolyMesh * GetRefinedMesh() const = 0;
  //
  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  static CATPolyWatershedSegmentationOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTol);

  virtual const CATTolerance & GetTolerance() const = 0;
};

#endif // CATPolyCatchmentBasinOperator_h__
