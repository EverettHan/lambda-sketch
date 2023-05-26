/// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMathCuttingByWeightDistribution :
//
//=============================================================================
//
//
//=============================================================================
// Mar. 2000    Creation                         A. Lieutier
//=============================================================================
#ifndef _CATMathApproxCuttingByWeightDistribution_HeaderFile
#define _CATMathApproxCuttingByWeightDistribution_HeaderFile

#include "CATMathApproxCutting.h"

class CATMathApproxCuttingByWeightDistribution : public CATMathApproxCutting
{

 public:

 // Methods PUBLIC
 //  
	 // Reset les Tables
	 virtual void Reset()=0;
	 // Add a error a localized weight
	 virtual void Add(double iU, double imoduleCoef) = 0; 
	 // Add a Global weight
	 virtual void Add(double imoduleCoef) = 0;
	 // Somme des erreurs;
	 virtual double Sum() const = 0; 
	 // Donne des decoupes preferentiels
	 virtual void SetPrefCutting(CATMathApproxCutting * iPrefCut) = 0;
};

#endif
