//===================================================================
// COPYRIGHT Dassault Systemes 2018/03/23
//===================================================================
// CATIParamAsStringCheck.h
// Header definition of class CATIParamAsStringCheck
//===================================================================
//
// Usage notes:
//
//===================================================================

//===================================================================
#ifndef CATIParamAsStringCheck_H
#define CATIParamAsStringCheck_H

#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATLifSpecs.h"
#include <CATICkeParm.h>
#include "CATICkeRelationForwards.h"
#include "CATIParmPublisher.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs  IID IID_CATIParamAsStringCheck;
#else
extern "C" const IID IID_CATIParamAsStringCheck;
#endif

class ExportedByCATLifSpecs CATIParamAsStringCheck : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  // Function that checks the parameter value from a string
  virtual void CheckVIDStringParameterForNotification(CATUnicodeString& iTextValue, const CATICkeParm_var& _spParm, const CATCkeFrameStyle iStyle, const CATIParmPublisher_var &Root, CATBoolean &obParameterValueChanged) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIParamAsStringCheck, CATBaseUnknown);

#endif
