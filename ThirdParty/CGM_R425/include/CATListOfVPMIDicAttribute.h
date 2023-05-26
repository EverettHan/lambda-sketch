//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATLISTOFVPMIDICATTRIBUTE_H
#define CATLISTOFVPMIDICATTRIBUTE_H

#include "VPMIDicInterfaces.h"

#include "CATLISTP_Clean.h"
#include "CATLISTP_PublicInterface.h"
#include "CATLISTP_Declare.h"

#include "VPMIDicAttribute.h"

#ifdef  CATCOLLEC_ExportedBy
#undef  CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedByVPMIDicInterfaces

CATLISTP_DECLARE( VPMIDicAttribute )

#define CATListOfVPMIDicAttribute CATLISTP(VPMIDicAttribute)

#endif // _CATListOfVPMIDicAttribute
