
#ifndef __CATLISTP_IID_h__
#define __CATLISTP_IID_h__

// COPYRIGHT DASSAULT SYSTEMES 2010

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(IID)
 * Collection class for IID pointers.
 * All the methods of handlers collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATLISTP_Clean.h"
#include "CATLISTP_PublicInterface.h"
#include "CATLISTP_Declare.h"

#include "IUnknown.h"

#include "CATProviderItf.h"
#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define	CATCOLLEC_ExportedBy ExportedByCATProviderItf

CATLISTP_DECLARE(IID)

#undef CATCOLLEC_ExportedBy
#include "CATLISTP_Clean.h"


#endif // __CATLISTP_IID_h__
