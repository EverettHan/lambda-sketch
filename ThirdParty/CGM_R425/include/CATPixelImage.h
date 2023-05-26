#ifndef CATPixelImage_H
#define CATPixelImage_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATMMediaPixelImage.h"

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATListOfCATString.h"
#include "CATStatCleaner.h"
#include "CATBaseUnknown.h"
//#include "CATMMPISpec.h"

//#include "CATMMColorProfile.h"
//#include "CATMMColorTransform.h"


class CATUnicodeString;
class CATStreamer;

struct CATMMPISpec;

class CATMMColorProfile;
class CATMMImageMetadata;
class lCATPixelImage;
class CATMMPIBuffer;

#ifndef uchar
/** @nodoc */
typedef unsigned char uchar;
#endif

#ifndef uint
/** @nodoc */
typedef unsigned int uint;
#endif

/**
 * Format of the pixel data stored in a <tt>CATPixelImage</tt>.
 * @param L
 *   Luminance (grey levels): 8-bit images.
 * @param LA
 *   Luminance with alpha: 16 bits.
 * @param RGB
 *   Red, green, blue: 24-bit images.
 * @param RGBA
 *   Red, green, blue with alpha: 32 bits.
 * @param BILEVEL
 *   Unused.
 * @param BADFORMAT
 *   Invalid format.
 * @param RGB_S3TC_DXT1
 *   RGB compression of DXT1 type.
 * @param RGBA_S3TC_DXT1
 *   RGBA compression of DXT1 type.
 * @param RGBA_S3TC_DXT3
 *   RGBA compression of DXT3 type.
 * @param RGBA_S3TC_DXT5
 *   RGBA compression of DXT5 type.
 * @param RGB_f
 *   Red, Green, Blue - 96 bits (float representation)
 * @param RGBA_f
 *  Red, Green, Blue with Alpha - 128 bits. (float representation)
 * @param BGR
 *   Blue, green, red: 24-bit images.
 * @param BGRA
 *   Blue, green, red with alpha: 32 bits.
 * @param L_f
 *   Single float channel: 32 bits.
 * @param L_f16
 *   Single float channel: 16 bits.
 * @param L_i32
 *   Single integer channel: 32 bits.
 * @param RGB_f16
 *   Red, Green, Blue - 48 bits (float representation)
 * @param RGB_i32
 *   Red, Green, Blue - 96 bits (integer representation)
 * @param RGBA_f16
 *   Red, Green, Blue with Alpha - 64 bits. (float representation)
 * @param RGBA_i32
 *   Red, Green, Blue with Alpha - 128 bits (integer representation)
 * @param Specific
 *   Specific format.
 * @see CATPixelImage
 */
enum CATPixelImageFormat
{
  L = 0,
  LA,
  RGB,
  RGBA,
  BILEVEL,
  BADFORMAT,
  RGB_S3TC_DXT1,
  RGBA_S3TC_DXT1,
  RGBA_S3TC_DXT3,
  RGBA_S3TC_DXT5,
  RGB_f,
  RGBA_f,
  BGR,
  BGRA,
  L_f,
  L_f16,
  L_i32,
  RGB_f16,
  RGB_i32,
  RGBA_f16,
  RGBA_i32,
  Specific
};

/** @nodoc */
typedef CATPixelImageFormat PixelImageFormat;

/**
 * Defines whether a <tt>CATPixelImage</tt> can be modified or not.
 * @param ReadOnly
 *   No modifications allowed.
 * @param NotReadOnly
 *   The image can be modified.
 * @see CATPixelImage
 */
enum CATReadOnlyState
{
	ReadOnly = 0,
	NotReadOnly
};

/** @nodoc */
typedef CATReadOnlyState ReadOnlyState;

/**
 * Defines whether the pixel data in a <tt>CATPixelImage</tt> should be deallocated when the image is destroyed,
 * and how (<tt>free()</tt> or <tt>delete[]</tt>).
 * @param PixDeallocateYESdelete
 *   Pixel data has been allocated with the C++ <tt>new</tt> operator and will be deleted when the <tt>CATPixelImage</tt> is destroyed.
 * @param PixDeallocateYESfree
 *   Pixel data has been allocated with the C <tt>malloc()</tt> function and will be deleted when the <tt>CATPixelImage</tt> is destroyed.
 * @param PixDeallocateNO
 *   Pixel data should not be deleted when the <tt>CATPixelImage</tt> is destroyed. It is the user to deallocate the pixel data.
 * @see CATPixelImage
 */
enum CATDeallocatePixels
{
	PixDeallocateYESdelete = 0,
	PixDeallocateYESfree,
	PixDeallocateNO
};

/** @nodoc */
typedef CATDeallocatePixels DeallocatePixels;

/**
 * Format of the secondary pixel data stored in a <tt>CATPixelImage</tt>.
 * @param sRGB
 *   Red, green, blue: 24-bit images.
 * @param sRGBA
 *   Red, green, blue with alpha: 32 bits.
 * @param sABGR
 *   Alpha, blue, green, red: 32-bit images.
 * @param sARGB
 *   Alpha, red, green, blue: 32 bits.
 * @see CATPixelImage
 */
enum CATSecondaryPixelImageFormat
{
	sRGB = 0,
	sRGBA,
	sABGR,
	sARGB
};

/** @nodoc */
typedef CATSecondaryPixelImageFormat SecondaryPixelImageFormat;

/**
 * Line progression of the secondary pixel image stored in a <tt>CATPixelImage</tt>.
 * @param Normalised
 *   Rows are stored bottom line first.
 * @param Inverted
 *   Rows are stored upper line first.
 * @see CATPixelImage
 */
enum CATLineProgression
{
	Normalised = 0,
	Inverted
};

/** @nodoc */
typedef CATLineProgression LineProgression;

/** @nodoc */
enum PhotometricInterpretation
{
	WhiteIsZero = 0,
	BlackIsZero
};

/** @nodoc */
enum CATStreamFormat
{
	Stream_DEFAULT = 0,
	Stream_BADCOMPRESSED,
	Stream_CCITTG3,
	Stream_UNCOMPRESSED,
	Stream_PNG,
	Stream_JPEG
};

/**
 * Dither Algorithm used for Bilevel format.
 * @param DITHER_FloydSteinberg
 *   FloydSteinberg algorithm.
 * @param DITHER_AverageThreshold
 *   Average threshold algorithm.
 */
enum DITHER_MODE
{
	DITHER_FloydSteinberg = 0,
	DITHER_AverageThreshold
};

/**
 * Class to represent a pixel image or texture in memory.
 * <b>Role</b>: This object is used to read, visualize, write pixel images.<br>
 * Supported internal formats are <tt>RGBA</tt>, <tt>RGB</tt>, <tt>LA</tt>, <tt>L</tt> (where <tt>L</tt> stands for
 * Luminance, that is a 8-bit Grey Scale value, and <tt>A</tt> for Alpha), <tt>RGB_S3TC_DXT1</tt>,
 * <tt>RGBA_S3TC_DXT1</tt>, <tt>RGBA_S3TC_DXT3</tt>, <tt>RGBA_S3TC_DXT5</tt>, <tt>RGB_f</tt>, <tt>RGBA_f</tt>.
 * The image can be locked to a <tt>ReadOnly</tt> State. This allows to create only one
 * image, and to reference it many times, with little risks for modification
 * conflicts.<br>
 * <br>
 * You can create a <tt>CATPixelImage</tt> from RGB, TIFF, JPEG, BMP, PNG files.<br>
 * You can visualize a <tt>CATPixelImage</tt> using the @href CAT2DImagePixelRep class.<br>
 * <br>
 * The pointer to the pixel data points to the first pixel of the bottom line (or row) of the image.
 * Origin is bottom left corner.<br>
 * The data is not stored by colors planes, but pixel by pixel
 * (that is : <tt>RGBRGBRGB</tt>... or <tt>RGBARGBARGBA</tt>...).<br>
 * <br>
 * @see CATPixelImageFormat, CATReadOnlyState, CATDeallocatePixels, CATSecondaryPixelImageFormat, CATLineProgression, CAT2DImagePixelRep
 */

class ExportedByCATMMediaPixelImage CATPixelImage : public CATBaseUnknown
{
	friend class CATMarshallablePixelImage;
	friend class CATExtIPixelImageStreaming;
	friend class SGCGRStreamerForPixelImage;
	friend class SGCGRNodesFactoryA;
  friend class lCATPixelImage;

	CATDeclareClass;

	//-------------------------------------------------------------------------
public:

	/**
	 * Default constructor.
	 */
	CATPixelImage();

	/**
	 * Constructs an image from a pixel array, pixel data is not duplicated.
	 * <br>Be careful with this constructor because you have to make sure
	 * to not deallocate pixels memory before any <tt>CATPixelImage</tt> referencing
	 * this data has disappeared. This is true for this image, but also any
	 * image copied from this image.<br>
	 * Use <tt>PixDeallocateYESdelete</tt> if data to delete has been allocated with <tt>new</tt>.
	 * Use <tt>PixDeallocateYESfree</tt> if data to delete has been allocated with <tt>malloc</tt>.<br>
	 * CAREFUL :
	 * Change the iToDelete value to <tt>PixDeallocateYESdelete</tt> or <tt>PixDeallocateYESfree</tt>
	 * do delete pixels when you delete the <tt>CATPixelImage</tt>.
	 * @param iXSize
	 *   The width of the image in pixels.
	 * @param iYSize
	 *   The height of the image in pixels.
	 * @param iFormat
	 *   The format of the data stored in the pixel array.
	 * @param iPixels
	 *   The pixel data.
	 * @param iToDelete
	 *   Whether the given pixel array has to be deleted when the <tt>CATPixelImage</tt> is destroyed, and how (<tt>free()</tt> or <tt>delete[]</tt>).
	 *   The default value for this parameter is <tt>PixelDeallocateNO</tt>, which implies the pixel data is not deleted when the image is destroyed.
	 *   It is the user to delete the pixel data.
	 */
	CATPixelImage(int iXSize, int iYSize, CATPixelImageFormat iFormat, unsigned char* iPixels, CATDeallocatePixels iToDelete = PixDeallocateNO);

	/**
	 * Constructs an image from a pixel array, pixel data is not duplicated.
	 * <br>Be careful with this constructor because you have to make sure
	 * to not deallocate pixels memory before any <tt>CATPixelImage</tt> referencing
	 * this data has disappeared. This is true for this image, but also any
	 * image copied from this image.<br>
	 * Use <tt>PixDeallocateYESdelete</tt> if data to delete has been allocated with <tt>new</tt>.
	 * Use <tt>PixDeallocateYESfree</tt> if data to delete has been allocated with <tt>malloc</tt>.<br>
	 * CAREFUL :
	 * Change the iToDelete value to <tt>PixDeallocateYESdelete</tt> or <tt>PixDeallocateYESfree</tt>
	 * do delete pixels when you delete the <tt>CATPixelImage</tt>.
	 * @param iXSize
	 *   The width of the image in pixels.
	 * @param iYSize
	 *   The height of the image in pixels.
	 * @param iFormat
	 *   The format of the data stored in the pixel array.
	 * @param ifPixels
	 *   The pixel data in float.
	 * @param iToDelete
	 *   Whether the given pixel array has to be deleted when the <tt>CATPixelImage</tt> is destroyed, and how (<tt>free()</tt> or <tt>delete[]</tt>).
	 *   The default value for this parameter is <tt>PixelDeallocateNO</tt>, which implies the pixel data is not deleted when the image is destroyed.
	 *   It is the user to delete the pixel data.
	 */
	CATPixelImage(int iXSize, int iYSize, CATPixelImageFormat iFormat, float* iPixels, CATDeallocatePixels iToDelete = PixDeallocateNO);

	/**
	 * Constructs a blank image.
	 * Use @href #GetPixelsToModify to modify it.
	 * <br>The warning indicated on the previous constructor does not apply here.
	 * @param iXSize
	 *   The width of the image in pixels.
	 * @param iYSize
	 *   The height of the image in pixels.
	 * @param iFormat
	 *   The format of the data.
	 */
	CATPixelImage(int iXSize, int iYSize, CATPixelImageFormat iFormat);

	/**
	 * Copy constructor.
	 * @param iPixelImage
	 *   An existing <tt>CATPixelImage</tt>.
	 */
	CATPixelImage(const CATPixelImage& iPixelImage);

	/**
	 * Assignment operator.
	 * @param iPixelImage
	 *   An existing <tt>CATPixelImage</tt>.
	 */
	CATPixelImage& operator=(const CATPixelImage& iPixelImage);

	/**
	 * @nodoc
	 * Streams a <tt>CATPixelImage</tt>.
	 */
	 virtual void Stream(CATStreamer& oStr, int iSaveType = 0);

	/**
	 * @nodoc
	 * Streams a <tt>CATPixelImage</tt>.
	   * The iStrCmpFormat parameter sets the format type of the stream.
	   * For BILEVEL bitmap, the format used is CCITT Group3(Stream_CCITTG3).
	   * For RGBA, RGB, LA, or L bitmap, the format used can be PNG or JPEG or not compressed
	   * (Stream_PNG or Stream_JPEG or Stream_UNCOMPRESSED).
	 */
	  virtual void Stream(CATStreamer& oStr, int iSaveType, CATStreamFormat iStrCmpFormat);

	/**
	 * @nodoc
	 * UnStreams a <tt>CATPixelImage</tt>.
	 */
	 virtual void UnStream(CATStreamer& iStr);

	/**
	 * @nodoc
	 * Get the format of a <tt>CATPixelImage</tt> stream.
	   * The oStrCmpFormat parameter is the format type of the stream.
	   * For BILEVEL bitmap, the format used is CCITT Group3(Stream_CCITTG3).
	   * For RGBA, RGB, LA, or L bitmap, the format used can be PNG or JPEG or not compressed
	   * (Stream_PNG or Stream_JPEG or Stream_UNCOMPRESSED).
	 */
	 static void GetStreamFormat(CATStreamer& iStr, CATStreamFormat& oStrCmpFormat);

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
	 *  <dd>RGB_S3TC_DXT1 format.</dd>
	 *  <dt>0</dt>
	 *  <dd>RGBA_S3TC_DXT1 format.</dd>
	 *  <dt>0</dt>
	 *  <dd>RGBA_S3TC_DXT3 format.</dd>
	 *  <dt>0</dt>
	 *  <dd>RGBA_S3TC_DXT5 format.</dd>
	 *  <dt>12</dt>
	 *  <dd>RGB_f format.</dd>
	 *  <dt>16</dt>
	 *  <dd>RGBA_f format.</dd>
	 *  <dt>0</dt>
	 *  <dd>Invalid format.</dd>
	 * </dl>
	 * @see CATPixelImageFormat
	 */
	virtual int GetBytesPerPixel() const;
	/**
	 * @deprecated
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
	 *  <dd>RGB_S3TC_DXT1 format.</dd>
	 *  <dt>0</dt>
	 *  <dd>RGBA_S3TC_DXT1 format.</dd>
	 *  <dt>0</dt>
	 *  <dd>RGBA_S3TC_DXT3 format.</dd>
	 *  <dt>0</dt>
	 *  <dd>RGBA_S3TC_DXT5 format.</dd>
	 *  <dt>96</dt>
	 *  <dd>RGB_f format.</dd>
	 *  <dt>128</dt>
	 *  <dd>RGBA_f format.</dd>
	 *  <dt>0</dt>
	 *  <dd>Invalid format.</dd>
	 * </dl>
	 * @see CATPixelImageFormat
	 */
	virtual int GetBitsPerPixel() const;

	/**
	 * Retrieves the image size in pixels.
	 * @param oXSize
	 *   Image width in pixels.
	 * @param oYSize
	 *   Image height in pixels.
	 */
	virtual void GetSize(int& oXSize, int& oYSize) const { oXSize = _xSize, oYSize = _ySize; }

	/**
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
	 *  <dt>RGB_S3TC_DXT1</dt>
	 *  <dd>RGB_S3TC_DXT1 format.</dd>
	 *  <dt>RGBA_S3TC_DXT1</dt>
	 *  <dd>RGBA_S3TC_DXT1 format.</dd>
	 *  <dt>RGBA_S3TC_DXT3</dt>
	 *  <dd>RGBA_S3TC_DXT3 format.</dd>
	 *  <dt>RGBA_S3TC_DXT5</dt>
	 *  <dd>RGBA_S3TC_DXT5 format.</dd>
	 *  <dt>RGB_f</dt>
	 *  <dd>RGB_f format.</dd>
	 *  <dt>RGBA_f</dt>
	 *  <dd>RGBA_f format.</dd>
	 *  <dt>BADFORMAT</dt>
	 *  <dd>Invalid format.</dd>
	 * </dl>
	 */
	virtual CATPixelImageFormat GetFormat() const { return _format; }

	/**
	 * Returns the image format as a string.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>See GetFormat().</dt>
	 * </dl>
	 */
	virtual CATString GetFormatStr() const;

	/**
	 * Returns the pixel data for consultation.
	 * @return
	 * <dl>
	 *  <dt>A <tt>const</tt> pointer to the pixel data</dt>
	 * </dl>
	 */
	virtual const unsigned char* GetPixelsToRead() const { return _pixels; }

	/**
	 * Returns the pixel data for modification.
	 * @return
	 * <dl>
	 *  <dt>A pointer to the pixel data</dt>
	 * </dl>
	 */
	virtual unsigned char* GetPixelsToModify();

	/** @nodoc */
	virtual unsigned char* CreateUncompressedBitmap(int iAlignToDWORD = 0, PhotometricInterpretation iPhoto = BlackIsZero) const;

	/** @nodoc */
	virtual const unsigned char* GetPixelsRuns(int iRow) const { return _runs[iRow]; }
	/** @nodoc */
	virtual unsigned char*& GetPixelsRuns(int iRow) { return _runs[iRow]; }

	/** @nodoc */
	virtual int GetPixelsRunsLength(int iRow) const { return _runsLength[iRow]; }
	/** @nodoc */
	virtual int& GetPixelsRunsLength(int iRow) { return _runsLength[iRow]; }

	/** @nodoc */
	virtual const float* GetFloatingPixelsToRead() const { return _fpixels; }

	/** @nodoc */
	virtual float* GetFloatingPixelsToModify();

	/** @nodoc */
	virtual float* GetFloatingScanLineToModify(int iRow);
	
	/** @nodoc */
	virtual const CATMMPIBuffer* GetPixelsBufferToRead() const;
	
	/** @nodoc */
	virtual CATMMPIBuffer* GetPixelsBufferToModify();

	// virtual CATPixelImage* CreateRotatedImage(int iAngleInDegrees) const;
	/**
	 * Returns the secondary image pixel data for consultation.
	 * @param iFormat
	 *   The secondary image format.
	 * @param iProgression
	 *   The secondary image line progression.
	 * @return
	 * <dl>
	 *  <dt>A <tt>const</tt> pointer to the secondary image pixel data</dt>
	 * </dl>
	 */
	virtual const unsigned char* GetSecondaryPixelsToRead(CATSecondaryPixelImageFormat iFormat, CATLineProgression iProgression);

	/**
	 * Returns the size in mm of one pixel in X direction.
	 */
	virtual float GetXPixelSize() const { return _xPixelSize; }

	/**
	 * Returns the size in mm of one pixel in Y direction.
	 */
	virtual float GetYPixelSize() const { return _yPixelSize; }

	/**
	 * Prevents modifications on the image.
	 * @see CATReadOnlyState
	 */
	virtual void LockAsReadOnly() { _readOnlyState = ReadOnly; }

	/**
	 * Allows modifications on the image.
	 * @see CATReadOnlyState
	 */
	virtual void Unlock() { _readOnlyState = NotReadOnly; }

	/**
	 * Returns TRUE if the image is locked as read only.
	 * Returns FALSE if modifications are allowed.
	 */
	virtual CATBoolean IsReadOnly() const { return (_readOnlyState == ReadOnly); }

	/**
	 * Duplicates an image.
	 * <br>This allows to modify a <tt>ReadOnly</tt> image.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATPixelImage</tt> pointer</dt>
	 *  <dd>The resulting image is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates an image and changes the format of the resulting image.
	 * <br>This allows to modify a <tt>ReadOnly</tt> image.
	 * @param iFormat
	 *   The new format.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATPixelImage</tt> pointer</dt>
	 *  <dd>The resulting image is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate(CATPixelImageFormat iFormat) const;

	/**
	 * Changes the image format.
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
	 * Inverts the line progression (flips the image).
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 * </dl>
	 */
	virtual int InvertLineProgression();

	/**
	 * Redefines an image.
	 * <br>In some cases the assignment operator may be used in place of this method.
	 * The pixel data is not duplicated ; because of this, pixel data should not be
	 * deallocated before any <tt>CATPixelImage</tt> referencing this data has disappeared.
	 * This is also true for any image copied from this image.
	 * @param iXSize
	 *   The width of the image in pixels.
	 * @param iYSize
	 *   The height of the image pixels.
	 * @param iFormat
	 *   The format of the data stored in the pixel array.
	 * @param iPixels
	 *   The pixel data.
	 * @param iToDelete
	 *   Whether the given pixel array has to be deleted when the <tt>CATPixelImage</tt> is destroyed, and how (free() or delete[]).
	 *   The default value for this parameter is <tt>PixelDeallocateNO</tt>, which implies the pixel data is not deleted when the image is destroyed.
	 *   It is the user to delete the pixel data.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 * </dl>
	 */
	virtual int Modify(int iXSize, int iYSize, CATPixelImageFormat iFormat, unsigned char* iPixels, CATDeallocatePixels iToDelete = PixDeallocateNO);

	/**
	 * Creates a new <tt>CATPixelImage</tt> from a region of the image.
	 * @param iXMin
	 *   The X left coordinate of the region.
	 * @param iXMax
	 *   The X right coordinate of the region.
	 * @param iYMin
	 *   The Y lower coordinate of the region.
	 * @param iYMax
	 *   The Y upper coordinate of the region.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATPixelImage</tt>.</dt>
	 * </dl>
	 */
	virtual CATPixelImage* CreateSubImage(int iXMin, int iYMin, int iXMax, int iYMax) const;

	/**
	 * Inserts a <tt>CATPixelImage</tt> inside the image.
	 * <br>Images must be of same type. The input image is clipped if it is larger than the original image.
	 * @param iX
	 *   The X coordinate of the insertion point.
	 * @param iY
	 *   The Y coordinate of the insertion point.
	 * @param iPixelImage
	 *   The <tt>CATPixelImage</tt> to insert.
	 * @param iTransparency
	 *   If not null, the color of the first pixel of <tt>iPixelImage<tt> is taken as transparent
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd><tt>iPixelImage</tt> is not a valid image.</dd>
	 *  <dt>2</dt>
	 *  <dd><tt>iPixelImage</tt> cannot be copied on itself.</dd>
	 *  <dt>10</dt>
	 *  <dd>Image is <tt>ReadOnly</tt> or formats are different.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual int InsertPixelImage(int iX, int iY, const CATPixelImage* iPixelImage, int iTransparency = 0);

	/**
	 * Creates a zoomed image from an existing image.
	 * <br>The size in mm of the image is also zoomed (that is the size in mm of each pixel is not changed).
	 * @param iXSize
	 *   The width of the new image in pixels.
	 * @param iYSize
	 *   The height of the new image in pixels.
	 * @param iZoomQuality
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>1</dt>
	 *  <dd>Pixel replication only (fast, poor quality).</dd>
	 *  <dt>2</dt>
	 *  <dd>if <tt>iZoomFactor < 1</tt> : linear interpolation, replication if <tt>> 1</tt>.</dd>
	 *  <dt>3</dt>
	 *  <dd>Linear interpolation in all cases (slow, good quality).</dd>
	 * </dl>
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATPixelImage</tt>.</dt>
	 * </dl>
	 */
	virtual CATPixelImage* CreateZoomedImage(int iXSize, int iYSize, int iZoomQuality = 1) const;

	/**
	 * Creates a zoomed image from an existing image.
	 * <br>The size in mm of the image is also zoomed (that is the size in mm of each pixel is not changed).
	 * @param iZoomFactor
	 *   The zoom factor.
	 * @param iZoomQuality
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>1</dt>
	 *  <dd>Pixel replication only (fast, poor quality).</dd>
	 *  <dt>2</dt>
	 *  <dd>if <tt>iZoomFactor < 1</tt> : linear interpolation, replication if <tt>> 1</tt>.</dd>
	 *  <dt>3</dt>
	 *  <dd>Linear interpolation in all cases (slow, good quality).</dd>
	 * </dl>
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATPixelImage</tt>.</dt>
	 * </dl>
	 */
	virtual CATPixelImage* CreateZoomedImage(float iZoomFactor, int iZoomQuality = 1) const;

	/**
	 * Creates a rotated image from an existing image.
	 * @param iAngleInDegrees
	 *   Legal values are 90, 180, 270.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATPixelImage</tt>.</dt>
	 * </dl>
	 */
	virtual CATPixelImage* CreateRotatedImage(int iAngleInDegrees) const;

	/**
	 * Sets the size in mm of one pixel in X direction.
	 * @param iXPixelSize
	 *   The new X pixel size.
	 */
	 virtual void SetXPixelSize(float iXPixelSize) { _xPixelSize = iXPixelSize; }

	/**
	 * Sets the size in mm of one pixel in Y direction.
	 * @param iYPixelSize
	 *   The new Y pixel size.
	 */
	virtual void SetYPixelSize(float iYPixelSize) { _yPixelSize = iYPixelSize; }

	virtual ~CATPixelImage();

  /**
   * @deprecated R422 use WriteToFileEx
	 * Writes an image to a file.
	 * @param iFileFormat
	 *   The output file format.
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>"TIFF"</dt>
	 *  <dd>True color uncompressed TIFF file.</dd>
	 *  <dt>"TIFFTCPB"</dt>
	 *  <dd>True color PackBits compressed TIFF file.</dd>
	 *  <dt>"TIFFINDEX"</dt>
	 *  <dd>Indexed (256 colors) uncompressed TIFF file.</dd>
	 *  <dt>"TIFFPB"</dt>
	 *  <dd>Indexed (256 colors) PackBits compressed TIFF file.</dd>
	 *  <dt>"TIFFGREY"</dt>
	 *  <dd>Grey scale PackBits compressed TIFF file.</dd>
	 *  <dt>"TIFFBWPB"</dt>
	 *  <dd>Bilevel (black and white) PackBits compressed TIFF file.</dd>
	 *  <dt>"RGB"</dt>
	 *  <dd>RGB file (SGI format).</dd>
	 *  <dt>"HPRTL"</dt>
	 *  <dd>HP/RTL - 300 dpi.</dd>
	 *  <dt>"BMP"</dt>
	 *  <dd>Windows Bitmap.</dd>
	 *  <dt>"JPEG_FAIR"</dt>
	 *  <dd>JPEG, fair quality.</dd>
	 *  <dt>"JPEG"</dt>
	 *  <dd>JPEG, medium quality.</dd>
	 *  <dt>"JPEG_HIGH"</dt>
	 *  <dd>JPEG, high quality.</dd>
	 *  <dt>"PNG"</dt>
	 *  <dd>Portable Network Graphics.</dd>
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
   * @deprecated R422 use GetNumberOfPagesEx
	 * Returns the number of pages for a multipage file.
   */
  static int GetNumberOfPages(const CATString& iPathName);

  /**
   * @deprecated R422 use IsValidBitmapFileEx
	 * Says whether the given file is a valid bitmap file or not.
   */
  static int IsValidBitmapFile(const CATString& iPathName);

  /**
   * @deprecated R422 use CreateFromFileEx
	 * Creates an image from a file.
	 * @param iPathName
	 *   The file to create the image from.
	 *   <br>Recognized formats are : TIFF, BMP, JPEG, PNG, RGB, PICTURE.
	 * @param iRState
	 *   The <tt>ReadOnly</tt> state of the new image.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATPixelImage</tt>.</dt>
	 * </dl>
   */
  static CATPixelImage* CreateFromFile(const CATString& iPathName, CATReadOnlyState iRState = NotReadOnly, int iPageNumber = 0);

  /**
   * @deprecated R422 use CreateFromFileEx
	 * Creates an image from a file given an explicit file format.
	 * @param iFileFormat
	 *   The format of the file to create the image from ; valid values are :
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>"TIFF"</dt>
	 *  <dt>"RGB"</dt>
	 *  <dt>"JPEG"</dt>
	 *  <dt>"BMP"</dt>
	 *  <dt>"PNG"</dt>
	 *  <dt>"PICTURE"</dt>
	 * </dl>
	 * @param iPathName
	 *   The file to create the image from.
	 * @param iRState
	 *   The <tt>ReadOnly</tt> state of the new image.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATPixelImage</tt>.</dt>
	 * </dl>
   */
  static CATPixelImage* CreateFromFile(const CATString& iFileFormat, const CATString& iPathName, CATReadOnlyState iRState = NotReadOnly, int iPageNumber = 0);

#ifdef _WINDOWS_SOURCE
	/**
	 * Creates a HBITMAP from a <tt>CATPixelImage</tt> (MS-Windows only).
	 * <br>The image must be in RGB format.
	 */
	HBITMAP GetHBITMAP();
#endif

	/**
	 * Get the list of the supported file formats.
	 * @param
	 * <dl>
	 *  <dt>A <tt>CATListValCATString</tt>s giving the supported file formats.</dt>
	 * </dl>
	 */
	static void  GetFileFormatList(CATListValCATString&);

	/**
	 * Get the list of the supported file formats extensions.
	 * @param
	 * <dl>
	 *  <dt>A <tt>CATListValCATString</tt>s giving the file formats extensions.</dt>
	 * </dl>
	 */
	static void GetFileExtensionList(CATListValCATString&);

	/**
	 * Get a list of the supported file formats comments.
	 * @param
	 * <dl>
	 *  <dt>A <tt>CATListValCATString</tt>s giving the file formats comments.</dt>
	 * </dl>
	 */
	static void GetFileCommentList(CATListValCATString&);

	/**
	 * Get a list of the supported file formats Read and Write properties.
	 * @param
	 * <dl>
	 *  <dt>A <tt>CATListValCATString</tt>s giving the file formats Read and Write properties.</dt>
	 * </dl>
	 */
	static void GetFileRWList(CATListValCATString& );

	/**
	 * Get a list of the supported file formats options.
	 * @param
	 * <dl>
	 *  <dt>A <tt>CATListValCATString</tt>s giving the file formats options.</dt>
	 * </dl>
	 */
	static void GetFileOptionsList(CATListValCATString&);

	/**
	 * Retrieves the properties of a given file format.
	 * @param iFileFormat
	 *   The requested file format (see @href #CreateFromFile, @href #WriteToFile ).
	 * @param iReadOrWrite
	 *   The Read or Write properties of the file format.
	 * @param oExtensions
	 *   The extension string associated with this file format.
	 * @param oCommand
	 *   The command string associated with this file format.
	 * @param oOptions
	 *   The options string associated with this file format.
	 * @param oComment
	 *   The comment string associated with this file format.
	 */
	virtual void GetFileFormatProperties(const CATString& iFileFormat, const CATString& iReadOrWrite,
										 CATString** oExtension, CATString** oCommand,
										 CATString** oOptions, CATString** oComment);

	/**
	 * Retrieves the color of a pixel.
	 * <br>If format is <tt>L</tt>, only <tt>oRL</tt> is evaluated (<tt>oRL</tt> and <tt>oA</tt> for <tt>LA</tt> format)
	 * @param iX
	 *   The X coordinate of the pixel.
	 * @param iY
	 *   The Y coordinate of the pixel.
	 * @param oRL
	 *   The Red or Luminance value of the pixel.
	 * @param oG
	 *   The Green value of the pixel.
	 * @param oB
	 *   The Blue value of the pixel.
	 * @param oA
	 *   The Alpha value of the pixel.
	 * @return
	 * <dl>
	 *  <dt>The format of the picture.</dt>
	 * </dl>
	 */
	virtual CATPixelImageFormat GetColorAtPixel(unsigned int iX, unsigned int iY,
											 unsigned int* oRL,
											 unsigned int* oG, unsigned int* oB,
											 unsigned int* oA);

	/**
	 * Returns an array of the most frequent colors.
	 * <br>The image must be in <tt>RGB</tt> format.
	 * @param oColorArray
	 *   The array of found colors. The array must be allocated before you call this method : <tt>oColorArray = new unsigned char[iNbBgColor*3]</tt>.
	 * @param iNbBgColor
	 *   The number of colors to look for. Must be <= 4.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>-1</dt>
	 *  <dd>Invalid format.</dd>
	 *  <dt>-2</dt>
	 *  <dd>Invalid image.</dd>
	 *  <dt>-3</dt>
	 *  <dd>Invalid <tt>iNbBgColor</tt> parameter.</dd>
	 * </dl>
	 * @see CATPixelImageFormat
	 */
	virtual int GetBgColor(unsigned char* oColorArray, unsigned int iNbBgColor);

	/**
	 * Changes a specific color in the whole image.
	 * @param iR1
	 *   The old Red value.
	 * @param iG1
	 *   The old Green value.
	 * @param iB1
	 *   The old Blue value.
	 * @param iR2
	 *   The new Red value.
	 * @param iG2
	 *   The new Green value.
	 * @param iB2
	 *   The new Blue value.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Image is <tt>ReadOnly</tt>.</dd>
	 *  <dt>2</dt>
	 *  <dd>Bad format.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual int ModifyColor(unsigned char iR1, unsigned char iG1, unsigned char iB1,
							unsigned char iR2, unsigned char iG2, unsigned char iB2);

	/**
	 * Looks for the most frequent colors and replaces them.
	 * <br>The image must be in <tt>RGB</tt> format.
	 * @param iNbBgColor
	 *   The number of colors to look for. Must be <= 4.
	 * @param iR
	 *   The new Red component.
	 * @param iG
	 *   The new Green component.
	 * @param iB
	 *   The new Blue component.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Image is <tt>ReadOnly</tt>.</dd>
	 *  <dt>2</dt>
	 *  <dd>Invalid format.</dd>
	 *  <dt>3</dt>
	 *  <dd>Invalid <tt>iNbBgColor</tt> parameter.</dd>
	 * </dl>
	 * @see CATReadOnlyState, CATPixelImageFormat
	 */
	virtual int ModifyBgColor(unsigned int iNbBgColor, unsigned char iR, unsigned char iG, unsigned char iB);

	/**
	 * Modifies a RGBA picture by setting every pixel which has the same color than the upper left one to a new alpha value.
	 * @param iAlpha
	 *   The new alpha value. <tt>iAlpha = 0</tt> means transparent, <tt>iAlpha = 255</tt> means opaque.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Failure.</dd>
	 *  <dt>2</dt>
	 *  <dd>Image is <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	int SetTransparency(unsigned char iAlpha = 0);

	/**
	 * Replaces every pixel whose alpha component is smaller than 128 by a new color.
	 * @param iR
	 *   The new Red component.
	 * @param iG
	 *   The new Green component.
	 * @param iB
	 *   The new Blue component.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Failure.</dd>
	 *  <dt>2</dt>
	 *  <dd>Image is <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	int ChangeTransparencyToColor(unsigned char iR, unsigned char iG, unsigned char iB);

	/**
	 * Replaces the <tt>A</tt> (alpha) component by <tt>255-A</tt>.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Failure.</dd>
	 * </dl>
	 */
	virtual int InvertTransparency();

	/**
	 * Rebuilds the I/O image formats list.
	 */
	virtual void UpdateAllList();

	/**
	 * Returns the latest error.
	 * @return
	 * <dl>
	 *  <dt>Returns the last available error message.</dt>
	 * </dl>
	 */
	static const CATUnicodeString* GetLastError();

	/**
	 * Informs of an image modification.
	 * <b>Role</b>: This method is not defined on a <tt>CATPixelImage</tt>.
	 * <br>For a @href CATTexturePixelImage, a flag is set to indicate that
	 * a pixel in the data zone is modified so that the image is regenerated at the next draw.
	 * This method is used in all the methods of <tt>CATPixelImage</tt> wich modify
	 * the pixel data.
	 */
	virtual void SetImagePixelsModification() {} // redefined in CATTexturePixelImage

	/**
	 * Sharpens the image applying a highpass filter.
	 * @param iAmount
	 *   The sharpening amount.<br>
	 *   <tt>0 < iAmount <= 200</tt> gives good results.
	 *   <tt>iAmount = 50</tt> is a good value
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Invalid image.</dd>
	 *  <dt>2</dt>
	 *  <dd>Image is <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual int Sharpen(int iAmount);

	/**
	 * Grey levels to Black and White conversion using Floyd-Steinberg algorithm.
	 * <br>Pixel format must be <tt>L</tt> and remains <tt>L</tt>.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Invalid image.</dd>
	 *  <dt>2</dt>
	 *  <dd>Image is <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual int Dither();

	/**
	 * @nodoc
	 */
	int InsertPixelImage(int iX, int iY, const CATPixelImage& iImage, uchar iLR, uchar iG, uchar iB);

	/**
	 * @nodoc
	 */
	void Clear(uchar iClearR, uchar iClearG, uchar iClearB,
			   uchar iKeepR,  uchar iKeepG,  uchar iKeepB);

	/**
	 * Sets the line progression for DXTn compressed pixel image.
	 * Be careful, if the line progression is normalised and if the image height is not a multiple of 4,
	 * top lines will be removed to get the right image height.
	 * Otherwise, the bottom lines will be removed.
	 * @param iLineProgression
	 *   The line progression of pixel image with DXTn CATPixelImageFormat.
	 */
	 virtual void SetDXTnLineProgression(CATLineProgression iLineProgression) { if (iLineProgression == Normalised) _normalisedDXTnLineProgression = TRUE; else _normalisedDXTnLineProgression = FALSE;}

	/**
	 * Gets the line progression for DXTn compressed pixel image.
	 * Be careful, if the line progression is normalised and if the image height is not a multiple of 4,
	 * top lines will be removed to get the right image height.
	 * Otherwise, the bottom lines will be removed.
	 * @param oLineProgression
	 *   The line progression of pixel image with DXTn CATPixelImageFormat.
	 */
	 virtual CATLineProgression GetDXTnLineProgression() const { if (_normalisedDXTnLineProgression == TRUE) return Normalised; else return Inverted;}

	/**
	 * Changes the image format to BILEVEL using DITHER_MODE algorithm.
	 * @param iMode
	 *   The dither algorithm (FloydSteinberg or AverageTheshold).
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 * </dl>
	 */
	virtual int ChangeFormatBilevel(DITHER_MODE mode= DITHER_FloydSteinberg);

	/**
	 * Grey levels to Black and White conversion using average threshold algorithm.
	 * <br>Pixel format must be <tt>L</tt> and remains <tt>L</tt>.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>0</dt>
	 *  <dd>Success.</dd>
	 *  <dt>1</dt>
	 *  <dd>Invalid image.</dd>
	 *  <dt>2</dt>
	 *  <dd>Image is <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual int DitherAverageThreshold();

	/** @nodoc
	 * Gets the struct CATMMPISpec _spec.
	 *
	 */
	virtual CATMMPISpec* getSpec();
	
	/** @nodoc
	 * Apply a color profile to the CATPixelImage Specifications as the input color profile.
	 * Apply a transform between the current color profile and the input color profile.
	 * <br> NULL is to generate a working color space to use (sRGB), hence the CATPixelImage become Device independant.
	 */
	virtual void ApplyColorProfile(CATMMColorProfile* iColorProfile=NULL, int intentType=0);


	/** @nodoc
	 * Assign a color profile to the CATPixelImage Specifications as the input color profile.
	 * <br> NULL is to generate a working color space to use (sRGB), hence the CATPixelImage become Device independant.
	 */
	virtual void AssignColorProfile(CATMMColorProfile* iColorProfile=NULL, int intentType=0);

	/** @nodoc
	 * Assign EXIF Metadata to the CATPixelImage Specifications as the input EXIF Metadata.
	 *
	 */
	virtual void SetMetadata(CATMMImageMetadata *exifData);

	/** @nodoc */
	virtual CATMMImageMetadata* GetMetadata();

	/** @nodoc */
	virtual CATMMColorProfile* GetColorProfile() const;

  /**
  * Writes an image to a file.
  * @param iFileFormat
  *   The output file format.
  * <br><b>Legal values</b>
  * <dl>
  *  <dt>"TIFF"</dt>
  *  <dd>True color uncompressed TIFF file.</dd>
  *  <dt>"TIFFTCPB"</dt>
  *  <dd>True color PackBits compressed TIFF file.</dd>
  *  <dt>"TIFFINDEX"</dt>
  *  <dd>Indexed (256 colors) uncompressed TIFF file.</dd>
  *  <dt>"TIFFPB"</dt>
  *  <dd>Indexed (256 colors) PackBits compressed TIFF file.</dd>
  *  <dt>"TIFFGREY"</dt>
  *  <dd>Grey scale PackBits compressed TIFF file.</dd>
  *  <dt>"TIFFBWPB"</dt>
  *  <dd>Bilevel (black and white) PackBits compressed TIFF file.</dd>
  *  <dt>"RGB"</dt>
  *  <dd>RGB file (SGI format).</dd>
  *  <dt>"HPRTL"</dt>
  *  <dd>HP/RTL - 300 dpi.</dd>
  *  <dt>"BMP"</dt>
  *  <dd>Windows Bitmap.</dd>
  *  <dt>"JPEG_FAIR"</dt>
  *  <dd>JPEG, fair quality.</dd>
  *  <dt>"JPEG"</dt>
  *  <dd>JPEG, medium quality.</dd>
  *  <dt>"JPEG_HIGH"</dt>
  *  <dd>JPEG, high quality.</dd>
  *  <dt>"PNG"</dt>
  *  <dd>Portable Network Graphics.</dd>
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
  virtual int WriteToFileEx(const CATString& iFileFormat, const CATUnicodeString& iPathName) const;

  /**
  * Returns the number of pages for a multipage file.
  */
  static int GetNumberOfPagesEx(const CATUnicodeString& iPathName);

  /**
  * Says whether the given file is a valid bitmap file or not.
  */
  static int IsValidBitmapFileEx(const CATUnicodeString& iPathName);

  /**
  * Creates an image from a file.
  * @param iPathName
  *   The file to create the image from.
  *   <br>Recognized formats are : TIFF, BMP, JPEG, PNG, RGB, PICTURE.
  * @param iRState
  *   The <tt>ReadOnly</tt> state of the new image.
  * @return
  * <dl>
  *  <dt>A new <tt>CATPixelImage</tt>.</dt>
  * </dl>
  */
  static CATPixelImage* CreateFromFileEx(const CATUnicodeString& iPathName, CATReadOnlyState iRState = NotReadOnly, int iPageNumber = 0);

  /**
  * Creates an image from a file given an explicit file format.
  * @param iFileFormat
  *   The format of the file to create the image from ; valid values are :
  * <br><b>Legal values</b>
  * <dl>
  *  <dt>"TIFF"</dt>
  *  <dt>"RGB"</dt>
  *  <dt>"JPEG"</dt>
  *  <dt>"BMP"</dt>
  *  <dt>"PNG"</dt>
  *  <dt>"PICTURE"</dt>
  * </dl>
  * @param iPathName
  *   The file to create the image from.
  * @param iRState
  *   The <tt>ReadOnly</tt> state of the new image.
  * @return
  * <dl>
  *  <dt>A new <tt>CATPixelImage</tt>.</dt>
  * </dl>
  */
  static CATPixelImage* CreateFromFileEx(const CATString& iFileFormat, const CATUnicodeString& iPathName, CATReadOnlyState iRState = NotReadOnly, int iPageNumber = 0);

	 ///////////////////////////////////////////////////////////////////////////
private:
	CATPixelImage(const CATPixelImageFormat iFormat, const CATPixelImageFormat iPixelsFormat,
	              const int iXSize, const int iYSize, const uchar * const ipPixels);
	CATBoolean IsValid() const;
	CATBoolean UsingBaseFormat() const;
	CATBoolean UsingFloatFormat() const;
	void InitAsInvalid();
	void ChangeRGB_fToRGB();
	CATPixelImage * DiscardInvalid(CATPixelImage *& iopPixelImage) const;
	CATBoolean CreateBiLevelBuffers(const int iySize);
	CATBoolean CreateBiLevelBuffers(const int iySize, const int * const ipRunsLength, const uchar * const * const ipRuns);
	CATBoolean CreateBiLevelBuffers(const int ixSize, const int iySize, const uchar * const ipPixels, const CATBoolean iGray=FALSE);
	CATBoolean CreateBitmapBuffer(const int ixSize, const int iySize);
	CATBoolean CreateBitmapBuffer(const int ixSize, const int iySize, const uchar * const ipPixels);
	CATBoolean CreateBitmapBuffer(const int ixSize, const int iySize, const float* const ifPixels);
	CATBoolean AssignBitmapBuffer(const int ixSize, const int iySize, uchar * const ipPixels, const DeallocatePixels iToDelete=PixDeallocateYESdelete);
	CATBoolean AssignBitmapBuffer(const int ixSize, const int iySize, float* const ifPixels, const DeallocatePixels iToDelete = PixDeallocateYESdelete);
	void SafeDone();
	void SafeDonePrimary();
	void SafeDoneBitmap();
	void SafeDoneBiLevel();
	void SafeDoneSecondary();

	int FlipBitmap();
	int FlipBiLevel();
	int FlipFloatImage();
	

	CATPixelImage * ZoomBILEVEL(const int ixSize, const int iySize, const int iZoomQuality) const;
	CATPixelImage * ZoomQuality1(const int ixSize, const int iySize) const;
	CATPixelImage * ZoomQuality2(const int ixSize, const int iySize) const;
	CATPixelImage * ZoomQuality3(const int ixSize, const int iySize) const;
	unsigned char * CreateBitmap(const CATPixelImageFormat iFormat) const;
	unsigned char * CreateDXTnCompression(const PixelImageFormat iFormat) const;

	// ------------------------------------------------------------------------

	int                             _xSize;
	int                             _ySize;
	CATPixelImageFormat             _format;

	// L, LA, RGB, RGBA bitmaps
	int                             _pixelsLength; // can be removed
	uchar                           *_pixels;

	// BILEVEL bitmaps
	int                             *_runsLength;
	uchar                           **_runs;

	// RBG and RGBA float
	float                           *_fpixels;

	CATReadOnlyState                _readOnlyState;
	CATDeallocatePixels             _deallocate;

	// Size in mm of one pixel for x and y directions
	float                           _xPixelSize;
	float                           _yPixelSize;

	// Duplicated image in another Format, Temporary and Read Only.
	// Usefull for performance optimization.
	CATPixelImage                   *_secondaryPixelImage;
	CATLineProgression              _secondaryLineProgression;
	CATSecondaryPixelImageFormat    _secondaryFormat;

	// StatClean just call delete StatPixelFormat in his destructor
	static CATStatCleaner           StatClean;

	CATBoolean                      _normalisedDXTnLineProgression;
	
	// Specifications of the CATPixelImage
	CATMMPISpec* _spec;
  lCATPixelImage                *_pPIInternals;
};

#endif // CATPixelImage_H
