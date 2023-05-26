// COPYRIGHT DASSAULT SYSTEMES 1999


#ifndef CATTracePixelLifeCycle_H
#define CATTracePixelLifeCycle_H


#include "CATMMediaPixelImage.h"
#include "CATPixelImage.h"
#include "CATTrace.h"

enum TraceErrorLevels {
  Errors  =  1,
                 // Lifecycle : see CATMMCStatCounter
  Engines =  4,  // Load/unload and use for reading images.
};
enum CATPixelImageDebugFilter {
  PIDF_NoFilter = 0,
  PIDF_Copy = 0x0001,
  PIDF_Icon     = 0x0002,
  PIDF_ChkErrMC = 0x0004
};

ExportedByCATMMediaPixelImage const char * _GetFormat(CATPixelImageFormat iFPxl);
ExportedByCATMMediaPixelImage void _DumpPixelBuffer(uint* iSz, int*ixSz, int*iySz,const CATPixelImageFormat*iFormat, const char* ipPrefixInfo=NULL, const char* ipSuffixInfo = NULL);
ExportedByCATMMediaPixelImage void _DumpPixelBufferbpp(uint* iSz, int*ixSz, int*iySz,int iBPP, const char* ipPrefixInfo = NULL, const char* ipSuffixInfo = NULL);
ExportedByCATMMediaPixelImage void _SetPixelSource(CATPixelImage* ipPixelImage, CATUnicodeString iSource, const char* ipPrefixInfo = NULL, const char* ipSuffixInfo = NULL);
ExportedByCATMMediaPixelImage int  _SetPixelFilter(CATPixelImage* ipPixelImage, int iDebugFilter);
ExportedByCATMMediaPixelImage int  _GetPixelFilter(CATPixelImage* ipPixelImage);

#endif
