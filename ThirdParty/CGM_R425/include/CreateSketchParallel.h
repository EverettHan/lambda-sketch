// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateSketchParallel :
// Declaration of global functions used to create and destroy
// an instance of the Sketch operator
//
//=============================================================================
// Usage notes:
// sample of use : DO NOT USE. TEMPORARY METHODS !!!
// to provide
//
//=============================================================================
// October 98  Creation                          GDR
// Juillet 99  Modification                      JBX
//=============================================================================
#ifndef CreateSketchParallel_H 
#define CreateSketchParallel_H 
//
#include "AdvTopoSketch.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"
#include <stdlib.h>
//
class CATSketchParallel;
class CATSketchNewParallel;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
//

/* Test de suppression par RR

//
// DO NOT USE
//
ExportedByAdvTopoSketch
CATSketchParallel * CreateSketchParallelGeodesic (CATGeoFactory     * iFactory,
						  CATBody           * iSupport    = 0,
						  CATBody           * iCurve      = 0,
						  CATLength           iOffset     = 0,
						  CATBody           * iTargetBody = 0,
						  CATCGMJournalList * iReport     = 0,
						  CATSkillValue       iMode       = BASIC);
//
// DO NOT USE
//
ExportedByAdvTopoSketch
CATSketchParallel * CreateSketchParallelEuclidien(CATGeoFactory     * iFactory,
						  CATBody           * iSupport    = 0,
						  CATBody           * iCurve      = 0,
						  CATLength           iOffset     = 0,
						  CATBody           * iTargetBody = 0,
						  CATCGMJournalList * iReport     = 0,
						  CATSkillValue       iMode       = BASIC);
//
// DO NOT USE
//
ExportedByAdvTopoSketch
void Remove (CATSketchParallel *& iSketchParallel);
//

//
// DO NOT USE
//
ExportedByAdvTopoSketch
CATSketchNewParallel * CreateSketchNewParallelGeodesic (CATGeoFactory     * iFactory,
							CATBody           * iSupport    = 0,
							CATBody           * iCurve      = 0,
							CATLength           iOffset     = 0,
							CATBody           * iTargetBody = 0,
							CATCGMJournalList * iReport     = 0,
							CATSkillValue       iMode       = BASIC);
//
// DO NOT USE
//
ExportedByAdvTopoSketch
CATSketchNewParallel * CreateParallelGeodesicOnOneEdge (CATGeoFactory     * iFactory,
							CATBody           * iSupport    = 0,
							CATBody           * iCurve      = 0,
							CATLength           iOffset     = 0,
							CATBody           * iTargetBody = 0,
							CATCGMJournalList * iReport     = 0,
							CATSkillValue       iMode       = BASIC);
//
// DO NOT USE
//
ExportedByAdvTopoSketch
void Remove (CATSketchNewParallel *& iSketchParallel);
//

*/

#endif
