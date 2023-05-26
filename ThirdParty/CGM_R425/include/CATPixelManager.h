#ifndef CATPIXELMANAGER_H
#define CATPIXELMANAGER_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaPixelImage.h"
#include "CATUnicodeString.h"

// Object to tries to allocate nbAlloc blocks of sizeAlloc bytes and book them
// if sizeAlloc is negative, it tries to allocate nbAlloc blocks of maximum size
// return 0 if it fails
// otherwise, returns the max size of a block so that it can allocate nbAlloc blocks
//class  ExportedByCATMMediaRasterFormats CATPixelManager
class  ExportedByCATMMediaPixelImage CATPixelManager
{
public:
    CATPixelManager();
    virtual ~CATPixelManager();
    static void ClearAllAllocableMemoryBlocks();
    static void SetDpiForAlloc(int dpi);
    static void ReleaseOneAllocableMemoryBlock();
    static long GetMaxSizeAllocableMemoryBlocks(int nbAlloc, long sizeAlloc=-1);
    
private:
    static unsigned char** _tab;
    static int _nbAlloc;
    static long _maxSizeAlloc;
    static CATUnicodeString _stringDpi;
};

#endif

