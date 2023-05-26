// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATWritePixelImage_H
#define CATWritePixelImage_H

//------------------------------------------------------------------------------
// Abstract: Functions to Write 
//           Color Pixel Image or Texture in memory. 
//
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------

//#include "CATViz.h"
#include "CATMMediaPixelImage.h"
#include "CATUnicodeString.h"

class CATPixelImage;
class CATString;

/** @nodoc */
enum CodingFormat { TC_UNCOMPRESSED , TC_PACKBITCOMPRESSED , INDEXE_UNCOMPRESSED ,
                    INDEXE_PACKBITCOMPRESSED , RGB_UNCOMPRESSED,
                    RGBA_UNCOMPRESSED,
                    UNCOMPRESSED, PACKBITS, CCITT_G4, INDEXED_UNCOMPRESSED, INDEXED_PACKBITS };


// Write RGB file
// Allowed coding formats are RGB_UNCOMPRESSED and RGBA_UNCOMPRESSED
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteRGBPixelImage(const CATPixelImage*, const char* pathName, CodingFormat codingFormat = RGB_UNCOMPRESSED);

// Write TIFF file(True color, not compressed, 1 strip only)
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTIFFPixelImage(const CATPixelImage*, const char* pathName, CodingFormat codingFormat = UNCOMPRESSED);

// Write HP/RTL file(a scale may be applied)
// gama is optional, if not specified(-1.0 value) then best gama is calculated. 
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteHPRTLPixelImage(const CATPixelImage* pRGBImage, const char* pathName, float scale, int dpi, float gama = -1.0);

// Write HP/RTL file with maximum size specified
// maxSize is the maximum dimension in mm 
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteFixedSizeHPRTLPixelImage(const CATPixelImage* pRGBImage, const char* pathName, float maxSize, int dpi, float gama = -1.0);

// return value is a return code equal to 0 if ok. 

// Write a BMP File
/** @nodoc */
// compression = 0: uncompressed
// compression = 1: compressed
ExportedByCATMMediaPixelImage int WriteBMPPixelImage(const CATPixelImage* pRGBImage, const char* pathName, int compresion = 0);
  // return 9     : bad entry format
  // return 1     : Can't open file
  // return 2,3,4 : problem during writing
  // return 5     : can't close file
  // return 6     : X or Y size of image = 0
  



// @@@@@@@@@@@@@@@@@ Tiff Bilevel @@@@@@@@@@@@@@@@@@

// Compression =1 ---> PackBit
// Compression =0 ---> Non Compresse
  
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTIFFBWPixelImage(const CATPixelImage* pRGBImage, const char* pathName, CodingFormat codingFormat = CCITT_G4);
  // return 0  : ok
  // return 1  : No RGB PixelImage
  // return 2  : Image size = 0;
  // return 3  : Compression flag incorrect;

// =============== Tiff Grey  ===============

// Compression =1 ---> PackBit
// Compression =0 ---> Non Compresse

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTIFFGreyPixelImage(const CATPixelImage* pRGBImage, const char* pathName, CodingFormat codingFormat = PACKBITS);
  // return 0  : ok
  // return 1  : No RGB or L PixelImage
  // return 2  : Image size = 0;
  // return 3  : Compression flag incorrect;
  // return 4  : memory error


// Writes a CATPixelImage to a JPEG file.
// <b>Role</b>:
// @param iPixelImage
//   The CATPixelImage to save.
// @param iPathName
//   The path to save the file to.
// @param iQuality
//   JPEG quality.
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>One of the standard quality levels enumerated in jpg_quality or an integer value between 1 and 100.</dt>
//     <dd>Low values give a better compression on the expense of the quality of the reconstructed image.</dd>
//   </dl>
// @param iMode
//   JPEG output mode.
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>One of the jpg_mode enum.</dt>
//   </dl>
// @return
//   An integer value. 
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>9</dt>
//     <dd>Bad entry format</dd>
//     <dt>1</dt>
//     <dd>Cannot open file for writing</dd>
//     <dt>5</dt>
//     <dd>Cannot close file</dd>
//     <dt>6</dt>
//     <dd>X or Y size of image = 0</dd>
//     <dt>-1</dt>
//     <dd>Null entry</dd>
//   </dl>
// @see CATPixelImage, jpg_quality, jpg_mode
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteJPEGPixelImage(const CATPixelImage* iPixelImage, const char* iPathName,
                                                   int iQuality = 75, int iMode = 0);

// Writes a CATPixelImage to a JPEG memory buffer.
// <b>Role</b>:
// @param iPixelImage
//   The CATPixelImage to save.
// @param oMemJPEGtoDelete
//   A pointer to the buffer the image has been saved in. The buffer must be de-allocated with delete[].
// @param oMemJPEGSize
//   The size of the generated JPEG buffer.
// @param iQuality
//   JPEG quality.
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>One of the standard quality levels enumerated in jpg_quality or an integer value between 1 and 100.</dt>
//     <dd>Low values give a better compression on the expense of the quality of the reconstructed image.</dd>
//   </dl>
// @param iMode
//   JPEG output mode.
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>One of the jpg_mode enum.</dt>
//   </dl>
// @return
//   An integer value. 
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>9</dt>
//     <dd>Bad entry format</dd>
//     <dt>1</dt>
//     <dd>Cannot open file for writing</dd>
//     <dt>5</dt>
//     <dd>Cannot close file</dd>
//     <dt>6</dt>
//     <dd>X or Y size of image = 0</dd>
//     <dt>-1</dt>
//     <dd>Null entry</dd>
//   </dl>
// @see CATPixelImage, jpg_quality, jpg_mode
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteToMemoryJPEGPixelImage(const CATPixelImage* iPixelImage, unsigned char** oMemJPEGtoDelete, int* oMemJPEGSize,
                                                           int iQuality = 75, int iMode = 0);

// Writes a CATPixelImage to a PNG memory buffer.
// <b>Role</b>:
// @param iPixelImage
//   The CATPixelImage to save.
// @param oMemPNGtoDelete
//   A pointer to the buffer the image has been saved in. The buffer must be de-allocated with delete[].
// @param oMemPNGSize
//   The size of the generated PNG buffer.
// @param iMode
//   PNG output mode.
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>One of the png_mode enum.</dt>
//   </dl>
// @return
//   An integer value. 
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>9</dt>
//     <dd>Bad entry format</dd>
//     <dt>1</dt>
//     <dd>Cannot open file for writing</dd>
//     <dt>5</dt>
//     <dd>Cannot close file</dd>
//     <dt>6</dt>
//     <dd>X or Y size of image = 0</dd>
//     <dt>-1</dt>
//     <dd>Null entry</dd>
//   </dl>
// @see CATPixelImage, png_quality, png_mode
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteToMemoryPNGPixelImage(const CATPixelImage* iPixelImage, unsigned char** oMemPNGtoDelete, int* oMemPNGSize,
                                                           int iMode = 0);

// Writes a CATPixelImage to a BMP memory buffer.
// <b>Role</b>:
// @param iPixelImage
//   The CATPixelImage to save.
// @param oMemBMPtoDelete
//   A pointer to the buffer the image has been saved in. The buffer must be de-allocated with delete[].
// @param oMemBMPSize
//   The size of the generated BMP buffer.
// @param iMode
//   BMP output mode.
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>One of the bmp_mode enum.</dt>
//   </dl>
// @return
//   An integer value. 
//   <br><b>Legal values</b>:
//   <dl>
//     <dt>9</dt>
//     <dd>Bad entry format</dd>
//     <dt>1</dt>
//     <dd>Cannot open file for writing</dd>
//     <dt>5</dt>
//     <dd>Cannot close file</dd>
//     <dt>6</dt>
//     <dd>X or Y size of image = 0</dd>
//     <dt>-1</dt>
//     <dd>Null entry</dd>
//   </dl>
// @see CATPixelImage, bmp_quality, bmp_mode
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteToMemoryBMPPixelImage(const CATPixelImage* iPixelImage, unsigned char** oMemJPEGtoDelete, int* oMemBMPSize,
                                                           int iMode = 0);

/** @nodoc */
ExportedByCATMMediaPixelImage int WritePNGPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteEXRPixelImage(const CATPixelImage * pixelImage, const char * pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteCALSPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteIFFPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteIOCAPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WritePCXPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WritePICTPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WritePSDPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteRASTPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTGAPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteXPMPixelImage(const CATPixelImage* pixelImage, const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int WriteXWDPixelImage(const CATPixelImage* pixelImage, const char* pathName);







/** @nodoc */
ExportedByCATMMediaPixelImage int WriteRGBPixelImageEx (const CATPixelImage*, const CATUnicodeString &pathName, CodingFormat codingFormat = RGB_UNCOMPRESSED);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTIFFPixelImageEx(const CATPixelImage*, const CATUnicodeString &pathName, CodingFormat codingFormat = UNCOMPRESSED);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteHPRTLPixelImageEx(const CATPixelImage* pRGBImage, const CATUnicodeString &pathName, float scale, int dpi, float gama = -1.0);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteFixedSizeHPRTLPixelImageEx(const CATPixelImage* pRGBImage, const CATUnicodeString &pathName, float maxSize, int dpi, float gama = -1.0);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteBMPPixelImageEx (const CATPixelImage* pRGBImage, const CATUnicodeString &pathName, int compresion = 0);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTIFFBWPixelImageEx(const CATPixelImage* pRGBImage, const CATUnicodeString &pathName, CodingFormat codingFormat = CCITT_G4);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTIFFGreyPixelImageEx(const CATPixelImage* pRGBImage, const CATUnicodeString &pathName, CodingFormat codingFormat = PACKBITS);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteJPEGPixelImageEx(const CATPixelImage* iPixelImage, const CATUnicodeString &iPathName,   int iQuality = 75, int iMode = 0);
/** @nodoc */
ExportedByCATMMediaPixelImage int WritePNGPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteCALSPixelImageEx(const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteIFFPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteIOCAPixelImageEx(const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WritePCXPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WritePICTPixelImageEx(const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WritePSDPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteRASTPixelImageEx(const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteTGAPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteXPMPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteXWDPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);
/** @nodoc */
ExportedByCATMMediaPixelImage int WriteEXRPixelImageEx (const CATPixelImage* pixelImage, const CATUnicodeString &pathName);

#endif 
