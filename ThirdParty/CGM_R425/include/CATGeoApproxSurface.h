#ifndef _CATGeoApproxSurface_HeaderFile
#define _CATGeoApproxSurface_HeaderFile
    
// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATCGMOperator.h"

#include "GeoApprox.h" 

class CATNurbsSurface;
class CATSurface;
class CATGeoFactory;
class CATSurLimits;

 /**
 * Operator that approximates a surface into a BSpline Surface.
 * <br>The surface to approximate must be C2 continuous.
 */    
class ExportedByGeoApprox CATGeoApproxSurface : public CATCGMOperator
{

  public:
    /**
 * @nodoc
 * Constructs a CATGeoApproxSurface operator.<br>
 * Can never be called. Use the <tt>CATCreateApproxSur</tt> global function
 * to create a CATGeoApproxSurface operator.
 */
    CATGeoApproxSurface(CATGeoFactory *iFactory);

    ~CATGeoApproxSurface() ;


    // Set the tolerance for approximation
	// default value = factory resolution.
/**
 * Sets the tolerance of the approximation.
 * <br>By default, (that is to say, this method is not called),
 * the tolerance is set to the factory resolution.
 */
    virtual int SetTolerance(const double iTol) = 0;


	/**
	 * Defines the order of the constraints requiered
	 * for internal continuities of the resulting surface.
	 * @param iUOrder
	 * The order of continuity in the u direction for the resulting BSpline.
	 * <br><bb>Legal values</bb>: <tt>0 <= iUOrder <= 2</tt>.
	 * By default, this value is set to 2.
	 * Set it to 1 if the surface to approximate is not C2 continuous in the 
	 * u direction.
	 * @param iVOrder
	 * The order of continuity in the v direction for the resulting BSpline.
	 * <br><bb>Legal values</bb>: <tt>0 <= iVOrder <= 2</tt>.
	 * By default, this value is set to 2.
	 * Set it to 1 if the surface to approximate is not C2 continuous in the 
	 * v direction.
	 **/

 	virtual int SetOrder(const int iUOrder,         
  	                     const int iVOrder) = 0;   

	/**
	 * Defines the parameters that tune the approximation.
	 * @param iMaxDegU
	 * The maximum degree in the u direction for the resulting BSpline.
	 * <br><bb>Legal values</bb>: <tt>2*iUOrder+1 <= iMaxDegU <= 11</tt>.
	 * By default, this value is set to 8.
	 * @param iMaxDegV
	 * The maximum degree in the v direction for the resulting BSpline.
	 * <br><bb>Legal values</bb>: <tt>2*iVOrder+1 <= iMaxDegV <= 11</tt>.
	 * By default, this value is set to 8.
	 * @param iMaxSegments
	 * The maximum number of segments for the resulting BSpline
	 * @param iPrecisCode
	 * The balance between the velocity and the accuracy of the computation of maximum distance 
	 * between the initial surface and its approximation.
	 * <br><bb>Legal values</bb>:
	 * from 0 (fast, but less precise on the maximum distance computation) to 
	 * 3 (slower, but much more precise on the maximum distance computation). 
	 * The default value is set to 1.
	 * @param iMinSegments
	 * The minimum number of segments for the resulting BSpline
	 * The default value is set to 1.
	 * @return
	 * A positive value if the input parameters are out of range.
	 */
    virtual int SetParams(const int iMaxDegU=8,      
    					  const int iMaxDegV=8,       
    					  const int iMaxSegments=64,    
    					  const int iPrecisCode=1,
						  const int iMinSegments=1) = 0;

    //---------------------
    // Get the results
    //---------------------

	/**
	 * Returns a pointer to the resulting approximated Nupbs surface.
	 */
    virtual CATNurbsSurface * GetSurface() const = 0;

	/**
	 * Returns the maximum distance between the original surface and its approximation.
	 */
    virtual double GetMaxDeviation() const =0;

};


/**
 * Creates a CATGeoApproxSurface operator.
 * @param iWhere
 * The factory where the approximated surface must be created.
 * @param iSurface
 * The surface to approximate.
 * @param iLimits
 * The limitations inside which the approximation is computed.
 */

ExportedByGeoApprox CATGeoApproxSurface * CreateGeoApproxSurface ( CATGeoFactory *iWhere,
                                                                   CATSurface *iSurface,
                                                                   CATSurLimits & iLimits );



#endif
