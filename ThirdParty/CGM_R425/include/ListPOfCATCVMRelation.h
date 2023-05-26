/* -*-c++-*- */
#ifndef ListPOfCATCVMRelation_h
#define ListPOfCATCVMRelation_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMRelation;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMRelation, 10)
typedef CATLISTP(CATCVMRelation) ListPOfCATCVMRelation;
#endif
