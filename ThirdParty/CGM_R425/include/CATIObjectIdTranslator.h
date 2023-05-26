#ifndef CATIObjectIdTranslator_h
#define CATIObjectIdTranslator_h
// COPYRIGHT DASSAULT SYSTEMES 2013
#include "JS0STDLIB.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0STDLIB  IID IID_CATIObjectIdTranslator;
#else
extern "C" const IID IID_CATIObjectIdTranslator;
#endif

class ExportedByJS0STDLIB CATIObjectIdTranslator : public CATBaseUnknown
{
  CATDeclareInterface;
  public :
  virtual HRESULT PushPLMIdInSession(const char *iObjectId)=0;
};


#endif

