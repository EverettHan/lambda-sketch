#ifndef CATPolyPPRobotConfigurationDistance_HH
#define CATPolyPPRobotConfigurationDistance_HH

/**   \addtogroup PathPlanRobot
 *   @{ */

#include "DSYExport.h"
#include "CATPolyPPConfigurationDistance.h"

#include "CATCGMSharedPtr.h"
#include <vector>

class PPRobot;
class CATMathPoint;

/**
 * implement a specific distance metric for robot arm.
 *
 * The CATPolyPPRobotConfigurationDistance is used to compare configuration of robot arm.
 * In this implementation the distance is based on the biggest movement of all its part.
 *
 * The movement of a part is approximate by the movement of the point of the bounding element of the part.
 *
 * @remark small angle can lead to big movement distance if the part as a big arm lever around the rotation axis!
 */
class DSYExport CATPolyPPRobotConfigurationDistance : public CATPolyPPConfigurationDistance
{
public:
  /**
   * Construct the distance operator based on the PPRobot descrtiption.
   * @param[in] ipRobot
   *            The robot dof descrition and the 3d shape
   */
  CATPolyPPRobotConfigurationDistance(CATCGMSharedPtr<PPRobot> ipRobot = CATCGMSharedPtr<PPRobot>(nullptr));
  ~CATPolyPPRobotConfigurationDistance();

  //override
  virtual HRESULT  SquareDistance(const CATPolyPPPosition & iConfig1, const CATPolyPPPosition & iConfig2, double& ioSquareDistance) ;
protected:

  CATCGMSharedPtr<PPRobot> _Robot;


  //precompute
  std::vector<std::vector<CATMathPoint>> _PointSampleByPart; ///< point extracted from the bounding element of the part of the robot
};
/**   @} */
#endif
