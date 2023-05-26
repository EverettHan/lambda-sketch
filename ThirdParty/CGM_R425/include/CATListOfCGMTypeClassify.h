#ifndef CATListOfCGMTypeClassify_H
#define CATListOfCGMTypeClassify_H

//=============================================================================
// Apr. 04 CGMTypeSortByNameInv(...), CGMTypeSortByMemoryBytes(...)       HCN
//=============================================================================

#include "CGMV5Interop.h"
class CGMTypeClassify;

#include "CATLISTP_Clean.h"
#define CATLISTP_Append
#define CATLISTP_Size
#define CATLISTP_ReSize
#define	CATLISTP_AppendList
#define CATLISTP_InsertAt
#define CATLISTP_Locate
#define CATLISTP_QuickSort
#define CATLISTP_RemoveDuplicates
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define	CATLISTP_Intersection
#include "CATLISTP_Declare.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCGMV5Interop
CATLISTP_DECLARE( CGMTypeClassify )


ExportedByCGMV5Interop int CGMTypeSortByName(CGMTypeClassify* i1, CGMTypeClassify *i2);
ExportedByCGMV5Interop int CGMTypeSortByNameInv(CGMTypeClassify* i1, CGMTypeClassify *i2);
ExportedByCGMV5Interop int CGMTypeSortByNumberOfObjects(CGMTypeClassify* i1, CGMTypeClassify *i2);
ExportedByCGMV5Interop int CGMTypeSortByCumulated(CGMTypeClassify* i1, CGMTypeClassify *i2);
ExportedByCGMV5Interop int CGMTypeSortByMemoryBytes(CGMTypeClassify* i1, CGMTypeClassify *i2);


#endif
