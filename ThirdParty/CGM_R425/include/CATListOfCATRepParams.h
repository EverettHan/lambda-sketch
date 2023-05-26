#ifndef __CATListOfCATRepParams_h
#define __CATListOfCATRepParams_h


// COPYRIGHT DASSAULT SYSTEMES 2000

class CATRepParams;


// listes de CATRepParams
//-----------------------
#include "CATLISTP_Clean.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAfrFoundation

#define CATLISTP_RemovePosition
#define CATLISTP_Append

#include "CATLISTP_Declare.h"



CATLISTP_DECLARE(CATRepParams)

typedef CATLISTP(CATRepParams) CATListOfCATRepParams;

#endif//__CATListOfCATRepParams_h
