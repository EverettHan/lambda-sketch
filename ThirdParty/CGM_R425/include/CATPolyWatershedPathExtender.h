//===================================================================
// COPYRIGHT Dassault Systemes Provence 2018
//===================================================================
// CATPolyWatershedPathExtender.h
//===================================================================
//
// Usage notes: Extend a water path according some criterion (depth or merge operations)
//===================================================================
// HISTORIQUE :
// 11/09/2019 : NUA : Set flow ope (fix IR-718674)
// 05/08/2019 : NUA : Remove hooklet
// 20/09/2018 : NUA : Creation
//===================================================================

#ifndef CATPolyWatershedPathExtender_h__
#define CATPolyWatershedPathExtender_h__

//
#include "ExportedByCATPolyWatershedOperators.h"
#include "CATPolyDropPathOnTerrainOperator.h"
#include "CATPolyWatershedSegmentationData.h"

#include <vector>
#include <utility>

class CATTolerance;

class CATPolyBasinMergerOperator;
class CATPolyCriticalMorseIndexOperator;
class CATPolyRingOperator;
class CATPolyWatershedSegmentationOperator;

class ExportedByCATPolyWatershedOperators CATPolyWatershedPathExtender
{
public:

  // basic version
  static CATPolyWatershedPathExtender * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolerance, bool SingleFlowAtBottom = true);

  // use this version for taking into account the basin merge operations  (@see CATPolyBasinMergerOperator)
  static CATPolyWatershedPathExtender * CreateInstance(const CATPolyBasinMergerOperator * iMergeOpe, const CATPolyWatershedSegmentationOperator * iSegmentationOpe, std::vector<int> && OutletsInMergedData, const CATPolyWatershedSegmentationData_t & iOriginalBasinData, const CATTolerance * iTol, CATPolyDropPathOnTerrainOperator * iFlowOpe);
  
  CATPolyWatershedPathExtender(const CATTolerance & iTolerance) : m_Tolerance(iTolerance) {}
  
  virtual ~CATPolyWatershedPathExtender() {}

  const CATTolerance &  GetTolerance() const { return m_Tolerance; }

  // reuse existing ope
  virtual void SetFlowOpe(CATPolyDropPathOnTerrainOperator * iOpe) {}
  virtual void SetIndexOpe(CATPolyCriticalMorseIndexOperator * iOpe) {}
  virtual void SetRingOpe(CATPolyRingOperator * iOpe) {}

  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  // iThreshold allow to ignore small basin : the path is able to get out of basins whose depths is lower than iThreshold
  // in addition to the merge operation adds
	virtual HRESULT Run(double iThreshold = 0) = 0;

  typedef std::pair<CATPolyWatershedSegmentationData::PathFromSaddle, CATPolyDropPathOnTerrainOperator::KindOfFlow> ExtendedPath;

  // iStartPoint is assumed to be an outlet
  virtual HRESULT ExtendPath(int iStartPoint, std::vector<ExtendedPath> & oResult) const = 0;

  // modify the input path to extend it according to the merge operations  / the depth specified 
  virtual HRESULT ExtendPath(CATPolyDropPathOnTerrainOperator::WaterFlow_t & ioPath) const = 0;

  virtual std::vector<int> GetOriginalOutlets() const = 0;

  ////////////////////////// debug purpose
  typedef std::map<int, std::vector<CATPolyWatershedSegmentationData::PathFromSaddle> > SetOfPathsAtSaddle_t;
  typedef std::map<int, std::set< std::pair<int, double > > > SetOfSaddlesFromBottom_t;
  virtual void GetBottomToSaddle(SetOfSaddlesFromBottom_t & ioBottomToSaddle) const {};
  virtual void GetPathsFromSaddle(SetOfPathsAtSaddle_t  & ioPathsFromSaddles) const {}

protected:
  const CATTolerance & m_Tolerance;
};

//
#endif // CATPolyWatershedPathExtender_h__
