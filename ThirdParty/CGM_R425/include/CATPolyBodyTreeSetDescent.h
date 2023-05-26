// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyTreeSetDescent.h
//
//===================================================================
//
// Usage notes:
// Class descending a pair of tree sets and find the inputs
// BVH trees whose BV are in interference.
//
//===================================================================
//
// Oct 2009 Creation: JS9
//===================================================================

#ifndef CATPolyBodyTreeSetDescent_h
#define CATPolyBodyTreeSetDescent_h

#include "PolyBodyBVHOperators.h"

// System
#include "CATMathTransformation.h"
#include "CATBoolean.h"
#include "CATListPV.h"

// Math
#include "CATTolerance.h"
#include "CATMathVector.h"

// Polyhedral
class CATBVHTree;
class CATBVHNodeConst;

// Interference
class CATBVHTreeSet;
class CATIPolyInterfInputNodeProcessor;

/**
 * Class descending a pair of BVH trees to get the interference.
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyTreeSetDescent
{
public:


  /**
   * Constructor and destructor.
   */
  CATPolyBodyTreeSetDescent(const CATTolerance & iTol);
  CATPolyBodyTreeSetDescent(const double iLargeEpsgForRelativeTest);
  virtual ~CATPolyBodyTreeSetDescent();

  /**
   * Set the input of the algorithm: the two sets to compare.
   * The colliding inputs will be found between the product of
   * the input nodes of these sets.
   */
  void SetInput(CATBVHTreeSet * set1,
                CATBVHTreeSet * set2, const CATMathTransformation * pos = NULL);

  /**
   * Same but for a single set.
   * The colliding inputs will be found between the input nodes
   * of this set.
   */
  void SetInput(CATBVHTreeSet * set);

  /**
   * Run the descent.
   * Only a status is return. Everything is be done in the processing.
   */
  HRESULT Run();

  /**
   * Set the tolerance to use between BV.
   */
  void SetTolerance(double tolerance);

  /**
   * Add a procesor for input nodes
   */
  void AddInputNodeProcessor(CATIPolyInterfInputNodeProcessor * processor);

  /**
   * Remove an alredy registered processor
   */
  void RemoveInputNodeProcessor(CATIPolyInterfInputNodeProcessor * processor);

  /**
   * Get the number of bounding volumes intersections
   * during last Run.
   */
  int GetNbCalls();

private:

  //-----------------------------------------------------
  // If the function returns TRUE, the descent continue to this children of the nodes.
  // If FALSE it stops.
  //
  CATBoolean ContinueDescent(const CATBVHNodeConst & node1, const CATBVHNodeConst & node2) const;

  // Choose whether to continue the descent on the left or the right node.
  int Choose(const CATBVHNodeConst & node1, const CATBVHNodeConst & node2) const;

  /**
   * Get whether a node is relative to the input.
   */
  CATBoolean IsInputNode(const CATBVHNodeConst & node) const;

  // Descent on the nodes thet are above the input nodes
  // parentInputNode1 and 2 are updated when the function reaches input nodes
  HRESULT Descent(const CATBVHNodeConst & iNode1, const CATBVHNodeConst & iNode2);

  // Descent between the children of a single node
  HRESULT Descent(const CATBVHNodeConst & node);

  // Process two leaf nodes
  HRESULT ProcessLeafNodes(const CATBVHNodeConst & node1, const CATBVHNodeConst & node2);

  // Get a scaled epsilon to use during the computation
  double GetScaledEpsilon() const;

  // Get an averag scale of the tree set data
  double GetScale(CATBVHTreeSet * treeSet) const;
  //-----------------------------------------------------
  CATBVHTreeSet * _pSet1;
  CATBVHTreeSet * _pSet2;
  CATMathTransformation _Pos1To2;
  CATBoolean _bIsIdentity;
  CATBoolean _bIsTranslation;
  CATMathVector _oTrans1To2;

  const double m_LargeRelEpsg;

  double _dSpecifiedTolerance;
  double _dTolerance;
  int _iNbBVColliding;

  CATListPV _oInputNodeProcessors; // List of processors for input reps
  //-----------------------------------------------------

#ifdef DEBUGBVHDESCENT
public:
  static CATLONG64 _nbbvbv;
  static CATLONG64 _nbbvbv2;
#endif
};

#endif // CATPolyInterferenceVisuBVHDescent_h

