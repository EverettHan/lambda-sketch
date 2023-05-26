/* -*-c++-*- */
#ifndef ListPOfCATCVMObject_h
#define ListPOfCATCVMObject_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMObject;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMObject, 10)
typedef CATLISTP(CATCVMObject) ListPOfCATCVMObject;
#endif
