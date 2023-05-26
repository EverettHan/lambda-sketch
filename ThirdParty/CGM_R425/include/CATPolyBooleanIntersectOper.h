// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanIntersectOper.h
// Header definition of CATPolyBooleanIntersectOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// January 2006 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanIntersectOper_H
#define CATPolyBooleanIntersectOper_H

#include "CATPolyBooleanOperators.h"
#include "CATPolyBoolean.h"
#include "CATMathBox.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"  // For the definition of HRESULT.

class CATIPolyMesh;
class CATPolyBars;
class CATPolyGriddedMeshAndBars;
class CATPolyGriddedMeshAndBarsConst;
class CATPolyBooleanOper;
class CATPolyBooleanSegments2;
class CATPolyBooleanSegmentsOper;
class CATPolyBooleanTriangulator;
class CATPolyBooleanError;
class CATPolyBooleanObserver;
class CATPolyMeshPartitionOper;
class CATPolyAttributeDomains;
class CATPolyExactArithmetic;
class CATMapOfIntToInt;
class CATBucketsOfInt;


/*
Main class to calculate boolean intersections (** interior only **) between two polyhedral bodies.  This 
operator can only work if one operand is a watertight volume since the interior cannot be defined otherwise.
If the two operands are watertight volumes with an intersection having a non-empty interior, the result is a 
volume representing this interior.  Volumes simply in contact are considered not intersecting by this operator.
If one operand is a watertight volume and the other a surface, the result is the portion of the surface
which is inside the volume but not on the volume.

The main method of this operator is Run ().  The bounding box should be set prior to running the operator.
Each operand is composed of the mesh, a container of bars and a flag indicating if the mesh is closed.
To clip an operand, set the clipping volume as the second operand.
The result is represented by one of the initial operands.  Both operands are edited during the computation of
the intersection.  Run () fails if both operands are open.

Volumes and surfaces with multiple shells and wires are supported.
*/
class ExportedByCATPolyBooleanOperators CATPolyBooleanIntersectOper
{

public :

  /**
  * Constructor.  An instance of exact arithmetic must be set into the operator.
  * This instance should have the maximum range of the coordinates set.
  */
  CATPolyBooleanIntersectOper (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyBooleanIntersectOper ();

  /**
   * Sets the bounding box of the domain that contains the operands.
   * The bounding box must be normalized by the instance of exact arithmetic.
   * The bounding box must be set before setting the operands.
   */
  HRESULT SetBoundingBox (const CATMathBox& iBoundingBox);

  /** 
   * Turn on an option to accept self-intersecting operands.
   * By default this option is off.
   */
  inline void DoAcceptSelfIntersectingOperands (const CATBoolean iAcceptSelfIntersectingOperands);

public:

  /**
   * Calculate the intersection between two operands, iMesh0 and iMesh1 with their optional layers of bars.
   * A flag should indicate whether each operand should be processed as a volume.
   * In case of clipping, the second operand should be the clipping volume.
   * An optional observer of boolean events can be set to update any layer on the mesh and the bars.
   */
  HRESULT Run (CATIPolyMesh& iMesh0, CATPolyBars* iBars0, const CATBoolean isVolume0, // Operand 0.
               CATIPolyMesh& iMesh1, CATPolyBars* iBars1, const CATBoolean isVolume1, // Operand 1 (clipping vol).
               CATPolyBooleanObserver* iObserver = 0);  // Operand 1.

  /**
   * Calculate the intersection between two operands, iMesh0 and iMesh1 with their optional layers of bars.
   * A flag should indicate whether each operand should be processed as a volume.
   * In case of clipping, the second operand should be the clipping volume.
   * An optional observer of boolean events can be set to update any layer on the mesh and the bars.
   */
  HRESULT Run (CATPolyGriddedMeshAndBars& iGriddedOperand0, const CATBoolean isVolume0, // Operand 0.
               CATPolyGriddedMeshAndBars& iGriddedOperand1, const CATBoolean isVolume1, // Operand 1 (clipping vol)
               CATPolyBooleanObserver* iObserver = 0);

public:

  /**
   * Returns the intersection result.
   * At least one operand must be a watertight volume.  The result if one of the initial operands.
   */
  CATIPolyMesh* GetResult () const;

  /*
   * Returns the error ID after failure of the operator. 
   * See CATPolyBoolean::BooleanError for a description of the various errors.
   * Returns CATPolyBoolean::eNoError when the operator runs successfully.
   */
  int GetErrorID () const;

  /*
   * Returns the error after failure of the operator.
   * Returns NULL if the operator runs successfully.
   * If an error is returned, the caller must release the object by calling the Release method.
   */
  CATPolyBooleanError* GetError () const;

public:

  /*
   * Return TRUE if the result of the operation is a volume and FALSE otherwise.
   */
  CATBoolean IsResultAVolume () const;

private:

  HRESULT SetOperand (const int iOperand, CATPolyGriddedMeshAndBars& iGriddedOperand, const CATBoolean iIsClosed);

  HRESULT ComputeMeshPartition (CATPolyGriddedMeshAndBarsConst& iGriddedOperand0,
                                CATPolyGriddedMeshAndBarsConst& iGriddedOperand1);

  // Main run method.
  HRESULT RunPrivate (CATPolyBooleanObserver* iObserver = 0);
  HRESULT RunVolumeVolume ();
  HRESULT RunVolumeSurface (CATPolyGriddedMeshAndBarsConst& iGriddedOperand0, 
                            CATPolyGriddedMeshAndBars& iGriddedOperand1);

  CATPolyBooleanError* GetErrorPrivate ();

  int* SetShellsToDelete (CATPolyGriddedMeshAndBarsConst& iGriddedOperand0,  // Volume
                          CATPolyGriddedMeshAndBars& iGriddedOperand1,        // Surface
                          const CATPolyAttributeDomains* iShells1, // Shells from Mesh 1.
                          const CATPolyBooleanSegmentsOper* iOper) const;

  HRESULT DeleteTriangles (CATIPolyMesh& iMesh, CATPolyBars* iBars, const CATListOfInt& triangles) const;

  HRESULT DeleteTriangles (CATIPolyMesh* iMesh,
                           CATPolyBooleanSegments2* iSegments,
                           CATPolyBooleanTriangulator* iTriangulator,
                           CATBucketsOfInt* iTrianglePositionLayer) const;

  HRESULT DeleteShells (CATIPolyMesh* iMesh, 
                        const CATPolyAttributeDomains* iShells, 
                        const int* iShellsToDelete) const;

private:

  const CATPolyExactArithmetic& _ExactArithmetic;
  CATMathBox _BoundingBox;

  CATBoolean _DoAcceptSelfIntersectingOperands;

  CATIPolyMesh* _Mesh[2];
  CATPolyBars* _Bars[2];
  CATPolyGriddedMeshAndBars* _GriddedOperand[2];

  int _MeshType[2];

  CATPolyBars* _BarsToDelete[2];
  CATPolyGriddedMeshAndBars* _GriddedOperandsToDelete[2];

  CATPolyMeshPartitionOper* _MeshPartition;

  CATPolyBooleanOper* _BooleanOper; // Boolean operator to compute the intersection between two volumes.
  CATIPolyMesh* _MeshResult;        // Result of the boolean operation.

  CATPolyBooleanError* _BooleanError;

  // Observer of boolean events.
  CATPolyBooleanObserver* _Observer;

};

inline void CATPolyBooleanIntersectOper::DoAcceptSelfIntersectingOperands (const CATBoolean iAcceptSelfIntersectingOperands)
{
  _DoAcceptSelfIntersectingOperands = iAcceptSelfIntersectingOperands;
}

#endif

