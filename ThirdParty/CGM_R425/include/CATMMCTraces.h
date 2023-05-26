#ifndef CATMMCTRACES_H
#define CATMMCTRACES_H

#include "CATMMediaCore2.h"

#include "CATUnicodeString.h"

class CATBaseUnknown;
class CATSysTSBaseUnknown;

/**
  * @ingroup groupPotentialSysInfra
  * @brief Service/helper for traces.
  */
class ExportedByCATMMediaCore2 CATMMCTraces
{
public:
  static CATUnicodeString GetSizeWithUnit(double iVal, const char*iFormat = NULL);
//static CATUnicodeString GetTimeWithUnit(DWORD iMilliSec, const char* iFormat = NULL);
  static CATUnicodeString DumpPointer(const void* iptr);
  static CATUnicodeString DumpClass(const void* iptr, const char* iType=NULL, const char* iInstance = NULL);
  static CATUnicodeString DumpBaseUnknwon(const CATBaseUnknown* ipBU, const char* iInstance = NULL);
  static CATUnicodeString DumpTSBaseUnknwon(const CATSysTSBaseUnknown* ipTSBU, const char* iInstance = NULL);

  //Image
  static CATUnicodeString DumpBitsPerPixels(unsigned int bpp);
  static CATUnicodeString DumpResolution(unsigned int width, unsigned int height);
  static CATUnicodeString DumpSignedResolution(int width, int height);
  static CATUnicodeString DumpPixelSizes(float xResolutino, float yResolution);
};


#endif
