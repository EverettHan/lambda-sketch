#ifndef CATVIZCUBICENVMAP_H
#define CATVIZCUBICENVMAP_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// Class  :  	CATVizCubicEnvMap
// Date   :  	15/11/05
//-----------------------------------------------------------------------------
//  Inheritance : CATVizCubicEnvMap
//					CATTexturePixelImage
//						CATPixelImage
//							CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies a cubic environment map used as texture.
//            One or more faces of a cube can be defined. All the faces should 
//            be the same size and the same format. The face orientation is defined 
//            by CATViz_CubeMap parameter.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	manage the faces
//		GetFaceCount
//		GetFace
//		GetFaceList
//		AddFace
//-----------------------------------------------------------------------------

// Local Framework
#include "CATTexturePixelImage.h"
#include "CATVisTextureObjects.h"
#include "CATVizFacePixelImage.h"
#include "CATListOfCATVizFacePixelImage.h"
// VisualizationBase Framework
class CATStreamer;


class ExportedByCATVisTextureObjects CATVizCubicEnvMap : public CATTexturePixelImage
{
	CATDeclareClass;

public:

	/** Contructs a blank cubic environment map of given size.
	 * @param iWidth
	 * Width of the faces used as texture.
	 * @param iHeight
	 * Height of the faces used as texture.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 */
	CATVizCubicEnvMap(const int iWidth, 
					  const int iHeight,
					  const PixelImageFormat iPixelDataFormat);

	/** Copy constructor */
	CATVizCubicEnvMap(const CATVizCubicEnvMap& iCubicEnvMap);

	/**
	 * Duplicates a cubic environment map.
	 * <br>This allows to modify a <tt>ReadOnly</tt> cubic environment map.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizCubicEnvMap</tt> pointer</dt>
	 *  <dd>The resulting cubic environment map is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates a cubic environment map and changes the format of the resulting cubic environment map.
	 * <br>This allows to modify a <tt>ReadOnly</tt> cubic environment map.
	 * @param iFormat
	 *   The new format.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizCubicEnvMap</tt> pointer</dt>
	 *  <dd>The resulting cubic environment map is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate(CATPixelImageFormat iFormat) const;

	/** Deletes the cubic environment map. */
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
	 * Retrieves the cubic environment map main face size in pixels.
	 * @param oXSize
	 *   Image width in pixels.
	 * @param oYSize
	 *   Image height in pixels.
	 */
	virtual void GetSize(int& oXSize, int& oYSize) const { oXSize = _facePixelWidth, oYSize = _facePixelHeight; }

	/**
	 * Retrieves the cubic environment map face format.
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
	virtual CATPixelImageFormat GetFormat() const { return _faceFormat; }

	/**
	 * Changes the cubic environment map format.
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
	 * Get the number of faces defining the cubic map.
	 * @return
	 * <dl>
	 *  <dt>the number of mipmaps in the texture.</dt>
	 * </dl>
	 */
	unsigned int GetFaceCount(void);

	/**
	 * Get the face with the CATViz_CubeMap orientation.
	 * @param iFaceOrientation
	 *   The orientation of the face.
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>CATViz_CubeMap_PositiveX</dt>
	 *  <dd>positive X orientation.</dd>
	 *  <dt>CATViz_CubeMap_NegativeX</dt>
	 *  <dd>negative X orientation.</dd>
	 *  <dt>CATViz_CubeMap_PositiveY</dt>
	 *  <dd>positive Y orientation.</dd>
	 *  <dt>CATViz_CubeMap_NegativeY</dt>
	 *  <dd>negative Y orientation.</dd>
	 *  <dt>CATViz_CubeMap_PositiveZ</dt>
	 *  <dd>positive Z orientation.</dd>
	 *  <dt>CATViz_CubeMap_NegativeZ</dt>
	 *  <dd>negative Z orientation.</dd>
	 *  <dd>Invalid format.</dd>
	 * </dl>
	 * @return
	 * <dl>
	 *  <dt>The face <tt>CATVizFacePixelImage</tt>.</dt>
	 * </dl>
	 */
	CATVizFacePixelImage* GetFace(CATViz_CubeMap iFaceOrientation);

	/**
	 * Get the face list defining the cubic environment map.
	 * @return
	 * <dl>
	 *  <dt>The face list <tt>CATListOfCATVizFacePixelImage</tt>.</dt>
	 * </dl>
	 */
	CATLISTP(CATVizFacePixelImage)* GetFaceList();

	/**
	 * Add a face to the cubic environment map.
	 * @param iFace
	 * The face to add. If a face with the same orientation 
	 * is already defined for the map, the new one replace it.
	 */
	void AddFace(CATVizFacePixelImage* iFace);

        /** @nodoc */
        virtual CATTexturePixelImageType GetTextureType();

protected:

	/** @nodoc */
	virtual ~CATVizCubicEnvMap();

protected:

	/** @nodoc */
	CATLISTP(CATVizFacePixelImage)* _paFaceList;

	// size of all the main faces
	unsigned int _facePixelWidth;
	unsigned int _facePixelHeight;

	// format of all the faces
	CATPixelImageFormat _faceFormat;
};

#endif



