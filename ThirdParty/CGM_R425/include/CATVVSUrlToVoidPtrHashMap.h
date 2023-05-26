/**
 * @level Protected
 * @usage U1
 */

#ifndef CATSysTSHashMapOfIntToVoidPtr_h
#define CATSysTSHashMapOfIntToVoidPtr_h

#include "VVSUrlUtils.h"
#include "CATVVSUrlKey.h"

#undef	ExportedBy
#define	ExportedBy ExportedByVVSUrlUtils

typedef void * CATSysTSVoidPtr;

#include "CATSysTSCtnrDeclInit.h"

#define CATSYSTS_CTNR                  CATVVSUrlToVoidPtrHashMap

#define CATSYSTS_KEY                   CATVVSUrlKey
#define CATSYSTS_KEY_HAS_HASH_FUNC     1
#define CATSYSTS_KEY_HAS_GET_BIN_DUMP  0
#define CATSYSTS_KEY_IS_BUILT_IN_TYPE  0

#define CATSYSTS_VAL                   CATSysTSVoidPtr
#define CATSYSTS_VAL_HAS_COMPARE_OP    0
#define CATSYSTS_VAL_IS_PTR            1
#define CATSYSTS_VAL_IS_BUILT_IN_TYPE  1

#include "CATSysTSHashMap_Declare.h"

#endif // CATSysTSHashMapOfIntToVoidPtr_h


