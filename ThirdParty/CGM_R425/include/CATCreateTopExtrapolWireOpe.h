#ifndef CATCreateTopExtrapolWireOpe_H 
#define CATCreateTopExtrapolWireOpe_H 

// COPYRIGHT DASSAULT SYSTEMES  2005

/**
 * @level Protected
 * @usage U1
 */

#include "CATTopExtrapolWireOpe.h"
#include "AdvTopoSketch.h"

/**
* Creates a topological operator that extrapolates a wire.
* <br>It allows you to extrapolate a wire
* <ul><li>in tangency mode
* <li> or in curvature mode
* <li> on a support or not.
* <li> from a given length or up to an other wire or a shell.
* </ul>
* @param iFactory
* The pointer to the geometry factory.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iBodyWire
* The pointer to the wire to extrapolate.
* @param iBodyShell
* The pointer to the body support on which the wire must be extrapolated. If <tt>NULL</tt>, the result won't have any support.
* @return
* The pointer to the created operator. 
* To delete with the usual C++ <tt>delete</tt> operator after use.
*/

ExportedByAdvTopoSketch
CATTopExtrapolWireOpe * CATCreateTopExtrapolWireOpe(CATGeoFactory * iFacto, CATTopData * iData, CATBody * iBodyWire,CATBody * iBodyShell=NULL);



#endif
