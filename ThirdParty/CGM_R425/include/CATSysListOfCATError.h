#ifndef CATSysListOfCATError_h
#define CATSysListOfCATError_h

// ==========================================================================
//          Definitions pour les listes de BehaviorEventStructure
// ==========================================================================
#include "JS0ERROR.h"

#include "CATError.h"
#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define	CATLISTP_AppendList
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveDuplicates
#define CATLISTP_Size
#define CATLISTP_Locate
#define CATLISTP_RemoveAll

#include "CATLISTP_Declare.h"

// --------------------------------------------------------------------------
//                 Generate implementation of collection-class
// --------------------------------------------------------------------------
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByJS0ERROR

CATLISTP_DECLARE(CATError)


#endif // CATSysListOfCATError_h
