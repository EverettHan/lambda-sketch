// COPYRIGHT DASSAULT SYSTEMES 2006  
/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATListPtrCATOmbUndoRedoMemento_H_
 * Do not use it directly use CATOmbUndoRedoMementoVector define in #href CATOmbSessionUndoMementoDefs header
 */
#ifndef CATListPtrCATOmbUndoRedoMemento_H_
#define CATListPtrCATOmbUndoRedoMemento_H_

class CATOmbUndoRedoMemento;

#include  "CATLISTP_Clean.h"

#include "CATLISTP_PublicInterface.h"

#include  "CATLISTP_Declare.h"


#include  "AD0XXBAS.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByAD0XXBAS


CATLISTP_DECLARE( CATOmbUndoRedoMemento )

typedef CATLISTP(CATOmbUndoRedoMemento) CATLISTP_CATOmbUndoRedoMemento;

#endif
