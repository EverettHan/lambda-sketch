// COPYRIGHT Dassault Systemes 2013
//===================================================================

// CATCDSMonoparCurvatureInverseEvaluator.h

//===================================================================

// Usage notes: Operator dedicated to find all parameters or intervals where a given a monoparametric displays a given curvature
//              and optionally determines whether the curvature is increasing, decreasing, or level in the neighborhood 
//              Newton algorithm is processed on a curvature evaluator

//===================================================================

//  Feb 2013  Creation:             BF8 CHU
//===================================================================
#ifndef CATCDSMonoparCurvatureInverseEvaluator_H
#define CATCDSMonoparCurvatureInverseEvaluator_H

#include "CDSProfile.h"
#include "CATCDSBoolean.h"

#include "CATICDSMonoparCurvatureInverseEvaluator.h"      // derived

class CATICDSMonoParametric2D;

class ExportedByCDSProfile CATCDSMonoparCurvatureInverseEvaluator : public CATICDSMonoparCurvatureInverseEvaluator
{

public:
  
  // Life Cycle 
  virtual ~CATCDSMonoparCurvatureInverseEvaluator();
  CATCDSMonoparCurvatureInverseEvaluator();

  // Initialize all input data. The operator will search all points or intervals where the curvature radius has a given value on a given parametric interval
  // The monoparametric is assumed to be C2 continuous in the interior of the domain
  // iDomain is the parametric interval associated with iOperand where curvature will be investigated
  // iTargetCurvatureRadius is the signed curvature radius value (positive toward the left of the tangent when seen from above normal to sketch)
  // iLinearTolerance = minimum distance between solutions, minimum shift between target curvature and real curvature at a solution point
  // iComputeCurvatureVariation must be set to 1 if the curvature variation should be investigated in the neighborhood of each solution point, thus enabling the
  // determination of intervals where curvature radius is above, equal, or below the target value. 0 if these intervals are not needed
  // returns TRUE if initialisation completed successfully, otherwise FALSE
  virtual CATCDSBoolean SetInput(CATICDSMonoParametric2D & iMonoParametric, double iDomain[2],  double iTargetCurvatureRadius, double iLinearTolerance,
    int iComputeCurvatureVariation = 0);

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
  // Same as above woith protected interface CATCSMonoParametric instead of CATICDSMonoParametric2D
  virtual CATCDSBoolean SetInputBypassPublicInterfaces(CATCSMonoParametric & iMonoParametric, double iDomain[2],  double iTargetCurvatureRadius, double iLinearTolerance,
    int iComputeCurvatureVariation = 0);
#endif

  // Set computation mode for the sense of variation of the curvature (default = 1 = yes)
  inline void ComputeCurvatureVariation(int iCompute=1);
   
  // Compute points and intervals where the curvature radius has the target value
  // returns TRUE if the computation succeeded, FALSE otherwise
  virtual CATCDSBoolean Run();
     
  // Give the number of solution points
  virtual int GetNumberOfPoints();

  // Get the iIdx-th solution point where the curvature radius has the target value
  // If the curvature is constant on an interval (circular arc), the two end points of this interval must be returned as consecutive solution points
  // iIdx is the range of the point: 1 <= iIdx <= Number of points
  // oParam is the parameter value 
  // oSenseOfVariationBeforePoint :
  //   if not null in input, *oSenseOfVariationBeforePoint gives the sense of variation of the curvature radius at the left of oParam, which
  //   is the sign the derivative of the curvature radius (in fact the sign of the first non-null derivative if any), hence can take 3 values
  //   -1 if the curvature radius is decreasing when w<oParam, 0 if the curvature is contant on an interval whose upper bound is oParam,
  //   +1 if the curvature radius is increasing when w>oParam
  // oSenseOfVariationAfterPoint :
  //   if not null in input, *oSenseOfVariationAfterPoint gives the sense of variation of the curvature radius at the right of oParam, which
  //   is the sign the derivative of the curvature radius (in fact the sign of the first non-null derivative if any), hence can take 3 values
  //   -1 if the curvature radius is decreasing when oParam<w, 0 if the curvature is contant on an interval whose lower bound is oParam,
  //   +1 if the curvature radius is increasing when oParam<w
  // Returns TRUE if the results could be retrieved, FALSE otherwise
  virtual CATCDSBoolean GetSolutionPoint(int iIdx, double & oParam, int * oSenseOfVariationBeforePoint = 0, int * oSenseOfVariationAfterPoint = 0);

  // Single solution structure 
  struct Pt {
    double _Param; // parameter
    int    _SenseOfVariationBeforePoint; // -1 if curv. radius is decreasing before _Param, 0 if level, +1 if increasing
    int    _SenseOfVariationAfterPoint;  // -1 if curv. radius is decreasing after _Param, 0 if level, +1 if increasing
  };

private:

  // Reset all result data
  void ResetResultData();

  // Add a solution to the list
  CATCDSBoolean AddSolution(double iLocalParam, int iSenseOfVariationBeforePoint, int iSenseOfVariationAfterPoint);

  // Input data
  CATICDSMonoParametric2D * _IMnp;                      // not owned
  double                    _Domain[2];
  double                    _TargetCurvatureRadius;
  int                       _ComputeCurvatureSenseOfVariation; // 0 if not required, 1 if required
  double                    _LinearTolerance;
  int                       _ComputeCurvatureVariation;

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
  CATCSMonoParametric     * _MnpBypassPublicInterfaces;  // not owned
#endif

  // Result Data
  int                       _NumberOfSolutions;
  int                       _MaxNumberOfSolutions; // allocated size
  Pt *                      _Solutions;            // owned

};

inline void CATCDSMonoparCurvatureInverseEvaluator::ComputeCurvatureVariation(int iCompute) {
  _ComputeCurvatureVariation = iCompute; }

#endif
