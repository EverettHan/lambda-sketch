/// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMathApproxXY :
// Abstract class for approximation algorithm of a CATMathApproxFunctionXY 
// The function is defined from R*2 --> R*N.
// N is the total dimension of the function.
// The function is composed of several function whose dimension can be 1,2 or 3
// Each function is called a sub-space which is characterized by its dimension 
// and its range (iDim,iNumSS)
// For each sub-space, there are methods to set:
// - the tolerance to respect by the approximation 
// - the tolerance to respect on the bounds of the function
// There are general methods to set:
// - the order of constraints to respect on the bounds of the function
// - the maximum degree in U and V
// - the maximum number of segments for the resulting NUBS
// - the precision of approximation
// - the favorite iso direction (U or V) 
//=============================================================================
//
//
//=============================================================================
// Avr. 99    Creation                         J. Panciatici
//=============================================================================

#ifndef _CATMathApproxXY_HeaderFile
#define _CATMathApproxXY_HeaderFile

#include "CATMathInterval.h"
#include "CATMathDef.h"
#include <MathApprox.h>
#include "CATBoolean.h"


//#define APPROX

class CATMathApproxFunctionXY;
class CATMathApproxCriterion;
class CATMathApproxCutting;
class CATSoftwareConfiguration;


class CATMathApproxXY  

{

  public:

		virtual ~CATMathApproxXY() {};
	//------------------------------------------
	//Methods to modify the default parameters
	//------------------------------------------

	// Set the tolerance for approximation of the part of the function 
	// represented by the sub-space iNumSS of dimension iDim
	// 
	virtual int SetTolerances(const int iDim,
	                          const int iNumSS,
					          const double iTolValue) =0 ;


// methode non utilisee : sous #define pour coverage
#ifdef APPROX
	// Set the tolerance for approximation of bounds of the part of the function
	// represented by the sub-space iNumSS of dimension iDim
	// iTolValue is an Array of 4 values , one for each isoparametric of the bound
	// of the function.
	virtual int SetTolBounds(const int iDim,
	                         const int iNumSS,
					         const double * iTolValue) =0 ;
#endif

    // Set Continuities
	// Warning : must be used before SetParams()
    virtual int SetOrder(const int iUOrder,
  	                     const int iVOrder) = 0;

    // Set some parameters for approximation
    virtual int SetParams(const int iMaxDegU,    
	  	                  const int iMaxDegV,    
				          const int MaxSegments, 
				          const int PrecisCode,  
				          const int iFavorIso,
						  const int MinSegments=1) = 0;  

    //Set Cutting management
    virtual void SetCutting(CATMathApproxCutting * iUChoice, 
	  			   CATMathApproxCutting * iVChoice) = 0;

    // Set the Criterion to satisfy
    virtual void SetCriterion(CATMathApproxCriterion * iCriterion) = 0;


    // Set the C2 conversion to be done
    virtual void SetConvertC2() = 0;

    //optional & advanced (default is 2.1)
    virtual int SetRatioTolForIso(const double iRatioTolForIso) = 0;

				 
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
	                      int &oUDegree, int &oVDegree,
	 			          int &oNbUKnots, int &oNbVKnots,
						  int &oNbUPoles, int &oNbVPoles,
						  double * oUknots, double * oVknots,
						  int * oUMult, int * oVMult,
						  double * oPoles) const = 0;

    // Get the maximum error for a given sub-space
    virtual double GetMaxError(const int iDim,
	                           const int iNumSS) const = 0;

// methodes non utilisees : sous #define pour coverage
#ifdef APPROX
	// Get the averrage error for a given sub-space
    virtual double GetAverageError(const int iDim,
	                               const int iNumSS) const = 0;
	// Get the maximum error on the U bounds for a given sub-space 
    virtual  double GetUFrontError(const int iDim,
	                               const int iNumSS) const = 0;

	// Get the maximum error on the V bounds for a given sub-space 
    virtual double GetVFrontError(const int iDim,
	                              const int iNumSS) const = 0;
#endif

	// Get the criterion error for a given sub-space
    virtual double GetCritError(const int iDim,
	                            const int iNumSS) const = 0;

		// Get the criterion ratio (error/tol) for a given sub-space
		virtual   double GetCritRatio(const int iDim,
	                   const int iNumSS) const = 0;

 
};


  ExportedByMathApprox CATMathApproxXY * CreateCATMathApproxXY(
																						CATSoftwareConfiguration* iConfig,
																						const CATMathInterval& iDomainU,
		                                        const CATMathInterval& iDomainV,
   	                                            CATMathApproxFunctionXY * iFunc);


  ExportedByMathApprox void RemoveCATMathApproxXY(CATMathApproxXY * iApprox);


#endif
