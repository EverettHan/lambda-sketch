/**
 *  CATMMRasterAdministrator.h
 *
 *  Created by sx6 on 15/04/2013.
 *  Copyright 2013 Dassault Systemes. All rights reserved.
 *
 */
/*
 * @quickReview V2E 15:10:29 New Raster engine friend
 * @quickreview TPG/HQ4 22:07:21 CATPixelImage unstream thread safety for LDH
 */
#ifndef CATMMRasterAdministrator_H
#define CATMMRasterAdministrator_H

#include "CATMMediaPixelImage.h"
#include "CATMMRasterEngineDef.h"
#include "CATMMImageMetadata.h"
#include "CATMMFormatInfo.h"
#include "CATMMImageProp.h"
#include "CATMMImageSize.h"
#include "CATMMImageWriteProp.h"
#include "CATListOfCATPixelImage.h"

// System
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATBaseUnknown.h"

#include "CATMMSTDSafeIncludeStart.h"
#include <vector>
#include "CATMMSTDSafeIncludeEnd.h"


class CATPixelImage;
class CATMMRasterEngine;
class CATMMColorProfile;
class CATMMRastAdmKeepFavoriteForRestore;

/**
 * @ingroup groupPixelImageMarsh
 * @brief Class providing high level services to read/write bitmap images in file/buffer with the engine management.
 **/
class ExportedByCATMMediaPixelImage CATMMRasterAdministrator : public CATBaseUnknown
{
  friend class CATMMRasterEngineGDIplus;
  friend class CATMMRasterEngineIM;
  friend class CATMMRasterEngineOpenAPI;
  friend class CATPixelImage;
  friend class CATMMRasterEngineSB;
  friend class CATMMRasterEngineQuartz2D;
  friend class CATMMRasterEngineEXR;
  friend class CATMMRasterEngineFactory; // DBE Mar 2023
  friend class CATMMRastAdmKeepFavoriteForRestore;


  CATDeclareClass;

public:
  CATMMRasterAdministrator();
  ~CATMMRasterAdministrator();
  //HRESULT Read(/*...*/); // appel du Read sur le CATListValCATBaseUnknown_var spListEngines selon le type / preference. En cas d'echec sur le 1er engine => essayer le 2eme, etc
  //HRESULT Write(/*...*/); // appel du Write sur le CATListValCATBaseUnknown_var spListEngines selon le type / preference. En cas d'echec sur le 1er engine => essayer le 2eme, etc
  //HRESULT GetInfo(/*.imageprop + imagesize.*/);

  static CATMMRasterAdministrator* GetInstance();
  static void DestroyInstance();

  // format
  HRESULT GetSupportedFormats(const CATListPtrCATMMFormatInfo *&opFormats);
  CATBoolean IsFormatSupported(const CATMMImageFormat iFormat, const CATMMImageCompression iCompression=MMIC_DEFAULT);
  const CATMMFormatInfo* GetInfoFromExt(CATUnicodeString iFileExt);

  //CATBoolean IsMultipageSupported(const CATMMImageFormat iFormat) const;

  // read file
  int GetNumberOfPages (const CATUnicodeString &iFilePath);
  int GetNumberOfTiles (const CATUnicodeString &iFilePath);

  HRESULT GetImageInfo (const CATUnicodeString &iFilePath, CATMMImageProp &oProp, CATMMImageSize &oSize, int iPage=0);

  /*
  * Get image metadata present in bitmap file. Currently, EXIF metadata
  * can be stored in JPEG and TIFF bitmap images
  * @param iFilePath
  *   Complete path of bitmap file.
  * @param oData
  *   Image metadata stored in bitmap file
  * @param iPage
  *   Page number (starting from 0)
  * @return
  * <br><b>Legal values</b>
  * <dl>
  *  <dt>MMIE_FORMAT_NOT_SUPPORTED</dt>
  *  <dd>Image format doesnot contain metadata.</dd>
  *  <dt>MMIE_METADATA_NOT_PRESENT</dt>
  *  <dd>Image format supports metadata but metadata is not present.</dd>
  *  <dt>E_FAIL</dt>
  *  <dd>Unknown error.</dd>
  *  <dt>S_OK</dt>
  *  <dd>Success.</dd>
  * </dl>
  * @see CATMMImageMetadata
  */
  HRESULT GetImageData (const CATUnicodeString &iFilePath, CATMMImageMetadata &oData, int iPage=0);
  HRESULT GetImageData (const CATUnicodeString &iFilePath, CATMMColorProfile* &opColorProfile, int iPage=0);
  HRESULT Read (const CATUnicodeString &iFilePath, CATPixelImage* &opImage, int iPage=0, int iData=MMIF_INVALID);

  // read buffer
  int GetNumberOfPages (const unsigned char *ipBuffer, const int iBufSz);
  int GetNumberOfTiles (const unsigned char *ipBuffer, const int iBufSz);

  HRESULT GetImageInfo (const unsigned char *ipBuffer, const int iBufSz, CATMMImageProp &oProp, CATMMImageSize &oDimention, int iPage=0);
  
  // Identifies the image format based on file signature.
  HRESULT GetImageFormat (const CATUnicodeString &iFilePath, CATMMImageProp &oProp);
  HRESULT GetImageFormat (const unsigned char *ipBuffer, const int iBufSz, CATMMImageProp &oProp);

  /*
  * Get image metadata present in bitmap buffer. Currently, EXIF metadata
  * can be stored in JPEG and TIFF bitmap images
  * @param ipBuffer
  *   Memory buffer containing bitmap image.
  * @param iBufSz
  *   Size of above memory buffer.
  * @param oData
  *   Image metadata stored in bitmap file
  * @param iPage
  *   Page number (starting from 0)
  * @return
  * <br><b>Legal values</b>
  * <dl>
  *  <dt>MMIE_FORMAT_NOT_SUPPORTED</dt>
  *  <dd>Image format doesnot contain metadata.</dd>
  *  <dt>MMIE_METADATA_NOT_PRESENT</dt>
  *  <dd>Image format supports metadata but metadata is not present.</dd>
  *  <dt>E_FAIL</dt>
  *  <dd>Unknown error.</dd>
  *  <dt>S_OK</dt>
  *  <dd>Success.</dd>
  * </dl>
  * @see CATMMImageMetadata
  */
  HRESULT GetImageData (const unsigned char *ipBuffer, const int iBufSz, CATMMImageMetadata &oData, int iPage=0);
  HRESULT GetImageData (const unsigned char *ipBuffer, const int iBufSz, CATMMColorProfile* &opColorProfile, int iPage=0);
  HRESULT Read (const unsigned char *ipBuffer, const int iBufSz, CATPixelImage* &opImage, int iPage=0);
  HRESULT ReadMultiPage (const unsigned char *ipBuffer, const int iBufSz, CATLISTP(CATPixelImage)* &opImage, std::vector<int>& imgPosition, std::vector<float>& frameDelays);
  HRESULT ReadMultiPage (CATUnicodeString iFilePath, CATLISTP(CATPixelImage)* &oImageList, std::vector<int>& imgPosition, std::vector<float>& frameDelays);

  /*
  * Write pixel image to file.
  * @param ipImage
  *   Pixel image to be written to file
  * @param iWriteProp
  *   Write properties specifying output format, preferred compression,
  *   preferred BPP, quality (only for JPEG) and metadata (if supported)
  * @param iFilePath
  *   Complete path (including file name).
  * @see CATPixelImage, CATMMImageWriteProp
  */
  HRESULT Write (const CATPixelImage* ipImage, CATUnicodeString iFilePath, const CATMMImageWriteProp &iWriteProp, bool iEndFlag=false);

  /*
  * Write pixel image to memory.
  * @param ipImage
  *   Pixel image to be written to memory
  * @param iWriteProp
  *   Write properties specifying output format, preferred compression,
  *   preferred BPP, quality (only for JPEG) and metadata (if supported)
  * @param opBuffer
  *   Memory destination where image is written.
  *   This memory must be de-allocated by caller.
  * @param oBufSz
  *   Size of image in memory.
  * @see CATPixelImage, CATMMImageWriteProp
  */
  HRESULT Write (const CATPixelImage* ipImage, unsigned char* &opBuffer, int &oBufSz, const CATMMImageWriteProp &iWriteProp);

  // others
  CATBoolean IsTiled (const CATUnicodeString &iFilePath);
  CATBoolean IsTiled (const unsigned char *ipBuffer, const int iBufSz);
  CATBoolean IsMultipage (const CATUnicodeString &iFilePath);
  CATBoolean IsMultipage (const unsigned char *ipBuffer, const int iBufSz);

  HRESULT SetFavoriteEngine(CATUnicodeString engineName, CATMMRastAdmKeepFavoriteForRestore*iopFavoriteKeeper=NULL);

  void SetRecommendedFavoriteEngineFor(CATMMImageFormat iFormat);

  void CatchFavoriteEngine(CATMMRastAdmKeepFavoriteForRestore&);

protected:
  // helping functions
  CATMMImageBPP GetBPP(int iBPP);
  CATMMImageBPP GetBPP(CATPixelImageFormat iFormat);
  CATMMImageBPP GetBestBPP(CATMMImageBPP imgBPP, CATMMImageBPP outBPP, CATMMImageBPP iWriteBPPs);
  const CATMMFormatInfo* GetMatchingFormatInfo(const CATListPtrCATMMFormatInfo *ipFormats, const CATMMImageFormat iFormat, const CATMMImageCompression iCompression=MMIC_DEFAULT);

  // other formats
  CATPixelImage* LoadPicture64(const CATUnicodeString& fileName);
  CATPixelImage* ReadPicture(const char * iprPathName, CATMMImageProp *opProp=NULL, CATMMImageSize *opDim=NULL);
  CATPixelImage* ReadRGB(const char * iprPathName);
  HRESULT WriteRGB(const CATPixelImage *ipImage, const char *ipPathName);
  //HRESULT WriteHPRTL(const CATPixelImage *ipImage, const char *ipPathName, float iScale, int iDpi, float iGamma=-1.f); // DBE Jan 2023 commented out 

private:

  enum EngineName
  {
    OpenAPI,
    OpenEXR,
    ImageMagick,
    GDIplus,
    Quartz2D,
    Snowbound
  };
  EngineName _favoriteEngine;
  // list des engines
  CATListOfInt _enginesList; // list of enum in reality

  static std::atomic<CATMMRasterAdministrator*> sInstance; // std::atomic to avoid data race in multithreaded context 
  HRESULT GetFormatFromSignature(const unsigned char *ipBuffer, const int iBufSz, CATMMImageProp &oProp);
  
  //TS:ThreadSafe
  static CATMMRasterAdministrator* GetInstanceNotTS();
  HRESULT SetFavoriteEngineNotTS(CATUnicodeString engineName);
  void  CatchFavoriteEngineNotTS(CATMMRastAdmKeepFavoriteForRestore& ioFK);
};

class ExportedByCATMMediaPixelImage CATMMRastAdmKeepFavoriteForRestore
{
  friend CATMMRasterAdministrator;
public:
  CATMMRastAdmKeepFavoriteForRestore();
  CATMMRastAdmKeepFavoriteForRestore(const CATMMRastAdmKeepFavoriteForRestore&);
  CATMMRastAdmKeepFavoriteForRestore(CATMMRasterAdministrator* ipRasterAdministrator, CATUnicodeString iFavoriteEngine);
  virtual ~CATMMRastAdmKeepFavoriteForRestore();

  CATMMRastAdmKeepFavoriteForRestore& operator=(const CATMMRastAdmKeepFavoriteForRestore&);

  void ForgetFavorite();

private:
  CATMMRasterAdministrator* _pRasterAdministrator;
  CATUnicodeString          _keptFavoriteEngine;
};


#endif  // CATMMRasterAdministrator_H
