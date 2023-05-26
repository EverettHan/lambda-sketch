#ifndef CreateTopologicalDeviation_H 
#define CreateTopologicalDeviation_H 

// COPYRIGHT DASSAULT SYSTEMES 1999

//  Fillet Blend Operator : creation of Blend between BitangencyCurves 
// if iSupportDomain is not provided the body must contain a single Domain on 
// which the Blend will be computed.
#include "PowerTopologicalOpe.h"

#include "CATSkillValue.h"

class CATGeoFactory;
class CATBody;
class CATDomain;
class CATTopologicalDeviation;
class CATCGMJournalList;
//========================================================================
//
//========================================================================   
ExportedByPowerTopologicalOpe
CATTopologicalDeviation *	CreateTopologicalDeviation 
								(CATGeoFactory *       iFactory,
								const CATBody *        iBodySupport1,
								const CATBody *        iBodySupport2,
								// imode proj / min 
								const CATDomain *      iDomainSupport1 = 0,
								const CATDomain *      iDomainSupport2 = 0,
								CATSkillValue          iMode = BASIC);
//
ExportedByPowerTopologicalOpe
void Remove ( CATTopologicalDeviation *&iTopologicalDeviation );



#endif







