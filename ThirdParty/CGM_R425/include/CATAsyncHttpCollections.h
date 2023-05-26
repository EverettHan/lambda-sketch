/**
* @fullReview  L6I 15:03:18 L6I: CATAsyncCollectionPrivate creation
*/

//===================================================================
// COPYRIGHT Dassault Systemes 2015/03/17
//===================================================================
// CATAsyncHttpCollections.cpp
// Header definition of class CATAsyncCollectionPrivate
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/03/17 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAsyncHttpCollections_H
#define CATAsyncHttpCollections_H

#include "CATOMYHTTP.h"
#include "CATAsyncCollections.h"

#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmxPair.h"
#include "CATOmxIter.h"

typedef CATOmxArray< CATUnicodeString > ListOfRequestHeaders;
typedef CATOmxIter< const CATUnicodeString > RequestHeaders_iter;
typedef CATOmxPair<CATUnicodeString, CATUnicodeString > OmyCATUnicodeStringPair;
typedef CATOmxIter< const OmyCATUnicodeStringPair > ListOfPostParams_iter;

ExportedByCATOMYHTTP CATOmxCollecManager &OmyCATUnicodeStringPairMgr();

typedef CATOmxArray< OmyCATUnicodeStringPair, OmyCATUnicodeStringPairMgr> ListOfPostParams;


#endif