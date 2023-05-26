// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuClashContactOper.h
//
//===================================================================
//
// Usage notes:
// Operator detecting clash and contact between visu rep.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyVisuClashContactOper_h
#define CATPolyVisuClashContactOper_h

#include "PolyVisuClash.h"

// Interference
#include "CATPolyVisuSimpleClashOper.h"
class CATIPolyInterfDecoPolyBodyFactory;

// Math
#include "CATTolerance.h"

/**
 * Operator detecting clash and contact between visu rep.
 */
class ExportedByPolyVisuClash CATPolyVisuClashContactOper : public CATPolyVisuSimpleClashOper
{
public:


  /**
   * Constructor and destructor.
   */
  CATPolyVisuClashContactOper(const CATTolerance & iTol = CATGetDefaultTolerance());
  CATPolyVisuClashContactOper(const CATPolyVisuClashContactOper & iCopy);
  virtual ~CATPolyVisuClashContactOper();

  /**
   * Launch the computation of inteferences between the two trees.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetResult function.
   */
  virtual HRESULT Run();

  // Readd Contact methods

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual CATPolyContactInterfList * GetContacts()
    {return CATPolyVisuSimpleClashOper::GetContacts();}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual HRESULT ComputeContactMeshes(CATBoolean meshMode)
    {return CATPolyVisuSimpleClashOper::ComputeContactMeshes(meshMode);}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual CATBoolean IsComputingContactMeshes() const
    {return CATPolyVisuSimpleClashOper::IsComputingContactMeshes();}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual HRESULT ComputeRefinedContactAreas(CATBoolean volumesMode)
    {return CATPolyVisuSimpleClashOper::ComputeRefinedContactAreas(volumesMode);}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual CATBoolean IsComputingRefinedContactAreas() const
    {return CATPolyVisuSimpleClashOper::IsComputingRefinedContactAreas();}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual HRESULT ComputeWitnessPoints(CATBoolean witnessMode)
    {return CATPolyVisuSimpleClashOper::ComputeWitnessPoints(witnessMode);}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual CATBoolean IsComputingWitnessPoints() const
    {return CATPolyVisuSimpleClashOper::IsComputingWitnessPoints();}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual HRESULT CheckInterferenceStability(CATBoolean checkMode)
    {return CATPolyVisuSimpleClashOper::CheckInterferenceStability(checkMode);}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual CATBoolean IsCheckingInterferenceStability() const
    {return CATPolyVisuSimpleClashOper::IsCheckingInterferenceStability();}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual HRESULT SetContactAccuracyChooser(AccuracyChooser * chooser)
    {return CATPolyVisuSimpleClashOper::SetContactAccuracyChooser(chooser);}

  /**
   * See CATPolyInterfClashContactOper.
   */
  virtual AccuracyChooser * GetContactAccuracyChooser()
    {return CATPolyVisuSimpleClashOper::GetContactAccuracyChooser();}

  /** Debug */
  virtual CATPolyInterfClashOper *                 CastToClashOper()                 {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactOper *          CastToClashContactOper()          {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactClearanceOper * CastToClashContactClearanceOper() {return 0;}

  virtual CATPolyVisuClashContactOper * Clone() const;

protected:

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT GuessBestMemoryConsumptionHint(MemoryConsumption & oMemoryHint) const
    {return CATPolyInterfClashContactOper::GuessBestMemoryConsumptionHint(oMemoryHint);}

  /**
   * @nodoc
   */
  const char * GetOperatorName() const;

};

#endif /* CATPolyVisuClashContactOper_h */
