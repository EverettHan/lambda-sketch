// COPYRIGHT DASSAULT SYSTEMES 2000
/** 
* @CAA2Required                  
*/

//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifndef _CATBaseUnknowns_H
#define _CATBaseUnknowns_H

#define MIGR_CCP_TO_VAR
//

#include<CATBaseUnknown.h>

//            -------------------------------------------------
//            Version CCP AVEC VarBaseUnkown=CATBaseUnknown_var
//            -------------------------------------------------
#ifndef VarBaseUnknown
#define VarBaseUnknown CATBaseUnknown_var
#endif
#ifndef NULL_varBaseUnknown
#define NULL_varBaseUnknown  NULL_var
#endif
#ifndef ListOfVarBaseUnknown
#define ListOfVarBaseUnknown CATLISTV(CATBaseUnknown_var)
#endif

//this includes should provide defintion for ListOfVarBaseUnknown
#include<CATLISTV_CATBaseUnknown.h>

#include <CP0CLIP.h>

//Localize with IsEqual 
ExportedByCP0CLIP
int CATBaseUnknown_Locate(const ListOfVarBaseUnknown& l, VarBaseUnknown i_obj);

#endif

