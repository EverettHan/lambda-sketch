// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
// CATDBCallbackCATList:
// A list of CATDBCallback objects
//=============================================================================
// Jan. 98  Creation                                     AVE
//=============================================================================
#ifndef _CATDBCallbackCATList_h
#define _CATDBCallbackCATList_h

//=============================================================================
//                      IMPORTED DECLARATIONS
//=============================================================================


//_____________________ Accessor class
#include "CATDBCallback.h"


//-----------------------------------------------------------------------------
#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_QuickSort
#define CATLISTP_RemoveValue

#include "CATLISTP_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByDI0BUILD

// Generation of the interface for the 'CATDBCallbackCATList' class
CATLISTP_DECLARE( CATDBCallback )

typedef CATLISTP(CATDBCallback) CATDBCallbackCATList;


#endif 

