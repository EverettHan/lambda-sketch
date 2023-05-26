#ifndef CATListOfCATPathElement_h
#define CATListOfCATPathElement_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATPathElement)
 * Collection class for pointers to CATPathElement.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPathElement
 */

#include "CATVisItf.h"

#include  <CATLISTP_Clean.h>

#define	CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define	CATLISTP_RemovePosition
#define	CATLISTP_Locate

#include  <CATLISTP_Declare.h>

class CATPathElement;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATVisItf

CATLISTP_DECLARE( CATPathElement)

#endif
