#ifndef PPRobot_H_
#define PPRobot_H_

#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"
#include <vector>
#include <unordered_map>
#include <map>

#include "CATMathTransformation.h"

class CATBVHTreeSet;
class PPMapCDS;
class PPRigidSet;
class CATCSJoint;
//not valid on linux class PPRobotPlannerModel;
#include "PPRobotPlannerModel.h"


#include "ExportedByPPRobot.h"

/**
 * \addtogroup PPRobotModel
 * @{
 */

/**
  PPRobot interface describe and allow to update the position of the robot arm
  - from a Dof State.
  - from a tool position ( if inverse kinematic is implemented )

  @remarks the method  ComputeDofByInverseKinematic must be implemented with an inverse kinematic
  solver of your choice ( @ref PPRobotCDS for an example )
*/
class ExportedByPPRobot PPRobot : public CATPolyRefCounted
{

public:
  typedef CATCGMSharedPtr<PPRobot> SPtr;
  /**
   * Construct a robot base on it's kinematic description and 3d part.
   * @param[in] iRobotModel
   *      The kinematic model of the robot
   * @param[in] iBodySet
   *      The bvhtree set that contains 3d node associate to the id of the iRobotModel node
   */
  PPRobot(CATCGMSharedPtr<PPRobotPlannerModel> iRobotModel = CATCGMSharedPtr<PPRobotPlannerModel>(),
          CATBVHTreeSet * iBodySet= nullptr );
  virtual ~PPRobot();

  /*
  * CLone this robot, in general it s a good idea to clone the BodyReps 
  */
  virtual PPRobot::SPtr Clone(CATBVHTreeSet * iBodySet = nullptr);
  /**
    @brief Set The BVHTreeSet that will contains all the shape of the body of the robot
    @param iBodySet contains the rep associate to the part of the robot
  */
  virtual void SetBodyReps(CATBVHTreeSet * iBodySet );
  virtual CATBVHTreeSet * GetBodyReps() const ;

  /**
    @brief Set the robot model description (kinematic chain ,joint )
    @param[in] iRobotModel the robot description
  */
  virtual void SetRobotModel(CATCGMSharedPtr<PPRobotPlannerModel> &iRobotModel );
  virtual CATCGMSharedPtr<PPRobotPlannerModel> GetRobotModel() const;

  /**
   * return the number of dof .
   * @warning even Rigid joint is count for 1 Dof.
   */
  virtual unsigned int GetNbDof() const;




  /**
   * Mappings between Dof vector index (@see ComputePartTransfo @see UpdateJointState) and PPRobotJointModel * of Robot kinematic Tree 
  */
  virtual std::map<int ,PPRobotJointModel*> GetDofToJointMapping() const;
  virtual std::map<PPRobotJointModel*,int>  GetJointToDofMapping() const;
  

  /**
    @brief  Modify the position of the Robot Part accordingly with the Dof state in input
    @param[in] iDofState new position of joint
    @return true if every things is OK , false if nbdof not valid or config position is invalid.
  */
  virtual bool UpdateJointState(const std::vector<double> & iDofState);
  virtual std::vector<CATMathTransformation> ComputePartTransfo(const std::vector<double> & iDofState)  ;

  /**
  * enum that describe the result of an inverse kinematic call
  */
  typedef enum PPMUCStatus_enum
  {
    Moved ,          ///< inverse kinematic has move tool exactly
    PartiallyMoved,  ///< inverse kinematic has move tool but not exactly where use ask (may be impossible)
    Undefined,       ///< inverse kinematic invalid result
    InverseKinNotImplemented   ///< inverse kinematic is not implemented
  } PPMUCStatus;

  /**
   * Result of an inverse kinematic solve.
   */
  typedef struct PPIKResult_st
  {
    PPMUCStatus status =  Undefined; ///< status of the solve
    std::vector<double> DofState;    ///< dof state computed by the solve
  } PPIKResult;

#define PPROBOTKinNotImplemented { PPIKResult resu; resu.status = PPRobot::InverseKinNotImplemented; return resu;}
  /**
    Compute the dof by inverse kinematic (if solvable) to put the BodyToMove/Frame to the new
    iNewPositionWCS CATMathAxis  (position and orientation will be respected)
    @param iNewPositionWCS in WCS of the body maker
    @param iBodyToMove  the body to move
    @param iFrameToMove by default origin of body, (inBodyCoordinate) the marker that need to go in NewPosition
  */
  virtual PPIKResult ComputeDofByInverseKinematic(
    CATMathAxis & iNewPositionWCS,
    PPRobotNodeModel & iBodyToMove,
    int iFrameToMove = -1) PPROBOTKinNotImplemented;

  /**
    Compute the dof by inverse kinematic (if solvable) to put the BodyToMove/Frame to the new
    iNewPositionWCS CATMathPoint  (only position will be respected, no orientation target)
    @param iNewPositionWCS in WCS of the body maker
    @param iBodyToMove  the body to move
    @param iFrameToMove by default origin of body, (inBodyCoordinate) the marker that need to go in NewPosition
  */
  virtual PPIKResult ComputeDofByInverseKinematic(
    CATMathPoint & iNewPositionWCS,
    PPRobotNodeModel & iBodyToMove,
    int iFrameToMove = -1) PPROBOTKinNotImplemented;

  typedef struct PPIKBodyTarget_st
  {
    PPRobotNodeModel::SPtr Body;
    int FrameToMove = -1;
    CATMathPoint newPoint;
    CATMathAxis newAxis;
    bool onlyPoint = false;
    bool dofConstraint = false;
    int dof = -1;
    double dofvalue = 0.0;
  } PPIKBodyTarget;

  /**
  Compute the dof by inverse kinematic (if solvable) to put the  multiple BodyToMove/Frame to the new
  iNewPositionWCS CATMathPoint  (only position will be respected, no orientation target)
  @param iTargets new target positions for several bodys 
  
  */
  virtual PPIKResult ComputeDofByInverseKinematic(
    std::vector<PPIKBodyTarget > & iTargets
  ) PPROBOTKinNotImplemented;

protected:
  CATBVHTreeSet *_BodySet = nullptr;
  CATCGMSharedPtr<PPRobotPlannerModel> _RobotModel;
  std::map<PPRobotJointModel*,int> _JointToDof;
  std::map<int ,PPRobotJointModel*> _DofToJoint;
  std::map<PPRobotNodeModel* ,PPRobotJointModel*> _BodyToJoint;
  };
/**    @} */
#endif
