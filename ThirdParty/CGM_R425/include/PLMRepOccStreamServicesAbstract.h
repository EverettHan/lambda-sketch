#ifndef PLMRepOccStreamServicesAbstract_H
#define PLMRepOccStreamServicesAbstract_H

#include "PLMRepLoadMode.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATPLMOccurrenceWrapper;

class PLMRepOccStreamServicesAbstract
{
private:
  friend class PLMRepStreamServices;
  virtual HRESULT GetLoadedData(CATPLMOccurrenceWrapper & iOccWrap, CATBaseUnknown *&opLoadedData)=0;
  virtual HRESULT ComputeLoadingMode(CATPLMOccurrenceWrapper & iOccWrap, PLMRepLoadMode & oLoadMode)=0;
  virtual HRESULT ChangeLoadingMode(CATPLMOccurrenceWrapper & iOccWrap, PLMRepLoadMode iNewMode)=0;
  virtual HRESULT CreateApplicativeContainer(CATPLMOccurrenceWrapper & iOccWrap, CATBaseUnknown *&opApplicativeContainer, const CATIdent iContainerType, const IID & iIID, const CATIdent iContainerSuperType, const CATUnicodeString & iIdentifier)=0;
  virtual HRESULT RetrieveApplicativeContainer(CATPLMOccurrenceWrapper & iOccWrap, const CATUnicodeString & iIdentifier, const IID & iIID, CATBaseUnknown *&opApplicativeContainer)=0;
};
#endif
