#ifndef __CATPLMAdpBackdoor__h__
#define __CATPLMAdpBackdoor__h__

/**
* @level Private
* @usage U3
*/

#include "CATPLMServicesItf.h"

#include "CATBooleanDef.h"

/**
* @nodoc 
* Class used to activate a global development launched by the PLMAdapter.
*/
class ExportedByCATPLMServicesItf CATPLMAdpBackdoor
{
public:
  friend class CATXPLMDataSetManager;
  /**
  * @nodoc
  * Forces the expand with all substitutes.
  */
  static CATBoolean _ForceAllSubstitute;
};


#endif
