// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfCollisionOper.h
//
//===================================================================
//
// Usage notes:
// Operator detecting collisions between BVHTreeSets.
// Works well on tree sets build upon Polybodies.
//
//===================================================================
//
// 2010-04-20 XXC: New
//===================================================================

#ifndef CATPolyInterfCollisionOper_h
#define CATPolyInterfCollisionOper_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATBoolean.h"

// Interference
#include "CATPolyInterferenceOper.h"
class CATPolyCollisionInterfList;
class CATPolyInterferenceRecorder;
class CATPolyCollisionInterfBuilderFactory;
class CATPolyPenetrationDataOper;
class CATIPolyInterfInputFacesFilter;

// Math
#include "CATTolerance.h"

/**
 * Interface describing the clash operator.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfCollisionOper : public CATPolyInterferenceOper
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyInterfCollisionOper(const CATTolerance & iTol = CATGetDefaultTolerance());
  virtual ~CATPolyInterfCollisionOper();

  /**
   * Sets the operator that computes the penetration data (direction, depth and contacts)
   * between two clashing entities.
   * The operator should not be deleted until running collision detection.
   */
  void SetPenetrationDataOper (CATPolyPenetrationDataOper& iOper);

  /**
   * Launch the computation of inteferences between the two trees.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetResult function.
   */
  virtual HRESULT Run();

  /**
   * After a call to Run, retrieve the clashes between the 2 trees.
   * For simple clash, all the interferences are clashes.
   * @return NULL if Run as not yet been called succesfully, the list of interferences otherwise.
   *         The resulting list is a CATPolyRefCounted and must released afterwards.
   */
  virtual CATPolyCollisionInterfList * GetCollisions();

  // /**
  //  * Specify whether the operator compute the intersection volumes (geometry + size) for each clash interference.
  //  * @param volumesMode TRUE to compute the intersection volumes, FALSE otherwise.
  //  * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
  //  *         because the functionnality is not yet implemented, E_FAIL otherwise.
  //  */
  // virtual HRESULT ComputeIntersectionVolumes(CATBoolean volumesMode);

  // /**
  //  * @return Whether the operator computes the intersection volumes for each clash.
  //  */
  // virtual CATBoolean IsComputingIntersectionVolumes() const;

  /**
   * Specify whether the operator checks that polybodies given as volumic are really Watertights.
   * Watertight polybodies are required to obtain accurate inclusion detection.
   * Warnings are generated each time a volumic polybody is found to have flaws.
   * Enabling this mode has no effect if inclusion detection is not also enabled.
   * @param checkMode if TRUE the operator will check the volumic polybodies.
   *                 If FALSE it will compute all of them.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT CheckWaterTightness(CATBoolean checkMode);

  /**
   * @return Whether to operator checks that the volumic polybodies are watertight.
   */
  virtual CATBoolean IsCheckingWaterTightness() const;

  /**
   * Specify the operator behaviour when a non water-tight rep is detected.
   * Enabling this mode has no effect if either inclusion detection or water-tigth check are nor enable.
   * @param treatMode if TRUE (not recommended) the operator still checks inclusion even if the object is non water-tight.
   *                  if FALSE (default) the operator doesn't check inclusion inside non watertight objects.
   */
  virtual HRESULT CheckInclusionInsideOpenObjects(CATBoolean treatMode);

  /**
   * @return The way non water-tight objects are treated.
   */
  virtual CATBoolean IsCheckingInclusionInsideOpenObjects() const;

  /**
   * Swaps operands in each interference from the interferences list,
   * such that the first operand is always the one with the minimum
   * index.
   * NOTICE: Works only if one get the collisions list through the
   * @GetCollisions method. If one uses the GetResult method, from
   * CATPolyInterferenceOper, one needs to apply the swap on the list
   * returned.
   */
  void SwapInterferences(CATBoolean iSwapInterferences);

  /**
   * Sorts the list of interferences according to the indexes of the
   * operands contained in each interference, from minimal indices to
   * maximal ones. The sort is done firstly on the first index then on
   * the second one.
   * NOTICE: Works only if one get the collisions list through the
   * @GetCollisions method. If one uses the GetResult method, from
   * CATPolyInterferenceOper, one needs to apply the sort on the list
   * returned.
   */
  void SortInterferenceList(CATBoolean iSortList);

  /** 
   * Set a filter for faces couples.
   * You can release it afterwards.
   */
  void SetFacesFilter(CATIPolyInterfInputFacesFilter * iFilter);

  /**
   * If true, the collision consists in a set of contact points and a
   * unique direction and a unique depth. If false, the result is one
   * independant direction and depth per contact point.
   */
  void SetOneDirectionPerCollision(CATBoolean iOneDirectionPerCollision);

  /** Debug */
  virtual CATPolyInterfCollisionOper * CastToCollisionOper(){return this;}

protected:
  /**
   * @nodoc
   */
  const char * GetOperatorName() const;


private:

  void InitFirstRun();

private:

  CATBoolean _bIsCheckingWaterTightness;
  CATBoolean _bIsCheckingInclusionInsideOpenObjects;

  CATBoolean _FirstRun;

  CATPolyCollisionInterfBuilderFactory * _BuildFact;

  CATBoolean _SwapInterference;
  CATBoolean _SortInterference;
};

#endif /* CATPolyInterfCollisionOper_h */
