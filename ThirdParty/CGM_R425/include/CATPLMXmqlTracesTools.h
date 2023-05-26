//===================================================================
// COPYRIGHT Dassault Systemes 2018/01/26
//===================================================================
// CATPLMXmqlTracesTools.cpp
// Header definition of class CATPLMXmqlTracesTools
//===================================================================
//
// Usage notes:
// Tools to dump common objects/information in Oms Xml Traces.
//
//===================================================================
//  2018/01/26 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMXmqlTracesTools_H
#define CATPLMXmqlTracesTools_H

#include "CATPLMServicesItf.h"
#include "CATIPLMError.h"

class ExportedByCATPLMServicesItf CATPLMXmqlTracesTools
{
public:
  static void DumpConnectedProviders();
  static void DumpPLMError(CATIPLMError& iError, const CATUnicodeString& iErrorMessage);

private:
  CATPLMXmqlTracesTools();
  virtual ~CATPLMXmqlTracesTools();

  CATPLMXmqlTracesTools (CATPLMXmqlTracesTools &);
  CATPLMXmqlTracesTools& operator=(CATPLMXmqlTracesTools&);
};

#endif
