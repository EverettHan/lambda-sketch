/**
 *  services to stream / unstream PLMQuery to/from XML
 */

#ifndef CATPLMXMLQueryServices_H
#define CATPLMXMLQueryServices_H
#include "CATErrorDef.h"
#include "CATPLMServicesItf.h"
#include "CATPLMQueryFilterEnum.h"

class CATPLMSpecDefinitionIterativeFilter;
class CATPCTExpand;
class CATIPLMFilterCriteria;
class CATPLMType;
class ExportedByCATPLMServicesItf CATPLMXMLQueryServices
{
  friend class CATPLMSpecDefinitionIterativeFilter;  // real client
  friend class CATPCTExpand;                         // testing purpose

private :
  static HRESULT MakeCriteriaIterative(CATIPLMFilterCriteria* pCriteria, Iterative::Mode iMode, CATPLMType *iType);
};

#endif
