/// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMathApproxFunctionX :
// Abstract class of functions of two variables for approximation algorithm 
// The values of the function are in RN.
//=============================================================================
//
//
//=============================================================================
// Avr. 99    Creation                         J. Panciatici
//=============================================================================

#ifndef CATMathApproxFunctionX_H
#define CATMathApproxFunctionX_H

#include "CATMathInterval.h"



class  CATMathApproxFunctionX
{
// public methods
 public:


   //-----------------------------------------------------------------
   // Evaluator
   //-----------------------------------------------------------------   
   virtual int  Eval(const CATMathInterval & iDomain,
	                 const CATLONG32 & iNbPoints, const double * iTabParam,
					 const CATLONG32 & iOrder , double * oValue)  = 0;


   //---------------------------------------
   // For giving the total dimension of the space
   //---------------------------------------
   virtual int GetDimension() const = 0;

   //-----------------------------------------------------------
   // For giving the Number Of sub-spaces for a given dimension
   //-----------------------------------------------------------
   virtual int GetNbSubSpaces(const int iDim) const = 0;
   
};

#endif
