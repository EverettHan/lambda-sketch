#ifndef CATListOfCATOmyCioUrlUsageCtx_H
#define CATListOfCATOmyCioUrlUsageCtx_H


// COPYRIGHT DASSAULT SYSTEMES 2005

/**
  * @level Protected
  * @usage U1
  */

/**
 * @collection CATLISTP(CATOmyCioUrlUsageCtx)
 * Collection class for CATOmyCioUrlUsageCtx.
 * Only the following methods of handler collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>Locate</tt</li>
 * <li><tt>RemoveValue</tt</li>
 * <li><tt>RemovePosition</tt</li>
 * <li><tt>RemoveDuplicates</tt</li>
 * <li><tt>RemoveAll</tt</li>
 * </ul> 
 * Refer to the articles dealing with collections in the encyclopedia.
 */


class CATOmyCioUrlUsageCtx ;  

#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_Locate
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define CATLISTP_RemoveDuplicates
#define CATLISTP_RemovePosition


#include "CATLISTP_Declare.h"

#include "CATOMYCuteIO.h"

// exportation du Block
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOMYCuteIO


CATLISTP_DECLARE(CATOmyCioUrlUsageCtx)

typedef class CATLISTP(CATOmyCioUrlUsageCtx) ExportedByCATOMYCuteIO CATListOfCATOmyCioUrlUsageCtx; 

#endif

