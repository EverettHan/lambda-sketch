// COPYRIGHT DASSAULT SYSTEMES 2001


#ifndef CATVizBaseReadPixelImage_H
#define CATVizBaseReadPixelImage_H

//
//------------------------------------------------------------------------------
// Abstract: Functions to Read
//           Color Pixel Image or Texture in memory.
//
//------------------------------------------------------------------------------
// Usage:    This functions are used to read Pixel Images
//
//------------------------------------------------------------------------------
// Inheritance:
//------------------------------------------------------------------------------
// Main methods:
//
//------------------------------------------------------------------------------
//--------------------------------------------------------------------------

//#include "CATViz.h"
#include "CATMMediaPixelImage.h"

#include "CATPixelImage.h"
//class CATDialog;
//class CATRep;

// Associated functions to create a CATPixelImage from files:

// Read RGB (SGI) file
// Get an RGB Image, or an RGBA Image if Alpha data is present.
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadRGBPixelImage(const char* pathName, ReadOnlyState = NotReadOnly);



// Read TIFF file (True color, compressed PackBit or not, 1 strip only)
//                (or Indexed 8 bits, compressed PackBit or not, 1 strip only)
//                (or Greyscale 8 bits, compressed PackBit or not, 1 strip only)
//                (or Bilevel, compressed PackBit or not, 1 strip only)
//                 LZW Compression not supported
// GET a L Image if Tiff GrayScale
// Get an RGBA Image if Alpha data is present.
//    If not, get an RGB Image.

// if Inrc != 0
// ReadTIFFPixelImage use it to return the "Return code"
// 1 = Impossible to create file
// 2 = Impossible to close file
// 3 = Writing error (Disk full ?)
// 4 = Invalid Input parameters
// 5 = Not a valid Tiff file
// 6 = Only True Color with 8-8-8 type is supported
// 7 = This compression algorithm is not supported
// 8 = Not a True Color or Indexed Color Image
// 10 = More than 1 strip images not supported
// 11 = Read error: truncated file or invalid Tiff file
// 12 = Impossible to open file
// 13 = Invalid Pixels data (Invalid Tiff file)
// 14 = This orientation is not supported (1 and 4 only)
// 15 = Invalid Indexed Image (Invalid Tiff file)
// 16 = Invalid Indexed Image, Color Palette missing
// 17 = Invalid Indexed Image, only 8 bits (256 colors palette) supported";
// 18 = Error when uncompressing pixels data
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadTIFFPixelImage(const char* pathName, ReadOnlyState = NotReadOnly, int pageNumber = 0, int* Inrc = 0);


/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadPicturePixelImage(const char* pathName, ReadOnlyState = NotReadOnly);

// Create a CATPixelImage from Raster data (1 pixel = 1 bit)
//
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* CreatePixelImageFromRaster(unsigned char* rasterPixels, int dimX, int dimY, ReadOnlyState rState = NotReadOnly);

// Idem, C or Fortran Binding
// *ier <> 0 if CATPixelImage is not Created
//
/** @nodoc */
ExportedByCATMMediaPixelImage int rastopix(unsigned char* rasterPixels, long* dimX, long* dimY, CATPixelImage** resultingCATPixelImage, int* ier);

// The generated CATPixelImage format is RGB in any case. (Except for ReadRGBPixelImage() and
// ReadTIFFPixelImage() that give an RGBA format if Alpha data was provided in the image file).


//Read JPEG File
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadJPEGPixelImage(const char* pathName, ReadOnlyState = NotReadOnly);

//Read JPEG From Memory buffer
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadMemoryJPEGPixelImage(const unsigned char* JpgBuff, int JpgBuffSize, ReadOnlyState rState);



// if pathName =
//     a complete PATH ReadBMPPixelImage read this bitmap
//     a simple name with no "/" :
//        ReadBMPPixelImage read the cnext icone name "pathName"
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadBMPPixelImage(const char* pathName, ReadOnlyState rState);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadMemBMPPixelImage(void* Buffer, int Length, ReadOnlyState rState);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadPNGPixelImage(const char* pathName, ReadOnlyState rState);
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadMemoryPNGPixelImage(void* Buffer, int Length, ReadOnlyState rState);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadMemTGAPixelImage(void* Buffer, int Length, ReadOnlyState rState);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadMemTIFFPixelImage(void* Buffer, int Length, ReadOnlyState rState);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadMemGenericPixelImage(void* Buffer, int Length, ReadOnlyState rState, int pageNumber = 0, int* rc = 0);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadGenericPixelImage(const char* pathName, ReadOnlyState rState, int pageNumber = 0, int* rc = 0);

/** @nodoc */
ExportedByCATMMediaPixelImage int GetNumberOfPages(const char* pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int GetNumberOfPages(void* Buffer, int Length);

/** @nodoc */
ExportedByCATMMediaPixelImage int GetBitmapFileType(const char* pathName);


/******** Unicode supported APIs********/


// Associated functions to create a CATPixelImage from files:

// Read RGB (SGI) file
// Get an RGB Image, or an RGBA Image if Alpha data is present.
/** @nodoc */

ExportedByCATMMediaPixelImage CATPixelImage* ReadRGBPixelImageEx(const CATUnicodeString & pathName, ReadOnlyState = NotReadOnly);

// Read TIFF file (True color, compressed PackBit or not, 1 strip only)
//                (or Indexed 8 bits, compressed PackBit or not, 1 strip only)
//                (or Greyscale 8 bits, compressed PackBit or not, 1 strip only)
//                (or Bilevel, compressed PackBit or not, 1 strip only)
//                 LZW Compression not supported
// GET a L Image if Tiff GrayScale
// Get an RGBA Image if Alpha data is present.
//    If not, get an RGB Image.

// if Inrc != 0
// ReadTIFFPixelImage use it to return the "Return code"
// 1 = Impossible to create file
// 2 = Impossible to close file
// 3 = Writing error (Disk full ?)
// 4 = Invalid Input parameters
// 5 = Not a valid Tiff file
// 6 = Only True Color with 8-8-8 type is supported
// 7 = This compression algorithm is not supported
// 8 = Not a True Color or Indexed Color Image
// 10 = More than 1 strip images not supported
// 11 = Read error: truncated file or invalid Tiff file
// 12 = Impossible to open file
// 13 = Invalid Pixels data (Invalid Tiff file)
// 14 = This orientation is not supported (1 and 4 only)
// 15 = Invalid Indexed Image (Invalid Tiff file)
// 16 = Invalid Indexed Image, Color Palette missing
// 17 = Invalid Indexed Image, only 8 bits (256 colors palette) supported";
// 18 = Error when uncompressing pixels data
/** @nodoc */

ExportedByCATMMediaPixelImage CATPixelImage* ReadTIFFPixelImageEx(const CATUnicodeString & pathName, ReadOnlyState = NotReadOnly, int pageNumber = 0, int* Inrc = 0);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadPicturePixelImageEx(const CATUnicodeString & pathName, ReadOnlyState = NotReadOnly);

//Read JPEG File
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadJPEGPixelImageEx(const CATUnicodeString & pathName, ReadOnlyState = NotReadOnly);

// if pathName =
//     a complete PATH ReadBMPPixelImage read this bitmap
//     a simple name with no "/" :
//        ReadBMPPixelImage read the cnext icone name "pathName"
/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadBMPPixelImageEx(const CATUnicodeString & pathName, ReadOnlyState rState);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadPNGPixelImageEx(const CATUnicodeString & pathName, ReadOnlyState rState);

/** @nodoc */
ExportedByCATMMediaPixelImage CATPixelImage* ReadGenericPixelImageEx(const CATUnicodeString & pathName, ReadOnlyState rState, int pageNumber = 0, int* rc = 0);

/** @nodoc */
ExportedByCATMMediaPixelImage int GetNumberOfPagesEx(const CATUnicodeString & pathName);

/** @nodoc */
ExportedByCATMMediaPixelImage int GetBitmapFileTypeEx(const CATUnicodeString & pathName);

/****************/


#endif
