#ifndef CATListOfITypeLib_h
#define CATListOfITypeLib_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#include "AutomationItf.h"
#include "IUnknown.h"

// COPYRIGHT DASSAULT SYSTEMES 2000

interface ITypeLib;


#define PARAM_LIST_INITIAL_SIZE 2 // Initial size of a parameter list

#include  "CATLISTP_Clean.h"

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAutoItf
#endif

// Define the methods supported by the list of pointers to parameters
#define	CATLISTP_Append
#define	CATLISTP_RemovePosition
#define	CATLISTP_RemoveAll
#define	CATLISTP_Locate
#define CATLISTP_FillArrayPtrs

#include  "CATLISTP_Declare.h"
// Declare the type : list of pointers to class <ITypeLib>
CATLISTP_DECLARE(ITypeLib);

typedef CATLISTP(ITypeLib) CATListOfITypeLib;

#endif

