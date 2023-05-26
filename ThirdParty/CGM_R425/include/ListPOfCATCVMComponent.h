/* -*-c++-*- */
#ifndef ListPOfCATCVMComponent_h
#define ListPOfCATCVMComponent_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMComponent;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMComponent, 10)
typedef CATLISTP(CATCVMComponent) ListPOfCATCVMComponent;
#endif
