/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxCompare_H
#define __CATOmxCompare_H

#include <string.h>

/**
 * A generic 'strcmp like' comparison function
 */
template<typename T>
inline int CATOmxCompare(const T& a, const T& b)
{
  if (a < b)
    return -1;
  else if (a > b)
    return 1;
  else
    return 0;
}

/** override for 'const char*' */
template<>
inline int CATOmxCompare<const char*>(const char*const& a, const char*const& b) { return strcmp(a, b); }

#include "CATUnicodeString.h"
/** override for 'CATUnicodeString' */
template<>
inline int CATOmxCompare<CATUnicodeString>(const CATUnicodeString& a, const CATUnicodeString& b) { return a.SortCompare(b); }


#endif
