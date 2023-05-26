
#ifndef IVISUIConfiguration_H
#define IVISUIConfiguration_H

//COPYRIGHT DASSAULT SYSTEMES 2012

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class IVISUIInteractionContext;

extern ExportedByIVInterfaces IID IID_IVISUIConfiguration;

/**
* Interface representing the configuration of a SUI scenario.
*/
class ExportedByIVInterfaces IVISUIConfiguration: public CATBaseUnknown
{
  CATDeclareInterface;

public:
};

CATDeclareHandler(IVISUIConfiguration, CATBaseUnknown);
//------------------------------------------------------------------

#endif
