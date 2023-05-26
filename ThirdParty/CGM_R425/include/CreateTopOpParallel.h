#ifndef CreateTopOpParallel_H 
#define CreateTopOpParallel_H 

// COPYRIGHT DASSAULT SYSTEMES  1999


//#include "Parallel.h"
#include "ParallelLight.h"
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
class CATDistanceTool;
//
/**
 * @nodoc
 * DEPRECATED. Use CATCreateTopParallel (CATTopParallel.h).
 * DO NOT USE
*/
ExportedByParallelLight
CATTopParallel * CreateTopOpParallel (CATGeoFactory     * iFactory,
				   CATBody      * iCurve,
				   CATBody       * iSupport,
				   CATLaw * iDistance,
           CATOrientation iOrientation,
				   CATCGMJournalList * iReport = NULL,
           CATLaw ** iMappingLaws=NULL);
//
/**
 * @nodoc
 * Deprecated. Use CATCreateTopParallel (CATTopParallel.h).
*/
ExportedByParallelLight
CATTopParallel * CreateTopOpAllParallel (CATGeoFactory     * iFactory,
				   CATBody      * iCurve,
				   CATBody       * iSupport,
				   CATDistanceTool * iDistance,
				   CATCGMJournalList * iReport = NULL,
           CATLaw ** iMappingLaws=NULL);
//
#endif


