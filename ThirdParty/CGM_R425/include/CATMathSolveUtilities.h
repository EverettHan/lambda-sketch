// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2016
//

#ifndef _CATMathSolveUtilities_HeaderFile
#define _CATMathSolveUtilities_HeaderFile

#include "CATFMMMathExport.h"

#include "CATBoolean.h"
#include "CATMathInterval.h"
#include "CATMathDiagnostic.h"
class CATTolerance;
class CATMathFunctionX;

class ExportedByFMMMath CATMathSolveUtilities  {

public:

	// Methods PUBLIC
	// 


  static CATMathDiagnostic SolveNewton(
                  const CATMathFunctionX        * iF,
                  const CATMathInterval & iD       ,
                  const double            iFmin    ,
                  const double            iFmax    ,
                  const CATLONG32       & iDerivate,
                  double          & ioResult,
                  const double iEpsRoot);

private :
	

   static CATMathDiagnostic SolveDichotomy(     
     const CATMathFunctionX        * iF,
     double    & ioMin,
     double    & ioMax,
     double    & ioFmin,
     double    & ioFmax,
     const CATLONG32 & iDerivate,
     double    & oResult,
     const int iNbMaxIteration);
};
#endif
