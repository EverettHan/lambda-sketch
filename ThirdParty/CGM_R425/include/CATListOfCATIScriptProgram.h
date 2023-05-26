#ifndef CATListOfCATIScriptProgram_h
#define CATListOfCATIScriptProgram_h

#include "AutomationItf.h"

// COPYRIGHT DASSAULT SYSTEMES 2000

class CATIScriptProgram;

#define PARAM_LIST_INITIAL_SIZE 2 // Initial size of a parameter list

#include  "CATLISTP_Clean.h"
#undef CATCOLLEC_ExportedBy
// Define the methods supported by the list of pointers to parameters
#define	CATLISTP_Append
#define	CATLISTP_RemovePosition
#define	CATLISTP_RemoveAll
#define	CATLISTP_Locate
#define CATCOLLEC_ExportedBy    ExportedByCATAutoItf

#include  "CATLISTP_Declare.h"
// Declare the type : list of pointers to class <CATIScriptProgram>
CATLISTP_DECLARE(CATIScriptProgram);

typedef CATLISTP(CATIScriptProgram) CATListOfCATIScriptProgram;

#endif

