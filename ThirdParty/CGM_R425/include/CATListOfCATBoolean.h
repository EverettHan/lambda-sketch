#ifndef	CATListOfCATBoolean_h
#define	CATListOfCATBoolean_h

// COPYRIGHT DASSAULT SYSTEMES 2003

// System framework
#include "CATBoolean.h"
#include "JS0CTYP.h"

// To undefine all possible methods of the list of values
#include "CATLISTV_Clean.h" 

// Define the methods supported by the list of values
#define	CATLISTV_Append
#define	CATLISTV_Locate
#define	CATLISTV_RemoveValue
#define CATLISTV_ArrayVals

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByJS0CTYP
#endif // CATCOLLEC_ExportedBy

// Declare the class CATListValCATBoolean : list of values of CATBoolean
#include "CATLISTV_Declare.h"
CATLISTV_DECLARE_TN(CATBoolean, CATBoolean)
typedef CATListValCATBoolean CATListOfCATBoolean;

#endif // CATListOfCATBoolean_h
