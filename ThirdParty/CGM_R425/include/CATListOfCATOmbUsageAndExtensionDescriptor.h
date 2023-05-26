#ifndef CATListOfCATOmbUsageAndExtensionDescriptor_H
#define CATListOfCATOmbUsageAndExtensionDescriptor_H

class CATOmbUsageAndExtensionDescriptor ;  

/**
 * @level Protected
 * @usage U1
 */

#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_Locate
#define CATLISTP_RemoveValue

#include "CATLISTP_Declare.h"

#include "CATOmbImportExport.h"

// exportation du Block
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOmbImportExport


CATLISTP_DECLARE(CATOmbUsageAndExtensionDescriptor)

typedef class CATLISTP(CATOmbUsageAndExtensionDescriptor) ExportedByCATOmbImportExport CATListOfCATOmbUsageAndExtensionDescriptor; 

#endif

