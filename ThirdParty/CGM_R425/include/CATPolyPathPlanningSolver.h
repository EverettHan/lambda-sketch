// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPathPlanningSolver.h
//
//===================================================================
//
// Usage notes: The nD Path Planning solver interface. It allows to
// define two configurations as the start and the target
// configurations, then to find a path between these two
// configurations by a list of intermediate valid configurations.  A
// valid configuration is the position of one or several objects such
// that they aren't in clash with any other object.
//
//===================================================================
//
// 2013-01-11 XXC: Creation
// 2013-09-12 JXO: Callback for user feedback
// 2013-10-07 JXO: Distance queue for better search of closest point
// 2015-08-26 JXO: Capture observer
// 2018-08-10 JXO: Config space is now refcounted.
//===================================================================

#ifndef CATPolyPathPlanningSolver_HH
#define CATPolyPathPlanningSolver_HH

#include "CATPolyDeprecated.h"
#include "PolyPathPlanning.h"

// Poly
#include "CATDynamicKDTree.h"
#include "CATPolyDebugPathPlanningTraces.h"
#include "CATPolyPPConfigurationChecker.h"
#include "CATPolyPPRRT.h"
#include "CATPolyPPRRTNode.h"
#include "CATPolyPathPlanningObserver.h"
#include "CATPolyPathPlanningSolverCallback.h"
#include "CATRefCounted.h"

// System
#include "CATSysErrorDef.h"
#include "DSYSysJSON.h"
//#include "CATPolyPPSteeringOperator.h"

class CATPolyPathPlanningSolverPositionsQueue;
class CATPolyPPTopologicalPoint;
class CATPolyPPTopologicalSpace;
class CATPolyPPCartesianProduct;
class CATPolyPPPath;
class CATPolyPPDefinition;
class CATPolyPPPosition;


class CATPolyPPManualExpander;
class CATPolyPPTreeBuilder;
class TaskRunNextPoint;
class CATPolyPPSteeringOperator;

#ifdef ENABLE_PP_MT
class RRTThread;
#include <atomic>
#include <condition_variable>
#include <vector>
#endif
#include <mutex>
#include <string>

#include "CATPolyThreadPool.h"

#include "CATMathTransformation.h"
#include "CATPolyLittleTimer.h"

/**
 *  The nDimension Path Planning solver interface .
 *
 *  Allows to solve a given path planning problem. The problem is
 *  defined from a CATPolyPPDefinition which includes a start and
 *  target configurations, possibly somme check points or black hole
 *  intermediate configurations (see CATPolyPPDefinition and
 *  CATPolyPPPosition). This solver will try to find a path between
 *  these two configurations by a list of intermediate valid
 *  configurations such that the segment between two following
 *  configurations is free according to the precision of the given
 *  CATPolyPPConfigurationChecker.
 *
 * @section PPSolverHowToUseIt How to use it ?
 * - @ref PPTutoExplain
 *
 * Instanciate a solver with a checker:
 * @snippet PPTutoMain.cpp PPSolverSetup
 * Config the solver options:
 * @snippet PPTutoMain.cpp PPSolverConfig
 * Execute until a path is found:
 * @snippet PPTutoMain.cpp PPSolverRun
 * @image html bidir.gif
 */
class ExportedByPolyPathPlanning CATPolyPathPlanningSolver
{
  public:
  /** Constructor for the path planning solver operator.
   *  The collision checker is given in the contructor making the solver dependant
   *  of the collision checker. The parameters for the checker can
   *  always been modified after the solver construction.
   * @param iChecker
   *    The collision checker that checks if a
   *    configuration or a segment in the configuration space is valid or
   *    not in term of collisions between the moving objects and the
   *    obstacles.
   */
  CATPolyPathPlanningSolver(CATPolyPPConfigurationChecker &iChecker);

  virtual ~CATPolyPathPlanningSolver();

  CATPolyPPConfigurationChecker &GetChecker() const { return _Checker; };

  /**
   * temporary api to activate the merge of the MultiThread/MonoThread code
   *
   * */
  void SetMonoCodeMode(bool iEnable = true);

  /** Initialize the operator for a new run.
   *  Deletes inner data as the path if it exists, with the exception of the problem
   *  definition and other option values.
   */
  HRESULT Reset();

  /** Sets the definition CATPolyPPDefinition of the problem.
   *  That is the start and target configurations of the path to solve. The definition given is
   *  deleted by the solver.
   * @param iDefinition
   *        pointer to the structure defining the problem
   *        to solve.
   */
  HRESULT SetProblemDefinition(CATPolyPPDefinition *iDefinition);
  CATPolyPPDefinition *GetProblemDefinition() const;

  /** Main method to call the path solver execution.
   *  It proceed step by step. Each time it is called, it try to add some predefined
   *  samples and try to grow the tree with these samples. The code
   *  returned indicates if the step succeeded or failed and, if it
   *  succeded, if a path was found or not.
   * @return S_OK if the step succeeded and managed to find a path
   * between the start and target configurations, S_FALSE if it
   * succeeded but without finding a path, E_FAIL or any error code if
   * it failed.
   */
  HRESULT RunStep();

  /**
   * @brief Run multi-threaded solver
   * @param iTimeout
   *        in milliseconds, waits until the timeout is reach or a solution is found
   * @return S_OK if the step succeeded and managed to find a path
   * between the start and target configurations, S_FALSE if it
   * succeeded but without finding a path, E_FAIL or any error code if
   * it failed.
   */
  HRESULT RunMT(unsigned iTimeout = 200);

  /**
   *	@brief Stop all running threads
   *    Solver could be resumed by calling RunMT
   */
  void Stop();
  void Join(); // wait end of RunMT

  /**
   *	@brief Define an unique seed for each thread
   * @param iSeed
   *         Seed to init the random generator
   */
  void ResetRNG(unsigned iSeed);

  /**
   *	@brief Call this method when the solvers and the bvh tree sets have changed.
   */
  void ResetThreads();

  /** @nodoc */
  void SetRRTThread(unsigned iRRT, unsigned iDDRRT);
  void SetDDRRTOnlyHullRatio(double iRatio = 0.5);

  /** Returns the path found by the solver between the start and
   *  target configurations. The path is deleted by the solver when it
   *  is reset or deleted. You have to copy it if you want to save it
   *  after the solver reset or deletion.
   * @return A pointer to a path CATPolyPPPath that joins the start
   * and target configurations of the moving objects without clashes
   * with the obstacles (according to the collision checker
   * precision). If this pointer equals to NULL this means no path was
   * found between the two configurations. A non null pointer can also
   * be a partial path between the start and an intermediate
   * configuration. The path is complete only when the RunStep method
   * returns S_OK.
   */
  CATPolyPPPath *GetResultingPath();

  /** Sets a callback for visualization  / logging / debugging purposes */
   POLY_DEPRECATED("Do not use  SetCallBack(CATPolyPathPlanningSolverCallback *pCallBack).  Replace instead by SetCallBack(CATPolyPathPlanningSolverCallback::SPtr & pCallBack).",
  void SetCallBack(CATPolyPathPlanningSolverCallback *pCallBack));
  void SetCallBack(CATPolyPathPlanningSolverCallback::SPtr & pCallBack);

  /**
   *  Manually adds a point in the RRT tree.
   *  It tries to expand the tree to this position like a random shot would do, using the precision factor, and returns the last valid position found.
   * @param iPos
   *  Position to test
   * @param iPrecisionDistanceFactor
   *  If set to a positive value, will use it. If not, will use last the defined positive precision distance factor
   * @param iParent 
   *  the parent to use if it is nullptr internal choice (likely nearest) will select parent from current tree
   * @return [out, IUnknown#Release]
   *  Last free position added to the tree, to be released by caller.
   */
  CATPolyPPPosition *ManualyExpandTree(CATPolyPPPosition *iPos, double iPrecisionDistanceFactor = -1., CATPolyPPRRTNode* iParent = nullptr);
  void ManualExpandingHelper(CATPolyPPPosition *iPos);

  /**
   * Configure the number of test by Run.
   * The tree generate by the solver will try to create iNbShotsPerStep new branch each
   * time the RunStep is called.
   * @param iNbShotsPerStep
   *        number of branch to create
   */
  INLINE void SetShotsNumberPerStep(unsigned int iNbShotsPerStep) { _ShotsPerStep = iNbShotsPerStep; }
  INLINE unsigned int GetShotsNumberPerStep() { return _ShotsPerStep; }

  /**
   * For debug only.
   */
  POLY_DEPRECATED("2022:Do not use GetStartRRT.  Replace instead by GetStartRRTSPtr.",
                  INLINE const CATPolyPPRRT *GetStartRRT()) { return _RandomTreeStart.get(); }
  CATPolyPPRRT::SPtr &GetStartRRTSPtr();
  /**
   * For debug only.
   */
  POLY_DEPRECATED("2022:Do not use GetTargetRRT.  Replace instead by GetTargetRRTSPtr.",
                  INLINE const CATPolyPPRRT *GetTargetRRT()) { return _RandomTreeTarget.get(); }
  CATPolyPPRRT::SPtr &GetTargetRRTSPtr();

  // Options

  /**
   * control how the tree is generated
   */
  enum DirectionMode
  {
    Monodirectional, //<! build a tree from the Start Point and go to the Target
    Bidirectional,   //<! build 2 tree, one from the Start and one from target and try to connect it
    Automatic        //<! the solver decide between Monodirectional and Bidirectional
  };

  /**
   * Control how a branch is created by the solver.
   */
  enum Steering
  {
    NoSteering = 0,             //<! don't change the point selected by the solver
    SimpleSteer = 1,            //<! Cut the branch if it is biffer that some distance @see SetSteeringDistance
    CutAndGo = 2,               //<! split the branch (generate more dense tree )
    ExternalSteerinOperator = 3 //<! the point to test selected by the solver can be modify by user callback @see SetSteeringOperator
  };

  /**
   * Control which strategy the solver will use to extend the tree.
   */
  enum ExtensionMode
  {
    None = 0,             //<! pick random point and connect it the nearest branch in tree
    DDRRT = 1,            //<! Dynamic-Domain RRT , try to grow the tree on contact space
    NodeNeighborhood = 2, //<! select random node of the tree , then try to create a new branch with a maximun lenght @see SetSteeringDistance

    // don't use !!
    IterativeRetraction = 4, //<! @deprecated not used
    ObstacleRetraction = 8,  //<! @deprecated not used
    ADDRRT = 17              //<! @deprecated not used 16 + 1 because ADDRRT includes DDRRT
  };

  /**
   * enum that evaluate the current difficulty to grow the tree.
   */
  enum DifficultyEvaluation
  {
    NotDefined = 0,
    OverEasy = 1,
    Easy = 2,
    Medium = 3,
    Hard = 4,
    Critical = 5
  };

  /**
   * Configure how the branch size of the tree will be generated
   * @param iSteeringMethod
   *        the Method of steering @see Steering
   */
  INLINE void SetSteeringMethod(Steering iSteeringMethod) { _Steering = iSteeringMethod; }
  INLINE Steering GetSteeringMethod() { return _Steering; }

  /**
   * Configure how the tree will grow
   * @param iExtensionMode
   *        the mode of extension  @see ExtensionMode
   */
  INLINE void SetExtensionMethod(ExtensionMode iExtensionMode) { _Extension = iExtensionMode; }
  INLINE int GetExtensionMethod() { return _Extension; }

  INLINE void SetRatioToTryTarget(int iRatioToTryTarget) { _RatioToTryTarget = iRatioToTryTarget <= 0 ? 1 : iRatioToTryTarget; }
  INLINE int GetRatioToTryTarget() { return _RatioToTryTarget; }

  /**
   * Configure the steering distance that can limit the length of the branch of the tree
   * @param iSteeringDistance
   *        max length of the branch
   */
  INLINE void SetSteeringDistance(double iSteeringDistance) { _SteeringDistance = iSteeringDistance; }
  INLINE double GetSteeringDistance() const { return _SteeringDistance; }

  /**
   * if SetExtensionMethod is ExternalSteerinOperator the provided iSteerOp will be used to "Steer"  the point.
   * @param iSteerOp
   *        Steering operator
   */
  void SetSteeringOperator(CATCGMSharedPtr<CATPolyPPSteeringOperator> &iSteerOp);
  const CATCGMSharedPtr<CATPolyPPSteeringOperator> &GetSteeringOperator() const;

  /**
   * Choose whether the search is mono or bidirectional, or automatic.
   * - Mono-directional works well with multithread and guiding path.
   * - Bidirectional works well with multithread, but does not work with guiding path.
   * - Automatic works only in mono-thread, and does not work with guiding path.
   */
  INLINE void SetBidirectionalSolving(DirectionMode iBidirectional)
  {
    _BidirectionalMode = iBidirectional;
    if (_BidirectionalMode == Monodirectional)
      _Bidirectional = FALSE;
    else
      _Bidirectional = TRUE;
  }
  INLINE DirectionMode GetBidirectionalSolving() { return _BidirectionalMode; }

  /**
   * work in progress : return the current difficulty .
   */
  INLINE DifficultyEvaluation GetDifficulty() const { return EvaluateDifficultyFromData(); }

  const CATPolyPPConfigurationChecker &GetConfigurationChecker() const;

  POLY_DEPRECATED("2022:Do not use  SetObserver(CATPolyPathPlanningObserver *ipObs).  Replace instead by SetObserver(CATPolyPathPlanningObserver::SPtr &ipObs)",
  void SetObserver(CATPolyPathPlanningObserver *ipObs));
  void SetObserver(CATPolyPathPlanningObserver::SPtr &ipObs);

  /**
   * @brief enable deported delete
   * @remarks must be use carefully !!!
   * */
  void ActiveDeportedDelete();

  /**
   * Interface to specify a function that compute the cost of a segment, the cost can be different of the distance function.
   * This function is used to search an optimal path relative to this cost function
   * */
  class ExportedByPolyPathPlanning CATPolyPPCostFunction : public CATPolyRefCounted
  {
public:
    /**
     * Must return the cost of the segment that go from iConfig1 to iConfig2
     * @param iConfig1: the first configuration of moving objects.
     * @param iConfig2: the second configuration of moving objects.
     * @return the cost of the segment (>=0)
     */
    virtual double Cost(const CATPolyPPPosition &iConfig1, const CATPolyPPPosition &iConfig2);

    typedef CATCGMSharedPtr<CATPolyPPCostFunction> SPtr;

    ~CATPolyPPCostFunction();
  };

  typedef struct ExportedByPolyPathPlanning PPRRTStarParameters_st
  {
    PPRRTStarParameters_st();
    bool enable = false;
    bool enableRewire = false;                          // if false the rewire step will not be sone , the path is less optimal but it is quicker
    CATPolyPPCostFunction::SPtr CostFunction = nullptr; // CATPolyPPCostFunction::SPtr(new CATPolyPPCostFunction());
    int nbNearToLook = 8;                               // the number of near node looked to optimize a new branch ( or rewire )
  } PPRRTStarParameters;

  void SetRRTStarParameters(const PPRRTStarParameters &iParameters);
  PPRRTStarParameters GetRRTStarParameters() const;

  /**
  * put the data of this solver into jsondata for debug it later
  */
  DSYSysJSONValue ToJson(std::string BaseFilename="");
  
  private:
  /**
   * add branch to tree from user defined edge of the CATPolyPPDefinition
   * */
  void PreGrowTree(CATPolyPPRRT &ioRRT);

  HRESULT GetNodeAndDirection(CATPolyPPRRT &iRRT, CATPolyPPRRTNode *&oFrom, CATPolyPPPosition *&oTo);
  void GetDDRRT(CATPolyPPRRT &iRRT, CATPolyPPRRTNode *&oFrom, CATPolyPPPosition *&oTo);
  void GetNodeNeighborhood(CATPolyPPRRT &iRRT, CATPolyPPRRTNode *&oFrom, CATPolyPPPosition *&oTo);

  HRESULT RunOneStep();

  CATPolyPPPosition *ExtendRRT(CATPolyPPRRT &iRRT, CATPolyPPRRTNode *iNearest, CATPolyPPPosition *iNewConfiguration, int &oCptExtensions, int &oExt_success, double iRatio);

  CATPolyPPPosition *RetractTo(CATPolyPPRRT &iRRT, CATPolyPPRRTNode *iNearest, CATPolyPPPosition *iNewConfiguration, double iRatio);

  CATPolyPPPosition *Steer(const CATPolyPPPosition *iNearest, CATPolyPPPosition *iNewConfiguration, double iRatio);

  void GenerateMinimumsOverLocalContactSpace(CATPolyPPPosition *iNearest, CATPolyPPPosition *iNewconfiguration, CATListPV &iConfigsToAdd, double iRatio);
  CATPolyPPPosition *GenerateConfigurationOverLocalContactSpace(CATPolyPPPosition *iConfiguration, const CATPolyPPPosition *iTarget, double iRatio);

  void InitRRTThread();
  HRESULT InitRRTrees();
  HRESULT MakePath();

  HRESULT RepairPath();
  HRESULT RepairConfiguration(CATPolyPPPosition *iConfiguration);
  HRESULT RepairSegment(int iIdx);

  
  private:
  DirectionMode _BidirectionalMode;
  CATBoolean _Bidirectional;

  unsigned int _ShotsPerStep;

  unsigned int _Counter;
  int _RatioToTryTarget;

  double _SteeringDistance;
  double _NeighborhoodDistance;
  double _AttractionTolerance;

  CATPolyPPConfigurationChecker &_Checker;
  CATPolyPPDefinition *_ProblemToSolve;
  const CATPolyPPCartesianProduct *_ConfigSpace;

  CATPolyPPRRT::SPtr _RandomTreeStart, _RandomTreeTarget;
  CATPolyPPPosition *_Start;
  CATPolyPPPosition *_Target;
  CATPolyPPManualExpander *_ManualHelper;
  CATBoolean _ManualExpansion;

  CATPolyPPRRT::SPtr _tree1, _tree2;

  int _RepairedPath;
  CATPolyPPPath *_Path;

  CATPolyPathPlanningSolverCallback::SPtr m_CallBack;

  private:
  // Options
  Steering _Steering;
  CATCGMSharedPtr<CATPolyPPSteeringOperator> _SteeringOperator; // will be used if Steering is CATPolyPathPlanningSolver::ExternalOperator
  ExtensionMode _Extension;
  CATPolyPathPlanningSolverPositionsQueue *m_pTreeToTargetQueue;

  DEBUGPATHPLANNINGOBJECTTRACE(m_traces);

  private:
  // Difficulty evaluation
  void EvaluateDifficultyFromData(int &ioCptExtensions, int &ioExt_success, double *ioValues, double &oSteerRatio, int &oDifficulty);
  DifficultyEvaluation EvaluateDifficultyFromData() const;
  void ExchangeData();

  int _Difficulty1, _Difficulty2, _Difficulty;
  int _CptExtensions_1, _CptExtensions_2, _Ext_success_1, _Ext_success_2;
  double _Values_1[10], _Values_2[10];
  double _SteerRatio_1, _SteerRatio_2;
  CATPolyPathPlanningObserver::SPtr m_pObserver;
#ifndef CATIAR425 
  bool _monoCode = false;
#else
  bool _monoCode = true;
#endif

  void CleanThreads();

#ifdef ENABLE_PP_MT

  friend class RRTThread;
  friend class DDRRTThread;

  std::vector<RRTThread *> m_Threads;
  std::atomic<bool> m_aDone;
  bool m_Done;
  std::condition_variable m_CV;
  std::mutex m_CVM;

  RRTThread *m_ManualThread;


  std::mutex m_ClashMutex;
  std::atomic<int> m_nbCLashOriginalInUse;
#endif

  bool m_ThreadsInitialized;
  bool m_Running;

  unsigned m_SlicingAxis;

  unsigned m_DDRRTThreads;
  unsigned m_RRTThreads;
  double m_DDRRTThreads_FullHullRatio = 0.5;

  CATPolyPPTreeBuilder *_pBuilder = nullptr;
  std::vector<CATPolyPPTreeBuilder *> _ThreadBuilder;
  std::vector<TaskRunNextPoint *> _Tasks;
  CATPolyThreadPool _ThreadPool;
  CATPolyLittleTimer _RunMTTimer;

  CATPolyThreadPool *_DeportedDelete = nullptr;

  // activation variable
  std::string PPValidTarget_var = std::string("");

  PPRRTStarParameters _RRTStarParams;

  bool _firstRun = true;
};


#endif
