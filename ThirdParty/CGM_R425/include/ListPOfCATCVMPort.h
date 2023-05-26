/* -*-c++-*- */
#ifndef ListPOfCATCVMPort_h
#define ListPOfCATCVMPort_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMPort;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMPort, 10)
typedef CATLISTP(CATCVMPort) ListPOfCATCVMPort;
#endif
