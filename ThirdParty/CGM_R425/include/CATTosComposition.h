#ifndef CATTosComposition_H
#define CATTosComposition_H

#include "ExportedByCATPLMTos.h"
#include "CATComponentId.h"

class CATOxEntity;

namespace CATTosComposition
{
  /**
   * return true if
   *   rel is a compositional relation and its target is is composed/maybecomposed
   *   rel is a rep instance and its target has V_isOnceInstantiable==true
   */
  ExportedByCATPLMTos bool IsACompositionRelation(const CATComponentId& rel);
  bool IsACompositionRelation(const CATOxEntity& rel);

  /**
   * return composer and optional composition relation
   * are supported
   * port/connexion             => oComposer = V_Owner, oCompositionalRelation = null
   * once instanciable rep      => oComposer = ref,     oCompositionalRelation = unique rep instance
   * (maybe)composed components
   *
   * @return
   *  S_FALSE: object is not composed
   *  S_TOS_M1COMPOSITION
   *  S_TOS_PORTORCONNECTION_COMPOSITION
   *  S_TOS_ONCEINSTANCIABLE_COMPOSITION
   *  E_TOS_NO_COMPOSER
   *  E_TOS_SEVERAL_COMPOSERS
   */
  ExportedByCATPLMTos HRESULT GetComposer(const CATComponentId& iComposed, CATComponentId& oCompositionalRelation, CATComponentId& oComposer);
  inline HRESULT GetComposer(const CATComponentId& iComposed, CATComponentId& oComposer)
  {
    CATComponentId relation;
    return GetComposer(iComposed, relation, oComposer);
  }
  inline CATComponentId GetComposer(const CATComponentId& iComposed)
  {
    CATComponentId composer;
    (void)GetComposer(iComposed, composer);
    return composer;
  }
}


#endif
