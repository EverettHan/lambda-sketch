// COPYRIGHT DASSAULT SYSTEMES 2006

/*
@level Protected
@usage U1
*/

#ifndef	CATLISTV_CATDbBinary_h
#define	CATLISTV_CATDbBinary_h

#include "CO0LSTPV.h"
#include "CATDbBinary.h"

// To undefine all possible methods of the list of values
#include "CATLISTV_Clean.h" 

// Define the methods supported by the list of values
#define	CATLISTV_Append
#define	CATLISTV_Locate
#define	CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_ArrayVals
#define CATLISTV_ReSize
#define CATLISTV_Size
#define CATLISTV_InsertAt
#define CATLISTV_RemoveAll
#define CATLISTV_QuickSort
#define CATLISTV_ApplyDelete

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCO0LSTPV

#include "CATLISTV_Declare.h"
CATLISTV_DECLARE( CATDbBinary )
typedef CATLISTV( CATDbBinary ) CATListOfCATDbBinary;

#endif
