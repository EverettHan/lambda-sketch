/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2001

#ifndef CATIContPersistStorage_H
#define CATIContPersistStorage_H
//
/**
 * @level Private
 * @usage U3
 */

#include "CATIPersistStorage.h"
#include "AD0XXBAS.h"
#include "CATBoolean.h"
//
class CATStorage;


extern ExportedByAD0XXBAS IID IID_CATIContPersistStorage ;


class ExportedByAD0XXBAS CATIContPersistStorage : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  virtual HRESULT LoadProperties (CATStorage* pStg) = 0; 
  
};

#endif
