#ifndef __CATListValCATUuid_H
#define __CATListValCATUuid_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTV(CATUuid)
 * Collection class for specobjects.
 * All the methods of handlers collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATLISTV_Clean.h"
#define CATLISTV_InsertAt
#define CATLISTV_ReSize
#define CATLISTV_Locate
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_ArrayVals
#include "CATLISTV_Declare.h"

#include "CATUuid.h"

#include "CATOmxKernel.h"
#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define	CATCOLLEC_ExportedBy ExportedByCATOmxKernel

CATLISTV_DECLARE(CATUuid)

#undef CATCOLLEC_ExportedBy

#endif

