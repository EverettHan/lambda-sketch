// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanOper.h
//
//===================================================================
// September 2004 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanOper_H
#define CATPolyBooleanOper_H

#include "CATPolyBooleanOperators.h"
#include "CATPolyBoolean.h"
#include "CATMathBox.h"
#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"  // For the definition of HRESULT.

class CATPolyBooleanOperObserver;
class CATPolyGriddedMeshAndBars;
class CATIPolyMesh;
class CATPolyBars;
class CATPolyGriddedPositions;
class CATPolyBooleanSegments2;
class CATPolyBooleanSegmentsOper;
class CATPolyBooleanTriangulator;
class CATPolyBooleanError;
class CATPolyBooleanObserver;
class CATPolySPOctreePartition;
class CATPolyMeshPartitionOper;
class CATPolyAttributeDomains;
class CATPolyExactArithmetic;
class CATBucketsOfInt;

//#define NEW_OCTREE_PARTITION 1


/**
Main class performing robust boolean operations (union, intersection or subtraction) between two watertight polyhedral meshes. 

To perform a robust clipping operation between a close or open first operand and a watertight second clipping operand 
see CATPolyBooleanIntersectOper.

<b> Extension (August 2013): </b>
The operator can also be used to clip an operand (open or closed) along an intersection trace.  To clip a mesh (Operand 0) by a second operand (Operand 1), 
set the type of boolean operation to none.

The operator uses exact arithmetic to perform robust intersection tests between the mesh triangles.

Before running the operator, operands and parameters must be set, specifically:
<ul>
  <li> The two mesh operands;
  <li> The type of operation to perform between the operands;
  <li> A bounding box sufficiently large to contain both operands;
</ul>

The operator modifies the two operands.  At the end of a successful run, the first operand becomes the result of the operation.
The second operand is modified during the run and can be discarded.

The result of the boolean operation is not regularized.  It may contain (on rare occasions) non-manifold bars and vertices.

The operator can be called iteratively to perform a series of boolean operations.  
The result of the current operation becomes the first operand of the next operation.
A new second operand should be set before each iteration.

@see CATPolyBoolean
@see CATPolyBooleanIntersectOper
*/
class ExportedByCATPolyBooleanOperators CATPolyBooleanOper
{

public:

/** @name Life cycle
    @{ */

  /**
   * Constructor.  The instance of exact arihmetic can be set into one of three modes:
   * <ul>
   *   <li> Integer (or gridded) arithmetic where the coordinates of the mesh vertices must be gridded for exact 
   *        computation of the predicates.  See CATPolyExactArithmetic for gridding coordinates.
   *   <li> Float arithmetic where the coordinates of the mesh vertices must have 32-bit floating point precision.
   *   <li> Double arithmetic where the coordinates of the mesh vertices must have at most 64-bit floating point precision.
   * </ul>
   * If the layer of coordinates of the mesh are expressed in double, the preferred arithmetic mode is double.
   */
  CATPolyBooleanOper (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyBooleanOper ();

/** @} */


public:

/** @name Options and parameters
    @{ */

  /**
   * Sets the bounding box of the domain.  It must be sufficiently large to contain the operands.
   * If the exact arithmetic is set in the integer (gridded) mode, then the bounding box coordinates must be gridded.
   * The bounding box must be set before setting the operands.
   */
  HRESULT SetBoundingBox (const CATMathBox& iBoundingBox);

  /**
   * Sets the type of boolean operation to perform.  (See CATPolyBoolean::BooleanOperation.)
   * @param iOperation
   *   <ul> 
   *     <li> CATPolyBoolean::eBooleanNone to perform no boolean operation. 
   *          This is the mode that should be set if one wants to clip Operand 0 by Operand 1 just according to the intersection traces 
   *          and the orientation of the operands.
   *     <li> CATPolyBoolean::eBooleanUnion to perform a union between Operand 0 and Operand 1.
   *     <li> CATPolyBoolean::eBooleanIntersection to perform an intersection between Operand 0 and Operand 1.
   *     <li> CATPolyBoolean::eBooleanSubtraction to subtract Operand 1 from Operand 0.
   *   </ul>
   */
  void SetBooleanOperation (const int iOperation);

  /**
   * When this option is turned on, only the shells of the operands that are in contact
   * are combined and the other shells are ignored.  By default this option is not turned on.
   * and the boolean operation combines the two operands whether they are in contact or not.
   * However, in some cases (for instance machining scenarios) and for optimization purposes,
   * it may be possible to ignore the shells that are not in contact.
   *
   * For split of Operand 0 by Operand 1, set this option on.
   */
  void SetContactOnly (const CATBoolean iContactOnly);

  /**
   * If boolean operations are performed iteratively between the current result and new operands
   * set this option to <tt>TRUE</tt> to prevent recalculating the spatial partition at each step.
   * By default, this option is turned off and the spatial partition is cleared at the end
   * of a boolean operation.
   */
  void SetKeepPartition (const CATBoolean iKeepPartition);

  /**
   * Sets an option to check that the operands are closed volumes. 
   * By default, this option is turned off and both operands are assumed to
   * be closed. If this check is turned on and one of the operand is not
   * closed, the operator returns an error.
   *
   * For split of Operand 0 by Operand 1, set this option off.
   */
  void SetCheckOperands (const CATBoolean iCheckOperand);

  /** 
   * Turns on an option to accept self-intersecting operands.
   * By default this option is off.
   */
  inline void DoAcceptSelfIntersectingOperands (const CATBoolean iAcceptSelfIntersectingOperands);

  /**
   * Turns on an option to remove the triangles from the first operand without 
   * adding the triangles from the second operand (incomplete Boolean operation.)
   * By default, this option is turned off.
   */
  inline void DoNotAddSecondOperand (const CATBoolean iDoNotAdd);

/** @} */


public:

/** @name Setting operands
    @{ */

  /**
   * Sets the first operand on which the boolean operation is performed.  
   * The operand must be normalized by the instance of exact arithmetic.
   * This operand will be modified during the run operation and become the result of the operation.
   * @param iMesh
   *   The first operand.
   * @param iBarLayer
   *   An optional layer of bars that can be defined on the mesh.
   * @param iGriddedVertexPositions
   *   The vertex position layer for the mesh and the bars.
   */
  HRESULT SetFirstOperand (CATIPolyMesh* iMesh);

  /**
   * Sets the second operand on which the boolean operation is performed.  
   * The operand must be normalized by the instance of exact arithmetic.
   * The second operand will be modified during the run operation for computational purposes.  
   * @param iMesh
   *   The second operand.
   * @param iBarLayer
   *   An optional layer of bars that can be defined on the mesh.
   * @param iGriddedVertexPositions
   *   The vertex position layer for the mesh and the bars.
   */
  HRESULT SetSecondOperand (CATIPolyMesh* iMesh);

/** @} */


public:

/** @name Running the operator
    @{ */

  /**
   * Runs the operator and performs the operation requested between the two operands.
   * The three boolean operations that can be performed between the polyhedral operands are:
   *   A Union B
   *   A Intersection B
   *   A Subtraction B
   * where A and B are respectively the first and second operands.  Both operands are modified during Run () and 
   * A becomes the result of the boolean operation.  This method can be called iteratively after setting a new 
   * second operand.
   */
  HRESULT Run (CATPolyGriddedMeshAndBars& iOperand0, CATPolyGriddedMeshAndBars& iOperand1,
               CATPolyBooleanObserver* iObserver = 0);
  /**
   * Runs the operator.
   * For a union, intersection or subtraction boolean operation, the two operands must be watertight.
   *
   * If no boolean operation has been set (CATPolyBoolean::eBooleanNone), then the operator splits Operand 0 by Operand 1 according to 
   * intersection traces of the operands and their orientation.  Shells that are not intersecting are ignored.
   */
  HRESULT Run ();

  /**
   * Returns the error ID after failure of the operator. 
   * See CATPolyBoolean::BooleanError for a description of the various errors.
   * Returns CATPolyBoolean::eNoError when the operator runs successfully.
   */
  int GetErrorID () const;

  /**
   * Returns the error after failure of the operator.
   * Returns NULL if the operator runs successfully.
   * If an error is returned, the caller must release the object by calling the Release method.
   */
  CATPolyBooleanError* GetError () const;

/** @} */


public:

/** @name Deprecated methods
    @{ */

  /**
   * @deprecated
   */
  CATPolyBooleanOper (const CATPolyExactArithmetic* iExactArithmetic);

/** @} */

public:

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetCaptureObserver (CATPolyBooleanOperObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyBooleanOperObserver* GetCaptureObserver () const;

private:

  // Main run method.
  HRESULT RunBoolean ();

  HRESULT SetOperand (const int iOperand, CATIPolyMesh* iMesh, CATPolyGriddedMeshAndBars* iGriddedOperand);

  HRESULT ComputeMeshPartition ();

  HRESULT GetVertexPosition (const int iMesh, const int v, CATMathPoint& P) const;
  HRESULT SetVertexPosition (const int iMesh, const int v, const CATMathPoint& P);

  CATPolyBooleanError* GetErrorPrivate ();

  int* SetShellsToDelete (const CATPolyAttributeDomains* iShells,   // Shells from Mesh 0.
                          const CATPolyBooleanSegmentsOper* iSegmentsOper) const;

  int* SetShellsToAdd (const CATPolyAttributeDomains* iShells,      // Shells from Mesh 1.
                       const CATPolyBooleanSegmentsOper* iSegmentsOper) const;

  HRESULT DeleteTriangles (const CATListOfInt& triangles) const;

  HRESULT DeleteTriangles (CATPolyBooleanSegments2* iSegments,
                           CATPolyBooleanTriangulator* iTriangulator) const;

  HRESULT DeleteShells (const CATPolyAttributeDomains* iShells, const int* iShellsToDelete) const;

  HRESULT SetMaps (CATPolyBooleanSegments2* iSegments);

  void ResetMaps ();

  HRESULT AddTriangles (const CATListOfInt& triangles) ;

  HRESULT AddTriangles (CATPolyBooleanSegments2* iSegments,
                        CATPolyBooleanTriangulator* iTriangulator) ;

  HRESULT AddShells (const CATPolyAttributeDomains* iShells, const int* iShellsToAdd) ;

  HRESULT RemoveNonManifoldBars () const;

  HRESULT AnalyzeMesh (CATIPolyMesh* iMesh);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;
  CATMathBox _BoundingBox;

  CATBoolean _DoAcceptSelfIntersectingOperands;

  CATIPolyMesh* _Mesh[2];
  CATPolyGriddedMeshAndBars* _GriddedOperand[2];
  CATPolySPOctreePartition* _Partition[2];

  // Layer of positions of the triangles from one mesh w.r.t. other mesh.
  CATBucketsOfInt* _TrianglePositionLayer[2];  

  CATPolyMeshPartitionOper* _MeshPartition;

  // An option to turn on or off the set membership algorithm for shells that are not in contact.
  // By default this option is on.  Turn it off for optimization purposes for machining scenarios.
  CATBoolean _SetMembership; 

  // An option to turn on to keep the mesh partition (for a subsequent run) after a boolean operation.
  // By default this option is off and the mesh partition is deleted at the end of a boolean operation.
  CATBoolean _KeepPartition;

  // An option to turn on or off the check of the operands prior to running the boolean operator.
  // If this option is turned on and one of the operand is opened, the operator returns an error.
  // By default, this option is off.  Leave it off for optimization purposes for machining scenarios.
  CATBoolean _CheckOperands;

  // An option that blocks the addition of the triangles from the second operand to the
  // first operand.  By default, this is set to FALSE.
  CATBoolean _DoNotAddSecondOperand;

  int _BooleanOperation;

  CATPolyBooleanError* _BooleanError;

  CATListPV _triangleLists;

  CATListOfInt _barVertices0;
  CATListOfInt _barVertices1;

  // The list of non-manifold bars that have been created (by pair of vertices for Operand 0.)
  // The bars are analyzed and removed if possible.

  CATListOfInt _NonManifoldBars0;

  // Observer of boolean events.
  CATPolyBooleanObserver* _Observer;
  CATPolyBooleanOperObserver* _CaptureObserver;

  // A mapping of the vertices from Operand 1 to Operand 0.
  int* _MapVerticesFromOperand1ToOperand0; 

};


inline void CATPolyBooleanOper::DoAcceptSelfIntersectingOperands (const CATBoolean iAcceptSelfIntersectingOperands)
{
  _DoAcceptSelfIntersectingOperands = iAcceptSelfIntersectingOperands;
}

inline void CATPolyBooleanOper::DoNotAddSecondOperand (const CATBoolean iDoNotAdd)
{
  _DoNotAddSecondOperand = iDoNotAdd;
}

inline void CATPolyBooleanOper::SetCaptureObserver (CATPolyBooleanOperObserver* iObserver)
{
  _CaptureObserver = iObserver;
}

inline CATPolyBooleanOperObserver* CATPolyBooleanOper::GetCaptureObserver () const
{
  return _CaptureObserver;
}

#endif

