#ifndef CATOmbRelationTransferViolation_H
#define CATOmbRelationTransferViolation_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATOmbRelationTransferSubRelationship.h"
#include "CATUnicodeString.h"
#include "CATPLMID.h"

 /**
  * Class that defines a listener to raise PLMIntegrity violation.
  */
class CATOmbRelationTransferViolation
{
  CATUnicodeString                      _ShortMessage;
  CATPLMID                              _PLMID;
  CATOmbRelationTransferSubRelationship _SubRelationship;
public:
  CATOmbRelationTransferViolation(const CATUnicodeString& shortMessage, const CATPLMID& id, const CATOmbRelationTransferSubRelationship& subRelationship) :
    _ShortMessage(shortMessage),
    _PLMID(id),
    _SubRelationship(subRelationship)
  {}

  /**
  * Returns short message
  * @return
  *      Short message
  */
  const CATUnicodeString & GetShortMessage() const { return _ShortMessage; }

  /**
  * Returns component owner
  * @return
  *      Component owner of the sub relationship
  */
  const CATPLMID & GetPLMID() const { return _PLMID; }

  /**
  * Returns sub relationship if violation in context of
  * @return
  *      The sub relationship
  */
  const CATOmbRelationTransferSubRelationship & GetSubRelationship()const { return _SubRelationship; }
};

#endif

