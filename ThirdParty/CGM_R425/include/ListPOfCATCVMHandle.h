/* -*-c++-*- */
#ifndef ListPOfCATCVMHandle_h
#define ListPOfCATCVMHandle_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMHandle;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMHandle, 10)
typedef CATLISTP(CATCVMHandle) ListPOfCATCVMHandle;
#endif
