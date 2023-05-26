//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2004                                         *
//*===========================================================================*
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation juin 2004                                                       *
//*===========================================================================*
#ifndef __CATListPOfCATListOfCATUnicodeString_H
#define __CATListPOfCATListOfCATUnicodeString_H

#include  "CATListOfCATUnicodeString.h"
	 
#include "CO0LSTST.h"		 
#include  "CATLISTP_Clean.h"
#define    CATLISTP_Append
#define    CATLISTP_RemoveAll
#define    CATLISTP_Size
#define    CATLISTP_RemovePosition
#define    CATLISTP_AppendList
#define    CATLISTP_Locate
#define    CATLISTP_InsertAt
#define    CATLISTP_ReSize

#include  "CATLISTP_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCO0LSTST
  	 
CATLISTP_DECLARE(CATListOfCATUnicodeString)
#undef	CATCOLLEC_ExportedBy

#endif
