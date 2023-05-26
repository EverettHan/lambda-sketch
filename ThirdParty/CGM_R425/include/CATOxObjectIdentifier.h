#ifndef __CATOxObjectIdentifier__
#define __CATOxObjectIdentifier__
/**
* @level Private
* @usage U1
*/

#include "CATIAdpType.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmxSR.h"

class CATOxObjectIdentifier
{
public:
  CATLISTV(CATUnicodeString) _ValueList;
  CATUnicodeString _KeyPhysID;
  CATOmxSR<CATIAdpType> _Type;
};

#endif 
