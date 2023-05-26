
#ifndef CATPolyPPRobotSpace1DofR_HH
#define CATPolyPPRobotSpace1DofR_HH
/**   \addtogroup PathPlanRobot
 *   @{ */
#include "CATPolyPPTopologicalSpace1Dof.h"

class CATPolyPPTopologicalPoint;
class CATPolyUniformRandomGenerator;
/**  WIP:not used for the moment*/
class DSYExport CATPolyPPRobotSpace1DofR : public CATPolyPPTopologicalSpace1Dof
{
public:
  CATPolyPPRobotSpace1DofR(CATPolyUniformRandomGenerator & iRandomGenerator);
  CATPolyPPRobotSpace1DofR(const CATPolyPPRobotSpace1DofR& iOther, CATPolyUniformRandomGenerator & iRandomGenerator);
  virtual ~CATPolyPPRobotSpace1DofR();


  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const double * iMin, const double * iMax, double iTolerance);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iNeighborhood);

};
/** @} */
#endif
