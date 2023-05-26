// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuClashContactClearanceOper.h
//
//===================================================================
//
// Usage notes:
// Operator detecting clash, contact and clearance between visu rep.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyVisuClashContactClearanceOper_h
#define CATPolyVisuClashContactClearanceOper_h

#include "PolyVisuClash.h"

#include "CATPolyVisuClashContactOper.h"

// Math
#include "CATTolerance.h"


class CATPolyClearanceInterfList;

/**
 * Operator detecting clash, contact and clearance between visu rep.
 * Normally CATPolyVisuClashContactClearanceOper should derive from
 * CATPolyInterfClashContactClearanceOper. Unfortunately, since
 * some old code assume that CATPolyVisuClashContactClearanceOper
 * derives from CATPolyVisuClashContactOper, I have to keep the hierarchy.
 * And then a lot of code is duplicated. It could be avoided by templates
 * and if you have an other idea, feel free to do the right thing.
 */
class ExportedByPolyVisuClash CATPolyVisuClashContactClearanceOper : public CATPolyVisuClashContactOper
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyVisuClashContactClearanceOper(const CATTolerance & iTol = CATGetDefaultTolerance());
  CATPolyVisuClashContactClearanceOper(const CATPolyVisuClashContactClearanceOper & iCopy);
  virtual ~CATPolyVisuClashContactClearanceOper();


  /**
   * Launch the computation of inteferences between the two trees.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetResult function.
   */
  virtual HRESULT Run();

  // Readd clearance functions
  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual CATPolyClearanceInterfList * GetClearanceInterferences()
    {return CATPolyVisuClashContactOper::GetClearanceInterferences();}

  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual HRESULT SetClearanceTolerance(double clearance)
    {return CATPolyVisuClashContactOper::SetClearanceTolerance(clearance);}

  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual double GetClearanceTolerance() const
    {return CATPolyVisuClashContactOper::GetClearanceTolerance();}

  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual HRESULT ComputeClearanceMeshes(CATBoolean meshMode)
    {return CATPolyVisuClashContactOper::ComputeClearanceMeshes(meshMode);}

  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual CATBoolean IsComputingClearanceMeshes() const
    {return CATPolyVisuClashContactOper::IsComputingClearanceMeshes();}

  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual HRESULT ComputeRefinedClearanceAreas(CATBoolean refinedMode)
    {return CATPolyVisuClashContactOper::ComputeRefinedClearanceAreas(refinedMode);}

  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual CATBoolean IsComputingRefinedContactAreas() const
    {return CATPolyVisuClashContactOper::IsComputingRefinedContactAreas();}

  /**
   * See CATPolyInterfClashContactClearanceOper.
   */
  virtual HRESULT ComputeMinDistance(CATBoolean distMode)
    {return CATPolyVisuClashContactOper::ComputeMinDistance(distMode);}

  /**
   * @return Whether the operator computes the minimum distance between each clearance areas.
   */
  virtual CATBoolean IsComputingMinDistance() const
    {return CATPolyVisuClashContactOper::IsComputingMinDistance();}

  /** Debug */
  virtual CATPolyInterfClashOper *                 CastToClashOper()                 {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactOper *          CastToClashContactOper()          {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactClearanceOper * CastToClashContactClearanceOper() {return this;}

  virtual CATPolyVisuClashContactClearanceOper * Clone() const;

protected:

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT GuessBestMemoryConsumptionHint(MemoryConsumption & oMemoryHint) const
    {return CATPolyInterfClashContactClearanceOper::GuessBestMemoryConsumptionHint(oMemoryHint);}

  /**
   * @nodoc
   */
  const char * GetOperatorName() const;

};

#endif /* CATPolyVisuClashContactClearanceOper_h */
