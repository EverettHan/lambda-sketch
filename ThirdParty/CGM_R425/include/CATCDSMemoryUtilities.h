// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//
// CATCDSMemoryUtilities:
//   Memory allocation functions.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jun 2007  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSMemoryUtilities_h
#define CATCDSMemoryUtilities_h

#ifdef _AIX_SOURCE
#define SIZEOF(a) (int(sizeof(a) / sizeof(a[0])))
#else
template<class T, unsigned int N>
char (&CATCDSSizeOf(T (&iArray)[N]))[N];

#define SIZEOF(a) sizeof(CATCDSSizeOf(a))
#endif

#endif
