#ifndef CATListOfCATIStandardObject_h
#define CATListOfCATIStandardObject_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "CATIStandardObject.h"

#include "CATLISTV_Clean.h"

#define CATLISTV_Append
#define CATLISTV_Locate
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_RemoveDuplicatesCount
#define CATLISTV_RemoveList

#include "CATLISTV_Declare.h"

// exporting module
#include "UIModelInterfaces.h"
#undef  CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByUIModelInterfaces

CATLISTV_DECLARE(CATIStandardObject_var)

typedef CATLISTV(CATIStandardObject_var) CATListOfCATIStandardObject;
     

#endif

