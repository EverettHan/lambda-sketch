
#ifndef __CATIUseEntity_h__
#define __CATIUseEntity_h__


// COPYRIGHT DASSAULT SYSTEMES 2009  

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "DataCommonProtocolUse.h"
#include "CATBaseUnknown.h"

extern ExportedByDataCommonProtocolUse IID IID_CATIUseEntity;

/**
 * Generic interface implemented by all objects on which DataCommonProtocol services can operate.
 * @see DataCommonProtocolServices
 */
class ExportedByDataCommonProtocolUse CATIUseEntity : public CATBaseUnknown
{
  CATDeclareInterface;
};

CATDeclareHandler(CATIUseEntity, CATBaseUnknown);


#endif // __CATIUseEntity_h__
