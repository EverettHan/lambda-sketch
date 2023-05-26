//----------------------------------------------------------------------------
//	CATMMediaImageBase.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageBase_H
#define CATMMediaImageBase_H

#include "CATMMediaRasterProcessor_Base.h"
#include "CATMMediaImageDef.h"
#include "CATPixelImage.h"

/** @nodoc */
//int ExportedByCATMMediaRasterFormats CATMMediaImageGetBitPerPixel(const CATMMediaImagePixelFormat iFormat);
int ExportedByCATMMediaRasterProcessor_Base CATMMediaImageGetBitPerPixel(const CATMMediaImagePixelFormat iFormat);

/** @nodoc */
//CATMMediaImagePixelFormat ExportedByCATMMediaRasterFormats CATMMediaImageGetPixelFormat(const CATPixelImageFormat iFormat);
CATMMediaImagePixelFormat ExportedByCATMMediaRasterProcessor_Base CATMMediaImageGetPixelFormat(const CATPixelImageFormat iFormat);

/** @nodoc */
//int ExportedByCATMMediaRasterFormats CATMMediaImageGetBitmapSize(const CATPixelImage& iImage);
int ExportedByCATMMediaRasterProcessor_Base CATMMediaImageGetBitmapSize(const CATPixelImage& iImage);

#endif // CATMMediaImageBase_H
