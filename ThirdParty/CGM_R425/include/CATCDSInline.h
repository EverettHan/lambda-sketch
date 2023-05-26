#ifndef CATCDSInline_h
#define CATCDSInline_h

#ifndef  CATCDSInline
#if defined(_WINDOWS_SOURCE) && defined(_MSC_VER) && _MSC_VER >= 1400
#define  CATCDSInline     __forceinline
#else
#define  CATCDSInline     inline
#endif
#endif

#endif
