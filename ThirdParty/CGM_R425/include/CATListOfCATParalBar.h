#ifndef CATListOfCATParalBar_h
#define CATListOfCATParalBar_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */ 

#include "CATCGMLISTPP_Declare.h"

class CATParalBar;

CATCGMLISTPP_DECLARE(CATParalBar);

typedef CATLISTP(CATParalBar) ListPOfCATParalBar;

class CATCGMOutput;
/**
 * @nodoc
 * Writes the tags of the cells of the list.
 * @param iWhereToWrite
 * The output.
 * @param  iToWrite
 * The list to dump.
 */
//ExportedByYI00IMPL CATCGMOutput& operator<<(CATCGMOutput& iWhereToWrite, const ListPOfCATCell& iToWrite);

#endif
