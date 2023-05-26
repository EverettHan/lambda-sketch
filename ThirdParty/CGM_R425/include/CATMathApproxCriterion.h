#ifndef _CATMathApproxCriterion_HeaderFile
#define _CATMathApproxCriterion_HeaderFile

#include "CATMathApproxCritDef.h"
#include "CATMathInterval.h"

#include "MathApprox.h"

class CATMathFunctionXY;

class ExportedByMathApprox CATMathApproxCriterion  {

public:

 // Methods PUBLIC
 // 
	 virtual ~CATMathApproxCriterion();
//
// Set the parameters of the criterion
//
   virtual  int SetType(const CATMathApproxCriterionType iType) =0;
   virtual  int SetRepartition(const CATMathApproxCriterionRepartition iRepar) =0;
//   virtual  int SetMaxValue(const double iMax) =0;

//
// gives the value of the criterion on the domain iDomainU x iDomainV relativly 
// to the proposed function iF on this domain
//
/*   virtual  double Value(const int iTotalDim,
                         const CATMathInterval& iDomainU,
                         const CATMathInterval& iDomainV,
	                       const CATMathFunctionXY ** iF) const = 0;
*/
// 
// tells if the the proposed function F on the domain iDomainU x iDomainV satisfies 
// the criterion
//
   virtual  CATBoolean IsSatisfied(const int iTotalDim,
                                   const CATMathInterval& iDomainU,
                                   const CATMathInterval& iDomainV,
	                                 const CATMathFunctionXY ** iF,
                                   const double iRelativeEpsilon = 0.0,
                                   double *  oUWorsParameter = 0, 
                                   double *  oVWorsParameter = 0) const = 0;
//
// Max value for the criterion
//
   virtual  double GetMaxValue() const = 0;
   virtual  double GetMaxRatioValue() const = 0;

   // gives the localization of the worst point, it can be usefull for cutting strategy.
   virtual int GetUVMaxRatioValue(double & oUParameter, double & oVParameter) const {return 33;}

// Get the type of the criterion
//
   virtual  CATMathApproxCriterionType GetType() const = 0;
// 
// Get the repartition 
//
   virtual  CATMathApproxCriterionRepartition GetRepartition() const = 0;
};
#endif
