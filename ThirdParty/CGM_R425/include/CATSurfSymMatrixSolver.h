// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//=================================================================== 
//
// CATSurfSymMatrixSolver :
// Solver for  Symetric square matrix of dimension N  
//
//===================================================================


//===================================================================
// Usage notes:
//   It is one class, than solve syteme like Ax=b by Full or sparse (generally faster) methodes
//   
//
//   WARNING : this class manipulate one refernece of one CATMathNxNFullSymMatrix  object
//   be carfull than this object is not deleted when we use our solver'sobject 
//  -----------------------------------------
//
//===================================================================



#ifndef  CATSurfSymMatrixSolver_h
#define  CATSurfSymMatrixSolver_h

#include "MathAdvMarsh.h"
class CATMathNxNFullSymMatrix;


class  ExportedByMathAdvMarsh CATSurfSymMatrixSolver 
{
	public:	
	  virtual ~CATSurfSymMatrixSolver();

    virtual int SetMatrix(const CATMathNxNFullSymMatrix* iFullSyM)=0;
    virtual int Factorize()=0;
    virtual int Solve (double *iob) const=0;
#ifdef CATSurf_MultiSolve
		virtual int Solve (const double *ib, double *ox, const int iNbCol) const=0;
#endif
    

	protected:
		CATSurfSymMatrixSolver();
};

 
/**
*  
* <br><b>Role</b>: Create one instance of CATSurfSymMatrixSolver
* @param iFullSyM
*  One FullSymetric Matrix A in order to solve Ax=b
* @param iRatioMax
*   The maximum ration of no-null coefficients for the use of sparse solver.
* 
*/
 ExportedByMathAdvMarsh CATSurfSymMatrixSolver* CATCreateSurfSymMatrixSolver(const CATMathNxNFullSymMatrix * iFullSyM,
                               const double iRatioMax = 0.3);


#endif
