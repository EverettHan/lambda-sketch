// COPYRIGHT Dassault Systemes 2002

/**
  * @level Protected
  * @usage U1
  */

/**
 * @collection CATLISTP(CATIDocId)
 * Collection class for pointers to <tt>CATIDocId</tt>.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>ApplyDelete</tt></li>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>InsertAfter</tt></li>
 * <li><tt>InsertAt</tt></li>
 * </ul>
 *
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIDocId
 */

#ifndef CATLISTP_CATIDocId_H
#define CATLISTP_CATIDocId_H

//   listes de CATIDocId
class CATIDocId;

#include "AD0XXBAS.h"
// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------

#include  "CATLISTP_Clean.h"

// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------

// minimaliste #include<CATLISTP_AllFunct.h>
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#define CATLISTP_Locate
#define CATLISTP_ApplyDelete
#define CATLISTP_InsertAfter
#define CATLISTP_InsertAt

#include "CATLISTP_PublicInterface.h"

// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------

#include "CATLISTP_Declare.h"
// DECLARE All functions for class CATListPtrCATIDocId :
// (generate body of class)


// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByAD0XXBAS


CATLISTP_DECLARE( CATIDocId )

typedef CATLISTP(CATIDocId) CATLISTP_CATIDocId;

#endif


