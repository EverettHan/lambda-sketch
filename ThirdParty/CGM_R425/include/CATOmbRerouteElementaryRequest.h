#ifndef CATOmbRerouteElementaryRequest_H
#define CATOmbRerouteElementaryRequest_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U3
 */

#include "IUnknown.h"
#include "CATObjectModelerBase.h"

class CATOmbOutputRelation;
class CATOmbRelationContext;
class CATComponentId;

/**
 * Class used to define an elementary reroute request provided by the system during
 * the reroute to allow the user to link: initial request <-> CATOmbRerouteAssistant
 */
class ExportedByCATObjectModelerBase CATOmbRerouteElementaryRequest
{
public:
  /** @nodoc */
  virtual ~CATOmbRerouteElementaryRequest() {}

  /**
   * Type of request
   * @param RELATION
   *    A reroute was requested on a relation. GetManipulatedRelation returns a valid relation
   * @param CONTEXT
   *    A reroute was request on a context. GetManipulatedContext returns a valid context
   */
  enum ManipulatedObjectType { RELATION, CONTEXT };

  /**
   * Returns the manipulated object type
   * @return
   *    The type
   */
  virtual ManipulatedObjectType GetManipulatedObjectType() const = 0;

  /**
   * Returns the manipulated relation
   * @param opRelation
   *    The returned relation
   * @return
   *    S_OK: opRelation is valuated
   *    E_FAIL: the request isn't about a relation
   */
  virtual HRESULT GetManipulatedRelation( CATOmbOutputRelation *&opRelation ) const = 0;

  /**
   * Returns the manipulated context
   * @param opContext
   *    The returned context
   * @return
   *    S_OK: opContext is valuated
   *    E_FAIL: the request isn't about a context
   */
  virtual HRESULT GetManipulatedContext( CATOmbRelationContext *&opContext ) const = 0;

  /**
   * If the request was explicit, i.e. the user provided a target to reroute to, this methods
   * returns this target.
   * @param oTarget
   *    The target
   * @return
   *    S_OK: oTarget is valuated
   *    S_FALSE: an assisted reroute (without explicit target) was requested
   */
  virtual HRESULT HasExplicitTarget( CATComponentId &oTarget ) const = 0;
};

#endif
