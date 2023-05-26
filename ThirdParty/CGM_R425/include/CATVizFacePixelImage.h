#ifndef CATVIZFACEPIXELIMAGE_H
#define CATVIZFACEPIXELIMAGE_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// Class  :  	CATVizFacePixelImage
// Date   :  	15/11/05
//-----------------------------------------------------------------------------
//  Inheritance : CATVizFacePixelImage
//					CATPixelImage
//						CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies a face.
//            A face is used as a texture with a cubic orientation.
//-----------------------------------------------------------------------------
//  Main Methods :
//
// GetOrientation
//-----------------------------------------------------------------------------

// Local Framework
#include "CATPixelImage.h"
#include "CATVisTextureObjects.h"
///
#include "CATStreamer.h"
///

enum CATViz_CubeMap
{
	CATViz_CubeMap_PositiveX,
	CATViz_CubeMap_NegativeX,
	CATViz_CubeMap_PositiveY,
	CATViz_CubeMap_NegativeY,
	CATViz_CubeMap_PositiveZ,
	CATViz_CubeMap_NegativeZ
};


class ExportedByCATVisTextureObjects CATVizFacePixelImage : public CATPixelImage
{
	CATDeclareClass;

public:

	/** Contructs a blank face of given size.
	 * @param iWidth
	 * Width of the face.
	 * @param iHeight
	 * Height of the face.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 */
	CATVizFacePixelImage(const int iWidth,
						 const int iHeight, CATViz_CubeMap iCubeMapOrientation,
						 const PixelImageFormat iPixelDataFormat);

	/** Contructs a blank face of given size.
	 * @param iWidth
	 * Width of the face.
	 * @param iHeight
	 * Height of the face.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 * @param iPixelData
	 * Data of the face.
	 */
	CATVizFacePixelImage(const int iWidth,
						 const int iHeight, CATViz_CubeMap iCubeMapOrientation,
						 const PixelImageFormat iPixelDataFormat,
						 unsigned char* iPixelData,
						 CATDeallocatePixels iToDelete = PixDeallocateNO);

	/** Copy constructor */
	CATVizFacePixelImage(const CATPixelImage& iPixelImage);

	/** Copy constructor */
	CATVizFacePixelImage(const CATVizFacePixelImage& iFace);

	/**
	 * Duplicates a face.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizFacePixelImage</tt> pointer</dt>
	 * </dl>
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates a face and changes the format of the resulting face.
	* @param iFormat
	*   The new format.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizFacePixelImage</tt> pointer</dt>
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


	/** Get the face orientation.
	 * @return
	 * The face orientation.
	*/
	const CATViz_CubeMap& GetOrientation() const {return _cubicOrientation;}

	/** Set the face orientation.
	 * @param iCubicOrientation
	 * The face orientation.
	*/
	void SetOrientation(CATViz_CubeMap iCubicOrientation) {_cubicOrientation = iCubicOrientation;}

protected:

	/** @nodoc */
	virtual ~CATVizFacePixelImage();

private:

	CATViz_CubeMap _cubicOrientation;
};

#endif
