// File : CATListOfDoubleArray.h

#ifndef CATListOfDoubleArray_h
#define CATListOfDoubleArray_h

typedef double DoubleArray;

// clean previous functions requests
#include "CATLISTPP_Clean.h"
// Pour l'export de la liste
#include "MathPlate.h"
//
// require needed functions
#define CATLISTPP_Append
#define CATLISTPP_Size
#define CATLISTPP_ReSize
#define	CATLISTPP_AppendList
#define	CATLISTPP_InsertAt
#define	CATLISTPP_Locate
#define	CATLISTPP_RemovePosition
#define	CATLISTPP_RemoveAll
//#define	CATLISTPP_Intersection
//
// generate interface of collection class
//
// get macros
#include "CATLISTPP_Declare.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByMathPlate

//
// generate interface of collection class
// (functions declarations)

CATLISTPP_DECLARE(DoubleArray)
typedef CATLISTP(DoubleArray) CATListOfDoubleArray;

#endif

