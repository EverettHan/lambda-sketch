//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
//  Creation a hull version of the input BVH
//
//=============================================================================
// 2021 GH7 :  Creation 
//=============================================================================

#ifndef CATPolyVisuBVHPPHullBuilder_h
#define CATPolyVisuBVHPPHullBuilder_h

#include "CATPolyBodyBVHPPHullBuilder.h"
#include "PolyVisuBVH.h"
#include <vector>
#include <map>


class CATPolyVisuBVHTreeSet;
class CATMathBox;

/**
 * Create a hull version bvh of the input bvh
 */
class ExportedByPolyVisuBVH CATPolyVisuBVHPPHullBuilder  : public CATPolyBVHPPHullBuilderCommon
{
 public:
  CATPolyVisuBVHPPHullBuilder(){}

  ~CATPolyVisuBVHPPHullBuilder(){}

  /**
   * @brief return a bvhtree visu whith the same structure/ID than the original but the rep are replaced by a hull version of the original
   * @param iOriginalMovable original bvh
   * @param iVoxelSize [optional] size of voxel if <0 an heristic chose the size
   * @param iRatioToUseHull [optional] ratio which decide if the hull will be use or not in function 
   * */
  CATPolyVisuBVHTreeSet * Run(
    CATPolyVisuBVHTreeSet & iOriginalMovable,
    double iVoxelSize=-1 ,
    double iRatioToUseHull=-1,
    std::map<int,std::vector<int>> idToGroupInHull=std::map<int,std::vector<int>>(),
    CATMathBox * iUserFilterBox=nullptr,
    double iOffsetToApply = 0.0);
};

#endif //CATPolyVisuBVHPPHullBuilder_h
