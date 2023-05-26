/*
 * @quickreview JS9 10:01:10 Remove the class and relocate its methods in CATPolyVisuInterferenceOper.
 */

// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuInterferenceOper.h
//
//===================================================================
//
// Usage notes:
// Parent class for operators detecting interferences between visu reps.
//
//===================================================================
//
// Aug 2009 Creation: JS9
// Nov 2012 Modification JXO: Added GetGuessedMemoryConsumptionHint and removed unnecessary observer calls (already called in base class)
//===================================================================

#ifndef CATPolyVisuInterferenceOper_h
#define CATPolyVisuInterferenceOper_h

#include "PolyVisuClash.h"

// Interference
#include "CATPolyInterfClashContactClearanceOper.h"

// Math
#include "CATMathInline.h"
class CATechExt;


// CATPolyVisuInterferenceOper should be removed.
class ExportedByPolyVisuClash CATPolyVisuInterferenceOper : protected CATPolyInterfClashContactClearanceOper
{
public:
  CATPolyVisuInterferenceOper(const CATTolerance & iTol);
  CATPolyVisuInterferenceOper(const CATPolyVisuInterferenceOper & iCOpy);
  virtual ~CATPolyVisuInterferenceOper();

  // Readd interference functions
  // Restore the hidden functions
  /**
   * See CATPolyInterferenceOper.
   */
  INLINE void SetFirstOperand(CATBVHTreeSet * data1) {CATPolyInterfClashContactClearanceOper::SetFirstOperand(data1);}

  /**
   * See CATPolyInterferenceOper.
   */
  INLINE void SetSecondOperand(CATBVHTreeSet * data2) {CATPolyInterfClashContactClearanceOper::SetSecondOperand(data2);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual CATPolyInterferenceList * GetResult() {return CATPolyInterfClashContactClearanceOper::GetResult();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual CATPolyInterfWarningList * GetWarnings() {return CATPolyInterfClashContactClearanceOper::GetWarnings();}

  /**
   * See CATPolyInterferenceOper.
   */
  void AddInputCoupleFilter(CATIPolyInterfInputCoupleFilter * filter)
    {CATPolyInterfClashContactClearanceOper::AddInputCoupleFilter(filter);}

  /**
   * See CATPolyInterferenceOper.
   */
  void RemoveInputCoupleFilter(CATIPolyInterfInputCoupleFilter * filter)
    {CATPolyInterfClashContactClearanceOper::RemoveInputCoupleFilter(filter);}

  /**
   * See CATPolyInterferenceOper.
   */
  void AddRepCoupleFilter(CATIPolyInterfInputCoupleFilter * filter)
    {CATPolyInterfClashContactClearanceOper::AddRepCoupleFilter(filter);}

  /**
   * See CATPolyInterferenceOper.
   */
  void RemoveRepCoupleFilter(CATIPolyInterfInputCoupleFilter * filter)
    {CATPolyInterfClashContactClearanceOper::RemoveRepCoupleFilter(filter);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT StopAtFirstInterference(CATBoolean stopMode)
    {return CATPolyInterfClashContactClearanceOper::StopAtFirstInterference(stopMode);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual CATBoolean IsStoppingAtFirstInterference() const
    {return CATPolyInterfClashContactClearanceOper::IsStoppingAtFirstInterference();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT SetGranularityLevel(GranularityLevel granularity)
    {return CATPolyInterfClashContactClearanceOper::SetGranularityLevel(granularity);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual GranularityLevel GetGranularityLevel() const
    {return CATPolyInterfClashContactClearanceOper::GetGranularityLevel();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT DetectInclusion(CATBoolean inclusionMode)
    {return CATPolyInterfClashContactClearanceOper::DetectInclusion(inclusionMode);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual CATBoolean IsDetectingInclusion() const
    {return CATPolyInterfClashContactClearanceOper::IsDetectingInclusion();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT EnablePartialGeometricResults(CATBoolean partialMode)
    {return CATPolyInterfClashContactClearanceOper::EnablePartialGeometricResults(partialMode);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual CATBoolean IsPartialGeometricResultsEnabled() const
    {return CATPolyInterfClashContactClearanceOper::IsPartialGeometricResultsEnabled();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT SetMemoryConsumptionHint(MemoryConsumption memoryHint)
    {return CATPolyInterfClashContactClearanceOper::SetMemoryConsumptionHint(memoryHint);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual MemoryConsumption GetMemoryConsumptionHint() const
    {return CATPolyInterfClashContactClearanceOper::GetMemoryConsumptionHint();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual MemoryConsumption GetGuessedMemoryConsumptionHint() const
    {return CATPolyInterfClashContactClearanceOper::GetGuessedMemoryConsumptionHint();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT SetMaximalNumberOfThreads(int nbThreads)
    {return CATPolyInterfClashContactClearanceOper::SetMaximalNumberOfThreads(nbThreads);}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual int GetMaximalNumberOfThreads() const
    {return CATPolyInterfClashContactClearanceOper::GetMaximalNumberOfThreads();}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual int GetNbInputBVIntersections()
    {return CATPolyInterfClashContactClearanceOper::GetNbInputBVIntersections();}

  // Internal only!!!!!
  virtual void SetCacheVisitor(CATPolyInterfDecoratedObjectsVisitor * backDoor)
  {CATPolyInterfClashContactClearanceOper::SetCacheVisitor(backDoor);}

  virtual void SetObserver(CATPolyInterferenceOperObserver * o)
  {CATPolyInterfClashContactClearanceOper::SetObserver(o);}

protected:

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT GuessBestMemoryConsumptionHint(MemoryConsumption & oMemoryHint) const
    {return CATPolyInterferenceOper::GuessBestMemoryConsumptionHint(oMemoryHint);}

  /**
   * See CATPolyInterferenceOper.
   */
  const char * GetOperatorName() const;
};

#endif /* CATPolyVisuInterferenceOper_h */
