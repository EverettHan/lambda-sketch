#include "CATComponentId.h"

// Clean previous functions requests
// Require needed functions
#include "CATLISTV_Clean.h"
#define CATLISTV_Append
#define CATLISTV_AppendList
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_Locate
#define CATLISTV_InsertAt
// Get macros
#include "CATLISTV_Declare.h"
#include "ExportedByCATPLMIdentification.h"

// Generate interface of collection-class
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPLMIdentification

