#ifndef	CATListValCATOmbLoadableDataUniqueKey_h
#define	CATListValCATOmbLoadableDataUniqueKey_h

/**
* @level  Private
* @usage   U1
*/

// type of elements
class CATOmbLoadableDataUniqueKey ;


// clean previous functions requests
#include  <CATLISTV_Clean.h>

// require needed functions
#include  <CATLISTV_AllFunct.h>
//#include  <CATLISTV_PublicInterface.h>

// get macros
#include  <CATLISTV_Declare.h>

// exporting module
#include  <CATOmbSelectiveLoading.h>
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOmbSelectiveLoading

//
// generate interface of collection-class
// (functions declarations)
//
CATLISTV_DECLARE( CATOmbLoadableDataUniqueKey )

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy
#endif	// CATListValCATOmbLoadableDataUniqueKey_h
