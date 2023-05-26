#ifndef PLMIOccurrenceChildrenService_H
#define PLMIOccurrenceChildrenService_H

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"
class CATIPLMNavOccurrence;

extern ExportedByCATPLMModelerBaseInterfaces const IID IID_PLMIOccurrenceChildrenService;

/**
 * this class must be implemented on the late type PLMIOccurrenceChildrenServiceFor<name of the PLM type>
 * it is meant to be implemented by the modeler which defines a PLM type
 * it must never be called directly
 */
class ExportedByCATPLMModelerBaseInterfaces PLMIOccurrenceChildrenService : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
   * tell if a component should be visible in a given occurrence tree
   * @param iPLMComponent
   *   an aggregated PLM component (for example a PLMConnection, for counter-example not a PLMReference)
   *   which does not participate to occurrence tree (by implementing 'CATIFaceletFactory')
   * @param iParentOccurrence
   *   the parent occurrence
   *   GetRelatedReference on this occurrence returns the father of iPLMComponent
   * @return
   *   true:
   *     the component is considered part of the occurrence tree
   *   false:
   *     the component is excluded from occurrence tree
   *     as a consequence it will be excluded from save scope or life cycle graph computed for this occurrence tree
   */
  virtual bool IsComponentVisibleInOccurrenceTree(CATBaseUnknown& iPLMComponent, CATIPLMNavOccurrence& iParentOccurrence) = 0;
};

#endif
