#ifndef ListPOfCATHVertex_h
#define ListPOfCATHVertex_h

// COPYRIGHT DASSAULT SYSTEMES  2007

#include "CATCGMLISTPP_Declare.h"
#include "ExportedByCATTopologicalObjects.h"

class CATHVertex;

/** 
 * @collection CATLISTP(CATHVertex)
 * Collection class for pointers to geometric features.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia. 
 */

CATCGMLISTPP_DECLARE(CATHVertex);

typedef CATLISTP(CATHVertex) ListPOfCATHVertex;

class CATCGMOutput;
/**
 * @nodoc
 * Writes the tags of the cell manifolds of the list.
 * @param iWhereToWrite
 * The output.
 * @param  iToWrite
 * The list to dump.
 */
ExportedByCATTopologicalObjects CATCGMOutput& operator<<(CATCGMOutput& iWhereToWrite, const ListPOfCATHVertex& iToWrite);

#endif
