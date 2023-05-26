// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLink_BindInterface_H
#define CATLink_BindInterface_H

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"
// Pour la definition de CATClassId
#include "CATBaseUnknown.h"

class CATBaseUnknown;

ExportedByCATObjectModelerBase
CATBaseUnknown*  CATLink_BindInterface( CATBaseUnknown* adapter
				       ,CATClassId                interfacename);

#endif
