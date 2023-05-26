//----------------------------------------------------------------------------
//	CATMMGenericFilter.h
//----------------------------------------------------------------------------
//	Creation by O1X
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2012
//----------------------------------------------------------------------------
#ifndef CATMMGenericFilter_H
#define CATMMGenericFilter_H
#include <math.h>
#include "CATMMediaRasterProcessor_Base.h"

//----------------------------------------------------------------------------
// Upsampling / downsampling filters
//
//----------------------------------------------------------------------------

/**
 *  @ingroup groupMMPIResize
 */
class ExportedByCATMMediaRasterProcessor_Base CATMMGenericFilter
{
protected:

    #define FILTER_PI  double (3.1415926535897932384626433832795)
    #define FILTER_2PI double (2.0 * 3.1415926535897932384626433832795)
    #define FILTER_4PI double (4.0 * 3.1415926535897932384626433832795)

    /// Filter support
	double  m_dWidth;

public:
    
    /// Constructor
	CATMMGenericFilter (double dWidth) : m_dWidth (dWidth) {}
	/// Destructor
    virtual ~CATMMGenericFilter() {}

    /// Returns the filter support
	double GetWidth()                   { return m_dWidth; }
	/// Change the filter suport
    void   SetWidth (double dWidth)     { m_dWidth = dWidth; }

    /// Returns F(dVal) where F is the filter's impulse response
	virtual double Filter (double dVal) = 0;
};

// -----------------------------------------------------------------------------------
// Filters library
// All filters are centered on 0
// -----------------------------------------------------------------------------------

/**
 *  @ingroup groupMMPIResize
 * Box filter<br>
 *  Box, pulse, Fourier window, 1st order (constant) b-spline.<br><br>
 * 
 *  <b>Reference</b> : <br>
 *  Glassner A.S., Principles of digital image synthesis. Morgan Kaufmann Publishers, Inc, San Francisco, Vol. 2, 1995
 */
class CATMMBoxFilter : public CATMMGenericFilter
{
public:
    /**
	Constructor<br>
	Default fixed width = 0.5
	*/
    CATMMBoxFilter() : CATMMGenericFilter(0.5) {}
    virtual ~CATMMBoxFilter() {}

    double Filter (double dVal) { return (fabs(dVal) <= m_dWidth ? 1.0 : 0.0); }
};

/**
 *  @ingroup groupMMPIResize
 * Bilinear filter
 */
class CATMMBilinearFilter : public CATMMGenericFilter
{
public:

    CATMMBilinearFilter () : CATMMGenericFilter(1) {}
    virtual ~CATMMBilinearFilter() {}

    double Filter (double dVal) {
		dVal = fabs(dVal); 
		return (dVal < m_dWidth ? m_dWidth - dVal : 0.0); 
	}
};


/**
 *  @ingroup groupMMPIResize
 * Mitchell & Netravali's two-param cubic filter<br>
 * 
 * The parameters b and c can be used to adjust the properties of the cubic. 
 * They are sometimes referred to as "blurring" and "ringing" respectively. 
 * The default is b = 1/3 and c = 1/3, which were the values recommended by 
 * Mitchell and Netravali as yielding the most visually pleasing results in subjective tests of human beings. 
 * Larger values of b and c can produce interesting op-art effects--for example, try b = 0 and c = -5. <br><br>
 * 
 * <b>Reference</b> : <br>
 * Don P. Mitchell and Arun N. Netravali, Reconstruction filters in computer graphics. 
 * In John Dill, editor, Computer Graphics (SIGGRAPH '88 Proceedings), Vol. 22, No. 4, August 1988, pp. 221-228.
 */
class CATMMBicubicFilter : public CATMMGenericFilter
{
protected:
	// data for parameterized Mitchell filter
    double p0, p2, p3;
    double q0, q1, q2, q3;

public:
    /**
	Constructor<br>
	Default fixed width = 2
	@param b Filter parameter (default value is 1/3)
	@param c Filter parameter (default value is 1/3)
	*/
    CATMMBicubicFilter (double b = (1/(double)3), double c = (1/(double)3)) : CATMMGenericFilter(2) {
		p0 = (6 - 2*b) / 6;
		p2 = (-18 + 12*b + 6*c) / 6;
		p3 = (12 - 9*b - 6*c) / 6;
		q0 = (8*b + 24*c) / 6;
		q1 = (-12*b - 48*c) / 6;
		q2 = (6*b + 30*c) / 6;
		q3 = (-b - 6*c) / 6;
	}
    virtual ~CATMMBicubicFilter() {}

    double Filter(double dVal) { 
		dVal = fabs(dVal);
		if(dVal < 1)
			return (p0 + dVal*dVal*(p2 + dVal*p3));
		if(dVal < 2)
			return (q0 + dVal*(q1 + dVal*(q2 + dVal*q3)));
		return 0;
	}
};

/**
 *  @ingroup groupMMPIResize
 * Catmull-Rom spline, Overhauser spline<br>
 * 
 * When using CBicubicFilter filters, you have to set parameters b and c such that <br>
 * b + 2 * c = 1<br>
 * in order to use the numerically most accurate filter.<br>
 * This gives for b = 0 the maximum value for c = 0.5, which is the Catmull-Rom 
 * spline and a good suggestion for sharpness.<br><br>
 * 
 * 
 * <b>References</b> : <br>
 * <ul>
 * <li>Mitchell Don P., Netravali Arun N., Reconstruction filters in computer graphics. 
 * In John Dill, editor, Computer Graphics (SIGGRAPH '88 Proceedings), Vol. 22, No. 4, August 1988, pp. 221-228.
 * <li>Keys R.G., Cubic Convolution Interpolation for Digital Image Processing. 
 * IEEE Trans. Acoustics, Speech, and Signal Processing, vol. 29, no. 6, pp. 1153-1160, Dec. 1981.
 * </ul>
 */
class CATMMCatmullRomFilter : public CATMMGenericFilter
{
public:

    /**
	Constructor<br>
	Default fixed width = 2
	*/
	CATMMCatmullRomFilter() : CATMMGenericFilter(2) {}
    virtual ~CATMMCatmullRomFilter() {}

    double Filter(double dVal) { 
		if(dVal < -2) return 0;
		if(dVal < -1) return (0.5*(4 + dVal*(8 + dVal*(5 + dVal))));
		if(dVal < 0)  return (0.5*(2 + dVal*dVal*(-5 - 3*dVal)));
		if(dVal < 1)  return (0.5*(2 + dVal*dVal*(-5 + 3*dVal)));
		if(dVal < 2)  return (0.5*(4 + dVal*(-8 + dVal*(5 - dVal))));
		return 0;
	}
};

/**
 *  @ingroup groupMMPIResize
 * Lanczos-windowed sinc filter<br>
 * 
 * Lanczos3 filter is an alternative to CBicubicFilter with high values of c about 0.6 ... 0.75 
 * which produces quite strong sharpening. It usually offers better quality (fewer artifacts) and a sharp image.<br><br>
*/
class CATMMLanczos3Filter : public CATMMGenericFilter
{
public:
    /**
	Constructor<br>
	Default fixed width = 3
	*/
	CATMMLanczos3Filter() : CATMMGenericFilter(3) {}
    virtual ~CATMMLanczos3Filter() {}

    double Filter(double dVal) { 
		dVal = fabs(dVal); 
		if(dVal < m_dWidth)	{
			return (sinc(dVal) * sinc(dVal / m_dWidth));
		}
		return 0;
	}

private:
	double sinc(double value) {
		if(value != 0) {
			value *= FILTER_PI;
			return (sin(value) / value);
		} 
		return 1;
	}
};

/**
 * 4th order (cubic) b-spline<br>
 */
class CATMMBSplineFilter : public CATMMGenericFilter
{
public:

    /**
	Constructor<br>
	Default fixed width = 2
	*/
	CATMMBSplineFilter() : CATMMGenericFilter(2) {}
    virtual ~CATMMBSplineFilter() {}

    double Filter(double dVal) { 

		dVal = fabs(dVal);
		if(dVal < 1) return (4 + dVal*dVal*(-6 + 3*dVal)) / 6;
		if(dVal < 2) {
			double t = 2 - dVal;
			return (t*t*t / 6);
		}
		return 0;
	}
};
#endif
