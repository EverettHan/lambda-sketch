// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATCDSMonoparIntersector.h

//===================================================================

// Usage notes: Interface of bundle gathering all mathematical operators optionally required by the CDS solver

//===================================================================

//  Dec 2012  Creation:             BF8 CHU
//===================================================================
#ifndef CATICDSMathBundle_H
#define CATICDSMathBundle_H

#include "CATCDS.h"
#include "CATCDSBoolean.h"

class CATICDSMonoparIntersector;
class CATICDSMonoparCurvatureInverseEvaluator;
class CATICDSMonopar2DFunctionRetriever;
class CATICDSNurbsApproxOperator;
class CATICDSInverseMatrixCalculator;
class CATSoftwareConfiguration;

/**
 * @SKIP
 */
class ExportedBySolverInterface CATICDSMathBundle
{

public:
  
  /**
   * Destructor
   */
  virtual ~CATICDSMathBundle();

  /**
   * Retrieves an operator dedicated to compute all intersections between two monoparametric elements
   * @param oOperator
   *   Intersection computation operator
   * @return
   *   TRUE if the required operator has been found, otherwise FALSE
   */
  virtual CATCDSBoolean GetMonoparIntersector(CATICDSMonoparIntersector *& oOperator) = 0;
  
  /**
   * Retrieves an operator dedicated to compute all parameters or parametric intervals where a taget curvature is reached
   * @param oOperator
   *   Curvature inverse evaluator
   * @return
   *   TRUE if the required operator has been found, otherwise FALSE
   */
  virtual CATCDSBoolean GetMonoparCurvatureInverseEvaluator(CATICDSMonoparCurvatureInverseEvaluator *& oOperator) = 0;

  /**
   * Retrieves an operator dedicated to approximate a Monoparametric in a NURBS Curve. 
   * @param oOperator
   *   NURBS approx operator
   * @return
   *   TRUE if the required operator has been found, otherwise FALSE
   */
  virtual CATCDSBoolean GetNurbsApproxOperator(CATICDSNurbsApproxOperator *& oOperator) = 0;

  /**
   * Retrieves an operator dedicated to invert a matrix. 
   * @param oOperator
   *   inverse matrix calculator
   * @return
   *   TRUE if the required operator has been found, otherwise FALSE
   */
  //virtual CATCDSBoolean GetInverseMatrixCalculator(CATICDSInverseMatrixCalculator *& oOperator) = 0;

  /**
   * Feed the math bundle with all existing operators. This can be called after construction.
   * A configuration must be created for operators that support CGM versioning (e.g. approximation into nurbs)
   * @return
   *   TRUE if initialization is complete, otherwise FALSE
   */
  virtual CATCDSBoolean InitializeAllOperators(CATSoftwareConfiguration* ipConfig) = 0;

protected:

  /**
   * Protected Constructor (the class must be derived)
   */
  CATICDSMathBundle();

};

#endif
