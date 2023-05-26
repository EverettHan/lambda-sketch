// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// Author  : Andre LIEUTIER, Thu Oct 19 1995
// Modified: Patrick BOSINCO, Tue May 18 1999
//           CATIA version


#ifndef _CATMathPlateFunction_HeaderFile
#define _CATMathPlateFunction_HeaderFile

#include "MathPlate.h"
#include "CATMathDef.h"
//#include "CATBaseUnknown.h"

class CATMathPlateSolver;
class CATMathVector;
class CATMathPoint2D;
class CATMathTransformation;
class CATMathApproxCuttingByWeightDistribution;

class CATMathPlateFunction //: public CATBaseUnknown 
{

public:

   virtual void AddRef() = 0;
   virtual void Release() = 0;
   virtual void Init() = 0;
   virtual void Clone(CATMathPlateFunction*& copy) const =0;
   virtual  CATMathVector Evaluate(const CATMathPoint2D& point2d) const = 0;
   virtual CATMathVector EvaluateDerivative(const CATMathPoint2D& point2d,
	                                 const int iu,const int iv) const = 0;
 
   virtual void SetPolynomialPartOnly(const CATBoolean PPOnly = 0) = 0;
   virtual int Continuity() const = 0;
   virtual CATBoolean UnStream(const int sizeLong,
                               const int sizeDouble,
                               const CATLONG32 *tabLong,
                               const double *tabDouble)= 0;
   virtual CATBoolean Stream( int &sizeLong,
                              int &sizeDouble,
                              CATLONG32 *&tabLong,
                              double *&tabDouble)const = 0;
   virtual void Transform(const CATMathTransformation* aMathTransfo) = 0;

   virtual CATMathPlateFunction *QueryQuickFunction(const double accuracy) const = 0;
/*	 virtual void GetLagrangeCoef(CATMathApproxCuttingByWeightDistribution *iCutU, 
																CATMathApproxCuttingByWeightDistribution *iCutV) const = 0;*/

};


// Empty Builder
ExportedByMathPlate CATMathPlateFunction * CreateCATMathPlateFunction();
#endif
