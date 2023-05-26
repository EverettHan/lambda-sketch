//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATApproxCurve:
// Abstract class for approximation of a Curve
//
//==========================================================================
// Usage Notes:
//
//==========================================================================
// Aout. 99     Creation                       J. PANCIATICI
//========================================================================== 
    
#ifndef _CATApproxCurve_HeaderFile
#define _CATApproxCurve_HeaderFile
    
    
#include "CATCrvLimits.h"

#include "CATMathDef.h"
#include "CATCGMOperator.h"
#include "CATSkillValue.h"

#include "GeoApprox.h" 

class CATNurbsCurve;
class CATCurve;
class CATGeoFactory;

    
class ExportedByGeoApprox CATApproxCurve : public CATCGMOperator
{

  public:
    //-------------
    // Constructor
    //-------------

    CATApproxCurve(CATGeoFactory *iFactory);

    //-------------
    // Destructor
    //-------------
    ~CATApproxCurve();

    //---------------------------------------
    // Set some parameters for approximation
    //---------------------------------------

    // Set Limits : the approximation will be done in this limits
    virtual int SetLimits(const CATCrvLimits * iLimits) = 0;

 	// SetContinuitiesOrder : 
 	virtual int SetOrder(const int iOrder) = 0;

    // Set some parameters for approximation
    virtual int SetTolerance(const double iTol) = 0;

    // Set some parameters for approximation
    virtual int SetParams(const int iMaxDeg,
    		              const int MaxSegments,
						  const int PrecisCode = 1) = 0;


    //---------------------
    // Get the results
    //---------------------

    // Even if Run() is false, a result can exists without satisfying the requiered
    // tolerance 
    virtual CATBoolean GetHasResult() const = 0;

    // Get the resulting NURBS Curve
    virtual CATNurbsCurve * GetCurve() const = 0;

    // Get the maximum error 
    virtual double GetMaxError() const =0;



};


/**
 * Do a new a CATApproxCurve operator from memory.
 */	
ExportedByGeoApprox CATApproxCurve * CreateApproxCurve ( CATGeoFactory *iWhere,
                                                          CATCurve *iCurve1,
                                                          CATSkillValue iMode=BASIC );


/**
 * Removes a CATApproxCurve operator from memory.
 */	
ExportedByGeoApprox void Remove( CATApproxCurve * iOperatorToRemove);


#endif
