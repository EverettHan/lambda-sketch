// COPYRIGHT DASSAULT SYSTEMES  1999
#ifndef CATHashDicCATIPLMIdentifierSet_H
#define CATHashDicCATIPLMIdentifierSet_H

/**
 * @level Private
 * @usage U3
 */

class CATIPLMIdentifierSet;

// clean all defines
#include "CATHDICO_Clean.h"

// define used to get some services
#define CATHDICO_Remove
#define CATHDICO_Locate
#define CATHDICO_RemoveAll
#define CATHDICO_ApplyGlobalFunct
#define CATHDICO_NextPosition

// tells NT which module exports the collection
#include "CATPLMComponentInterfaces.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATPLMComponentInterfaces

#include "CATHDICO_Declare.h"
CATHDICO_DECLARE( CATIPLMIdentifierSet )

#endif
