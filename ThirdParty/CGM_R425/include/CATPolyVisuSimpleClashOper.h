// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuSimpleClashOper.h
//
//===================================================================
//
// Usage notes:
// Operator detecting clashes between visu rep.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyVisuSimpleClashOper_h
#define CATPolyVisuSimpleClashOper_h

#include "PolyVisuClash.h"

// Interference
#include "CATPolyInterfClashOper.h"
#include "CATPolyVisuInterferenceOper.h"

// Math
#include "CATTolerance.h"

/**
 * Interface describing the clash operator.
 */
class ExportedByPolyVisuClash CATPolyVisuSimpleClashOper : public CATPolyVisuInterferenceOper
{
public:


  /**
   * Constructor and destructor.
   */
  CATPolyVisuSimpleClashOper(const CATTolerance & iTol = CATGetDefaultTolerance());
  CATPolyVisuSimpleClashOper(const CATPolyVisuSimpleClashOper & iCopy);
  virtual ~CATPolyVisuSimpleClashOper();


  /**
   * Launch the computation of inteferences between the two trees.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetResult function.
   */
  virtual HRESULT Run();

  // Readd clash functions
  /**
   * See CATPolyInterfClashOper.
   */
  virtual CATPolyClashInterfList * GetClashes()
    {return CATPolyInterfClashContactClearanceOper::GetClashes();}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual HRESULT ComputeIntersectionCurves(CATBoolean curvesMode)
    {return CATPolyInterfClashContactClearanceOper::ComputeIntersectionCurves(curvesMode);}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual CATBoolean IsComputingIntersectionCurves() const
    {return CATPolyInterfClashContactClearanceOper::IsComputingIntersectionCurves();}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual HRESULT ComputeIntersectionVolumes(CATBoolean volumesMode)
    {return CATPolyInterfClashContactClearanceOper::ComputeIntersectionVolumes(volumesMode);}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual CATBoolean IsComputingIntersectionVolumes() const
    {return CATPolyInterfClashContactClearanceOper::IsComputingIntersectionVolumes();}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual HRESULT ComputePenetrationVectors(CATBoolean penetrationVectorMode)
    {return CATPolyInterfClashContactClearanceOper::ComputePenetrationVectors(penetrationVectorMode);}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual CATBoolean IsComputingPenetrationVectors() const
    {return CATPolyInterfClashContactClearanceOper::IsComputingPenetrationVectors();}

  virtual HRESULT SetPenetrationVectorDirection(PenetrationVectorDirection dir)
    {return CATPolyInterfClashContactClearanceOper::SetPenetrationVectorDirection(dir);}

  /**
   * @return Method used to choose the penetration vector direction.
   */
  virtual PenetrationVectorDirection GetPenetrationVectorDirection() const
  {return CATPolyInterfClashContactClearanceOper::GetPenetrationVectorDirection();}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual HRESULT StopAtFirstClash(CATBoolean stopMode)
    {return CATPolyInterfClashContactClearanceOper::StopAtFirstClash(stopMode);}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual CATBoolean IsStoppingAtFirstClash() const
    {return CATPolyInterfClashContactClearanceOper::IsStoppingAtFirstClash();}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual HRESULT CheckWaterTightness(CATBoolean checkMode)
    {return CATPolyInterfClashContactClearanceOper::CheckWaterTightness(checkMode);}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual CATBoolean IsCheckingWaterTightness() const
    {return CATPolyInterfClashContactClearanceOper::IsCheckingWaterTightness();}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual HRESULT CheckInclusionInsideOpenObjects(CATBoolean treatMode)
    {return CATPolyInterfClashContactClearanceOper::CheckInclusionInsideOpenObjects(treatMode);}

  /**
   * See CATPolyInterfClashOper.
   */
  virtual CATBoolean IsCheckingInclusionInsideOpenObjects() const
    {return CATPolyInterfClashContactClearanceOper::IsCheckingInclusionInsideOpenObjects();}

  /** Debug */
  virtual CATPolyInterfClashOper *                 CastToClashOper()                 {return this;}
  /** Debug */
  virtual CATPolyInterfClashContactOper *          CastToClashContactOper()          {return 0;}
  /** Debug */
  virtual CATPolyInterfClashContactClearanceOper * CastToClashContactClearanceOper() {return 0;}

  virtual CATPolyVisuSimpleClashOper * Clone() const;

protected:
  const char * GetOperatorName() const;

};

#endif /* CATPolyVisuSimpleClashOper_h */
