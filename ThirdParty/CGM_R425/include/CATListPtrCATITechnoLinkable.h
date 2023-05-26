/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATListPtrCATITechnoLinkable_H_
#define CATListPtrCATITechnoLinkable_H_

class CATITechnoLinkable;

#include  "CATLISTP_Clean.h"

#include "CATLISTP_PublicInterface.h"

#include  "CATLISTP_Declare.h"

#define	CATLISTP_AppendList



#include  "TECHNLNK.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByTECHNLNK


CATLISTP_DECLARE(CATITechnoLinkable)

typedef CATLISTP(CATITechnoLinkable) CATLISTP_CATITechnoLinkable;

#endif

