// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateTopologicalParallel :
// Declaration of global functions used to create and destroy
// an instance of the TopologicalParallel operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// March 99  Creation                          JHN
// Augu. 99  Insertion of Mappinglaws          JHN
//=============================================================================
#ifndef CreateTopParallel_H 
#define CreateTopParallel_H 
//
#include "FrFTopologicalOpe.h"
#include "CATSkillValue.h"
#include "CATGeoToTopOperator.h"
#include "CATTopDef.h"
#include <stdlib.h>
//
class CATTopParallel;
class CATGeoFactory;
class CATGeometry;
class CATBody;
class CATCGMJournalList;
class CATLaw;
//
// MappingLaws contains one law for each edge in the wire of icurve
//
ExportedByFrFTopologicalOpe
CATTopParallel * CreateTopParallel (CATGeoFactory     * iFactory,
				   CATBody      * iCurve,
				   CATBody       * iSupport,
				   CATLaw * Radius,
           CATOrientation Orientation,
				   CATCGMJournalList * iReport = NULL,
           CATLaw ** iMappingLaws=NULL);
//
ExportedByFrFTopologicalOpe
void Remove( CATTopParallel *&iTopologicalParallel );

//
#endif


