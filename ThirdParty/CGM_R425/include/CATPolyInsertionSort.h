// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInsertionSort.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyInsertionSort_h
#define CATPolyInsertionSort_h

#include "CATPolyMiscellaneous.h"
#include "CATListPV.h"

void ExportedByCATPolyMiscellaneous CATPolyInsertionSort (CATListPV & list,
                                                          int (*compare)(const void * a, const void * b));

#endif
