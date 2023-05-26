#ifndef  CATPolyPPAssert_H
#define  CATPolyPPAssert_H

#include "DSYExport.h"

#define CATPPASSERT(condition) \
if (!(condition)) \
{\
  CATPolyPPAssert(#condition,__FILE__, __LINE__);\
}\

DSYExport void CATPolyPPAssert(const char* iTxt, const char* iFileName, int iLine);


#endif 
