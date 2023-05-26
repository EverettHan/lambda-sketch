// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATICDSMonoparCurvatureInverseEvaluator.h

//===================================================================

// Usage notes: Interface of operator dedicated to find all parameters or intervals where a given a monoparametric displays a given curvature
//              and optionally determines whether the curvature is increasing, decreasing, or level in the neighborhood 

//===================================================================

//  Dec 2012  Creation:             BF8 CHU
//===================================================================
#ifndef CATICDSMonoparCurvatureInverseEvaluator_H
#define CATICDSMonoparCurvatureInverseEvaluator_H

#include "CATCDS.h"
#include "CATCDSBoolean.h"
#define CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces

class CATICDSMonoParametric2D;
#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
class CATCSMonoParametric;
#endif

/**
 * @SKIP
 *
 */
class ExportedBySolverInterface CATICDSMonoparCurvatureInverseEvaluator
{

public:

  /**
   * Life Cycle (this class must be derived)
   */
  virtual ~CATICDSMonoparCurvatureInverseEvaluator();

  /**
   * Initialize all input data. The operator will search all points or intervals where the curvature radius has a given value on a given parametric interval
   * The monoparametric is assumed to be C2 continuous in the interior of the domain
   * @param iMonoParametric
   *   Monoparametric object being investigated
   * @param iDomain
   *   Parametric interval associated with iOperand where curvature will be investigated
   * @param iTargetCurvatureRadius
   *   Signed curvature radius value (positive toward the left of the tangent when seen from above normal to sketch)
   * @param iLinearTolerance
   *   Minimum distance between solutions, minimum shift between target curvature and real curvature at a solution point
   * @param iComputeCurvatureVariation
   *   Must be set to 1 if the curvature variation should be investigated in the neighborhood of each solution point, thus enabling the
   *   determination of intervals where curvature radius is above, equal, or below the target value. 0 if these intervals are not needed
   * @return
   *   TRUE if initialisation completed successfully, otherwise FALSE
   */
  virtual CATCDSBoolean SetInput(CATICDSMonoParametric2D & iMonoParametric, double iDomain[2],  double iTargetCurvatureRadius, double iLinearTolerance,
    int iComputeCurvatureVariation = 0) = 0;
   
#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
  // Same as above woith protected interface CATCSMonoParametric instead of CATICDSMonoParametric2D
  virtual CATCDSBoolean SetInputBypassPublicInterfaces(CATCSMonoParametric & iMonoParametric, double iDomain[2],  double iTargetCurvatureRadius, double iLinearTolerance,
    int iComputeCurvatureVariation = 0) = 0;
#endif

  /**
   * Compute points and intervals where the curvature radius has the target value
   * @return
   *   TRUE if the computation succeeded, FALSE otherwise
   */
  virtual CATCDSBoolean Run() = 0;

     
  /**
   * Give the number of solution points
   * @return
   *   Number of isolated points or interval limit points where the curvature radius has the target value
   */
  virtual int GetNumberOfPoints() = 0;

  /**
   * Get the iIdx-th solution point where the curvature radius has the target value
   * If the curvature is constant on an interval (circular arc), the two end points of this interval must be returned as consecutive solution points
   * @param iIdx 
   *   Range of the point: 1 <= iIdx <= Number of points
   * @param oParam
   *   Parameter value 
   * @param oSenseOfVariationBeforePoint
   *   if not null in input, *oSenseOfVariationBeforePoint gives the sense of variation of the curvature radius at the left of oParam, which
   *   is the sign the derivative of the curvature radius (in fact the sign of the first non-null derivative if any), hence can take 3 values
   *   -1 if the curvature radius is decreasing when w<oParam, 0 if the curvature is contant on an interval whose upper bound is oParam,
   *   +1 if the curvature radius is increasing when w>oParam
   * @param oSenseOfVariationAfterPoint
   *   if not null in input, *oSenseOfVariationAfterPoint gives the sense of variation of the curvature radius at the right of oParam, which
   *   is the sign the derivative of the curvature radius (in fact the sign of the first non-null derivative if any), hence can take 3 values
   *   -1 if the curvature radius is decreasing when oParam<w, 0 if the curvature is contant on an interval whose lower bound is oParam,
   *   +1 if the curvature radius is increasing when oParam<w
   * @return
   *   TRUE if the results could be retrieved, FALSE otherwise
   */
  virtual CATCDSBoolean GetSolutionPoint(int iIdx, double & oParam, int * oSenseOfVariationBeforePoint = 0, int * oSenseOfVariationAfterPoint = 0) = 0;

protected:

  /**
   * Life Cycle (this class must be derived)
   */
  CATICDSMonoparCurvatureInverseEvaluator();

};

#endif
