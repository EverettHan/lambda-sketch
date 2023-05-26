// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathPlanning3DChecker.h
// Header definition of CATPolyAssemblyPathPlanning3DChecker
//
//===================================================================
//
// Usage notes: Checker implementation for path planning
//
//===================================================================
//
// October 2013 Creation: JXO
//===================================================================
#ifndef CATPolyAssemblyPathPlanning3DChecker_H
#define CATPolyAssemblyPathPlanning3DChecker_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
#include "CATPolyPPConfigurationChecker.h"
#include "CATPolyDebugPathPlanningTraces.h"
#include "CATPolyPPTopologicalSpaceSO3.h"
#include "CATPolySetMeasureBetween.h"
#include "CATPolyInterfClashContactOper.h"
#include "CATIPolyInterfInputCoupleFilter.h"

#include "CATIPolyInterference.h"
// Math
#include "CATMathTransformation.h"

// System
#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#include "CATCGMSharedPtr.h"
#include "CATPolyLittleTimer.h"

#ifdef _AIX_SOURCE
#undef throw
#undef try
#undef catch
#endif

#include <map>
#include <mutex>
// problem with list #include <unordered_set>

#ifdef _AIX_SOURCE
#define throw ERROR
#define try ERROR
#define catch ERROR
#endif

// Forward declarations
class CATPolyPPPosition;
class CATPolyInterferenceOper;
class CATBVHTreeSet;
class CATPolyAssemblyPathPlanning;
class CATIPolySetMeasureBetween;

/**
 * \addtogroup PathPlan3DAssembly
 * @{
 */

/**
 * Checker implementation
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanning3DChecker : public CATPolyPPConfigurationChecker
{
public:
  CATPolyAssemblyPathPlanning3DChecker(CATPolyAssemblyPathPlanning & iSpecs);

  bool IsA(const char * iClassName) const ;

  CATPolyAssemblyPathPlanning3DChecker( const CATPolyAssemblyPathPlanning3DChecker& iOther, CATPolyAssemblyPathPlanning & iSpecs );
  

  /**
    Active a mode to compute the worst distance  :
      - if penetration exist it is the worst penetration
      - if non penetration it is the min distance before collision
    in normal mode we stop the computation on the first rejected configuration.
    @param[in] iEnable Enable/Disable the mode
  */
  void SetForceComputeWorst( CATBoolean iEnable = TRUE);
  CATBoolean GetForceComputeWorst() const;


  Collision TestConfiguration(const CATPolyPPPosition & iConfig, CATBoolean iStatus = 0);

  void InitCache( unsigned iSize = 2048u );

  //---------------------------------------------------------------------------------------------------------
  // Accessor methods for getting data from CATPolyAssemblyPathPlanning operator(exploits friendship between
  // the two classes) needed for phoenix extension of CATPolyPPPathSmoothing operator
  //---------------------------------------------------------------------------------------------------------
  // Clash Solver related accessors
  void RefreshClash();
  CATPolyInterferenceOper * GetClashOper() const;
  int IsComputingContactMeshes() const;
  int IsComputingRefinedContactAreas() const;
  int IsComputingWitnessPoints() const;
  int IsCheckingInterferenceStability() const;
  int IsComputingIntersectionCurves() const;
  int IsComputingPenetrationVectors() const;
  int GetPenetrationVectorDirection() const;
  int IsStoppingAtFirstClash() const;
  int IsPartialGeometricResultsEnabled() const;
  int GetMemoryConsumptionHint() const;
  int IsCheckingWaterTightness() const;
  int GetGranularityLevel() const;
  int IsDetectingInclusion() const;
  int IsCheckingInclusionInsideOpenObjects() const;
  int GetMaximalNumberOfThreads() const;

  // Path planning related accessors
  int GetPathPlanType() const;
  int GetPathPlanRandomGenType() const;
  int GetPathPlanRandomGenSeed() const;
  double GetPathPlanPenetration() const;
  const CATListOfInt & GetPathPlanLimitedDims() const;
  const CATListOfDouble & GetPathPlanMinLimits() const;
  const CATListOfDouble & GetPathPlanMaxLimits() const;
  CATMathTransformation GetTranslationAxis() const;
  CATMathTransformation GetRotationAxis() const;
  const CATBVHTreeSet * GetScene() const;
  const CATBVHTreeSet * GetMovingModel() const;  
  //const CATBVHTreeSet * GetMovingModelHull()const ;

  CATPolyPPTopologicalSpaceSO3::RotationType GetRotationType() const;

  /** Debug */
  virtual CATPolyAssemblyPathPlanning3DChecker * CastToAssemblyChecker() {return this;}
  /** Debug */
  virtual const CATPolyAssemblyPathPlanning3DChecker * CastToAssemblyChecker() const {return this;}

  virtual CATPolyAssemblyPathPlanning3DChecker* Clone( CATPolyAssemblyPathPlanning & iSpecs ) const;

  CATPolyPPConfigurationChecker* Clone() const;


  CATPolyAssemblyPathPlanning & GetPlanner() { return m_Specs; }

  /**
   * callback that allow to do statistic on bad clash
   * */
  class StatCallBack : public CATPolyRefCounted 
  {
    
    public:
      typedef CATCGMSharedPtr<StatCallBack> SPtr;

      virtual void StartTestConfig(const CATPolyPPPosition& iConfig, int threadID){};
      virtual void EndTestConfig(const CATPolyPPConfigurationChecker::Collision &iCollision, const CATPolyPPPosition& iConfig,int threadID){};
      /**
       * method called when testConfiguration reject a configuration
       * */
      virtual void OnRejectConfig(const CATPolyPPConfigurationChecker::Collision &iCollision, const CATPolyPPPosition& iConfig,int threadID) = 0;

  };

  void SetStatCallBack(StatCallBack::SPtr iCallBack );

  StatCallBack::SPtr GetStatCallBack() const;

  /**
   * @brief override the inner CATIPolySetMeasureBetween operator
   *  - should be use when point cloud exist in the bvhtree (the standard CATPolySetMeasureBetween does not)
   * @param iMeasureOperator distance operator
   * @param iApplySquareRootToGetResultData some distance operator return the square of the distance , this value say if we must apply a square root
   * */
  void SetUserMinDistOperator( CATIPolySetMeasureBetween * iMeasureOperator, bool iApplySquareRootToGetResultData = true  );

  int m_ID=-1;

  void SetClashOriginalMutex(std::mutex * ilock, std::atomic<int> * nbInUse, int  imaxallow = 1 );
  
protected:
  ~CATPolyAssemblyPathPlanning3DChecker();//why protected ? 
  Collision RunClashOperator(CATPolyInterferenceOper & iOper, CATIPolyInterference::InterferenceType &oInterferencetype, const double iAllowedDepth = -1., const double retractation = 0.);
  CATPolyAssemblyPathPlanning3DChecker( const CATPolyAssemblyPathPlanning3DChecker& iOther, CATPolyAssemblyPathPlanning * iSpecs );

private:
  friend class CATPolyAssemblyPathPlanning;
  friend class CATPolyPathPlanningSolver;
  friend class RRTThread;
  CATPolyAssemblyPathPlanning & m_Specs;//my be put some ptr instead 
  bool _MustCleanSpecs = false;
  int m_clashes;
  int m_nbValidOriginal =0;




  struct MultiPassClash
  {
    CATPolyInterferenceOper* m_ClashOper;
    bool m_Destroy;
    CATListOfInt m_ActiveScene;
    CATListOfInt m_ActiveMoving;
    CATListOfInt m_ActiveMovingHull;
    CATListOfInt m_ActiveSceneHull;
    CATBVHTreeSet* m_MovingObject;
    CATBVHTreeSet* m_MovingHull;
    CATBVHTreeSet* m_SceneHull;
    bool m_OnlyHull;
    double m_PenetrationRequested;
    double m_Penetration;
    CATPolyInterfClashContactOper::AccuracyChooser * m_AccuracyChooser;
    CATIPolyInterfInputCoupleFilter  * m_Filter = nullptr;
    CATIPolyInterfInputCoupleFilter  * m_FilterHull = nullptr;

    MultiPassClash()
    {
      m_ClashOper = 0;
      m_Destroy = true;
      m_MovingObject = 0;
      m_PenetrationRequested = -1.0;
      m_Penetration = -1.0;
      m_AccuracyChooser = 0;
      m_MovingHull = 0;
      m_OnlyHull = false;    
      m_SceneHull = 0;  
    }
  };

  void AddClashSolverPass(MultiPassClash & iPass);

  HRESULT SetClashSolverPassHull(unsigned iPass,CATBVHTreeSet * iHull ,const CATListOfInt& iActivatedMovingObject, bool full);
  HRESULT SetClashSolverPassSceneHull(unsigned iPass,CATBVHTreeSet * iHull ,const CATListOfInt& iActivatedSceneObject);
  

  std::vector< MultiPassClash > m_MultiPassClash;
  bool m_MovingFullActivated;
  bool m_SceneFullActivated;
  CATPolySetMeasureBetween m_MinDist;
  CATIPolySetMeasureBetween * m_MiniDistOverride = nullptr;
  bool _MustApplySquareRootToGetResultData = true;

  CATPolyAssemblyPathPlanning3DChecker::StatCallBack::SPtr _StatCallBack=nullptr;
  
  CATBoolean m_ForceComputeWorstEnabled;

  int _nbHull=0;
  CATPolyLittleTimer _HullTimer;
  int _nbStd=0;
  CATPolyLittleTimer _StdTimer;
  int _nbStdValid=0;
  CATPolyLittleTimer _LifeTimer;

  bool m_ToggleHullOnly = true;//switch for each branch 
  

  std::mutex * _lockClash = nullptr;
  std::atomic<int> * _nbClashInUse = nullptr;
  int _nbClashInUseMaxAllowed = 1; 
  

  DEBUGPATHPLANNINGOBJECTTRACE(m_traces);
};

/** @} */

#endif
