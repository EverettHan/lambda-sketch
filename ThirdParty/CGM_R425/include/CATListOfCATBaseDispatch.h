#ifndef CATListOfCATBaseDispatch_h
#define CATListOfCATBaseDispatch_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"

class CATBaseDispatch;

#define PARAM_LIST_INITIAL_SIZE 2 // Initial size of a parameter list

#include  "CATLISTP_Clean.h"

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAutoItf
#endif

// Define the methods supported by the list of pointers to parameters
#define	CATLISTP_Append
#define	CATLISTP_RemoveAll
#define	CATLISTP_RemovePosition
#define CATLISTP_FillArrayPtrs
#define	CATLISTP_Locate

#include  "CATLISTP_Declare.h"
// Declare the type : list of pointers to class <CATBaseDispatch>
CATLISTP_DECLARE(CATBaseDispatch);

typedef CATLISTP(CATBaseDispatch) CATListOfCATBaseDispatch;

#endif

