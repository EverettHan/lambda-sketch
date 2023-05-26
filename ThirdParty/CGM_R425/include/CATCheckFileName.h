//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//===========================================================================
//                                                                           
//                                                      
//                                                                           
//  Usage Notes: V4 to V5 naming pattern 
//===========================================================================
//  Creation juin 1999                                 adt              
//===========================================================================
#ifndef _CATCHECKFILENAME
#define _CATCHECKFILENAME
#include "JS0STDLIB.h"

class CATUnicodeString;


#ifdef __cplusplus
extern "C" {
#endif
  ExportedByJS0STDLIB int CheckFileName(CATUnicodeString *iFileName, 
				      char **oASCIIpath,
				      int iFlag=0);
  
#ifdef __cplusplus
};
#endif
#endif
