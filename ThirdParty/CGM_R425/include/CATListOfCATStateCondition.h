#ifndef CATListOfCATStateCondition_h
#define CATListOfCATStateCondition_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

#include "CATLISTP_Clean.h"

#define	CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define	CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATStateCondition;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATDialogEngine

CATLISTP_DECLARE(CATStateCondition)

#define CATListOfCATStateCondition CATLISTP(CATStateCondition)

#endif
