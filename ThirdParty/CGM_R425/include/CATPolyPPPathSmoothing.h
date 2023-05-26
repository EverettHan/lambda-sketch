// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPPathSmoothing.h
//
//===================================================================
//
// Usage notes: Tool attached to the nD Path Planning solver that
// simplify and smooth a resulting path (a list of valid
// configurations) according to a given clash solver.
//
//===================================================================
//
// 2013-01-04 XXC: Creation
// 2013-09-12 XXC: Getters for Phoenix
//===================================================================

#ifndef CATPolyPPPathSmoothing_HH
#define CATPolyPPPathSmoothing_HH

#include "PolyPathPlanning.h"
#include "CATErrorDef.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATPolyDebugPathPlanningTraces.h"
#include "CATPolyPPConfigurationChecker.h"

class CATPolyPPPath;
class CATPolyPathSmoothingObserver;
#ifdef ENABLE_PP_MT
class CATPolyPPMTSegmentChecker;
#endif
/// Path smoothing tool.
/** This operator is a tool that smooth a path (or track) according to
 *  the definition of moving objects and obstacles. A
 *  CATPolyPPConfigurationChecker check for collisions between the
 *  moving objects and the obstacles in order to verify, during the
 *  smoothing, that the new path does not contain collisions. The
 *  smoothing algorithm is iterative, several calls to this operator
 *  with the same path allows to get a smoother path at each call
 *  until the reach of a convergence point.
 */
class ExportedByPolyPathPlanning CATPolyPPPathSmoothing
{
// public:
//   enum SmoothingMode {
//     Basic=1,
//     Smart=2
//   };

public:

  /** Constructor for the smoothing operator.
   * @param iChecker: the collision solver used to detect clashes
   * between the object moving along the path and other obstacle
   * objects. The moving object and obstacles are defined in the
   * collision solver itself.
   */
  CATPolyPPPathSmoothing(CATPolyPPConfigurationChecker & iChecker);
  ~CATPolyPPPathSmoothing();

  // /** Set the mode to use to smooth the given path. If Basic, only
  //  *  basic algorithms are used, if Smart, some smarter but slower
  //  *  algorithms are used.
  //  * @param iSmoothingMode: the smoothing mode between two values
  //  * CATPolyPPPathSmoothing::Basic and CATPolyPPPathSmoothing::Smart.
  //  */
  // void SetSmoothingMode(SmoothingMode iSmoothingMode);

  /** Request a multi threaded version of the smoothing. May not work
   * on all platforms.
   *@param iNbThreads: optional number of threads to use. If set to 0
   *(default), use the maximum system number of available threads.
   *@return S_FALSE if multi threading is not possible (wrong
   *platform, inappropriate configuration checker, ...), S_OK if it is
   *activated, E_FAIL if something went wrong.
   */
  HRESULT ActivateMultiThreading(int iNbThreads = 0);

  /** Set the path to smooth to the solver. The given path is modified
   *  when one calls the RunSmoothing method and kept to be possibly
   *  smoothed again until another path is given.
   */
  HRESULT SetPath(CATPolyPPPath & ioPath);

  /** Run the smoothing algorithms onto the given path as many times
   *  as desired, according to the number of iterations set (see
   *  method @see SetIterationComplexity). The path is modified during
   *  the run.
   * @param ioPath: in/out path to smooth.
   * @return E_FAIL if the smoothing failed, S_OK if it succeeded.
   */
  HRESULT RunSmoothing(CATPolyPPPath & ioPath);
  HRESULT RunSmoothing();
  HRESULT RunSmoothingStep();
  HRESULT RunRemoveOnlyStep(CATPolyPPPath * ioPath);

  void SetObserver(CATPolyPathSmoothingObserver * ipObs);

  const CATPolyPPConfigurationChecker & GetConfigurationChecker() const;

  unsigned int GetPercentDone() const;

  /* int GetSmoothingMode() const; */

  CATPolyPPPath * GetPath() const;

  /**
   * Control how the corner cutting with converge 
   * @param iPercent should be in [0..1.0[, 0.05 (5%)  is a good start
   * */
  void SetSmoothingRatioCornerEvol(double iPercent = 0.05 );

private:

  HRESULT CheckPathViability();

  CATPolyPPConfigurationChecker::CollisionType CheckSegment(const CATPolyPPPosition & iConfig1, CATPolyPPPosition & iConfig2);

  HRESULT PathPruning();

  /* HRESULT CuttingOffTriangleCorners(); */

  /* HRESULT RetractingVertices(); */

  HRESULT local_PathPruning(unsigned int i);

  HRESULT local_CuttingOffTriangleCorners(unsigned int i);

  HRESULT local_RetractingVertices(unsigned int i);

  void NotifyObserverOfCurInputs(const CATPolyPPPath & iPath);

 private:
  /* SmoothingMode _Mode; */

  double _LimitSmallSegment;
  double _Epsilon;
  double _LimitCornerEvolRatio = 0;

  CATPolyPPConfigurationChecker & _Checker;

#ifdef ENABLE_PP_MT
  CATPolyPPMTSegmentChecker * _MTChecker;
#endif

  CATPolyPPPath * _PathToSmooth;
  CATListOfInt _Moves;

  CATPolyPathSmoothingObserver * _pObserver;

 private:
  char _DoneParts;
  unsigned int _CurrentIndex;
  unsigned int _NbAction, _ActionToDo;

  CATBoolean m_first;
  DEBUGPATHPLANNINGOBJECTTRACE(m_traces);
};

#endif
