#ifndef CATOmbRerouteRequest_H
#define CATOmbRerouteRequest_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"
#include "CATCollec.h"
#include "CATBoolean.h"
#include "CATOmxList.h"
#include "CATBaseUnknown.h"

class CATOmbOutputRelation;
class CATOmbRelationContext;
class CATOmbRerouteRequestImpl;
class CATLISTP(CATOmbOutputRelation);
class CATComponentId;

/**
 * Class used to define a reroute request, i.e. a set of relation and contexts, along with optionnal
 * explicit targets.
 */
class ExportedByCATObjectModelerBase CATOmbRerouteRequest
{
public:
  /**
   * Creates an empty request
   */
  CATOmbRerouteRequest();

  /** @nodoc */
  ~CATOmbRerouteRequest();

  /**
   * Add an assisted reroute to this request.
   * @param ipRelation
   *	     A relation to reroute.
   */
  CATOmbRerouteRequest &AddAssistedReroute(CATOmbOutputRelation *ipRelation);

  /**
   * Add an assisted reroute to this request.
   * @param iRelations
   *	     A list of relations to reroute.
   */
  CATOmbRerouteRequest &AddAssistedReroute(CATLISTP(CATOmbOutputRelation) &iRelations);

  /**
   * Add an assisted reroute to this request.
   * @param ipContext
   *	     A context to reroute.
   */
  CATOmbRerouteRequest &AddAssistedReroute(CATOmbRelationContext *ipContext);

  /**
   * Add an explicit reroute to this request.
   * @param ipRelation
   *	     A relation to reroute.
   * @param iTarget
   *      The new target
   *
   */
  CATOmbRerouteRequest& AddExplicitReroute(CATOmbOutputRelation* ipRelation, CATComponentId& iTarget);
  CATOmbRerouteRequest& AddExplicitReroute(CATOmbOutputRelation* ipRelation, const CATOmxList<CATBaseUnknown>& iTarget);

  /**
   * Add an explicit reroute to this request.
   * @param ipContext
   *	     A context to reroute.
   * @param iTarget
   *      The new target
   * @param iUseMinimalContext
   *      Automatically truncate context to minimum
   */
  CATOmbRerouteRequest &AddExplicitReroute(CATOmbRelationContext *ipContext, CATComponentId &iTarget, CATBoolean iUseMinimalContext = TRUE);

  /** @nodoc */
  inline CATOmbRerouteRequestImpl& GetLetter() { return m_letter; }

  /**
   * Returns True if there are no assisted reroute requests or explicit reroute requests in the object,
   * False otherwise.
   */
  CATBoolean IsEmpty();

private:
  CATOmbRerouteRequestImpl& m_letter;
};

#endif
