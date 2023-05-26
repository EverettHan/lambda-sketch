#ifndef CATElfSkyLine_H
#define CATElfSkyLine_H

#include "CATELFOptimization.h"

class CATElfMemoryManager;
class CATElfSparse;

class ExportedByCATELFOptimization CATElfSkyLine
{
  
  public :

    CATElfSkyLine();     
   ~CATElfSkyLine();     
  
  /** ***********************************************************************
   * Factorize: calculate the sky-line factorization of A
   *           
   *    where:
   *
   *    A is a sparse square symetric definite positive matrix
   *    Only the lower part of the matrix and the non zero values are stocked
   *
   ***************************************************************************
   *
   *
   *    Example:  a01 to a12 are the non-zero values of the matrix
   *   
   *         1   2   3   4   5   6
   *    1   a01 0.0 0.0 0.0 0.0 0.0
   *    2   0.0 a02 a03 a05 0.0 0.0
   *    3   0.0 a03 a04 0.0 a07 a10 
   *    4   0.0 a05 0.0 a06 a08 0.0 
   *    5   0.0 0.0 a07 a08 a09 a11
   *    6   0.0 0.0 a10 0.0 a11 a12 
   *      
   *
   *  iNumberOfLine = 6
   *  iNumberOfCoefficient = 12
   *  iEndOflinePointer[13] = 0, 1, 2, 4, 6, 9, 12 
   *  iColumn =  1 ,  2 ,  2 ,  3 ,  2 ,  4 ,  3 ,  4 ,  5 ,  3 ,  5 ,  6 
   *  iValues = a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, a11, a12
   *
   *
   **************************************************************************
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
  

  /** ***********************************************************************
   * MultiSolve: 
   *
   *        Ax = b 
   *          1   1
   *        ........
   *
   *        Ax = b  
   *          N   N
   *           
   **************************************************************************
   *
   *    First: use Factorize 
   *    Then : use Solve 
   *
   *
   *  Input:
   *
   *  int      iSizeOfVector   : iNumberOfLine
   *  int      iNumberOfVector : N 
   *
   *  char**&  ioPointerOfVector[iNumberOfVector]  : b  to b  
   *                                                  1     N 
   *           The size of the iNumberOfVector pointed vectors is iNumberOfLine
   *           Vectors must be allocate in double
   *
   *  Output:
   *                             
   *  char**&  ioPointerOfVector[iNumberOfVector]  : x  to x
   *                                                   1     N 
   *           The size of the iNumberOfVector pointed vectors is iNumberOfLine
   *
   *  Return Code = -1 Internal Error
   *  Return Code =  0 Computation successfully performed
   *  Return Code =  1 Use Factorize before Solve 
   *  Return Code =  2 Not enough Memory
   *  Return Code =  3 Invalid Input
   *    
   * ***********************************************************************
   */   
  

  int MultiSolve(int       iSizeOfVector,
		 int       iNumberOfVector,
		 char**&   ioPointerOfVector);  
    
  private :
      
  CATElfMemoryManager* _MemorySkyLine;

  int     _FactoComputed;
 
  int     _NtDeg;
  int     _NtCKF;
  int*    _MPKF;
  double* _AKF;  
  double* _DKF;  

  int     _IPARM[25];
  double  _DPARM[25];
  
  int     _nChar;
  double* _DEPL;
  int     _Full;
  CATElfSparse *_Sparse;
};

#endif

