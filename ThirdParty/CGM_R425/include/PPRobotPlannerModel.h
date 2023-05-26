#ifndef PPRobotPlannerModel_H_
#define PPRobotPlannerModel_H_
/**
 * \addtogroup PPRobotModel
 *  @{
 */
#include "DSYExport.h"

#include <vector>


#include "CATMathAxis.h"
#include "CATMathTransformation.h"

#include "CATCGMSharedPtr.h"
#include "CATPolyRefCounted.h"



class PPRobotNodeModel;
class PPRobotJointModel;
typedef int PPRobotBodyId;



/**
 * Describe a joint of robot arm.
 *
 * For a dof value of 0, the axis FrameInParent and  FrameInChild are coincident,
 * when the dof value change the FrameInChild will rotate/translate on x axis of FrameInParent.
 *
 * \snippet PPRobotTutoMain.cpp PPRobotTutoPPRobotJointModel
 * \image html PPRobotTutoSlideX.gif
 * The data can be represented as json
 * \dontinclude  Shared/Tuto/RobotKinematic.json
 * \skip Joints
 * \until Body
 */
class DSYExport PPRobotJointModel : public CATPolyRefCounted
{

public:
  typedef  CATCGMSharedPtr<PPRobotJointModel> SPtr;
  /**
   * enum that define the type of movement of a joint dof.
   */
  enum DofMovement
  {
    Rigid,        ///< No movement
    Rotation,     ///< rotation movement around X axis of FrameInParent   (Revolute joint)
    Translation   ///< translation movement along X axis of FrameInParent (Translation joint)
  };


  CATMathAxis FrameInParent; ///< The axis system of the joint attach to the parent body (in local coordinate of parent body)
  CATMathAxis FrameInChild;  ///< The axis system of the joint attach to the child body  (in local coordinate of child body )

  enum DofMovement Movement = Translation ; ///< Dof movement type
  double DofLimits[2]={-2*3.1415,2*3.1415}; ///< Limits of the dof

  CATCGMSharedPtr<PPRobotNodeModel> ChildBody; ///< The child body of this joint

  SPtr Clone();
};

/**
 * Describe a body of the robot and the joint that connect it to it's children.
 *
 * \snippet PPRobotTutoMain.cpp PPRobotTutoPPRobotBodyModel
 *  The data can be represented as json
 * \dontinclude  Shared/Tuto/RobotKinematic.json
 * \until FrameInParent
 */
class DSYExport PPRobotNodeModel : public CATPolyRefCounted
{
public:
  typedef  CATCGMSharedPtr<PPRobotNodeModel> SPtr;

  PPRobotBodyId id; ///< Id use to associate a 3D shape to this node
  std::vector<CATCGMSharedPtr<PPRobotJointModel>> Joints; ///< List of joints connected to children

  std::vector<CATMathAxis> _AttachedFrames;///< List of Frame attached to the body (can be used as mounting point)


  SPtr Clone();
};

/**
 * Describe a robot arm.
 * The robot arm is composed of
 * - body and joints that describe the kinematic
 * - a position to place the robot in the scene.
 * - a dof state that represent the initial configuration of the robot.
 *
 * \snippet PPRobotTutoMain.cpp PPRobotTutoPPRobotPlannerModelFULL
 * \image html PPRobotTuto_problem.jpg
 * The data can be represented as json
 * \include Shared/Tuto/RobotKinematic.json
 */
class DSYExport PPRobotPlannerModel : public CATPolyRefCounted
{
public:
  typedef CATCGMSharedPtr<PPRobotPlannerModel> SPtr;
  CATMathAxis RootPosition; ///< The position of the root body
  CATCGMSharedPtr<PPRobotNodeModel> Root; ///< Root node of the tree representing the robot arm kinematic
  std::vector<double> JointDofState;  ///< initial state of the joint


  /**
   * Visitor to use with PPRobotPlannerModel::VisitFrom
   * 
   * developer should override the visit methods to do what they want
   * @code
   *  bool visit(PPRobotNodeModel & ioBody)
   *  {
   *    std::cout << ioBody.id << std::endl;
   *    return true;
   *  }
   * @code
  */
  class Visitor
  {
    public:
    virtual bool visit(PPRobotNodeModel & ioBody) { return true;};
    virtual bool visit(PPRobotJointModel & ioJoint) { return true;};
  };

  /**
   * iter on the kinematic chain starting at iStartingNode;
  */
  static bool VisitFrom(Visitor & iVisitor,PPRobotNodeModel & ioStartNode);

  /**
   * return the ordered list of the body.
   * the dof state is ordered in the same way.
   */
  std::vector<PPRobotBodyId> GetRobotPartIdList() const ;

  /**
   * return the body at the end of the kineamtic tree
  */
  std::vector<PPRobotBodyId> GetRobotLeafPartIdList() const ;

  /**
   * Return the node associate to a body id.
   * @param[in] id
   *    id of the body to get
   * @return PPRobotNodeModel or nullptr
   */
  CATCGMSharedPtr<PPRobotNodeModel> GetNodeById(PPRobotBodyId id) const;
  CATCGMSharedPtr<PPRobotNodeModel> GetParentNodeOfId(PPRobotBodyId id) const;
  /**
   * Return the joint that have the ChildBody associate to id
   * @param[in] id
   *    id of the child body to get
   * @return PPRobotJointModel or nullptr
   */
  CATCGMSharedPtr<PPRobotJointModel> GetJointByChildId(PPRobotBodyId id) const;
  
};

/**  @} */

#endif

