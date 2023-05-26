#ifndef _VPMIDicGlobalFunctions_h
#define _VPMIDicGlobalFunctions_h

#include "CATUnicodeString.h"

#include "VPMIDicMaskedAttributeServices.h"


class ExportedByMaskedAttributeItf VPMIDicGlobalFunctions 
{

public:
  static VPMIDicMaskedAttributeServices_var GetMaskedAttributeServices();

private:
  static VPMIDicMaskedAttributeServices_var _maskedAttributeServices;

}; /* _VPMIDicGlobalFunctions_h */ 

#endif 
