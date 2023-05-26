// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSMapForward:
//
// For inclusion in header files
//
//=============================================================================
//  Jan 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSMapForward_h
#define CATCDSMapForward_h

#include "CATCDSMapSpecializations.h"

#ifndef CPP11_AVAILABLE
namespace std {
  template<class T>
  struct hash;
}
#else
#include <functional>
#endif

template<class Key, class Value, class Hash = typename std::hash<typename CDSStorageType<Key>::type> > 
class CATCDSMap;

#endif
