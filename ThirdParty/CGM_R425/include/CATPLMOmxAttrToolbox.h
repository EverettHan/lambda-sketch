// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMOmxAttrToolbox.h
// Header definition of CATPLMOmxAttrToolbox
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// November 2009  Creation: EPB
//===================================================================

/**
 * @level Protected
 * @usage U1
 */

// U1:        Concrete class: use as is only. C++ usage 
// Protected: The header doc is only generated in the PLMInf web. All frameworks authorized to use the framework containing the header can use it.


#ifndef CATPLMOmxAttrToolbox_H
#define CATPLMOmxAttrToolbox_H

#include "CATPLMServicesItf.h"

#include "AttrTypes.h"
#include "CATPLMOmxAttr.h"

class ExportedByCATPLMServicesItf CATPLMOmxAttrToolbox
{
public:
public:
  static HRESULT Convert(CATPLMOmxAttr iOmxAttr,AttrTypes& oAttrTypes);

  static HRESULT Convert(AttrTypes iAttrTypes,CATPLMOmxAttr& oOmxAttr);
};

#endif
