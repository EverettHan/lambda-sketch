#ifndef CATOmbRelationTransferListener_H
#define CATOmbRelationTransferListener_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U3
 */
#include "CATOmbRelationTransfer.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"

class CATOmbRelationTransferViolation;

/**
 * Class that defines a listener to raise PLMIntegrity violation.
 */
class CATOmbRelationTransferListener : public CATBaseUnknown
{
public:

  /**
  * Event raised when violation incoming
  */
  virtual void OnViolation(CATOmbRelationTransferViolation & iTransferViolation) = 0;
};

#endif

