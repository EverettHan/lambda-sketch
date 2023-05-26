#ifndef __CATOmxSignedIntIncHelper_h__ 
#define __CATOmxSignedIntIncHelper_h__


// ObjectModelerCollection
#include "CATOmxCxxPortability.h"

// C++03 version, compatible with AIX.
// C++11 & later version could be fun to write, with a requirement on an unsigned type.
template<typename T> inline T & unsigned_like_preinc(T &) OMX_Cxx11_DELETE; // Not defined, will cause errors (link on AIX) with any usage with a type that is not int.
template<> inline int & unsigned_like_preinc(int & v) { return reinterpret_cast<int &>(++reinterpret_cast<unsigned int &>(v)); }
template<> inline long & unsigned_like_preinc(long & v) { return reinterpret_cast<long &>(++reinterpret_cast<unsigned long &>(v)); }


#endif // __CATOmxSignedIntIncHelper_h__
