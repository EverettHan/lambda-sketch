/* -*-c++-*- */
#ifndef ListPOfCATCVMInstance_h
#define ListPOfCATCVMInstance_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMInstance;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMInstance, 10)
typedef CATLISTP(CATCVMInstance) ListPOfCATCVMInstance;
#endif
