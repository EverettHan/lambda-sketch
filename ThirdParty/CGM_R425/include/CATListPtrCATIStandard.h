/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATListPtrCATIStandard_H_
#define CATListPtrCATIStandard_H_

class CATIStandard;

#include  "CATLISTP_Clean.h"

#include "CATLISTP_PublicInterface.h"

#include  "CATLISTP_Declare.h"

#define	CATLISTP_AppendList



#include  "AD0XXBAS.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByAD0XXBAS


CATLISTP_DECLARE(CATIStandard)

typedef CATLISTP(CATIStandard) CATLISTP_CATIStandard;

#endif

