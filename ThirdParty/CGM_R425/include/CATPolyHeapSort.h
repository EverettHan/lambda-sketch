// COPYRIGHT DASSAULT SYSTEMES 2002, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHeapSort.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyHeapSort_h
#define CATPolyHeapSort_h

#include "CATPolyMiscellaneous.h"

#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"

void ExportedByCATPolyMiscellaneous CATPolyHeapSort (CATListPV & iList,
                                             int (* compare)(const void * a, const void * b));

void ExportedByCATPolyMiscellaneous CATPolyHeapSort (CATListOfInt & iList);

void ExportedByCATPolyMiscellaneous CATPolyHeapSort (CATListOfDouble & iList);

#endif
