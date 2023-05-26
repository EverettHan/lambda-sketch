//===================================================================
// COPYRIGHT Dassault Systemes Provence 2018
//===================================================================
// CATPolyBasinMergerOperator.h
//===================================================================
//
// Usage notes: Merges basins according to a tolerance 
//@sy CATPolyCatchmentBasinData.h
//===================================================================
// HISTORIQUE :
// 20/09/2018 : Ajout du journal des fusions pour mettre a jour l'écoulement depuis les anciens exutoires
// 13/04/2018 : CDT6 : Creation
//===================================================================

#ifndef CATPolyBasinMergerOperator_h__
#define CATPolyBasinMergerOperator_h__


#include "ExportedByCATPolyWatershedOperators.h"
#include "CATPolyWatershedSegmentationData.h"
#include "CATErrorDef.h"

#include <vector>

class CATIPolyMesh;
struct CATPolyWatershedCallback;

/*
1 - Instanciate operator
2 - Call run method
3 - Call others methods
*/

class ExportedByCATPolyWatershedOperators CATPolyBasinMergerOperator
{
public:


	// Creates ope instance
	static CATPolyBasinMergerOperator * CreateInstance(const CATIPolyMesh * mesh, const CATPolyWatershedSegmentationData_t & InputSetOfBasins);

	virtual ~CATPolyBasinMergerOperator() {}

  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  virtual HRESULT Run() = 0;

  // Merges basin according to given tolerance 
	virtual HRESULT MergeBasinsAccordingToTolerance(CATPolyWatershedSegmentationData_t & SetOfBasinsMerged, const double tolerance) = 0;

	// Gives the distance from the lowest point of the basin 
	// to the lowest point of the boundaries with others catchment basins (or with the boundary of the mesh if IgnoreBoundary = false)
	virtual HRESULT GetDepth(const CATPolyWatershedSegmentationData::Cell_t * Basin, double & depth, const bool IgnoreBoundary = true) const = 0;

  // Merges basin of index IdxBasinToBeMerged into basin of index IdxAdjacentBasin in the set of basins SetOfBasinsMerged
  // The adjacent basin should be the one with the lowest exutoire 
  virtual HRESULT MergeTwoBasins(CATPolyWatershedSegmentationData_t * SetOfBasinsMerged, const int IdxBasinToBeMerged, const int IdxAdjacentBasin, CATPolyWatershedSegmentationData::Edge_t * iCommonEdge) = 0;

  // Merge basins until there is a certain number of basins left
  virtual HRESULT MergeUntilHavingANumberOfBasins(CATPolyWatershedSegmentationData_t & SetOfBasinsMerged, const int NumberOfRemainingBasins) = 0;

};


#endif // CATPolyBasinMergerOperator_H
