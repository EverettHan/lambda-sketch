#ifndef	CATListOfCATCmdAccess_h
#define	CATListOfCATCmdAccess_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrFoundation.h"

#include  <CATLISTP_Clean.h>

#define	CATLISTP_Append
#define	CATLISTP_RemoveAll
#define	CATLISTP_RemovePosition
#define	CATLISTP_RemoveValue
#define	CATLISTP_RemoveDuplicates
#define	CATLISTP_InsertAt
#define	CATLISTP_Locate

#include  <CATLISTP_Declare.h>

class CATCmdAccess;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAfrFoundation

CATLISTP_DECLARE( CATCmdAccess )

#endif
