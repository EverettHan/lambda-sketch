#ifndef CATWritePixelImageEx_H
#define CATWritePixelImageEx_H

//------------------------------------------------------------------------------
// Abstract: Functions to Write Color Pixel Image. 
//
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------

#include "CATMMediaPixelImage.h"

class CATPixelImage;
class CATString;
class CATUnicodeString;

/** @nodoc */
ExportedByCATMMediaPixelImage int WritePixelImageToFile(const CATPixelImage* ipPixelImage, const CATString* ipFileFormat, const CATUnicodeString* ipPathName);

#endif 
