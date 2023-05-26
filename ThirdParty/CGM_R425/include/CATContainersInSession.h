//
#ifndef CATContainersInSession_h
#define CATContainersInSession_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Required                     
 */

/**
 * @collection CATLISTP(CATIContainer)
 * Collection class for pointers to CATIContainer.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>ReSize</tt></li>
 * <li><tt>Append</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */


class CATIContainer ;


#include "CATLISTP_Clean.h"

#define CATLISTP_ReSize
#define CATLISTP_Append
#define CATLISTP_Locate
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition



#include  "AC0XXLNK.h"

#include "CATLISTP_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByAC0XXLNK

CATLISTP_DECLARE(CATIContainer)
#endif









