#ifndef CATIOMemoryMappedFilePosix_h_
#define CATIOMemoryMappedFilePosix_h_

#ifndef _WINDOWS_SOURCE

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATUnicodeString.h"

typedef CATULONG64 CATIOOffset;
typedef CATULONG64 CATIOSize;

class ExportedBySGComposites CATIOMemoryMappedFile
{
public:
    CATIOMemoryMappedFile();
    virtual ~CATIOMemoryMappedFile();

    // Open the file
    HRESULT    Open(const CATUnicodeString& iFilePath, CATULONG64 iFileSize = 0);

    // Set the current position
    HRESULT    Seek(const CATIOOffset& iOffsetWithin);
    // Append data (the size of the mapped area may increase)
    HRESULT    Append(void* iSrcBuffer, const CATIOSize& iBufferSize, CATIOOffset& oOffset);
    // Read from the mapped area at the current position
    HRESULT    Retrieve(void* iDstBuffer, const CATIOSize& iBufferSize);

    // Map a part of the file into memory
    HRESULT    Map(const CATIOOffset& iOffset, const CATIOSize& iSize);
    // Remove the mapping
    HRESULT    UnMap();

private:
    HRESULT    ExpandAllocation(CATULONG64 iFileSize);
    // Close everything
    void       Dispose();
    // Set back the mapping values (offset, size, etc...)
    void       ResetMapping();

    CATIOMemoryMappedFile(const CATIOMemoryMappedFile&);
    CATIOMemoryMappedFile& operator=(const CATIOMemoryMappedFile&);

private:
    // Size of one page in memory
    CATIOSize       _pageSize;

    // File descriptor
    int             _fd;

    // Pointer to the beginning of the buffer of the current mapped area
    void*           _baseCursor;
    // Global offset of the beginning of the current mapped area
    CATIOOffset     _baseOffset;
    // Size of the current mapped area
    CATIOSize       _baseSize;

    // Total size of the file
    CATIOSize       _fileSize;
    // Global offset of the current read/write position
    CATIOOffset     _globalOffset;
    // Global offset of the position after last write
    CATIOOffset     _lastWrite;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !_WINDOWS_SOURCE

#endif // !CATIOMemoryMappedFilePosix
