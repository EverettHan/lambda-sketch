// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySimpleClashOper.h
//
//===================================================================
//
// Usage notes:
// Operator to compute clash.
//
//===================================================================
//
// Sep 2009 Creation: JXO
//===================================================================
#ifndef CATPolyBodySimpleClashOper_h
#define CATPolyBodySimpleClashOper_h

#include "CATPolyBVHNodePairStack.h"
#include "CATPolyBVHClashOper.h"
#include "CATBVHDescentOperator.h"
#include "CATPolyBVHMultiThreadClashOper.h"
#include "CATSetOfInt.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListPV.h"

class CATBVHTree;
class CATPolyBodySimpleClashResultIterator;
class CATPolyBodySimpleClashFaceEdgeIterator;
class CATPolyBodyBVHTreeSet;
class CATBVHTreeSet;
class CATBVHNodeConst;
class CATBucketsOfDouble;
class CATMathTransformation;
class CATMapOfBVHNodesToAttributes;
class CATCellId;

#include "PolyBodyBVHOperators.h"

/**
 * Computes clash between two BVH.
 *
 * Note about memory: Temporary computation data is stored inside this
 * Operator. It can heavily be re-used in next computations for performance
 * purposes. So you just have to change operands and call Run method again.
 * To release memory, just delete the operator.
 *
 * This operator uses new CATBVHTree architecture.
 */

class ExportedByPolyBodyBVHOperators CATPolyBodySimpleClashOper : CATBVHDescentOperator

{
public:

  /**
   * Clash specification: 
   *       FirstClash: computation stops as soon as two triangles clash.
   *       IntersectionCurves: returns the intersection (if any) between the two solids
   */

  enum ClashMode
  {
    FirstClash = 0,
    IntersectionCurves,
    // For debug purpose only, don't use:
    ClashTriangles,
    TriangleBoxes,
    BoundingVolumes,
    Canonics
  };

  /**
   * Clash result: 
   *       Undefined: 'Run' method not called or other problem.
   *       NoClash: the two solids do not intersect.
   *       Clash: the two solids intersect.
   */

  enum ClashStatus
  {
    Undefined = 0,
    NoClash,
    Clash,
    // Not implemented yet:
    Contact,
    Clearance,
    Boolean
  };

  /**
   * Clash entities: 
   *      Decide what you want to clash against what.
   *      Default is Faces against Faces.
   */

  enum ClashEntities
  {
    FacesAgainstFaces = 0,
    EdgesAgainstFaces,
    FacesAgainstEdges,
    AllAgainstFaces,
    FacesAgainstAll,
    AllAgainstAll
  };

public:

  /**
   * Constructor and destructor.
   */
  CATPolyBodySimpleClashOper ();
  virtual ~CATPolyBodySimpleClashOper ();


  /**
   * 1 against 1 run method. Computes the clash.
   * Params:
   *   iClashmode: see @ClashMode
   *   oResult: intersection result, may be NULL. Should be deleted by caller.
   *   oStatus: see @ClashStatus
   * Returns:
   *   S_OK: everything went fine
   *   Error code if something wrong happened
   */

  HRESULT Run(ClashMode iClashmode, CATIPolyCurveIterator *& oResult, ClashStatus & oStatus);

  /**
   * All against All (or L1 against L2) method.
   * Params:
   *   iClashmode: see @ClashMode
   *   iClashEntities: see @ClashEntities
   *   oResult: intersection result, maybe NULL. Should be released by caller. When not initially NULL, new clashes
   *            are added in it.
   *   iDiscardEdgeLimits: if set to TRUE, edge limits won't generate intersection points.
   *   iClashingTrees: if set, lists will be filled with IDs of trees that interact with at least one other tree.
   *                   IDs are the one in the CATBVHTreeSet operands.
   *   iSymetry: If set to TRUE, in non symetric modes (Edges agains Faces for example), we force the symetric
   *             computation (Edges against Faces AND Faces against Edges for example)
   * Returns:
   *   S_OK: everything went fine
   *   Error code if something wrong happened
   */

  HRESULT Run(ClashMode iClashmode, ClashEntities iClashEntities, CATPolyBodySimpleClashResultIterator * &oResult, CATBoolean iDiscardEdgeLimits = FALSE, CATBoolean iClashingTrees = FALSE, CATBoolean iSymetry = FALSE);

  /**
   * Specific 1 against 1
   * Params:
   *   iClashmode: see @ClashMode
   *   iClashEntities: see @ClashEntities
   *   oResult: will be filled with result. Should not be NULL.
   *   object1Id, int object2Id: IDs of couple
   *   iSymetry: if set to TRUE, then FacesAgainstEdges is symetric
   * Returns:
   *   S_OK: everything went fine
   *   Error code if something wrong happened
   */
  HRESULT RunOneAgainstOne(ClashMode iClashmode, ClashEntities iClashEntities, CATPolyBodySimpleClashResultIterator * oResult, int object1Id, int object2Id, CATBoolean iSymetry = FALSE, CATBoolean iDiscardEdgeLimits = FALSE);

  /**
   * Set the two operands. Run method will look for CATPolyBVHAttributes on nodes.
   * Trees better have been constructed with @CATPolyBodyBVHTreeBuilder.
   * Use this method for 1 against 1.
   * @param pTree1
   *        First tree
   * @param pTree2
   *        Second tree, to be clashed against first tree
   * @param pPos1
   *        Position of first tree
   * @param pPos2
   *        Position of second tree
   * @param pOverridePos1ToPos2
   *        Override position used for bounding volume tests. If set, pPos1 and pPos2 will be used only for geometric tests.
   */
  void SetTrees(CATBVHTree * pTree1, CATBVHTree * pTree2, CATMathTransformation * pPos1 = 0, CATMathTransformation * pPos2 = 0, CATMathTransformation * pOverridePos1ToPos2 = 0);

  /**
   * Set the first data to be used by the operator.
   * To test only the first set against itself, set the second operand
   * to NULL.
   * Use this method for All against All or Set1 against Set2.
   * @param data1 first set of data.
   */
  virtual void SetFirstOperand(CATBVHTreeSet * data1, const CATMathTransformation * pos = NULL);
  
  /**
   * Set the seond set of data to be used by the operator.
   * If not set or set to NULL, the operator will test the first set
   * against itself.
   * Use this method for Set1 against Set2.
   * @param data2 second set of data.
   * @param iDiscardSameIds for some specific scenarios you may want to discard
   *        identical IDs from set1 and set2
   */
  virtual void SetSecondOperand(CATBVHTreeSet * data2, const CATMathTransformation * pos = NULL, CATBoolean iDiscardSameIds = FALSE);

  /**
   * Activate GPGPU.
   */
  void ActivateGPGPU(CATBoolean activate = TRUE);


  /**
   * See @iClashingTrees argument of Run method 2.
   */
  const CATSetOfInt & GetClashingTreesFromSet1();
  /**
   * See @iClashingTrees argument of Run method 2.
   */
  const CATSetOfInt & GetClashingTreesFromSet2();


public:
  /** @nodoc */
  void GetDebugInfos(CATLONG64 & BVBVtests, CATLONG64 & BV2BV2tests, CATLONG64 & CouplesClashing, CATLONG64 & FaceCouplesClashing, CATLONG64 & TTTests);
  /** @nodoc */
  const CATPolyBVHNodePairStack & GetDebugCouples();

protected:
  /**
   * Implements @CATBVHDescentOperator.
   */
  virtual HRESULT ProcessLeafNodes(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2);
  virtual CATBoolean Filter(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2);
  virtual int Choose(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2);
  virtual CATBoolean Cancel() const;
  virtual void End(CATBVHNodeConst& iBVHNode1, CATBVHNodeConst& iBVHNode2);

protected:
  /**
   * Updates _clashstatus and _result depending on _clashmode and _Couples
   */
  HRESULT ClashCouples();
  HRESULT DescentToPolyBodies(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2, int object1Id, int object2Id);
  HRESULT ClashPolyBodies(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2, int object1Id, int object2Id);
  HRESULT DescentToPolyCells(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2);
  HRESULT ClashPolyCells(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2);
  CATBoolean BVOverlap(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2);
  static CATBoolean IsPolyFace(CATBVHNodeConst & iNode1);
  static CATBoolean IsPolyEdge(CATBVHNodeConst & iNode1);
  static CATBoolean IsPolyCell(CATBVHNodeConst & iNode1);
  static CATBoolean IsPolyBody(CATBVHNodeConst & iNode1);
  static CATCellId * GetId(CATBVHNodeConst & iNode);
  int MultiThreadedDescend(CATBVHTree & Tree1, CATBVHTree & Tree2);
  HRESULT AddCoupleToStack(const CATBVHNodeConst & iNode1, const CATBVHNodeConst & iNode2, const CATMathTransformation * pPos1 = NULL, const CATMathTransformation * pPos2 = NULL, CATMapOfBVHNodesToAttributes * pMap = NULL, void * oList = NULL);
  HRESULT StackCoupleForGPGPU(const CATBVHNodeConst & iNode1, const CATBVHNodeConst & iNode2);
  void DumpCanonicalInfos(const CATBVHNodeConst & iNode1, const CATBVHNodeConst & iNode2);

protected:
  CATBVHTree * _pTree1;
  CATBVHTree * _pTree2;
  CATMathTransformation _Pos1;
  CATMathTransformation _Pos2;
  CATMathTransformation _Pos1To2;
  ClashMode _clashmode;
  ClashStatus _clashstatus;
  CATIPolyCurveIterator * _result;

  CATBVHTreeSet * _pSet1;
  CATBVHTreeSet * _pSet2;
  CATBoolean _DiscardSameIds;
  CATPolyBodySimpleClashResultIterator * _ResultIterator;
  CATPolyBodySimpleClashFaceEdgeIterator * _FaceEdgeIterator;
  CATBoolean _Symetry;
  CATBoolean _DiscardEdgeLimits;
  CATBoolean _GPGPUActivated;

  const CATMathTransformation * _currentpos1;
  const CATMathTransformation * _currentpos2;
  int _currentreplevel1;
  int _currentreplevel2;

  int _break;
  
  CATPolyBVHNodePairStack _Couples;

  CATPolyBVHClashOper _bvhoper;
  CATPolyBVHMultiThreadClashOper _bvthreadoper;

  ClashEntities _ClashEntities;

  // Debug variables:
  CATLONG64 _BVBVtests;
  CATLONG64 _BV2BV2tests;
  CATLONG64 _CouplesClashing;
  CATLONG64 _FaceCouplesClashing;
  CATLONG64 _TTTests;

  CATSetOfInt _ClashingTrees1;
  CATSetOfInt _ClashingTrees2;

public:
  // NOT SUPPORTED
  static int nbthreads;

};

#endif // CATPolyBodySimpleClashOper_H

