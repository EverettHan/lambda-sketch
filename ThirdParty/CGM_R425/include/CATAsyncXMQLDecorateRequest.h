//===================================================================
// COPYRIGHT Dassault Systemes 2019/03/05
//===================================================================
// Header definition of class CATAsyncXMQLDecorateRequest
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2019/03/05 Creation: EPB
//===================================================================

#ifndef CATAsyncXMQLDecorateRequest_H
#define CATAsyncXMQLDecorateRequest_H

#include "CATPLMxMQL.h"

#include "CATPLMRepositoryName.h"

#include "CATSysErrorDef.h"

class CATIPLMExpandResultHandler;
class CATIPLMQueryFilter;
class CATAsyncXMQLExpandRequest;

class ExportedByCATPLMxMQL CATAsyncXMQLDecorateRequest
{
public:
  CATAsyncXMQLDecorateRequest(const CATPLMRepositoryName& iRepo = CATPLMRepositoryName_Null);

  ~CATAsyncXMQLDecorateRequest();

  CATAsyncXMQLDecorateRequest(const CATAsyncXMQLDecorateRequest& obj);

  CATAsyncXMQLDecorateRequest& operator=(const CATAsyncXMQLDecorateRequest& obj);

  HRESULT Build(CATIPLMQueryFilter* ipQF);

  HRESULT Expand(CATIPLMExpandResultHandler * iopExpandHandler);

private:
  CATPLMRepositoryName _repo;
  CATAsyncXMQLExpandRequest* _pRequest;
};

#endif
