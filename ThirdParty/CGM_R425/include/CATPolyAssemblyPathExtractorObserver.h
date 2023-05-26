// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathExtractorObserver.h
// Header definition of CATPolyAssemblyPathExtractorObserver
//
//===================================================================
//
// Usage notes: Observer for Extractor
//
//===================================================================
//
// January 2017 Creation: JXO
//===================================================================
#ifndef CATPolyAssemblyPathExtractorObserver_H
#define CATPolyAssemblyPathExtractorObserver_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
#include "CATPolyObserver.h"
#include "CATPolyPPConfigurationChecker.h"
#include "CATPolyAssemblyPathExtractor.h"
#include "CATUnicodeString.h"

// Math
class CATMathTransformation;

/**
 * Observer of the clash extractor
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathExtractorObserver : public CATPolyObserver<CATPolyAssemblyPathExtractorObserver>
{
public:
  /** Constructor */
  CATPolyAssemblyPathExtractorObserver();
  /** Destructor */
  ~CATPolyAssemblyPathExtractorObserver();

  /** Called before ExtractFromPosition */
  virtual void BeginExtractFromPosition(CATPolyAssemblyPathExtractor::Method iMethod,
                                        int iMaxIterations,
                                        double iSmallStep,
                                        double iMinimumRadius,
                                        double iMaximumRadius,
                                        CATPolyAssemblyPathExtractor::RandomMode iRandomMode,
                                        double iRotationMode,
                                        const CATMathTransformation & iPos,
                                        const CATMathPoint & iCenterOfMovingObject) = 0;

  /** Called after ExtractFromPosition */
  virtual void EndExtractFromPosition(const HRESULT oReturnCode, const CATMathTransformation & oFoundPos, double oFoundDist, int oNbTotalClashes) = 0;

  /** Called after each clash test */
  virtual void ClashTest(int clashid, double R1, double R2, double dist, const CATMathTransformation & iPos, CATPolyPPConfigurationChecker::Collision & iColStatus) = 0;

  /** Called before each sphere crust */
  virtual void BeginSphere(int sphereid, double R1, double R2, int NbToTestPositions) = 0;
  /** Called after each sphere crust */
  virtual void EndSphere(int sphereid, double Rotation [4], double R2, double anglemax, int Ntested_tcouche, int NbTestedPositions, int NbFreePositionsFound, CATUnicodeString str) = 0;
  /** Called after finding a first solution in 'back and forth' mode sphere crust */
  virtual void InitialSolution(const CATMathTransformation & oFoundPos, double oFoundDist) = 0;
};

#endif

