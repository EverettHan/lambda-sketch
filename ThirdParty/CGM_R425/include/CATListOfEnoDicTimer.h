//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATListOfEnoDicTimer_h
#define CATListOfEnoDicTimer_h

class EnoDicTimer;

#include <CATLISTP_Clean.h>

#define CATLISTP_QuickSort
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Locate

#include <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "ENODicTime.h"
#undef    CATCOLLEC_ExportedBy
#define    CATCOLLEC_ExportedBy ExportedByENODicTime

CATLISTP_DECLARE(EnoDicTimer);
/**
 * @nodoc
 */
typedef  CATLISTP(EnoDicTimer) CATListOfEnoDicTimer;

#endif
