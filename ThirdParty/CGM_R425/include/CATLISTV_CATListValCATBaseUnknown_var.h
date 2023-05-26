#ifndef CATLISTV_CATListValCATBaseUnknown_var_H
#define CATLISTV_CATListValCATBaseUnknown_var_H

#include "CATBaseUnknown_var.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATLISTV_Clean.h"

// Require needed functions.
#define CATLISTV_Append
#define CATLISTV_Size
#define CATLISTV_RemoveAll
#define CATLISTV_InsertAt
#define CATLISTV_RemoveNulls
#define CATLISTV_RemoveDuplicates
#define CATLISTV_AppendList
#define CATLISTV_RemovePosition
#define CATLISTV_RemoveValue

// Macros.
#include "CATSysTS.h"
#include "CATLISTV_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy          ExportedByCO0LSTPV

CATLISTV_DECLARE(CATListValCATBaseUnknown_var)
 
typedef CATLISTV(CATListValCATBaseUnknown_var)    CATLISTV_CATListValCATBaseUnknown_var;

#endif  // CATLISTV_CATListValCATBaseUnknown_var_H
