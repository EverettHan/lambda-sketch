#ifndef CATIComTubeSSO_h
#define CATIComTubeSSO_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"

extern "C" ExportedByCATComSidl const IID IID_CATIComTubeSSO ;

class ExportedByCATComSidl CATIComTubeSSO :public IUnknown 
{
public:
  virtual HRESULT BeforeSend(void **oBuff,unsigned int *oLen)=0;
  virtual HRESULT ValidateSend(void *iBuff,unsigned int iLen)=0;
  virtual HRESULT BeforeReply(void **oBuff,unsigned int* oLen)=0;
  virtual HRESULT ValidateReply(void *iBuff,unsigned int iLen)=0;
  virtual HRESULT DeleteBuffer(void *iBuff)=0;
};

CATDeclareHandler( CATIComTubeSSO , IUnknown );

#endif
