/*====================================================
 *  (c) 1999 Dassault Systemes. All rights reserved  =
 *     Generated by CNextBackEnd version 0.1 on      =
 *===================================================*/

#ifndef CATIANetworkStatisticsSettingAtt_h
#define CATIANetworkStatisticsSettingAtt_h

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

extern ExportedByJS03TRA IID IID_CATIANetworkStatisticsSettingAtt;

class ExportedByJS03TRA CATIANetworkStatisticsSettingAtt : public CATIAGeneralStatisticsSettingAtt
{
    CATDeclareInterface;

public:

  
};

CATDeclareHandler(CATIANetworkStatisticsSettingAtt, CATIASettingController);

#include "CATBaseDispatch.h"
#include "CATBaseUnknown.h"
#include "CATIABase.h"
#include "CATSafeArray.h"
#include "CATVariant.h"
#include "IDispatch.h"
#include "IUnknown.h"


#endif
