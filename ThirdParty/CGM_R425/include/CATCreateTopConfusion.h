#ifndef CATCreateTopConfusion_H 
#define CATCreateTopConfusion_H 

// COPYRIGHT DASSAULT SYSTEMES  2000

#include "CATHybDef.h"
#include "BOHYBOPE.h"

//========================================================================
// 
//  Confusion Operator Body onto Body : 
// 
//========================================================================
/**
* Constructs an operator that analyze FULL confusion between Bodies.
* <br>This operator allows to check 
* <ul><li>a shell on a shell or a volume
* </ul>
* The candidate body and the support body can contain several domains.
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyCandidate
* A pointer to the body to check confusion on iBodySupport. 
* @param iBodySupport
* A pointer to the support body.
*/

ExportedByBOHYBOPE CATHybConfusion * CATCreateTopConfusion(CATGeoFactory*           iFactory,
                                                           CATTopData*              iData,
                                                           CATBody*                 iBodyCandidate,
                                                           CATBody*                 iBodySupport);
#endif
