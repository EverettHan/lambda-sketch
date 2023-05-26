#ifndef CATCreateTopDisconnect_H 
#define CATCreateTopDisconnect_H 

// COPYRIGHT DASSAULT SYSTEMES  2000

/**
 * @level Protected
 * @usage U1
 */ 
#include "BOHYBOPELight.h"

/**
 * Creates the operator to insert vertices in a wire or skin body, or to
 * insert edges in a skin body.
 * @param iFactory
 * The pointer to the geometry factory.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 *  @param iBodyToDisconnect
 * The pointer to the body in which cells are inserted.
 * @param iDisconnectingBody
 * The pointer to the body containing the cells to insert.
 * @param iCuttingBody
 * The pointer to the resulting body of the operation of projection of <tt>iDisconnectingBody</tt>
 * onto <tt>iBodyToDisconnect</tt>.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBOHYBOPELight CATHybDisconnect * CATCreateTopDisconnect(CATGeoFactory*     iFactory,
                                                             CATTopData*        iData,
                                                             CATBody*           iBodyToDisconnect,
                                                             CATBody*           iDisconnectingBody,
                                                             CATBody*           iCuttingBody);
#endif
