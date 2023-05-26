
// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATVisLook_h
#define CATVisLook_h

#include "CATVisFoundation.h"
#ifndef NULL
#define NULL 0
#endif

// careful : this is for licence check 
ExportedByCATVisFoundation int GetVisLook();


// careful : this is for Dialog Look 
typedef int (*CATVisLookPtrFunc) (int*);
ExportedByCATVisFoundation int CATSetDialogLookPtrFunc(CATVisLookPtrFunc);

ExportedByCATVisFoundation int GetDialogLook(int * oP1LookLevel = NULL);


#endif

