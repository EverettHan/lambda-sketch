//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATLISTOFVPMIDICSERVICE_H
#define CATLISTOFVPMIDICSERVICE_H

#include "VPMIDicInterfaces.h"

#include "CATLISTP_Clean.h"
#include "CATLISTP_PublicInterface.h"
#include "CATLISTP_Declare.h"

#include "VPMIDicService.h"

#ifdef  CATCOLLEC_ExportedBy
#undef  CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedByVPMIDicInterfaces

CATLISTP_DECLARE( VPMIDicService )

#define CATListOfVPMIDicService CATLISTP(VPMIDicService)

#endif // _CATListOfVPMIDicService