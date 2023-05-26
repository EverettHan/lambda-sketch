#ifndef CATPolyPPTimeEvaluator_H 
#define CATPolyPPTimeEvaluator_H

#include <vector>

#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"

#include "CATPolyPPPosition.h"

class CATPolyPPTimeEvaluator : public CATPolyRefCounted
{
  public:
    typedef CATCGMSharedPtr<CATPolyPPTimeEvaluator> SPtr;
    class KinematicState
    {
      public:
      double time;//when this point is reached
      CATPolyPPPosition::SPtr Dof;
      std::vector<double> dDof;//current speed of dof
      std::vector<double> ddDof;//current acceleration of dof
    };
  
  /**
   * evaluate for each point of the input iPathPoints the time where is happen and speed and acceleration
  */
  std::vector<KinematicState>  EvaluateTimes(std::vector<CATPolyPPPosition::SPtr> iPathPoints, KinematicState * StartingState = nullptr);
};




#endif
