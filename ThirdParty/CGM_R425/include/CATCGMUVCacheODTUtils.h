// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVCacheODTUtils.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Feb 2012  Creation: MPX
//===================================================================

#ifndef CATCGMUVCacheODTUtils_H
#define CATCGMUVCacheODTUtils_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"


class ExportedByTessellateCommon CATCGMUVCacheODTUtils
{
public:
  static inline CATBoolean GetOptionStreamEmptyAttr();
  static inline void SetOptionStreamEmptyAttr(CATBoolean iVal);

private:
  static CATBoolean _OptionStreamEmptyAttr;
};

inline CATBoolean 
CATCGMUVCacheODTUtils::GetOptionStreamEmptyAttr()
{
  return _OptionStreamEmptyAttr;
}

inline void 
CATCGMUVCacheODTUtils::SetOptionStreamEmptyAttr(CATBoolean iVal)
{
  _OptionStreamEmptyAttr = iVal;
}

#endif
