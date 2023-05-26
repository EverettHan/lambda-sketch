#ifndef	CATListOfCATCommand_h
#define	CATListOfCATCommand_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATCommand)
 * Collection class for pointers to <tt>CATCommand</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATCommand
 */

#include "CATAfrFoundation.h"

#include "CATLISTP_Clean.h"

#include "CATLISTP_PublicInterface.h"

#include "CATLISTP_Declare.h"

class CATCommand;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAfrFoundation

CATLISTP_DECLARE( CATCommand )

#endif
