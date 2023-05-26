#ifndef CATPolyWatershedBasinVolumeOpe_h__
#define CATPolyWatershedBasinVolumeOpe_h__
//===================================================================
// COPYRIGHT Dassault Systemes Provence 2019
//===================================================================
// CATPolyWatershedBasinVolumeOpe.h
//===================================================================
//
// Usage notes: Compute the volume (as a scalar) of the watershed basins
//
//===================================================================
// HISTORIQUE :
// 05/08/2019 : NUA : Creation
//===================================================================

#include "ExportedByCATPolyWatershedOperators.h"

#include "CATMathPoint.h"
#include "CATPolyWatershedSegmentationData.h"

// STL
#include <vector>
#include <array>

class CATIPolyMesh;

class ExportedByCATPolyWatershedOperators CATPolyWatershedBasinVolumeOpe
{
public:
  static CATPolyWatershedBasinVolumeOpe * CreateInstance(const CATPolyWatershedSegmentationData_t & iCurrentSegmentation, const CATIPolyMesh & iRefinedMesh);

  virtual ~CATPolyWatershedBasinVolumeOpe() {}

  virtual HRESULT Init() = 0;

  enum KindOfComputation
  {
    K_Triangulate,
    K_Boolean,

  };
  // visu purpose
  typedef std::vector<std::array<CATMathPoint, 3> > BasinSurface_t;

  virtual HRESULT ComputeBasinVolume(int NumBasin, double & oVolume, BasinSurface_t & oBasinSurface , KindOfComputation K) const = 0;

};

#endif // CATPolyWatershedBasinVolumeOpe_h__
