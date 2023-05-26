#ifndef CATCGMCreateTopSweepCircleWireSkin_h_
#define CATCGMCreateTopSweepCircleWireSkin_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @CAA2Level L1
 * @CAA2Usage U1
*/

#include "CATGMOperatorsInterfaces.h"

class CATBody;
class CATGeoFactory;
class CATLaw;
class CATTopData;
class CATICGMTopSweepWireSkinCircle;

/**
 * Creates a CATICGMTopSweepWireSkinCircle operator.
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
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method.
 */
ExportedByCATGMOperatorsInterfaces CATICGMTopSweepWireSkinCircle *CATCGMCreateTopSweepWireSkinCircleVariable(
  CATGeoFactory *iFactory,
  CATTopData *iData,
  CATBody *iSupportShell,
  CATBody *iGuide,
  CATBody *iSpine,
  CATLaw *iRadiusLaw);

#endif /* CATCGMCreateTopSweepCircleWireSkin_h_ */
