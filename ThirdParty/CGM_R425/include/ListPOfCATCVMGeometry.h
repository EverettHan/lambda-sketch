/* -*-c++-*- */
#ifndef ListPOfCATCVMGeometry_h
#define ListPOfCATCVMGeometry_h

#include "CATCVMGeoObjects.h"


#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATCVMGeometry;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCVMGeoObjects

CATLISTPP_DECLARE_TS(CATCVMGeometry, 10)
typedef CATLISTP(CATCVMGeometry) ListPOfCATCVMGeometry;
#endif
