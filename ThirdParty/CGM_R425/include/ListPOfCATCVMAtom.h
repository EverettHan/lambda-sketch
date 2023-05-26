/* -*-c++-*- */
#ifndef ListPOfCATCVMAtom_h
#define ListPOfCATCVMAtom_h

#include "CATCVMSysObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMAtom;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMSysObjects

CATLISTPP_DECLARE_TS(CATCVMAtom, 10)
typedef CATLISTP(CATCVMAtom) ListPOfCATCVMAtom;
#endif
