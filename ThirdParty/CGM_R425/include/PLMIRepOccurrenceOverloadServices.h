#ifndef PLMIRepOccurrenceOverloadServices_H
#define PLMIRepOccurrenceOverloadServices_H

#include "CATPLMModelerBaseInterfaces.h"

#include "CATBaseUnknown.h"
#include "PLMRepLoadMode.h"

class CATUnicodeString;
class CATPLMOccurrenceWrapper;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerBaseInterfaces IID IID_PLMIRepOccurrenceOverloadServices ;
#else
extern "C" const IID IID_PLMIRepOccurrenceOverloadServices ;
#endif

//------------------------------------------------------------------

class ExportedByCATPLMModelerBaseInterfaces PLMIRepOccurrenceOverloadServices : public CATBaseUnknown
{
public:
  CATDeclareInterface;
private:
  friend class PLMRepOccurrenceOverloadServices;
	virtual HRESULT CreateOverloadingStream(CATPLMOccurrenceWrapper & iOccWrap)=0;
	virtual HRESULT RemoveOverloadingStream(CATPLMOccurrenceWrapper & iOccWrap)=0;
  virtual HRESULT IsStreamOverloaded(CATPLMOccurrenceWrapper & iOccWrap, CATBoolean iCheckSubOverload,
    CATBoolean & oOverload, CATBoolean & oSubOverload, CATPLMOccurrenceWrapper & oSubOverloadedOccWrap)=0;
};

//------------------------------------------------------------------
#endif
