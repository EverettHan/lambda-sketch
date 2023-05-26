#ifndef CATVIZFACEWITHMIPMAP_H
#define CATVIZFACEWITHMIPMAP_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// Class  :  	CATVizFaceWithMipMap
// Date   :  	15/11/05
//-----------------------------------------------------------------------------
//  Inheritance : CATVizFaceWithMipMap
//					CATVizFacePixelImage
//						CATPixelImage
//							CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies a face with mipmaps.
//            The face is defined with different level of detail, so it contains
//            several mipmaps.
//            The mipmap size should be divided by 2 for each level.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

// Local Framework
#include "CATVizFacePixelImage.h"
#include "CATVisTextureObjects.h"
#include "CATListOfCATVizMipMapPixelImage.h"
// VisualizationBase Framework
class CATStreamer;


class ExportedByCATVisTextureObjects CATVizFaceWithMipMap : public CATVizFacePixelImage
{
	CATDeclareClass;

public:

	/** Contructs a blank face of given size with mipmaps.
	 * @param iWidth
	 * Width of the main mipmap.
	 * @param iHeight
	 * Height of the main mipmap.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 */
	CATVizFaceWithMipMap(const int iWidth,
						 const int iHeight, CATViz_CubeMap iCubeMapOrientation,
						 const PixelImageFormat iPixelDataFormat);

	/** Copy constructor */
	CATVizFaceWithMipMap(const CATVizFaceWithMipMap& iFaceWithMipMap);

	/**
	 * Duplicates a face with mipmaps.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizFaceWithMipMap</tt> pointer</dt>
	 * </dl>
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates a face with mipmaps and changes the format of the resulting face.
	* @param iFormat
	*   The new format.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizFaceWithMipMap</tt> pointer</dt>
	 * </dl>
	 */
	virtual CATPixelImage* Duplicate(CATPixelImageFormat iFormat) const;

	/** @nodoc */
	virtual void Stream(CATStreamer& oStreamer, int iSaveType = 0);

	/** @nodoc */
	virtual void Stream(CATStreamer& oStreamer, int iSaveType, CATStreamFormat iStrCmpFormat);

	/** @nodoc */
	virtual void UnStream(CATStreamer& iStreamer);

	/** @nodoc */
	static void GetStreamFormat(CATStreamer& iStreamer, CATStreamFormat& oStrCmpFormat);

	/**
	 * Returns the number of bytes per pixel.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>1</dt>
	 *  <dd>L format.</dd>
	 *  <dt>2</dt>
	 *  <dd>LA format.</dd>
	 *  <dt>3</dt>
	 *  <dd>RGB format.</dd>
	 *  <dt>4</dt>
	 *  <dd>RGBA format.</dd>
	 *  <dt>0</dt>
	 *  <dd>Invalid format.</dd>
	 * </dl>
	 * @see CATPixelImageFormat
	 */
	virtual int GetbytesPerPixel() const;

	/**
	 * Returns the number of bits per pixel.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>8</dt>
	 *  <dd>L format.</dd>
	 *  <dt>16</dt>
	 *  <dd>LA format.</dd>
	 *  <dt>24</dt>
	 *  <dd>RGB format.</dd>
	 *  <dt>32</dt>
	 *  <dd>RGBA format.</dd>
	 *  <dt>0</dt>
	 *  <dd>Invalid format.</dd>
	 * </dl>
	 * @see CATPixelImageFormat
	 */
	virtual int GetBitsPerPixel() const;

	/**
	 * Retrieves the main mipmap size in pixels.
	 * @param oXSize
	 *   Image width in pixels.
	 * @param oYSize
	 *   Image height in pixels.
	 */
	virtual void GetSize(int& oXSize, int& oYSize) const { oXSize = _mainMipMapPixelWidth, oYSize = _mainMipMapPixelHeight; }

	/**
	 * Retrieves the face format.
	 * Returns the format.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>L</dt>
	 *  <dd>L format.</dd>
	 *  <dt>LA</dt>
	 *  <dd>LA format.</dd>
	 *  <dt>RGB</dt>
	 *  <dd>RGB format.</dd>
	 *  <dt>RGBA</dt>
	 *  <dd>RGBA format.</dd>
	 *  <dt>BADFORMAT</dt>
	 *  <dd>Invalid format.</dd>
	 * </dl>
	 */
	virtual CATPixelImageFormat GetFormat() const { return _mainMipMapFormat; }

	/**
	 * Changes the face format.
	 * <br>Valid conversions are: <tt>RGB</tt> to <tt>RGBA</tt> and <tt>RGBA</tt> to <tt>RGB</tt>.
	 * @param iFormat
	 *   The new format.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 * </dl>
	 */
	virtual int ChangeFormat(CATPixelImageFormat iFormat);

	/**
	 * Get the number of mipmaps defining the face.
	 * @return
	 * <dl>
	 *  <dt>the number of mipmaps of the face.</dt>
	 * </dl>
	 */
	unsigned int GetMipMapCount(void);

	/**
     * Get the mipmap defining the texture with detail n.
	 * @param iMipMapNum
	 *   The detail number of the mimap.
	 * <br><b>Legal values</b>
	 * <dl>
	 *  This number is less or equal to the mimap count and superior to 0.
	 * </dl>
     * @return
     * <dl>
	 *  <dt>The mipmap <tt>CATVizMipMapPixelImage</tt>.</dt>
     * </dl>
     */
	CATVizMipMapPixelImage* GetMipMap(unsigned int iMipMapNum);

	/**
	 * Get the mipmap list defining the face with several levels of detail.
	 * @return
	 * <dl>
	 *  <dt>The mipmap list <tt>CATListOfCATMimpmapPixelImage</tt>.</dt>
	 * </dl>
	 */
	CATLISTP(CATVizMipMapPixelImage)* GetMipMapList();

	/**
	 * Add a mipmap to the face.
	 * @param iMipMapPixelImage
	 * The mipmap to add.
	 */
	void AddMipMap(CATVizMipMapPixelImage* iMipMapPixelImage);

protected:

	/** @nodoc */
	virtual ~CATVizFaceWithMipMap();

private:

	// mipmap list
	CATLISTP(CATVizMipMapPixelImage)* _paMipMapList;

	// size of the main mipmap
	unsigned int _mainMipMapPixelHeight;
	unsigned int _mainMipMapPixelWidth;

	// format of all the mipmaps
	CATPixelImageFormat _mainMipMapFormat;
};

#endif
