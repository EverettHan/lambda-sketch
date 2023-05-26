#ifndef CATICollectProviders_H
#define CATICollectProviders_H

/**
* @level Private
* @usage U3
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"

class CATIVisitor;

extern ExportedByCATPLMModelerBaseInterfaces IID IID_CATICollectProviders ;

class ExportedByCATPLMModelerBaseInterfaces CATICollectProviders : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * @nodoc 
  */
  virtual HRESULT AppendProvidersForIID(const CATBaseUnknown_var& collector, const char* providerType, const IID& iid, CATIVisitor* iVisitor) = 0;

};

CATDeclareHandler(CATICollectProviders, CATBaseUnknown);

#endif
