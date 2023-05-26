// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSFileUtilities:
//   Auxiliary functions.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Aug 2003  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSFileUtilities_h
#define CATCDSFileUtilities_h

#include <time.h>

#include "CATCDSUtilities.h"
#include "CATCDSString.h"

#ifdef _WINDOWS_SOURCE
  #define DIR_DELIMITER "\\"
#else
  #define DIR_DELIMITER "/"
#endif

#ifndef _WINDOWS_SOURCE
  #define _access access
  #define _chdir chdir
  #define _putenv putenv
  #define _unlink unlink
  #include <unistd.h>
#else
  #include <io.h>
  #ifndef F_OK
    #define F_OK 00
    #define X_OK 01
    #define W_OK 02
    #define R_OK 04
  #endif
#endif

ExportedByCATCDSUtilities clock_t CATCDSClockPerSec();
ExportedByCATCDSUtilities clock_t CATCDSClock();

ExportedByCATCDSUtilities CATCDSString CATCDSExtractFileFolder(const CATCDSString& iPath);
ExportedByCATCDSUtilities CATCDSString CATCDSExtractDirName(const CATCDSString& iPath);
ExportedByCATCDSUtilities CATCDSString CATCDSExtractFileName(const CATCDSString& iPath);
ExportedByCATCDSUtilities CATCDSString CATCDSExtractFullFileName(const CATCDSString& iPath);
ExportedByCATCDSUtilities CATCDSString CATCDSRemoveExt(const CATCDSString& iPath);
ExportedByCATCDSUtilities CATCDSString CATCDSMakePath(const CATCDSString& iPath, const CATCDSString& iFile);
ExportedByCATCDSUtilities CATCDSString CATCDSChangeFileExt(const CATCDSString& iPath, const CATCDSString& iExt = "");
ExportedByCATCDSUtilities CATCDSString CATCDSGetFileExt(const CATCDSString& iPath);

ExportedByCATCDSUtilities void CATCDSCopyFile(const CATCDSString& iFileSrc, const CATCDSString& iFileDst);

#endif
