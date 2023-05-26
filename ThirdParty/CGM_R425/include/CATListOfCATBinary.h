#ifndef	CATListOfCATBinary_h
#define	CATListOfCATBinary_h

// COPYRIGHT DASSAULT SYSTEMES 2003

// System framework
#include "CATBinary.h"
#include "JS0CTYP.h"

// To undefine all possible methods of the list of values
#include "CATLISTV_Clean.h" 

// Define the methods supported by the list of values
#define	CATLISTV_Append
#define	CATLISTV_Locate
#define	CATLISTV_RemoveValue
#define CATLISTV_ArrayVals
#define CATLISTV_ReSize
#define CATLISTV_Size
#define CATLISTV_InsertAt
#define CATLISTV_RemoveAll

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByJS0CTYP
#endif // CATCOLLEC_ExportedBy

// Declare the class CATListValCATBinary : list of values of class <CATBinary>
#include "CATLISTV_Declare.h"
CATLISTV_DECLARE(CATBinary)
typedef CATListValCATBinary CATListOfCATBinary;

#endif // CATListOfCATBinary_h
