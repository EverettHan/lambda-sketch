#ifndef IVISUICollection_H
#define IVISUICollection_H

//COPYRIGHT DASSAULT SYSTEMES 2012

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"

#include "CATLISTP_Clean.h"

class IVISUIBehaviour;
class IVIDeviceHandle;
class IVISUIInteraction;

#define CATLISTP_Append
#define CATLISTP_RemovePosition
#define	CATLISTP_RemoveAll
#define	CATLISTP_Locate

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByIVInterfaces

#include "CATLISTP_Declare.h"

// ===============================
// IVISUIBehaviourPtrList
// ===============================
CATLISTP_DECLARE(IVISUIBehaviour);

typedef ExportedByIVInterfaces CATLISTP(IVISUIBehaviour) IVISUIBehaviourPtrList;

// ===============================
// IVIDeviceHandlePtrList
// ===============================
CATLISTP_DECLARE(IVIDeviceHandle);

typedef ExportedByIVInterfaces CATLISTP(IVIDeviceHandle) IVIDeviceHandlePtrList;

// ===============================
// IVISUIInteractionPtrList
// ===============================
CATLISTP_DECLARE(IVISUIInteraction);

typedef ExportedByIVInterfaces CATLISTP(IVISUIInteraction) IVISUIInteractionPtrList;

#endif // IVISUICollection_H
