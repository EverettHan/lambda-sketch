#ifndef CGMObjULong_H
#define CGMObjULong_H
//---------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES  2002
//---------------------------------------------------
#include "CATDataType.h"
#include "CATCGMNewArray.h"
class CATCGMObject;
#include "CGMV5Interop.h"

class ExportedByCGMV5Interop  CGMObjULong
{
public:
  CGMObjULong(CATCGMObject *Obj,  CATULONG32  Value);
  ~CGMObjULong();
  CATCGMNewClassArrayDeclare;  
  
  CATCGMObject       *const _Obj;
  CATULONG32        _Value;
};

#endif
