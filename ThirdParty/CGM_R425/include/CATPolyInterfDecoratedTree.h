// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfDecoratedTree.h
//
//===================================================================
//
// Usage notes:
// Class adding additional informations on a BVH tree.
//
//===================================================================
//
// Jan 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterfDecoratedTree_h
#define CATPolyInterfDecoratedTree_h

#include "CATPolyBoundingVolumeOperators.h"


// Math
class CATTolerance;
#include "CATMathTransformation.h"
#include "CATMapOfPtrToPtr.h"

// Polyhedral
class CATBVHTree;
class CATBVHNodeConst;

// Interference
#include "CATPolyInterfClashContactOper.h"
class CATPolyInterfDecoratedObjectsVisitor;
class CATPolyInterfDecoratedPolyBody;
class CATBVHTreeObserverForDecoratedTree;

/**
 * Class adding additional informations on a BVH tree.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfDecoratedTree
{
public:

  CATPolyInterfDecoratedTree(CATBVHTree  &tree, int inputId,
                             CATPolyInterfClashContactOper::AccuracyChooser * accuracyChooser,
                             const CATTolerance & iTol,
                             const CATMathTransformation * initialPos = NULL);
  ~CATPolyInterfDecoratedTree();

  /**
   * Flush all the data cached by the tree.
   */
  void FlushAll();

  /**
   * Restore the tree to its original state (no more expand).
   */
  void CollapseTree();

  /**
   * Flush all the memory allocated by the attributes (ie actual polybodies)
   */
  void FlushAttributesMemory();

  /**
   * Call Smart Flush on Smart Rep Nodes (don't ask)
   */
  void SmartFlush();

  /**
   * Restore the tree to its original state (Nodes and attributes).
   */
  void FlushAndCollapseNoThreadSafe();

  /**
   * Flush all the cache used for decorated meshes.
   * But don't destroy polybodies.
   * Warning: Don't use this function in combination with
   *          one of the flush functions impacting the actual tree.
   *          Otherwise the decorated polybodies won't be valid any more.
   */
  void FlushInterferenceMeshCache();

  /**
   * Flush the cache used for interference computation.
   */
  void FlushInterferenceCache();

  /**
   * Set a new position for the tree.
   */
  void SetNewPosition(const CATMathTransformation & newPos);

  /**
   * Return the current position of the tree.
   */
  const CATMathTransformation & GetCurrentPosition() const;

  /**
   * Get the polybody corresponding to a node contained in the tree.
   */
  CATPolyInterfDecoratedPolyBody * GetCorrespondingPolyBody(const CATBVHNodeConst & node);

  /**
   * Get the actual BVH tree.
   */
  const CATBVHTree & GetActualTree() const;

  /**
   * Get the root node of the tree.
   */
  CATBVHNodeConst * GetTreeRoot();

  /**
   * Check if two transformations are equals
   */
  CATBoolean AreEquals(const CATMathTransformation & transfo1, const CATMathTransformation & transfo2);

  /**
   * Accept a visitor and call its visit method on the children polybodies.
   */
  void Accept(CATPolyInterfDecoratedObjectsVisitor & visitor);

  /**
   * Get the Id of the input relative to the tree in the interference process.
   */
  int GetInputId() const;

  /**
   * Modify the id of the input relative to the tree in the interference process.
   */
  void SetInputId(int treeId);

  /**
   * Compute the additional tolerance that must be applied on BV checks for contact.
   */
  double GetAdditionalContactTolerance();

  /**
   * Scan the tree to find the polybody with the highest accuracy
   */
  static double GetAdditionalContactTolerance(const CATBVHTree & tree, CATPolyInterfClashContactOper::AccuracyChooser * chooser);

private:

  //---------------------------------------------------
  static double GetAdditionalContactTolerance(const CATBVHNodeConst & node,
                                              CATPolyInterfClashContactOper::AccuracyChooser & chooser);
  //---------------------------------------------------
  CATBVHTree & _rTree;
  int _iInputId;
  CATPolyInterfClashContactOper::AccuracyChooser * _pAccuracyChooser;
  CATMathTransformation _oCurrentPosition;
  CATMapOfPtrToPtr _oNodeToDecoPB;
  int _iRefCounter;
  double _dAdditionalContactTolerance;

  const CATTolerance & m_Tol;
  const double _sdLargeEpsg;

  CATBVHTreeObserverForDecoratedTree * m_treeobs;
};

#endif // CATPolyInterfDecoratedTree_H

