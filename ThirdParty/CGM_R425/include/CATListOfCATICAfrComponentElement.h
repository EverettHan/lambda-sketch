#ifndef CATListOfCATICAfrComponentElement_H
#define CATListOfCATICAfrComponentElement_H

// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @CAA2Usage U1
 */
/**
 * @collection CATLISTP(CATICAfrComponentElement)
 * Collection class for pointers to CATICAfrComponentElement interface.
 * Refer to the articles dealing with collections in the encyclopedia.
 */


#include "CATAfrItf.h"
#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATICAfrComponentElement;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAfrItf

CATLISTP_DECLARE (CATICAfrComponentElement)

typedef CATLISTP(CATICAfrComponentElement) CATListOfCATICAfrComponentElement;

#endif
