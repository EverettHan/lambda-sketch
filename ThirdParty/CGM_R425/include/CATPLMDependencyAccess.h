#ifndef CATPLMDependencyAccess_H 
#define CATPLMDependencyAccess_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMTos.h"
#include "CATComponentId.h"
#include "CATPLMDependencyType.h"
#include "CATOmxIter.h"

struct CATPLMDependency
{
  CATPLMDependencyType Type;
  CATComponentId Target;
};
/**
* Dependencies access
*/
namespace CATPLMDependencyAccess
{
  /**
  * Visit direct dependencies
  */
  ExportedByCATPLMTos CATOmxIter<const CATPLMDependency> GetDirectDependencies(const CATComponentId & iCID);

  /**
  * Visit inverse dependencies
  */
  ExportedByCATPLMTos CATOmxIter<const CATPLMDependency> GetInverseDependencies(const CATComponentId & iCID);

  /**
   * scan direct dependencies of iDuplicateObject for an entry matching iDependencyType
   */
  ExportedByCATPLMTos CATComponentId GetOriginalObject(const CATComponentId& iDuplicateObject, CATPLMDependencyType iDependencyType);
};

#endif
