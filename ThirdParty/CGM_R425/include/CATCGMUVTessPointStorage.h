// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessPointStorage.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessPointStorage_H
#define CATCGMUVTessPointStorage_H

#include "ExportedByTessellateCommon.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATMathPoint;

class ExportedByTessellateCommon CATCGMUVTessPointStorage
{
public :
  CATCGMUVTessPointStorage();
  virtual ~CATCGMUVTessPointStorage();

public:
  //Face Edge Curve Storage
  virtual HRESULT StorePoint(const CATMathPoint& iPosition)=0;
};

#endif
