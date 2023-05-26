#ifndef _CATVizUVGeometryServices_
#define _CATVizUVGeometryServices_
#include "SGInfra.h"
#include "list.h"
#include "CATErrorDef.h"
class CATRep;
class CATVizMeasurableIterator;
class CATVizPrimitive;

/**
* Retrieves canonical informations on primitives of a representation
* @param iRep
* The representation including the primitives
* @param iSubElements
* A list of indices of primitives on which canonical informations is to be retrieved
* @param oCanonicals
* The list of output canonical informations (through CATVizMeasurableIterator interface).
* Can include NULL pointers if no canonical informations is available on some primitives.
*/

HRESULT ExportedBySGInfra GetCanonicalInformation(CATRep & iRep, list<int> & iSubElements, list<CATVizMeasurableIterator> & oCanonicals);

/**
* Retrieves canonical informations on a CATVizPrimitive
* @param iPrimitive
* The primitive
*/
ExportedBySGInfra CATVizMeasurableIterator * GetCanonicalInformation(CATVizPrimitive * iPrimitive);

#endif
