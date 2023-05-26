/* -*-c++-*- */
#ifndef ListPOfCATCVMContainer_h
#define ListPOfCATCVMContainer_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMContainer;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMContainer, 10)
typedef CATLISTP(CATCVMContainer) ListPOfCATCVMContainer;
#endif
