#ifndef CATPolyPPRobotServices_H
#define CATPolyPPRobotServices_H
/**  \addtogroup PathPlanRobot
 *   @{
 */
#include "DSYExport.h"
#include <vector>
#include "CATCGMSharedPtr.h"

//#include "PPRobot.h"
#include "PPRobotPlannerModel.h"

#include "CATPolyPPPosition.h"

#include "CATMathPoint.h"
#include "CATMathTransformation.h"


#include "CATPolyBoundingVolume.h"

#include "DSYSysJSON.h"

class CATPolyInterferenceOper;


/**
* Various service used by ...PPRobot... classes
*
*/

namespace CATPolyPPRobotServices
{

/**
 * @brief return a list of point used to compute distance between volume
 * @param[in] iBounding
 *            The bounding volume from which the point must be sampled
*/
DSYExport std::vector<CATMathPoint> GetSamplingOfBoundingVolume(const CATPolyBoundingVolume & iBounding);

/**
 * Get the englobing AABB
 * */
DSYExport CATMathBox GetBox(const CATPolyBoundingVolume & iBounding);

/**
  @brief apply iT0 and iT1 to a list of point and return the max movement between the pair of point
  @param[in] iPoint
      list of point representing the moving part
  @param[in] iT0
      Current position of part
  @param[in] iT1
      New position of part
  @return the maximun distance movement from all the points.
*/
DSYExport double GetMaxMovementSquare(const std::vector<CATMathPoint> & iPoint, const CATMathTransformation & iT0, const CATMathTransformation & iT1 );

/**
  Convert from CATPolyPPPosition to dof state vector and inverse
*/
DSYExport std::vector<double> Convert(const CATPolyPPPosition & iTopoPoint) ;
DSYExport CATCGMSharedPtr<CATPolyPPPosition> Convert(const std::vector<double> & iDofState, const CATPolyPPCartesianProduct & iDofSpace) ;

/**
  @brief return the CATMathTransformation based on the dof type and dof value
  @param[in] iDofMovement The type of movement of the joint
    - Rotation
    - Translation
    - ...
  @param[in] iDofValue angle of lenght value of the joint
  @return the transformation that represent this movement
*/
DSYExport CATMathTransformation  GetTransfoFromDof(const PPRobotJointModel::DofMovement & iDofMovement, double iDofValue);
DSYExport CATMathTransformation  GetRelativeTransfoFromParentJoint( PPRobotPlannerModel & Model,
  PPRobotNodeModel & bodyA,
  CATMathAxis iFrame
);

  //JSON Streaming/unstreaming
  
  DSYExport DSYSysJSONValue ToJson(const CATMathTransformation & M);
  DSYExport DSYSysJSONValue ToJson(const  CATMathAxis & M);
  DSYExport DSYSysJSONValue ToJson(PPRobotNodeModel & M);
  DSYExport DSYSysJSONValue ToJson(PPRobotJointModel & M);
  DSYExport DSYSysJSONValue ToJson(PPRobotPlannerModel & iModel);


  //should be somewhere else 
  DSYExport DSYSysJSONValue ToJson(CATPolyInterferenceOper & iOper);
  DSYExport CATPolyInterferenceOper * FromJson(DSYSysJSONValue & iJsonOper);

}


/** @} */
#endif

