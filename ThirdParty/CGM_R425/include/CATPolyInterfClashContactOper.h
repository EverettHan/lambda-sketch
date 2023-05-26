// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfClashContactOper.h
//
//===================================================================
//
// Usage notes:
// Operator detecting clashes and contact between BVHTreeSets.
// Works well on tree sets build upon Polybodies.
// For visu tree sets, use CATPolyVisuSimpleClashOper.h
//
//===================================================================
//
// Jan 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterfClashContactOper_h
#define CATPolyInterfClashContactOper_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATBoolean.h"

// BVH
class CATBVHTreeSet;
class CATBVHNodeConst;

// Interference
#include "CATPolyInterfClashOper.h"
class CATPolyContactInterfList;
class CATIPolyInterference;
class CATPolyInterfWarningList;

// Math
#include "CATTolerance.h"

/**
 * Operator detecting clashes and contact between BVHTreeSets.
 * Works well on tree sets build upon Polybodies.
 * For visu tree sets, use CATPolyVisuSimpleClashOper.h
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfClashContactOper : public CATPolyInterfClashOper
{
public:


  /**
   * Constructor and destructor.
   */
  CATPolyInterfClashContactOper(const CATTolerance & iTol = CATGetDefaultTolerance());

  CATPolyInterfClashContactOper( const CATPolyInterfClashContactOper& iOther );

  virtual ~CATPolyInterfClashContactOper();

  /**
   * Set the first data to be used by the operator.
   * To test only the first set against itself, set the second operand
   * to NULL.
   * @param data1 first set of data.
   */
  virtual void SetFirstOperand(CATBVHTreeSet * data1);
  
  /**
   * Set the seond set of data to be used by the operator.
   * If not set or set to NULL, the operator will test the first set
   * against itself.
   * @param data2 second set of data.
   */
  virtual void SetSecondOperand(CATBVHTreeSet * data2);

  /**
   * Launch the computation of inteferences between the two trees.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetResult function.
   */
  virtual HRESULT Run();

  /**
   * After a call to Run, retrieve the contacts between the 2 trees.
   * @return NULL if Run as not yet been called succesfully, the list of interferences otherwise.
   *         The resulting list is a CATPolyRefCounted and must released afterwards.
   */
  virtual CATPolyContactInterfList * GetContacts();

  /**
   * Specify whether the operator computes the triangles involved in each contact interference.
   * @param meshMode TRUE to compute the contact meshes, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeContactMeshes(CATBoolean meshMode);

  /**
   * @return Whether the operator computes the meshes in contact for each contact.
   */
  virtual CATBoolean IsComputingContactMeshes() const;

  /**
   * Specifies whether the operator computes refined meshes approximating exact contact areas.
   * @param meshMode TRUE to compute the refined meshes, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeRefinedContactAreas(CATBoolean meshMode);

  /**
   * @return Whether the operator computes the refined meshes for each contact.
   */
  virtual CATBoolean IsComputingRefinedContactAreas() const;

  /**
   * Specifies whether the operator computes two points realizing the contact
   * for each contact interferences.
   * @param witnessMode TRUE to compute the witness points, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT ComputeWitnessPoints(CATBoolean witnessMode);

  /**
   * @return Whether the operator computes the witness points for each contact.
   */
  virtual CATBoolean IsComputingWitnessPoints() const;

  /**
   * Active a mode that will consider the clash as contact.
   * 
   * */
  virtual HRESULT ComputeClashAsContact(CATBoolean bClashAsContact);
  virtual CATBoolean IsComputingClashAsContact() const;

  /**
   * Specifies whether the operator checks that generated interferences are stable or not.
   * An interference is not stable if a slight displacement of the operands is likely
   * to change the interference status (from Contact to Clash for instance).
   * This mode can be used to find the interference that may change between two interference solvers.
   * If the stability mode is enabled, a warning is generated each time an unstable interference is found.
   * WARNING: Enabling this mode migth modify silently some other options of the operator.
   * WARNING: This mode only works on CLASH + CONTACT operators not on the Clearance one.
   * @param checkMode TRUE to check interference stability, FALSE otherwise.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT CheckInterferenceStability(CATBoolean checkMode);

  /**
   * @return Whether the operator check interference stability.
   */
  virtual CATBoolean IsCheckingInterferenceStability() const;

  /**
   * Class used to specify the accuracy used for contact.
   */
  class AccuracyChooser
  {
  public:

    AccuracyChooser() {}
    virtual ~AccuracyChooser() {}

    /**
     * @param sag sag of the current object.
     * @return accuracy to be used. For instance to use a fixed accuracy
     *         just return a constant value. The result must be positive.
     */
    virtual double GetAccuracy(double sag) = 0;
  };

  /**
   * Specifies the accuracies to use for contact detection.
   * By default the chooser is NULL and in this case the sag is used as the accuracy.
   * Different accuracies depending on the sag can also be used.
   * The operator does not claims ownership on the object, but it should remain
   * valid during the operator run.
   * @param chooser if not NULL this chooser will be used to get the accuracy.
   * @return S_OK if the chooser is successfully set, E_NOTIMPL if the chooser can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT SetContactAccuracyChooser(AccuracyChooser * chooser);

  /**
   * @return the current object used to specifies the accuracy.
   */
  virtual AccuracyChooser * GetContactAccuracyChooser();

  virtual CATPolyInterfClashContactOper* Clone() const;

  /** Debug */
  virtual CATPolyInterfClashOper *                 CastToClashOper()                 {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactOper *          CastToClashContactOper()          {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactClearanceOper * CastToClashContactClearanceOper() {return 0;}

protected:

  // Get the maximum sag of a tree set
  double GetMaxSag(CATBVHTreeSet * treeSet, AccuracyChooser & chooser) const;

  HRESULT Run( double additionalTolerance );

  HRESULT StandardRun();

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

  //---------------------------------------------------------
  HRESULT RunWithStablityCheck();

  HRESULT CompareWithOffsetList(CATPolyInterferenceList * refList, double offset, CATPolyInterfWarningList & warningList);

  HRESULT CompareWithOffsetList(CATPolyInterferenceList * refList, CATPolyInterferenceList * offsetList,
                                CATPolyInterfWarningList & warningList);

  HRESULT GenerateWarningsFromEmptyList(CATPolyInterferenceList & list, CATPolyInterfWarningList & warningList);

  void CheckInterferenceExistence(CATIPolyInterference & interf, CATPolyInterferenceList * offsetList,
                                  CATPolyInterfWarningList & warningList);

  void GenerateStabilityWarning(int firstObjectId, int secondObjectId, CATPolyInterfWarningList & warningList);

  static const double _sdUnstabilityRatio;
  //---------------------------------------------------------
  CATBoolean _bIsComputingContactMeshes;
  CATBoolean _bIsComputingWitnessPoints;
  CATBoolean _bIsCheckingInterfStability;
  CATBoolean _bComputeRefinedContactAreas;
  AccuracyChooser * _pAccuracyChooser;
  CATBoolean _RecomputeAccuracy;
  double _AdditionalAccuracy;
  CATBoolean _bClashAsContact;
  //---------------------------------------------------------
};

#endif /* CATPolyInterfClashContactOper_h */
