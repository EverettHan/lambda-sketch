/// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMathApproxFunctionXY :
// Abstract class of functions of two variables for approximation algorithm 
// The values of the function are in RN.
//=============================================================================
//
//
//=============================================================================
// Avr. 99    Creation                         J. Panciatici
//=============================================================================

#ifndef CATMathApproxFunctionXY_H
#define CATMathApproxFunctionXY_H

#include "CATMathInterval.h"


class  CATMathApproxFunctionXY
{
// public methods
 public:


   //------------------------------------------------------------
   // Evaluator
   //------------------------------------------------------------
	 virtual int  Eval( const CATMathInterval & iDomainU, const CATMathInterval & iDomainV,
	                    const CATLONG32 & iTypeIso, const double & iConstPara,
	                    const CATLONG32 & iNbPoints, const double * iTabParam,
	                    const CATLONG32 & iOrderU , const CATLONG32 & iOrderV,
	                    double * oValue)  = 0;
   
	//------------------------------------------------------------
   // Evaluator
   //------------------------------------------------------------
	 virtual int  Eval( const CATMathInterval & iDomainU, const CATMathInterval & iDomainV,
	                    const CATLONG32 & iNbPoints, const double * iTabParam,
	                    const CATLONG32 & iOrderU , const CATLONG32 & iOrderV,
						double * oValue) { return 1;}

  // //------------------------------------------------------------
  // // Evaluator ThreadSafe
  // //------------------------------------------------------------
	 virtual int  EvalMT( int iThreadId,
	                      const CATMathInterval & iDomainU, const CATMathInterval & iDomainV,
	                      const CATLONG32 & iTypeIso, const double & iConstPara,
	                      const CATLONG32 & iNbPoints, const double * iTabParam,
	                      const CATLONG32 & iOrderU , const CATLONG32 & iOrderV,
	                      double * oValue) { return 33; }

   //------------------------------------------------------------
   // For giving the total dimension of the space
   //------------------------------------------------------------
   virtual int GetDimension() const = 0;

   //------------------------------------------------------------
   // For giving the Number Of sub-spaces for a given dimension
   //------------------------------------------------------------
   virtual int GetNbSubSpaces(const int iDim) const = 0;


   //------------------------------------------------------------
   // Pour savoir si la fonction est ThreadSafe
   //------------------------------------------------------------
	 virtual CATBoolean IsThreadSafe() const { return FALSE; }

  // //------------------------------------------------------------
  // // Pour dubliquer les Surf et initialiser le Nombre de Threads
  // //------------------------------------------------------------
	 //virtual int InitMultiThread(int NbThreads) { return 0; }

   //------------------------------------------------------------
   // Pour savoir si la fonction est MultiThreade
   //------------------------------------------------------------
	 virtual int HowManyThread() { return 1; }

   
};

#endif
