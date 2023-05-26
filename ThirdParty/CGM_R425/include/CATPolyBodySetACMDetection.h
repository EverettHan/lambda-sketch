// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySetACMDetection.h
//
//===================================================================
//
// Usage notes:
// Operator computing area contact model between two CATPolyBody's.
// This is a trimmed down version of CATPolyBodySetCollisionDetection that returns the triangles included in the intersection and makes no further computation of contact points and depth.
// DO NOT USE except for CDS-Dyn tests
//
//===================================================================

#ifndef CATPolyBodySetACMDetection_h
#define CATPolyBodySetACMDetection_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATBoolean.h"
#include "CATSysErrorDef.h"

#include "CATMapOfPtrToPtr.h"

// Interference
#include "CATPolyInterfACMOper.h"

#include "CATBVHTreeSet.h"

// Math
#include "CATTolerance.h"

class CATPolyBody;
class CATMathTransformation;
class CATPolyACMInterfList;
class CATBVHTree;
class CATPolyBodyBVHTreeSet;
class CATPolyPenetrationDataOper;

/**
 * Operator that computes collisions between every pair of Objects,
 * given as CATPolyBody's or groups of CATPolyBody's, among a set of
 * Objects.
 * Since some CATPolyBodies can be grouped together (compound
 * objects), Objects are given as CATBVHTree's. All these trees are
 * then added to a CATBVHTreeSet, which determine which pairs of
 * objects are potentially collinding.
 * Note about the memoryconsumption: The computation of the
 * CATBVHTreeSet obviously takes a bit time. Moreover, each
 * CATPolyBodies are duplicated according to their positions. In order
 * to be able to use a same CATPolyBody in several computations or
 * positions, the built of the CATBVHTreeSet and the positionned
 * geometry is saved and kept inside the operator and deleted only
 * when the operator itself is deleted. In order to save memory, it is
 * also possible to flush geometric data after each call by calling
 * the method @KeepTemporaryData with FALSE as argument.
 */

class CATPolyACMInterfList;
class CATIPolyInterfInputFacesFilter;

/**
 * Interface describing the clash operator.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyBodySetACMDetection
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyBodySetACMDetection(const CATTolerance & iTol = CATGetDefaultTolerance());
  CATPolyBodySetACMDetection(CATBVHTreeSet & ioObjectSet, const CATTolerance & iTol = CATGetDefaultTolerance());
  ~CATPolyBodySetACMDetection();

  /** 
   * Set a filter to manage frozen objects or objects 'out of the
   *  world' properly.
   */
  void SetFilter(CATIPolyInterfInputCoupleFilter * iFilter);

  /**
   * Set a filter for faces couples.
   * You can release it afterwards.
   */
  void SetFilter(CATIPolyInterfInputFacesFilter * iFilter);

  /**
   * Sets the operator that computes the penetration data (direction, depth and contacts)
   * between two clashing entities.
   * The operator should not be deleted until running collision detection.
   */
  void SetPenetrationDataOper (CATPolyPenetrationDataOper& iOper);

  /** Add an object to the set, in order to include it in the
   *  collision detection process.
   *@param iObjectIndex: An integer used as an index to refer to the
   *object to add to the set. It is used, as an example, to modify the
   *position of the object.
   */
  HRESULT AddObject(int iObjectIndex, CATBVHTree * iObject, const CATMathTransformation * iPosition = NULL);

  /** Remove a tree from the set.
   */
  HRESULT RemoveObject(int iObjectIndex);

  /** Change the position of an object from its index in the set.
   */
  HRESULT ModifyObjectPosition(int iObjectIndex, const CATMathTransformation & iPosition);

  /** Deactivate an object in the set. It will not be included in the
   *  collision detection process.
   */
  HRESULT DeactivateObject(int iObjectIndex);
  /** Reactivate an object in the set. It will be included again in
   *  the collision detection process.
   */
  HRESULT ActivateObject(int iObjectIndex);

  /**
   * Launch the computation of collisions between every pairs of
   * objects added in the set.
   * @return S_OK if the computation was successfull. In this case the
   *              interferences can be retrieved with the GetCollision
   *              function.
   */
  HRESULT Run();

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
  CATPolyACMInterfList * GetCollisions();

  /**
   * Specify wether the operator checks that one polybody given as
   * volumic is containing the other one.
   * @param checkMode: If TRUE the operator will check inclusions and return a collision in case of an inclusion.
   *                   If FALSE the operator will consider the volumes boundaries only (i.e. see volumes as surfaces).
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  HRESULT CheckInclusion(CATBoolean checkMode);

  /**
   * Specify whether the operator checks that polybodies given as volumic are really Watertights.
   * Watertight polybodies are required to obtain accurate inclusion detection.
   * Warnings are generated each time a volumic polybody is found to have flaws.
   * Enabling this mode has no effect if inclusion detection is not also enabled.
   * @param checkMode If TRUE the operator will check the volumic polybodies.
   *                  If FALSE it will not check if polybodies are watertight during the inclusion detection.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  HRESULT CheckWaterTightness(CATBoolean checkMode);

  /**
   * Specify the operator behaviour when a non water-tight rep is detected.
   * Enabling this mode has no effect if either inclusion detection or water-tigth check are nor enable.
   * @param treatMode if TRUE (not recommended) the operator still checks inclusion even if the object is non water-tight.
   *                  if FALSE (default) the operator doesn't check inclusion inside non watertight objects.
   */
  HRESULT CheckInclusionInsideOpenObjects(CATBoolean treatMode);

  /**
   * Specify the total number of threads that the operator can use to
   * detect collisions. The given number should be greater or equal to
   * 1 (uses 1 otherwise) and chosen appropriately according to the
   * number of threads that can be run simultaneously on the system.
   *@param iNbThreads: the number of threads to use to detects
   *collisions.
   */
  void UseMultipleThreads(unsigned int iNbThreads);

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
   * Swaps operands in each interference from the interferences list,
   * such that the first operand is always the one with the minimum
   * index.
   */
  void SwapInterferences(CATBoolean iSwapInterferences);

  /**
   * Sorts the list of interferences according to the indexes of the
   * operands contained in each interference, from minimal indices to
   * maximal ones. The sort is done firstly on the first index then on
   * the second one.
   */
  void SortInterferenceList(CATBoolean iSortList);

  /**
   * If true, the collision consists in a set of contact points and a
   * unique direction and a unique depth. If false, the result is one
   * independant direction and depth per contact point. Default is
   * true.
   */
  void SetOneDirectionPerCollision(CATBoolean iOneDirectionPerCollision);

private:

  CATBVHTreeSet * _TreeSet;
  CATBoolean _IsNewSet;

  CATBoolean _KeepData;

  CATPolyInterfACMOper _Operator;

  CATPolyACMInterfList * _ResultList;
};

#endif /* CATPolyBodySetACMDetection_h */
