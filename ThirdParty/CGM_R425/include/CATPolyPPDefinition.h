// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPDefinition.h
//
//===================================================================
//
// Usage notes: Container defining the input data of a Path Planning
// problem to be solved, as the start and target positions, also
// defining the space of positions (configuration space) and other
// options values.
//
//===================================================================
//
// 2013-01-09 XXC: Creation
// 2013-10-30 XXC: InsertNewBlackHole
// 2015-09-18 JXO: Capture Observer
//===================================================================

#ifndef CATPolyPPDefinition_HH
#define CATPolyPPDefinition_HH

#include "PolyPathPlanning.h"
#include "CATMathInline.h"
#include "CATPolyPPPath.h"
#include "CATPolyPPPosition.h"
#include "CATPolyDeprecated.h"
#include "CATPolyPPTargetDefinitionBase.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

#include "CATMathPoint.h"
#include "CATMathBox.h"

#include "CATCGMSharedPtr.h"

#ifdef ENABLE_PP_MT
#include <atomic>
#include <mutex>
#endif

#ifdef _AIX_SOURCE
#undef throw
#undef try
#undef catch
#endif

#include <vector>
#include <map>

#ifdef _AIX_SOURCE
#define throw ERROR
#define try ERROR
#define catch ERROR
#endif

class CATPolyAssemblyPathPlanning;

class CATPolyPPCartesianProduct;
class CATPolyPPPosition;
class CATPolyPPDefinitionObserver;
class CATMathTransformation;
class CATPolyPPConfigurationChecker;


/** Container defining the input data of a Path Planning problem to be
 *  solved. It contains, among other options, the start and target
 *  configurations and also the list of intermediates
 *  configurations. Intermediates confugrations are intermediate
 *  ordered positions that "drive" the solver to find the path from
 *  the start configuration to the target configuration. An
 *  intermediate position can be of two type : CheckPoint, that is a
 *  configuration through which the moving object must pass, or
 *  BlackHole, that is a configuration that acts as an attractive
 *  point. As a consequence, the CheckPoint configuration will be
 *  contained in the resulting pass while the BlackHole point will
 *  not.
 */
class ExportedByPolyPathPlanning CATPolyPPDefinition
{
public:
  /** Initialization of a Path Planning Definition with two
   *  configurations for the start and the target of the path to
   *  solve.
   * @param iStart: Starting configuration, the position of the moving
   * object at the beginning of the path to solve.
   * @param iTarget: Target configuration, the final position where
   * the moving object has to be dragged to.
   */
  CATPolyPPDefinition(CATPolyPPPosition * iStart, CATPolyPPPosition * iTarget);

  /** Initialization of a Path Planning Definition with a
   *  start configuration and a generic target definition.
   * @param iStart: Starting configuration, the position of the moving
   * object at the beginning of the path to solve.
   * @param iTarget: generic target definition 
   */
  CATPolyPPDefinition(CATCGMSharedPtr<CATPolyPPPosition> & iStart, CATCGMSharedPtr<CATPolyPPTargetDefinitionBase> & iTargetDefinition);


  ~CATPolyPPDefinition();

  /** Gets the start configuration.
   * @return The start configuration.
   */
  INLINE CATPolyPPPosition * GetStart() const;
  /**
  @deprecated please use a CATPolyPPTargetDefinitionBase validator (CATPolyPPTargetDefinitionSimple for same behavior)
   Gets the target configuration.
    @return The target configuration.
   */
  CATPolyPPPosition * GetTarget() const;

  CATCGMSharedPtr<CATPolyPPTargetDefinitionBase> GetTargetDefinition() const;

  /**
   * prepopulate the tree of path by inserting a branch.
   * iSegmentStart must already exist in the tree
   * can return E_FAIL if the segment is not free of collisions
   * @param[in] iSegmentStart 
   *    Start point 
   * @param[in] iSegmentEnd
   *    End point 
   * @param[in] iCheckerForValidity
   *    if you pass a checker the method will validate the segment and may reject if checker found collision, 
   *    if checker is nullptr the method will accept this segment without validation.
   * @return S_SUCCESS if the segment is inserted.
   */
  HRESULT InsertSegment(
    CATCGMSharedPtr<CATPolyPPPosition> iSegmentStart,
    CATCGMSharedPtr<CATPolyPPPosition> iSegmentEnd,
    CATCGMSharedPtr<CATPolyPPConfigurationChecker> iCheckerForValidity =nullptr);

  std::vector<std::pair<CATPolyPPPosition::SPtr,CATPolyPPPosition::SPtr>> GetInsertedSegments() const;
  /**
   * return the list of configuration that are connected by a direct segment (previously added with InsertSegment ) from iNodeConfiguration;
   * @param[in] iNodeConfiguration starting point of the edge to find
   * @return vector of CATPolyPPPosition if edge exist , empty vector otherwise 
   * */ 
  std::vector<CATCGMSharedPtr<CATPolyPPPosition>> GetUserEdgeFrom(CATCGMSharedPtr<CATPolyPPPosition> & iNodeConfiguration ) const;

  /** Add a black hole typed configuration just after the current
   *  intermediate target configuration. This insertion can be done
   *  during the iteration on intermediate targets. The inserted
   *  configuration is deleted by the class itself.
   */
  HRESULT InsertNewBlackHole(CATPolyPPPosition * iBlackHole);

  /** Append an intermediate configuration at the end of the list of
   *  intermediate target configurations. This configuration can be of
   *  type CheckPoint or BlackHole. See CATPolyPPPosition for more
   *  details about the configuration type. The added configuration is
   *  deleted by the class itself. Notice, the addition of an
   *  intermediate target must be done before any iteration on the
   *  list of intermediate points. Adding an intermediate target
   *  restart the iteration at the beginning. If one want to insert a
   *  new configuration at the place of the current intermediate
   *  target, one must use InsertNewBlackHole instead. Only black
   *  holes can be added during the iteration on the intermediate
   *  points.
   * @param iIntermediatePoint: the intermediate configuration on the
   * path to add at the end of the list of intermediate configuration.
   */
  HRESULT AppendIntermediateTarget(CATPolyPPPosition * iIntermediatePoint);

  // INLINE void SetSteeringRadius(double iRadius);
  // INLINE double GetSteeringRadius() const;

  /** Get the configuration space as a CATPolyPPCartesianProduct.
   * @param oConfigSpace: the out parameter to which the configuration
   * space is assigned.
   * @return S_OK if one was able to get the configuration space
   * without problems, E_FAIL otherwise (if the start and target are
   * not defined in the same space, as an example).
   */
  HRESULT GetConfigurationSpace(const CATPolyPPCartesianProduct *& oConfigSpace) const;

  /** For user purpose : get the current target without iterating on
   *  intermediate targets. The result can be a black hole, a check
   *  point or the final target, according to the point on which the
   *  solver is currently focusing on.
   */
  const CATPolyPPPosition * GetCurrentIntermediateTarget() const;


  /**
   * @brief Define guiding path anchor point ( see CATPolyAssemblyPPFilterPipe )
   * @deprecated
   *
   * @param iAnchor
   *
   */
  void SetGuidingPathAnchor( const CATMathPoint& iAnchor );

  /**
  * @brief Define guiding path anchor transformation ( see CATPolyAssemblyPPFilterPipe )
  *
  * @param iAnchor
  *
  */
  void SetGuidingPathAnchor( const CATMathTransformation& iAnchor );
  CATMathTransformation GetGuidingPathAnchor() const;

  /**
    @brief  return the anchor point as topological point.

    @remarks SetGuidingPathPlanner must be set
  */
  CATCGMSharedPtr<CATPolyPPPosition> GetGuidingPathAnchorConfiguration() const;

  /**
   * DEPRECATED. You should use the AddGuidingPath with CATMathTransformations instead
   * @brief Define a guiding path from the starting to the end position by pipe segments.
   * The guiding path will locally redefine problem limits to help computation.
   * To work correctly, a full path of segment must be defined from the start to the end.
   * @deprecated
   *
   * @param iStart   starting position of a guiding path segment
   * @param iEnd     end position of a guiding path segment
   * @param iRadius  radius of the guiding path segment
   * @param iPlanner the problem planner
   *
   */
   POLY_DEPRECATED("Use AddGuidingPath with CATMathTransformations instead.", HRESULT AddGuidingPath( const CATMathPoint& iStart, const CATMathPoint& iEnd, double iRadius, CATPolyAssemblyPathPlanning& iPlanner) );

  /**
  * @brief Define a guiding path from the starting to the end position by pipe segments.
  * The guiding path will locally redefine problem limits to help computation.
  * To work correctly, a full path of segment must be defined from the start to the end.
  * Anchor point must be defined as the center of moving object with SetGuidingPathAnchor.
  * Any radius not in the range of [oMinRadius, oMaxRadius] (see GetPreferedRadius method)
  * could lead to convergence issues. It may lead to max-times, so use at your own risk!
  *
  * @param iStart   starting position of a guiding path segment (in solver axis system)
  * @param iEnd     end position of a guiding path segment      (in solver axis system)
  * @param iRadius  radius of the guiding path segment. Any radius not in the range of [oMinRadius, oMaxRadius] could lead to convergence issues.
  * @param iPlanner the problem planner
  *
  */
  HRESULT AddGuidingPath( const CATMathTransformation& iStart, const CATMathTransformation& iEnd, double iRadius, CATPolyAssemblyPathPlanning& iPlanner );

  /**
    @brief return the number of guiding path
  */
  int GetNbGuidingPath( ) const ;
  HRESULT GetGuidingPath(int index, CATMathTransformation& oStart, CATMathTransformation& oEnd, double &oRadius) const;
  bool GetGuidingLimits(int index, CATMathPoint& oLow, CATMathPoint& oHigh, double& oSteering) const;


  /**
  * This planner will be used to convert CATPolyPPPosition into CATMathTransformation for guiding path
  * @remarks iPlanner must exist during all the life of this Problem definition
  **/
  void SetGuidingPathPlanner(CATPolyAssemblyPathPlanning * iPlanner){ _Planner = iPlanner;};
  CATPolyAssemblyPathPlanning *GetGuidingPathPlanner() const { return _Planner;};



  /*
    @brief if iIndexPath < GetNbGuidingPath return the end point else retunr nullptr;
  */
  //CATCGMSharedPtr< CATPolyPPPosition> GetGuidingPathTarget(int iIndexPath) const;
  /*
  * @brief return the target from the current guiding segment
  * @param[out] oGuidIndex the index of the current guide (can be != from previous GetCurrentGuidingPath in Multithread )
  */
  CATCGMSharedPtr< CATPolyPPPosition> GetCurrentGuidingPathTarget(int & oGuideIndex) const;
  //for tree builder
  int GetCurrentGuidingPath()const ;



  //GuidingPath  GetGuidingPath(int iIndex);
  /**
   * Returns the best estimated radius to be used in the AddGuidingPath method.
   * Note that any radius smaller than oMinRadius or bigger than oMaxRadius passed to AddGuidingPath
   * can lead to the path planning not converging.
   * @param[out] oMinRadius
   *        Minimal radius to set (lesser will generate convergence issue)
   * @param[out] oMaxRadius
   *        Maximal radius to set (bigger will generate convergence issue)
   * @param[out] oPreferedRadius
   *        Should be the radius hopefully leading to the best performances.
   * @param iPlanner
   *        planner use to computed oPreferedRadius
   * @return S_OK if everything went fine
   *         Error code if the planner was not set properly.
   */
  HRESULT GetPreferedRadius(double & oMinRadius, double & oMaxRadius, double & oPreferedRadius, CATPolyAssemblyPathPlanning& iPlanner);

public:

  /** Return the next configuration in the list of intermediate
   *  configurations. This method allows to iterate on the
   *  intermediate configurations list. It is not supposed to be
   *  called by the user but only by the Path Planning solver.
   * @return a pointer on the next configuration in the list of
   * intermediate configurations. Return a NULL pointer if there is
   * no more inermdiate configuration in the list.
   */
  CATBoolean HasIntermediatePosition(bool usethreadsafe=false) const;

  CATPolyPPPosition * GetIntermediatePosition(bool usethreadsafe=false);

  void GotoNextIntermediatePosition(bool usethreadsafe=false);


  int GetNbIntermediatePosition() const;
  const CATPolyPPPosition* GetIntermediatePositionByIndex(int iIndex) const;

  CATPolyPPPosition * GetNextTarget();


  /** Re-initialization of the iteration on the intermediate
   *  configurations list. It is not supposed to be called by the user
   *  but only by the Path Planning solver.
   */
  void ReStart();

  /** Register an observer (will observe start, end, and addition of new points)
   */
  void RegisterObserver(CATPolyPPDefinitionObserver * iObs);

  /** Unegister an observer
   */
  void UnregisterObserver(CATPolyPPDefinitionObserver * iObs);

 private:

 #ifdef ENABLE_PP_MT

  CATBoolean aHasIntermediatePosition() const;

  CATPolyPPPosition * aGetIntermediatePosition();

  void aGotoNextIntermediatePosition();

#endif

   CATPolyPPDefinition( const CATPolyPPDefinition& iOther );

   CATPolyPPDefinition& operator=(const CATPolyPPDefinition& iOther );


  CATCGMSharedPtr<CATPolyPPPosition> _Start;
  CATCGMSharedPtr<CATPolyPPPosition> _Target;

  CATCGMSharedPtr<CATPolyPPTargetDefinitionBase> _TargetDefinition;

  unsigned int _CurrentTarget;
  unsigned int _CurrentIntermediate;
  CATPolyPPPath _Track;

#ifdef ENABLE_PP_MT
  std::atomic< unsigned > _aCurrentTarget;
  std::atomic< unsigned > _aCurrentIntermediate;
  std::atomic< unsigned > _aCurrentTrackSize;
  std::atomic< int > _aGlobalGuidingSegment;
  std::mutex _LockSegment;
#endif


private:

  typedef struct
  {
    CATMathTransformation start;
    CATMathTransformation end;
    CATMathPoint p1;
    CATMathPoint p2;
    double sqr;
  } GuidingPath;

  /**
   * use to store edge created by user 
   * */
  typedef struct 
  {
    CATCGMSharedPtr< CATPolyPPPosition > Start;
    CATCGMSharedPtr< CATPolyPPPosition > End;
  } PPUserEdge;

  friend class RRTThread;
  friend class DDRRTThread;
  friend class CATPolyPPTreeBuilder;


  std::vector< CATMathBox >  m_GuidingLimits;           ///< no need to be thread safe since no guiding points will be added during the run
  std::vector< GuidingPath > m_GuidingPath;             ///<
  std::vector< CATCGMSharedPtr< CATPolyPPPosition> > m_GuidingTarget;    ///<
  std::vector< double > m_Steering;                     ///<
  CATMathTransformation m_Anchor;                       ///<
  
  std::multimap<CATPolyPPPosition *, PPUserEdge> _UserEdge;
  std::multimap<CATPolyPPPosition *, PPUserEdge> _UserEdgeReverse;

  CATBoolean TestChangeLimits(const CATMathTransformation& iPos, int ioCurrentPath);
  CATBoolean ChangeLimits(const CATMathTransformation& iPos, int& ioCurrentPath, CATMathPoint& oLow, CATMathPoint& oHigh, double& oSteering, CATBoolean donotChangeLimits);

  inline double HasGuidingPath( int iPath ) const { return iPath < (int)(m_GuidingPath.size()-1) ? true : false; }




  void ResetGuidintPath();
  bool GoNextGuidingPath(int iCurrent);
  /*
    @brief check if this point is in the end of the current guiding path and the start of the next
  */
  bool IsOnCurrentTargetGuidingPath(const CATPolyPPPosition &ippPos);


  CATPolyAssemblyPathPlanning * _Planner = nullptr;;

  CATPolyPPDefinitionObserver * m_obs;
};

INLINE CATPolyPPPosition * CATPolyPPDefinition::GetStart() const
{
  return _Start.get();
}


// INLINE void CATPolyPPDefinition::SetSteeringRadius(double iRadius)
// {
//   _Radius = iRadius;
// }
// INLINE double CATPolyPPDefinition::GetSteeringRadius() const
// {
//   return _Radius;
// }

#endif
