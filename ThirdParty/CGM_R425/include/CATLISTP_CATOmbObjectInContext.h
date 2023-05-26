/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @collection CATLISTP(CATOmbObjectInContext)
 * Collection class for pointers to <tt>CATOmbObjectInContext</tt>.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>ApplyDelete</tt></li>
 * </ul>
 *
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATOmbObjectInContext
 */

#ifndef CATLISTP_CATOmbObjectInContext_H_
#define CATLISTP_CATOmbObjectInContext_H_

class CATOmbObjectInContext;

#include "AD0XXBAS.h"
// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------

#include  "CATLISTP_Clean.h"

// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------

#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#define CATLISTP_Locate
#define  CATLISTP_ApplyDelete

#include "CATLISTP_PublicInterface.h"

// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------

#include "CATLISTP_Declare.h"
// DECLARE All functions for class CATListPtrCATOmbObjectInContext :
// (generate body of class)
// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByAD0XXBAS


CATLISTP_DECLARE( CATOmbObjectInContext )

typedef CATLISTP(CATOmbObjectInContext) CATLISTP_CATOmbObjectInContext;

#endif


