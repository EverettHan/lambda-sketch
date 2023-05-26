#ifndef CATListOfCATFrmWindow_h
#define CATListOfCATFrmWindow_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATFrmWindow)
 * Collection class for pointers to document windows.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATFrmWindow
 */

#include "CATAfrFoundation.h"

#include  <CATLISTP_Clean.h>

#include  <CATLISTP_PublicInterface.h>

#include  <CATLISTP_Declare.h>

class CATFrmWindow;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAfrFoundation

CATLISTP_DECLARE(CATFrmWindow)

#endif
