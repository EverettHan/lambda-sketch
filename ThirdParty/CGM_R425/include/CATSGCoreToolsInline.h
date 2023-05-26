#ifndef  INLINE

// COPYRIGHT DASSAULT SYSTEMES  2009

#if defined(_WINDOWS_SOURCE) && defined(_MSC_VER) && _MSC_VER>1300
#define  INLINE     __forceinline
#else
#define  INLINE     inline
#endif

#endif
