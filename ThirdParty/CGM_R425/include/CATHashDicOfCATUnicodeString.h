
// COPYRIGHT DASSAULT SYSTEMES 2002

// --------------------------------------------------------------
// An associative dictionary of strings indexed by strings (CATUnicodeString
// in both cases).
// --------------------------------------------------------------       

#ifndef CATHashDicOfCATUnicodeString_H
#define CATHashDicOfCATUnicodeString_H
//
#include "CATHDICO_Clean.h"
#include  "CO0HDICO.h"
//
#define CATHDICO_Insert
#define CATHDICO_Locate
#define CATHDICO_NextPosition
#define CATHDICO_Dimension
#define CATHDICO_ApplyDelete
#define CATHDICO_Remove
#define CATHDICO_RemovePosition
//
#include "CATHDICO_Declare.h"
#include  "CO0HDICO.h"
//

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedByCO0HDICO
//
CATHDICO_DECLARE (CATUnicodeString);
//
#undef CATCOLLEC_ExportedBy
//
#endif

