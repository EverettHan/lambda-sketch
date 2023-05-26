//===================================================================
// COPYRIGHT Dassault Systemes 2014-06-05
//===================================================================
// 2014-06-05 Creation: D6K
//===================================================================

#ifndef CATIVectorImageRender_H
#define CATIVectorImageRender_H

// Local
#include "MultimediaItf.h"
#include "CATMM2DTypes.h"
// System
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATPixelImage;

extern ExportedByMultimediaItf IID IID_CATIVectorImageRender;

/**
 * 2D render interface for vector images.
 * Usage:
 * - Build a 2D model with one of these Build methods.
 * - Set your preferences (size, margins, etc.).
 * - Rasterize the model (the last built/used model is supposed to be stored in the component).
 */
class ExportedByMultimediaItf CATIVectorImageRender : public CATBaseUnknown
{
	CATDeclareInterface;

public:
	/**
	 * Builds a 2D model object from the file containing the vector image.
	 * @param i_filePath
	 *   Absolute path to the vector image file.
	 * @param i_type
	 *   Vector file type identifier.
	 * @param o_pModel
	 *   2D model built from the vector image.
	 */
	virtual HRESULT BuildModelFromFile(const CATUnicodeString&   i_filePath,
	                                   const CATMM2D::VectorType i_type,
	                                   CATBaseUnknown*&          o_pModel) = 0;
	/**
	 * Builds a 2D model object from the buffer containing the vector image.
	 * @param i_pBuffer
	 *   Data buffer containing the vector image description.
	 * @param i_bufferLength
	 *   Data buffer size (in bytes).
	 * @param i_type
	 *   Vector file type identifier.
	 * @param o_pModel
	 *   2D model built from the vector image.
	 */
	virtual HRESULT BuildModelFromBuffer(const unsigned char* const i_pBuffer,
	                                     const size_t               i_bufferLength,
	                                     const CATMM2D::VectorType  i_type,
	                                     CATBaseUnknown*&           o_pModel) = 0;
	/**
	 * Generates a raster image from the last built or used 2D model.
	 * @param o_pImage
	 *   Model raster image.
	 */
	virtual HRESULT Rasterize(CATPixelImage*& o_pImage) = 0;
	/**
	 * Generates a raster image from the provided 2D model.
	 * @param i_pModel
	 *   Model to rasterize.
	 * @param o_pImage
	 *   Model raster image.
	 */
	virtual HRESULT RasterizeModel(CATBaseUnknown* i_pModel,
	                               CATPixelImage*& o_pImage) = 0;
	/**
	 * Changes the size of the target image.
	 * @param i_size
	 *   New image dimensions (in pixels).
	 */
	virtual HRESULT SetSize(const CATMM2D::Size<int>& i_size) = 0;
	/**
	 * Returns the current size of the target image.
	 * @param o_size
	 *   Current image dimensions (in pixels);
	 */
	virtual HRESULT GetSize(CATMM2D::Size<int>& o_size) = 0;
	/**
	 * Changes the length of the target image margins.
	 * @param i_margins
	 *   New image margins (in pixels).
	 */
	virtual HRESULT SetMargins(const CATMM2D::Margins<int>& i_margins) = 0;
	/**
	 * Returns the current margins of the target image.
	 * @param o_margins
	 *   Current image margins (in pixels).
	 */
	virtual HRESULT GetMargins(CATMM2D::Margins<int>& o_margins) = 0;
	/**
	 * Defines scale parameter for stroke width.
	 * @param i_scalable
	 *   Set to true: scale is applied on stroke width.
	 *   Set to false: scale is applied everywhere but on stroke width.
	 */
	virtual HRESULT SetScalableStrokeWidth(const bool i_scalable) = 0;
	/**
	 * Changes the scale that will be used with the image initial size
	 * to compute the output resolution in pixels.
	 * @param i_scale
	 *   New scale, to multiply with the base dimensions.
	 * @note
	 *   Only use this method once the model is built, to read its size.
	 * @warning
	 *   If the vector image doesn't have an explicit size,
	 *   results are not guaranteed.
	 */
	virtual HRESULT SetScale(const double i_scale) = 0;
};

CATDeclareHandler(CATIVectorImageRender, CATBaseUnknown);

#endif
