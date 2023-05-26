#ifndef CATIAMemoryWarningSettingAtt_h
#define CATIAMemoryWarningSettingAtt_h
/*====================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
 *===================================================*/

#include "CATCORBABoolean.h"
#include "CAT_VARIANT_BOOL.h"
#include "CATBSTR.h"
#include "CATIASettingController.h"
#include "JS0ERROR.h"

extern ExportedByJS0ERROR  IID IID_CATIAMemoryWarningSettingAtt;

class ExportedByJS0ERROR  CATIAMemoryWarningSettingAtt : public CATIASettingController
{
    CATDeclareInterface;

public:

    virtual HRESULT __stdcall get_ActivationState(CAT_VARIANT_BOOL & oActivationState)=0;

    virtual HRESULT __stdcall put_ActivationState(CAT_VARIANT_BOOL iActivationState)=0;

    virtual HRESULT __stdcall SetActivationStateLock(CAT_VARIANT_BOOL iLocked)=0;

    virtual HRESULT __stdcall GetActivationStateInfo(CATBSTR & AdminLevel, CATBSTR & oLocked, CAT_VARIANT_BOOL & oModified)=0;

    virtual HRESULT __stdcall get_UsageLimit(CATLONG & oMaxLimit)=0;

    virtual HRESULT __stdcall put_UsageLimit(CATLONG iMaxLimit)=0;

    virtual HRESULT __stdcall SetUsageLimitLock(CAT_VARIANT_BOOL iLocked)=0;

    virtual HRESULT __stdcall GetUsageLimitInfo(CATBSTR & AdminLevel, CATBSTR & oLocked, CAT_VARIANT_BOOL & oModified)=0;


};

CATDeclareHandler(CATIAMemoryWarningSettingAtt, CATIASettingController);

#include "CATBaseDispatch.h"
#include "CATBaseUnknown.h"
#include "CATIABase.h"
#include "CATSafeArray.h"
#include "CATVariant.h"
#include "IDispatch.h"
#include "IUnknown.h"


#endif
