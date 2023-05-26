#ifndef CATOmbRelationRerouteTransaction_H
#define CATOmbRelationRerouteTransaction_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U3
 */

 // BSFBuildtimeData
#include "CATIAV5Level.h"
 // System
#include "CATCollec.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATOmbOutputRelation;
class CATOmbRelationContext;
class CATComponentId;
class CATLISTP(CATOmbElementaryRerouteTransaction);

/**
 * Class to store a transaction affecting a relation during a reroute
 */
#if defined(CATIAR425)
#include "CATOmxSharable.h"
class ExportedByCATObjectModelerBase CATOmbRelationRerouteTransaction : public CATOmxSharable
#else
#include "CATOmbUnknown.h"
class ExportedByCATObjectModelerBase CATOmbRelationRerouteTransaction : public CATOmbUnknown
#endif
{
public:
  /**
   * @param RELATION
   *    The transaction applies to a relation
   * @param CONTEXT
   *    The transaction applies to a context
   */
  enum TransactionType { RELATION, CONTEXT };

  /**
   * Returns the type of the transaction
   * @returns
   *    A type
   */
  virtual CATOmbRelationRerouteTransaction::TransactionType GetType() const = 0;

  /**
   * Returns the relation to which the transaction applies
   * @return
   *		The relation
   */
  virtual const CATOmbOutputRelation & GetRelation() const = 0;

  /**
   * Returns the relation to which the transaction applies
   * @return
   *		The relation
   */
  virtual const CATOmbRelationContext & GetContext() const = 0;

  /**
   * Returns the new target of the relation
   * @return
   *    The new target
   */
  virtual const CATComponentId & GetNewTarget() const = 0;
};

#endif
