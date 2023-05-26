#ifndef CATListOfCATDialogTransition_h
#define CATListOfCATDialogTransition_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

#include "CATLISTP_Clean.h"

#define	CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define	CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATDialogTransition;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATDialogEngine

CATLISTP_DECLARE(CATDialogTransition)

#define CATListOfCATDialogTransition CATLISTP(CATDialogTransition)

#endif
