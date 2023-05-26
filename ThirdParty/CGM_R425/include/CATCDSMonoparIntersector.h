// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATCDSMonoparIntersector.h

//===================================================================

// Usage notes: Implementation of operator dedicated to find all intersections / coincidence intervals between monoparametrics

//===================================================================

//  Dec 2012  Creation:             BF8 CHU
//===================================================================
#ifndef CATCDSMonoparIntersector_H
#define CATCDSMonoparIntersector_H

#include "CATICDSMonoparIntersector.h"
#include "CDSProfile.h"

class CATCSMonoParametric;

class ExportedByCDSProfile CATCDSMonoparIntersector : public CATICDSMonoparIntersector
{

public:
  
  // Life Cycle
  CATCDSMonoparIntersector();
  virtual ~CATCDSMonoparIntersector();

  // Initialize operands. The operator will search all intersections and coincidence intervals between the two parametric intervals
  // given in input. Both monoparametrics are assumed to be C1 continuous in the interior of the intervals
  CATCDSBoolean SetOperands(CATICDSMonoParametric2D & iOperand1, double iDomain1[2], CATICDSMonoParametric2D & iOperand2, double iDomain2[2],
    double iLinearTolerance);

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
  // Initialize operands (same as above), this method is temporary and should not be callled when public interfaces are integrated to all applications
  // Temporarily, work wirth protected interface CATCSMonoParametric, to enable trimming profiles created by the player, while the player does not yet handle public interfaces (waiting for bf8)
  CATCDSBoolean SetOperandsBypassPublicInterfaces(CATCSMonoParametric * iOperand1, double iDomain1[2], CATCSMonoParametric * iOperand2, double iDomain2[2], double iLinearTolerance);
#endif

  // Compute all intersections
  CATCDSBoolean Run();
 
  // Retrieve the number of solutions, a solution is either an intersection or the start or end point of an interval where both 
  int GetNumberOfSolutions ();
   
  // Read a solution, defined by its range (1-based)
  // All solutions are parameter-wise sorted on the 1st operand
  // ioDeterminantOf1stDerivatives is ignored if null in input, otherwise *ioDeterminantOf1stDerivatives is the determinant of the 1st derivative vectors of 
  // operand 1 and 2 with repect to the parameter, at the solution point. Zero means the solution is bounding an interval where
  // both monoparametrics are coincident, the 1st occurence of zero is the starting point of this interval (within the domain given in input)
  // and the next occurence is its end point
  CATCDSBoolean GetSolution (int iIdx, double & oParam1, double & oParam2, double * ioDeterminantOf1stDerivatives);

  // Single solution structure 
  struct Pt {
    double _Param[2]; // parameters on both operands
    double _DetFirstDeriv;
  };

private:

  // Utility for IntersectMonoparametrics: handle the case of one self-intersected operand (by dichotomy)
  CATCDSBoolean FindSelfIntersectionOnMonoParametric(CATCSMonoParametric & iMonop, double iStartDomain, double iEndDomain, int & ioDepth);

  // Utility for IntersectMonoparametrics: handle the case of two operands (or two disjoint intervals on the same curve)
  // If iSolutionToSkip is not null, *iSolutionToSkip will not be regarded as a valid solution (point shared by adjacent intervals)
  CATCDSBoolean FindIntersectionsBetweenTwoMonoParametric(CATCSMonoParametric & iMonop1, double iStartDomain1, double iEndDomain1, 
    CATCSMonoParametric & iMonop2, double iStartDomain2, double iEndDomain2, int iSkipCheckingBoxes, double * iSolutionToSkip);
    
  // Add a solution to the list
  CATCDSBoolean AddSolution(double iLocalParams[2], double iDetFirstDeriv);

  // Reset all result data
  void ResetResultData();

  // Sort utility
  static int ComparePt(const void * iPt1, const void * iPt2);

  // Input Data
  CATICDSMonoParametric2D * _Operand1; 
  CATICDSMonoParametric2D * _Operand2; 
  double                    _Domain1[2];
  double                    _Domain2[2];
  double                    _LinearTolerance;

  // Result Data
  int                       _NumberOfSolutions;
  int                       _MaxNumberOfSolutions; // allocated size
  Pt *                      _Solutions;

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
  CATCSMonoParametric     * _Operand1BypassPublicInterfaces; 
  CATCSMonoParametric     * _Operand2BypassPublicInterfaces; 
#endif

};

#endif
