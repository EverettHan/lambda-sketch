#ifndef CATListOfCATIScriptFunction_h
#define CATListOfCATIScriptFunction_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"

class CATIScriptFunction;

#define PARAM_LIST_INITIAL_SIZE 2 // Initial size of a parameter list

#include  "CATLISTP_Clean.h"

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAutoItf
#endif

// Define the methods supported by the list of pointers to parameters
#define	CATLISTP_Append
#define	CATLISTP_RemoveAll
#define	CATLISTP_Locate

#include  "CATLISTP_Declare.h"
// Declare the type : list of pointers to class <CATIScriptFunction>
CATLISTP_DECLARE(CATIScriptFunction);

typedef CATLISTP(CATIScriptFunction) CATListOfCATIScriptFunction;

#endif
