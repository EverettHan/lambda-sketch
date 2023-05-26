#ifndef CATIOMemoryMappedFile_h_
#define CATIOMemoryMappedFile_h_

#if defined(__EMSCRIPTEN__)
    #include "CATIOMemoryMappedFileEmsc.h"
#elif defined(_WINDOWS_SOURCE)
    #include "CATIOMemoryMappedFileWin32.h"
#else
    #include "CATIOMemoryMappedFilePosix.h"
#endif

#endif // !CATIOMemoryMappedFile_h_
