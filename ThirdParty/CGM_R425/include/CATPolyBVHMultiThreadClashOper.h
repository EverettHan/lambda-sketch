// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHMultiThreadClashOper.h
//
//===================================================================
//
// Usage notes:
// Operator to compute clash from a stack of BV couples, multithread
//
//===================================================================
//
// Jun 2009 Creation: JXO
//===================================================================
#ifndef CATPolyBVHMultiThreadClashOper_h
#define CATPolyBVHMultiThreadClashOper_h

#include "CATPolyBoundingVolumeOperators.h"

#include "CATPolyBVHNodePairStack.h"
#include "CATIPolyCurveIterator.h"
#include "CATMapOfBVHNodesToAttributes.h"
#include "CATPolyMultiThreadedClashStructure.h"
#include "CATPolyThreads.h"

class CATPolyCurveFromBarsIterator;
class CATMathTransformation;

/**
 * Given a list of BVHNodes couples, computes the clash.
 * You may pass the number of threads as a parameter.
 */

class ExportedByCATPolyBoundingVolumeOperators CATPolyBVHMultiThreadClashOper : public CATPolyThreads<true>
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyBVHMultiThreadClashOper();
  ~CATPolyBVHMultiThreadClashOper();

  /**
   * Run method. Computes the clash.
   * Params:
   *   iClashmode:
   *       0: computation stops as soon as two triangles clash.
   *       1: returns the intersection (if any) between the two solids
   *   iStack:
   *       Input couples. May be filled by another thread during computation.
   *       This operator will wait for the end of filling event.
   * Note that this method will launch a thread and return.
   * You have to wait for the end of the computation with the Join method.
   */
  HRESULT Run(int iClashmode, CATPolyBVHNodePairStack & iStack, int nbthreads = 1);


  /**
   *   Returns: intersection result, may be NULL.
   *   oStatus:
   *       0: 'Run' method not called or other problem.
   *       1: the two solids do not intersect.
   *       2: the two solids intersect.
   */
  CATIPolyCurveIterator * GetResult(int & oStatus);


  /**
   * Multi Thread specific methods
   */
  virtual CATThreadsReturnCode Begin(void *iArg=NULL);

  inline static CATMutex & GetMutexForMeshesAccess(){return CATPolyMultiThreadedClashStructure::GetMutexForMeshesAccess();}


public:
  /** @nodoc */
  void GetDebugInfos(CATLONG64 & FaceCouplesClashing);
  /** @nodoc */
  void ResetDebugInfos();
  /** @nodoc */
  void FlushCachedData();


private:
  void ComputeClash();
  int DestroyMap(CATMapOfBVHNodesToAttributes & map);

private:
  int _clashmode;

  CATPolyBVHNodePairStack * _pCouples;

  int _clashstatus;
  CATPolyCurveFromBarsIterator * _CurvesIterator;
  CATMapOfBVHNodesToAttributes _MapOfBoxesAttributes;

  // Debug
  CATLONG64 _FaceCouplesClashing;

  int _nbthreads;

};

#endif // CATPolyBVHMultiThreadClashOper_H

