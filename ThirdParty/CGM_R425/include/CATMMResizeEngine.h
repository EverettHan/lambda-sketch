//----------------------------------------------------------------------------
//	CATMMResizeEngine.h
//----------------------------------------------------------------------------
//	Creation by O1X
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2012
//----------------------------------------------------------------------------
#ifndef CATMMResizeEngine_H
#define CATMMResizeEngine_H
#include "CATMMediaRasterProcessor_Base.h"
//This class performs filtered zoom. It scales an image to the desired dimensions with 
//any of the CGenericFilter derived filter class.<br>
//It works with 8-, 24- and 32-bit buffers.<br><br>

class CATMMGenericFilter;
class CATPixelImage;

/**
 *  @ingroup groupPixelImageTransfo
 * @defgroup groupMMPIResize Pixel Image Resize Transformation.
 * Supported formats:
 * |     Format     | Resize support |
 * | :------------- | :------------: |
 * | L              |  Implemented   |
 * | LA             |                |
 * | RGB            |  Implemented   |
 * | RGBA           |  Implemented   |
 * | BILEVEL        |                |
 * | BADFORMAT      |                |
 * | RGB_S3TC_DXT1  |                |
 * | RGBA_S3TC_DXT1 |                |
 * | RGBA_S3TC_DXT3 |                |
 * | RGBA_S3TC_DXT5 |                |
 * | RGB_f          |  Implemented   |  
 * | RGBA_f         |  Implemented   |  
 * | BGR            |                |
 * | BGRA           |                |
 * | L_f            |                |
 * | L_f16          |                |
 * | L_i32          |                |
 * | RGB_f16        |                |
 * | RGB_i32        |                |
 * | RGBA_f16       |                |
 * | RGBA_i32       |                |
 **/

 /**
  *  @ingroup groupMMPIResize
  */
 class ExportedByCATMMediaRasterProcessor_Base CATMMResizeEngine
{
private:
	/// Pointer to the FIR / IIR filter
	CATMMGenericFilter* m_pFilter;

public:

    /// Constructor
	CATMMResizeEngine(CATMMGenericFilter* filter):m_pFilter(filter) {}

    /// Destructor
	virtual ~CATMMResizeEngine() {}

    /** Scale an image to the desired dimensions
	@param src Pointer to the source image
	@param dst_width Destination image width
	@param dst_height Destination image height
	@return Returns the scaled image if successful, returns NULL otherwise
	*/
	CATPixelImage* scale(CATPixelImage *src, unsigned dst_width, unsigned dst_height);

private:

    /// Performs horizontal image filtering
	void horizontalFilter(CATPixelImage *src, unsigned src_width, unsigned src_height, CATPixelImage *dst, unsigned dst_width, unsigned dst_height);

    /// Performs vertical image filtering
    void verticalFilter(CATPixelImage *src, unsigned src_width, unsigned src_height, CATPixelImage *dst, unsigned dst_width, unsigned dst_height);
};

#endif
