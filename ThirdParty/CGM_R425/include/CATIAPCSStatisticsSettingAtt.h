/*====================================================
 *  (c) 1999 Dassault Systemes. All rights reserved  =
 *     Generated by CNextBackEnd version 0.1 on      =
 *===================================================*/

#ifndef CATIAPCSStatisticsSettingAtt_h
#define CATIAPCSStatisticsSettingAtt_h

#include "CATCORBABoolean.h"
#include "CAT_VARIANT_BOOL.h"
#include "CATIAGeneralStatisticsSettingAtt.h"

#ifndef ExportedByJS03TRA
#if defined(__JS03TRA)
#define ExportedByJS03TRA DSYExport
#else
#define ExportedByJS03TRA DSYImport
#endif
#include "DSYExport.h"
#endif

#include "CATBSTR.h"
#include "CATIASettingController.h"

extern ExportedByJS03TRA IID IID_CATIAPCSStatisticsSettingAtt;

class ExportedByJS03TRA CATIAPCSStatisticsSettingAtt : public CATIAGeneralStatisticsSettingAtt
{
    CATDeclareInterface;

public:
	virtual HRESULT __stdcall get_MemUse(CAT_VARIANT_BOOL & oStatus)=0;
	virtual HRESULT __stdcall put_MemUse(CAT_VARIANT_BOOL iStatus)=0;
};

CATDeclareHandler(CATIAPCSStatisticsSettingAtt, CATIASettingController);

#include "CATBaseDispatch.h"
#include "CATBaseUnknown.h"
#include "CATIABase.h"
#include "CATSafeArray.h"
#include "CATVariant.h"
#include "IDispatch.h"
#include "IUnknown.h"


#endif
