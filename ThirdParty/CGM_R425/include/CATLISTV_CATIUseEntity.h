
#ifndef __CATLISTV_CATIUseEntity_h__
#define __CATLISTV_CATIUseEntity_h__

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTV(CATIUseEntity)
 * Collection class for Use Entities.
 * All the methods of handlers collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATLISTHand_Clean.h"
#include "CATLISTHand_AllFunct.h"
#include "CATLISTHand_Declare.h"

#include "CATIUseEntity.h"

#include "DataCommonProtocolUse.h"
#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define	CATCOLLEC_ExportedBy ExportedByDataCommonProtocolUse

CATLISTHand_DECLARE(CATIUseEntity_var)

#undef CATCOLLEC_ExportedBy

/**
 * Type for collection of CATIUseEntity.
 * <b>Role</b>:Use this type in place of @href CATListValCATIUseEntity
 */
typedef	class CATLISTV(CATIUseEntity_var) CATListOfCATIUseEntity_var;

#endif // __CATLISTV_CATIUseEntity_h__
