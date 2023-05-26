// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================

#ifndef CATPolyAssemblyPathPlanning3DCheckerStatCallBack_H
#define CATPolyAssemblyPathPlanning3DCheckerStatCallBack_H

// ExportedBy
#include "PolyBodyBVHOperators.h"
#include "CATPolyAssemblyPathPlanning3DChecker.h"

#include "CATCGMSharedPtr.h"
#include <mutex>


class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanning3DCheckerStatCallBack : public CATPolyAssemblyPathPlanning3DChecker::StatCallBack
{
  public:
  //redefine SPtr
  typedef CATCGMSharedPtr<CATPolyAssemblyPathPlanning3DCheckerStatCallBack> SPtr;

  struct RejectInfo
  {
    int NbReject;
    std::vector<CATMathPoint> clashPoints;
  };

  CATPolyAssemblyPathPlanning3DCheckerStatCallBack();
  ~CATPolyAssemblyPathPlanning3DCheckerStatCallBack();

  
  void OnRejectConfig(const CATPolyPPConfigurationChecker::Collision &iCollision, const CATPolyPPPosition& iConfig,int threadID);

  std::map<int, RejectInfo> GetRejectStat();

  protected:
  std::map<int, RejectInfo> _NbRejectById;
  std::mutex _mutex;
};


#endif
