// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// Author  : Andre LIEUTIER, Thu Oct 19 1995
// Modified: Patrick BOSINCO, Tue May 18 1999
//           CATIA version


#ifndef CATMathPlateSolver_h
#define CATMathPlateSolver_h

#define SolveAgain

#include "MathPlate.h"
#include "CATMathDef.h" // include necessaire

class CATIMathPlatePPCArray;
class CATIMathPlateLXYZCArray;
class CATIMathPlateLScalarCArray;

class CATMathPlateFunction;

class CATMathPlateSolver  {

public:

 // Methods PUBLIC
 // 

	 virtual void Load(CATIMathPlatePPCArray* IPPC)=0;
	 virtual void Load(CATIMathPlateLXYZCArray* ILXYZC)=0;
	 virtual void Load(CATIMathPlateLScalarCArray* ILSC)=0;


   virtual void SolveTI(const int ord = 4,const double anisotropie = 1.0) =0;


#ifdef SolveAgain
   virtual void SolveTIAgain() =0;
#endif

   virtual CATBoolean IsDone() const =0;


   virtual void Init() = 0 ;
   virtual const CATMathPlateFunction * GetFunction() const =0;
   virtual void UVBox(double& UMin,double& UMax,
											double& VMin,double& VMax) const =0;

	 virtual int NumberOfPunctualLoad() const =0;
//   virtual void UVConstraints(TColgp_SequenceOfXY& Seq) const =0;
};

ExportedByMathPlate CATMathPlateSolver * CreateCATMathPlateSolver();

//ExportedByMathPlate CATMathPlateSolver * CreateCATMathPlateSolver(const CATMathPlateSolver * iSolve );

ExportedByMathPlate void RemoveCATMathPlateSolver(const CATMathPlateSolver * iSolve);
#endif
