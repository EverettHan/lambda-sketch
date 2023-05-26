// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMultiThreadedClashStructure.h
//
//===================================================================
//
//
//===================================================================
//
// Jun 2009 Creation: JXO
//===================================================================
#ifndef CATPolyMultiThreadedClashStructure_h
#define CATPolyMultiThreadedClashStructure_h

#define CLASHMULTITHREAD

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATBoolean.h"

// Poly
#include "CATPolyBars.h"
#include "CATBucketsOfPoints.h"
#include "CATPolyThreads.h"
#ifdef CLASHCANONICMODE
#include "CATPolyTrimmedCanonicFactory.h"
#endif

class CATPolyBVHNodePair;
class CATPolyBVHNodePairStack;
class CATMapOfBVHNodesToAttributes;
class CATPolyPoolOfPoints;
class CATBVHNode;
class CATMathTransformation;
class CATPolyExactArithmetic;
class CATPolyTriangleIntersector;
class CATPolyBoxBoxIterator;
class CATPolyCurveFromBarsConcatenator;
class CATPolyCurveFromBarsIterator;


/**
 * Clash structure for multithreaded simple clash.
 */

class ExportedByCATPolyBoundingVolumeOperators CATPolyMultiThreadedClashStructure : public CATPolyThreads<true>
{
public:
  /**
   * Clash structure for multithreaded simple clash, constructor.
   * @param iPairs
   *        Stack of colliding Bounding Volumes pairs
   * @param PoolOfPoints
   *        Return pool of intersection points (Points 2i and 2i+1 form a bar, not 2i+1 and 2i+2)
   * @param iClashmode
   *        Clash mode:
   *        0: first clash, stops as soon a clash is detected.
   *        1: Normal clash, all intersection bars are computed.
   *        5: Canonic mode, use at your own risk.
   */
  CATPolyMultiThreadedClashStructure(CATPolyBVHNodePairStack & iPairs,
                                     CATPolyPoolOfPoints & PoolOfPoints,
                                     int iClashmode,
                                     CATMapOfBVHNodesToAttributes * ioMapOfBoxesAttributes = NULL,
                                     CATBoolean iOnlyPops = FALSE,
                                     CATBoolean iLocateAndInsert = FALSE,
                                     CATBoolean GPGPUActivated = FALSE) :
    _Pairs(iPairs),
    _MapOfBoxesAttributes(ioMapOfBoxesAttributes),
    _PoolOfPoints(PoolOfPoints),
    _clashmode(iClashmode),
    _clashstatus(0),
    _FaceCouplesClashing(0),
    _nbtttests(0),
    _OnlyPops(iOnlyPops),
    _GPGPUActivated(GPGPUActivated)
  {
    _pIter = NULL;
    _MapMut = iLocateAndInsert;
  }
  ~CATPolyMultiThreadedClashStructure();

  virtual CATThreadsReturnCode Begin(void *iArg=NULL);
  void ComputeClash();
  void MergeInto(CATPolyCurveFromBarsConcatenator & concat, int & clashstatus, CATLONG64 & FaceCouplesClashing);
  int Clash(CATPolyBVHNodePair & Pair,
            CATPolyExactArithmetic & exactArithmetic,
            CATPolyTriangleIntersector & triangleintersector,
            CATPolyBoxBoxIterator & bbit);

  inline static CATMutex & GetMutexForMeshesAccess(){return _MeshMutex;}

public:
  int _clashstatus;
  CATLONG64 _FaceCouplesClashing;
  CATLONG64 _nbtttests;

private:
  CATPolyBVHNodePairStack & _Pairs;
  CATMapOfBVHNodesToAttributes * _MapOfBoxesAttributes;
  CATPolyPoolOfPoints & _PoolOfPoints;
  int _clashmode;
  CATBoolean _OnlyPops;
  CATPolyCurveFromBarsIterator * _pIter;
  CATBucketsOfPoints _bucket;
  CATPolyBars _bars;
  CATBoolean _MapMut;
  CATBoolean _GPGPUActivated;

#ifdef CLASHCANONICMODE
  CATPolyTrimmedCanonicFactory m_CanonicFactory;
#endif

  static CATMutex _MeshMutex;
  static CATMutex _MapMutex;
};


#endif // CATPolyMultiThreadedClashStructure_H

