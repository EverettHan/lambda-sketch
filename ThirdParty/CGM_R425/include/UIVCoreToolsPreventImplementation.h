#ifndef PREVENT_IMPLEMENTATION

// COPYRIGHT DASSAULT SYSTEMES  2017

#if defined(_WINDOWS_SOURCE) && defined(_MSC_VER) && _MSC_VER>=1900
#define PREVENT_IMPLEMENTATION =delete
#elif defined(_LINUX_SOURCE) && __cplusplus>=201103L
#define PREVENT_IMPLEMENTATION =delete
#else
#define PREVENT_IMPLEMENTATION
#endif

#endif
