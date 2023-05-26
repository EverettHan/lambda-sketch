// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHClashOper.h
//
//===================================================================
//
// Usage notes:
// Operator to compute clash from a stack of BV couples
//
//===================================================================
//
// Apr 2009 Creation: JXO
//===================================================================
#ifndef CATPolyBVHClashOper_h
#define CATPolyBVHClashOper_h

#include "CATPolyBoundingVolumeOperators.h"

#include "CATPolyBVHNodePairStack.h"
#include "CATIPolyCurveIterator.h"
#include "CATMapOfBVHNodesToAttributes.h"

class CATPolyCurveFromBarsIterator;
class CATPolyBVHTreeNode;
class CATMathTransformation;


/**
 * Given a list of BVHNodes couples, computes the clash.
 */

class ExportedByCATPolyBoundingVolumeOperators CATPolyBVHClashOper
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyBVHClashOper();
  ~CATPolyBVHClashOper();

  void SetOperands(CATPolyBVHNodePairStack & Stack);

  /**
   * Run method. Computes the clash.
   * Params:
   *   iClashmode:
   *       0: computation stops as soon as two triangles clash.
   *       1: returns the intersection (if any) between the two solids
   *   oResult: intersection result, may be NULL.
   *   oStatus:
   *       0: 'Run' method not called or other problem.
   *       1: the two solids do not intersect.
   *       2: the two solids intersect.
   */

  HRESULT Run(int iClashmode, CATIPolyCurveIterator *& oResult, int & oStatus, CATBoolean GPGPUActivated = FALSE);




public:
  /** @nodoc */
  void GetDebugInfos(CATLONG64 & FaceCouplesClashing, CATLONG64 & NbTTTests);
  /** @nodoc */
  void ResetDebugInfos();
  /** @nodoc */
  void FlushCachedData();


private:
  int DestroyMap(CATMapOfBVHNodesToAttributes & map);

private:
  int _clashmode;

  CATPolyBVHNodePairStack _Couples;

  int _clashstatus;
  CATPolyCurveFromBarsIterator * _CurvesIterator;
  CATMapOfBVHNodesToAttributes _MapOfBoxesAttributes;

  // Debug
  CATLONG64 _FaceCouplesClashing;
  CATLONG64 _NbTTTests;

};

#endif // CATPolyBVHClashOper_H

