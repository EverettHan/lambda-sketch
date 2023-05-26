#ifndef _CATPLMStreamingContext_H
#define _CATPLMStreamingContext_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATUuid;

class ExportedByCATPLMTos CATPLMStreamingContext
{
public:

  enum TransactionType {Propagate=0, LocalSave=1, Export=2, Unload=3, ExportForCloning=4, ExportForCATDWC=5};

  /**
  * @param iContext [in]
  *   The context the streams must be created for.
  * @param iTransUUID [in]
  *   The UUID of the streaming transaction.
  */
  CATPLMStreamingContext (TransactionType iTransType, const CATUuid & iTransId);
  ~CATPLMStreamingContext();

  TransactionType GetTransactionType() const {return _TransType;}

  const CATUuid * GetTransactionId() const {return _TransId;} 

private:

  CATPLMStreamingContext (CATPLMStreamingContext &);
  CATPLMStreamingContext& operator=(CATPLMStreamingContext&);

  TransactionType  _TransType;
  const CATUuid  * _TransId;
};

#endif
