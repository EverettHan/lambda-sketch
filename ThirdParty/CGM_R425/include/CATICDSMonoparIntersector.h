// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATCDSMonoparIntersector.h

//===================================================================

// Usage notes: Interface of operator dedicated to find all intersections / coincidence intervals between monoparametrics

//===================================================================

//  Dec 2012  Creation:             BF8 CHU
//===================================================================
#ifndef CATICDSMonoparIntersector_H
#define CATICDSMonoparIntersector_H

#include "CATCDS.h"
#include "CATCDSBoolean.h"

#define CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces

class CATICDSMonoParametric2D;
class CATICDSMonopar2DFunctionRetriever;
#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
class CATCSMonoParametric;
#endif
/**
 * @SKIP
 *
 */
class ExportedBySolverInterface CATICDSMonoparIntersector
{

public:

  /**
   * Life Cycle (this class must be derived)
   */
  virtual ~CATICDSMonoparIntersector();

  /**
   * Initialize operands. The operator will search all intersections and coincidence intervals between the two parametric intervals
   * given in input. Both monoparametrics are assumed to be C1 continuous in the interior of the intervals
   * @param iOperand1
   *   First operand
   * @param iDomain1
   *   Parametric interval associated with iOperand1 where intersections will be investigated
   * @param iOperand2
   *   Second operand
   * @param iDomain2
   *   Parametric interval associated with iOperand2 where intersections will be investigated
   * @param iLinearTolerance
   *   Minimum distance between solutions
   * @return
   *   TRUE if initialisation completed successfully, otherwise FALSE
   */
  virtual CATCDSBoolean SetOperands(CATICDSMonoParametric2D & iOperand1, double iDomain1[2], CATICDSMonoParametric2D & iOperand2, double iDomain2[2],
    double iLinearTolerance) = 0;

  /**
   * Compute all intersections
   * @return
   *   TRUE if computaion completed successfully, otherwise FALSE
   */
  virtual CATCDSBoolean Run() = 0;
 
  /**
   * Retrieve the number of solutions, a solution is either an intersection or the start or end point of an interval where both 
   * mono-parametrics are coincident
   * @return
   *   Number of solutions
   */
  virtual int GetNumberOfSolutions () = 0;
   
  /**
   * Read a solution, defined by its range (1-based)
   * All solutions are parameter-wise sorted
   * @param iIdx
   *   Range of the requested solution (1 <= iIdx <= Number of solutions)
   * @param oParam1
   *   Parameter on operand 1, must be in the domain assigned to operand 1 upon initialization (iDomain1)
   * @param oParam2
   *   Parameter on operand 2, must be in the domain assigned to operand 2 upon initialization (iDomain2)
   * @param ioDeterminantOf1stDerivatives
   *   ignored if null in input, otherwise *ioDeterminantOf1stDerivatives is the determinant of the 1st derivative vectors of 
   *   operand 1 and 2 with repect to the parameter, at the solution point. Zero means the solution is bounding an interval where
   *   both monoparametrics are coincident, the 1st occurence of zero is the starting point of this interval (within the domain given in input)
   *   and the next occurence is its end point
   * @return
   *   TRUE if the requested solution exists
   */
  virtual CATCDSBoolean GetSolution (int iIdx, double & oParam1, double & oParam2, double * ioDeterminantOf1stDerivatives) = 0;

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
   /**
    * @nodoc
    * Do not use. For compatibility only.
    * Initialize operands (same as above), this method is temporary and should not be called when public interfaces are integrated to all applications
    * Temporarily, work wirth protected interface CATCSMonoParametric, to enable trimming profiles created by the player, while the player does not yet handle public interfaces (waiting for bf8)
    */
  virtual CATCDSBoolean SetOperandsBypassPublicInterfaces(CATCSMonoParametric * iOperand1, double iDomain1[2], CATCSMonoParametric * iOperand2, double iDomain2[2], double iLinearTolerance) = 0;
#endif

protected:

  /**
   * Life Cycle (this class must be derived)
   */
  CATICDSMonoparIntersector();

};

#endif
