#ifndef CATVIZCUBICENVMAPWITHMIPMAP_H
#define CATVIZCUBICENVMAPWITHMIPMAP_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// Class  :  	CATVizCubicEnvMapWithMipMap
// Date   :  	15/11/05
//-----------------------------------------------------------------------------
//  Inheritance : CATVizCubicEnvMapWithMipMap
//					CATVizCubicEnvMap
//						CATTexturePixelImage
//							CATPixelImage
//								CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies a cubic environment map used as texture.
//            The faces are defined with different level of detail, so they contain
//            several mipmaps.
//            One or more faces of a cube can be defined. All the faces should 
//            be the same size, the same format and the have the same mimap count.
//            The face orientation is defined by CATViz_CubeMap parameter.
//            The mipmap size should be divided by 2 for each level.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	manage the faces
//		GetMipMapCount
//		GetFaceCount
//		GetFace
//		GetFaceList
//		AddFace
//-----------------------------------------------------------------------------

// Local Framework
#include "CATVizCubicEnvMap.h"
#include "CATVisTextureObjects.h"
#include "CATVizFaceWithMipMap.h"
// VisualizationBase Framework
class CATStreamer;


class ExportedByCATVisTextureObjects CATVizCubicEnvMapWithMipMap : public CATVizCubicEnvMap
{
	CATDeclareClass;

public:

	/** Contructs a blank cubic environment map with mipmaps.
	 * @param iWidth
	 * Width of the main faces used as texture.
	 * @param iHeight
	 * Height of the main faces used as texture.
	 * @param iPixelDataFormat
	 * Format of the data. @see PixelImageFormat
	 */
	CATVizCubicEnvMapWithMipMap(const int iWidth, 
								const int iHeight,
								 const PixelImageFormat iPixelDataFormat);

	/** Copy constructor */
	CATVizCubicEnvMapWithMipMap(const CATVizCubicEnvMapWithMipMap& iCubicEnvMapWithMipMap);

	/**
	 * Duplicates a cubic environment map with mipmaps.
	 * <br>This allows to modify a <tt>ReadOnly</tt> cubic environment map.
	 * @return
	 * <dl>
	 *  <dt>A <tt>CATVizCubicEnvMapWithMipMap</tt> pointer</dt>
	 *  <dd>The resulting cubic environment map is not <tt>ReadOnly</tt>.</dd>
	 * </dl>
	 * @see CATReadOnlyState
	 */
	virtual CATPixelImage* Duplicate() const;

	/**
	 * Duplicates a cubic environment map with mipmaps and changes the format of the resulting cubic environment map.
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
	 * Get the number of mipmaps defining each face of the cubic environment map.
	 * @return
	 * <dl>
	 *  <dt>the number of mipmaps of each face.</dt>
	 * </dl>
	 */
	unsigned int GetMipMapCount(void);

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
     * </dl>
     */
	CATVizFaceWithMipMap* GetFace(CATViz_CubeMap iFaceOrientation);

	/**
	 * Add a face with mipmaps to the cubic environment map.
	 * @param iFace
	 * The face with mipmaps to add. If a face with the same orientation 
	 * is already defined for the map, the new one replace it.
	 */
	void AddFace(CATVizFacePixelImage* iFace);

	/**
	 * Add a face with mipmaps to the cubic environment map.
	 * @param iFace
	 * The face with mipmaps to add. If a face with the same orientation
	 * is already defined for the map, the new one replace it.
	 */
	void AddFace(CATVizFaceWithMipMap* iFace);

        /** @nodoc */
        virtual CATTexturePixelImageType GetTextureType();

protected:

    /** @nodoc */
	virtual ~CATVizCubicEnvMapWithMipMap();

private:

	unsigned int _mipmapCount;
};

#endif
