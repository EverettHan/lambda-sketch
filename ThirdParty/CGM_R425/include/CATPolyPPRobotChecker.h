#ifndef CATPolyPPRobotChecker_H
#define CATPolyPPRobotChecker_H

/**   \addtogroup PathPlanRobot 
 *  @{ */

// ExportedBy
#include "PolyBodyBVHOperators.h"
#include "DSYExport.h"

#include "CATCGMSharedPtr.h"
#include "CATPolyDeprecated.h"

// Poly
#include "CATPolyPPPosition.h"
#include "CATPolyPPConfigurationChecker.h"
#include "CATPolyPPCartesianProduct.h"
#include "CATPolyInterfClashContactOper.h"


#include "CATPolyUniformRandomGenerator.h"
#include "CATPolyLittleTimer.h"
#include <memory>

//Robot
#include "PPRobot.h"

//#include "CATManufTestUtilitiesServices.h" //for timer


// Forward declarations
//class CATPolyPPPosition;
class CATPolyInterferenceOper;
class CATBVHTreeSet;

class CATPolyPPConfigurationDistance;
class CATPolyPPRobotConfigurationDistance;
class CATPolyInterfInputCoupleFilterImpl;
class PPRobotPlannerModel;
class DSYSysJSONValue;


/**
 * implementation of a CATPolyPPConfigurationChecker specific to the path planning of robotic arm.
 *
 * this implementation :
 * - create the space to explore base on the dof description of the PPRobot model.
 * - implement a default clash test between:
 *    - the robot part treeset @see GetScene that is generate from the PPRobot description
 *    - the scene tresset @see  GetMovingModel that is provided by  SetScene
 *
 * The checker use the PPRobot class to get information about the kinematic of the robot and to use the inverse kinematics if needed
 */
class DSYExport CATPolyPPRobotChecker : public CATPolyPPConfigurationChecker
{
public:
  typedef CATCGMSharedPtr<CATPolyPPRobotChecker> SPtr;
  /**
  * Construct the checker and the space to explore based on the robot description
  * @param[in] iRobotSpec
  *   a description of the robot
  */
  CATPolyPPRobotChecker(CATCGMSharedPtr<PPRobot> &iRobotSpec );

  /**
   * Construct by copy (important for multithread ).
   */
//  CATPolyPPRobotChecker( const CATPolyPPRobotChecker& iOther );

  bool IsA(const char * iClassName) const ;
  /**
   * Desctructor
   * will release reference in PPRobot
   */
  ~CATPolyPPRobotChecker();



  /*
  * TODO
  */
  class DSYExport IUserInterpolationOperator : public CATPolyRefCounted
  {
    public:
    typedef CATCGMSharedPtr<IUserInterpolationOperator> SPtr;
    //TODO interpolation interfaces methodes;
    /**
     * return the interpolate point between iPosition1,iPosition2
     * 
     * @remark if a point cannot be interpolate for an index , the method must return a CATPolyPPPosition but flag is as  ConfigurationType::Invalid
    */
    virtual std::vector<CATPolyPPPosition::SPtr> Interpolate(const CATPolyPPPosition &iPosition1, const CATPolyPPPosition &iPosition2, unsigned int iNbSteps);

    /**
     * interpolate the point on the segment [iPosition1,iPosition2] at the param iParam
    */
    virtual CATPolyPPPosition::SPtr Interpolate(const CATPolyPPPosition &iPosition1, const CATPolyPPPosition &iPosition2, double iParam) = 0;

    virtual ~IUserInterpolationOperator();

      /**
   * @brief internal usage for debug stream of data
   * 
   * @param oJsonData object that will be filled with data of this class
   * @param iOutputDirectory directory where put external (cgr,...) file if required
   */
  virtual void ToJson(DSYSysJSONValue & oJsonData, const char * iOutputDirectory = nullptr){};
  };
  typedef enum PPInterpolation
  {
    DofInterpolation,
    Part3DInterpolation,
    UserInterpolation
  } PPInterpolationEnum;

  /**
   * Set the type of interpolation made by this robot between 2 point
   * @param[in] iMode basic type of interpolation or UserInterpolation
   * @param[in] iUserOperator an operator of interpolation if iMode is UserInterpolation
  */
  void SetInterpolationMode(PPInterpolationEnum iMode = DofInterpolation,IUserInterpolationOperator::SPtr iUserOperator = IUserInterpolationOperator::SPtr());
  PPInterpolationEnum GetInterpolationMode() const ;
  IUserInterpolationOperator::SPtr GetInterpolationOperator() const ;
  

  /**
   * Convert a CATPolyPPPosition into an array of dof
   * @param[in] iTopoPoint
   *    the configuration to convert
   * @return the dof list value
   */
  std::vector<double> Convert(const CATPolyPPPosition & iTopoPoint) const;
  /**
   * convert a list of dof value into a CATPolyPPPosition.
   * @param[in] iDofState
   *    the dof list value
   * @return the equivalent CATPolyPPPosition
   */
  CATCGMSharedPtr<CATPolyPPPosition> Convert(const std::vector<double> & iDofState) const;

  /**
   * return the config space associate to this robot arm.
   * The space is compose of several topological space that represent the dof of the robots.
   */
  CATCGMSharedPtr<CATPolyPPCartesianProduct> GetConfigSpace() const;

  //override method
  //see the doc in original interface

  Collision TestConfiguration(const CATPolyPPPosition & iConfig, CATBoolean iStatus = 0);
  CollisionType* TestConfigurations(const CATPolyPPPosition & iConfig1, const CATPolyPPPosition & iConfig2, unsigned int oNbTests);
  CollisionType TestConfigurations(const CATPolyPPPosition & iConfig1, CATPolyPPPosition & iConfig2, CATPolyPPPosition *& oLastValidPosition, bool iCDIST /* = true */);
  CollisionType TestConfigurationsCached(CATPolyPPCartesianProduct& iSpace, const CATPolyPPPosition & iConfig1, CATPolyPPPosition & iConfig2, CATPolyPPPosition *& oLastValidPosition, bool iCDIST /*= true*/);
  void InitCache( unsigned iSize  ){};

  /*
  void AddClashSolverPass(CATPolyInterferenceOper * pOper, const CATListOfInt& iActivatedSceneObject, const CATListOfInt& iActivatedMovingObject, double iPenetration = -1.0, bool iTakeOwnership = true );
  void GetClashSolverPass(unsigned iPass, CATPolyInterferenceOper *& opOper, CATListOfInt& oActivatedSceneObject, CATListOfInt& oActivatedMovingObject, double &oPenetration  ) const;
  int GetNbClashSolverPass() const;
  */

  /**
   * Set the obstable that the robot must avoid.
   * @param[in] ipScene (must not be deleted before this )
   */
  void SetScene( CATBVHTreeSet * ipScene) ;
  const CATBVHTreeSet * GetScene() const;
  const CATBVHTreeSet * GetMovingModel() const;
  CATCGMSharedPtr<PPRobot> GetRobot() const;

  //enable self collision of the part of the robot
  POLY_DEPRECATED("use AddSelfInterferenceOperator instead",
  void SetSelfCollisionMode(bool iEnable = true );)
  POLY_DEPRECATED("use AddSelfInterferenceOperator instead",
  bool GetSelfCollisionMode() const;)
  /**
   * @brief filter collision between some pair of parts (usefull for part connected by a joint/dof )
   * obsolete  use AddSelfCollisionOperator;
   * */
  POLY_DEPRECATED("use AddSelfInterferenceOperator instead",
  void SetSelfCollisionFilterCouple( const std::vector<std::pair<int,int>> & iCoupleToFilter );)

  class InterferencePassData
  {
    public: 
    std::shared_ptr<CATPolyInterferenceOper>  Oper;
    std::vector<std::pair<int,int>> FilterMap;
  };

  /**
   * add an operator of self interference test
   * @param[in] iOper the interference operator 
   * @param[in] iCoupleToFilter interference will not be computed between this couple
  */
  int AddSelfInterferenceOperator(  std::shared_ptr<CATPolyInterferenceOper>  iOper, const std::vector<std::pair<int,int>> & iCoupleToFilter );
  int AddSelfInterferenceOperator( const InterferencePassData & iPass);
  const std::vector<InterferencePassData > GetSelfInterferenceOperator() const ;

  /**
   * add an operator of scene vs  interference test
   * @param[in] iOper the interference operator 
   * @param[in] iCoupleToFilter interference will not be computed between this couple
   */
  int AddSceneRobotInterferenceOperator( const InterferencePassData & iPass);
  const std::vector<InterferencePassData > GetSceneRobotInterferenceOperator() const ;


  static InterferencePassData BuildClashPass( );
  static InterferencePassData BuildClearancePass( double iClearance );


  /**
   * @brief Helper that generate filter based on the robot model, a new filter will be create if 2 part have a common joint
   * @param[in] iRobotModel the robot model with joints
   * @return a list of pair that must be filter by clash 
  */
  static std::vector<std::pair<int,int>> BuildCollisionFilterFromJoint(PPRobotPlannerModel &iRobotModel);
  /**
   * @brief Helper that generate filter couple based on the current interference
   * @param[in] iOper an operator of interference ( make sur the operator compute all interference @see StopAtFirstInterference @see StopAtFirstClash ...)
   * @param[in] iRobot robot checker where this method will find the bvhtree of the robot
  */
  static std::vector<std::pair<int,int>> BuildCollisionFilterFromCurrentClash(CATPolyInterferenceOper & iOper,CATPolyPPRobotChecker & iRobot);


  /**
   * Clone method important for multithread.
   */
  CATPolyPPConfigurationChecker* Clone() const;

  /** Debug */
  virtual CATPolyPPRobotChecker * CastToRobotChecker() {return this;}
  /** Debug */
  virtual const CATPolyPPRobotChecker * CastToRobotChecker() const {return this;}

  int m_ID = -1;

protected:

  class InterfPass : public InterferencePassData
  {
    public:
    //std::shared_ptr<CATPolyInterferenceOper> Oper;
    std::shared_ptr<CATPolyInterfInputCoupleFilterImpl> Filter;
  } ;
  std::vector<InterfPass> _SelfInterfPasses;
  std::vector<InterfPass> _SceneRobotInterfPasses;

  CATCGMSharedPtr<PPRobot> _Robot;                        ///< Robot description and inverse kin
  CATCGMSharedPtr<CATPolyPPCartesianProduct> _DofSpace;   ///< Space that represent the Dof of the robot

  CATPolyUniformRandomGenerator _Generator=CATPolyUniformRandomGenerator(17,CATPolyUniformRandomGenerator::AdvMathematics); ///< generator use for random point in space

  //CATPolyInterferenceOper *_ClashDefault = nullptr; ///< clash operator use to test robot vs scene
  CATBVHTreeSet *_Scene = nullptr;                  ///< Obstacle tree

  CATPolyPPRobotConfigurationDistance *_DistOperator; ///< specific operator of distance for robot


  //PerfAnalyse
  CATPolyLittleTimer _RunClash ;
  CATPolyLittleTimer _RunUpdate ;
  size_t _NbClash = 0;
  bool _SelfCollisionMode = false;
  //std::vector<std::pair<int,int>> _FilterCouples;

  //CATPolyInterfInputCoupleFilterImpl * _SelfCollisionFilter = nullptr;

  PPInterpolationEnum _InterpolationMode = DofInterpolation;
  IUserInterpolationOperator::SPtr _UserInterpolator = nullptr;

  CATPolyPPConfigurationChecker::CollisionType RunClashOperator(CATPolyInterferenceOper &iclashOper, CATBVHTreeSet &iScene, CATBVHTreeSet &iMove,CATIPolyInterfInputCoupleFilter*iFilter=nullptr);
  CATPolyPPConfigurationChecker::CollisionType RunSelfClashOperator(
    CATPolyInterferenceOper &iclashOper, CATBVHTreeSet &iMove,
    CATIPolyInterfInputCoupleFilter &iFilter);
};

/**   @} */
#endif
