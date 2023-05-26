
#ifndef CATPolyPPRobotSpace1DofT_HH
#define CATPolyPPRobotSpace1DofT_HH
/**
 * \addtogroup PathPlanRobot
 * @{
 */
#include "CATPolyPPTopologicalSpace1Dof.h"

class CATPolyPPTopologicalPoint;
class CATPolyUniformRandomGenerator;
/**  WIP:not used for the moment*/
class DSYExport CATPolyPPRobotSpace1DofT : public CATPolyPPTopologicalSpace1Dof
{
public:
  CATPolyPPRobotSpace1DofT(CATPolyUniformRandomGenerator & iRandomGenerator);
  CATPolyPPRobotSpace1DofT(const CATPolyPPRobotSpace1DofT& iOther, CATPolyUniformRandomGenerator & iRandomGenerator);
  virtual ~CATPolyPPRobotSpace1DofT();


  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const double * iMin, const double * iMax, double iTolerance);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iNeighborhood);

};
/**    @} */
#endif
