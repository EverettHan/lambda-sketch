#ifndef CATElfOptimize_H
#define CATElfOptimize_H

#include "CATELFOptimization.h"
#include "CATError.h"

class CATElfMemoryManager;

/** ***********************************************************************
  *                           OPTIMIZATION
  *
  *
  *
  *  Minimize the Objective Function:
  *
  *     F(X) = F(x ,x , ...... ,x )   
  *               1  2           N
  *
  *
  *  With:
  *
  *
  *     -->  G (X) = G (x ,x , ...... ,x )     j = 1,M
  *           j       j  1  2           N
  *
  *                       min
  *              G (X) > G               if ConstraintType = 1 
  *               j       j
  *
  *          Or:
  *                       max
  *              G (X) < G               if ConstraintType = 2 
  *               j       j
  *
  *          Or:
  *               min            max
  *              G    < G (X) < G        if ConstraintType = 3 
  *               j      j       j
  *
  *
  *
  *           min          max 
  *     -->  x    <  x  < x        i = 1,N     
  *           i       i    i
  *
  *
  *************************************************************************
  */
class ExportedByCATELFOptimization CATElfOptimize
{
  
  public :

    CATElfOptimize();     
   ~CATElfOptimize();     
  

/** ***********************************************************************
  * SetParameters
  *
  * Input:
  *
  *  int     N    : Number of Parameters 
  *
  *  double* Xo   : [N] (Must be allocated and desallocated by user)
  *                 Initial Values of Parameters 
  *                          o  
  *                 Xo[i] = x        i = 0,N-1
  *                          i+1 
  *
  *  double* Xmin : [N] (Must be allocated and desallocated by user)
  *                 Minimum Values of Parameters
  *                            min  
  *                 Xmin[i] = x      i = 0,N-1
  *                            i+1 
  *
  *  double* Xmax : [N] (Must be allocated and desallocated by user)
  *                 Maximum Values of Parameters
  *                            max  
  *                 Xmax[i] = x      i = 0,N-1
  *                            i+1 
  *
  * ***********************************************************************
  */  

   void SetParameters(int     iN,  
                      double* iXo,
                      double* iXmin,
                      double* iXmax);


  /** ***********************************************************************
   * SetObjectiveFunction
   *
   * Input:
   *
   *  double  Fo   : Initial value of the Objective Function 
   *                                 o  o           o
   *                 Fo = F(Xo) = F(x ,x , ...... ,x )
   *                                 1  2           N
   *
   *  double* dFo  : [N] (Must be allocated and desallocated by user)
   *                 Sensitivities of the Objective Function
   *                                   
   *                          dF
   *                 dFo(i) = -- (Xo)  i = 0,N-1
   *                          dx
   *                            i+1
   *
   * ***********************************************************************
   */  
  
  void SetObjectiveFunction(double  iFo,  
			    double* idFo);

  
  /** ***********************************************************************
   * SetConstraints
   *
   * Input:
   *
   *  int     M    : Number of Constraints
   *
   *  double* Go   : [M] (Must be allocated and desallocated by user)
   *                 Initial Values of Constraints
   *                            
   *                 Go[i] = G (Xo)   j = 0,M-1
   *                          j+1 
   *
   *  double* dGo  : [N,M] (Must be allocated and desallocated by user) 
   *
   *                 We expected:                  
   *
   *
   *                            M times
   *                 <---------------------------->
   *                 (1 to N, 1 to N, ...., 1 to N) 
   *
   *
   *                 Sensitivity of the Constraints
   *                                   
   *                            dG
   *                              j+1
   *                 dGo[i,j] = -----  (Xo)  i = 0,N-1   j = 0,M-1
   *                            dx
   *                              i+1
   *
   *  double* Gmin : [M] (Must be allocated and desallocated by user)
   *                 Minimum Values of Constraints
   *                            min  
   *                 Gmin[j] = G      j = 0,M-1
   *                            j+1 
   *
   *  double* Gmax : [M] (Must be allocated and desallocated by user)
   *                 Maximum Values of Constraints
   *                            max  
   *                 Gmax[j] = G      j = 0,M-1
   *                            j+1 
   *
   *  int*   Gtype : [M] (Must be allocated and desallocated by user)
   *                 Type of Constraint
   *
   *                 if Gtype[j] = 1      G (X) > Gmin[j]
   *                                       j
   *
   *                 if Gtype[j] = 2      G (X) < Gmax[j]
   *                                       j
   *
   *                 if Gtype[j] = 3      Gmin[j] < G (X) < Gmax[j]
   *                                                 j
   *
   * ***********************************************************************
   */  

  void SetConstraints(int     iM,
		      double* iGo,  
		      double* idGo,
		      double* iGmin,
		      double* iGmax,
		      int*    iGtype);
  

  /** ***********************************************************************
   * ComputeOptimization
   *
   * Input:
   *
   *  double ExpectedAccuracy: 
   *
   * ***********************************************************************
   */  

  HRESULT ComputeOptimization(double ExpectedAccuracy);


  /** ***********************************************************************
   * GetResults
   *
   * Output:
   *
   *  double&  Fminimum: Minimum Values of the Objective Function
   *
   *  double*& Xoptimum: [N] (Must be allocated and desallocated by user)
   *                     Optimums Parameters 
   *
   *
   * ***********************************************************************
   */  

  void GetResults(double&  oFminimum,
                  double*& ioXoptimum);


  /** ***********************************************************************
   * GetAccuracy
   *
   * Output:
   *
   *  int&    NbIter
   *
   *  double& ReachedAccuracy
   *
   *
   * ***********************************************************************
   */  

  void GetAccuracy(int&    oNbIter,
                   double& oReachedAccuracy);
  
  /** ***********************************************************************
   * OptimizationReport
   * ***********************************************************************
   */  

  void OptimizationReport();
  
  void OptimizationSmooth();

  private :

  CATElfMemoryManager* GetMemory();

  int     _N;
  double* _Xo;
  double* _Xmin;
  double* _Xmax;

  double  _Fo;  
  double* _dFo;

  int     _M;
  double* _Go;  
  double* _dGo;
  double* _Gmin;
  double* _Gmax;
  int*    _Gtype;
  
  double  _Fminimum;
  char*   _Xoptimum;

  int     _NbIter;
  double  _ExpectedAccuracy;
  
  int     _IterG;
  double  _ReachedAccuracy;

  int     _Parameters_OK;
  int     _Constraints_OK;
  int     _ObjectiveFunction_OK;

  double*  _Previous_Parameters ;
  int      _Nb_Previous_Parameters ;

  int _Smooth ;

  CATElfMemoryManager* _MemoryOptim;

  void PrintOptimization(int iNumber, double iXo, double iXf, double iXmin, double iXmax);

  
};

#endif

