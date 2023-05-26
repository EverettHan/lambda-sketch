#ifndef CATListOfIVCameraData_H
#define CATListOfIVCameraData_H

//COPYRIGHT DASSAULT SYSTEMES 2012

#include "IVInterfaces.h"

#include "CATLISTP_Clean.h"
#include "IVISUIScenarioMultipipeHelpers.h"

#define CATLISTP_Append
#define CATLISTP_RemovePosition
#define	CATLISTP_RemoveAll
#define	CATLISTP_Locate
#define CATLISTV_RemovePosition

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByIVInterfaces

#include "CATLISTV_Declare.h"

// ===============================
// CATListValIVCameraData
// ===============================
CATLISTV_DECLARE(IVCameraData);

#endif // 
