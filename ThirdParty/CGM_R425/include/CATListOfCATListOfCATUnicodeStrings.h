//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2004                                         *
//*===========================================================================*
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation juin 2004                                                       *
//*===========================================================================*
#ifndef __CATListOfCATListOfCATUnicodeString_H
#define __CATListOfCATListOfCATUnicodeString_H

#include  "CATListOfCATUnicodeString.h"
#include "CO0LSTST.h"	 
	 
#include  "CATLISTV_Clean.h"
#define    CATLISTV_Append
#define    CATLISTV_RemoveAll
#define    CATLISTV_Size
#define    CATLISTV_RemovePosition

#include  "CATLISTV_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCO0LSTST
CATLISTV_DECLARE(CATListValCATUnicodeString)


typedef  CATLISTV(CATListValCATUnicodeString) CATListOfCATListOfCATUnicodeString ; 
#undef	CATCOLLEC_ExportedBy

#endif
