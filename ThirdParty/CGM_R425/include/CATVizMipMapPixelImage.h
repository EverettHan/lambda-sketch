#ifndef CATVIZMIPMAPPIXELIMAGE_H
#define CATVIZMIPMAPPIXELIMAGE_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// Class  :  	CATVizMipMapPixelImage
// Date   :  	15/11/05
//-----------------------------------------------------------------------------
//  Inheritance : CATVizMipMapPixelImage
//							CATPixelImage
//								CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies a mipmap.
//            A mipmap is used as a texture for different level of detail.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

// Local Framework
#include "CATPixelImage.h"
#include "CATVisTextureObjects.h"


class ExportedByCATVisTextureObjects CATVizMipMapPixelImage : public CATPixelImage
{
	CATDeclareClass;

public:

	/** Contructs a blank mimap of given size.
	 * @param iWidth
	 * Width of the mimap used as texture.
	 * @param iHeight
	 * Height of the mimap used as texture.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 */
	CATVizMipMapPixelImage(const int iWidth,
						   const int iHeight,
						   const PixelImageFormat iPixelDataFormat);

	/** Constructs a mimap of given size and data.
	 * @param iWidth
	 * Width of the mimap used as texture.
	 * @param iHeight
	 * Height of the mimap used as texture.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 * @param iPixelData
	 * Data of the mimap used as texture.
	 */
	CATVizMipMapPixelImage(const int iWidth,
						   const int iHeight,
						   const PixelImageFormat iPixelDataFormat,
						   unsigned char* iPixelData,
						   CATDeallocatePixels iToDelete = PixDeallocateNO);

  CATVizMipMapPixelImage(const int iWidth,
    const int iHeight,
    const PixelImageFormat iPixelDataFormat,
    float* iPixelData,
    CATDeallocatePixels iToDelete = PixDeallocateNO);

	/** Copy constructor */
	CATVizMipMapPixelImage(const CATPixelImage& iPixelImage);

	/** Copy constructor */
	CATVizMipMapPixelImage(const CATVizMipMapPixelImage& iMipMap);

	/**
	 * Duplicates a mipmap.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizMipMapPixelImage</tt> pointer</dt>
	 * </dl>
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates a mipmap and changes the format of the resulting mipmap.
	* @param iFormat
	*   The new format.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizMipMapPixelImage</tt> pointer</dt>
	 * </dl>
	 */
	virtual CATPixelImage* Duplicate(CATPixelImageFormat iFormat) const;

	/** Modify the mipmap.
	 * @param iWidth
	 * Width of new image.
	 * @param iHeight
	 * Height of new image.
	 * @param iFormat
	 * Pixel data format of new image used.
	 * @param iPixels
	 * Pixel data of new image used
	 * @param iFlag
	 * Inactive.
	*/
	virtual int Modify(int iWidth,
					   int iHeight, 
					   PixelImageFormat iFormat, 
					   unsigned char* iPixels,
					   DeallocatePixels iFlag = PixDeallocateYESfree);

protected:

	/** @nodoc */
	virtual ~CATVizMipMapPixelImage();
};

#endif
