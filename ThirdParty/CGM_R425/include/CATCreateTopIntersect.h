#ifndef CATCreateTopIntersect_H 
#define CATCreateTopIntersect_H 

// COPYRIGHT DASSAULT SYSTEMES  2000

/**
* @level Protected
* @usage U1
*/

#include "CATHybDef.h"
#include "BOHYBOPELight.h"


/**
* Constructs an operator that intersects two bodies.
* <br>The bodies to intersect can contain several domains.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iBody1ToIntersect
* The pointer to the first body to intersect. It can contain several 
* domains. In this case, the operator only processes the domains of highest dimension.
* @param iBody2ToIntersect
* The pointer to the second body to intersect. It can contain several 
* domains. In this case, the operator only processes the domains of highest dimension.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/

ExportedByBOHYBOPELight CATHybIntersect* CATCreateTopIntersect(CATGeoFactory*     iFactory,
                                                          CATTopData*        iData,
                                                          CATBody*           iBody1ToIntersect,
                                                          CATBody*           iBody2ToIntersect);
#endif
