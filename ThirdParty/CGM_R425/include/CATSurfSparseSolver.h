#ifndef CATSurfSparseSolver_H
#define CATSurfSparseSolver_H


#include "MathAdvMarsh.h"
#include "CATBoolean.h"
#include "CATMathSparseSymMatrix.h" //directive de compil 

#ifdef DefineCATSurfSparseMxNMatrix
#define SurfSparseSolver_Implement
#endif

#ifdef SurfSparseSolver_Implement
class ExportedByMathAdvMarsh  CATSurfSparseSolver
{
public:
	virtual ~CATSurfSparseSolver();

  virtual int Solve(const double *iSecondMembers, double *oSolution) =0;

  virtual int MultiSolve(const double *iSecondMembers, double *oSolutions, const int iNbSolves)=0;
};


ExportedByMathAdvMarsh CATSurfSparseSolver * CATCreateSurfSparseSolver(CATMathSparseSymMatrix * iFirstMember, const CATBoolean iSparseMode = TRUE);
#endif
#endif
