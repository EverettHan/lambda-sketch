#ifndef CATVIZANIMATEDTEXTURE_H
#define CATVIZANIMATEDTEXTURE_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
//-----------------------------------------------------------------------------
// Class  :  	CATVizAnimatedTexture
// Date   :  	08/02/07
//-----------------------------------------------------------------------------
//  Inheritance : CATVizAnimatedTexture
//					CATTexturePixelImage
//						CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies texture with an animation of pixel images.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

// Local Framework
#include "SGInfra.h"
#include "CATTexturePixelImage.h"
#include "CATTexturePixelImage.h"
#include "list.h"


class ExportedBySGInfra CATVizAnimatedTexture : public CATTexturePixelImage
{
	CATDeclareClass;

public:

	/** Contructs an empty animated texture.
	 * @param iWidth
	 * Width of the image used as the texture.
	 * @param iHeight
	 * Height of the image used as the texture.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 */
	CATVizAnimatedTexture(const int iWidth, 
						  const int iHeight,
						  const PixelImageFormat iPixelDataFormat);

	/** Copy constructor */
	CATVizAnimatedTexture(const CATVizAnimatedTexture& iAnimation);

	/**
	 * Duplicates an animated texture.
	 * <br>This allows to modify an <tt>ReadOnly</tt> animated texture.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizAnimatedTexture</tt> pointer</dt>
	 *  <dd>The resulting animated texture is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates an animated texture and changes the format of the resulting animated texture.
	 * <br>This allows to modify an <tt>ReadOnly</tt> animated texture.
	 * @param iFormat
	 *   The new format.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizAnimatedTexture</tt> pointer</dt>
	 *  <dd>The resulting animated texture is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate(CATPixelImageFormat iFormat) const;

	/** Deletes the animated texture. */
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
	 * Retrieves the animated texture size.
	 * @param oXSize
	 *   Display width in pixels.
	 * @param oYSize
	 *   Display height in pixels.
	 */
	virtual void GetSize(int& oXSize, int& oYSize) const { oXSize = _texturePixelWidth, oYSize = _texturePixelHeight; }

	/**
	 * Retrieves the animated texture format.
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
	virtual CATPixelImageFormat GetFormat() const { return _animatedTextureFormat; }

	/**
	 * Changes the animated texture format.
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
	 * Get the number of frames defining the animation.
	 * @return
	 * <dl>
	 *  <dt>the number of frames in the animation.</dt>
	 * </dl>
	 */
	unsigned int GetFramesCount(void) const;

    /**
     * Get the frame with number iFrameNum in the animation.
	 * @param iFrameNum
	 *   The frame number.
	 * <br><b>Legal values</b>
	 * <dl>
	 *  This number is less or equal to the frame count and superior to 0.
	 * </dl>
     * @return
     * <dl>
	 *  <dt>The frame <tt>CATPixelImage</tt>.</dt>
     * </dl>
     */
	CATTexturePixelImage* GetFrame(unsigned int iFrameNum);

	/**
	 * Get the frame list defining the animation.
	 * @return
	 * <dl>
	 *  <dt>The frame list <tt>CATListOfCATPixelImage</tt>.</dt>
	 * </dl>
	 */
	list<CATTexturePixelImage>* GetFrameList();

	/**
	 * Add a frame to the animation.
	 * @param iFrame
	 * The frame to add.
	 */
	void AddFrame(CATTexturePixelImage* iprFrame);

	/**
	 * Get / Set the frame delay of the animation in ms.
	 */
    void SetFrameDelay(float iFrameDelay);
    void GetFrameDelay(float& oFrameDelay);

	/**
	 * Get / Set the animation iteration maximum.
	 */
    void SetIterationMax(unsigned int iIterationMax);
    void GetIterationMax(unsigned int& oIterationMax);

    /**
	 * Get / Set the delay before repeating the animation.
	 */
    void SetTermDelay(float iTermDelay);
    void GetTermDelay(float& oTermDelay);

protected:

    /** Deletes the animation. */
	virtual ~CATVizAnimatedTexture();

private:

	// size of the texture
	unsigned int _texturePixelWidth;
	unsigned int _texturePixelHeight;

	// frame rate
    float _frameDelay;

    // frame list
    list<CATTexturePixelImage>* _paFrameList;

    // frame iteration maximum
    unsigned int _iterationMax;

    // term delay
    float _termDelay;

	// format for the whole texture
	CATPixelImageFormat _animatedTextureFormat;

};
#endif
