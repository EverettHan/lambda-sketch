#ifndef VisListOfTouchEvent_h
#define VisListOfTouchEvent_h

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	CATListPtrVisTouchEvent
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : CATListPtrVisTouchEvent
//					        CATListPV
//-----------------------------------------------------------------------------
// Abstract : @collection CATLISTP(VisTouchEvent)
//            Collection class for pointers to touch screen event.
//            All the methods of pointer collection classes are available.
//            Refer to the articles dealing with collections in the encyclopedia.
//            @see VisTouchEvent
//-----------------------------------------------------------------------------
//  Main Methods :
//-----------------------------------------------------------------------------


#include "CATVisFoundation.h"

#include  <CATLISTP_Clean.h>

#include  <CATLISTP_PublicInterface.h>

#include  <CATLISTP_Declare.h>

class VisTouchEvent;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATVisFoundation

CATLISTP_DECLARE(VisTouchEvent)

#endif
