#ifndef CATProxyTransactionSearch_H
#define CATProxyTransactionSearch_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Protected
 * @usage U1
 */
#include "ExportedByCATPLMTos.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATProxyTransaction.h"
#include "CATProxyTransactionPurpose.h"

class CATComponentId;


class CATProxyTransactionSearch
{
public:
  /** obsolete */
  inline CATProxyTransactionSearch() = default;
  inline CATProxyTransactionSearch(const CATComponentId&) {}

  /**
  * Check if transaction is opened
  *
  * @param iPurpose
  *   Purpose of the transaction
  *
  * @return
  *   TRUE a transaction has been found
  *   FALSE no transaction found
  **/
  static ExportedByCATPLMTos CATBoolean IsUnderTransaction(const CATProxyTransactionPurpose iPurpose);

  static ExportedByCATPLMTos CATBoolean IsSwitchAuthorized();
};

#endif
