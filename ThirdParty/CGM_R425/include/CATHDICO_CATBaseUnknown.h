// COPYRIGHT DASSAULT SYSTEMES 2005
//=========================================================================
// Mar2005   Creation                                            Ph.BAUCHER
//=========================================================================
#ifndef CATHDICO_CATBaseUnknown_H
#define CATHDICO_CATBaseUnknown_H

/**
* @level  Protected
* @usage   U1
*/


class CATBaseUnknown;


//===================================================================
//  CHOOSE MEMBERS REQUIRED FOR THAT CLASS
//===================================================================

#include "CATHDICO_Clean.h"

#include "CATHDICO_AllFunct.h"
/*
#define	CATHDICO_Locate
#define	CATHDICO_Next
#define	CATHDICO_NextPosition
#define CATHDICO_ApplyDelete
*/
#include "CATHDICO_Declare.h"


//===================================================================
//  CHOOSE MODULE EXPORTING THAT CLASS
//===================================================================
#include "CATOMY.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOMY


//===================================================================
//  DECLARE THE CLASS CATHashDicoCATBaseUnknown
//===================================================================
CATHDICO_DECLARE (CATBaseUnknown)
//
// a.k.a.
typedef  CATHDICO(CATBaseUnknown)  CATHDICO_CATBaseUnknown;


#endif




