#ifndef CATHashTableOfCGMObjULong_H
#define CATHashTableOfCGMObjULong_H

#include "CGMV5Interop.h"
class CGMObjULong;

//64 Bits ALV 04/09/03
#include "CATDataType.h"

#include "CATHTAB_Clean.h"
#define CATHTAB_Insert
#define CATHTAB_Locate
#define CATHTAB_PrintAddr
#define CATHTAB_PrintStats
#define CATHTAB_Remove
#define CATHTAB_RemoveAll
#define	CATHTAB_ApplyDelete
#define	CATHTAB_KeyLocate

#include "CATHTAB_Declare.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCGMV5Interop
CATHTAB_DECLARE( CGMObjULong )


ExportedByCGMV5Interop CATUINT32 HashKeyCGMObjULong(CGMObjULong* inew); //64 Bits ALV 04/09/03
ExportedByCGMV5Interop int CompareCGMObjULong(CGMObjULong* i1, CGMObjULong *i2);



#endif
