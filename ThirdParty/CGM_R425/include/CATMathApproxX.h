/// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMathApproxX :
// Abstract class for approximation algorithm of a CATMathApproxFunctionX 
// The function is defined from R --> R*N.
// N is the total dimension of the function.
// The function is composed of several function whose dimension can be 1,2 or 3
// Each function is called a sub-space which is characterized by its dimension 
// and its range (iDim,iNumSS)
// For each sub-space, there are methods to set:
// - the tolerance to respect by the approximation 
// - the tolerance to respect on the bounds of the function
// There are general methods to set:
// - the order of constraints to respect on the bounds of the function
// - the maximum degree 
// - the maximum number of segments for the resulting NUBS
// - the precision of approximation 
//=============================================================================
//
//
//=============================================================================
// Aout. 99    Creation                         J. Panciatici
//=============================================================================

#ifndef _CATMathApproxX_HeaderFile
#define _CATMathApproxX_HeaderFile

#include "CATMathInterval.h"
#include "CATMathDef.h"
#include <MathApprox.h>

//#define APPROX

class CATMathApproxFunctionX;
class CATMathApproxCutting;


class CATMathApproxX  

{

  public:

   virtual ~CATMathApproxX();

	//------------------------------------------
	//Methods to modify the default parameters
	//------------------------------------------

	// Set the tolerance for approximation of the part of the function 
	// represented by the sub-space iNumSS of dimension iDim
	// 
	virtual int SetTolerances(const int iDim,
	                          const int iNumSS,
					          const double iTolValue) =0 ;

    // SetContinuities 
    virtual int SetOrder(const int iOrder) = 0;

    // Set some parameters for approximation
    virtual int SetParams(const int iMaxDeg,        
				          const int MaxSegments, 
				          const int PrecisCode) = 0;  

    //Set Cutting management
    virtual void SetCutting(CATMathApproxCutting * iChoice) = 0;

				 
    //--------
	// Run() 
    //--------
	virtual int Run() = 0;

	//---------
	//Result
	//---------

    // There can be a result even if Run return a value different from 0
    virtual inline   CATBoolean GetHasResult() const = 0;

	// For each sub-space, get all the parameters needed to build the result 
	// as a NUBS 
    virtual int GetResult(const int iDim,const int iNumSS,
	                      int &oDegree, int &oNbKnots, int &oNbPoles, 
						  double * oknots, int * oMult, double * oPoles) const = 0;

    // Get the maximum error for a given sub-space
    virtual double GetMaxError(const int iDim,
	                           const int iNumSS) const = 0;

// methode non utilisee : sous #define pour coverage
#ifdef APPROX
	// Get the averrage error for a given sub-space
    virtual double GetAverageError(const int iDim,
	                               const int iNumSS) const = 0;
#endif
 
};


  ExportedByMathApprox CATMathApproxX * CreateCATMathApproxX(const CATMathInterval& iDomainU,
   	                                                         CATMathApproxFunctionX * iFunc);


  ExportedByMathApprox void RemoveCATMathApproxX(CATMathApproxX * iApprox);


#endif
