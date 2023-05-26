#ifndef CATTopSweepWireSkinSegment_h
#define CATTopSweepWireSkinSegment_h
 
// COPYRIGHT DASSAULT SYSTEMES  2003

/**
* @level Protected
* @usage U1
*/


#include <Fillet.h>

#include "CATTopSweepWireSkin.h"
/**
 * Constructs an operator that creates a segment sweep
 * between a skin body and a wire body.
 */

#define CATTopSweepWireSkinSegment CATTopSweepWireSkin

/**
 * Creates a CATTopSweepWireSkinSegment operator.
 * @param iFactory
 * The pointer to the geometry factory that creates the result bodies.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iSupportShell
 * The pointer to the skin body.
 * @param iGuide
 * The pointer to the wire body.
 * @param iSpine
 * The pointer to the spine body. Each segment section is in the plane normal to this spine curve.
 * @return
 * The pointer to the created operator. To delete after use, with the usual C++ <tt>delete</tt>
 * operator.
 */
ExportedByFillet 
CATTopSweepWireSkinSegment* 
CATCreateTopSweepWireSkinSegment (CATGeoFactory * iFactory,
                                  CATTopData *    iData,
                                  CATBody *       iSupportShell,
                                  CATBody *       iGuide,
                                  CATBody *       iSpine);
   
    
#endif
