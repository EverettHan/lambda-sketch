#ifndef	CATListOfCATCommandHeader_h
#define	CATListOfCATCommandHeader_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATCommandHeader)
 * Collection class for pointers to <tt>CATCommandHeader</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATCommandHeader
 */

#include "CATAfrFoundation.h"

#include <CATLISTP_Clean.h>

#include <CATLISTP_PublicInterface.h>

#include <CATLISTP_Declare.h>

class CATCommandHeader;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAfrFoundation

CATLISTP_DECLARE( CATCommandHeader )

#endif
