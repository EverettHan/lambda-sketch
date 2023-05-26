//----------------------------------------------------------------------------
//	CATMMediaImageDimension.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageDimension_H
#define CATMMediaImageDimension_H

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaRasterFormats_SB_File.h"

/**
 * Class to represent a pixel image dimension
 * <b>Role</b>: This object is used to describe image dimension.<br>
 * <br>
 * @see CATPixelImageFormat
 */
//class ExportedByCATMMediaRasterFormats CATMMediaImageDimension
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageDimension
{
public:
    /**
     * Default constructor.
     */
    CATMMediaImageDimension();

    /**
     * Constructs with full paramater.
     * @param iWidth
     *   The width of the image in pixels.
     * @param iHeight
     *   The height of the image in pixels.
     * @param iXdpi
     *   The number of dot per inch in X direction.
     * @param iYdpi
     *   The number of dot per inch in Y direction.
     */
	CATMMediaImageDimension(const int iWidth, const int iHeight, const long iXdpi, const long iYdpi);

	/** @nodoc */		
	virtual ~CATMMediaImageDimension();

    /**
     * Retrieves the image width in pixels.
     */
	int GetWidth() const				{ return _Width; }

    /**
     * Retrieves the image height in pixels.
     */
	int GetHeight()	const				{ return _Height; }

    /**
     * Retrieves number of pixel (dot) per inch, in X direction.
     */
    long GetXdpi() const				{ return _Xdpi; }

    /**
     * Retrieves number of pixel (dot) per inch, in Y direction.
     */
	long GetYdpi() const				{ return _Ydpi; }

    /**
     * Retrieves the aspect ratio (X*xdpi)/(Y*ydpi)
     */
	float GetRatio() const				
	{
		if (HasMetric()) return (GetWidthInInch()/GetHeightInInch());
		if (_Height != 0) return (float(_Width)/float(_Height));
		return 0.0f;
	}

    /**
     * Retrieves if number of pixel (dot) per inch, in X or Y direction is valid.
     */
	int HasMetric() const				{ return ((_Xdpi != 0) && (_Xdpi != 0)); }

	// --- computed ---
    /**
     * Retrieves the image width in inches.
     */
	float GetWidthInInch() const		{ return (_Xdpi != 0 ) ? (float)_Width/(float)_Xdpi : 0.0f; }

    /**
     * Retrieves the image height in inches.
     */
	float GetHeightInInch() const		{ return (_Ydpi != 0 ) ? (float)_Height/(float)_Ydpi : 0.0f; }

    /**
     * Retrieves the image width in Mm.
     */
	float GetWidthInMm() const			{ return GetWidthInInch()*25.4f; }
	
    /**
     * Retrieves the image height in Mm.
     */
	float GetHeightInMm() const			{ return GetHeightInInch()*25.4f; }

    /**
     * Sets the width pixel size.
     * @param iWidth
     *   The new width pixel size.
     */
	void SetWidth(const int iWidth)		{ _Width = iWidth; }

    /**
     * Sets the height pixel size.
     * @param iHeight
     *   The new height pixel size.
     */
	void SetHeight(const int iHeight)	{ _Height = iHeight; }

    /**
     * Sets number of pixel (dot) per inch, in X direction.
     * @param iXdpi
     *   The new dot per inch in X direction.
     */
	void SetXdpi(const long iXdpi)		{ _Xdpi = iXdpi; }

    /**
     * Sets number of pixel (dot) per inch, in Y direction.
     * @param iYdpi
     *   The new dot per inch in Y direction.
     */
	void SetYdpi(const long iYdpi)		{ _Ydpi = iYdpi; }

private:	
	long	_Xdpi;
	long	_Ydpi;
	int		_Width;				// in pixel
	int		_Height;			// in pixel
};

#endif // CATMMediaImageDimension_H
