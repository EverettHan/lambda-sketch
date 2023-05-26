// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfClashContactClearanceOper.h
//
//===================================================================
//
// Usage notes:
// Operator detecting clash, contact and clearance between BVHTreeSets.
// Works well on tree sets build upon Polybodies.
// For visu tree sets, use CATPolyVisuSimpleClashOper.h
//
//===================================================================
//
// Jan 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterfClashContactClearanceOper_h
#define CATPolyInterfClashContactClearanceOper_h

#include "CATPolyBoundingVolumeOperators.h"

#include "CATBoolean.h"
#include "CATPolyInterfClashContactOper.h"

class CATPolyClearanceInterfList;

// Math
#include "CATTolerance.h"

/**
 * Operator detecting clash, contact and clearance between BVHTreeSets.
 * Works well on tree sets build upon Polybodies.
 * For visu tree sets, use CATPolyVisuSimpleClashOper.h
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfClashContactClearanceOper : public CATPolyInterfClashContactOper
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyInterfClashContactClearanceOper(const CATTolerance & iTol = CATGetDefaultTolerance());

  CATPolyInterfClashContactClearanceOper( const CATPolyInterfClashContactClearanceOper& iOther );

  virtual ~CATPolyInterfClashContactClearanceOper();

  /**
   * Launch the computation of inteferences between the two trees.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetResult function.
   */
  virtual HRESULT Run();

  /**
   * After a call to Run, retrieve the clearances areas between the 2 trees.
   * @return NULL if Run as not yet been called succesfully, the list of interferences otherwise.
   *         The resulting list is a CATPolyRefCounted and must released afterwards.
   */
  virtual CATPolyClearanceInterfList * GetClearanceInterferences();

  /**
   * Specify the clearance value to use for the interference computation
   * @param clearance positive double specifyng the tolerance to use.
   * @return S_OK if the clearance is successfully set, E_NOTIMPL if the clearance can not be taken into account
   *         because the functionnality is not yet implemented, E_INVALIDARG if the clearance value
   *         is strictly negative, E_FAIL otherwise.
   */
  virtual HRESULT SetClearanceTolerance(double clearance);

  /**The clearance tolerance used by the operator.
   */
  virtual double GetClearanceTolerance() const;

  /**
   * Specify whether the operator compute the triangles involved in each clearance interference.
   * @param meshMode TRUE to compute the clearance meshes, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeClearanceMeshes(CATBoolean meshMode);

  /**
   * @return Whether the operator computes the meshes in clearance for each contact.
   */
  virtual CATBoolean IsComputingClearanceMeshes() const;

  /**
   * Specifies whether the operator compute refined meshes approximating exact clearance areas.
   * @param refinedMode TRUE to compute the refined meshes, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeRefinedClearanceAreas(CATBoolean refinedMode);

  /**
   * @return Whether the operator computes the refined meshes for each clash.
   */
  virtual CATBoolean IsComputingRefinedClearanceAreas() const;

  /**
   * Specifies whether the operator compute the minimum distance between each clearance areas.
   * @param distMode TRUE to compute the minimum distances, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeMinDistance(CATBoolean distMode);

  /**
   * @return Whether the operator computes the minimum distance between each clearance areas.
   */
  virtual CATBoolean IsComputingMinDistance() const;

  virtual CATPolyInterfClashContactClearanceOper* Clone() const;

  /** Debug */
  virtual CATPolyInterfClashOper *                 CastToClashOper()                 {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactOper *          CastToClashContactOper()          {return this;}
  /** Debug */
  virtual CATPolyInterfClashClearanceOper *        CastToClashClearanceOper()        {return 0;}
  /** Debug */
  virtual CATPolyInterfClashContactClearanceOper * CastToClashContactClearanceOper() {return this;}

protected:

  /**
   * Try to guess what would be the best memory consumption mode, depending on the
   * currently available memory on the computer. We will try to avoid pagination 
   * at all cost. If plenty of memory is available then LOW, MEDIUM, etc... modes 
   * may be returned. Note that more consuming modes are generaly much faster than
   * MINIMUM.
   * @return S_OK if we successfully guessed what would be best, E_NOTIMPL otherwise.
   *         In case of failure, oMemoryHint falls back to MINIMUM.
   */
  virtual HRESULT GuessBestMemoryConsumptionHint(MemoryConsumption & oMemoryHint) const;

  /**
   * @nodoc
   */
  const char * GetOperatorName() const;

private:

  CATBoolean _bIsComputingClearanceMeshes;
  CATBoolean _bIsComputingMinDistance;
  CATBoolean _bIsComputingRefinedClearanceMeshes;
  double _dClearance;

};

#endif /* CATPolyInterfClashContactClearanceOper_h */
