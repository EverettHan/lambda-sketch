// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfClashOper.h
//
//===================================================================
//
// Usage notes:
// Operator detecting clashes between BVHTreeSets.
// Works well on tree sets build upon Polybodies.
// For visu tree sets, use CATPolyVisuSimpleClashOper.h
//
//===================================================================
//
// Jan 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterfClashOper_h
#define CATPolyInterfClashOper_h

#include "CATPolyBoundingVolumeOperators.h"

// Interference
#include "CATPolyInterferenceOper.h"
class CATPolyClashInterfList;

// Math
#include "CATTolerance.h"

// System
#include "CATBoolean.h"

/**
 * Interface describing the clash operator.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfClashOper : public CATPolyInterferenceOper
{
public:


  /**
   * Constructor and destructor.
   */
  CATPolyInterfClashOper(const CATTolerance & iTol = CATGetDefaultTolerance());

  CATPolyInterfClashOper( const CATPolyInterfClashOper& iOther );

  virtual ~CATPolyInterfClashOper();

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
  virtual CATPolyClashInterfList * GetClashes();

  /**
   * Specify whether the operator compute the intersection curves for each clash interference.
   * @param curvesMode TRUE to compute the intersection curves, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeIntersectionCurves(CATBoolean curvesMode);

  /**
   * @return Whether the operator computes the intersection curves for each clash.
   */
  virtual CATBoolean IsComputingIntersectionCurves() const;

  /**
   * Specify whether the operator compute the intersection volumes (geometry + size) for each clash interference.
   * Note: For this to work, input bodies need to be solid bodies (volume type), and watertight
   * (high quality meshes from V6 tessellation for example.)
   * Note that this option is not compatible with multithread. 
   *      Multithread is deactivated if ComputeIntersectionVolumes is set.
   * @param volumesMode TRUE to compute the intersection volumes, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeIntersectionVolumes(CATBoolean volumesMode);

  /**
   * @return Whether the operator computes the intersection volumes for each clash.
   */
  virtual CATBoolean IsComputingIntersectionVolumes() const;

  /**
   * Specify whether the operator compute the penetration vector for each clash interference.
   * Enabling penetration vector forces the computation of intersection curves since
   * they are required for the computation.
   * @param penetrationVectorMode TRUE to compute the intersection volumes, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputePenetrationVectors(CATBoolean penetrationVectorMode);

  /**
   * @return Whether the operator computes the penetration vector for each clash.
   */
  virtual CATBoolean IsComputingPenetrationVectors() const;

  /**
   * Enum listing the different possibilities used to choose the penetration vector direction.
   */
  enum PenetrationVectorDirection
  {
    /**
     * Depth penetration computes the shorter vector that must be applied the smaller object
     * in order to remove it from the larger.
     */
    REMOVE_SMALLER_FROM_LARGER = 0,

    /**
     * Depth penetration computes the shorter vector that must be applied the first object any created interference
     * to remove it from the second
     */
    REMOVE_OBJECT1_FROM_OBJECT2,

     /**
      * Depth penetration computes the shorter vector that must be applied the second object any created interference
      * to remove it from the first.
      */
    REMOVE_OBJECT2_FROM_OBJECT1
  };

  /**
   * Specify how the choice for the depth penetration direction is done in CATPolyClashInterf classes.
   * The choice determines the result of the GetDepthPenetrationDirection() method of these objects.
   * @param dir any of the values of the enum. Default is REMOVE_SMALLER_FROM_LARGER.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT SetPenetrationVectorDirection(PenetrationVectorDirection dir);

  /**
   * @return Method used to choose the penetration vector direction.
   */
  virtual PenetrationVectorDirection GetPenetrationVectorDirection() const;

  /**
   * Specify whether the operator compute all the interferences or stops when the first clash interference is found.
   * @param stopMode if TRUE the operator will stop when the first clash interference is found.
   *                 If FALSE it will compute all of them.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT StopAtFirstClash(CATBoolean stopMode);

  /**
   * @return Whether the operator stops when the first clash interference is found or not.
   */
  virtual CATBoolean IsStoppingAtFirstClash() const;

  /**
   * Specify whether the operator checks that polybodies given as volumic are really Watertights.
   * Watertight polybodies are required to obtain accurate inclusion detection.
   * Warnings are generated each time a volumic polybody is found to have flaws.
   * Enabling this mode has no effect if inclusion detection is not also enabled.
   * @param checkMode if TRUE (default) the operator will check the volumic polybodies.
   *                  if FALSE it will compute all of them.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT CheckWaterTightness(CATBoolean checkMode);

  /**
   * @return Whether the operator checks that the volumic polybodies are watertight.
   */
  virtual CATBoolean IsCheckingWaterTightness() const;

  /**
   * Specify whether the operator reports a warning when the input polybody for inclusion is surfacic.
   * If either A or B is surfacic and inclusion is asked, a warning is reported.
   * Enabling this mode has no effect if inclusion detection is not also enabled.
   * @param warnMode if TRUE the operator will report a warning.
   *                 if FALSE (default) no warning is reported.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT AddWarningForSurfacicInclusion(CATBoolean warnMode);

  /**
   * @return Whether the operator reports a warning when the input polybody for inclusion is surfacic.
   */
  virtual CATBoolean WarningForSurfacicInclusion() const;

  /**
   * Specify the operator behaviour when a non water-tight rep is detected.
   * Enabling this mode has no effect if either inclusion detection or water-tigth check are nor enable.
   * @param treatMode if TRUE (default) the operator still checks inclusion even if the object is non water-tight.
   *                  if FALSE the operator doesn't check inclusion inside non watertight objects.
   */
  virtual HRESULT CheckInclusionInsideOpenObjects(CATBoolean treatMode);

  /**
   * @return The way non water-tight objects are treated.
   */
  virtual CATBoolean IsCheckingInclusionInsideOpenObjects() const;

  virtual CATPolyInterfClashOper* Clone() const;

  /** Debug */
  virtual CATPolyInterfClashOper *                 CastToClashOper()                 {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactOper *          CastToClashContactOper()          {return 0;}
  /** Debug */
  virtual CATPolyInterfClashContactClearanceOper * CastToClashContactClearanceOper() {return 0;}

protected:
  /**
   * @nodoc
   */
  const char * GetOperatorName() const;

private:

  CATBoolean _bIsComputingIntersectionCurves;
  CATBoolean _bIsComputingDepthPenetration;
  PenetrationVectorDirection _ePenetrationDir;
  CATBoolean _bIsStoppingAtFirstClash;
  CATBoolean _bIsCheckingWaterTightness;
  CATBoolean _bIsCheckingInclusionInsideOpenObjects;
  CATBoolean _bAddWarningForSurfacicInclusion;

};

#endif /* CATPolyInterfClashOper_h */
