#ifndef CATTexturePixelImage_H
#define CATTexturePixelImage_H

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

//
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : This Class specifies image pixel used
//            in the graphic material textured
//
//            this class allows
//                 - to optimize the drawing 
//                 - to minimize the number of image read by pathname
//           
//
// ----------------------------------------------------------------
//  Usage : 
//
//   An Image attached to a material (ie a CATGraphicMaterial)
//
//       When you attach an image you increase the reference's number 
//       of this image. The management of the image's destruction 
//       is done by the material. An image is deleted when it number 
//       of links is zero.
//
//   Creation of a CATTexturePixelImage
//
//     - by new operator :If you give pixels data these data 
//       are duplicated in the new instance. It's the case when you
//       use the copy constructeur with CATPixelImage, in anycase, the
//       data of the CATPixelImage are duplicated.
//       If no data are indicated a data zone is created where each 
//       pixel is initialized to zero.
//
//     - by the static method GetImage  if the image comes from a file 
//
//   Static list of CATTexturePixelImage
//       
//       When you put an image in the list, the reference number of 
//       this image is increased of one. In this way, your image 
//       can be deleted by a material.
//
//       The list are updated with  methods :
//
//     - GetImage tries first to find your image in the list 
//       else on a file (the name is a pathname )
//     - AddList adds an instance and verify only that the adress 
//       of your image is not in the list. This method returns 1 if 
//       the instance is already in the list.
//     - RemoveList removes an instance of the list,Warning: if your 
//       image has 0 link it will be deleted in thid method.
//     - EmptyList,at the end of your application you must call this method
//       to remove all the instance of the list.
//
//       To go throw the list, first you call the method GetListLength 
//       to know the size of the list, and next you ask the ieme image 
//       by the method GetImageFromList(i)
//
//       You can get an image from the list by it name, you use the method
//       GetImageFromList(name). 
//       
//   Pixels of CATTexturePixelImage
//    
//       Pixels are belong to the instance. When there is a destruction of
//       an instance, there is a destruction of the pixels. 
//
//   
//   Send A notification to the material attach
//
//      You have make a modification in your image, You can
//      call the material to worn it about this modification.After 
//      the material send a notification to the elements attach to it.
//      In general case the modification is a redraw. Use this method :
//      SendMaterialNotification( CATRedrawNotification)
//
// ----------------------------------------------------------------
//  Inheritance : CATTexturePixelImage
//                   CATPixelImage
//                      CATBaseUnknown
// ----------------------------------------------------------------
//  Main Methods :
//
//     manage the number of reference
//        AddRef
//        Release
//
//     acces to the name of the image
//        GetPathName
//        SetPathName
//
//     manage DL
//        SetIndTextDL
//        GetIndTextDL
//        GetTextOkDL
//
//     access to the pixels image - ie the CATPixelImage
//
//     Managment of the static list  ( a PathName is using )
//        GetImage    , return an image (from a file or the list)
//        EmptyList   , empty the list and del instances with 0 link
//        AddList     , add a CATTexturePixelImage in the list
//        RemoveList  , rm an instance from the list, and del it if 0 link
//        GetListLength         , return the list size
//        GetImageFromList(i)   , return the ieme image of the list
//        GetImageFromList(name), return the image with this name
//
// ----------------------------------------------------------------
#include "CATPixelImage.h"

// interfaces

// TIEs

// others
#include "CATEventSubscriber.h"
#include "CATMaterialNotification.h"
#include "CATViz.h" // JQT : Kept due to applicative build impact : CATViz --> SGInfra
#include "SGInfra.h"
#include "list.h"
#include "CATMutex.h"
#include "CATDataType.h"


class CATStreamer;
class CATCacheOfDestroyedElements;

#ifdef _IRIX_SOURCE
class CATSupport;
#endif

/** @nodoc */
enum CATTexturePixelImageType { TEXTURE_SIMPLE, TEXTURE_SIMPLE_WITH_MIPMAP, TEXTURE_VOLUME, TEXTURE_VOLUME_WITH_MIPMAP, TEXTURE_CUBIC_ENV_MAP, TEXTURE_CUBIC_ENV_MAP_WITH_MIPMAP };

/** Class to create an image used in texture mapping. */
class ExportedBySGInfra CATTexturePixelImage : public CATPixelImage


{
	/** @nodoc */
	friend class CATMarshallableTexturePixelImage;
	/** @nodoc */
	friend class CATCacheOfDestroyedElements;
	/** @nodoc */
	CATDeclareClass;

public:

	/** Contructs a blank texture of given size.
	* @param iWidth
	* Width of the image used as the texture.
	* @param iHeight
	* Height of the image used as the texture.
	* @param iPixelDataFormat
	* Format of the data. @see CATPixelImageFormat
	*/
	CATTexturePixelImage(const int                 iWidth,
		const int                 iHeight,
		const CATPixelImageFormat iPixelDataFormat);

	/** Constructs a texture of given size and data.
	* @param iWidth
	* Width of the image used as the texture.
	* @param iHeight
	* Height of the image used as the texture.
	* @param iPixelDataFormat
	* Format of the data. @see CATPixelImageFormat
	* @param iPixelData
	* Data of the image used as the texture.
	*/
	CATTexturePixelImage(const int                   iWidth,
		const int                   iHeight,
		const CATPixelImageFormat   iPixelDataFormat,
		const unsigned char       * iPixelData);


	/** Copy constructor */
	CATTexturePixelImage(const CATPixelImage        & iImage);

	/** Copy constructor */
	CATTexturePixelImage(const CATTexturePixelImage & iImage);

	/** @nodoc */
	virtual void Stream(CATStreamer& oStream,int iSaveType = 0);
	/** @nodoc */
	virtual void Stream(CATStreamer& oStr, int iSaveType, CATStreamFormat iFormat);

	/** @nodoc */
	virtual void UnStream(CATStreamer& iStream);

	/** @nodoc */
	virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);

	/**
	* Writes the texture to a file.
	* @param iFileFormat
	*   The output file format.
	* <br><b>Legal values</b>
	* <dl>
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

#ifdef ADDREFERENCE_MIGRATION
#else
	/** @deprecated: R424
	 * Use rather Release method
	 * Deletes the texture.
	 */
	virtual int Destroy();

	/** @deprecated: R424
	 * Use rather AddRef method
	 * Increments the reference counter of the texture.
	 */
	void            AddReference();

	/** @deprecated: R424
	 * Use rather Release method
	 * Decrements the reference counter of the texture.
	 */
	void            SubReference();

	/** @deprecated: R424
	 * Returns the reference counter value of the texture.
	 */
	int             GetReferenceNumber() const;
#endif

	/** Modify the image used as the texture.
	* @param iWidth
	* Width of new image used as the texture.
	* @param iHeight
	* Height of new image used asthe texture.
	* @param iFormat
	* Pixel data format of new image used as the texture.
	* @param iPixels
	* Pixel data of new image used as the texture
	* @param iFormat
	* Inactive.
	*/
	virtual int Modify(int                   iWidth,
		int                   iHeight, 
		CATPixelImageFormat   iFormat, 
		unsigned char       * iPixels,
		CATDeallocatePixels   iFlag = PixDeallocateYESfree);

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

	/** Returns the pathname of the image used as the texture. */
	virtual const CATString & GetPathName() const;

	/** Sets the pathname of the image used as the texture.
	* @param iPathName
	* Pathname of the image.
	*/
	virtual void SetPathName(const CATString &iPathName);

	/** @nodoc */
	static CATTexturePixelImage * GetImage(const CATString     & iPathName, 
		const ReadOnlyState   iState = ReadOnly);
	/** @nodoc */
	static CATTexturePixelImage * GetImageFromList(const CATString & iPath);

	/** @nodoc */
	static CATTexturePixelImage * GetImageFromList(const int iNumber);

	/** @nodoc */
	static int GetListLength();

	/** @nodoc */
	static void EmptyList();

	//      return 0 : OK / 1 : KO ( if iImage=NULL , return = 0 )
	/** @nodoc */
	static int AddList(CATTexturePixelImage * iImage);

	/** @nodoc */
	static int RemoveList(CATTexturePixelImage * iImage);

	/** @nodoc */
	virtual void SetImagePixelsModification(); 

	/** @nodoc */
	static void SetAllImagePixelsModification();

	/** Updates the display after a modification of the graphic material.
	* <ul>
	* <li>CATRedrawNotification : redraw the window.</li>
	* <li>CATUpdateTCNotification : recalculate texture coordinates and redraw the window.</li>
	* </ul>
	*/
	virtual void SendMaterialNotification(CATMaterialNotificationType iType);

#if defined(_IRIX_SOURCE) || defined(_WINDOWS_SOURCE)
	/** @nodoc */  
	static ::list<CATTexturePixelImage> &GetListImage();
#endif

	/** @nodoc */
	inline unsigned int GetStorageID();
	/** @nodoc */
	inline void SetStorageID( unsigned int iStorageID);

	/** @nodoc */
	int IsTransparent() const;

	/** @nodoc */
	virtual CATTexturePixelImageType GetTextureType();

	// Resource management

	/** @nodoc */
	char* GetProvider();

	/** @nodoc */
	char* GetUUID();

	/** @nodoc */
	/** Call this method to check that two textures are the same. */
	virtual bool IsEqual(const CATTexturePixelImage& iCompare) const;

  static CATTexturePixelImage* Create(const CATPixelImage& src);

	/**
	 * Increments the reference count for the given interface.
	 * @return The reference count value.
	 * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
	 */
	virtual ULONG   __stdcall AddRef();

	/**
	 * Decrements the reference count for the given interface.
	 * @return The reference count value.
	 * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
	 */
	virtual ULONG   __stdcall Release();

protected:

	/** @nodoc */
	virtual ~CATTexturePixelImage();

  CATTexturePixelImage(const int                   iWidth,
    const int                   iHeight,
    const CATPixelImageFormat   iPixelDataFormat,
    const float       * iPixelData);

private:
	unsigned char* InternalCopyPicture(unsigned char* oBuf, const unsigned char* iBuf, int iSize, int iPixSize, CATPixelImageFormat iFormat);

	int 	    _ReferenceNumber;
	CATString   _PathName;

	unsigned int _StorageID;

	unsigned int _transparencyActivation;

	static ::list<CATTexturePixelImage> _ListImage;

	// provider
	char* _resourceUUID;
	char* _resourceProvider;
};

inline unsigned int CATTexturePixelImage::GetStorageID()
{
	return _StorageID;
}

inline void CATTexturePixelImage::SetStorageID( unsigned int iStorageID)
{
	_StorageID = iStorageID;
}

#endif // CATTexturePixelImage_H
