#ifndef CATPLMDisciplineManagement_H 
#define CATPLMDisciplineManagement_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
#include "CATBaseUnknown.h"
class CATComponentId;
class CATUnicodeString;

class CATPLMDisciplineManagement
{
public:
  inline static HRESULT InvalidDiscipline(const CATComponentId& ) {return S_OK;}

};

#endif
