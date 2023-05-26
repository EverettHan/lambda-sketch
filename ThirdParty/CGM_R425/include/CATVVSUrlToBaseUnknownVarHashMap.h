/**
 * @level Protected
 * @usage U1
 */


#ifndef CATVVSUrlToBaseUnknownVarHashMap_h
#define CATVVSUrlToBaseUnknownVarHashMap_h

#include "VVSUrlUtils.h"
#include "CATVVSUrlKey.h"
#include "CATBaseUnknown_var.h"
//#include "CATBaseUnknown.h"

#undef	ExportedBy
#define	ExportedBy ExportedByVVSUrlUtils

#include "CATSysTSCtnrDeclInit.h"

#define CATSYSTS_CTNR                  CATVVSUrlToBaseUnknownVarHashMap

#define CATSYSTS_KEY                   CATVVSUrlKey
#define CATSYSTS_KEY_HAS_HASH_FUNC     1
#define CATSYSTS_KEY_HAS_GET_BIN_DUMP  0
#define CATSYSTS_KEY_IS_BUILT_IN_TYPE  0

#define CATSYSTS_VAL                   CATBaseUnknown_var
#define CATSYSTS_VAL_HAS_COMPARE_OP    1
#define CATSYSTS_VAL_IS_PTR            0
#define CATSYSTS_VAL_IS_BUILT_IN_TYPE  0

#include "CATSysTSHashMap_Declare.h"

#endif // CATSysTSHashMapOfIntToVoidPtr_h


