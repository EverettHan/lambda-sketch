#ifndef CATListOfCATBaseUnknown_WR_h
#define CATListOfCATBaseUnknown_WR_h

// COPYRIGHT DASSAULT SYSTEMES 2004

#include "JS0CORBA.h"

#include "CATBaseUnknown_WR.h"

#include "CATLISTV_Clean.h"

#define	CATLISTV_AppendList
#define	CATLISTV_InsertAt
#define	CATLISTV_Locate
#define	CATLISTV_RemoveValue
#define	CATLISTV_RemoveList
#define	CATLISTV_RemovePosition

#include "CATLISTV_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByJS0CORBA

CATLISTV_DECLARE(CATBaseUnknown_WR)

#undef CATCOLLEC_ExportedBy

typedef	class CATLISTV(CATBaseUnknown_WR)	CATListOfCATBaseUnknown_WR;

#endif // CATListOfCATBaseUnknown_WR_h


