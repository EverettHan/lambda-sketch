#ifndef CATPLMAggregationFilter_H 
#define CATPLMAggregationFilter_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/

// System
#include "CATUnicodeString.h"
// CATPLMIdentificationAccess
#include "CATPLMCoreType.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeToolsDefinitions.h"
// CATPLMIdentification
#include "ExportedByCATPLMTos.h"

/**
* aggregation filter.
*/
class CATPLMAggregationFilter
{
  int m_coreTypes;
  bool m_treeOrder;
  bool m_destroyedComponents;
  bool m_hasDiscipline; //compatv4, allow creating a filter that keeps only objects with no discipline...
  CATUnicodeString m_discipline;
  CATPLMTypeH m_type;
public:
  inline CATPLMAggregationFilter(int iCoreTypes = TYPTRP_Component) :m_coreTypes(iCoreTypes), m_treeOrder(false), m_destroyedComponents(false), m_hasDiscipline(false) {}

  /**
  * Filtering with a list of core type (Default value is TYPTRP_Component)
  */
  void SetCoreTypesFilter(int iCoreTypes) { m_coreTypes = iCoreTypes; }

  /**
  * Deleted components will be integrated to the result (Default value is FALSE)
  */
  void SearchDestroyedComponents() { m_destroyedComponents = true; }

  /**
   * Activate tree order
   */
  void WithTreeOrder() { m_treeOrder = true; }

  /**
   * Activate filter on discipline, probably obsolete
   */
  void WithDiscipline(const CATUnicodeString& iDiscipline) { m_discipline = iDiscipline; m_hasDiscipline = true; }

  /**
   * Activate filter on type.
   *
   * @param iType : searched type (or derived from it)
   */
  void WithSingleTypeFilter(const CATPLMTypeH& iType) { m_type = iType; }

  friend class CATOxEntity;
};

#endif
