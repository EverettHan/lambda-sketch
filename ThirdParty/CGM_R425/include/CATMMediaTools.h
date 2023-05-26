#ifndef CATMMEDIATOOLS_H
#define CATMMEDIATOOLS_H
//--------------------------------------------------------------
// Module Name:
//               CATMMediaTools.h
//--------------------------------------------------------------
// Abstract:
//               Basic Tools API
//
//--------------------------------------------------------------

#include "CATMMediaPixelImage.h"
#include "CATUnicodeString.h"

//#include "CATMMediaVideo.h"

// -- declaration des prototypes de function implentes dans MMediaTools.cpp

ExportedByCATMMediaPixelImage CATUnicodeString   GetExtensionFromFile(const CATUnicodeString& filename);
ExportedByCATMMediaPixelImage CATUnicodeString GetFileWithoutExtension(const CATUnicodeString& filename,char delimiter='.');
ExportedByCATMMediaPixelImage const CATUnicodeString CATGetValidDirectory(const CATUnicodeString);
#ifdef __cplusplus
extern "C" {
#endif
ExportedByCATMMediaPixelImage unsigned char * RGBA2BGRandSize( const unsigned char * pixels,int width, int height,int &countBits );
ExportedByCATMMediaPixelImage unsigned char *  RGBA2BGR(const unsigned char * pixels,int width, int height, int *opCountBits=0);
ExportedByCATMMediaPixelImage unsigned char *  RGBA2ABGR(const unsigned char * pixels,int width, int height);
ExportedByCATMMediaPixelImage void  RGBA2ABGRbis( unsigned char * pixels,int xSize, int ySize );
ExportedByCATMMediaPixelImage unsigned char * ABGR2RGBA(unsigned char * pixels,int width, int height );
ExportedByCATMMediaPixelImage unsigned char * ABGR2RGB( unsigned char * pixels,int width, int height );
ExportedByCATMMediaPixelImage unsigned char * BGR2RGB( unsigned char * pixels,int width, int height );
ExportedByCATMMediaPixelImage unsigned char * BGR2RGBA( unsigned char * pixels,int width, int height );

ExportedByCATMMediaPixelImage const char *CATGetCurrentDirectory(void);
ExportedByCATMMediaPixelImage const char *resizePath(const char* , int);
ExportedByCATMMediaPixelImage unsigned long GetTimeInMilliSeconds();
ExportedByCATMMediaPixelImage char * getCFOURCC(const int & c4);
#ifdef __cplusplus
};
#endif

#endif






