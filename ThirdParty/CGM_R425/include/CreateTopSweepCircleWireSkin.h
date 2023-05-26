#ifndef CATCreateTopSweepWireSkinCircle2_h
#define CATCreateTopSweepWireSkinCircle2_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "FrFTopologicalOpe.h"

class CATTopSweepWireSkinCircle;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATLaw;
/**
 * Creates a CATTopSweepWireSkinCircle operator.
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
 * The pointer to the spine body. Each circular section is in the plane normal to this spine curve.
 * @param iRadiusLaw
 * The pointer to the radius law. 
 * @return
 * The pointer to the created operator. To be deleted after use, with the C++ <tt>delete</tt>
 * operator.
 */
ExportedByFrFTopologicalOpe CATTopSweepWireSkinCircle* 
CATCreateTopSweepWireSkinCircleVariable (CATGeoFactory * iFactory,
                                         CATTopData *    iData,
                                         CATBody *       iSupportShell,
                                         CATBody *       iGuide,
                                         CATBody *       iSpine,
                                         CATLaw  *       iRadiusLaw);

#endif
