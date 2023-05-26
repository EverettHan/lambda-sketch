#ifndef CATVIZTEXTUREWITHMIPMAP_H
#define CATVIZTEXTUREWITHMIPMAP_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// Class  :  	CATVizTextureWithMipMap
// Date   :  	15/11/05
//-----------------------------------------------------------------------------
//  Inheritance : CATVizTextureWithMipMap
//						CATTexturePixelImage
//							CATPixelImage
//								CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies a texture with mipmaps.
//            The texture is defined with different level of detail, so it contains
//            several mipmaps.
//            The mipmap size should be divided by 2 for each level.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	manage the mipmaps
//		GetMipMapCount
//		GetMipMapNum
//		GetMipMapList
//		AddMipMap
//-----------------------------------------------------------------------------

// Local Framework
#include "CATTexturePixelImage.h"
#include "CATVisTextureObjects.h"
#include "CATListOfCATVizMipMapPixelImage.h"
// VisualizationBase Framework
class CATStreamer;


class ExportedByCATVisTextureObjects CATVizTextureWithMipMap : public CATTexturePixelImage
{
	CATDeclareClass;

public:

	/** Contructs a blank texture of given size with mipmaps.
	 * @param iWidth
	 * Width of the main mipmap used as texture.
	 * @param iHeight
	 * Height of the main mipmap used as texture.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 */
	CATVizTextureWithMipMap(const int iWidth, 
							const int iHeight,
							const PixelImageFormat iPixelDataFormat);

	/** Copy constructor */
	CATVizTextureWithMipMap(const CATVizTextureWithMipMap& iTextureWithMipmap);

	/**
	 * Duplicates a texture with mipmaps.
	 * <br>This allows to modify a <tt>ReadOnly</tt> texture.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizTextureWithMipMap</tt> pointer</dt>
	 *  <dd>The resulting texture is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates a texture with mipmaps and changes the format of the resulting texture.
	 * <br>This allows to modify a <tt>ReadOnly</tt> texture.
	 * @param iFormat
	 *   The new format.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizTextureWithMipMap</tt> pointer</dt>
	 *  <dd>The resulting texture is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate(CATPixelImageFormat iFormat) const;

	/** Deletes the texture. */
#ifdef ADDREFERENCE_MIGRATION
	virtual ULONG   __stdcall Release();
#else
	virtual int Destroy();
#endif

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
	 * Retrieves the texture main mipmap size in pixels.
	 * @param oXSize
	 *   Image width in pixels.
	 * @param oYSize
	 *   Image height in pixels.
	 */
	virtual void GetSize(int& oXSize, int& oYSize) const { oXSize = _mainMipMapPixelWidth, oYSize = _mainMipMapPixelHeight; }

	/**
	 * Retrieves the texture format.
	 * Returns the image format.
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
	 * Changes the texture format.
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
	 * Writes the texture to a file.
	 * @param iFileFormat
	 *   The output file format.
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>"DDS"</dt>
	 *  <dd>Microsoft DirectDraw Surface.</dd>
	 * </dl>
	 * @param iPathName
	 *   The file to save the image in.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 * </dl>
	 */
	virtual int WriteToFile(const CATString& iFileFormat, const CATString& iPathName) const;

	/**
	 * Get the number of mipmaps defining the texture.
	 * @return
	 * <dl>
	 *  <dt>the number of mipmaps in the texture.</dt>
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
	 * Get the mipmap list defining the texture with several levels of detail.
	 * @return
	 * <dl>
	 *  <dt>The mipmap list <tt>CATListOfCATVizMipMapPixelImage</tt>.</dt>
	 * </dl>
	 */
	CATLISTP(CATVizMipMapPixelImage)* GetMipMapList();

	/**
	 * Add a mipmap to the texture.
	 * @param iMipMapPixelImage
	 * The mipmap to add.
	 */
	void AddMipMap(CATVizMipMapPixelImage* iMipMapPixelImage);

        /** @nodoc */
        virtual CATTexturePixelImageType GetTextureType();

protected:

	/** @nodoc */
	virtual ~CATVizTextureWithMipMap();

protected:

	CATLISTP(CATVizMipMapPixelImage)* _paMipMapList;

private:

	// size of the main mipmap
	unsigned int _mainMipMapPixelHeight;
	unsigned int _mainMipMapPixelWidth;

	// format of all the mipmaps
	CATPixelImageFormat _mainMipMapFormat;
};

#endif
