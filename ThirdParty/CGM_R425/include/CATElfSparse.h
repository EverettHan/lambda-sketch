#ifndef CATElfSparse_H
#define CATElfSparse_H

#include "CATELFSparseSolver.h"

class ExportedByCATELFSparseSolver CATElfSparse
{
  
  public :

    CATElfSparse();     
   ~CATElfSparse();     
  
  /**************************************************************************
   *
   *  Input:
   *
   *  int     iNumberOfLine
   *
   *  int     iNumberOfCoefficient
   *
   *  int*    iEndOflinePointer[iNumberOfLine+1]
   *          Pointer in iColumnNumber and iValues
   *
   *  int*    iColumn[iNumberOfCoefficient]
   *                            
   *  double* iValues[iNumberOfCoefficient]
   *                             
   *
   *  Return Code = -1 Internal Error
   *  Return Code =  0 Computation successfully performed
   *  Return Code =  1 Negative or Null EigenValue
   *  Return Code =  2 Not enough Memory
   *  Return Code =  3 Invalid Input
   *    
   * ***********************************************************************
   */  
  
  int Factorize(int     iNumberOfLine,
		int     iNumberOfCoefficient,  
		int*    iEndOfLinePointer,  
		int*    iColumn,  
		double* iValues);
  

  /** ***********************************************************************
   * Solve:  Ax = b
   **************************************************************************
   *
   *
   *    First: use Factorize 
   *    Then : use Solve 
   *
   *
   *  Input:
   *
   *
   *  int      iSizeOfVector : iNumberOfLine
   *  double*& ioVector      : b 
   *
   *  Output:
   *                             
   *  double*& ioVector      : x
   *
   *  Return Code = -1 Internal Error
   *  Return Code =  0 Computation successfully performed
   *  Return Code =  1 Use Factorize before Solve 
   *  Return Code =  2 Not enough Memory
   *  Return Code =  3 Invalid Input
   *    
   * ***********************************************************************
   */   

  int Solve(int      iSizeOfvector,
	    double*& ioVector);
  

  int MultiSolve(int       iSizeOfVector,
                 int       iNumberOfVector,
                 char**&   ioPointerOfVector);

  private :
      
  void Clean ();

  int     _FactoComputed;
 
  int     _NtDeg, _Maxlnz, _Maxsub;
  int*    _PERM;
  int*    _INVP;
  int*    _XNZSUB;
  int*    _NZSUB;
  int*    _XLNZ;
  double* _LNZ;
  double* _DIAG;
  
};

#endif

