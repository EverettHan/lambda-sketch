#ifndef CATCreateTopSplitOnSupport_H 
#define CATCreateTopSplitOnSupport_H 

// COPYRIGHT DASSAULT SYSTEMES  2001

/**
* @level Protected
* @usage U1
*/

#include "CATHybDef.h"
#include "BOHYBOPELight.h"

/**
* Constructs an operator that splits one body by another one on a support context.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* <br><b>Orientation</b>: The orientation of the domains in the resulting body corresponds to the orientation
* of the inital domains in the first body <tt>iBodyToSplit</tt>.
* @param iFactory
* The pointer to the factory that creates the result.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iBodyToSplit
* The pointer to the first body to cut. It can contain several 
* domains. In this case, the operator only processes the domains of highest dimension.
* @param iSideToKeep
* The side to keep 
* <br><b>Legal values</b>:
* <dl><dt>1</dt><dd> The left side is kept
* <dt>-1</dt><dd>The right side is kept
* </dl>
* @param iSplittingBody
* The pointer to the body that splits <tt>iBodyToSplit</tt>. It can contain several 
* domains. In this case, the operator only processes the domains of highest dimension.
* @param iBodySupport
* The pointer to the body defining the support.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/	

ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitOnSupport(CATGeoFactory*     iFactory,
                                                                CATTopData*        iData,
                                                                CATBody*           iBodyToSplit,
                                                                short              iSideToKeep,
                                                                CATBody*           iSplittingBody,
                                                                CATBody*           iBodySupport);
#endif
