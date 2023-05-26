#ifndef CATListOfVisTouchGesture_h
#define CATListOfVisTouchGesture_h

// COPYRIGHT DASSAULT SYSTEMES 1999


/**
 * @collection CATLISTP(VisTouchGesture)
 * Collection class for pointers to VisTouchGesture.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see VisTouchGesture
 */

//#include "CATVisFoundation.h"
//#include "CATVisItf.h"

#include  <CATLISTP_Clean.h>

#define	CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define	CATLISTP_RemovePosition
#define	CATLISTP_Locate
#define CATLISTP_RemoveNulls

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATVisFoundation

#include  <CATLISTP_Declare.h>

class VisTouchGesture;



CATLISTP_DECLARE( VisTouchGesture)

#endif
