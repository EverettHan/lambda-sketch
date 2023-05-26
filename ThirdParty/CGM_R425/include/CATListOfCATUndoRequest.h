#ifndef CATListOfCATUndoRequest_h
#define CATListOfCATUndoRequest_h
#include "UndoRedoUI.h"

// COPYRIGHT DASSAULT SYSTEMES 2000
// protected CD0FRAME.m

#include "CATLISTP_Clean.h"

#define	CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define	CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATUndoRequest;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByUndoRedoUI

CATLISTP_DECLARE(CATUndoRequest)

#endif
 
