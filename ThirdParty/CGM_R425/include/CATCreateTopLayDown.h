#ifndef CATCreateTopLayDown_H 
#define CATCreateTopLayDown_H 

// COPYRIGHT DASSAULT SYSTEMES  2004

/**
* @level Protected
* @usage U1
*/

#include "AnalysisToolsLight.h"

class CATLayDownOperator;
class CATGeoFactory;
class CATTopData;
class CATBody;

/**
* Constructs an operator that  projects a body onto another one referred to as the support
* and returns a solution.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iBodyToLayDown
* The pointer to the body to be projected. 
* @param iBodySupport
* The support.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/	

ExportedByAnalysisToolsLight CATLayDownOperator* CATCreateTopLayDown(CATGeoFactory*           iFactory,
																CATTopData*              iData,
																CATBody*                 iBodyToLayDown,
																CATBody*                 iBodySupport);
#endif
