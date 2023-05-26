#ifndef CATHashTableOfCGMTypeClassify_H
#define CATHashTableOfCGMTypeClassify_H

#include "CGMV5Interop.h"
class CGMTypeClassify;

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
CATHTAB_DECLARE( CGMTypeClassify )


ExportedByCGMV5Interop unsigned int HashKeyCGMTypeClassify(CGMTypeClassify* inew);
ExportedByCGMV5Interop int CompareCGMTypeClassify(CGMTypeClassify* i1, CGMTypeClassify *i2);



#endif
