// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPConfigurationChecker.h
//
//===================================================================
//
// Usage notes: Abstract checker that test for collisions between
// configurations of an assemmbly and the remaining
// scene. Implementations must implement the positioning of the
// assembly according to the corresponding given
// configurations/positions.
//
//===================================================================
//
// 2013-02-08 XXC: Creation
// 2013-09-12 JXO: Cast methods for Phoenix
// 2015-12-07 JXO: Added FilteredOut status enum, and RemoveFilter method
//===================================================================

#ifndef CATPolyPPConfigurationChecker_HH
#define CATPolyPPConfigurationChecker_HH

#include "PolyPathPlanning.h"
#include "CATPolyRefCounted.h"
#include "CATPolyOBB.h"

#include "CATPolyPathPlanningSolverCallback.h"


class CATPolyPPPosition;
class CATBVHTreeSet;
class CATPolyAssemblyPathPlanning3DChecker;
class CATPolyPPRobotChecker;
class CATPolyPPConfigurationFilter;
class CATMathTransformation;
class CATPolyPPCartesianProduct;
class CATPolyPPPath;

// Poly Math
#include "CATPolyObserver.h"

// Math
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATErrorDef.h"



#ifdef _AIX_SOURCE
#undef throw
#undef try
#undef catch
#endif

#include <vector>
#include <atomic>

#ifdef _AIX_SOURCE
#define throw ERROR
#define try ERROR
#define catch ERROR
#endif


#include "CATPolyPPTimeEvaluator.h"


class CATPolyPPRRTNode;

/** Class defining the Configuration Checker interface. It defines all
*  the data shared by the various effective implementation of any
*  configuration checker and that are used by the path smoother
*  CATPolyPPPathSmoothing and the path solver
*  CATPolyPPPathSolver. Various implementations of a checker just
*  has to implement the method TestConfiguration that check for
*  collisions between moving objects which positions are defined by
*  the given configuration and static obstacles.
*/
class ExportedByPolyPathPlanning CATPolyPPConfigurationChecker : public CATPolyRefCounted
{
public:
  typedef CATCGMSharedPtr<CATPolyPPConfigurationChecker> SPtr;
  enum LevelOfDetail {
    UserDefined,
    Low,
    Medium,
    High
  };

  enum CollisionType {
    Free = 0, /**< No collision, no contact */
    WithinTolerance = 1, /**< Contact. No collision but the objects are close from each others, the distance between them is within the defined tolerance. */
    Allowed = 2, /**< Collisions but the penetration depth is fewer than a depth limit value */
    Rejected = 3, /**< Deep collisions */
    FilteredOut = 4, /**< Filtered out by any user filter */
    Error = 5 ,/**< Error status */
    Interrupted = 6 /**< only on mutithread when we interupte the validation of a segment (because other thread have found a solution)*/
  };

  /** Data associated to a collision */
  class ExportedByPolyPathPlanning Collision
  {
  public:
    Collision(CollisionType iType = Error);
    CollisionType m_type;
    double m_depth;
    double m_minimumdistance;
    double m_intersectionvolume;
    /** Returns the type of the collision */
    int m_IdFirstObject=-1;
    int m_IdSecondObject=-1;
    CATMathPoint m_clashPoint; //only valid if m_depth>0
    operator CollisionType ();
  };

public:
  CATPolyPPConfigurationChecker();

  CATPolyPPConfigurationChecker( const CATPolyPPConfigurationChecker& iOther );

  /**
   * @brief must be override by child class 
   * */
  virtual bool IsA(const char * iClassName) const ;

  /** Defines the level of precision of the interpolation between two
  *  positions used to test collisions along a segment of positions.
  * @param iLevel: The level of precision amongst explicit values Low,
  * Medium and High. The UserDefined value is ignored, see
  * SetPrecisionDistanceFactor to set a user defined value of
  * precision.
  */
  void SetPrecisionLevel(LevelOfDetail iLevel);
  /** Get the level of precision used inside the Checker of
  *  collisions.
  * @return The level of precision amongst values UserDefined, Low,
  * Medium and High. UserDefined is returned if an explicit double
  * value for the precision has been set by the user (see
  * SetPrecisionDistanceFactor).
  */
  LevelOfDetail GetPrecisionLevel() const;

  /** Factor combined to the object scale (see SetDistanceScale) to
  *  determine the precision of the interpolation in term of segment
  *  length. If iScale is the object scale, the maximum length
  *  between two interpolations will be iStepLength*iScale. Setting
  *  this parameter manually from this method discards the level set
  *  with method SetPrecisionLevel and set the level to UserDefined.
  * @param iStepLength: the length factor.
  */
  void SetPrecisionDistanceFactor(double iStepLength);
  /** Get the precision factor corresponding to the level of
  *  precision.
  * @return The precision factor.
  */
  double GetPrecisionDistanceFactor() const;

  /** Define the scale of the moving object(s). Defining this scale
  *  allows the precision for the interpolation between two
  *  configurations to depends on the size of the object. Thus, any
  *  precision level remains stable according to the size of the
  *  object.
  * @param iScale: the object distance scale.
  */
  void SetDistanceScale(double iScale);
  /** Get the object distance scale.
  * @return The object distance scale value.
  */
  double GetDistanceScale() const;

  /** Retrieves the distance between two interpolations when checking
  *  the freeness of a segment of positions. This distance is valued
  *  according to both the scale and the precision factor. To reduce
  *  the step, one can reduce the precision factor with
  *  SetPrecisionLevel, or SetPrecisionDistanceFactor for a user
  *  defined value. When using the CDIST algorithm to compute
  *  distances in the configuration space, it corresponds to the
  *  maximal mouvement between two interpolated positions. This
  *  distance can then be used as a clearance value to assert the
  *  moving object does not collide with the obstacles, even between
  *  two interpolated positions.
  */
  double GetInterpolationStep() const;

  /** Add a filter to the configuration checker. A filter allows to
  *  restrain the scope of valid configurations in addition to the
  *  standard limits defined in the configuration space.
  *  Any number of filters can be added, according to the
  *  requirements.
  *@return S_OK upon success, E_FAIL otherwise.
  */
  HRESULT AddFilter(CATPolyPPConfigurationFilter * iFilter);
  /** Removes a previously added filter */
  HRESULT RemoveFilter(CATPolyPPConfigurationFilter * iFilter);
  /** Remove all filters and destroy them is required */
  void RemoveAllFilters( CATBoolean iDestroy = 0 );

  /**
   * Get the current list of filters
   * */
  std::vector<CATPolyPPConfigurationFilter *> GetFilters() const;

  void SetFilterGuidingSegment( const int iSegment );

  void SetRetraction();
  void UnsetRetraction();

  /** Test for collisions between moving objects and obstacles for a
  *  particular configuration of the moving objects.
  * @param iConfig: the configuration determining the position of the
  * moving objects.
  * @param iStatus: force penetration computation using distance min
  * when an offset is performed on the moving object.
  * @return A collision status amongst Free (no clash), Allowed (in
  * contact), WithinTolerance (clash with depth within the allowed
  * tolerance), Rejected (real clashes), FilteredOut (user filter),
  * Error (something's gone wrong).
  */
  virtual Collision TestConfiguration(const CATPolyPPPosition & iConfig, CATBoolean iStatus = 0) = 0;

  /** Test collisions for a segment of configurations. Uses the
  *  precision level and the distance scale to interpolate the
  *  segment between the two given configurations. Return the test
  *  result for each interpolated configuration and the number of
  *  interpolation. The given start and end configurations are not
  *  checked, only the interpolated configurations between them are.
  * @param iConfig1: the first configuration of moving objects.
  * @param iConfig2: the second configuration of moving objects.
  * @param oNbTests: out parameter, set to the number of interpolated
  * points computed between the two configuration iConfig1 and
  * iConfig2. This number is computed from the distance between the
  * two given configurations, the scale defined and the precision
  * level.
  * @return An array of oNbTests collision status for each computed
  * interpolated configuration.
  */
  virtual CollisionType* TestConfigurations(const CATPolyPPPosition & iConfig1, const CATPolyPPPosition & iConfig2, unsigned int oNbTests);

  /** Test collisions for a segment of configurations. Uses the
  *  precision level and the distance scale to interpolate the
  *  segment between the two given configurations. Returns the test
  *  result of the first rejected test to verify a possible error.
  *  The given start configuration is not checked and is supposed
  *  valid. If every interpolated configurations are valid, the end
  *  configuration (iConfig2) is checked. If it is valid,
  *  oLastValidPosition points to iConfig2 and the collision type
  *  returned is a valid type (free, within tolerance or allowed).
  * @param iConfig1: the first configuration of moving objects.
  * @param iConfig2: the second configuration of moving objects.
  * @param oLastValidPosition: the last valid interpolated
  * configuration starting from iConfig1, ending to iConfig2.
  * To be released by caller.
  * @param iCDIST if true use the distance operator provided by the user in the constructor CATPolyPPConfigurationDistance
  * @return The first invalid collision status to detect if an error
  * occured.
  */
  virtual CollisionType TestConfigurations(const CATPolyPPPosition & iConfig1, CATPolyPPPosition & iConfig2, CATPolyPPPosition *& oLastValidPosition, bool iCDIST = true);

  /**
  * @brief Same as TestConfigurations except a cache of position is used to compute interpolations
  * Space is not taken from positions parameters but given as argument instead (more suited for multi-thread)
  *
  * @param iSpace
  * @param iConfig1
  * @param iConfig2
  * @param oLastValidPosition
  * @param iCDIST
  *
  */
  virtual CollisionType TestConfigurationsCached(CATPolyPPCartesianProduct& iSpace, const CATPolyPPPosition & iConfig1, CATPolyPPPosition & iConfig2, CATPolyPPPosition *& oLastValidPosition, bool iCDIST = true);

  /** Test collisions for a segment of configurations. Uses the
  *  precision level and the distance scale to interpolate the
  *  segment between the two given configurations. Returns a status
  *  for the whole segment. The given start and end configurations
  *  are not checked, only the interpolated configurations between
  *  them are. Interpolated configurations are tested in a sequential
  *  order from the first configuration following iConfig1 to the
  *  last just before iConfig2.
  * @param iConfig1: the first configuration of moving objects.
  * @param iConfig2: the second configuration of moving objects.
  * @return The status indicating if the whole segment is free of
  * collisions or not. The status is FilteredOut, Rejected,
  * WithinTolerance, Allowed or Free in this order of priority 
  * if at least one interpolated point has this status.
  */
  virtual CollisionType TestConfigurations(const CATPolyPPPosition & iConfig1, const CATPolyPPPosition & iConfig2);

  /** Test collisions for a segment of configurations. Uses the
  *  precision level and the distance scale to interpolate the
  *  segment between the two given configurations. Returns a status
  *  for the whole segment. The given start and end configurations
  *  are not checked, only the interpolated configurations between
  *  them are. Interpolated configurations are tested in a dichotomic
  *  order.
  * @param iConfig1: the first configuration of moving objects.
  * @param iConfig2: the second configuration of moving objects.
  * @return The status indicating if the whole segment is free of
  * collisions or not. The status is FilteredOut, Rejected,
  * WithinTolerance, Allowed or Free in this order of priority 
  * if at least one interpolated point has this status.
  */
  virtual CollisionType FastTestConfigurations(const CATPolyPPPosition & iConfig1, const CATPolyPPPosition & iConfig2);

  /** Debug */
  virtual CATPolyAssemblyPathPlanning3DChecker * CastToAssemblyChecker() {return 0;}
  /** Debug */
  virtual const CATPolyAssemblyPathPlanning3DChecker * CastToAssemblyChecker() const {return 0;}

  /** Debug */
  virtual CATPolyPPRobotChecker * CastToRobotChecker() {return 0;}
  /** Debug */
  virtual const CATPolyPPRobotChecker * CastToRobotChecker() const {return 0;}

  virtual CATPolyPPConfigurationChecker* Clone() const;

  virtual void InitCache( CATPolyPPCartesianProduct & space, unsigned iSize = 2048u ) ;

  double GetSteeringDistance(){return m_SteeringDistance;}

  void SetConfigurationCallBack(CATPolyPathPlanningSolverCallback::SPtr &pcallback);
  CATPolyPathPlanningSolverCallback::SPtr & GetConfigurationCallBack();

  /***
   * @brief only usefull in multithread mode, call this function to interrupted quicker the current TestConfigurations
   * @param iInterrupt by default true to stop a validation , must be put to false to reset the checker for new usage.
   * */
  virtual void InterruptSegmentTest(bool iInterrupt=true);
  
  virtual ~CATPolyPPConfigurationChecker();

  //Helper
  /**
   * Create a path with all the interpolate points of this path based on the configuration of this checker
   * should be delete by caller.
  */
  CATPolyPPPath * InterpolatePath(CATPolyPPPath & iPath,bool iCDIST=true);


protected:



  /** Filter a configuration. @see CATPolyPPConfigurationFilter and
  *  method @see AddFilter for more details on filters.
  * @param iConfig: the transformation to apply to the moving objects.
  * @return TRUE if the configuration passed through the filters,
  * that is to say it is in the scope of the scenario, FALSE if it is
  * out of the scope.
  */
  CATBoolean FilterConfiguration(const CATMathTransformation & iConfig);

  /**
  *	mutex not needed since modifications are always done before Running
  *    Data race can't happen.
  */
  class PPCheckerObserver
  {
  public :
    PPCheckerObserver( CATPolyPPConfigurationChecker& iChecker );

    HRESULT AddFilter(CATPolyPPConfigurationFilter * iFilter);

    HRESULT RemoveFilter(CATPolyPPConfigurationFilter * iFilter);

    void SetDistanceScale(double iScale);

    void SetPrecisionDistanceFactor(double iStepLength);

  private :

    CATPolyPPConfigurationChecker& m_Checker;
  };

  void RegisterObserver( PPCheckerObserver* ipObserver );
  void UnregisterObserver( PPCheckerObserver* ipObserver );

  void DestroyObservers();

  friend class CATPolyPathPlanningSolver;

public:
  class TestObserver : public CATPolyObserver<TestObserver>
  {
  public:
    virtual void TestedConfiguration(const CATPolyPPPosition & iConfig, Collision & oCol) = 0;
  protected:
    TestObserver(){}
    ~TestObserver(){}
  };
  void RegisterTestObserver(TestObserver * to);
  void UnregisterTestObserver(TestObserver * to);
  enum DirectionInBiDirectionalSearch
  {
    BACKWARD_IN_BI_DIR_SEARCH = -1,
    FORWARD_IN_BI_DIR_SEARCH = 1
  };

  inline void SetDirectionInBiDirSearch(DirectionInBiDirectionalSearch dir) { m_DirectionInBiDirSearch  = dir; }
  inline DirectionInBiDirectionalSearch GetDirectionInBiDirSearch() const { return m_DirectionInBiDirSearch; }

protected:
  double _SampleDistance;
  double _Scale;
  bool m_Cloned;
  CATPolyPathPlanningSolverCallback::SPtr m_CallBack=nullptr;

  std::vector<CATPolyPPConfigurationFilter*> _Filters;
  

protected:
  double _Retraction; // TODO: Actuellement g�r� dans
                      // CATPolyAssemblyPathPlanning3DChecker::TestConfiguration,
                      // dans un calcul de p�n�tration. Pas top ! De
                      // plus, quid de la sp�cification d'une distance
                      // de clearance si l'utilisateur ne veut pas
                      // trop s'approcher des objets dans la
                      // r�solution de chemin ?

  std::vector< PPCheckerObserver* > m_Observers;

  std::vector< CATPolyPPPosition* > m_PosCache;

  TestObserver * m_to;
  double m_SteeringDistance;
  DirectionInBiDirectionalSearch  m_DirectionInBiDirSearch; // QIF: indicator for forward direction in bi-directional search.
  int m_nbSample=-1;
  int m_currentSampleIdx=-1;

  int m_currentNbBranch=0;
  std::atomic<bool> _InterruptSignal;//invalid in macos = false;
  const CATPolyPPRRTNode * _CurrentParentNode = nullptr;

  CATPolyPPTimeEvaluator::SPtr _TimeEvaluator;
  
public:
  CATPolyOBB m_objectobb;
};

#endif
