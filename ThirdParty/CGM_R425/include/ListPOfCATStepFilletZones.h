#ifndef ListPOfCATStepFilletZones_H
#define ListPOfCATStepFilletZones_H

#include "AdvOpeInfra.h"

#include "CATLISTPP_Clean.h"
#define CATLISTPP_AppendList
#define CATLISTPP_RemovePosition
#include "CATLISTPP_MinimumPublicInterface.h"
#include "CATLISTPP_Declare.h"

class CATStepFilletZone;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByAdvOpeInfra

CATLISTPP_DECLARE_TS(CATStepFilletZone, 3)
typedef CATLISTP(CATStepFilletZone) ListPOfCATStepFilletZones;

#endif
