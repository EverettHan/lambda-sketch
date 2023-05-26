// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyCollisionDetection.h
//
//===================================================================
//
// Usage notes:
// Operator detecting collisions between two CATPolyBody's.
//
//===================================================================
//
// 2010-04-23 XXC: New
//===================================================================

#ifndef CATPolyBodyCollisionDetection_h
#define CATPolyBodyCollisionDetection_h

#include "CATPolyBoundingVolumeOperators.h"

// Interference
class CATPolyCollisionOper;
class CATPolyBody;
class CATMathTransformation;
class CATPolyCollisionInterfList;
class CATBVHTreeSet;
class CATPolyBodyBVHTreeSet;
class CATPolyInterfDecoratedTree;
class CATPolyBodyCollisionDetectionData;

// Poly math
#include "CATMapOfPtrToPtr.h"

// Math
#include "CATTolerance.h"

// System
#include "CATBoolean.h"
#include "CATSysErrorDef.h"

/**
 * Operator that computes collisions between two CATPolyBodies.
 * Note about the memory consumption: every CATPolyBody given to the
 * operator imply the computation of a Bounding Volume Hierarchy
 * (BVH), to accelerate the computation. Since the build of a BVH
 * takes a bit time, in order to be able to use a same CATPolyBody in
 * several computations, even in another position or with several
 * different CATPolyBody's, the built BVH is saved inside the operator
 * and associated to the CATPolyBody that has generated it. This thus
 * avoid to build it again, later, when this CATPolyBody is
 * re-used. In order to save memory, you can empty some saved BVH's with
 * the method @FlushMemory.
 * You can also change this default behaviour by calling the method
 * @KeepTemporaryData with FALSE as argument.
 */

class CATPolyCollisionInterfList;

/**
 * Interface describing the clash operator.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyBodyCollisionDetection
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyBodyCollisionDetection(const CATTolerance & iTol = CATGetDefaultTolerance(), CATBoolean iOneDirectionPerClash = TRUE);
  ~CATPolyBodyCollisionDetection();

  /**
   * Launch the computation of collisions between the two given CATPolyBody's.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetCollision function.
   */
  HRESULT Run(CATPolyBody * iPolyBody1, CATPolyBody * iPolyBody2,
              CATMathTransformation * iPosition1 = NULL, CATMathTransformation * iPosition2 = NULL);

  /**
   * Indicate if the two given poly bodies, after having run the operator,
   * are colliding or not.
   */
  CATBoolean AreColliding();

  /**
   * After a call to Run, retrieve the clashes between the 2 trees.
   * For simple clash, all the interferences are clashes.
   * @return NULL if Run as not yet been called succesfully, the list of interferences otherwise.
   *         The resulting list is a CATPolyRefCounted and must released afterwards.
   */
  CATPolyCollisionInterfList * GetCollisions();

  /**
   * Keep, between each call, the temporary structures (bounding
   * volume hierarchies, BVH) used to accelerate the computation of
   * the collisions. This avoids to compute again these structures
   * when calling the operator several time on the same
   * CATPolyBody. It is particularly usefull in the context of a set
   * of CATPolyBody's to collide several time each CATPolyBody of a
   * set with the others. But it also consequently occupy some
   * memory. Use the @FlushMemory function to free the memory used by
   * the BVH. Default value is "Keep temporary data".
   *@param iKeepData: if equal to TRUE, tells the operator to keep
   *temporary BVH's, if equal to FALSE, tells the operator to flush
   *the BVH's after each call.
   */
  void KeepTemporaryData(CATBoolean iKeepData);

  /**
   * Remove the BVH associated to the given CATPolyBody. If the
   * CATPolyBody is null (default parameter if omited), flush all the
   * saved BVH.
   *@param iPolyBody: a pointer to a CATPolyBody to indicate the
   *corresponding BVH to remove (and delete). If null, every BVH is
   *removed.
   */
  HRESULT FlushMemory(const CATPolyBody * iPolyBody = NULL);

private:
  HRESULT GetTree(CATPolyBodyCollisionDetectionData *& oTreeSet, CATPolyBody * iPolyBody);

private:

  CATBoolean _KeepData;

  CATMapOfPtrToPtr _MapPolyBodyToTree;
  const CATTolerance & m_Tol;

private:
  CATPolyCollisionOper & _Operator;

};

#endif /* CATPolyBodyCollisionDetection_h */
