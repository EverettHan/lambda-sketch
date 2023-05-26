#ifndef __CATOmxUTF8String_util_h__
#define __CATOmxUTF8String_util_h__
#include "CATOmxUTF8String.h"
#include <stdio.h>
/** usefull function to migrate old code usiing char **/
inline FILE *fopen(const CATOmxUTF8String &iName,const char *fmode) { return fopen(iName.asChar(),fmode); }
inline void strcpy(CATOmxUTF8String &iDst,const char *iSrc) { iDst=iSrc; }
inline int strlen(const CATOmxUTF8String &iDst) { return iDst.length(); }
inline int strcmp(const CATOmxUTF8String &iDst,const CATOmxUTF8String &iSrc) { return CATOmxUTF8String::StrCompare(iDst,iSrc); }
inline int strcmp(const CATOmxUTF8String &iDst,const char *iSrc) { return strcmp(iDst.asChar(),iSrc); }
#endif
