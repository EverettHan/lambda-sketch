//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATApproxSurface:
// Abstract class for approximation of a Surface into a BSpline Surface
//
//==========================================================================
// Usage Notes: 
// The surface to approximate has to be C2 continuous.
// Some methods are provided to manage:
// - the order of constraints to respect on the bounds of the function
// - the maximum degree in U and V
// - the maximum number of segments for the resulting NUBS
// - the precision of error computation
//
//==========================================================================
// Avr. 99     Creation                       J. PANCIATICI
//========================================================================== 

#ifndef _CATApproxSurface_HeaderFile
#define _CATApproxSurface_HeaderFile
    
    
#include "CATMathDef.h"
#include "CATCGMOperator.h"
#include "CATSkillValue.h"
#include "CATGeoApproxSurface.h"
#include "GeoApprox.h" 

class CATNurbsSurface;
class CATSurface;
class CATGeoFactory;
class CATSurLimits;
class CATMathApproxCutting;
class CATMathApproxCriterion;
    
class ExportedByGeoApprox CATApproxSurface : public CATGeoApproxSurface
{

  public:
    //-------------
    // Constructor
    //-------------

    CATApproxSurface(CATGeoFactory *iFactory);

    //-------------
    // Destructor
    //-------------
    ~CATApproxSurface();

    //---------------------------------------
    // Set some parameters for approximation
    //---------------------------------------

    // Set Limits : the approximation will be done in this limits
	//              (by default the approximation is done in the 
    //               limits of the surface)
    virtual int SetLimits(const CATSurLimits * iLimits) = 0;

    // Set the tolerance for approximation
	// default value = factory resolution.
    virtual int SetTolerance(const double iTol) = 0;

 	// SetContinuitiesOrder : the order of the constraints requiered
	// for internal continuities of the resulting surface.
	//           - minimum value = 0
	//           - maximum value = 2
	//           - default value = 2
	// return a positive int if the value is out the possible values
 	virtual int SetOrder(const int iUOrder,         
  	                     const int iVOrder) = 0;    

    // Set some parameters for approximation
	// MaxDegU : maximum U-degree for the resulting BSpline 
	//           - minimum value = 2*iUOrder+1
	//           - maximum value = 11
	//           - default value = 8
	// MaxDegV : maximum V-Degree for the resulting BSpline 
	//           - minimum value = 2*iUOrder+1
	//           - maximum value = 14
	//           - default value = 8
	// MaxSegments : maximum number of segments for the resulting BSpline
	//           - minimum value = 1
	//           - maximum value = no 
	//           - default value = 64
	// Preciscode : precision code for error computation (default value = 1)
	//           - minimum value = 0
	//           - maximum value = 3
	//           - default value = 1        
	// return a positive int if the value is out the possible values
	// MinSegments : minimum number of segments for the resulting BSpline
	//           - minimum value = 1
	//           - maximum value = MaxSegments
	//           - default value = 1
    virtual int SetParams(const int iMaxDegU=8,      
    					  const int iMaxDegV=8,       
    					  const int iMaxSegments=64,    
    					  const int iPrecisCode=1, 
						  const int iMinSegments=1) = 0;

    // Set the Criterion to satisfy : special use
    virtual void SetCriterion(CATMathApproxCriterion * iCriterion) = 0;

			// Set the Cutting Tools to use
		virtual void SetCuttingTools(CATMathApproxCutting * iUCut, 
																 CATMathApproxCutting * iVCut) = 0;


    //---------------------
    // Get the results
    //---------------------

    // Even if Run() is false, a result can exists without satisfying the requiered
    // tolerance 
    virtual CATBoolean GetHasResult() const = 0;

    // Get the resulting NURBS surface
    virtual CATNurbsSurface * GetSurface() const = 0;

    // Get the maximum error 
    virtual double GetMaxError() const =0;
	/**
	 * Returns the maximum distance between the original surface and its approximation.
	 */
    virtual double GetMaxDeviation() const =0;

    // Get the criterium error : in the case of SetCriterion is used.
    virtual double GetCritError() const =0;
 

};


/**
 * Do a new a CATApproxSurface operator from memory.
 */	
ExportedByGeoApprox CATApproxSurface * CreateApproxSurface ( CATGeoFactory *iWhere,
                                                          CATSurface *iSurface1,
                                                          CATSkillValue iMode=BASIC );


/**
 * Removes a CATApproxSurface operator from memory.
 */	
ExportedByGeoApprox void Remove( CATApproxSurface * iOperatorToRemove);


#endif
