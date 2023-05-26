// COPYRIGHT DASSAULT SYSTEMES 2000
/** 
* @CAA2Required                  
*/
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifndef CATFormat_List_H_
#define CATFormat_List_H_

#include<CP0CLIP.h>

class CATFormat;

//For list of Formats: Collections package....
#include<CATLISTP_Clean.h>

// minimaliste #include<CATLISTP_AllFunct.h>
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#define CATLISTP_Locate

#include<CATLISTP_Declare.h>
#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedByCP0CLIP
CATLISTP_DECLARE( CATFormat);

ExportedByCP0CLIP
int CATFormat_LocateMatching(const CATLISTP(CATFormat)& l, const CATFormat* i_fmt);

ExportedByCP0CLIP
int CATFormat_Locate(const CATLISTP(CATFormat)& l, const CATFormat* i_fmt);


#endif

