#ifndef ListPOfCATWbrData_H
#define ListPOfCATWbrData_H

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

// ListPOf

class CATWbrVirtualElement;
CATLISTPP_DECLARE_TS(CATWbrVirtualElement, 10)
typedef CATLISTP(CATWbrVirtualElement) ListPOfCATWbrVirtualElement;

class CATWbrSimpleElement;
CATLISTPP_DECLARE_TS(CATWbrSimpleElement, 10)
typedef CATLISTP(CATWbrSimpleElement) ListPOfCATWbrSimpleElement;

class CATWbrPlaneData;
CATLISTPP_DECLARE_TS(CATWbrPlaneData, 10)
typedef CATLISTP(CATWbrPlaneData) ListPOfCATWbrPlaneData;

class CATWbrRevolutionData;
CATLISTPP_DECLARE_TS(CATWbrRevolutionData, 10)
typedef CATLISTP(CATWbrRevolutionData) ListPOfCATWbrRevolutionData;

class CATWbrCylinderData;
CATLISTPP_DECLARE_TS(CATWbrCylinderData, 10)
typedef CATLISTP(CATWbrCylinderData) ListPOfCATWbrCylinderData;

class CATWbrConeData;
CATLISTPP_DECLARE_TS(CATWbrConeData, 10)
typedef CATLISTP(CATWbrConeData) ListPOfCATWbrConeData;

class CATWbrFacingElement;
CATLISTPP_DECLARE_TS(CATWbrFacingElement, 10)
typedef CATLISTP(CATWbrFacingElement) ListPOfCATWbrFacingElement;

class CATWbrWallData;
CATLISTPP_DECLARE_TS(CATWbrWallData, 10)
typedef CATLISTP(CATWbrWallData) ListPOfCATWbrWallData;

class CATWbrBendData;
CATLISTPP_DECLARE_TS(CATWbrBendData, 10)
typedef CATLISTP(CATWbrBendData) ListPOfCATWbrBendData;

// ListPOfListPOf

CATLISTPP_DECLARE_TS(ListPOfCATWbrVirtualElement, 10)
typedef CATLISTP(ListPOfCATWbrVirtualElement) ListPOfListPOfCATWbrVirtualElement;

CATLISTPP_DECLARE_TS(ListPOfCATWbrBendData, 10)
typedef CATLISTP(ListPOfCATWbrBendData) ListPOfListPOfCATWbrBendData;

#endif
