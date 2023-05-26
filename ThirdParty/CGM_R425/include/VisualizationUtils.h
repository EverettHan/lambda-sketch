#ifndef VisualizationUtils_H
#define VisualizationUtils_H

// COPYRIGHT DASSAULT SYSTEMES 2014

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"

/** Return if visualization is using the new or the legacy render engine
* WARNING, IMPORTANT NOTICE:
* A CGR stream can be opened in a session running on NRE or on the legacy engine. 
* In particular, a CGR created on NRE can be opened with legacy engine.
* It is therefore not authorized to create a different scene graph on the legacy and the new render engine, in case this scene graph can be streamed in a cgr.
*@return integer
*<ol>
* <li> 0 = Legacy render engine</li>
* <li> 1 = New render engine</li>
*</ol>
*/
ExportedByCATVisFoundation int IsNewRenderEngine();

#endif
