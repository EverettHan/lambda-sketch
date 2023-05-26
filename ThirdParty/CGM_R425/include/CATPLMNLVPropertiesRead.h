// COPYRIGHT Dassault Systemes 2021
//===================================================================
//
// CATPLMNLVPropertiesRead.h
//
//===================================================================
// June 2021  Creation: JSL7
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMNLVPropertiesRead_H
#define CATPLMNLVPropertiesRead_H

#include "CATPLMServicesItf.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxCollecManager.h"
#include "CATOmxArray.h"
#include "CATPLMOmxCollections.h"

class ExportedByCATPLMServicesItf CATPLMNLVPropertiesRead
{
public:

  CATPLMNLVPropertiesRead();
  ~CATPLMNLVPropertiesRead();
  CATPLMNLVPropertiesRead(const CATPLMNLVPropertiesRead &);
  CATPLMNLVPropertiesRead & operator =(const CATPLMNLVPropertiesRead &);

  void SetIntentE();
  void SetIntentI();
  void SetIntentS();
  CATOmxArray<CATUnicodeString> GetListIntent() const;


private:

  CATOmxArray<CATUnicodeString> _listIntent;
};

#endif
