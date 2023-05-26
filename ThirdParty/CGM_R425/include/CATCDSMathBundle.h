// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATCDSMonoparIntersector.h

//===================================================================

// Usage notes: Implementation of the bundle that gathers all mathematical operators optionally required by the CDS solver

//===================================================================

//  Dec 2012  Creation:             BF8 CHU
//===================================================================
#ifndef CATCDSMathBundle_H
#define CATCDSMathBundle_H

#include "CATICDSMathBundle.h"
#include "CDSProfile.h"

class ExportedByCDSProfile CATCDSMathBundle : public CATICDSMathBundle
{

public:
  
  // Life Cycle
  CATCDSMathBundle();
  virtual ~CATCDSMathBundle();

  // Set operators (the bundle becomes the owner of these operators)
  void SetMonoparIntersector(CATICDSMonoparIntersector * iOperator);
  void SetMonoparCurvatureInverseEvaluator(CATICDSMonoparCurvatureInverseEvaluator * iOperator);
  //If the new operator doesn't have a configuration or a factory we keep the old ones.
  void SetNurbsApproxOperator(CATICDSNurbsApproxOperator* iOperator);

  // Set all existing operators (this can be called after construction, does all the previous settings in one call)
  CATCDSBoolean InitializeAllOperators(CATSoftwareConfiguration* ipConfig);

  // Methods declared in the interface
  CATCDSBoolean GetMonoparIntersector(CATICDSMonoparIntersector *& oOperator);
  CATCDSBoolean GetMonoparCurvatureInverseEvaluator(CATICDSMonoparCurvatureInverseEvaluator *& oOperator);
  CATCDSBoolean GetNurbsApproxOperator(CATICDSNurbsApproxOperator *& oOperator);

private:

  CATICDSMonoparIntersector               * _Intersector;              // owned
  CATICDSMonoparCurvatureInverseEvaluator * _CrvInverseEvaluator;      // owned
  CATICDSNurbsApproxOperator              * _NurbsApproxOperator;      // owned
};

#endif
