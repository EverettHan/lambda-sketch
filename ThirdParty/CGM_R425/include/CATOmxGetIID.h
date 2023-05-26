#ifndef __CATOmxGetIID_H
#define __CATOmxGetIID_H

#include "CATOmxPortability.h"

/**return IID associated to interface T. Can be overriden to get rid of link to dll defining T::ClassId*/
template<class T>
inline const IID& CATOmxGetIID(const T*) { return T::ClassId(); }

#endif
