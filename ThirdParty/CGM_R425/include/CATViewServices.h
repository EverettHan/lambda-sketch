#ifndef _CATViewServices_H
#define _CATViewServices_H

#include <CATView.h>
#include <CATString.h>
#include <CATListOfCATString.h>
#include <CATFilePath.h>

class CATRender;
class CATGraphicAttributeSet;
class CATPixelImage;
class CATUnicodeString;

/**
 * Get a file in path list. Sample : CATSearchFile( CATGetEnv( "CATGraphicPath" ), "icons/normal/toto.bmp" );
 **/
#define CATSearchFile( iPathList, iPath ) (CATFilePath::Search( iPath, iPathList ))
/**
 * Get an icon from the runtimeview.
 * Use an indexed internal memory cache, so don't store the resulting pointer,
 * but call the function each time you need access to the image
 **/
ExportedByCATView CATPixelImage * CATGetStaticIcon( const CATUnicodeString &iName, int iSize, float iDensity = 1.0f );
/**
 * Load a BMP image file.
 * This service is already provided by CATPixelImage but throught the MultiMedia Framework.
 * To avoid loading this framework in Web Viewer context, the service is also provided here.
 * Returns NULL if file not found, or format not handled (currently limited to 24 bits images)
 */
ExportedByCATView CATPixelImage *CATLoadImageBMP( const CATFilePath &iPath );
/**
 * Split a string
 **/
int        ExportedByCATView CATSplitString( const CATUnicodeString &iString, CATListOfCATUnicodeString &oList, const char *iSeparator );

#endif
